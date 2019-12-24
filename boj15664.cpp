#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
//�ߺ�x ����
int n, m;
int arr[8], check[8];
set<string> s;
vector<int> v;

bool duplicate() {
	//�� string�� ������༭ vector�� �ִ� ���� ������ �־��ش�
	string temp = "";
	for (int i = 0; i < v.size(); i++) {
		temp += v[i];
	}
	//�׸��� �ߺ����� �ƴ����� Ȯ���ϱ� ����
	if (s.find(temp) == s.end()) {
		//set�� temp�� ������� �ʴٸ� �־��ְ�, 0 ����
		s.insert(temp);
		return false;
	}
	else return true;	//�ߺ��̸� true(1) ����
}

void dfs(int idx, int k) {
	if (k == m) {
		//���⼭ �ߺ� Ȯ��
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