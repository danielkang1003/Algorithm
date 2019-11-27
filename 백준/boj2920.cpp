#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
int num;


int main() {
	for (int i = 0; i < 8; i++) {
		cin >> num;
		arr.push_back(num);
	}
	
	int asc = 0, des = 0;
	//다음 수와 비교해서 높아지면 ascending
	//역순이면 descending
	//숫자 마음대로면 mixxed
	for (int i = 0; i < 8 - 1; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (arr[j] < arr[i]) des = 1;
			else if (arr[j] > arr[i]) asc = 1;
		}
	}

	if (asc == 1 && des == 1) {
		cout << "mixed" << '\n';
	}
	else if (asc == 1 && des == 0) {
		cout << "ascending" << '\n';
	}
	else if (asc == 0 && des == 1) {
		cout << "descending" << '\n';
	}
	

	return 0;
}
