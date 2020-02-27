#include<iostream>
#include<vector>

using namespace std;

int n, weight, height;
vector<pair<int, int>> v;
int ranking[50];
void compareRank() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].first > v[j].first&& v[i].second > v[j].second) {
				ranking[j]++;	//모두가 클 때만 증가 시켜준다. 그래서 1등은 0개의 카운트를 가지게 될 것
			}
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		cout << ranking[i] + 1 << " ";	// 모든 값에 + 1 해주어서 등수 매겨주기
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight >> height;
		v.push_back({ weight, height });
	}
	compareRank();
	print();
}