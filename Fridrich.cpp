#include "Fridrich.h"


Fridrich::Fridrich()
{
}


Fridrich::~Fridrich()
{
}

void Fridrich::initialize(Movements *move, int ** temp_color)
{
	help = new FridrichHelper(move);
	this->move = move;
	this->color = move->color;
	this->temp_color = temp_color;
	f2l_reset_counter = 0;
	x_counter = 0;
	x2_counter = 0;
	y_counter = 0;
}

void Fridrich::setTmpColor(int ** temp_color)
{
	this->temp_color = temp_color;
}


void Fridrich::cross()
{
	firstUpEdge(color[1][4], color[0][4]);
	secondUpEdge(color[1][4], color[4][4]);
	thirdUpEdge(color[1][4], color[2][4]);
	fourthUpEdge(color[1][4], color[5][4]);
	help->removeRepetitiveMoves();
}

void Fridrich::firstUpEdge(int c1, int c2)
{

	if (color[0][1] == c1 && color[4][3] == c2)
	{
		move->backP();
		move->upP();
	}
	else if (color[0][3] == c1 && color[3][5] == c2)
	{
		move->left();
		move->backP();
		move->upP();
	}
	else if (color[0][5] == c1 && color[1][3] == c2)
	{
		move->leftP();
		move->backP();
		move->upP();
	}
	else if (color[0][7] == c1 && color[5][3] == c2)
	{
		move->front();
		move->up();
	}
	else if (color[1][1] == c1 && color[4][7] == c2)
	{
		move->upP();
	}
	else if (color[1][3] == c1 && color[0][5] == c2)
	{

	}
	else if (color[1][5] == c1 && color[2][3] == c2)
	{
		move->up();
		move->up();
	}
	else if (color[1][7] == c1 && color[5][1] == c2)
	{
		move->up();
	}
	else if (color[2][1] == c1 && color[4][5] == c2)
	{
		move->back();
		move->upP();
	}
	else if (color[2][3] == c1 && color[1][5] == c2)
	{
		move->right();
		move->back();
		move->upP();
	}
	else if (color[2][5] == c1 && color[3][3] == c2)
	{
		move->rightP();
		move->back();
		move->upP();
	}
	else if (color[2][7] == c1 && color[5][5] == c2)
	{
		move->right();
		move->right();
		move->back();
		move->upP();
	}
	else if (color[3][1] == c1 && color[4][1] == c2)
	{
		move->back();
		move->back();
		move->upP();
	}
	else if (color[3][3] == c1 && color[2][5] == c2)
	{
		move->right();
		move->right();
		move->up();
		move->up();
	}
	else if (color[3][5] == c1 && color[0][3] == c2)
	{
		move->left();
		move->left();
	}
	else if (color[3][7] == c1 && color[5][7] == c2)
	{
		move->downP();
		move->left();
		move->left();
	}
	else if (color[4][1] == c1 && color[3][1] == c2)
	{
		move->backP();
		move->left();
	}
	else if (color[4][3] == c1 && color[0][1] == c2)
	{
		move->left();
	}
	else if (color[4][5] == c1 && color[2][1] == c2)
	{
		move->back();
		move->back();
		move->left();
	}
	else if (color[4][7] == c1 && color[1][1] == c2)
	{
		move->back();
		move->left();
	}
	else if (color[5][1] == c1 && color[1][7] == c2)
	{
		move->frontP();
		move->leftP();
	}
	else if (color[5][3] == c1 && color[0][7] == c2)
	{
		move->leftP();
	}
	else if (color[5][5] == c1 && color[2][7] == c2)
	{
		move->front();
		move->front();
		move->leftP();
	}
	else if (color[5][7] == c1 && color[3][7] == c2)
	{
		move->front();
		move->leftP();
	}

}

void Fridrich::secondUpEdge(int c1, int c2)
{


	if (color[0][1] == c1 && color[4][3] == c2)
	{
		move->backP();
	}
	else if (color[0][3] == c1 && color[3][5] == c2)
	{
		move->leftP();
		move->front();
		move->up();
		move->up();
		move->left();
	}
	else if (color[0][5] == c1 && color[1][3] == c2)
	{

	}
	else if (color[0][7] == c1 && color[5][3] == c2)
	{
		move->front();
		move->leftP();
		move->up();
		move->up();
		move->left();
	}
	else if (color[1][1] == c1 && color[4][7] == c2)
	{

	}
	else if (color[1][3] == c1 && color[0][5] == c2)
	{
	}
	else if (color[1][5] == c1 && color[2][3] == c2)
	{
		move->left();
		move->upP();
		move->leftP();

	}
	else if (color[1][7] == c1 && color[5][1] == c2)
	{
		move->leftP();
		move->up();
		move->up();
		move->left();
	}
	else if (color[2][1] == c1 && color[4][5] == c2)
	{
		move->back();
	}
	else if (color[2][3] == c1 && color[1][5] == c2)
	{
		move->right();
		move->back();
	}
	else if (color[3][5] == c1 && color[3][3] == c2)
	{
		move->rightP();
		move->back();
	}
	else if (color[2][7] == c1 && color[5][5] == c2)
	{
		move->right();
		move->right();
		move->back();
	}
	else if (color[3][1] == c1 && color[4][1] == c2)
	{
		move->back();
		move->back();
	}
	else if (color[3][3] == c1 && color[2][5] == c2)
	{
		move->down();
		move->back();
		move->back();
	}
	else if (color[3][5] == c1 && color[0][3] == c2)
	{
		move->downP();
		move->back();
		move->back();
	}
	else if (color[3][7] == c1 && color[5][7] == c2)
	{
		move->down();
		move->down();
		move->back();
		move->back();
	}
	else if (color[4][1] == c1 && color[3][1] == c2)
	{
		move->downP();
		move->rightP();
		move->back();
	}
	else if (color[4][3] == c1 && color[0][1] == c2)
	{
		move->back();
		move->downP();
		move->rightP();
		move->back();
	}
	else if (color[4][5] == c1 && color[2][1] == c2)
	{
		move->backP();
		move->downP();
		move->rightP();
		move->back();
	}
	else if (color[4][7] == c1 && color[1][1] == c2)
	{
		move->backP();
		move->up();
		move->rightP();
		move->upP();
	}
	else if (color[5][1] == c1 && color[1][7] == c2)
	{
		move->front();
		move->up();
		move->right();
		move->upP();
	}
	else if (color[5][3] == c1 && color[0][7] == c2)
	{
		move->front();
		move->front();
		move->up();
		move->right();
		move->upP();
	}
	else if (color[5][5] == c1 && color[2][7] == c2)
	{
		move->up();
		move->right();
		move->upP();
	}
	else if (color[5][7] == c1 && color[3][7] == c2)
	{
		move->frontP();
		move->up();
		move->right();
		move->upP();
	}

}

