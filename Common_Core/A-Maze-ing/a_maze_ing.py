# **************************************************************************** #
# 																			   #
# 														  :::	   ::::::::    #
# 	 a_maze_ing.py										:+:		 :+:	:+:    #
# 													  +:+ +:+		  +:+	   #
# 	 By: sspirig <sspirig@42lausanne.ch>			+#+  +:+	   +#+		   #
# 												  +#+#+#+#+#+	+#+			   #
# 	 Created: 2026/09/27 21:42:13 by sspirig		   #+#	  #+#			   #
# 	 Updated: 2026/10/02 23:50:38 by sspirig		  ###	########.fr		   #
# 																			   #
# **************************************************************************** #

import random
import sys

# --- Constants ---
WALL_N, WALL_E, WALL_S, WALL_W = 1, 2, 4, 8
FULL_WALL = 15
DIRECTIONS = {
    "N": (0, -1, WALL_N, WALL_S),
    "E": (1, 0, WALL_E, WALL_W),
    "S": (0, 1, WALL_S, WALL_N),
    "W": (-1, 0, WALL_W, WALL_E),
}

# --- Visuals ---
CHAR_FULL = "█"
COLOR_RESET = "\033[0m"
COLORS = {
    "wall": ["\033[90m", "\033[93m"],
    "entry": "\033[92m",
    "exit": "\033[91m",
    "path": "\033[94m",
}
BLOCK = "██"
FLOOR = "  "


class Config:
    def __init__(self):
        self.width = self.height = self.entry = self.exit = None
        self.output_file = self.perfect = self.seed = None


def setup():
    config = Config()
    try:
        with open("config.txt", "r") as f:
            for line in f:
                line = line.split("#")[0].strip()
                if "=" in line:
                    k, v = line.split("=", 1)
                    k, v = k.lower().strip(), v.strip()
                    if v == "X":
                        v = None
                    if hasattr(config, k):
                        setattr(config, k, v)
                        print(f"{k} => {v}")
    except FileNotFoundError:
        print("Error: config.txt not found")
        sys.exit(1)
    except Exception as e:
        print(f"Exception: {e}")
        sys.exit(1)
    return config


def create_grid(w, h):
    return [[FULL_WALL] * w for _ in range(h)]


# --- Constraint Check ---
def would_create_3x3(grid, cx, cy, nx, ny, direction):
    if nx == 0 or nx == len(grid[0]) - 1 or ny == 0 or ny == len(grid) - 1:
        return False
    _, _, _, w_rem = DIRECTIONS[direction]
    if (grid[ny][nx] & ~w_rem & 15) != 0:
        return False
    if (grid[ny - 1][nx] & 10) or (grid[ny + 1][nx] & 10):
        return False
    if (grid[ny][nx - 1] & 5) or (grid[ny][nx + 1] & 5):
        return False
    return True


# --- Generator 1: Perfect Maze (Standard DFS) ---
def generate_perfect_maze(grid, start_x, start_y):
    h, w = len(grid), len(grid[0])
    visited = {(start_x, start_y)}
    stack = [(start_x, start_y)]

    while stack:
        cx, cy = stack[-1]
        neighbors = []
        for d, (dx, dy, _, _) in DIRECTIONS.items():
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < w and 0 <= ny < h and (nx, ny) not in visited:
                if not would_create_3x3(grid, cx, cy, nx, ny, d):
                    neighbors.append((nx, ny, d))

        if neighbors:
            nx, ny, d = random.choice(neighbors)
            _, _, wc, wn = DIRECTIONS[d]
            grid[cy][cx] &= ~wc
            grid[ny][nx] &= ~wn
            visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            stack.pop()


