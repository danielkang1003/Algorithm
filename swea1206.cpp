#include<iostream>
#include<cstring>

using namespace std;

int n, maxHeight, answer;
int map[1000];

//14
//0 0 3 5 2 4 9 0 6 4 0 6 0 0
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		memset(map, 0, sizeof(map));
		answer = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		for (int i = 2; i < n - 2; i++) {
			bool flag = true;	//j ������ŭ �¿� ��ĭ Ȯ���ϸ� �䰡 Ȯ�� ���� ������ false��
			maxHeight = 0;
			for (int j = i - 2; j <= i + 2; j++) {
				if (i == j) continue;
				if (map[i] > map[j]) {
					//cout << "map[" << i << "]�� map[" << j << "] �� ��� �������� Ȯ���˴ϴ�.\n";
					if (maxHeight < map[j]) maxHeight = map[j];
				}
				else if (map[i] <= map[j]) {
					//cout << "map[" << j << "] �� ���� ������ Ȯ������ �ʽ��ϴ�.\n";
					flag = false;
					break;
				}
			}
			if (flag == true) {
				answer += map[i] - maxHeight;
			}
		}
		cout << "#" << t << " " << answer << '\n';

	}
	return 0;
}