#include<iostream>

using namespace std;

int tNum;
string sentence, search;


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		cin >> tNum >> search >> sentence;
		int size = sentence.length();
		int searchSize = search.length();
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			bool flag = true;
			if (search[0] == sentence[i]) {//�˻��Ϸ��� ù���ڿ� ������ ���ڰ� ���ٸ� Ž��
				for (int j = 1; j < searchSize; j++) {
					if (sentence[i + j] == search[j]) continue;	//���ٸ� �Ѿ
					//cout << i <<"���� " <<search[0] <<"��" << sentence[i + j] << "�� " << search[j] << "�� �ٸ��ϴ�\n";
					flag = false;
				}
				if (flag == true) cnt++;
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}