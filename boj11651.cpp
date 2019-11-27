#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

//bool comp(const pair<int, int>& a, const pair<int, int>& b) {
//	if (a.second == b.second) return a.first < b.first;
//	else return a.second < b.second;
//}
struct XY {
	int x, y;
};

XY xy[100001];

bool comp(const XY& a, const XY& b) {
	if (a.y < b.y) return true;
	else if (a.y == b.y) {
		if (a.x < b.x) return true;
	}
	return false;
}

int main() {
	cin >> n;
	//구조체로 풀기
	for (int i = 0; i < n; i++) {
		cin >> xy[i].x >> xy[i].y;
	}
	sort(xy, xy + n, comp);
	for (int i = 0; i < n; i++) {
		cout << xy[i].x << ' ' << xy[i].y << '\n';
	}

	//벡터로 풀기
	/*vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first <<' '<< v[i].second <<'\n';
	}*/
	return 0;
}