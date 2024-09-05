# Snake Game

This project is a simple console-based Snake Game implemented in C++. The objective of the game is to control the snake's movement using the WASD keys, collect food, and grow the snake without hitting the walls or its own tail.

## Features

- **Classic snake gameplay**: control the snake to collect food and avoid obstacles
- **Dynamic game field**: the game takes place on a 40x24 grid where the snake moves and grows as it eats
- **Randomized food generation**: food is randomly generated at different coordinates on the grid after the snake eats it
- **Real-time input**: control the snake's movement using keyboard input
- **Score tracking**: the game keeps track of the score, which increases as the snake consumes more food
- **Game over detection**: the game ends when the snake runs into the walls or its own tail.

## Controls

- `W`: Move Up
- `A`: Move Left
- `S`: Move Down
- `D`: Move Right
- `ESC`: Quit the game

## How to run

1. Clone the Repository
    ```bash
    git clone https://github.com/your-username/snake-game.git
    ```
2. Navigate to the project directory
    ```bash
    cd snake-game
    ```
3. Compile the code using GCC (MinGW on Windows)
    ```bash
    g++ -o SnakeGame SnakeGame.cpp -std=c++11
    ```
4. Run the executable (using MinGW on Windows)
    ```bash
    ./SnakeGame.exe
    ```

## Requirements

- **Operating system**: the game uses the `<Windows.h>` library, which is specific to Windows. For now, this game will only run on the Windows platform. You can port it to other operating systems by removing or replacing the Windows-specific code (e.g., `system("cls")` and `Sleep()` functions)
- **C++ Compiler**: MinGW (GCC) is a popular choice for compiling C++ code on Windows
- **Build tools**: ensure that your environment is configured with the necessary build tools and that your compiler is in your system's PATH
