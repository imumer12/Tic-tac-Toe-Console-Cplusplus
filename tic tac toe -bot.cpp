#include<iostream>
#include<conio.h>
#include <cstdlib>
#include <ctime>


using namespace std;

void delay() {
	for (int i = 1; i < 10000; i++) {
		for (int j = 1; j < 20000; j++) {

		}
	}
}

char arr[9];
bool player, Bot;
bool p1 = false, bot = false;
bool gameSet = false;

void display() {
	system("cls");
	cout << endl << endl;
	cout << "\t\t" << "  Tic Tac Toe" << endl;
	cout << "\t" << "---------------------------------" << endl;

	if (player == true) {
		cout << "\t\t" << "  Player ( O ) " << endl;
		cout << "\t" << "---------------------------------" << endl;
	}
	if (Bot == true) {
		cout << "\t\t" << "  Bot ( X ) " << endl;
		cout << "\t" << "---------------------------------" << endl;
	}


	cout << endl << endl;
	cout << "\t" << "          |          |          " << endl;
	cout << "\t" << "     " << arr[0] << "    |     " << arr[1] << "    |     " << arr[2] << "     " << endl;
	cout << "\t" << "__________|__________|__________" << endl;
	cout << "\t" << "          |          |          " << endl;
	cout << "\t" << "     " << arr[3] << "    |     " << arr[4] << "    |     " << arr[5] << "     " << endl;
	cout << "\t" << "__________|__________|__________" << endl;
	cout << "\t" << "          |          |          " << endl;
	cout << "\t" << "     " << arr[6] << "    |     " << arr[7] << "    |     " << arr[8] << "     " << endl;
	cout << "\t" << "          |          |          " << endl;
	cout << endl << endl;
	cout << "\t---------->>>";
}


void winner() {
	system("cls");
	if (p1 == true) {
		cout << endl;
		cout << "\t\t" << "  Player WON! " << endl;
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "   Press any key to play again!  " << endl;
		cout << "\t" << "---------------------------------" << endl;
		_getch();
		return;
	}
	if (bot == true) {
		cout << endl;
		cout << "\t\t" << "  Bot WON! " << endl;
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "   Press any key to play again!  " << endl;
		cout << "\t" << "---------------------------------" << endl;
		_getch();
		return;
	}
}

void check() {

	if (arr[0] == arr[1] && arr[1] == arr[2]) {					//check for row 1
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[3] == arr[4] && arr[4] == arr[5]) {					//check for row 2
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[6] == arr[7] && arr[7] == arr[8]) {					//check for row 3
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[0] == arr[3] && arr[3] == arr[6]) {					//check for column 1
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[1] == arr[4] && arr[4] == arr[7]) {					//check for column 2
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[2] == arr[5] && arr[5] == arr[8]) {					//check for column 3
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[0] == arr[4] && arr[4] == arr[8]) {					//check for left diagonal
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

	if (arr[2] == arr[4] && arr[4] == arr[6]) {					//check for right diagonal
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			bot = true;
		}
	}

}

void game() {
	srand(time(0));
B:	player = true;
	Bot = false;
	int x = 0;
	int count = 1;
	char arr1[9] = { '1','2','3','4','5','6','7','8','9' };

	for (int i = 0; i < 9; i++) {
		arr[i] = arr1[i];
		arr1[i] = '0';
	}

A:	if (player == true) {

	display();
	cin >> x;
	if (x > 9 || x < 1) {
		goto A;
	}

	for (int i = 0; i < 9; i++) {
		if (arr1[i] == x) {
			goto A;
		}
	}

	arr1[x - 1] = x;
	arr[x - 1] = 'O';
	count++;

}

	if (Bot == true) {

		display();
		delay();
		x = rand() % 9 + 1;

		for (int i = 0; i < 9; i++) {
			if (arr1[i] == x) {
				goto A;
			}
		}

		arr1[x - 1] = x;
		arr[x - 1] = 'X';
		count++;

	}


	check();

	if (gameSet == false && count == 9) {
		cout << endl << endl;
		cout << "\t\t" << "  Draw ! " << endl;
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "   Press any key to play again!  " << endl;
		cout << "\t" << "---------------------------------" << endl;
		_getch();
		goto B;
	}

	if (gameSet == true) {
		winner();
		gameSet = false;
		goto B;
	}

	if (player == true) {
		player = false;
		Bot = true;
		goto A;
	}

	if (Bot == true) {
		player = true;
		Bot = false;
		goto A;
	}



}


int main() {
	system("COLOR 0A");
	game();
	return 0;
}