#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
//중복x 조합
int n, m;
int arr[8], check[8];
set<string> s;
vector<int> v;

bool duplicate() {
	//빈 string을 만들어줘서 vector에 있는 것을 꺼내서 넣어준다
	string temp = "";
	for (int i = 0; i < v.size(); i++) {
		temp += v[i];
	}
	//그리고 중복인지 아닌지를 확인하기 위해
	if (s.find(temp) == s.end()) {
		//set에 temp가 들어있지 않다면 넣어주고, 0 리턴
		s.insert(temp);
		return false;
	}
	else return true;	//중복이면 true(1) 리턴
}

void dfs(int idx, int k) {
	if (k == m) {
		//여기서 중복 확인
		if (duplicate() == 0) {
			for (int i = 0; i < m; i++) {
				cout << v[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			v.push_back(arr[i]);
			dfs(i, k + 1);
			v.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);

	return 0;
}