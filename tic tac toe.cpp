#include<iostream>
#include<conio.h>
using namespace std;

char arr[9];
bool player;
bool p1 = false, p2 = false;
bool gameSet = false;

void display() {
	system("cls");
	cout << endl << endl;
	cout << "\t\t" << "  Tic Tac Toe" << endl;
	cout << "\t" << "---------------------------------" << endl;

	if (player == false) {
		cout << "\t\t" << "  Player 1 ( O ) " << endl;
		cout << "\t" << "---------------------------------" << endl;
	}
	else {
		cout << "\t\t" << "  Player 2 ( X ) " << endl;
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
		cout << "\t\t" << "  Player 1 WON! " << endl;
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "   Press any key to play again!  " << endl;
		cout << "\t" << "---------------------------------" << endl;
		_getch();
		return;
	}
	if (p2 == true) {
		cout << endl;
		cout << "\t\t" << "  Player 2 WON! " << endl;
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
			p2 = true;
		}
	}

	if (arr[3] == arr[4] && arr[4] == arr[5]) {					//check for row 2
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

	if (arr[6] == arr[7] && arr[7] == arr[8]) {					//check for row 3
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

	if (arr[0] == arr[3] && arr[3] == arr[6]) {					//check for column 1
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

	if (arr[1] == arr[4] && arr[4] == arr[7]) {					//check for column 2
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

	if (arr[2] == arr[5] && arr[5] == arr[8]) {					//check for column 3
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

	if (arr[0] == arr[4] && arr[4] == arr[8]) {					//check for left diagonal
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

	if (arr[2] == arr[4] && arr[4] == arr[6]) {					//check for right diagonal
		gameSet = true;
		if (player == true) {
			p1 = true;
		}
		else {
			p2 = true;
		}
	}

}

void game() {

B:	player = false;
	int x = 0;
	int count = 0;
	char arr1[9] = { '1','2','3','4','5','6','7','8','9' };

	for (int i = 0; i < 9; i++) {
		arr[i] = arr1[i];
		arr1[i] = '0';
	}

A:	if (player == false) {

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
	player = true;
}
	else {

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

	arr[x - 1] = 'X';
	count++;
	player = false;
}

	check();

	if (gameSet == false && count == 8) {
		system("cls");
		cout << endl;
		cout << "\t\t\t" << "  Draw ! " << endl;
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "   Press any key to play again!  " << endl;
		cout << "\t" << "---------------------------------" << endl;
		_getch();
	}

	if (gameSet == true) {
		winner();
		gameSet = false;
	}
	else {
		goto A;
	}

	if (player == true) {
		player = false;
	}
	else {
		player = true;
	}

	goto B;

}


int main() {
	system("COLOR 0A");
	game();
	return 0;
}