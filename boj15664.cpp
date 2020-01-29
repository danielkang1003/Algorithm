#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n, m;
int arr[8];
bool check[8];
vector<int> v;
set<string> s;

bool duplicate() {
	string temp = "";
	for (int i = 0; i < v.size(); i++) {
		temp += v[i];
	}
	if (s.find(temp) == s.end()) {	//존재하지 않는다는 뜻
		//temp숫자를 찾기 시작하고 set의 끝까지 돌아서 없으면
		//temp를 삽입하고 중복안됬으니 표시
		s.insert(temp);	//다음번에 이 숫자가 들어왔는지 확인 위해 set에 넣어줌
		return false;
	}
	else return true;	//temp가 있다면 중복이므로 true 표시
	//else if(s.find(temp) != s.end())와 같음
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		if (duplicate() == 0) {
			//같은 숫자 사용이 없으면
			for (int i = 0; i < m; i++) {
				cout << v[i] << ' ';
			}
			cout << '\n';
			return;
		}
	}
	for (int i = idx; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i + 1, cnt + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}