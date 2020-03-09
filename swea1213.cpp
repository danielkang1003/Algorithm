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
			if (search[0] == sentence[i]) {//검색하려는 첫글자와 문장의 글자가 같다면 탐색
				for (int j = 1; j < searchSize; j++) {
					if (sentence[i + j] == search[j]) continue;	//같다면 넘어감
					//cout << i <<"번쨰 " <<search[0] <<"와" << sentence[i + j] << "가 " << search[j] << "가 다릅니다\n";
					flag = false;
				}
				if (flag == true) cnt++;
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}