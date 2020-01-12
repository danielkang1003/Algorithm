#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int n;
vector<pair<int, pair<int, int>>> v;
bool possibleNum[1000];

int main() {
	//���ڸ� ���� �߿��� �ߺ��Ǹ� possibleNum(������ �������� Ȯ�� �ϴ� �迭)�� 0(�Ұ���)���� ������ֱ�
	memset(possibleNum, 1, sizeof(possibleNum));
	for (int i = 100; i <= 999; i++) {
		string init_num = to_string(i);
		if (init_num[0] == init_num[1] || init_num[0] == init_num[2] || init_num[1] == init_num[2]) possibleNum[i] = 0;
		if (init_num[0] - '0' == 0 || init_num[1] - '0' == 0 || init_num[2] - '0' == 0) possibleNum[i] = 0;
	}

	//�Է� �ޱ�
	cin >> n;
	for (int i = 0; i < n; i++) {
		int threeNum, strike, ball;
		cin >> threeNum >> strike >> ball;
		v.push_back({ threeNum, {strike, ball} });
	}

	//�Է¹��� ��ŭ Ȯ�� �۾�
	int size = v.size();
	for (int i = 0; i < size; i++) {
		int v_num = v[i].first;
		int v_strike = v[i].second.first;
		int v_ball = v[i].second.second;
		string number = to_string(v_num);	//���� ���ڿ�
		for (int j = 100; j <= 999; j++) {
			int s_temp = 0, b_temp = 0;
			if (possibleNum[j] == 1) {
				string n_temp = to_string(j);	//������ ���ڸ� Ȯ��
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (a == b && number[a] == n_temp[b]) s_temp++;	//�ڸ��� ���� ���� ���ڿ� ������ ���ڰ� ������ ��Ʈ����ũ ����
						if (a != b && number[a] == n_temp[b]) b_temp++; //���ڴ� ���� �ڸ��� �ٸ��� �� ����
					}
				}
				if (v_strike != s_temp || v_ball != b_temp) possibleNum[j] = 0;	//���Ϳ� ���� ��Ʈ����ũ�� ���� ���ؼ� �ٸ��� ������ ���ڿ��� ����
			}
		}
	}

	//���� ���
	int answer = 0;
	for (int i = 100; i <= 999; i++) {
		if (possibleNum[i] == 1) answer++;
	}
	cout << answer;

	return 0;
}