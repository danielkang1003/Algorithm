#include<iostream>

using namespace std;

void star(int N);

int main() {
	int N;
	cin >> N;

	star(N);

	return 0;
}

void star(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int ni = i, nj = j;
			while (ni) {
				if (ni % 3 == 1 && nj % 3 == 1) {
					break;
				}
				ni /= 3, nj /= 3;
			}
			cout << (ni ? ' ' : '*');
		}
		cout << '\n';
	}
}
