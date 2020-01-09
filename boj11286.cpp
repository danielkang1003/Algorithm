#include<iostream>
#include<queue>

using namespace std;

int n, num;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//pair�� ����ϸ� ���밪�� ���� �ڵ鸵�� �����ϴ�.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else {
			pq.push({ abs(num), num });
		}
	}

	return 0;
}