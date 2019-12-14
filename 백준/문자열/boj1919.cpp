#include<iostream>

using namespace std;

string input, change;
int input_cnt[27];
int change_cnt[27];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> input >> change;
	int i_len = input.length();
	int c_len = change.length();
	//문자열 세기
	for (int i = 0; i < i_len; i++) {
		input_cnt[input[i] - 'a']++;
	}
	for (int i = 0; i < c_len; i++) {
		change_cnt[change[i] - 'a']++;
	}
	/*cout << "첫번째 문자: ";
	for (int i = 0; i < 27; i++) cout << input_cnt[i] << ' ';
	cout << "\n두번째 문자: ";
	for (int i = 0; i < 27; i++) cout << change_cnt[i] << ' ';
	cout << '\n';*/
	int total = 0;
	for (int i = 0; i < 27; i++) {
		if (input_cnt[i] == 0 && change_cnt[i] != 0) {
			total += change_cnt[i];
		}
		else if (input_cnt[i] != 0 && change_cnt[i] == 0) {
			total += input_cnt[i];
		}
		else if (input_cnt[i] != 0 && change_cnt[i] != 0) {
			if (input_cnt[i] > change_cnt[i]) total += (input_cnt[i] - change_cnt[i]);
			else total += (change_cnt[i] - input_cnt[i]);
		}
	}
	//cout <<"삭제해야 하는 수: " << total;
	cout << total;
	return 0;
}