# --- Generator 2: Imperfect Maze (Corridor Widener) ---
def generate_imperfect_maze(grid, start_x, start_y, widen_attempts=50):
    # Step 1: Generate a perfect base
    generate_perfect_maze(grid, start_x, start_y)

    h, w = len(grid), len(grid[0])

    # Step 2: Widen corridors by removing parallel walls
    # We look for patterns like: [Open] | [Wall] | [Open] | [Wall] | [Open]
    # And remove both walls if safe, creating a 1x3 corridor.

    for _ in range(widen_attempts):
        # Randomly choose horizontal or vertical
        if random.choice([True, False]):
            # Horizontal: Check rows for A|B|C pattern
            y = random.randint(1, h - 2)
            x = random.randint(1, w - 4)  # Need space for 3 cells

            # Cells: (x,y), (x+1,y), (x+2,y)
            # Walls: Between x|x+1 (East of x) and x+1|x+2 (East of x+1)

            c1 = grid[y][x]
            c2 = grid[y][x + 1]
            c3 = grid[y][x + 2]

            # Check if middle cell is isolated by walls on East and West
            # i.e., c1 has East wall, c2 has West and East walls, c3 has West wall
            if (c1 & WALL_E) and (c2 & WALL_W) and (c2 & WALL_E) and (c3 & WALL_W):
                # Try removing both walls
                # Check 3x3 constraint for first removal (between c1, c2)
                if not would_create_3x3(grid, x, y, x + 1, y, "E"):
                    # Check 3x3 constraint for second removal (between c2, c3)
                    # Simulate first removal for second check
                    temp_grid_c2 = c2 & ~WALL_W
                    # We need a temporary check function or just try it
                    # For simplicity, let's just try removing both and revert if 3x3 forms
                    original_c2 = c2
                    grid[y][x] &= ~WALL_E
                    grid[y][x + 1] &= ~WALL_W
                    grid[y][x + 1] &= ~WALL_E
                    grid[y][x + 2] &= ~WALL_W

                    # Check if we created a 3x3 anywhere in the affected area
                    created_3x3 = False
                    for cy in range(y - 1, y + 2):
                        for cx in range(x, x + 3):
                            if 0 < cx < w - 1 and 0 < cy < h - 1:
                                if (grid[cy][cx] & 15) == 0:  # Center open
                                    if (grid[cy - 1][cx] & 10) == 0 and (
                                        grid[cy + 1][cx] & 10
                                    ) == 0:
                                        if (grid[cy][cx - 1] & 5) == 0 and (
                                            grid[cy][cx + 1] & 5
                                        ) == 0:
                                            created_3x3 = True
                                            break
                        if created_3x3:
                            break

                    if created_3x3:
                        # Revert
                        grid[y][x] |= WALL_E
                        # grid[y][x + 1] |= WALL_W
                        grid[y][x + 1] |= WALL_E
                        grid[y][x + 2] |= WALL_W
        else:
            # Vertical: Check columns for A|B|C pattern
            y = random.randint(1, h - 3)
            x = random.randint(1, w - 2)

            # Cells: (x,y), (x,y+1), (x,y+2)
            # Walls: Between y|y+1 (South of y) and y+1|y+2 (South of y+1)

            c1 = grid[y][x]
            c2 = grid[y + 1][x]
            c3 = grid[y + 2][x]

            if (c1 & WALL_S) and (c2 & WALL_N) and (c2 & WALL_S) and (c3 & WALL_N):
                if not would_create_3x3(grid, x, y, x, y + 1, "S"):
                    grid[y][x] &= ~WALL_S
                    grid[y + 1][x] &= ~WALL_N
                    grid[y + 1][x] &= ~WALL_S
                    grid[y + 2][x] &= ~WALL_N

                    created_3x3 = False
                    for cy in range(y, y + 3):
                        for cx in range(x - 1, x + 2):
                            if 0 < cx < w - 1 and 0 < cy < h - 1:
                                if (grid[cy][cx] & 15) == 0:
                                    if (grid[cy - 1][cx] & 10) == 0 and (
                                        grid[cy + 1][cx] & 10
                                    ) == 0:
                                        if (grid[cy][cx - 1] & 5) == 0 and (
                                            grid[cy][cx + 1] & 5
                                        ) == 0:
                                            created_3x3 = True
                                            break
                        if created_3x3:
                            break

                    if created_3x3:
                        grid[y][x] |= WALL_S
                        grid[y + 1][x] |= WALL_N
                        grid[y + 1][x] |= WALL_S
                        grid[y + 2][x] |= WALL_N


# --- Pathfinding (BFS) ---
def bfs_path(grid, start, end):
    h, w = len(grid), len(grid[0])
    q = [(start, [])]
    vis = {start}
    while q:
        (cx, cy), path = q.pop(0)
        if (cx, cy) == end:
            return path
        for d, (dx, dy, wc, _) in DIRECTIONS.items():
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < w and 0 <= ny < h and (nx, ny) not in vis:
                if not (grid[cy][cx] & wc):
                    vis.add((nx, ny))
                    q.append(((nx, ny), path + [d]))
    return None


def parse_coords(s):
    if not s:
        return None
    p = s.split(",")
    if len(p) != 2:
        return None
    try:
        return (int(p[0]), int(p[1]))
    except:
        return None


# --- Path Rendering ---
def get_path_tiles(entry, path):
    if not path:
        return set()

    tiles = set()
    x, y = entry
    tiles.add((2 * x + 1, 2 * y + 1))

    for move in path:
        prev_x, prev_y = x, y
        if move == "N":
            y -= 1
        elif move == "S":
            y += 1
        elif move == "E":
            x += 1
        elif move == "W":
            x -= 1

        tiles.add((2 * x + 1, 2 * y + 1))
        mid_tx = prev_x + x + 1
        mid_ty = prev_y + y + 1
        tiles.add((mid_tx, mid_ty))

    return tiles


