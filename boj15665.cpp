#include<iostream>
#include<algorithm>
//#include<vector>
#include<set>
//순열 문제 중복가능
//벡터랑 배열 둘 다 가능
using namespace std;

int n, m;
int arr[7];
//vector<int> v;
int saved[7];
set<string> s;

bool duplicate() {
	string temp = "";
	/*for (int i = 0; i < v.size(); i++) {
		temp += v[i];
	}*/
	for (int i = 0; i < m; i++) {
		temp += saved[i];
	}
	if (s.find(temp) == s.end()) {
		s.insert(temp);
		return false;
	}
	else return true;
}
void dfs(int k) {
	if (k == m) {
		if (duplicate() == 0) {
			/*for (int i = 0; i < m; i++) {
				cout << v[i] << ' ';
			}*/
			for (int i = 0; i < m; i++) {
				cout << saved[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		saved[k] = arr[i];
		//v.push_back(arr[i]);
		dfs(k + 1);
		//v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0);
	return 0;
}