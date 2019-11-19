#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<double> arr;

int main() {
	int N, score;
	double MAX = 0.0, sum = 0.0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score;
		arr.push_back(score);
	}
	
	for (int i = 0; i < N; i++) {
		if (arr[i] > MAX) MAX = arr[i];
	}

	for (int i = 0; i < N; i++) {
		sum += (arr[i] / MAX) * 100.0;
	}
	cout << sum / N;

	return 0;
}