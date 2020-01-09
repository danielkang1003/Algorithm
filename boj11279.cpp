#include<iostream>
#include<queue>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	//priority_queue<int, vector<int>, greater<int> > pq;
	//�ּ���
	priority_queue<int>pq;	//�ִ���
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}
