#include<iostream>
#include<algorithm>

using namespace std;

int n;

//����ü ���
struct student {
	string name;
	int kor, eng, math;
};

student roommate[100001];
//pair�� ��� ���� pair ���������� bool ���� ����
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

//pair ���
/*
int n;
pair<pair<string, int>, pair<int, int>> student[100000];

bool comp(const pair<pair<string, int>, pair<int, int>>& a, pair<pair<string, int>, pair<int, int>>& b) {
	//a ���������� ũ�� a �� ũ�� (�ڷ� ������ ����)
	if (a.first.second > b.first.second) return true;
	//���������� ���ٸ�
	else if (a.first.second == b.first.second) {
		//���� ������ �����ϵ���
		if (a.second.first < b.second.first) return true;
		//���� ������ ���ٸ�
		else if (a.second.first == b.second.first) {
			//���������� �����ϵ���
			if (a.second.second > b.second.second) return true;
			//��� ���ٸ�
			else if (a.second.second == b.second.second) {
				//�̸��� ���������� ����
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