#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k;
int food[11][11];
int addFood[11][11];
vector<int> tree[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void print() {
	cout << "################\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << food[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "################\n";
}

void ssSeason() {	//������ ����
	//print();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;
			//������ ���ٸ� ������
			int deadTreeFood = 0;
			vector<int> addAge;
			sort(tree[i][j].begin(), tree[i][j].end());	//���̰� �����Ű� ������ ��������
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				//cout << "(" << i << ' ' << j << ")�� ���� ����: " << age <<'\n';
				if (food[i][j] >= age) {//����� �������� ������
					food[i][j] -= age;
					addAge.push_back(age + 1);
					//cout << "����� ����ؼ� (" << i << ' ' << j << ")�� ���̴�" << age << "�̰� ���� ����� " << food[i][j] << '\n';
				}
				else {
					deadTreeFood += (age / 2);
					//cout << "(" << i << ' ' << j << ")�� ������ �׾� ����� " << deadTreeFood << "��ŭ �߰��˴ϴ�\n";
				}
			}
			tree[i][j].clear();	//�����ߴ� ��������ְ� ���� �־��ֱ�
			for (int k = 0; k < addAge.size(); k++) {
				tree[i][j].push_back(addAge[k]);	//����� �־ ���̸� ���� ������ �־���
			}
			food[i][j] += deadTreeFood;
		}
	}
	//cout << "��& ����: \n";
	//print();
}

void fall() { //�������� ���� ����. ���̴� 5����ΰ͸� ���� 8ĭ�� ���̰� 1�� ���� ����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) {
				//cout << "(" << i << ',' << j << ")�� ������ �����ϴ�.\n";
				continue;
			}

			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (age % 5 == 0) {
					//cout << "(" << i << ',' << j << ")�� ���̰� 5�� ��� �Դϴ�.\n";
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= n + 1) continue;
						tree[nx][ny].push_back(1);
					}
				}

				//cout << "(" << i << ',' << j << ")�� ������ ������ ���̰� " << age << "�� 5�� ����� �ƴմϴ�\n";
			}
		}
	}
	//cout << "����: \n";
	//print();
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += addFood[i][j];
		}
	}
	//cout << "�ܿ�: \n";
	//print();
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> addFood[i][j];
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, old;
		cin >> x >> y >> old;
		tree[x][y].push_back(old);	//�� ĭ�� �������� ������ �������� �����Ƿ� �� ������ ���̸� ����
	}

	for (int i = 0; i < k; i++) {
		//k����� ����� Ȱ��
		ssSeason();
		fall();
		winter();
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++)
				answer++;
		}
	}
	cout << answer;
	return 0;
}