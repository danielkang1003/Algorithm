#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
string name;
vector<string> lists, answer;

bool binarysearch(int start, int end, string search) {
	if (start > end) return false;
	else {
		int mid = (start + end) / 2;
		//if (lists[mid] ==search) return true;
		if (!lists[mid].compare(search)) return true;
		else if (lists[mid] > search) return binarysearch(start, mid - 1, search);
		else return binarysearch(mid + 1, end, search);
	}
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		lists.push_back(name);
	}
	sort(lists.begin(), lists.end());
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (binarysearch(0, lists.size() - 1, name)) {
			//if(binary_search(lists.begin(), lists.end(), name)){
			answer.push_back(name);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}

//맵 활용한 문제 풀이
/*
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
string names;
map<string, int> list;
vector<string> v;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> names;
		list[names]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> names;
		list[names]++;
	}
	map<string, int>::iterator it;
	for (it = list.begin(); it != list.end(); it++) {
		if ((*it).second == 2) v.push_back((*it).first);
	}
	sort(v.begin(), v.end());
	cout << v.size() <<'\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
*/