#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> 

// cd (cd), dir (ls), type (cat), del (rm), ren (mv), copy (cp)

void main ()
{
	// use "%" to define variable location + attributes (e.g. left justified, padding, num system conversions, etc)
    printf("code is working\n");
    //int *test;
    //*test = 111;
    //printf("%ls", test);
    //variable declarations/assignments
    int command_size;
    int arg1_size;
    int arg2_size;
    bool exit = false;
	char input[512];

    char command[128];
	command[0] = 0;
    char arg1[128];
	arg1[0] = 0;
    char arg2[128];
	arg2[0] = 0;
    char *string;
    do {
		printf("Type Ctrl+C to Exit \n> ");

		fgets(input, 512, stdin);
		//printf("%s", input);
		//temp = input;

		//begin parsing the user input
		string = strtok(input, " \n\t\r\a");

		//iterate through the user input and assign each token to a variable depending on the value of i
		int i = 1;
		while(string != NULL) {
			//printf("%s ", string);
			switch(i) {
				//first token
				case 1:
			  		strncpy(command, string, 64);
					//command = string;
					//printf("command: %s\n", command);
					break;
					//printf("I AM IN COMMAND");
				//second token
				case 2:
			  		strncpy(arg1, string, 64);
					//printf("arg1: %s\n", arg1);
					break;
					//i++;
				//etc..
				case 3:
			  		strncpy(arg2, string, 64);
					//arg2 = string;
					//printf("arg2: %s\n", arg2);
					break;
					//i++;

			}
			//next token
			string = strtok(NULL, " \n\t\r\a");
			if(string == NULL) {
				//printf("it is null\n");
				break;
				//continue;
			}
			else {
				i++;
			}
		}
		//printf("command: %s\n arg1: %s\n arg2: %s\n", command, arg1, arg2);

		//printf("%s\n%s\n%s", command, arg1, arg2);
		// cd (cd), dir (ls), type (cat), del (rm), ren (mv), copy (cp)
		if(strcmp(command, "cd") == 0) {
			chdir(arg1);
			memset(arg1, 0, sizeof(arg1));
			//strncat(command, arg2, 64);
			//printf("%s\n", command);
			//system("cd ../");
		}
		if(strcmp(command, "dir") == 0) {
			char ls[] = "ls ";
			if(strlen(arg1) != 0) {
				strncat(ls, arg1, 128);
				
				if(strlen(arg2) != 0) {
					strncat(ls, " ", 1);
					strncat(ls, arg2, 128);
					system(ls);
					memset(arg1, 0, sizeof(arg1));
					memset(arg1, 0, sizeof(arg2));
				}
				else {
					system(ls);
					memset(arg1, 0, sizeof(arg1));
				}
			}
			else {
				system(ls);
			}
		}
		if(strcmp(command, "type") == 0) {
			char cat[] = "cat ";
			if(strlen(arg1) != 0) {
				strncat(cat, arg1, 128);
				
				if(strlen(arg2) != 0) {
					strncat(cat, " ", 1);
					strncat(cat, arg2, 128);
					system(cat);
					memset(arg1, 0, sizeof(arg1));
					memset(arg1, 0, sizeof(arg2));
				}
				else {
					system(cat);
					memset(arg1, 0, sizeof(arg1));
				}
			}
			else {
				printf("[ERROR] no argument provided for type\n");
			}
		}
		if(strcmp(command, "del") == 0) {
			char rm[] = "rm ";
			if(strlen(arg1) != 0) {
				strncat(rm, arg1, 128);
				
				if(strlen(arg2) != 0) {
					strncat(rm, " ", 1);
					strncat(rm, arg2, 128);
					system(rm);
					memset(arg1, 0, sizeof(arg1));
					memset(arg1, 0, sizeof(arg2));
				}
				else {
					system(rm);
					memset(arg1, 0, sizeof(arg1));
				}
			}
			else {
				printf("[ERROR] no argument provided for del\n");
			}
		}
		if(strcmp(command, "ren") == 0) {
			char ren[] = "mv ";
			if(strlen(arg1) != 0) {
				strncat(ren, arg1, 128);
				
				if(strlen(arg2) != 0) {
					strncat(ren, " ", 1);
					strncat(ren, arg2, 128);
					system(ren);
					memset(arg1, 0, sizeof(arg1));
					memset(arg2, 0, sizeof(arg2));
				}
				else {
					system(ren);
					memset(arg1, 0, sizeof(arg1));
				}
			}
			else {
				printf("[ERROR] no argument provided for ren\n");
			}
		}
		if(strcmp(command, "copy") == 0) {
			char cp[] = "cp ";
			if(strlen(arg1) != 0) {
				strncat(cp, arg1, 128);
				
				if(strlen(arg2) != 0) {
					strncat(cp, " ", 1);
					strncat(cp, arg2, 128);
					system(cp);
					memset(arg1, 0, sizeof(arg1));
					memset(arg2, 0, sizeof(arg2));
				}
				else {
					system(cp);
					memset(arg1, 0, sizeof(arg1));
				}
			}
			else {
				printf("[ERROR] no argument provided for cp\n");
			}
		}

        //printf("%s %s %s\n", command, arg1, arg2);
        //char *command = malloc(sizeof(char[command_size]));
        //char *arg1 = malloc(sizeof(char[arg1_size]));
        //char *arg2 = malloc(sizeof(char[arg2_size]));
    } while (exit == false);
    
}

