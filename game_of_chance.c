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
			if (choice != last_game)
			{
				if (choice == 1)
					player.current_game = pick_a_number;
				else if (choice == 2)
					player.current_game = dealer_no_match;
				else
					player.current_game = find_the_ace;
				last_game = choice;
			}
			play_the_game();
		}
		else if (choice == 4)
			show_highscore();
		else if (choice == 5)
		{
			printf("\nChange user name\n");
			printf("Enter your new name: ");
			input_name();
			printf("Your name has been changed.\n\n");
		}
		else if (choice == 6)
		{
			printf("\nYour account has been reset with 100 credits.\n\n");
			player.credits = 100;
		}
	}
	update_player_data();
	printf("\nThanks for playing! Bye bye.\n");

	return 0;
}

int get_player_data()
{
	int fd, uid, read_bytes;
	User entry;

	uid = getuid();

	fd = open(DATAFILE, O_RDONLY);
	if (fd == -1)
		return -1;
	read_bytes = read(fd, &entry, sizeof(User));
	while(entry.uid != uid && read_bytes > 0)
	{
		read_bytes = read(fd, &entry, sizeof(User));
	}
	close(fd);
	
	if (ready_bytes < sizeof(User))
		return -1;
	else
		player = entry;
	return 1;
}

void register_new_player()
{
	int fd;

	printf("-=-={ New Player Registration }=-=-\n");
	printf("Enter your name: ");
	input_name();

	player.uid = getuid();
	player.highscore = player.credits = 100;

	fd = open(DATAFILE, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if (fd == -1)
		fatal("in register_new_player() while opening file");
	write(fd, &player, sizeof(User));
	close(fd);

	printf("\nWelcome to the Game of Chance %s.\n", player.name);
	printf("You have been given %u credits.\n", player.credits);
}




















