# **************************************************************************** #
# 																			   #
# 														  :::	   ::::::::    #
#    a_maze_ing.py                                      :+:      :+:    :+:    #
# 													  +:+ +:+		  +:+	   #
# 	 By: sspirig <sspirig@42lausanne.ch>			+#+  +:+	   +#+		   #
# 												  +#+#+#+#+#+	+#+			   #
# 	 Created: 2026/09/27 21:42:13 by sspirig		   #+#	  #+#			   #
#    Updated: 2026/09/28 17:49:18 by sspirig          ###   ########.fr        #
# 																			   #
# **************************************************************************** #

import random
import sys

# Constants
WALL_N = 1  # 0001
WALL_E = 2  # 0010
WALL_S = 4  # 0100
WALL_W = 8  # 1000
FULL_WALL = 15  # 1111

DIRECTIONS = {
    "N": (0, -1, WALL_N, WALL_S),
    "E": (1, 0, WALL_E, WALL_W),
    "S": (0, 1, WALL_S, WALL_N),
    "W": (-1, 0, WALL_W, WALL_E),
}

# closed cells forming a "42" (4 on the left, 2 on the right).
PATTERN_42 = (
    "X.X.XXX",
    "X.X...X",
    "XXX.XXX",
    "..X.X..",
    "..X.XXX",
)

# ASCII Constants
CHAR_FULL = "█"
CHAR_EMPTY = " "
CHAR_ENTRY = "S"
CHAR_EXIT = "E"
CHAR_PATH = "."
COLOR_RESET = "\033[0m"
COLOR_WALL_DEFAULT = "\033[90m"  # Bright Black / Gray
COLOR_WALL_ALT = "\033[89m"
COLOR_ENTRY = "\033[92m"  # Green
COLOR_EXIT = "\033[91m"  # Red
COLOR_PATH = "\033[94m"  # Blue

RESET = "\033[0m"
BLOCK = "██"
FLOOR = "  "

COLOR_ENTRY = "\033[92m"
COLOR_EXIT = "\033[91m"
COLOR_PATH = "\033[94m"

WALL_COLORS = [
    "\033[37m",
    "\033[93m",
]


class Config:
    def __init__(self):
        self.width = None
        self.height = None
        self.entry = None
        self.exit = None
        self.output_file = None
        self.perfect = None
        self.seed = None
        self.algorithm = None


def setup():
    config = Config()
    # Opening file in read mode
    file = open("config.txt", "r")

    # Reading line by line
    try:
        line = file.readline()
        while line:
            temp = line.strip()  # .strip() removes newline characters
            if "=" in temp:
                temparr = temp.split("=")
                key = temparr[0].lower().strip()
                value = temparr[1].strip()
                if value == "X":
                    value = None

                if hasattr(config, key):  # checks if config obj has the key attribute
                    setattr(
                        config, key, value
                    )  # if true then sets the value to that key
                    print(f"{key} => {value}")
                else:
                    print(f"Warning: unknown config key '{key}'")
            line = file.readline()
    except FileNotFoundError:
        print("Error: config.txt not found")
    except Exception as e:
        print(f"Execption: {e}")
    file.close()
    return config


def create_grid(width, height):
    grid = [[FULL_WALL for _ in range(width)] for _ in range(height)]
    return grid


def get_neighbors(grid, x, y, visited, perfect):
    width = len(grid[0])
    height = len(grid)
    unvisited = []
    visited_safe = []

    for direction, (dx, dy, _, _) in DIRECTIONS.items():
        nx, ny = x + dx, y + dy
        if 0 <= nx < width and 0 <= ny < height:
            if would_create_3x3_open_area(grid, x, y, nx, ny, direction):
                continue
            if (nx, ny) not in visited:
                unvisited.append((nx, ny, direction))
            elif not perfect:
                visited_safe.append((nx, ny, direction))

    if unvisited:
        return unvisited
    return visited_safe


