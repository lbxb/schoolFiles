//Matt Polewaczyk and Liam Bixby
/*
────────────────████
───────────────█░░███
───────────────█░░████
────────────────███▒██─────████████
──────████████─────█▒█──████▒▒▒▒▒▒████
────███▒▒▒▒▒▒████████████░░████▒▒▒▒▒███
──██▒▒▒▒░▒▒████░░██░░░░██░░░░░█▒▒▒▒▒▒▒███
─██▒▒░░░░▒██░░░░░█▒░░░░░██▒░░░░░░░▒▒▒▒▒▒█
██▒░░░░░▒░░░░░░░░░▒░░░░░░░▒▒░░░░░░░▒▒▒▒▒██
█░░░░░░▒░░░██░░░░░░░░░░░░░██░░░░░░░░▒▒▒▒▒█
█░░░░░░░░█▒▒███░░░░░░░░░█▒▒███░░░░░░░▒▒▒▒█
█░░░░░░░████████░░░░░░░████████░░░░░░▒▒▒▒█
█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒█
██░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░▒▒▒▒█
─█░░░░██░█░░░░░░░░░░░░░░░░░░░░░░░███▒▒▒▒▒█
─█▒▒░░░░█████░░░█░░░░██░░░██░░████░▒▒▒▒▒▒█
─██▒▒░░░░░█████████████████████░░░▒▒▒▒▒▒██
──██▒▒▒▒░░░░░██░░░███░░░██░░░█░░░▒▒▒▒▒▒██
───███▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒█████
─────███▒▒▒▒▒▒░░░░░░░░░░░░░▒▒▒▒▒▒████
────────██████████████████████████
HAPPY HALLOWEEN*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_LINE 80

// used 2 functions instead of putting all in main to make main not look as gross and crazy.
void Input(char in[], char *parameter[], const char delimeter[]){
	char *text;
	text = strtok(in, delimeter); //parses out users input to be broken down into different arguments
	int i = 0;

	while (text != NULL){
		parameter[i] = text;
		text = strtok(NULL, delimeter);
		i++;
	}
	parameter[i] = NULL;
}

void newChild(char *parameter[]){ //adapted from page 142 in the book as well as page 118
	pid_t pid;
	pid = fork(); 
	if (pid < 0){
		fprintf(stderr, "FORK FAILED. No can do buckaroo."); // produces error
	}
	else if (pid == 0){ 
		execvp(parameter[0], parameter); // executes a child 
	}
	else {
		wait(NULL); //waits to terminate
	}
}

int main(void) {
	char *args[MAX_LINE/2+1];
	char input[MAX_LINE];
	const char delimeter[2] = " ";

	while(1 == 1){
		printf("osh>");
		fgets(input, MAX_LINE, stdin); //reads a line from specified stream and stores it into the string point by the str and stops when either (n-1) characters are read new line character is read, or end of file is reached
		if(input[strlen(input) - 1] == '\n'){
			input[strlen(input) - 1] = '\0'; //reads the users input and if they hit enter or 'line break'
			//it does \0 which is commonly used in c to terminate a string
		}
		Input(input, args, delimeter);
		if (strcmp(args[0], "exit") == 0){ // uses strcmp to compare the users arguement to the text "exit"
		// if they match it closes out of program 
			return 0;
		}
		else{
			newChild(args);
		}
		fflush(stdout);
	}
	return 0;
}


