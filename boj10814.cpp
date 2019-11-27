#include<iostream>
#include<vector>
#include<algorithm>
//BOJ 10814 나이순 정렬
//1번 방법: vector 활용
//2번 방법: 구조체 활용

using namespace std;

int n;

//구조체 활용
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
	//이거는 런타임 에러. 터짐
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

//vector 활용
/*
bool comp(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main() {
	cin >> n;
	vector<pair<int, string>> v(n);	//나이, 이름
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	//순서를 보존하려면 일반 sort가 아닌, stable_sort를 사용!
	//sort는 정렬을 하면 크기가 같을 때 순서가 랜덤으로 정해지는데
	//stable_sort는 그 순서를 보존한다. 먼저 들어온 순서대로 정렬
	stable_sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}
*/