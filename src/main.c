// CCDSTRU Machine Project

#include <stdio.h>
#include <stdbool.h>

//function prototypes
void gameOver(bool over, int arr_R[3][3][2], int arr_B[3][3][2]); //recently modified by dihhcoderhahah
int getCardinalities(int arr[3][3][2]); //recently modified by dihhcoderhahah

int main() //recently modified by dihhcoderhahah
{	
	int i,j,k;

	//applicable sets
	int arr_C[3] = {1,2,3};
	int arr_N[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int arr_M[3][3][2] = {{{1,1},{1,2},{1,3}},
						  {{2,1},{2,2},{2,3}},
						  {{3,1},{3,2},{3,3}}};
	bool arr_V[2] = {true, false};
	
	//System Variables
	bool good;
	bool go;
	bool start;
	bool over;
	bool found;
	int val;
	int arr_R[3][3][2];
	int arr_B[3][3][2];
	int arr_S[3][3][2];
	int arr_T[3][3][2];
	int arr_F[3][3][2];	
	
	
	//System Initialization
	good = arr_V[1];
	go = arr_V[0];
	start = arr_V[0];
	found = arr_V[1];
	val = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			arr_R[i][j][0] = 0;
			arr_R[i][j][1] = 0;
			arr_B[i][j][0] = 0;
			arr_B[i][j][1] = 0;
			arr_S[i][j][0] = 0;
			arr_S[i][j][1] = 0;
			arr_T[i][j][0] = 0;
			arr_T[i][j][1] = 0;
		}
	}
	
	
	//System Facts
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 2; k++)
			{
				arr_F[i][j][k] = arr_M[i][j][k];
			}
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if((arr_R[i][j][0] != 0 && arr_R[i][j][1] != 0) || (arr_B[i][j][0] != 0 && arr_B[i][j][1] != 0))
			{
				arr_F[i][j][0] = 0;
				arr_F[i][j][1] = 0;
			}
		}
	}

	int card_F = 0; 
	int card_R = 0;
	int card_B = 0;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(arr_F[i][j][0] != 0 && arr_F[i][j][1] != 0)
			{
				card_F++;
			}
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(arr_R[i][j][0] != 0 && arr_R[i][j][1] != 0)
			{
				card_R++;
			}
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(arr_B[i][j][0] != 0 && arr_B[i][j][1] != 0)
			{
				card_B++;
			}
		}
	}
	
	if(card_F == 3 || val >= 20 || !start && (card_R > 0 && card_B == 0 || card_R == 0 && card_B > 0))
	{
		over = true;
	}
	else
	{
		over = false;
	}
	
	return 0;
}

void gameOver(bool over, int arr_R[3][3][2], int arr_B[3][3][2])
{
	char result[3][20] = {"R Wins", "B wins", "draw"};
	int card_R = getCardinalities(arr_R);
	int card_B = getCardinalities(arr_B);
	if (over && card_R > card_B)
	{
		printf("%s\n", result[0]);
	}
	else if (over && card_B > card_R)
	{
		printf("%s\n", result[1]);
	}
	else if (over && card_R == card_B) 
	{
		printf("%s\n", result[2]);
	}
}


int getCardinalities(int arr[3][3][2])
{
	int i, j, count = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(arr[i][j][0] != 0 && arr[i][j][1] != 0)
			{
				count++;
			}
		}
	}
	return count;
}




