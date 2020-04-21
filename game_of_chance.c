/*
 * =====================================================================================
 *
 *       Filename:  game_of_chance.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/21/2020 02:14:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dalibor Lipovac (dl), dlipovac012@gmail.com
 *        Company:  raptr.dev
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include "hacking.h"

#define DATAFILE "/var/chance.data" // file to store users data

typedef struct {
	unsigned uid;
	unsigned credits;
	int highscore;
	char name[160];
	int (*current_game) ();	
} User;

// prototypes
int get_player_data();
void register_new_player();
void update_player_data();
void show_highscore();
void jackpot();
void input_name();
void print_cards(char*, char*, int);
int take_wager(int, int);
void play_the_game();
int pick_a_number();
int dealer_no_match();
int find_the_ace();
void fatal(char*);

// global variables
User player;

int main(int argc, char **argv)
{
	int choice, last_game;
 
	srand(time(0)); // seed randomizer with current time
	
	if (get_player_data() == -1)
		register_new_player();

	while(choice != 7)
	{
		printf("-=[ Game of Chance Menu]=-\n");
		printf("1 - Play the Pick a Number game\n");
		printf("2 - Play the No Match Dealer game\n");
		printf("3 - Play the Find the Ace game\n");
		printf("4 - View current high score\n");
		printf("5 - Change your user name\n");
		printf("6 - Reset your account at 100 credits\n");
		printf("7 - Quit\n");
		printf("[Name: %s]\n", player.name);
		printf("[You have %u credits] -> ", player.credits);
		
		scanf("%d", &choice);

		if (choice < 1 || choice > 7)
			printf("\n[!!] The number %d is an invalid selection. Choose wisely. \n\n", choice);
		else if (choice < 4)
		{
			
		}
	}



	return 0;
}
























