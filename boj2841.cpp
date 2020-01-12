#include<iostream>
#include<vector>

using namespace std;

vector<int> v[7];
int n, p, cnt;
//벡터사용 풀이법
int main() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int r_num, p_num;
		cin >> r_num >> p_num;
		if (v[r_num].empty()) {
			cnt++;
			v[r_num].push_back(p_num);
			continue;
		}
		while (v[r_num].back() > p_num) {
			cnt++;
			v[r_num].pop_back();
			if (v[r_num].empty()) break;
		}
		if (!v[r_num].empty() && v[r_num].back() == p_num) continue;
		cnt++;
		v[r_num].push_back(p_num);
	}
	cout << cnt;
	return 0;
}


//스택 사용 풀이법
//#include<iostream>
//#include<stack>
//using namespace std;
//
//int n, p, cnt;
//stack<int> s[7];
//
//int main() {
//	ios_base::sync_with_stdio(0), cin.tie(0);
//	cin >> n >> p;
//	for (int i = 0; i < n; i++) {
//		int r_num, p_num;
//		cin >> r_num >> p_num;
//		while (true) {
//			if (s[r_num].empty()) {
//				s[r_num].push(p_num);
//				cnt++;
//				break;
//			}
//			int cur = s[r_num].top();
//			if (p_num == cur) {
//				break;
//			}
//			else if (p_num > cur) {
//				s[r_num].push(p_num);
//				cnt++;
//			}
//			else {
//				s[r_num].pop();
//				cnt++;
//			}
//		}
//	}
//	cout << cnt;
//	return 0;
//}