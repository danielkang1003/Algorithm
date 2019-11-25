#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int check[10];

int main() {
	//int 타입으로 받았을 경우
	/*int roomNum, set = 0;
	cin >> roomNum;
	while (1) {	
		check[roomNum % 10]++;
		if (roomNum / 10 == 0) break;
		roomNum /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (i != 9 && i != 6) set = max(set, check[i]);
	}
	cout << max(set, (check[6] + check[9] + 1) / 2);
	return 0;*/

	//string 타입으로 받았을 경우
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++) check[input[i] - '0']++;
	int set = 0;
	for (int i = 0; i < 10; i++) {
		if (i != 9 && i != 6) set = max(set, check[i]);
	}
	cout << max(set, (check[6] + check[9] + 1) / 2);
}