void Fridrich::thirdUpEdge(int c1, int c2)
{
	if (color[0][1] == c1 && color[4][3] == c2)
	{
		move->upP();
		move->backP();
		move->up();
	}
	else if (color[0][3] == c1 && color[3][5] == c2)
	{
		move->down();
		move->frontP();
		move->right();
	}
	else if (color[0][5] == c1 && color[1][3] == c2)
	{

	}
	else if (color[0][7] == c1 && color[5][3] == c2)
	{
		move->up();
		move->front();
		move->upP();
	}
	else if (color[1][1] == c1 && color[4][7] == c2)
	{

	}
	else if (color[1][3] == c1 && color[0][5] == c2)
	{

	}
	else if (color[1][5] == c1 && color[2][3] == c2)
	{

	}
	else if (color[1][7] == c1 && color[5][1] == c2)
	{
		move->frontP();
		move->up();
		move->front();
		move->upP();
	}
	else if (color[2][1] == c1 && color[4][5] == c2)
	{
		move->upP();
		move->back();
		move->up();
	}
	else if (color[2][3] == c1 && color[1][5] == c2)
	{
		move->right();
		move->upP();
		move->back();
		move->up();
	}
	else if (color[2][5] == c1 && color[3][3] == c2)
	{
		move->rightP();
		move->upP();
		move->back();
		move->up();
	}
	else if (color[2][7] == c1 && color[5][5] == c2)
	{
		move->right();
		move->right();
		move->upP();
		move->back();
		move->up();
	}
	else if (color[3][1] == c1 && color[4][1] == c2)
	{
		move->upP();
		move->back();
		move->back();
		move->up();
	}
	else if (color[3][3] == c1 && color[2][5] == c2)
	{
		move->down();
		move->upP();
		move->back();
		move->back();
		move->up();
	}
	else if (color[3][5] == c1 && color[0][3] == c2)
	{
		move->downP();
		move->upP();
		move->back();
		move->back();
		move->up();
	}
	else if (color[3][7] == c1 && color[5][7] == c2)
	{
		move->down();
		move->down();
		move->upP();
		move->back();
		move->back();
		move->up();
	}
	else if (color[4][1] == c1 && color[3][1] == c2)
	{
		move->down();
		move->down();
		move->frontP();
		move->right();
	}
	else if (color[4][3] == c1 && color[0][1] == c2)
	{
		move->up();
		move->up();
		move->left();
		move->up();
		move->up();
	}
	else if (color[4][5] == c1 && color[2][1] == c2)
	{
		move->rightP();
	}
	else if (color[4][7] == c1 && color[1][1] == c2)
	{

	}
	else if (color[5][1] == c1 && color[1][7] == c2)
	{
		move->front();
		move->right();
	}
	else if (color[5][3] == c1 && color[0][7] == c2)
	{
		move->front();
		move->front();
		move->right();
	}
	else if (color[5][5] == c1 && color[2][7] == c2)
	{
		move->right();// PC();
	}
	else if (color[5][7] == c1 && color[3][7] == c2)
	{
		move->frontP();
		move->right();
	}
}

void Fridrich::fourthUpEdge(int c1, int c2)
{
	if (color[0][1] == c1 && color[4][3] == c2)
	{
		move->up();
		move->up();
		move->backP();
		move->up();
		move->up();
	}
	else if (color[0][3] == c1 && color[3][5] == c2)
	{
		move->up();
		move->left();
		move->up();
		move->backP();
		move->up();
		move->up();
	}
	else if (color[0][5] == c1 && color[1][3] == c2)
	{

	}
	else if (color[0][7] == c1 && color[5][3] == c2)
	{
		move->front();
	}
	else if (color[1][1] == c1 && color[4][7] == c2)
	{

	}
	else if (color[1][3] == c1 && color[0][5] == c2)
	{

	}
	else if (color[1][5] == c1 && color[2][3] == c2)
	{

	}
	else if (color[1][7] == c1 && color[5][1] == c2)
	{

	}
	else if (color[2][1] == c1 && color[4][5] == c2)
	{
		move->up();
		move->up();
		move->back();
		move->up();
		move->up();
	}
	else if (color[2][3] == c1 && color[1][5] == c2)
	{

	}
	else if (color[2][5] == c1 && color[3][3] == c2)
	{
		move->upP();
		move->right();
		move->up();
		move->frontP();
	}
	else if (color[2][7] == c1 && color[5][5] == c2)
	{
		move->frontP();
	}
	else if (color[3][1] == c1 && color[4][1] == c2)
	{
		move->up();
		move->up();
		move->back();
		move->back();
		move->up();
		move->up();
	}
	else if (color[3][3] == c1 && color[2][5] == c2)
	{
		move->down();
		move->up();
		move->up();
		move->back();
		move->back();
		move->up();
		move->up();
	}
	else if (color[3][5] == c1 && color[0][3] == c2)
	{
		move->downP();
		move->up();
		move->up();
		move->back();
		move->back();
		move->up();
		move->up();
	}
	else if (color[3][7] == c1 && color[5][7] == c2)
	{
		move->down();
		move->down();
		move->up();
		move->up();
		move->back();
		move->back();
		move->up();
		move->up();
	}
	else if (color[4][1] == c1 && color[3][1] == c2)
	{
		move->up();
		move->up();
		move->back();
		move->up();
		move->rightP();
		move->up();
	}
	else if (color[4][3] == c1 && color[0][1] == c2)
	{
		move->up();
		move->left();
		move->upP();
	}
	else if (color[4][5] == c1 && color[2][1] == c2)
	{
		move->upP();
		move->rightP();
		move->up();
	}
	else if (color[4][7] == c1 && color[1][1] == c2)
	{

	}
	else if (color[5][1] == c1 && color[1][7] == c2)
	{
		move->front();
		move->upP();
		move->right();
		move->up();
	}
	else if (color[5][3] == c1 && color[0][7] == c2)
	{
		move->up();
		move->leftP();
		move->upP();
	}
	else if (color[5][5] == c1 && color[2][7] == c2)
	{
		move->upP();
		move->right();
		move->up();
	}
	else if (color[5][7] == c1 && color[3][7] == c2)
	{
		move->frontP();
		move->upP();
		move->right();
		move->up();
	}
}


