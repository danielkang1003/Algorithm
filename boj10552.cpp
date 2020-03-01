#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int n, m, p;	//��� ��, Ƽ�� ä�� ��, Ƽ�� ���� ä��
vector<int> channel[100001];
bool check[100001];

int changeChannel() {
	queue<int> q;
	q.push(p);	//ù ä�� �־���
	check[p] = 1;	//���� ä�� üũ

	int cnt = 0;
	while (!q.empty()) {
		int currentCh = q.front();
		q.pop();

		if (channel[currentCh].size() == 0) return cnt;	//ä���� �Ⱦ��ϴ� ������ִٸ� 1�̻��� ��
		if (check[channel[currentCh][0]] == true)break;	//�湮�ߴٸ�
		q.push(channel[currentCh][0]);	//�����ϴ� ä�� �ֱ�
		check[channel[currentCh][0]] = 1;	//�湮 üũ
		cnt++;

	}
	return -1;	//�׷��� ���� ��
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {	//���� ���� -> ū ��
		int a, b;	//�����ϴ� ä��, �Ⱦ��ϴ� ä��
		cin >> a >> b;
		channel[b].push_back(a);	//�Ⱦ��ϴ� ä���� �ε����� �ΰ� �����ϴ� ä�� �ֱ�
	}
	//������� ä�� ���濡 �ʿ��� Ƚ��, �ȵȴٸ� -1
	cout << changeChannel() << '\n';

}