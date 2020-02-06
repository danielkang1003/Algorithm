#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int n, input;
ll answer = 0, cnt;
ll factorial[21];
bool check[21];
vector<int> v;

int main() {
	cin >> n >> input;
	memset(check, 0, sizeof(check));
	factorial[0] = 1;
	for (int i = 1; i <= 20; i++)
		factorial[i] = factorial[i - 1] * i;

	switch (input) {
	case 1:
		cin >> cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j] == 1)continue;
				if (factorial[n - i - 1] < cnt) {
					cnt -= factorial[n - i - 1];
				}
				else {
					v.push_back(j);
					check[j] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (check[j] == 0) answer += factorial[n - i - 1];
			}
			check[v[i]] = 1;
		}
		cout << answer + 1 << '\n';
		break;
	}

	return 0;
}