#include<iostream>
#include<queue>
using namespace std;

int n;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	priority_queue<int, vector<int>, greater<int> > pq;
	//위의 코드와같이 선언하면 최소힙
	//priority_queue<int> 로 선언하면 최대힙
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