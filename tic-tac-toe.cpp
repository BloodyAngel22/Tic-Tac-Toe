#include <iostream>

using namespace std;

void display(const char* arr){
	cout << "   |   |   " << endl;
	cout << " " << arr[0] << " | " << arr[1] << " | " << arr[2] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << arr[3] << " | " << arr[4] << " | " << arr[5] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << arr[6] << " | " << arr[7] << " | " << arr[8] << endl;
	cout << "   |   |   " << endl;

}

void p1Choice(char* arr, char p1, char p2){
	int pos;
	cout << "Firts player turn" << endl;
	do{
	cin >> pos;
	} while ((pos <= 0 or pos >= 10) and arr[pos-1] != ' ');
	arr[pos - 1] = p1;
}

void p2Choice(char* arr, char p2, char p1){
	int pos;
	cout << "Second player turn" << endl;
	do{
	cin >> pos;
	if (arr[pos - 1] != ' ')
		pos = -1;
	} while ((pos <= 0 or pos >= 10) and arr[pos-1] != ' ');
	arr[pos - 1] = p2;
}

bool checkP1Win(char* arr, char p1){
	if (arr[0] == p1 and arr[1] == p1 and arr[2] == p1)
		return true;
	if (arr[3] == p1 and arr[4] == p1 and arr[5] == p1)
		return true;
	if (arr[6] == p1 and arr[7] == p1 and arr[8] == p1)
		return true;

	if (arr[0] == p1 and arr[3] == p1 and arr[6] == p1)
		return true;
	if (arr[1] == p1 and arr[4] == p1 and arr[7] == p1)
		return true;
	if (arr[2] == p1 and arr[5] == p1 and arr[8] == p1)
		return true;

	if (arr[0] == p1 and arr[4] == p1 and arr[8] == p1)
		return true;
	if (arr[2] == p1 and arr[4] == p1 and arr[6] == p1)
		return true;
	return false;
}

bool checkP2Win(char* arr, char p2){
	if (arr[0] == p2 and arr[1] == p2 and arr[2] == p2)
		return true;
	if (arr[3] == p2 and arr[4] == p2 and arr[5] == p2)
		return true;
	if (arr[6] == p2 and arr[7] == p2 and arr[8] == p2)
		return true;

	if (arr[0] == p2 and arr[3] == p2 and arr[6] == p2)
		return true;
	if (arr[1] == p2 and arr[4] == p2 and arr[7] == p2)
		return true;
	if (arr[2] == p2 and arr[5] == p2 and arr[8] == p2)
		return true;

	if (arr[0] == p2 and arr[4] == p2 and arr[8] == p2)
		return true;
	if (arr[2] == p2 and arr[4] == p2 and arr[6] == p2)
		return true;
	return false;
}

bool checkDraw(char* arr){
	int count = 0;
	for (int i = 0; i < 9; i++){
		if (arr[i] != ' ')
			count++;
	}
	if (count == 9)
		return true;
	return false;
}

void result(char* arr, char p1, char p2, bool& isRunning){
	if (checkP1Win(arr, p1)){
		cout << "First player won" << endl;
		isRunning = false;
	}
	else if (checkP2Win(arr, p2)){
		cout << "Second player won" << endl;
		isRunning = false;
	}
	else if (checkDraw(arr)){
		cout << "Draw" << endl;
		isRunning = false;
	}
}

int main(){
	char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char p1 = 'X';
	char p2 = 'O';
  bool isRunning = true;
	
	display(arr);
	while (isRunning){
	p1Choice(arr, p1, p2);
	display(arr);
	result(arr, p1, p2, isRunning);
	if (isRunning == true){
	p2Choice(arr, p2, p1);
	display(arr);
	result(arr, p1, p2, isRunning);
	}
	}
}
