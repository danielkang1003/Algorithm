#include<iostream>

using namespace std;

int n, finalScore;
int playerScore[50][10]; //�� �̴׺� ���� ���� ����
int optimizedSelect[10];	//������ ���� ����� ���� �迭
bool check[10];				//������ ����� ���� �Ǻ�����

int findMaxScore(int a, int b) {
	return a > b ? a : b;
}

void gameStart() {
	int score = 0;	//�� ���Ӹ��� �������� ������ ���� ���ϸ� �ִ� ������ �� ����
	int playerIdx = 1;	//������ 1������ ����
	for (int i = 0; i < n; i++) {	//ù(0��°����) �̴� ���� ����
		int outCnt = 0;	//3�ƿ��� �Ǹ� inningChange true��
		bool inningChange = false;	//3�ƿ� �Ǵ�
		bool baseStatus[4] = { 0, };	//1,2,3�� �ڸ� 0���� ����
		while (true) {
			for (int j = playerIdx; j < 10; j++) {	//������ ���ӿ� ������
				int currentPlayer = playerScore[i][optimizedSelect[j]];	//�̴׺� ������ ���ʴ�� ��
				//���� ������ ���� 0 : �ƿ�, 1: 1��Ÿ, 2: 2��Ÿ, 3:3��Ÿ, 4: Ȩ��
				if (currentPlayer == 0) {
					//Ÿ���� �� ������ �ƿ�(0)�̸�
					outCnt++;
				}
				else if (currentPlayer == 1) {
					//1��Ÿ ġ��
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							//�տ� ���� ������ �ִٸ�
							if (go == 3) {
								//3�翡 ������ ������
								baseStatus[go] = 0;	//������ Ȩ���� �鿩����
								score++;	//���� �߰�
							}
							else {
								//2��� 1���� ������ �̵�
								baseStatus[go] = 0;
								baseStatus[go + 1] = 1;
							}
						}
					}
					baseStatus[1] = 1;	//���� Ÿ�ڰ� 1�� ġ�� 1���ڸ��� ����
				}
				else if (currentPlayer == 2) {
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							if (go == 3 || go == 2) {
								//3�� �Ǵ� 2�翡 ���� ������ �����ִٸ�
								baseStatus[go] = 0;
								score++;
							}
							else {	//go�� 1�翡 ���� �� -> 3��� ������
								baseStatus[go] = 0;
								baseStatus[go + 2] = 1;	//3��� �̵�
							}
						}
					}
					//2��Ÿ ģ ����
					baseStatus[2] = 1;	//���� Ÿ�ڰ� 2�������Ƿ� 2�� �ڸ��� �̵�
				}
				else if (currentPlayer == 3) {	//3�縦 ģ ����
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {	//3�縦 ġ�� Ÿ���� �ִ� ��� �������� �鿩������ ���� ��
							baseStatus[go] = 0;
							score++;
						}
					}
					baseStatus[3] = 1;
				}
				else {//Ȩ��(4) ģ ����
					for (int go = 1; go <= 3; go++) {
						if (baseStatus[go] == 1) {	//�տ� �����ִ� �������� �鿩������ ���� ��
							baseStatus[go] = 0;
							score++;
						}
					}
					score++;	//Ȩ��ģ ���� ������ ���� ��
				}
				if (outCnt == 3) {//3 �ƿ��� inningChange�� true�� �����ϰ� ���� Ÿ�ڸ� �����־��
					inningChange = true;
					playerIdx = j + 1;	//j���� Ÿ���� �����Ƿ� j + 1 ���ֱ�
					if (playerIdx == 10) playerIdx = 1;	//������ ������ 9���̾��ٸ� playerIdx = 10 (9 + 1)�� �ǹǷ� ó������ ������
					break;
				}
			}
			if (inningChange == true) break;
			playerIdx = 1;	//������ Ÿ�ڱ��� ���� ���´µ� 3�ƿ� �߻����� �ʾƼ� ��� �����ؾ��ϴ� ��Ȳ.
			//������ Ÿ�ڱ��� ������ �������Ƿ� 1�� �������� �ٽ� ����
		}
	}
	finalScore = findMaxScore(finalScore, score);
}

void dfs(int cnt) {
	if (cnt == 10) {
		//��� ������ ������ ����
		gameStart();	//������ ��������
		return;
	}
	for (int i = 1; i < 10; i++) {
		//9���� �������� ��ȣ �ο�
		if (check[i] == 0) {
			check[i] = 1;
			optimizedSelect[i] = cnt;
			dfs(cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			//�� �̴� ���� 10 ���� ���� ������ ����
			cin >> playerScore[i][j];
		}
	}
	//������ 4��Ÿ�ڸ� 1�� ������ ����
	optimizedSelect[4] = 1;
	check[4] = 1;
	dfs(2);	//2��° �������� ������ ���� �̱�
	cout << finalScore;
	return 0;
}