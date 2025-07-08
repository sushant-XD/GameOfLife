# Conway's Game of Life

A fast and interactive implementation of Conway's Game of Life with core implementation in C++ and Python for UI linked by pybind11. 

## What's this?

This is Conway's Game of Life - the classic cellular automaton where cells live, die, and reproduce based on simple rules. 
Rules of Conway's game of life are:
    - if a cell is alive:
        - if the cell has less than 2 live neighboring cells, it dies
        - if it has 2 or 3 live neighbors, it survives onto next step
        - if it has more than 3 live neighbors, it dies
    - if a cell is dead and has exactly 3 live neighbors, it lives on next step
## How it works

The project is split into two parts:

**C++ Core** (`src/`) - Handles the game logic:
- Grid management and cell state tracking
- Game logic and pattern evolution
- Calculations

**Python UI** (`python_ui/`) - The interface:
- Interactive pygame window
- Click to toggle cells, resize window
- Toroidal wrapping 

**Controls**
- Space - pause/play
- Left Click - set cells to live/dead
- Escape - exit the program

Note: it is possible to set the cells only when the game is paused.

## Building

You'll need:
- CMake
- A C++ compiler
- Python 3.x
- pygame (`pip install pygame`)

```bash

# Install Python dependencies
pip install pygame pybind11

# Build the C++ components
mkdir build && cd build
cmake ..
make
cd ..

# Run 
python3 python_ui/main.py 

```
This is a basic implementation meant for basic understanding interfacing C++ with python.  
