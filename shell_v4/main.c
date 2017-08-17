// @author Anjali Malik

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Global Variables
int status = 0;
int status2 = 0;
int flag = 0;
char str[100];
int tmp = 0;

// Part of Bonus Problem Lab 7
// mon_child()
void mon_chld(int signal)
{
	if (signal == SIGCHLD)
	{
		pid_t pid = wait(&status2);
		int stat = WEXITSTATUS(status2);
		
		if (stat == 0)
		{
			fprintf(stdout, "pid %d has terminated: exit %d\n", pid, stat);
			fflush(stdout);
		}
	}
}

int main()
{
	// Initialize local variables
	pid_t k;
	char buf[100];

	int len, y, x;

	char check[6];
	int flag = 0;
	char str[100];
	char secret[100];
	char password[100];
	int stop = 0;
	int i = 0;
	int a = 0;
	int tmp = 0;
	int run = 1;
	char c;

	// Get the secret string from text file for lck command
	FILE *fp;
	fp = fopen("secretstring.txt", "r");
	fscanf(fp, "%s", secret);
	fclose(fp);

	//Get commands using infinite loop
	while (!stop)
	{
		int background = 0;
		run = 1;
		len = 0;
		buf[0] = '\0';

		// Print prompt
		char *name = getenv("USER");
		if (flag == 0)
		{
			fprintf(stdout, "%s: ", name);
		}
		else if (flag >= 1)
		{
			fprintf(stdout, "%s: ", str);
		}
		else if (flag == -1)
		{
			flag = tmp;
		}

		// Get buf array
		fgets(buf, 100, stdin);
		len = strlen(buf);
		if (len == 1)
			continue;
		buf[len - 1] = '\0';

		// CUSTOM SHELL COMMAND: enter command which is partially case insensitive
		//(all letters are treated as small letters) using ASCII
		check[0] = buf[0];
		check[1] = '\0';
		if (strcmp("_", check) == 0)
		{
			for (i = 1; i <= len; i++)
			{
				if (buf[i] >= 'A' && buf[i] <= 'Z')
				{
					c = buf[i] + 32; // char converted from big to small letters
					buf[i - 1] = c;
				}
				else
				{
					buf[i - 1] = buf[i]; // all other characters remain the same
				}
			}
			len = len - 1;
			buf[len] = '\0';
			run = 1;
		}

		// storing first 5 characters into check array to check for cprt command
		check[0] = buf[0];
		check[1] = buf[1];
		check[2] = buf[2];
		check[3] = buf[3];
		check[4] = buf[4];
		check[5] = '\0';

		// Code for cprt string custom command
		if (strcmp(check, "cprt ") == 0)
		{
			run = 0;
			flag += 1;
			str[0] = '\0';
			for (i = 0; buf[i + 5] != '\0'; i++)
			{
				str[i] = buf[i + 5];
			}
			str[i] = '\0';
		}

		// If pressed return key without command
		if (buf[0] == '\n')
		{
			run = 0;
			if (flag >= 1)
			{
				flag = flag;
			}
		}

		// EXIT - E, x, e, X inputs - works same as "Ctrl+C"
		if ((strcmp("E", buf) == 0) || (strcmp("e", buf) == 0) || (strcmp("x", buf) == 0) || (strcmp("X", buf) == 0))
		{
			stop = 1;
			run = 0;
		}

		// Custom command lck: Need correct password to unlock
		if ((strcmp("lck", buf) == 0))
		{
			run = 0;
			tmp = flag;
			flag = -1;
			password[0] = '\0'; // Initialize

			// Cannot resume the normal operations until secret string is entered
			while (strcmp(password, secret) != 0)
			{
				printf("key to unlock: ");
				scanf("%s", password);
			}
		}

		// Different for Problem 2 in Lab6
		char temp[100]; // temporary array for buf
		strcpy(temp, buf);
		char *s[100]; // create char * array to store the entire command

		// Using strtok with delimiter as " "
		s[0] = strtok(temp, " ");

		a = 1;
		while (1)
		{
			s[a] = strtok(NULL, " ");
			if (s[a] == NULL)
			{
				break;
			}
			if ((strcmp(s[a], "&") == 0))
			{
				background = 1;
				s[a] = NULL;
				break;
			}
			a++;
		}
		s[a] = NULL;

		// fork if the input is not custom one defined in eesh
		if (run == 1 || run == 2)
		{

			signal(SIGCHLD, &mon_chld);

			flag = 0;
			k = fork();

			if (k == 0)
			{
				/* CHILD */
				if (run == 1)
				{
					// SLEEPBIN - part of BONUS problem Lab 7
					// Check if sleepbin
					if (strcmp("sleepbin", s[0]) == 0)
					{
						s[0] = "sleep";
						s[1] = "7";
						s[2] = NULL;
					}
					//fprintf(stdout, "new process will run: %s\n", buf);
					x = execvp(s[0], s);
				}

				// if command doesn't exist
				if (x == -1)
				{
					fprintf(stdout, "Failure to execute: -eesh: %s: no such command found\n", buf);
					exit(1);
				}
			}
			else if (k < 0)
			{
				fprintf(stdout, "Forking failed!\n");
				exit(1);
			}
			fflush(stdout);

			/* BACK TO PARENT */
			if (background == 1)
			{
				continue;
			}
			waitpid(k, &status, 0);
		}
	}
	return 0;
}
