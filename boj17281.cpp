#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n, answer;//�̴�, ���� ���� ������ ���
int expectedScore[51][10];	//�� �̴��� ������ ���� ���� ���� �迭
//������ ���� �迭
int order[10];
bool check[10];

int findMax(int a, int b) {
	return a > b ? a : b;
}

void startGame() {
	int score = 0;	//�� �̴״� ������ ���� ����
	int playerIdx = 1;	//�̴׳����� Ÿ�� ���� ���� �����ϱ� ����. 1������ ����
	int baseStatus[4];	//0: Ȩ, 1: 1��, 2: 2��, 3: 3��

	for (int i = 1; i <= n; i++) {
		int outCnt = 0;	//3�ƿ� ī��Ʈ
		bool inningCheck = false;	//3�ƿ��̸� ���� �̴����� �Ѿ true�� ������ false
		memset(baseStatus, 0, sizeof(baseStatus));
		while (true) {
			for (int j = playerIdx; j < 10; j++) {
				//1�� �������� �߱� ����
				int curPlayer = expectedScore[i][order[j]];
				//���� Ÿ���� Ÿ�ڰ� 0: �ƿ�, 1: 1��Ÿ,2: 2��Ÿ, 3: 3��Ÿ ĥ ��
				if (curPlayer == 0) outCnt++;	//�ƿ�ħ
				else if (curPlayer == 1) {
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							if (go == 3) {//3�� �ڸ��� ������
								baseStatus[go] = 0;//���°����� ó��
								score++;//���� 1�� �߰�
							}
							else {//3�� �ڸ� �ƴϸ�
								baseStatus[go + 1] = 1;	//��ĭ�� ����
								baseStatus[go] = 0;	//���� �ڸ��� �������� ǥ��
							}
						}
					}
					baseStatus[1] = 1;	//���� Ÿ�ڰ� 1��Ÿ �����Ƿ� 1�� ���¿� 1 üũ
				}
				else if (curPlayer == 2) {	//2��Ÿ
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							if (go == 3 || go == 2) {
								baseStatus[go] = 0;
								score++;
							}
							else {
								baseStatus[go + 1] = 1;
								baseStatus[go] = 0;
							}
						}
					}
					baseStatus[2] = 1;
				}
				else if (curPlayer == 3) {	//3��Ÿ
					for (int go = 3; go >= 1; go--) {	//���� ���ڵ� ��� ���� �� ����
						if (baseStatus[go] == 1) {
							baseStatus[go] = 0;
							score++;
						}
					}
					baseStatus[3] = 1;
				}
				else {
					//Ȩ��
					for (int go = 1; go <= 3; go++) {
						if (baseStatus[go] == 1) {
							baseStatus[go] = 0;
							score++;	//�տ� �����ִ� ������ �ִٸ� ���� �߰�
						}
					}
					score++;	//�ڽ��� Ȩ��ģ�� 1�� �߰�
				}

				if (outCnt == 3) {
					playerIdx = j + 1;	//���� �̴׿� �̾ ġ������
					if (playerIdx == 10) playerIdx = 1;	//������ Ÿ�ڱ��� �ƴٸ� 1�� �ٽ� ���ƿ�
					//���� 9��° Ÿ�ڿ��� ����ٸ� 9 + 1 (����Ÿ�� ���� + 1) �� 10�̶�� 1�� �ٽ� �ʱ�ȭ
					inningCheck = true;
					break;
				}
			}
			//3�ƿ����� �̴��� ������ ����
			if (inningCheck) break;
			playerIdx = 1;	//�̴��� ������ �ʾҴٸ� 1Ÿ�ڰ� �ٽ� Ÿ����
		}
	}
	answer = findMax(answer, score);
}

void dfs(int cnt) {
	if (cnt == 10) {
		//��� ������ Ÿ���� ���ϸ� ��
		/*for (int i = 0; i < 10; i++) {
			cout << order[i] << ' ';
		}
		cout << '\n';*/
		startGame();
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			order[i] = cnt;
			dfs(cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			//�� �̴״� 9�� ������ ������ ����
			cin >> expectedScore[i][j];
		}
	}
	check[4] = 1;
	order[4] = 1;	//4�� Ÿ���� Ÿ���� 1������ ���� ����
	dfs(2);

	cout << answer;
	return 0;
}