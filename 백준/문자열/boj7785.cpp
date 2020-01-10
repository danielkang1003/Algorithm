#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	set<string, greater<string>> lists;	//정렬도 함꼐 적용
	int n;
	cin >> n;
	while (n--) {
		string name, enter;
		cin >> name >> enter;
		if (enter == "enter") lists.insert(name);
		else lists.erase(name);
	}
	set<string, greater<string>>::iterator it;
	for (it = lists.begin(); it != lists.end(); it++) cout << *it << '\n';
	return 0;
}