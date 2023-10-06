# cub3D

## Overview

`cub3D` is a 3D graphical engine inspired by the classic game Wolfenstein 3D. It's built using C and the MLX graphics library. This project serves as a fun and educational way to explore the fundamentals of computer graphics.

## Features

- 3D rendering using raycasting techniques
- Texture mapping
- Collision detection
- Simple user interface

## Prerequisites

- GCC Compiler
- MLX

## Installation

1. Clone the repository:
git clone https://github.com/demenciel/cub3D.git

3. Compile the project:
```
make
```


## Usage

Run the program with:

```
./cub3D [map_file.cub]
```

or

```
make run
```

## Code Organization

- `src/`: Contains the source code files for the main functionality.
    - `src/parsing/`: Contains the code for the parsing of the map file.
        - `src/parsing/final_map.c`: Creates a map `2d int array`, to be passed to the MLX
        - `src/parsing/find_colors.c`: Parse the input file to get the RGBA colors
        - `src/parsing/find_nswe.c`: Parse the input file to get the textures sources
        - `src/parsing/find_width_height.c`: Functions to get the actual size of the map
        - `src/parsing/flood_map.c`: A flood fill implementation to check if map is valid
        - `src/parsing/open_read.c`: Create a copy of the content of the input file
- `inc/`: Header files and global variable declarations.
- `lib/libft`: A custom library `libft` of basic C functions.
- `assets/`: Textures, sprites, and other graphical assets.
- `maps/`: Game map files in `.cub` format.
- `Makefile`: Script for compiling the project.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
