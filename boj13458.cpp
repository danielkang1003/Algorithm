#include<iostream>

using namespace std;

int n, a, b, c;
int classroom[1000001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		classroom[i] = a;
	}
	cin >> b >> c;

	long long total = 0;
	for (int i = 0; i < n; i++) {
		classroom[i] = classroom[i] - b;	//총감독은 1명임. 빼주고
		total++;							//1명 늘려주기
		if (classroom[i] > 0) {				//늘려주고 나서 학생이 남으면
			int subTeacher = classroom[i] / c;	//부감독으로 넘어감
			if (classroom[i] % c != 0) {		//그러고도 학생이 남으면
				subTeacher++;					//부감독 한명 증가
			}
			total += subTeacher;			//총 감독과 부감독 수
		}
	}
	cout << total;
	return 0;
}