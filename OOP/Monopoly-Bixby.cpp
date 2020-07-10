//Liam Bixby


#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int N = 40;
const int M = 4;

void landingnumber(int landings[]);

int main(void){
	//srand((unsigned)(time(NULL)));	
	srand((unsigned)23232323);
	int landings[N] = { 0 }, curpos[M] = { 0 };	
	int die1, die2, diesum;
	for (int x = 1; x <= 5; x++){		
		for (int i = 0; i < 4; i++){	
			die1 = rand() % 6 + 1;		
			die2 = rand() % 6 + 1;
			diesum = die1 + die2;
			curpos[i] = (curpos[i] + diesum) % 40;	
			landings[curpos[i]]++;	
			if (die1 == die2){
				cout << "Player " << i << " rolled a double.\n";
				die1 = rand() % 6 + 1;		
				die2 = rand() % 6 + 1;
				diesum = die1 + die2;
				curpos[i] = (curpos[i] + diesum) % 40;	
				landings[curpos[i]]++;	
				if (die1 == die2){
					cout << "Player " << i << " goes to jail.\n";
					curpos[i] = 10;
				}
			}
		}
		cout << "AFTER ROUND " << x << endl;
		cout << "Player 0 is at location " << curpos[0] << endl;
		cout << "Player 1 is at location " << curpos[1] << endl;
		cout << "Player 2 is at location " << curpos[2] << endl;
		cout << "Player 3 is at location " << curpos[3] << endl;

		landingnumber(landings);
	}

	return 0;
}

void landingnumber(int landings[]){
	int counter = 1;
	cout << "Squares landed on one or more times \n";
	cout << setw(10) << "Square" << setw(10) << "Landings" << setw(10);
	cout << setw(10) << "Square" << setw(10) << "Landings" << setw(10);
	cout << setw(10) << "Square" << setw(10) << "Landings" << endl;
	for (int i = 0; i < N; i++){
		if (landings[i]>0){
			cout << setw(10) << i << setw(10) << landings[i];
			counter++;
			if (counter > 3){
				cout << endl;
				counter = 1;
			}
		}
	}
	cout << endl;
}
