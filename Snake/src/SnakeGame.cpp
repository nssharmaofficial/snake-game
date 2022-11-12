
#include "SnakeGame.h"

// create template for all functions

void SnakeGame::Setup()
{
	// game has to start
	isGameOver = false; 
	score = 0; 

	// game field
	width = 40;
	height = 24;

	// snake to be stationary and at the center of field
	dir = STOP;
	snakeHeadX = width / 2;
	snakeHeadY = height / 2;

	// coord. of fruits have to be random 
	// (each time diff. random)
	srand(time(NULL));			 
	foodX = rand() % width;
	foodY = rand() % height;

	snakeTailX.resize(100);
	snakeTailY.resize(100);

}


void SnakeGame::Print()
{
	// every time we have to clear the screen
	system("cls");

	// print the first line of the game field (upper bound)
	// +2 because the first and last elements must be for the vertical lines
	for (int i = 0; i < width + 2; i++) 
		std::cout << "#";

	std::cout << std::endl;

	// height
	for (int i = 0; i < height; i++) 
	{
		// width
		for (int j = 0; j < width; j++) 
		{
			// left side of the game field
			if (j == 0)
				std::cout << "#";

			// snake head
			if (i == snakeHeadY && j == snakeHeadX)
				std::cout << "O"; 
			// fruit
			else if (i == foodY && j == foodX)
				std::cout << "X";
			// snake tail 
			else 
			{
				bool isSnakeTailCoord = false;

				for (int k = 0; k < snakeTailLength; k++)
				{
					if (snakeTailY[k] == i && snakeTailX[k] == j)
					{
						std::cout << "o";
						isSnakeTailCoord = true;
					}
				}

				// empty space in the game field
				if (!isSnakeTailCoord)
					std::cout << " ";
			}

			// right side of the game field
			if (j == width - 1)
				std::cout << "#";		
		}
		std::cout << std::endl;
	}

	// bottom line of the game field (lower bound)
	for (int i = 0; i < width + 2; i++)
		std::cout << "#";

	// score
	std::cout << std::endl << std::endl;
	std::cout << "Score: " << score;
	std::cout << std::endl << std::endl;
}


void SnakeGame::Input()
{
	// kbhit = keyboard hit 
	if (_kbhit())
	{
		// getch = get character (wasd)
		switch (_getch())
		{
		case 'w': 
			dir = UP;
			break;
		
		case 'a':
			dir = LEFT;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'd':
			dir = RIGHT;
			break;
		
		// ESC button = 27
		case 27:
			isGameOver = true;
			break;
		}
	}
}


void SnakeGame::Logic()
{
	// previous coordinates
	int prevX = snakeTailX[0];
	int prevY = snakeTailY[0]; 
	int prev2X, prev2Y;

	// first element of this vector is the head
	snakeTailX[0] = snakeHeadX;
	snakeTailY[0] = snakeHeadY;

	// move mechanics
	for (int i = 1; i < snakeTailLength; i++)
	{
		prev2X = snakeTailX[i];
		prev2Y = snakeTailY[i];
		snakeTailX[i] = prevX;
		snakeTailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	// direction
	switch (dir)
	{
	case UP:
		snakeHeadY--;
		Sleep(60);
		break;

	case LEFT:
		snakeHeadX--;
		break;

	case DOWN:
		snakeHeadY++;
		Sleep(60);
		break;

	case RIGHT:
		snakeHeadX++;
		break;

	default:
		break;
	}

	// check if the snake head is hitting the border
	if (snakeHeadX > width || snakeHeadX < 0 || snakeHeadY > height || snakeHeadY < 0) 
	{
		isGameOver = true;
		std::cout << "Game Ended !!!" << std::endl;
	}

	for (int i = 0; i < snakeTailLength; i++)
	{
		if (snakeTailX[i] == snakeHeadX && snakeTailY[i] == snakeHeadY)
		{
			isGameOver = true;
			std::cout << "Game Ended !!!" << std::endl; 
		}

	}

	// check if the snake head is eating the fruit
	if (snakeHeadX == foodX && snakeHeadY == foodY)
	{
		snakeTailLength++;
		score++;

		// after eating the fruit make it reappear again
		srand(time(NULL));
		foodX = rand() % width;
		foodY = rand() % height;
	}
}

int main()
{
	SnakeGame snake;

	snake.Setup();

	// while the game is not over
	while (!snake.getIsGameOver())
	{
		snake.Print();
		snake.Input();
		snake.Logic();
		Sleep(5); // slow down the game
	}

	return 0;
}

