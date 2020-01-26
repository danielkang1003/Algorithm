#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

string input;

void solve(string var) {
	int size = var.size() - 2;	//;는 받지 않을 예정
	for (int i = size; i >= 0; i--) {
		if (var[i] == ']') {
			cout << "[]";
			i--;
		}
		else if (var[i] == '&' || var[i] == '*') cout << var[i];
		else {
			cout << ' ';
			for (int j = 0; j <= i; j++) {
				cout << var[j];
			}
			cout << ";\n";
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	getline(cin, input);
	stringstream ss(input);
	string datatype, variable;
	ss >> datatype;
	while (ss >> variable) {
		cout << datatype;
		solve(variable);
	}
	return 0;
}