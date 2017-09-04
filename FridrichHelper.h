#pragma once
#include "Movements.h"

class FridrichHelper
{
public:
	FridrichHelper();
	FridrichHelper(Movements *move) :move(move){};


public:
	void removeRepetitiveMoves();
	void copyTab(int**,int**);


private:
	Movements *move;

};