# --- Rendering ---
def render_ascii_maze(grid, entry, exit_p, path, show_path, color_idx):
    h, w = len(grid), len(grid[0])
    path_set = get_path_tiles(entry, path) if (show_path and path) else set()
    e_tile = (2 * entry[0] + 1, 2 * entry[1] + 1)
    x_tile = (2 * exit_p[0] + 1, 2 * exit_p[1] + 1)
    w_col = COLORS["wall"][color_idx]

    print("\033[H\033[J", end="")

    for ty in range(2 * h + 1):
        line = ""
        for tx in range(2 * w + 1):
            t = (tx, ty)
            if t == e_tile:
                line += f"{COLORS['entry']}{BLOCK}{COLOR_RESET}"
                continue
            if t == x_tile:
                line += f"{COLORS['exit']}{BLOCK}{COLOR_RESET}"
                continue
            if t in path_set:
                line += f"{COLORS['path']}{BLOCK}{COLOR_RESET}"
                continue

            is_w = False
            if tx % 2 == 0 and ty % 2 == 0:
                is_w = True
            elif tx % 2 == 1 and ty % 2 == 1:
                is_w = False
            else:
                cx, cy = tx // 2, ty // 2
                if 0 <= cx < w and 0 <= cy < h:
                    if ty % 2 == 0:
                        is_w = bool(grid[cy][cx] & WALL_N)
                    else:
                        is_w = bool(grid[cy][cx] & WALL_W)
                else:
                    is_w = True

            if is_w:
                line += f"{w_col}{BLOCK}{COLOR_RESET}"
            else:
                line += FLOOR
        print(line)


def write_output(filename, grid, entry, exit_p, path):
    with open(filename, "w") as f:
        for r in grid:
            f.write("".join(format(c, "X") for c in r) + "\n")
        f.write("\n")
        f.write(f"{entry[0]},{entry[1]}\n")
        f.write(f"{exit_p[0]},{exit_p[1]}\n")
        f.write("".join(path) + "\n")


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 a_maze_ing.py config.txt")
        sys.exit(1)

    cfg = setup()
    if not cfg.width or not cfg.height:
        print("Error: Width/Height required")
        sys.exit(1)

    w, h = int(cfg.width), int(cfg.height)

    perfect_mode = True
    if cfg.perfect:
        val = str(cfg.perfect).lower()
        if val in ["false", "0", "no", "off"]:
            perfect_mode = False

    entry = parse_coords(cfg.entry) or (0, 0)
    exit_p = parse_coords(cfg.exit) or (w - 1, h - 1)

    if cfg.seed:
        random.seed(int(cfg.seed))

    def run_generation():
        grid = create_grid(w, h)
        if perfect_mode:
            generate_perfect_maze(grid, entry[0], entry[1])
        else:
            generate_imperfect_maze(grid, entry[0], entry[1], widen_attempts=100)

        # Open Borders
        if entry[1] == 0:
            grid[0][entry[0]] &= ~WALL_N
        if entry[0] == 0:
            grid[entry[1]][0] &= ~WALL_W
        if exit_p[1] == h - 1:
            grid[h - 1][exit_p[0]] &= ~WALL_S
        if exit_p[0] == w - 1:
            grid[exit_p[1]][w - 1] &= ~WALL_E
        return grid

    grid = run_generation()
    path = bfs_path(grid, entry, exit_p)

    if not path:
        print("⚠️  Path not found! Regenerating as Perfect...")
        perfect_mode = True
        grid = run_generation()
        path = bfs_path(grid, entry, exit_p)

    if not path:
        print("Critical Error: No path found.")
        sys.exit(1)

    out_file = cfg.output_file or "maze.txt"
    write_output(out_file, grid, entry, exit_p, path)
    print(
        f"Maze generated ({'Perfect' if perfect_mode else 'Imperfect'}). Path: {len(path)} steps."
    )

    show_path, col_idx = False, 0
    while True:
        render_ascii_maze(grid, entry, exit_p, path, show_path, col_idx)

        print("\n=== A-Maze-ing ===")
        print("1. Re-generate")
        print("2. Toggle Path")
        print("3. Change Color")
        print("4. Quit")

        ch = input("Choice? ").strip()
        if ch == "1":
            if cfg.seed:
                random.seed()
            grid = run_generation()
            path = bfs_path(grid, entry, exit_p)
            if path:
                write_output(out_file, grid, entry, exit_p, path)
        elif ch == "2":
            show_path = not show_path
        elif ch == "3":
            col_idx = 1 - col_idx
        elif ch == "4":
            sys.exit(0)


if __name__ == "__main__":
    main()
