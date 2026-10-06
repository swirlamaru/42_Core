def render_ascii_maze(grid, entry_pos, exit_pos, path=None, show_path=False):
    height = len(grid)
    width = len(grid[0])
    # Creating a set of path coordinates
    path_coords = set()
    if show_path and path:
        cx, cy = entry_pos
        for move_dir in path:
            path_coords.add((cx, cy))
            if move_dir == "N":
                cy -= 1
            elif move_dir == "S":
                cy += 1
            elif move_dir == "E":
                cx += 1
            elif move_dir == "W":
                cx -= 1
        path_coords.add((cx, cy))
    print("\n")
    # Looping through every row
    for y in range(height):
        # Printing the top row of the cell
        line_top = ""
        line_bottom = ""
        for x in range(width):
            cell_value = grid[y][x]
            is_entry = (x, y) == entry
            is_exit = (x, y) == exit_pos
            is_path = (x, y) in path_coords
            # Assigning ascii char for this cell
            if is_entry:
                char = CHAR_ENTRY
            elif is_exit:
                char = CHAR_EXIT
            elif show_path and is_path:
                char = CHAR_PATH
            else:
                char = CHAR_EMPTY
            # Building Top-line (by checking north wall)
            if cell_value & WALL_N:
                line_top += CHAR_FULL + CHAR_FULL
            else:
                line_top += char + char
            # Building Bottom-line (by checking west wall)
            if cell_value & WALL_W:
                line_top -= CHAR_FULL + char
            else:
                line_top -= char + char
        print(line_top)
        print(line_botttom)
    print("\n")

-----------------------------------------------------------------------------------------------------
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
COLOR_WALL_ALT = "\033[93m"  # Yellow
COLOR_ENTRY = "\033[92m"  # Green
COLOR_EXIT = "\033[91m"  # Red
COLOR_PATH = "\033[94m"  # Blue




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


def get_unvisited_neighbors(grid, x, y, visited):
    neighbors = []
    width = len(grid[0])
    height = len(grid)

    for direction, (dx, dy, _, _) in DIRECTIONS.items():
        nx, ny = x + dx, y + dy
        # Checking bounds
        if 0 <= nx < width and 0 <= ny < height:
            if (nx, ny) not in visited:
                neighbors.append((nx, ny, direction))
    return neighbors


def generate_maze_dfs(grid, start_x, start_y):
    height = len(grid)
    width = len(grid[0])
    visited = set()
    stack = [(start_x, start_y)]
    visited.add((start_x, start_y))

    while stack:
        cx, cy = stack[-1]  # current cell
        neighbors = get_unvisited_neighbors(grid, cx, cy, visited)
        if neighbors:
            # picking a random neighbor
            nx, ny, direction = random.choice(neighbors)
            # removing walls
            _, _, wall_current, wall_neighbor = DIRECTIONS[direction]
            # removing wall from current cell
            grid[cy][cx] &= ~wall_current
            # removing opposite wall from neighbor
            grid[ny][nx] &= ~wall_neighbor
            visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            # Backtracking
            stack.pop()


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

        # Write Entry (1-based)
        f.write(f"{entry[0]+1},{entry[1]+1}\n")

        # Write Exit (1-based)
        f.write(f"{exit_pos[0]+1},{exit_pos[1]+1}\n")

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


