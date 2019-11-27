#include<iostream>
#include<algorithm>

using namespace std;

int n;

//구조체 사용
struct student {
	string name;
	int kor, eng, math;
};

student roommate[100001];
//pair와 방식 동일 pair 구현에서의 bool 내용 참고
bool comp(const student& a, const student& b) {
	if (a.kor > b.kor) return true;
	else if (a.kor == b.kor) {
		if (a.eng < b.eng) return true;
		else if (a.eng == b.eng) {
			if (a.math > b.math) return true;
			else if (a.math == b.math) {
				if (a.name < b.name) return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> roommate[i].name >> roommate[i].kor >>
			roommate[i].eng >> roommate[i].math;
	}
	sort(roommate, roommate + n, comp);
	for (int i = 0; i < n; i++) {
		cout << roommate[i].name << '\n';
	}
	return 0;
}

//pair 사용
/*
int n;
pair<pair<string, int>, pair<int, int>> student[100000];

bool comp(const pair<pair<string, int>, pair<int, int>>& a, pair<pair<string, int>, pair<int, int>>& b) {
	//a 국어점수가 크면 a 가 크게 (뒤로 갈수록 감소)
	if (a.first.second > b.first.second) return true;
	//국어점수가 같다면
	else if (a.first.second == b.first.second) {
		//영어 점수는 증가하도록
		if (a.second.first < b.second.first) return true;
		//영어 점수도 같다면
		else if (a.second.first == b.second.first) {
			//수학점수는 감소하도록
			if (a.second.second > b.second.second) return true;
			//모두 같다면
			else if (a.second.second == b.second.second) {
				//이름이 사전순으로 증가
				if (a.first.first < b.first.first) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> student[i].first.first >> student[i].first.second >>
			student[i].second.first >> student[i].second.second;
	}
	sort(student, student + n, comp);
	for (int i = 0; i < n; i++) {
		cout << student[i].first.first << '\n';
	}

	return 0;
}
*/