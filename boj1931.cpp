#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> time[100001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	//(����, ��) �ð��� �ƴ�, (���ð�, ���۽ð�)���� ����
	for (int i = 0; i < n; i++) {
		cin >> time[i].second >> time[i].first;
	}

	sort(time, time + n);
	/*for (int i = 0; i < n; i++) {
		cout << time[i].first << ' ' <<time[i].second<<'\n';
	}*/
	int res = 0;	//�ִ� ����� �� �ִ� ȸ�Ǽ� ī��Ʈ
	int cur = 0;	//���� �ð��� ����ش�.
	for (int i = 0; i < n; i++) {
		if (cur > time[i].second) continue;	//���� ����ð����� ���۽ð��� �����̶�� �Ѿ��
		//cout << "���� �ð�: " << cur << " " << "�� ȸ��" << time[i].first << " " << time[i].second << '\n';
		res++;	//ȸ�� �� ���� ( ���� �ð��� ����ð� ������ ȸ���̹Ƿ�)
		cur = time[i].first;	//����ð��� ������ �ð����� ����

	}
	cout << res << '\n';
	return 0;
}