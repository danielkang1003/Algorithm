#include<iostream>
#include<queue>

using namespace std;

int n, k;	//����, ����
bool check[100001];

//��� 1. priority queue ���. �̵� �ð� �������� ������ ����
int pqbfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//��� �ð� �������� �켱������ �����ؾ��ؼ�
	//��� �ð��� ª���� �� ���� �켱������ ������ pq ����
	pq.push({ 0,n });	//��� �ð� ��������. ª������ �켱������ ŭ
	check[n] = 1;
	while (!pq.empty()) {
		int cnt = pq.top().first;	//�̵� �ð�
		int cur = pq.top().second;	//��ġ
		pq.pop();

		if (cur == k) return cnt;

		if (cur * 2 <= 100001 && check[cur * 2] == 0) {
			pq.push({ cnt, cur * 2 });
			check[cur * 2] = 1;
		}
		if (cur + 1 <= 100001 && check[cur + 1] == 0) {
			pq.push({ cnt + 1, cur + 1 });
			check[cur + 1] = 1;
		}
		if (cur - 1 >= 0 && check[cur - 1] == 0) {
			pq.push({ cnt + 1, cur - 1 });
			check[cur - 1] = 1;
		}
	}
}


//��� 2. �Ϲ� bfs
//�������� �������� ���� �ƴ� ���������� ���� ���� ����ó����.
int bfs() {
	queue<pair<int, int>> q;
	check[n] = 1;
	q.push({ n, 0 });	//���� ��ġ, �ð�
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;

		//cout << "���� ���� �ڸ�: " << cur << '\n';
		if (cur == k) {
			return cnt;
			break;
		}
		q.pop();

		//�����̵�
		if (cur * 2 <= 100000 && check[cur * 2] == 0) {
			q.push({ cur * 2, cnt });
			check[cur * 2] = 1;
		}
		////////////////////////////////////////////////
		//���� ó�� �����ؾ��ϴ� �κ�.
		if (cur - 1 >= 0 && check[cur - 1] == 0) {
			q.push({ cur - 1, cnt + 1 });
			check[cur - 1] = 1;
		}
		if (cur + 1 <= 100000 && check[cur + 1] == 0) {
			q.push({ cur + 1, cnt + 1 });
			check[cur + 1] = 1;
		}
		////////////////////////////////////////////////
	}
}

int main() {
	cin >> n >> k;
	//int answer = bfs();
	int answer = pqbfs();
	cout << answer;
	return 0;
}