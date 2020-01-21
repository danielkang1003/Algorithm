#include<iostream>
#include<algorithm>
using namespace std;

struct countries {
	int num, gold, silver, bronze, rank = 1;
};

int n, k;
struct countries country[1000];

bool comp(countries a, countries b) {
	if (a.gold > b.gold) return true;
	else if (a.gold == b.gold) {
		if (a.silver > b.silver) return true;
		else if (a.silver == b.silver) return a.bronze > b.bronze ? true : false;
		else return false;
	}
	else return false;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> country[i].num >> country[i].gold >> country[i].silver >> country[i].bronze;
	}
	sort(country, country + n, comp);

	//cout << "등수 설정 전 정렬 : \n";
	//for (int i = 0; i < n; i++) {
	//	cout << country[i].num << ' ' << country[i].gold << " " << country[i].silver << ' ' << country[i].bronze <<'\n';
	//}

	//중복 등수 설정
	for (int i = 1; i < n; i++) {
		if (country[i].gold == country[i - 1].gold && country[i].silver == country[i - 1].silver && country[i].bronze == country[i - 1].bronze)
			country[i].rank = country[i - 1].rank;
		else country[i].rank = i + 1;
	}

	//cout << "등수 설정 완료: \n";
	//for (int i = 0; i < n; i++) {
	//	cout << "국가: " << country[i].num << " 등수: " << country[i].rank << " 금: " << country[i].gold << " 은: " << country[i].silver << " 동: " << country[i].bronze << '\n';
	//}

	for (int i = 0; i < n; i++) {
		if (country[i].num == k) cout << country[i].rank;
	}
}