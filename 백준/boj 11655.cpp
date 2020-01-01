#include<iostream>
#include<string>
using namespace std;

string input;
int rot = 13;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (getline(cin, input)) {
		int size = input.size();
		for (int i = 0; i < size; i++) {
			if (input[i] >= 'A' && input[i] <= 'M') {
				input[i] += rot;
			}
			else if (input[i] >= 'N' && input[i] <= 'Z') {
				input[i] -= rot;
			}
			else if (input[i] >= 'a' && input[i] <= 'm') {
				input[i] += rot;
			}
			else if (input[i] >= 'n' && input[i] <= 'z') {
				input[i] -= rot;
			}

			cout << input[i];
		}
	}
	return 0;
}