def generate_maze(grid, start_x, start_y, perfect=True):
    height = len(grid)
    width = len(grid[0])
    visited = set()
    stack = [(start_x, start_y)]
    visited.add((start_x, start_y))

    while stack:
        cx, cy = stack[-1]
        neighbors = get_neighbors(grid, cx, cy, visited, perfect)

        if neighbors:
            nx, ny, direction = random.choice(neighbors)
            _, _, wall_current, wall_neighbor = DIRECTIONS[direction]

            grid[cy][cx] &= ~wall_current
            grid[ny][nx] &= ~wall_neighbor

            if (nx, ny) not in visited:
                visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            stack.pop()


def would_create_3x3_open_area(grid, cx, cy, nx, ny, direction):
    if nx == 0 or nx == len(grid[0]) - 1 or ny == 0 or ny == len(grid) - 1:
        return False
    _, _, _, wall_neighbor = DIRECTIONS[direction]
    new_walls = grid[ny][nx] & ~wall_neighbor
    if (new_walls & 15) != 0:
        return False
    if (grid[ny - 1][nx] & 10) or (grid[ny + 1][nx] & 10):
        return False
    if (grid[ny][nx - 1] & 5) or (grid[ny][nx + 1] & 5):
        return False
    return True


def get_shortest_path_bfs(grid, start, end):
    width = len(grid[0])
    height = len(grid)
    queue = [(start, [])]
    visited = {start}
    while queue:
        (cx, cy), path = queue.pop(0)
        if (cx, cy) == end:
            return path
        for direction, (dx, dy, wall_check, _) in DIRECTIONS.items():
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < width and 0 <= ny < height:
                if (nx, ny) not in visited:
                    # Checking if wall exist (if bit = 0 then path is open)
                    if not (grid[cy][cx] & wall_check):
                        visited.add((nx, ny))
                        queue.append(((nx, ny), path + [direction]))
    return None


def write_output(filename, grid, entry, exit_pos, path):
    """Writes the grid, coordinates, and path to the file"""
    with open(filename, "w") as f:
        # Write Grid
        for row in grid:
            hex_row = "".join(format(cell, "X") for cell in row)
            f.write(hex_row + "\n")

        f.write("\n")

        # Write Entry
        f.write(f"{entry[0]},{entry[1]}\n")

        # Write Exit
        f.write(f"{exit_pos[0]},{exit_pos[1]}\n")

        # Write Path
        f.write("".join(path) + "\n")


def parse_coordinates(coords):
    """Helper function that convert 'x,y' string into (int, int) tuple"""
    if not coords:
        return None
    temparr = coords.split(",")
    if len(temparr) != 2:
        return None
    try:
        return (int(temparr[0].strip()), int(temparr[1].strip()))
    except ValueError:
        return None


def path_cells(entry_pos, path):
    """Return every cell crossed by the path."""
    x, y = entry_pos
    cells = [(x, y)]

    for step in path:
        if step == "N":
            y -= 1
        elif step == "E":
            x += 1
        elif step == "S":
            y += 1
        elif step == "W":
            x -= 1
        cells.append((x, y))

    return cells


def path_tiles(entry_pos, path):
    """Return display tiles occupied by the path and its corridors."""
    cells = path_cells(entry_pos, path)

    tiles = {(2 * x + 1, 2 * y + 1) for x, y in cells}

    for (x1, y1), (x2, y2) in zip(cells, cells[1:]):
        tiles.add((x1 + x2 + 1, y1 + y2 + 1))

    return tiles


def is_wall_tile(grid, width, height, tx, ty):
    """Return True when a display tile represents a maze wall.
    Parameters :
    grid
    """
    if tx % 2 == 0 and ty % 2 == 0:
        return True

    if tx % 2 == 1 and ty % 2 == 1:
        return False

    if ty % 2 == 0:
        cy = ty // 2
        cx = tx // 2

        if cy < height:
            return bool(grid[cy][cx] & WALL_N)

        return bool(grid[height - 1][cx] & WALL_S)

    cx = tx // 2
    cy = ty // 2

    if cx < width:
        return bool(grid[cy][cx] & WALL_W)

    return bool(grid[cy][width - 1] & WALL_E)


