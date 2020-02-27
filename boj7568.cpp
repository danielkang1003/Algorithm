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
				ranking[j]++;	//��ΰ� Ŭ ���� ���� �����ش�. �׷��� 1���� 0���� ī��Ʈ�� ������ �� ��
			}
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		cout << ranking[i] + 1 << " ";	// ��� ���� + 1 ���־ ��� �Ű��ֱ�
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