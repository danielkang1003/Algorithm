#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct INFO {
	int rank;
	string inp;
};

int testc, len;
string tc, inp;

INFO table[10] = {
	{0, "ZRO"},
	{ 1, "ONE" },
	{ 2, "TWO" },
	{ 3, "THR" },
	{ 4, "FOR" },
	{ 5, "FIV" },
	{ 6, "SIX" },
	{ 7, "SVN" },
	{ 8, "EGT" },
	{ 9, "NIN" }
};

vector<int> list;

int setRank(string inp) {
	for (int i = 0; i < 10; i++) {
		if (inp == table[i].inp) return table[i].rank;
	}
}

string getString(int num) {
	for (int i = 0; i < 10; i++) {
		if (num == table[i].rank) return table[i].inp;
	}
}

int main() {
	cin >> testc;
	for (int t = 1; t <= testc; t++) {
		list.clear();
		cin >> tc >> len;
		for (int i = 0; i < len; i++) {
			cin >> inp;
			list.push_back(setRank(inp));	//문자열을 받아서 알맞은 등수를 매겨준다
		}
		sort(list.begin(), list.end());
		cout << tc << '\n';
		for (int i = 0; i < len; i++) {
			if (i != 0) cout << ' ';
			cout << getString(list[i]);		//매겨진 등수로 string값을 찾는다.
		}
		cout << '\n';
	}

	return 0;
}