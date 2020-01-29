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
	if (s.find(temp) == s.end()) {	//�������� �ʴ´ٴ� ��
		//temp���ڸ� ã�� �����ϰ� set�� ������ ���Ƽ� ������
		//temp�� �����ϰ� �ߺ��ȉ����� ǥ��
		s.insert(temp);	//�������� �� ���ڰ� ���Դ��� Ȯ�� ���� set�� �־���
		return false;
	}
	else return true;	//temp�� �ִٸ� �ߺ��̹Ƿ� true ǥ��
	//else if(s.find(temp) != s.end())�� ����
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		if (duplicate() == 0) {
			//���� ���� ����� ������
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