def render_ascii_maze(grid, entry_pos, exit_pos, path, show_path_flag, color_mode):
    """Render the maze with walls, entry, exit and shortest path."""
    height = len(grid)
    width = len(grid[0])

    on_path = path_tiles(entry_pos, path) if show_path_flag else set()

    entry_tile = (2 * entry_pos[0] + 1, 2 * entry_pos[1] + 1)

    exit_tile = (2 * exit_pos[0] + 1, 2 * exit_pos[1] + 1)

    wall_color = WALL_COLORS[color_mode - 1]

    for ty in range(2 * height + 1):
        line = ""

        for tx in range(2 * width + 1):
            tile = (tx, ty)

            if tile == entry_tile:
                line += f"{COLOR_ENTRY}{BLOCK}{RESET}"

            elif tile == exit_tile:
                line += f"{COLOR_EXIT}{BLOCK}{RESET}"

            elif is_wall_tile(grid, width, height, tx, ty):
                line += f"{wall_color}{BLOCK}{RESET}"

            elif tile in on_path:
                line += f"{COLOR_PATH}{BLOCK}{RESET}"

            else:
                line += FLOOR

        print(line)


def main():
    # Config
    if len(sys.argv) < 2:
        print("Usage: python3 a_maze_ing.py config.txt")
        sys.exit(1)
    config = setup()
    if not config.width or not config.height:
        print("Error: Width and Height are required in the config.txt file")
        sys.exit(1)
    width = int(config.width)
    height = int(config.height)
    # Seed
    if config.seed is not None:
        random.seed(config.seed)

        # Perfect attribute check
    perfect = True
    if config.perfect:
        temp = str(config.perfect).lower()
        if temp in ["false", "0"]:
            perfect = False
    # Generating maze entry and exit cells
    grid = create_grid(width, height)

    entry_pos = parse_coordinates(config.entry)
    if entry_pos is None:
        entry_pos = (0, 0)
    exit_pos = parse_coordinates(config.exit)
    if exit_pos is None:
        exit_pos = (width - 1, height - 1)

    # Generation
    generate_maze(grid, entry_pos[0], entry_pos[1], perfect=perfect)
    # Finding shortest path
    path = get_shortest_path_bfs(grid, entry_pos, exit_pos)
    if path is None:
        print("Error: No path found between entry and exit")
        sys.exit(1)

    output_file = config.output_file if config.output_file else "output_maze.txt"
    write_output(output_file, grid, entry_pos, exit_pos, path)

    print(f"Maze has been successfully generated in {output_file}")

    # Visual Representation
    color_mode = 1
    show_path_flag = False
    while True:
        # Clearing screen
        # print("\033[H\033[J", end="")
        render_ascii_maze(grid, entry_pos, exit_pos, path, show_path_flag, color_mode)

        print("=== A-Maze-ing ===")
        print("1. Re-generate a new maze")
        print("2. Show/Hide path")
        print("3. Change wall colors")
        print("4. Quit")

        choice = input("Choice? (1-4): ").strip()
        if choice == "1":
            # 			 if config.seed:  # if seed was given in config file, it will Re-generate the same maze (need to do thatt)
            # 				 random.seed()
            grid = create_grid(width, height)
            generate_maze(grid, entry_pos[0], entry_pos[1])
            if not perfect:
                add_random_loops(grid, 0.15)
            path = get_shortest_path_bfs(grid, entry_pos, exit_pos)
            write_output(output_file, grid, entry_pos, exit_pos, path)
        elif choice == "2":
            show_path_flag = not show_path_flag
        elif choice == "3":
            color_mode = 2 if color_mode == 1 else 1
        elif choice == "4":
            print("Exiting...")
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
