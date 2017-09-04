#include "FridrichHelper.h"


FridrichHelper::FridrichHelper()
{
}

void FridrichHelper::copyTab(int ** src, int ** dst)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			dst[i][j] = src[i][j];
		}
	}
}

void FridrichHelper::removeRepetitiveMoves()
{
	int rep3 = 0, rep4 = 0, opp = 0; //3 and 4 repetion counters and opposed
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < move->moves_cunter - (rep3 * 3) - (rep4 * 4); i++)
		{
			if (move->solv_moves[i] == move->solv_moves[i + 1])
			{
				if (move->solv_moves[i + 1] == move->solv_moves[i + 2])
				{
					if (move->solv_moves[i + 2] == move->solv_moves[i + 3])
					{
						rep4++;
						for (int j = 0; j < move->moves_cunter - (rep3 * 3) - (rep4 * 4) - (opp * 2); j++)
						{
							move->solv_moves[j + i] = move->solv_moves[j + i + 4];
						}
					}
					else
					{
						if (move->solv_moves[i] < 97)
						{
							move->solv_moves[i] += 32;
						}

						else
						{
							move->solv_moves[i] -= 32;
						}
						rep3++;
						for (int j = 0; j < move->moves_cunter - (rep3 * 3) - (rep4 * 4) - (opp * 2); j++)
						{
							move->solv_moves[j + i + 1] = move->solv_moves[j + i + 3];
						}
					}
				}
			}
			if ((move->solv_moves[i] == move->solv_moves[i + 1] + 32) ||
				(move->solv_moves[i] == move->solv_moves[i + 1] - 32))
			{
				opp++;
				for (int j = 0; j < move->moves_cunter - (rep3 * 3) - (rep4 * 4) - (opp * 2); j++)
				{
					move->solv_moves[j + i] = move->solv_moves[j + i + 2];
				}
			}
		}
	}
	if (move->solv_moves[move->moves_cunter + 1] == 35 ||
		move->solv_moves[move->moves_cunter + 1] == 36)
	{
		if (move->solv_moves[move->moves_cunter] == 'Y' ||
			move->solv_moves[move->moves_cunter] == 'X' ||
			move->solv_moves[move->moves_cunter] == 'y' ||
			move->solv_moves[move->moves_cunter] == 'x')
		{
			move->moves_cunter--;
		}
	}
	move->moves_cunter = move->moves_cunter - ((rep3 * 2) + (rep4 * 4) + (opp * 2));
}

