#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
struct XY {
	int x, y;
};

XY xy[100001];


bool comp(const XY& a, const XY& b) {
	if (a.x == b.x) return a.y < b.y;
	else if (a.x < b.x) return true;
	else return false;
}

//구조체 사용
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xy[i].x >> xy[i].y;
	}

	sort(xy, xy + n, comp);


	for (int i = 0; i < n; i++) {
		cout << xy[i].x << ' ' << xy[i].y << '\n';
	}

	return 0;
}

//bool comp(const pair<int, int>& a, const pair<int, int>& b) {
//	if (a.first == b.first) return a.second < b.second; //x가 같을 떄, y 좌표에 대해 오름차순
//	return a.first < b.first;	//x 좌표에 대해 오름차순
//}
////vector 사용
//int main() {
//	cin >> n;
//	vector < pair<int, int>> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i].first >> v[i].second;
//	}
//	sort(v.begin(), v.end(), comp);
//	for (int i = 0; i < n; i++) {
//		cout << v[i].first << ' ' << v[i].second << '\n';
//	}
//
//	return 0;
//}