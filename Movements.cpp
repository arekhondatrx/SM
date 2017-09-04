#include "Movements.h"


Movements::Movements()
{
	cmp = 1;
	moves_cunter = 0;
}


void Movements::initialize(int **tab)
{
	color = tab;
	resetTab();
	moves_cunter = 0;
}

void Movements::resetTab()
{
	cmp_color = new int[6];
	resetCmpTable();

	temp = new int[9];
	for (int i = 0; i < 9; i++)
	{
		temp[i] = i;
	}

	solv_moves = new char[MOVE_TAB_SIZE];
	resetMoveTable();

	moves_cunter = 0;
}

void Movements::resetCmpTable()
{
	for (int i = 0; i < 6; i++)
	{
		cmp_color[i] = i;
	}
}

void Movements::resetMoveTable()
{
	for (int i = 0; i < MOVE_TAB_SIZE; i += 2)
	{
		solv_moves[i] = 35;
		solv_moves[i + 1] = 36;
	}
}
void Movements::rotateWallRight(int i)
{
	temp[0] = color[i][5];
	temp[1] = color[i][8];

	color[i][8] = color[i][2];
	color[i][5] = color[i][1];
	color[i][2] = color[i][0];
	color[i][1] = color[i][3];
	color[i][0] = color[i][6];
	color[i][3] = color[i][7];
	color[i][7] = temp[0];
	color[i][6] = temp[1];
}

void Movements::rotateWallLeft(int i)
{
	temp[0] = color[i][2];
	temp[1] = color[i][5];

	color[i][2] = color[i][8];
	color[i][5] = color[i][7];
	color[i][8] = color[i][6];
	color[i][6] = color[i][0];
	color[i][7] = color[i][3];
	color[i][3] = color[i][1];
	color[i][0] = temp[0];
	color[i][1] = temp[1];
}
void Movements::up()
{
	temp[0] = color[5][0];
	temp[1] = color[5][1];
	temp[2] = color[5][2];

	color[5][0] = color[2][6];
	color[5][1] = color[2][3];
	color[5][2] = color[2][0];

	color[2][6] = color[4][8];
	color[2][3] = color[4][7];
	color[2][0] = color[4][6];

	color[4][8] = color[0][2];
	color[4][7] = color[0][5];
	color[4][6] = color[0][8];

	color[0][2] = temp[0];
	color[0][5] = temp[1];
	color[0][8] = temp[2];

	rotateWallRight(1);
	solv_moves[moves_cunter] = 'U';
	moves_cunter++ ;
	checkMoveCunter();
	
}

