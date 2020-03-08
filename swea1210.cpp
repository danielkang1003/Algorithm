#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int map[100][100];
//�� �� ��. ���� �ö󰡹Ƿ� ���� �ʿ� x
int dx[4] = { -1,0,0 };
int dy[4] = { 0,-1,1 };

pair<int, int> goal;

void dfs(int x, int y) {	//�� ����Ʈ x y
	int dir = 0;
	while (true) {
		if (x == 0) {
			cout << y << '\n';	//���� ��
			return;
		}
		if (dir == 0) {
			x--;
			while (true) {
				if (x == 0) break;	//�������� ������
				if (y + 1 < 100) {	//���� ������
					if (map[x][y + 1] == 1) {	//���ʿ� ���� �ִٸ�
						dir = 1;
						break;
					}
				}
				if (y - 1 >= 0) {	//���� ��
					if (map[x][y - 1] == 1) {//���ʿ� ���� �ִٸ�
						dir = 2;
						break;
					}
				}
				x--;	//�Ѵ� �ش� �ȵǸ� �ö�
			}
		}
		else if (dir == 1) {	//�������� �̵�
			y++;	//���������� �̵������ֱ�
			while (true) {
				if (x - 1 >= 0) {	//�������� �������� �ʾҴٸ�
					if (map[x - 1][y] == 1) {//���� ���� ������ ���̻� ���ʿ� ���� ���ٴ� �ŹǷ� ����
						dir = 0;
						break;
					}
				}
				y++;	//�׷��� ������
			}
		}
		else if (dir == 2) {	//�������� �̵�. ���� ����
			y--;
			while (true) {
				if (x - 1 >= 0) {
					if (map[x - 1][y] == 1) {
						dir = 0;
						break;
					}
				}
				y--;
			}
		}
	}
}

//�������� �ö������ ����
int main() {
	for (int t = 0; t < 10; t++) {
		int tnum;
		cin >> tnum;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) goal.first = i, goal.second = j; //������������ ����ϱ�
			}
		}
		cout << "#" << tnum << " ";
		dfs(goal.first, goal.second);
	}
	return 0;
}


/*
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 2

output = 4
*/