bool Fridrich::F2Le(int c1, int c2, int c3)//c1=0,c2=4
{
	// 1
	if (color[0][2] == c1 && color[4][3] == c1 &&
		color[4][6] == c2 && color[0][1] == c2)
	{
		move->backP();
		move->left();
		move->back();
		move->leftP();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 2
	else if (color[0][2] == c1 && color[3][1] == c1 &&
			 color[4][6] == c2 && color[4][1] == c2)
	{
		move->downP();
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 3
	else if (color[0][2] == c1 && color[0][3] == c1 &&
			 color[4][6] == c2 && color[3][5] == c2)
	{
		move->down();
		move->back();
		move->downP();
		move->backP();
		move->downP();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 4
	else if (color[4][6] == c1 && color[0][3] == c1 &&
			 color[1][0] == c2 && color[3][5] == c2 &&
			 color[0][2] == c3)
	{
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 5
	else if (color[4][6] == c1 && color[3][1] == c1 &&
			 color[1][0] == c2 && color[4][1] == c2 &&
			 color[0][2] == c3)
	{
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 6
	else if (color[4][6] == c1 && color[0][5] == c1 &&
			 color[1][0] == c2 && color[4][3] == c2 &&
			 color[0][2] == c3)
	{
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 7
	else if (color[4][6] == c1 && color[4][3] == c1 &&
			 color[1][0] == c2 && color[0][1] == c2 &&
			 color[0][2] == c3)
	{
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->down();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 8
	else if (color[3][1] == c1 && color[1][0] == c1 &&
			 color[0][2] == c2 && color[4][1] == c2 &&
			 color[4][6] == c3)
	{
		move->back();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 9
	else if (color[0][3] == c1 && color[1][0] == c1 &&
			 color[0][2] == c2 && color[3][5] == c2 &&
			 color[4][6] == c3)
	{
		move->leftP();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 10
	else if (color[0][1] == c1 && color[1][0] == c1 &&
			 color[0][2] == c2 && color[4][3] == c2 &&
			 color[4][6] == c3)
	{
		move->back();
		move->down();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 11
	else if (color[4][3] == c1 && color[1][0] == c1 &&
			 color[0][1] == c2 && color[0][2] == c2 &&
			 color[4][6] == c3)
	{
		move->back();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 12
	else if (color[0][1] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[4][3] == c2 &&
			 color[3][2] == c3)
	{
		move->back();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 13
	else if (color[4][3] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[0][1] == c2 &&
			 color[3][2] == c3)
	{
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 14
	else if (color[3][1] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[4][1] == c2 &&
			 color[3][2] == c3)
	{
		move->back();
		move->down();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 15
	else if (color[4][1] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[3][1] == c2 &&
			 color[3][2] == c3)
	{
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 16
	else if (color[0][3] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[3][5] == c2 &&
			 color[3][2] == c3)
	{
		move->leftP();
		move->down();
		move->down();
		move->left();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 17
	else if (color[3][5] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[0][3] == c2 &&
			 color[3][2] == c3)
	{
		move->back();
		move->down();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 18
	else if (color[3][7] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[5][7] == c2 &&
			 color[3][2] == c3)
	{
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 19
	else if (color[5][7] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[3][7] == c2 &&
			 color[3][2] == c3)
	{
		move->downP();
		move->leftP();
		move->down();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 20
	else if (color[2][5] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[3][3] == c2 &&
			 color[3][2] == c3)
	{
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 21
	else if (color[3][3] == c1 && color[4][0] == c1 &&
			 color[0][0] == c2 && color[2][5] == c2 &&
			 color[3][2] == c3)
	{
		move->down();
		move->back();
		move->down();
		move->down();
		move->backP();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 22
	else if (color[0][0] == c1 && color[0][1] == c1 &&
			 color[3][2] == c2 && color[4][3] == c2 &&
			 color[4][0] == c3)
	{
		move->down();
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 23
	else if (color[0][0] == c1 && color[4][3] == c1 &&
			 color[3][2] == c2 && color[0][1] == c2 &&
			 color[4][0] == c3)
	{
		move->down();
		move->leftP();
		move->downP();
		move->left();
		move->downP();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 24
	else if (color[0][0] == c1 && color[3][1] == c1 &&
			 color[3][2] == c2 && color[4][1] == c2 &&
			 color[4][0] == c3)
	{
		move->downP();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 25
	else if (color[0][0] == c1 && color[4][1] == c1 &&
			 color[3][2] == c2 && color[3][1] == c2 &&
			 color[4][0] == c3)
	{
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 26
	else if (color[0][0] == c1 && color[0][3] == c1 &&
			 color[3][2] == c2 && color[3][5] == c2 &&
			 color[4][0] == c3)
	{
		move->downP();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 27
	else if (color[0][0] == c1 && color[3][5] == c1 &&
			 color[3][2] == c2 && color[0][3] == c2 &&
			 color[4][0] == c3)
	{
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 28
	else if (color[0][0] == c1 && color[3][3] == c1 &&
			 color[3][2] == c2 && color[2][5] == c2 &&
			 color[4][0] == c3)
	{	
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 29
	else if (color[0][0] == c1 && color[2][5] == c1 &&
			 color[3][2] == c2 && color[3][3] == c2 &&
			 color[4][0] == c3)
	{
		move->down();
		move->leftP();
		move->down();
		move->down();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 30
	else if (color[0][0] == c1 && color[5][7] == c1 &&
			 color[3][2] == c2 && color[3][7] == c2 &&
			 color[4][0] == c3)
	{
		move->down();
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 31
	else if (color[0][0] == c1 && color[3][7] == c1 &&
			 color[3][2] == c2 && color[5][7] == c2 &&
			 color[4][0] == c3)
	{
		move->downP();
		move->back();
		move->down();
		move->backP();
		move->down();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 32
	else if (color[0][1] == c1 && color[3][2] == c1 &&
			 color[4][3] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->downP();
		move->back();
		move->downP();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 33
	else if (color[4][3] == c1 && color[3][2] == c1 &&
			 color[0][1] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->downP();
		move->back();
		move->down();
		move->backP();
		move->down();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 34
	else if (color[3][1] == c1 && color[3][2] == c1 &&
			 color[4][1] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 35
	else if (color[4][1] == c1 && color[3][2] == c1 &&
			 color[3][1] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->leftP();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->down();
		move->left();

		return true;
	}

	// 36
	else if (color[0][3] == c1 && color[3][2] == c1 &&
			 color[3][5] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->down();
		move->leftP();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 37
	else if (color[3][5] == c1 && color[3][2] == c1 &&
			 color[0][3] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->down();
		move->back();
		move->down();
		move->backP();

		return true;
	}

	// 38
	else if (color[3][3] == c1 && color[3][2] == c1 &&
			 color[2][5] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->downP();
		move->back();
		move->down();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 39
	else if (color[2][5] == c1 && color[3][2] == c1 &&
			 color[3][3] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->down();
		move->leftP();
		move->downP();
		move->left();
		move->downP();
		move->leftP();
		move->downP();
		move->left();

		return true;
	}

	// 40
	else if (color[3][7] == c1 && color[3][2] == c1 &&
			 color[5][7] == c2 && color[4][0] == c2 &&
			 color[0][0] == c3)
	{
		move->downP();
		move->back();
		move->down();
		move->down();
		move->backP();
		move->down();
		move->down();
		move->back();
		move->downP();
		move->backP();

		return true;
	}

	// 41
	else if (color[5][7] == c1 && color[3][2] == c1 &&
			 color[3][7] == c2 && color[4][0] == c2  &&
			 color[0][0] == c3)
	{
		move->leftP();
		move->downP();
		move->left();

		return true;

	}
	else
	{
		return false;
	}


}


   /////////////////////////////

// F2La
void Fridrich::F2L4()
{
	F2L();

	while (color[1][0] != color[1][4] ||
		   color[1][2] != color[1][4] ||
		   color[1][6] != color[1][4] ||
		   color[1][8] != color[1][4])
	{
		f2l_reset_counter = 0;
		help->copyTab(temp_color,color);
		x_counter++;

		if (x_counter > 3)
		{
			y_counter++;
			x_counter = 0;
		}

		if (y_counter > 3)
		{
			x2_counter++;
			y_counter = 1;
			x_counter = 0;
		}

		if (x2_counter > 3)
		{
			break;
		}

		for (int j = 0; j < x2_counter; j++)
		{
			move->moves_cunter = 0 + f2l_reset_counter;
			move->rotateXaxis();
			f2l_reset_counter++;
		}

		for (int j = 0; j < y_counter; j++)
		{
			move->moves_cunter = 0 + f2l_reset_counter;
			move->rotateYaxis();
			f2l_reset_counter++;
		}

		for (int j = 0; j < x_counter; j++)
		{
			move->moves_cunter = 0 + f2l_reset_counter;
			move->rotateXaxis();
			f2l_reset_counter++;
		}
			
		cross();
		F2L();
	}

	if (color[0][1] != color[0][4] || color[0][7] != color[0][4] ||
		color[2][1] != color[2][4] || color[2][7] != color[2][4] ||
		color[4][3] != color[4][4] || color[4][5] != color[4][4] ||
		color[5][3] != color[5][4] || color[5][5] != color[5][4] )
	{
		move->down();
		F2L();
	}
	help->removeRepetitiveMoves();
}


bool Fridrich::F2L()
{
		for (int j = 0; j < 4; j++)
		{
			for (int c = 0; c < 4; c++)
			{
				if (F2Le(color[0][4],color[4][4],color[1][4]) == false)
				{
					move->down();
				}

			}
			if (F2Le(color[0][4], color[4][4], color[1][4]) == false)
			{
				move->rotateYaxis();
			}
		}	
	return false;
}

// OLL

bool Fridrich::OLLe()
{
	// all edge corect
	if (color[3][1] == color[3][4] && color[3][3] == color[3][4] &&
		color[3][5] == color[3][4] && color[3][7] == color[3][4])
	{
		// 1
		if (color[4][0] == color[3][4] &&
			color[4][2] == color[3][4] &&
			color[5][6] == color[3][4] &&
			color[5][8] == color[3][4])
		{
			move->left();
			move->down();
			move->down();
			move->leftP();
			move->downP();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->left();
			move->downP();
			move->leftP();

			return true;
		}

		// 2
		else if (color[5][6] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[2][2] == color[3][4] &&
				 color[2][8] == color[3][4])
		{
			move->left();
			move->down();
			move->down();
			move->left();
			move->left();
			move->downP();
			move->left();
			move->left();
			move->downP();
			move->left();
			move->left();
			move->down();
			move->down();
			move->left();

			return true;
		}

		// 3
		else if (color[4][2] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[0][6] == color[3][4])
		{
			move->left();
			move->backP();
			move->leftP();
			move->front();
			move->left();
			move->back();
			move->leftP();
			move->frontP();

			return true;
		}

		// 4
		else if (color[4][0] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[4][2] == color[3][4])
		{
			move->left();
			move->left();
			move->upP();
			move->left();
			move->down();
			move->down();
			move->leftP();
			move->up();
			move->left();
			move->down();
			move->down();
			move->left();

			return true;
		}

		// 5
		else if (color[0][6] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[2][8] == color[3][4])
		{
			move->left();
			move->back();
			move->leftP();
			move->front();
			move->left();
			move->backP();
			move->leftP();
			move->frontP();

			return true;
		}

		// 6
		else if (color[2][2] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->rightP();
			move->downP();
			move->right();
			move->downP();
			move->rightP();
			move->down();
			move->down();
			move->right();

			return true;
		}

		// 7
		else if (color[0][0] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->left();
			move->down();
			move->leftP();
			move->down();
			move->left();
			move->down();
			move->down();
			move->leftP();

			return true;
		}
	}

	// dot shape
	if (color[0][3] == color[3][4] && color[2][5] == color[3][4] &&
		color[4][1] == color[3][4] && color[5][7] == color[3][4])
	{
		// 8
		if (color[0][0] == color[3][4] &&
			color[0][6] == color[3][4] &&
			color[2][2] == color[3][4] &&
			color[2][8] == color[3][4])
		{
			move->left();
			move->down();
			move->down();
			move->left();
			move->left();
			move->front();
			move->left();
			move->frontP();
			move->down();
			move->down();
			move->leftP();
			move->front();
			move->left();
			move->frontP();

			return true;
		}

		// 9
		else if (color[0][0] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->right();
			move->frontP();
			move->rightP();
			move->front();
			move->down();
			move->down();
			move->front();
			move->downP();
			move->left();
			move->downP();
			move->leftP();
			move->frontP();

			return true;
		}

		// 10
		else if (color[2][2] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][8] == color[3][4])
		{
			move->left();
			move->down();
			move->down();
			move->left();
			move->left();
			move->front();
			move->left();
			move->frontP();
			move->down();
			move->down();
			move->right();
			move->leftP(); // ?
			move->front();
			move->left();
			move->frontP();
			move->rightP();

			return true;
		}

		// 11
		else if (color[2][2] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->front();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->frontP();
			move->back();
			move->down();
			move->right();
			move->downP();
			move->rightP();
			move->backP();

			return true;
		}

		// 12
		else if (color[0][6] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][2] == color[3][4])
		{
			move->leftP();
			move->down();
			move->down();
			move->front();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->front();
			move->front();
			move->down();
			move->down();
			move->front();
			move->left();

			return true;
		}

		// 13 
		else if (color[0][0] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->right();
			move->leftP();//?
			move->front();
			move->leftP();
			move->up();
			move->up();
			move->left();
			move->front();
			move->rightP();
			move->front();
			move->right();
			move->right();
			move->leftP();

			return true;
		}

		// 14 
		else if (color[2][2] == color[3][4] &&
				 color[3][8] == color[3][4] &&
			   	 color[4][0] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->right();
			move->leftP();//?
			move->frontP();
			move->right();
			move->up();
			move->up();
			move->rightP();
			move->frontP();
			move->left();
			move->frontP();
			move->left();
			move->left();
			move->right();

			return true;
		}

		// 15 
		else if (color[3][0] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[3][8] == color[3][4])
		{
			move->right();
			move->leftP();//?
			move->front();
			move->left();
			move->front();
			move->leftP();
			move->frontP();
			move->right();
			move->right();
			move->leftP();
			move->leftP();
			move->back();
			move->left();
			move->backP();
			move->rightP(); // ?

			return true;
		}

	}

	// P shape
	if ((color[3][1] == color[3][4] && color[5][7] == color[3][4]) &&
	   ((color[3][2] == color[3][4] && color[3][5] == color[3][4] && color[3][8] == color[3][4]) ||
		(color[3][0] == color[3][4] && color[3][3] == color[3][4] && color[3][6] == color[3][4])))
	{
		// 16
		if (color[2][5] == color[3][4] &&
			color[4][2] == color[3][4] &&
			color[5][8] == color[3][4])
		{
			move->leftP();
			move->downP();
			move->front();
			move->down();
			move->left();
			move->downP();
			move->leftP();
			move->frontP();
			move->left();

			return true;
		}

		// 17
		else if (color[0][3] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->right();
			move->down();
			move->frontP();
			move->downP();
			move->rightP();
			move->down();
			move->right();
			move->front();
			move->rightP();

			return true;
		}

		// 18
		else if (color[0][0] == color[3][4] &&
				 color[0][3] == color[3][4] &&
				 color[0][6] == color[3][4])
		{
			move->front();
			move->down();
			move->left();
			move->downP();
			move->leftP();
			move->frontP();

			return true;
		}

		// 19
		else if (color[2][2] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[2][8] == color[3][4])
		{
			move->frontP();
			move->downP();
			move->rightP();
			move->down();
			move->right();
			move->front();

			return true;
		}
	}

	// W shape
	if ((color[3][1] == color[3][4] && color[5][7] == color[3][4]) &&
	   ((color[0][3] == color[3][4] && color[0][6] == color[3][4] && color[4][2] == color[3][4]) ||
		(color[2][5] == color[3][4] && color[2][8] == color[3][4] && color[4][0] == color[3][4])))
	{
		// 20
		if (color[3][0] == color[3][4] &&
			color[3][5] == color[3][4] &&
			color[3][8] == color[3][4])
		{
			move->rightP();
			move->downP();
			move->right();
			move->downP();
			move->rightP();
			move->down();
			move->right();
			move->down();
			move->right();
			move->frontP();
			move->rightP();
			move->front();

			return true;
		}

		// 21
		else if (color[3][2] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[3][6] == color[3][4])
		{
			move->left();
			move->down();
			move->leftP();
			move->down();
			move->left();
			move->downP();
			move->leftP();
			move->downP();
			move->leftP();
			move->front();
			move->left();
			move->frontP();

			return true;
		}
	}

	// small l shape 1
	if (color[2][2] == color[3][4] && color[2][8] == color[3][4] &&
		color[3][1] == color[3][4] && color[5][7] == color[3][4])
	{
		// 22
		if (color[0][0] == color[3][4] &&
			color[0][3] == color[3][4] &&
			color[0][6] == color[3][4] &&
			color[3][3] == color[3][4])
		{
			move->leftP();
			move->frontP();
			move->right();
			move->frontP();
			move->rightP();
			move->front();
			move->right();
			move->frontP();
			move->rightP();
			move->front();
			move->front();
			move->left();

			return true;
		}

		// 23
		else if (color[0][0] == color[3][4] &&
				 color[0][6] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][5] == color[3][4])
		{
			move->right();
			move->front();
			move->leftP();
			move->front();
			move->left();
			move->frontP();
			move->leftP();
			move->front();
			move->left();
			move->front();
			move->front();
			move->rightP();

			return true;
		}

		// 24  <---> (25 on webside) 
		if (color[0][3] == color[3][4] &&
			color[3][3] == color[3][4] &&
			color[4][0] == color[3][4] &&
			color[5][6] == color[3][4])
		{
			move->front();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->frontP();

			return true;
		}
	}

	// small l shape 2
	else if (color[0][0] == color[3][4] && color[0][6] == color[3][4] &&
			 color[2][5] == color[3][4] && color[4][2] == color[3][4])
	{
		// 25  <---> (24 on webside) 
		if (color[3][1] == color[3][4] &&
			color[3][5] == color[3][4] &&
			color[5][7] == color[3][4] &&
			color[5][8] == color[3][4])
		{
			move->frontP();
			move->rightP();
			move->downP();
			move->right();
			move->down();
			move->rightP();
			move->downP();
			move->right();
			move->down();
			move->front();

			return true;
		}
	}

	// small l shape 3
	if ((color[3][7] == color[3][4] && color[4][1] == color[3][4]) &&
	   ((color[0][3] == color[3][4] && color[4][2] == color[3][4]) ||
		(color[2][5] == color[3][4] && color[4][0] == color[3][4])))
	{
		// 26
		if (color[2][2] == color[3][4] &&
			color[2][8] == color[3][4] &&
			color[3][5] == color[3][4] &&
			color[5][6] == color[3][4])
		{
			move->rightP();
			move->back();
			move->right();
			move->right();
			move->frontP();
			move->right();
			move->right();
			move->backP();
			move->right();
			move->right();
			move->front();
			move->rightP();

			return true;
		}

		// 27
		else if (color[0][0] == color[3][4] &&
				 color[0][6] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->left();
			move->backP();
			move->left();
			move->left();
			move->back();
			move->left();
			move->left();
			move->back();
			move->left();
			move->left();
			move->backP();
			move->left();

			return true;
		}

		// 28
		else if (color[0][6] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->rightP();
			move->downP();
			move->right();
			move->back();
			move->rightP();
			move->backP();
			move->down();
			move->back();
			move->right();
			move->backP();

			return true;
		}

		// 29
		else if (color[2][8] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->left();
			move->down();
			move->leftP();
			move->backP();
			move->left();
			move->back();
			move->downP();
			move->backP();
			move->leftP();
			move->back();

			return true;
		}
	}

	// C shape 
	if (color[0][6] == color[3][4] && color[3][0] == color[3][4])
	{
		// 30
		if (color[2][8] == color[3][4] &&
			color[3][2] == color[3][4] &&
			color[3][3] == color[3][4] &&
			color[3][5] == color[3][4] &&
			color[4][1] == color[3][4] &&
			color[5][7] == color[3][4])
		{
			move->leftP();
			move->downP();
			move->left();
			move->down();
			move->front();
			move->left();
			move->backP();
			move->leftP();
			move->back();
			move->frontP();

			return true;
		}

		// 31
		else if (color[0][0] == color[3][4] &&
				 color[0][3] == color[3][4] &&
				 color[2][5] == color[3][4] &&
	   			 color[3][1] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[3][7] == color[3][4])
		{
			move->leftP();
			move->downP();
			move->leftP();
			move->front();
			move->left();
			move->frontP();
			move->down();
			move->left();

			return true;
		}
	}

	// T shape 
	if (color[3][2] == color[3][4] && color[3][3] == color[3][4] &&
		color[3][5] == color[3][4] && color[3][8] == color[3][4] &&
		color[4][1] == color[3][4] && color[5][7] == color[3][4])
	{
		// 32
		if (color[4][2] == color[3][4] &&
			color[5][8] == color[3][4])
		{
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->leftP();
			move->front();
			move->left();
			move->frontP();

			return true;
		}

		// 33
		else if (color[2][2] == color[3][ 4] &&
				 color[2][8] == color[3][ 4])
		{
			move->front();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->frontP();

			return true;
		}
	}

	// I shape 
	if (color[0][0] == color[3][4] && color[0][6] == color[3][4])
	{
		// 34
		if (color[0][3] == color[3][4] &&
			color[2][2] == color[3][4] &&
			color[2][5] == color[3][4] &&
			color[2][8] == color[3][4] &&
			color[3][1] == color[3][4] &&
			color[3][7] == color[3][4])
		{
			move->left();
			move->down();
			move->down();
			move->left();
			move->left();
			move->downP();
			move->left();
			move->downP();
			move->leftP();
			move->down();
			move->down();
			move->front();
			move->left();
			move->frontP();

			return true;
		}

		// 35
		else if (color[3][3] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[4][1] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[5][7] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->front();
			move->down();
			move->left();
			move->downP();
			move->leftP();
			move->down();
			move->left();
			move->downP();
			move->leftP();
			move->frontP();

			return true;
		}

		// 36
		else if (color[2][2] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[4][1] == color[3][4] &&
				 color[5][7] == color[3][4])
		{
			move->rightP();
			move->backP();
			move->right();
			move->downP();
			move->leftP();
			move->down();
			move->left();
			move->downP();
			move->leftP();
			move->down();
			move->left();
			move->rightP();
			move->back();
			move->right();

			return true;
		}

		// 37
		else if (color[0][3] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][1] == color[3][4] &&
				 color[3][7] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->leftP();
			move->downP();
			move->left();
			move->downP();
			move->leftP();
			move->down();
			move->frontP();
			move->down();
			move->front();
			move->left();

			return true;
		}
	}

	// square or s shape 
	if (color[3][1] == color[3][4] && color[5][7] == color[3][4])
	{
		// 38
		if (color[0][0] == color[3][4] &&
			color[0][3] == color[3][4] &&
			color[2][8] == color[3][4] &&
			color[3][0] == color[3][4] &&
			color[3][3] == color[3][4] &&
			color[5][6] == color[3][4])
		{
			move->leftP();
			move->front();
			move->front();
			move->right();
			move->front();
			move->rightP();
			move->front();
			move->left();

			return true;
		}

		// 39
		else if (color[0][6] == color[3][4] &&
				 color[2][2] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->right();
			move->front();
			move->front();
			move->leftP();
			move->frontP();
			move->left();
			move->frontP();
			move->rightP();

			return true;
		}

		// 40
		else if (color[0][6] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[4][2] == color[3][4])
		{
			move->leftP();
			move->up();
			move->up();
			move->left();
			move->left();
			move->backP();
			move->leftP();
			move->back();
			move->leftP();
			move->up();
			move->up();
			move->left();

			return true;
		}

		// 41
		else if (color[0][0] == color[3][4] &&
				 color[0][3] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->front();
			move->leftP();
			move->frontP();
			move->left();
			move->down();
			move->left();
			move->downP();
			move->leftP();

			return true;
		}

		// 42
		else if (color[0][0] == color[3][4] &&
				 color[0][3] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->right();
			move->front();
			move->leftP();
			move->front();
			move->left();
			move->front();
			move->front();
			move->rightP();

			return true;
		}

		// 43
		else if (color[2][2] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->leftP();
			move->frontP();
			move->right();
			move->frontP();
			move->rightP();
			move->front();
			move->front();
			move->left();

			return true;
		}

		// 44
		else if (color[0][3] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->leftP();
			move->right();
			move->right();
			move->front();
			move->rightP();
			move->front();
			move->right();
			move->front();
			move->front();
			move->rightP();
			move->front();
			move->rightP();
			move->left();

			return true;
		}

		// 45
		else if (color[0][6] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->right();
			move->left();
			move->left();
			move->frontP();
			move->left();
			move->frontP();
			move->leftP();
			move->front();
			move->front();
			move->left();
			move->frontP();
			move->rightP();
			move->left();

			return true;
		}

		// 46
		else if (color[0][0] == color[3][4] &&
				 color[2][2] == color[3][4] &&
				 color[2][5] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[3][8] == color[3][4])
		{
			move->frontP();
			move->right();
			move->frontP();
			move->right();
			move->right();
			move->down();
			move->right();
			move->down();
			move->rightP();
			move->downP();
			move->right();
			move->front();
			move->front();

			return true;
		}

		// 47
		else if (color[0][0] == color[3][4] &&
				 color[0][3] == color[3][4] &&// was 06
				 color[2][2] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[3][8] == color[3][4])
		{
			move->front();
			move->leftP();
			move->front();
			move->left();
			move->left();
			move->downP();
			move->leftP();
			move->downP();
			move->left();
			move->down();
			move->leftP();
			move->front();
			move->front();

			return true;
		}

		// 48 
		else if (color[0][3] == color[3][4] &&
				 color[2][2] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[3][2] == color[3][4] &&
				 color[3][3] == color[3][4] &&
				 color[3][8] == color[3][4])
		{
			move->leftP();
			move->front();
			move->left();
			move->frontP();
			move->leftP();
			move->front();
			move->left();
			move->frontP();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->left();
			move->down();
			move->leftP();

			return true;
		}

		// 49 
		else if (color[0][0] == color[3][4] &&
				 color[0][6] == color[3][4] &&
			   	 color[2][5] == color[3][4] &&
			 	 color[3][0] == color[3][4] &&
			 	 color[3][5] == color[3][4] &&
			 	 color[3][6] == color[3][4])
		{
			move->right();
			move->frontP();
			move->rightP();
			move->front();
			move->right();
			move->frontP();
			move->rightP();
			move->front();
			move->rightP();
			move->downP();
			move->right();
			move->down();
			move->rightP();
			move->downP();
			move->right();

			return true;
		}
	}

	// L shape 
	if (color[3][3] == color[3][4] && color[3][5] == color[3][4] &&
		color[4][1] == color[3][4] && color[5][7] == color[3][4])
	{
		// 50
		if (color[0][6] == color[3][4] &&
			color[3][2] == color[3][4] &&
			color[3][6] == color[3][4] &&
			color[4][2] == color[3][4])
		{
			move->right();
			move->frontP();
			move->rightP();
			move->downP();
			move->right();
			move->down();
			move->front();
			move->downP();
			move->rightP();

			return true;
		}

		// 51
		else if (color[2][8] == color[3][4] &&
				 color[3][0] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[4][0] == color[3][4])
		{
			move->leftP();
			move->front();
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->frontP();
			move->down();
			move->left();

			return true;
		}

		// 52
		else if (color[0][0] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[4][2] == color[3][4] &&
				 color[5][6] == color[3][4])
		{
			move->right();
			move->frontP();
			move->rightP();
			move->downP();
			move->right();
			move->front();
			move->rightP();
			move->frontP();
			move->down();
			move->front();

			return true;
		}

		// 53
		else if (color[2][2] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[4][0] == color[3][4] &&
				 color[5][8] == color[3][4])
		{
			move->leftP();
			move->front();
			move->left();
			move->down();
			move->leftP();
			move->frontP();
			move->left();
			move->front();
			move->downP();
			move->frontP();

			return true;
		}

		// 54
		else if (color[0][0] == color[3][4] &&
				 color[2][8] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[4][2] == color[3][4])
		{
			move->rightP();
			move->backP();
			move->right();
			move->leftP();
			move->downP();
			move->left();
			move->down();
			move->rightP();
			move->back();
			move->right();

			return true;
		}

		// 55
		else if (color[0][6] == color[3][4] &&
				 color[2][2] == color[3][4] &&
				 color[3][6] == color[3][4] &&
				 color[4][0] == color[3][4])
		{
			move->left();
			move->back();
			move->leftP();
			move->right();
			move->down();
			move->rightP();
			move->downP();
			move->left();
			move->backP();
			move->leftP();

			return true;
		}
	}

	// F or H orientation 
	if (color[3][0] == color[3][4] && color[3][2] == color[3][4] &&
		color[3][6] == color[3][4] && color[5][7] == color[3][4])
	{
		// 56
		if (color[0][3] == color[3][4] &&
			color[3][1] == color[3][4] &&
			color[3][3] == color[3][4] &&
			color[3][8] == color[3][4])
		{
			move->left();
			move->rightP();
			move->back();
			move->right();
			move->leftP();
			move->down();
			move->down();
			move->left();
			move->rightP();
			move->back();
			move->right();
			move->leftP();

			return true;
		}

		// 57
		else if (color[3][3] == color[3][4] &&
				 color[3][5] == color[3][4] &&
				 color[3][8] == color[3][4] &&
				 color[4][1] == color[3][4])
		{
			move->left();
			move->down();
			move->leftP();
			move->downP();
			move->right();
			move->leftP();
			move->front();
			move->left();
			move->frontP();
			move->rightP();

			return true;
		}
	}

	return false;
}

void Fridrich::OLL()
{
	for (int i = 0; i < 4; i++)
	{
		if(OLLe() == false) move->rotateYaxis();
		else break;
	}
	help->removeRepetitiveMoves();
}

// PLL

void Fridrich::PLL()
{
	for (int ii = 0; ii < 2; ii++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (PLLe() == false) move->rotateYaxis();
			else break;
		}


		for (int j = 0; j < 4; j++)
		{
			if (color[0][0] != color[0][4] || color[0][3] != color[0][4] || color[0][6] != color[0][4] ||
				color[2][2] != color[2][4] || color[2][5] != color[2][4] || color[2][8] != color[2][4] ||
				color[4][2] != color[4][4] || color[4][1] != color[4][4] || color[4][0] != color[4][4] ||
				color[5][6] != color[5][4] || color[5][7] != color[5][4] || color[5][8] != color[5][4])
			{
				move->down();
				for (int i = 0; i < 4; i++)
				{
					if (PLLe() == false) move->rotateYaxis();
					else break;
				}
			}
			else break;
		}
	}
	help->removeRepetitiveMoves();
}

bool Fridrich::PLLe()
{
	// A
	if (color[2][8] == color[4][4] && color[5][8] == color[2][4] &&
		color[2][2] == color[4][4] && color[4][2] == color[0][4] &&
		color[4][0] == color[5][4] && color[0][3] == color[2][4])
	{
		move->backP();
		move->left();
		move->backP();
		move->right();
		move->right();
		move->back();
		move->leftP();
		move->backP();
		move->right();
		move->right();
		move->back();
		move->back();

		return true;
	}

	// A'
	if (color[0][0] == color[4][4] && color[0][6] == color[4][4] &&
		color[2][2] == color[0][4] && color[5][6] == color[0][4] &&
		color[4][2] == color[5][4] && color[4][0] == color[2][4])
	{
		move->back();
		move->rightP();
		move->back();
		move->left();
		move->left();
		move->backP();
		move->right();
		move->back();
		move->left();
		move->left();
		move->back();
		move->back();

		return true;
	}

	// E
	if (color[0][6] == color[4][4] && color[2][8] == color[4][4] &&
		color[5][8] == color[2][4] && color[5][6] == color[0][4])
	{
		move->left();
		move->backP();
		move->leftP();
		move->front();
		move->left();
		move->back();
		move->leftP();
		move->frontP();
		move->left();
		move->back();
		move->leftP();
		move->front();
		move->left();
		move->backP();
		move->leftP();
		move->frontP();

		return true;
	}

	// F
	if (color[0][0] == color[4][4] && color[0][3] == color[2][4] &&
		color[2][2] == color[0][4] && color[4][0] == color[2][4] &&
		color[4][2] == color[0][4])
	{
		move->leftP();
		move->down();
		move->left();
		move->downP();
		move->left();
		move->left();
		move->frontP();
		move->downP();
		move->front();
		move->down();
		move->left();
		move->front();
		move->leftP();
		move->frontP();
		move->left();
		move->left();
		move->downP();

		return true;
	}

	// G
	if (color[4][2] == color[0][4] && color[4][1] == color[5][4] &&
		color[2][2] == color[5][4] && color[2][5] == color[4][4] &&
		color[5][0] == color[0][4] && color[0][6] == color[2][4] &&
		color[5][2] == color[4][4] && color[2][8] == color[5][4])
	{
		move->leftP();
		move->backP();
		move->left();
		move->back();
		move->back();
		move->up();
		move->rightP();
		move->down();
		move->right();
		move->downP();
		move->right();
		move->upP();
		move->back();
		move->back();

		return true;
	}

	// G'
	if (color[4][0] == color[0][4] && color[4][1] == color[5][4] &&
		color[0][3] == color[4][4] && color[5][1] == color[0][4] &&
		color[0][6] == color[5][4] && color[5][2] == color[2][4] &&
		color[5][0] == color[4][4] && color[2][8] == color[0][4])
	{
		move->right();
		move->down();
		move->rightP();
		move->back();
		move->back();
		move->upP();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->leftP();
		move->up();
		move->back();
		move->back();

		return true;
	}

	// G2
	if (color[4][2] == color[0][4] && color[4][1] == color[2][4] &&
		color[2][2] == color[4][4] && color[4][0] == color[5][4] &&
		color[5][0] == color[2][4] && color[2][5] == color[0][4] &&
		color[2][8] == color[4][4] && color[0][0] == color[2][4])
	{
		move->left();
		move->left();
		move->up();
		move->backP();
		move->down();
		move->backP();
		move->downP();
		move->back();
		move->upP();
		move->left();
		move->left();
		move->frontP();
		move->down();
		move->front();

		return true;
	}


	// G2'
	if (color[4][2] == color[5][4] && color[4][1] == color[0][4] &&
		color[2][2] == color[0][4] && color[4][0] == color[2][4] &&
		color[0][6] == color[2][4] && color[2][5] == color[4][4] &&
		color[5][2] == color[0][4] && color[0][0] == color[4][4])
	{
		move->right();
		move->right();
		move->upP();
		move->back();
		move->downP();
		move->back();
		move->down();
		move->backP();
		move->up();
		move->right();
		move->right();
		move->front();
		move->downP();
		move->frontP();

		return true;
	}

	// H
	if (color[4][1] == color[5][4] && color[5][7] == color[4][4] &&
		color[2][5] == color[0][4] && color[0][3] == color[2][4])
	{
		move->right();
		move->right();
		move->left();
		move->left();
		move->up();
		move->right();
		move->right();
		move->left();
		move->left();
		move->down();
		move->down();
		move->right();
		move->right();
		move->left();
		move->left();
		move->up();
		move->right();
		move->right();
		move->left();
		move->left();

		return true;
	}

	// J
	if (color[4][2] == color[2][4] && color[5][8] == color[2][4] &&
		color[2][5] == color[4][4] && color[4][1] == color[2][4] &&
		color[2][2] == color[5][4] && color[2][8] == color[5][4])
	{
		move->leftP();
		move->down();
		move->right();
		move->downP();
		move->left();
		move->down();
		move->down();
		move->rightP();
		move->down();
		move->right();
		move->down();
		move->down();
		move->rightP();

		return true;
	}

	// J'
	if (color[4][0] == color[0][4] && color[5][6] == color[0][4] &&
		color[0][3] == color[4][4] && color[4][1] == color[2][4] &&
		color[0][0] == color[5][4] && color[0][6] == color[5][4])
	{
		move->right();
		move->downP();
		move->leftP();
		move->down();
		move->rightP();
		move->down();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->down();
		move->left();

		return true;
	}

	// N
	if (color[4][1] == color[5][4] && color[5][7] == color[4][4] &&
		color[4][0] == color[5][4] && color[5][8] == color[4][4] &&
		color[2][8] == color[0][4] && color[0][0] == color[2][4])
	{
		move->right();
		move->downP();
		move->leftP();
		move->down();
		move->rightP();
		move->down();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->down();
		move->left();

		return true;
	}

	// N'
	if (color[4][2] == color[5][4] && color[5][7] == color[4][4] &&
		color[4][1] == color[5][4] && color[5][6] == color[4][4] &&
		color[2][2] == color[0][4] && color[0][6] == color[2][4])
	{
		move->right();
		move->downP();
		move->left();
		move->down();
		move->down();
		move->rightP();
		move->down();
		move->leftP();
		move->right();
		move->downP();
		move->left();
		move->down();
		move->down();
		move->rightP();
		move->down();
		move->leftP();
		move->downP();

		return true;
	}

	// R
	if (color[4][2] == color[0][4] && color[4][0] == color[2][4] &&
		color[5][7] == color[0][4] && color[0][3] == color[5][4] &&
		color[2][2] == color[4][4] && color[0][0] == color[4][4])
	{
		move->leftP();
		move->down();
		move->down();
		move->left();
		move->down();
		move->down();
		move->leftP();
		move->front();
		move->left();
		move->down();
		move->leftP();
		move->downP();
		move->leftP();
		move->frontP();
		move->left();
		move->left();
		move->downP();

		return true;
	}

	// R'
	if (color[4][2] == color[0][4] && color[4][0] == color[2][4] &&
		color[5][7] == color[2][4] && color[2][5] == color[5][4] &&
		color[2][2] == color[4][4] && color[0][0] == color[4][4])
	{
		move->right();
		move->down();
		move->down();
		move->rightP();
		move->down();
		move->down();
		move->right();
		move->frontP();
		move->rightP();
		move->downP();
		move->right();
		move->down();
		move->right();
		move->front();
		move->right();
		move->right();
		move->down();

		return true;
	}

	// T
	if (color[4][0] == color[0][4] && color[0][0] == color[5][4] &&
		color[0][6] == color[4][4] && color[5][6] == color[0][4] &&
		color[2][5] == color[0][4] && color[0][3] == color[2][4])
	{
		move->left();
		move->down();
		move->leftP();
		move->downP();
		move->leftP();
		move->front();
		move->left();
		move->left();
		move->downP();
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->leftP();
		move->frontP();

		return true;
	}

	// U
	if (color[0][3] == color[2][4] && color[2][5] == color[4][4] &&
		color[4][1] == color[0][4])
	{
		move->leftP();
		move->down();
		move->leftP();
		move->downP();
		move->leftP();
		move->downP();
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->left();
		move->left();

		return true;
	}

	// U'
	if (color[0][3] == color[4][4] && color[2][5] == color[0][4] &&
		color[4][1] == color[2][4])
	{
		move->left();
		move->left();
		move->downP();
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->left();
		move->down();
		move->left();
		move->downP();
		move->left();

		return true;
	}

	// V
	if (color[4][2] == color[5][4] && color[2][2] == color[0][4] &&
		color[0][6] == color[2][4] && color[5][6] == color[4][4] &&
		color[2][5] == color[5][4] && color[5][7] == color[2][4])
	{
		move->rightP();
		move->down();
		move->rightP();
		move->downP();
		move->frontP();
		move->rightP();
		move->front();
		move->front();
		move->downP();
		move->frontP();
		move->down();
		move->frontP();
		move->right();
		move->front();
		move->right();

		return true;
	}

	// Y
	if (color[4][2] == color[5][4] && color[2][2] == color[0][4] &&
		color[0][6] == color[2][4] && color[5][6] == color[4][4] &&
		color[2][5] == color[4][4] && color[4][1] == color[2][4])
	{
		move->front();
		move->left();
		move->downP();
		move->leftP();
		move->downP();
		move->left();
		move->down();
		move->leftP();
		move->frontP();
		move->left();
		move->down();
		move->leftP();
		move->downP();
		move->leftP();
		move->front();
		move->left();
		move->frontP();

		return true;
	}

	// Z
	if (color[4][1] == color[2][4] && color[2][5] == color[4][4] &&
		color[5][7] == color[0][4] && color[0][3] == color[5][4])
	{
		move->down();
		move->leftP();
		move->downP();
		move->left();
		move->downP();
		move->left();
		move->down();
		move->left();
		move->downP();
		move->leftP();
		move->down();
		move->left();
		move->down();
		move->left();
		move->left();
		move->downP();
		move->leftP();
		move->down();

		return true;
	}

	return false;
}