def render_ascii_maze(
    grid, entry_pos, exit_pos, path=None, show_path=False, color_mode=1
):
    height = len(grid)
    width = len(grid[0])

    # Force types
    entry_pos = (int(entry_pos[0]), int(entry_pos[1]))
    exit_pos = (int(exit_pos[0]), int(exit_pos[1]))

    # Path calc
    path_coords = set()
    if show_path and path:
        cx, cy = entry_pos
        path_coords.add((cx, cy))
        for move_dir in path:
            if move_dir == "N":
                cy -= 1
            elif move_dir == "S":
                cy += 1
            elif move_dir == "E":
                cx += 1
            elif move_dir == "W":
                cx -= 1
            if 0 <= cx < width and 0 <= cy < height:
                path_coords.add((cx, cy))

    c_wall = COLOR_WALL_DEFAULT if color_mode == 1 else COLOR_WALL_ALT
    c_reset = COLOR_RESET
    c_entry = COLOR_ENTRY
    c_exit = COLOR_EXIT
    c_path = COLOR_PATH

    print("\n")

    for y in range(height):
        line_top = ""
        line_bot = ""

        for x in range(width):
            cell_val = grid[y][x]
            is_entry = x == entry_pos[0] and y == entry_pos[1]
            is_exit = x == exit_pos[0] and y == exit_pos[1]
            is_path = (x, y) in path_coords

            # Determine the "Content" of the cell (what we see in the open space)
            if is_entry:
                content_char = CHAR_ENTRY
                content_color = c_entry
            elif is_exit:
                content_char = CHAR_EXIT
                content_color = c_exit
            elif show_path and is_path:
                content_char = CHAR_PATH
                content_color = c_path
            else:
                content_char = CHAR_EMPTY
                content_color = c_reset

            # --- LINE 1: Top Half ---
            # If North Wall exists, draw Wall. Else, draw Content.
            if cell_val & WALL_N:
                line_top += f"{c_wall}{CHAR_FULL}{c_reset}"
                line_top += f"{c_wall}{CHAR_FULL}{c_reset}"
            else:
                # No North Wall: Draw content twice (for 2x2 width)
                line_top += f"{content_color}{content_char}{c_reset}"
                line_top += f"{content_color}{content_char}{c_reset}"

            # --- LINE 2: Bottom Half ---
            # Left Side: Check West Wall
            if cell_val & WALL_W:
                line_bot += f"{c_wall}{CHAR_FULL}{c_reset}"
            else:
                # No West Wall: Draw content
                line_bot += f"{content_color}{content_char}{c_reset}"

            # Right Side: Check East Wall
            if cell_val & WALL_E:
                line_bot += f"{c_wall}{CHAR_FULL}{c_reset}"
            else:
                # No East Wall: Draw content
                line_bot += f"{content_color}{content_char}{c_reset}"

        print(line_top)
        print(line_bot)

    # --- BOTTOM BORDER ---
    # This draws the South walls of the last row.
    # If the Exit is at the bottom and we opened the wall, this will draw SPACE.
    last_y = height - 1
    border_line = ""
    for x in range(width):
        cell_val = grid[last_y][x]
        if cell_val & WALL_S:
            border_line += f"{c_wall}{CHAR_FULL}{c_reset}" * 2
        else:
            border_line += "  "  # Open space (Exit)
    print(border_line)
    print("\n")


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 a_maze_ing.py config.txt")
        sys.exit(1)
    config = setup()
    if not config.width or not config.height:
        print("Error: Width and Height are required in the config.txt file")
        sys.exit(1)
    width = int(config.width)
    height = int(config.height)
    if config.seed:
        random.seed(int(config.seed))
    grid = create_grid(width, height)

    entry_pos = parse_coordinates(config.entry)
    if entry_pos is None:
        entry_pos = (0, 0)
    exit_pos = parse_coordinates(config.exit)
    if exit_pos is None:
        exit_pos = (width - 1, height - 1)

    generate_maze_dfs(grid, entry_pos[0], entry_pos[1])  # for now its a perfect maze
    # Manually Opening the exit wall
    # The DFS creates walls everywhere. We must carve the exit to the outside.

    ex, ey = exit_pos
    # If Exit is at the bottom edge, remove South Wall
    if ey == height - 1:
        grid[ey][ex] &= ~WALL_S
    # If Exit is at the right edge, remove East Wall
    if ex == width - 1:
        grid[ey][ex] &= ~WALL_E

    sx, sy = entry_pos
    # If Entry is at top edge, remove North Wall
    if sy == 0:
        grid[sy][sx] &= ~WALL_N
    # If Entry is at left edge, remove West Wall
    if sx == 0:
        grid[sy][sx] &= ~WALL_W

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
            if (
                config.seed
            ):  # if seed was given in config file, it will Re-generate the same maze (need to do thatt)
                random.seed()
            grid = create_grid(width, height)
            generate_maze_dfs(grid, entry_pos[0], entry_pos[1])
            path = get_shortest_path_bfs(grid, entry_pos, exit_pos)
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

