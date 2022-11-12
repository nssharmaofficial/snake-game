#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>


class SnakeGame
{
private: //declare all the variables that we are using
	bool isGameOver;
	int width, height;			// dimensions of play field

	int snakeHeadX, snakeHeadY; // coord. of snake
	int foodX, foodY;			// coord. of food
	int score;

	std::vector<int> snakeTailX, snakeTailY;
	int snakeTailLength;

	// take the value based on which keyboard button the player is pressing
	enum eDirection
	{
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	eDirection dir; // variable of the eDirection

public:
	bool getIsGameOver() { return isGameOver; }

	void Setup(); // in which point of the game the player is
	void Print(); // print the board, snake and fruit
	void Input(); // which button is the player pressing
	void Logic(); // if the move is doable or if the game is lost

};