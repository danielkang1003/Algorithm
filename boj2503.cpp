#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int n;
vector<pair<int, pair<int, int>>> v;
bool possibleNum[1000];

int main() {
	//세자리 수들 중에서 중복되면 possibleNum(가능한 숫자인지 확인 하는 배열)을 0(불가능)으로 만들어주기
	memset(possibleNum, 1, sizeof(possibleNum));
	for (int i = 100; i <= 999; i++) {
		string init_num = to_string(i);
		if (init_num[0] == init_num[1] || init_num[0] == init_num[2] || init_num[1] == init_num[2]) possibleNum[i] = 0;
		if (init_num[0] - '0' == 0 || init_num[1] - '0' == 0 || init_num[2] - '0' == 0) possibleNum[i] = 0;
	}

	//입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int threeNum, strike, ball;
		cin >> threeNum >> strike >> ball;
		v.push_back({ threeNum, {strike, ball} });
	}

	//입력받은 만큼 확인 작업
	int size = v.size();
	for (int i = 0; i < size; i++) {
		int v_num = v[i].first;
		int v_strike = v[i].second.first;
		int v_ball = v[i].second.second;
		string number = to_string(v_num);	//원래 숫자와
		for (int j = 100; j <= 999; j++) {
			int s_temp = 0, b_temp = 0;
			if (possibleNum[j] == 1) {
				string n_temp = to_string(j);	//가능한 숫자를 확인
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (a == b && number[a] == n_temp[b]) s_temp++;	//자리가 같고 원래 숫자와 가능한 숫자가 같으면 스트라이크 증가
						if (a != b && number[a] == n_temp[b]) b_temp++; //숫자는 같고 자리는 다르면 볼 증가
					}
				}
				if (v_strike != s_temp || v_ball != b_temp) possibleNum[j] = 0;	//벡터에 넣은 스트라이크와 볼을 비교해서 다르면 가능한 숫자에서 제외
			}
		}
	}

	//정답 출력
	int answer = 0;
	for (int i = 100; i <= 999; i++) {
		if (possibleNum[i] == 1) answer++;
	}
	cout << answer;

	return 0;
}