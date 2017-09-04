#pragma once
#define MOVE_TAB_SIZE 200


class Movements
{
public:
	Movements();

public:
	void rotateWallRight(int);
	void rotateWallLeft(int);
	void rotateYaxis();
	void rotateYaxisP();
	void rotateXaxis();
	void rotateXaxisP();
	void up();
	void upP();
	void down();
	void downP();
	void right();
	void rightP();
	void left();
	void leftP();
	void front();
	void frontP();
	void back();
	void backP();
	void initialize(int **tab);
	void resetTab();
	void checkMoveCunter(){ if (moves_cunter > MOVE_TAB_SIZE - 1) moves_cunter = 0; }
	void setMoveCounter(int moves_cunter){ this->moves_cunter = moves_cunter; }
	void resetCmpTable();
	void resetMoveTable();

public:
	int cmp;
	int *temp;
	int *cmp_color;
	int **color;
	char *solv_moves;
	int moves_cunter;
};

