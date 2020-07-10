//Matt Polewaczyk and Liam Bixby
#include <stdio.h>
#include <stdlib.h>
/*
▒▒▒▒▒▐▀▀▀█▄▒▒▒▒▒▒▒▒▒
▒▒▒▒█▀─────█▒▒▒▒▒▒▒▒
▒▒▒█────▄─▄─▌▒▒▒▒▒▒▒
▒▒▒▌───██─█▌▌▒▒▒▒▒▒▒
▒▒▒▌───█▌──▌▌▒▒▒▒▒▒▒
▒▒▒▌────────▌▒▒▒▒▒▒▒
▒▒█─────────▐▒▒▒▒▒▒▒
▒▐▌─▐───────▐▄▄▒▒▒▒▒
▒▐▌─▐────────▄▀▀█▒▒▒
▒█──▀▄──▄█▄▀▀▒▒▒▌▀▄▒
▐▌────██▀█░█▄▒▄▄█▀▀▌
▐▌──▌▐───▐░░▐▀░░░░░▌
▐▌──▌────▐░░▐░░░░░░▌
▐───▌────▐░░▐░░░░░░▌
▐───█────▐░░▐░░░░░░▌
▐───█────▐░░▐░░░░░░▌
▐───█─────▀█▐▄▄▄█▀▀▒
▀▄▄─▐───────▄█▒▒▒▒▒▒
▒▒▒▀█───█▄▀▀▀▒▒▒▒▒▒▒
▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒▒▒▒▒
Boo!
*/

int main(int argc, char *argv[]){  //adapted from page 170 in the book
	int sum = 0;
	sum = strtol(argv[1], NULL, 10) + strtol(argv[2], NULL, 10); // reads into array and converts the arguments
	// from characters to long integers using strtol
	printf("The sum is: %d\n", sum);
	return 0;
}

