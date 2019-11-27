#include<iostream>

using namespace std;

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string ox;
		cin >> ox;
		int count = 0, answer = 0;
		for (int j = 0; j < ox.size(); j++) {
			if (ox.at(j) == 'O') count++;
			else count = 0;
			answer += count;
		}
		cout << answer << '\n';
	}

	return 0;
}
