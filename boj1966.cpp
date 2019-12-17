#include<iostream>
#include<queue>
using namespace std;

int tc, n, m, imp, cnt;

int main() {
	cin >> tc;
	while (tc--) {
		cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			cin >> imp;
			q.push(make_pair(i, imp));
			pq.push(imp);
		}
		while (!q.empty()) {
			int currentIdx = q.front().first;
			int currentImp = q.front().second;
			q.pop();

			//���� �켱������ �߿䵵�� ť�� �ִ� �߿䵵�� ���� �ʴٸ�
			//�ѱ��
			if (currentImp != pq.top()) {
				q.push(make_pair(currentIdx, currentImp));
			}
			else {
				//�켱���� �߿䵵�� ť���ִ� �߿䵵�� ���ٸ�
				cnt++;
				pq.pop();
				if (currentIdx == m) {
					cout << cnt << '\n';
					break;
				}
			}
		}
	}

	return 0;
}