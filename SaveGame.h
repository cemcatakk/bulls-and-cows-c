#pragma once
#include <stdio.h>
#include <string.h>
 struct Game {
	int index;
	char secret[11];
	char guess_list[31][11];
	int attempcount;
	int result;
};
void saveGames(struct Game game) {
	
	FILE * save = fopen("bullsandcows.txt", "a+");
		fprintf(save,"-------------------------\nSaved Game:\n Index: %d\nSecret: %s\nAttemps: %d\nResult: %d\n--Attemps--\n", game.index, game.secret, game.attempcount, game.result);
		for (int i = 0; i < game.attempcount; i++)
		{
			if (strcmp(game.guess_list[i], "") == 1) {
				fprintf(save,"->%s\n", game.guess_list[i]);
			}
		}
		fprintf(save, "------------------------\n");
	fclose(save);
}