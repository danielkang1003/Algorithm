#include<iostream>
#include<vector>
#include<algorithm>
//BOJ 10814 ���̼� ����
//1�� ���: vector Ȱ��
//2�� ���: ����ü Ȱ��

using namespace std;

int n;

//����ü Ȱ��
struct info {
	int age;
	string name;
	int join;
};

info boj[100001];

bool comp(const info& a, const info& b) {
	if (a.age == b.age) return a.join < b.join;
	//else if (a.age < b.age) return true;
	//else return false;
	//�̰Ŵ� ��Ÿ�� ����. ����
	else if (a.age < b.age) return a.age < b.age;
	else return a.age > b.age;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> boj[i].age >> boj[i].name;
		boj[i].join = i;
	}
	sort(boj, boj + n, comp);
	for (int i = 0; i < n; i++) {
		cout << boj[i].age << ' ' << boj[i].name << '\n';
	}

	return 0;
}

//vector Ȱ��
/*
bool comp(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main() {
	cin >> n;
	vector<pair<int, string>> v(n);	//����, �̸�
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	//������ �����Ϸ��� �Ϲ� sort�� �ƴ�, stable_sort�� ���!
	//sort�� ������ �ϸ� ũ�Ⱑ ���� �� ������ �������� �������µ�
	//stable_sort�� �� ������ �����Ѵ�. ���� ���� ������� ����
	stable_sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}
*/