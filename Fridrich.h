#pragma once
#include "Movements.h"
#include "FridrichHelper.h"
#include <stdio.h>

class Fridrich
{
public:
	Fridrich();
	~Fridrich();


public:
	bool F2Le(int,int,int);
	bool F2L();
	void F2L4();
	bool OLLe();
	void OLL();
	bool PLLe();
	void PLL();
	void cross();
	void initialize(Movements *,int**);
	void setTmpColor(int **);
	void ResteF2Lcounters(){ x_counter = 0; x2_counter = 0; y_counter = 0; }

private:
	void firstUpEdge(int, int);
	void secondUpEdge(int, int);
	void thirdUpEdge(int, int);
	void fourthUpEdge(int, int);

public:
	FridrichHelper *help;

private:
	Movements *move;
	int **color;
    int **temp_color;
	int f2l_reset_counter;
	int x_counter;
	int x2_counter;
	int y_counter;


};

