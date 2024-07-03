# cub3D

## Overview


<img src="https://imgur.com/SCUimh3.gif" alt="visualizer image" width="800">


`cub3D` is a 3D graphical engine inspired by the classic game Wolfenstein 3D. It's built using C and the MLX graphics library. This project serves as a fun and educational way to explore the fundamentals of computer graphics.

## Features

- 3D rendering using raycasting techniques
- Texture mapping
- Collision detection
- Simple user interface

## Prerequisites

- GCC Compiler
- MLX42

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

## Map exemple

```
NO ./asset/stone.png
SO ./asset/wall.png
WE ./asset/Stones_Texture.png
EA ./asset/Brickwall6_Texture.png
F 153,76,0
C 32,32,32

11111111111
1000 000001
1N000100001
10000100001
11111111111
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.