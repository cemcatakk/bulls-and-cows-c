// Bulls_And_Cows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <C:\Users\Cem\source\repos\Bulls_And_Cows\Bulls_And_Cows\SaveGame.h>
static int index = 0;
int main()
{
	//srand(5);
	do
	{
		srand((unsigned int)time(NULL));
		int digits;
		int maxattemps = 30;
		int attemps = 0;
		int result = 0;
		do
		{
			printf("Enter number of digits between 2-9 to generate randomly\n>>");
			scanf("%d", &digits);
		} while ((digits < 2) || (digits > 9));
		char*guess = (char*)malloc(sizeof(char)*digits);
		char*number = (char*)malloc(sizeof(char)*digits);
		char guess_list[30][10];
		bool*used = (bool*)malloc(sizeof(bool) * 10);
		for (int i = 0; i < 10; i++)
		{
			used[i] = false;
		}
		char nums[] = "1234567890";
		int rndnum = 0;
		number[digits] = 0;
		for (int i = 0; i < digits; i++)
		{
			while (1)
			{
				rndnum = rand() % 10;
				if (used[rndnum] == false) {
					used[rndnum] = true;
					break;
				}
			}
			number[i] = nums[rndnum];
		}
		//Disable comment line to see number
		printf("Number is: %s\n", number);
		while (true)
		{
			int bulls = 0, cows = 0;
			printf("Guess:");
			scanf("%s", guess);
			strcpy(guess_list[attemps], guess);
			//printf("Guessed: %s\n", guess_list[attemps]);
			attemps++;
			if (strcmp(guess, "quit") == 0) {
				printf("You given up. Number was: %s", number);
				break;
			}
			for (int i = 0; i < digits; i++)
			{
				if (guess[i] == number[i])
				{
					cows++;
				}
				else {
					for (int j = 0; j < digits; j++)
					{
						if ((guess[i] == number[j]) && (i != j)) {
							bulls++;
							break;
						}
					}
				}

			}
			printf("Attemps left: %d\n", (maxattemps - attemps));
			printf("Bulls: %d, Cows %d\n", bulls, cows);
			if (cows == digits)
			{
				result = 1;
				printf("Gratz! You won!\n");
				break;
			}
			else if (attemps == maxattemps) {
				result = 0;
				printf("You lose\nThe number was %s\n", number);
				break;
			}
		}
		struct Game game;
		game.index = index;
		game.attempcount = attemps;
		game.result = result;
		for (int i = 0; i < attemps; i++)
		{
			if (strcmp(guess_list[i], "") == 1)
			{
				strcpy(game.guess_list[i], guess_list[i]);
			}

		}
		strcpy(game.secret, number);
		saveGames(game);
		index++;
		printf("Play Again? \n1-Yes\n2-No\n>>");
		int choose;
		scanf("%d", &choose);
		if (choose!=1)
		{
			printf("\nGOODBYE!\n");
			break;
		}
	} while (true);
}