void Movements::upP()
{
	temp[0] = color[5][0];
	temp[1] = color[5][1];
	temp[2] = color[5][2];

	color[5][0] = color[0][2];
	color[5][1] = color[0][5];
	color[5][2] = color[0][8];

	color[0][2] = color[4][8];
	color[0][5] = color[4][7];
	color[0][8] = color[4][6];

	color[4][8] = color[2][6];
	color[4][7] = color[2][3];
	color[4][6] = color[2][0];

	color[2][6] = temp[0];
	color[2][3] = temp[1];
	color[2][0] = temp[2];

	rotateWallLeft(1);
	solv_moves[moves_cunter] = 'u';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::back()
{
	temp[0] = color[1][0];
	temp[1] = color[1][1];
	temp[2] = color[1][2];

	color[1][0] = color[2][0];
	color[1][1] = color[2][1];
	color[1][2] = color[2][2];

	color[2][0] = color[3][0];
	color[2][1] = color[3][1];
	color[2][2] = color[3][2];

	color[3][0] = color[0][0];
	color[3][1] = color[0][1];
	color[3][2] = color[0][2];

	color[0][0] = temp[0];
	color[0][1] = temp[1];
	color[0][2] = temp[2];

	rotateWallRight(4);
	solv_moves[moves_cunter] = 'B';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::backP()
{
	temp[0] = color[1][0];
	temp[1] = color[1][1];
	temp[2] = color[1][2];

	color[1][0] = color[0][0];
	color[1][1] = color[0][1];
	color[1][2] = color[0][2];

	color[0][0] = color[3][0];
	color[0][1] = color[3][1];
	color[0][2] = color[3][2];

	color[3][0] = color[2][0];
	color[3][1] = color[2][1];
	color[3][2] = color[2][2];

	color[2][0] = temp[0];
	color[2][1] = temp[1];
	color[2][2] = temp[2];

	rotateWallLeft(4);
	solv_moves[moves_cunter] = 'b';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::down()
{
	temp[0] = color[5][8];
	temp[1] = color[5][7];
	temp[2] = color[5][6];

	color[5][8] = color[0][6];
	color[5][7] = color[0][3];
	color[5][6] = color[0][0];

	color[0][6] = color[4][0];
	color[0][3] = color[4][1];
	color[0][0] = color[4][2];

	color[4][0] = color[2][2];
	color[4][1] = color[2][5];
	color[4][2] = color[2][8];

	color[2][2] = temp[0];
	color[2][5] = temp[1];
	color[2][8] = temp[2];

	rotateWallRight(3);
	solv_moves[moves_cunter] = 'D';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::downP()
{
	temp[0] = color[5][8];
	temp[1] = color[5][7];
	temp[2] = color[5][6];

	color[5][8] = color[2][2];
	color[5][7] = color[2][5];
	color[5][6] = color[2][8];

	color[2][2] = color[4][0];
	color[2][5] = color[4][1];
	color[2][8] = color[4][2];

	color[4][0] = color[0][6];
	color[4][1] = color[0][3];
	color[4][2] = color[0][0];

	color[0][6] = temp[0];
	color[0][3] = temp[1];
	color[0][0] = temp[2];

	rotateWallLeft(3);
	solv_moves[moves_cunter] = 'd';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::front()
{
	temp[0] = color[3][8];
	temp[1] = color[3][7];
	temp[2] = color[3][6];

	color[3][8] = color[2][8];
	color[3][7] = color[2][7];
	color[3][6] = color[2][6];

	color[2][8] = color[1][8];
	color[2][7] = color[1][7];
	color[2][6] = color[1][6];

	color[1][8] = color[0][8];
	color[1][7] = color[0][7];
	color[1][6] = color[0][6];

	color[0][8] = temp[0];
	color[0][7] = temp[1];
	color[0][6] = temp[2];

	rotateWallRight(5);
	solv_moves[moves_cunter] = 'F';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::frontP()
{
	temp[0] = color[3][8];
	temp[1] = color[3][7];
	temp[2] = color[3][6];

	color[3][8] = color[0][8];
	color[3][7] = color[0][7];
	color[3][6] = color[0][6];

	color[0][8] = color[1][8];
	color[0][7] = color[1][7];
	color[0][6] = color[1][6];

	color[1][8] = color[2][8];
	color[1][7] = color[2][7];
	color[1][6] = color[2][6];

	color[2][8] = temp[0];
	color[2][7] = temp[1];
	color[2][6] = temp[2];

	rotateWallLeft(5);
	solv_moves[moves_cunter] = 'f';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::left()
{
	temp[0] = color[5][6];
	temp[1] = color[5][3];
	temp[2] = color[5][0];

	color[5][6] = color[1][6];
	color[5][3] = color[1][3];
	color[5][0] = color[1][0];

	color[1][6] = color[4][6];
	color[1][3] = color[4][3];
	color[1][0] = color[4][0];

	color[4][6] = color[3][2];
	color[4][3] = color[3][5];
	color[4][0] = color[3][8];

	color[3][2] = temp[0];
	color[3][5] = temp[1];
	color[3][8] = temp[2];

	rotateWallRight(0);
	solv_moves[moves_cunter] = 'L';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::leftP()
{
	temp[0] = color[5][6];
	temp[1] = color[5][3];
	temp[2] = color[5][0];

	color[5][6] = color[3][2];
	color[5][3] = color[3][5];
	color[5][0] = color[3][8];

	color[3][2] = color[4][6];
	color[3][5] = color[4][3];
	color[3][8] = color[4][0];

	color[4][6] = color[1][6];
	color[4][3] = color[1][3];
	color[4][0] = color[1][0];

	color[1][6] = temp[0];
	color[1][3] = temp[1];
	color[1][0] = temp[2];

	rotateWallLeft(0);
	solv_moves[moves_cunter] = 'l';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::right()
{
	temp[0] = color[5][2];
	temp[1] = color[5][5];
	temp[2] = color[5][8];

	color[5][2] = color[3][6];
	color[5][5] = color[3][3];
	color[5][8] = color[3][0];

	color[3][6] = color[4][2];
	color[3][3] = color[4][5];
	color[3][0] = color[4][8];

	color[4][2] = color[1][2];
	color[4][5] = color[1][5];
	color[4][8] = color[1][8];

	color[1][2] = temp[0];
	color[1][5] = temp[1];
	color[1][8] = temp[2];

	rotateWallRight(2);
	solv_moves[moves_cunter] = 'R';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::rightP()
{
	temp[0] = color[5][2];
	temp[1] = color[5][5];
	temp[2] = color[5][8];

	color[5][2] = color[1][2];
	color[5][5] = color[1][5];
	color[5][8] = color[1][8];

	color[1][2] = color[4][2];
	color[1][5] = color[4][5];
	color[1][8] = color[4][8];

	color[4][2] = color[3][6];
	color[4][5] = color[3][3];
	color[4][8] = color[3][0];

	color[3][6] = temp[0];
	color[3][3] = temp[1];
	color[3][0] = temp[2];

	rotateWallLeft(2);
	solv_moves[moves_cunter] = 'r';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::rotateXaxis()
{
	temp[0] = color[1][0];
	temp[1] = color[1][1];
	temp[2] = color[1][2];
	temp[3] = color[1][3];
	temp[4] = color[1][4];
	temp[5] = color[1][5];
	temp[6] = color[1][6];
	temp[7] = color[1][7];
	temp[8] = color[1][8];

	color[1][0] = color[5][0];
	color[1][1] = color[5][1];
	color[1][2] = color[5][2];
	color[1][3] = color[5][3];
	color[1][4] = color[5][4];
	color[1][5] = color[5][5];
	color[1][6] = color[5][6];
	color[1][7] = color[5][7];
	color[1][8] = color[5][8];

	color[5][0] = color[3][8];
	color[5][1] = color[3][7];
	color[5][2] = color[3][6];
	color[5][3] = color[3][5];
	color[5][4] = color[3][4];
	color[5][5] = color[3][3];
	color[5][6] = color[3][2];
	color[5][7] = color[3][1];
	color[5][8] = color[3][0];

	color[3][0] = color[4][8];
	color[3][1] = color[4][7];
	color[3][2] = color[4][6];
	color[3][3] = color[4][5];
	color[3][4] = color[4][4];
	color[3][5] = color[4][3];
	color[3][6] = color[4][2];
	color[3][7] = color[4][1];
	color[3][8] = color[4][0];

	color[4][0] = temp[0];
	color[4][1] = temp[1];
	color[4][2] = temp[2];
	color[4][3] = temp[3];
	color[4][4] = temp[4];
	color[4][5] = temp[5];
	color[4][6] = temp[6];
	color[4][7] = temp[7];
	color[4][8] = temp[8];

	rotateWallRight(2);
	rotateWallLeft(0); // czy w prawo ? :D
	//zmien_kolor();
	cmp = cmp_color[1];
	cmp_color[1] = cmp_color[5];
	cmp_color[5] = cmp_color[3];
	cmp_color[3] = cmp_color[4];
	cmp_color[4] = cmp;

	solv_moves[moves_cunter] = 'X';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::rotateXaxisP()
{
	temp[0] = color[1][0];
	temp[1] = color[1][1];
	temp[2] = color[1][2];
	temp[3] = color[1][3];
	temp[4] = color[1][4];
	temp[5] = color[1][5];
	temp[6] = color[1][6];
	temp[7] = color[1][7];
	temp[8] = color[1][8];

	color[1][0] = color[4][0];
	color[1][1] = color[4][1];
	color[1][2] = color[4][2];
	color[1][3] = color[4][3];
	color[1][4] = color[4][4];
	color[1][5] = color[4][5];
	color[1][6] = color[4][6];
	color[1][7] = color[4][7];
	color[1][8] = color[4][8];

	color[4][0] = color[3][8];
	color[4][1] = color[3][7];
	color[4][2] = color[3][6];
	color[4][3] = color[3][5];
	color[4][4] = color[3][4];
	color[4][5] = color[3][3];
	color[4][6] = color[3][2];
	color[4][7] = color[3][1];
	color[4][8] = color[3][0];

	color[3][0] = color[5][8];
	color[3][1] = color[5][7];
	color[3][2] = color[5][6];
	color[3][3] = color[5][5];
	color[3][4] = color[5][4];
	color[3][5] = color[5][3];
	color[3][6] = color[5][2];
	color[3][7] = color[5][1];
	color[3][8] = color[5][0];

	color[5][0] = temp[0];
	color[5][1] = temp[1];
	color[5][2] = temp[2];
	color[5][3] = temp[3];
	color[5][4] = temp[4];
	color[5][5] = temp[5];
	color[5][6] = temp[6];
	color[5][7] = temp[7];
	color[5][8] = temp[8];

	rotateWallLeft(2);
	rotateWallRight(0); // czy w lewo ? :D 
	//zmien_kolor();
	cmp = cmp_color[1];
	cmp_color[1] = cmp_color[4];
	cmp_color[4] = cmp_color[3];
	cmp_color[3] = cmp_color[5];
	cmp_color[5] = cmp;

	solv_moves[moves_cunter] = 'x';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::rotateYaxis()
{
	temp[0] = color[0][0];
	temp[1] = color[0][1];
	temp[2] = color[0][2];
	temp[3] = color[0][3];
	temp[4] = color[0][4];
	temp[5] = color[0][5];
	temp[6] = color[0][6];
	temp[7] = color[0][7];
	temp[8] = color[0][8];

	color[0][0] = color[5][6];
	color[0][1] = color[5][3];
	color[0][2] = color[5][0];
	color[0][3] = color[5][7];
	color[0][4] = color[5][4];
	color[0][5] = color[5][1];
	color[0][6] = color[5][8];
	color[0][7] = color[5][5];
	color[0][8] = color[5][2];

	color[5][0] = color[2][6];
	color[5][1] = color[2][3];
	color[5][2] = color[2][0];
	color[5][3] = color[2][7];
	color[5][4] = color[2][4];
	color[5][5] = color[2][1];
	color[5][6] = color[2][8];
	color[5][7] = color[2][5];
	color[5][8] = color[2][2];

	color[2][0] = color[4][6];
	color[2][1] = color[4][3];
	color[2][2] = color[4][0];
	color[2][3] = color[4][7];
	color[2][4] = color[4][4];
	color[2][5] = color[4][1];
	color[2][6] = color[4][8];
	color[2][7] = color[4][5];
	color[2][8] = color[4][2];

	color[4][0] = temp[6];
	color[4][1] = temp[3];
	color[4][2] = temp[0];
	color[4][3] = temp[7];
	color[4][4] = temp[4];
	color[4][5] = temp[1];
	color[4][6] = temp[8];
	color[4][7] = temp[5];
	color[4][8] = temp[2];

	rotateWallRight(1);
	rotateWallLeft(3); // czy w prawo ? :D
	//zmien_kolor();
	cmp = cmp_color[0];
	cmp_color[0] = cmp_color[5];
	cmp_color[5] = cmp_color[2];
	cmp_color[2] = cmp_color[4];
	cmp_color[4] = cmp;

	solv_moves[moves_cunter] = 'Y';
	moves_cunter++;
	checkMoveCunter();
}

void Movements::rotateYaxisP()
{
	temp[0] = color[0][0];
	temp[1] = color[0][1];
	temp[2] = color[0][2];
	temp[3] = color[0][3];
	temp[4] = color[0][4];
	temp[5] = color[0][5];
	temp[6] = color[0][6];
	temp[7] = color[0][7];
	temp[8] = color[0][8];

	color[0][0] = color[4][2];
	color[0][1] = color[4][5];
	color[0][2] = color[4][8];
	color[0][3] = color[4][1];
	color[0][4] = color[4][4];
	color[0][5] = color[4][7];
	color[0][6] = color[4][0];
	color[0][7] = color[4][3];
	color[0][8] = color[4][6];

	color[4][0] = color[2][2];
	color[4][1] = color[2][5];
	color[4][2] = color[2][8];
	color[4][3] = color[2][1];
	color[4][4] = color[2][4];
	color[4][5] = color[2][7];
	color[4][6] = color[2][0];
	color[4][7] = color[2][3];
	color[4][8] = color[2][6];

	color[2][0] = color[5][2];
	color[2][1] = color[5][5];
	color[2][2] = color[5][8];
	color[2][3] = color[5][1];
	color[2][4] = color[5][4];
	color[2][5] = color[5][7];
	color[2][6] = color[5][0];
	color[2][7] = color[5][3];
	color[2][8] = color[5][6];

	color[5][0] = temp[2];
	color[5][1] = temp[5];
	color[5][2] = temp[8];
	color[5][3] = temp[1];
	color[5][4] = temp[4];
	color[5][5] = temp[7];
	color[5][6] = temp[0];
	color[5][7] = temp[3];
	color[5][8] = temp[6];

	rotateWallLeft(1);
	rotateWallRight(3);// czy w lewo ? :D 
	//zmien_kolor();

	cmp = cmp_color[0];
	cmp_color[0] = cmp_color[4];
	cmp_color[4] = cmp_color[2];
	cmp_color[2] = cmp_color[5];
	cmp_color[5] = cmp;

	solv_moves[moves_cunter] = 'y';
	moves_cunter++;
	checkMoveCunter();
}
