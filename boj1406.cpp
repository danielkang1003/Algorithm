#include<iostream>
#include<string>
#include<list>
using namespace std;


//두가지 방법
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string input;
	cin >> input;
	list<char> L;
	for (auto c : input) L.push_back(c);
	auto cursor = L.end();	//커서 마지막에 위치
	int Q;
	cin >> Q;
	string tmp;	//줄바꿈 한 개 제거
	getline(cin, tmp);
	while (Q--) {
		string order;
		getline(cin, order);
		if(order[0] == 'L'){
			if (cursor != L.begin()) cursor--;
		}
		else if (order[0] == 'D') {
			if (cursor != L.end()) cursor++;
		}
		else if (order[0] == 'P') {
			L.insert(cursor, order[2]);
		}
		else {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}
	for (auto c : L) cout << c;

	return 0;
}



//#include<iostream>
//#include<cstring>
//#include<stack>
//
//char a[600000];
//using namespace std;
//
//int main(void) {
//	scanf("%s", a);
//	stack<char> left, right;
//	int len = strlen(a);
//	for (int i = 0; i < len; i++) {
//		left.push(a[i]);
//	}
//	int n;
//	scanf("%d", &n);
//	while (n--) {
//		char sth;
//		scanf(" %c", &sth);
//		if (sth == 'L') {	//L입력되면 왼쪽위 값 오른쪽으로 push
//			if (!left.empty()) {	//왼쪽에서 top값 pop
//				right.push(left.top());
//				left.pop();
//			}
//		}
//		else if (sth == 'D') {	//위와 같은 로직	
//			if (!right.empty()) {
//				left.push(right.top());
//				right.pop();
//			}
//		}
//		else if (sth == 'B') {	//삭제 부분은
//			if (!left.empty()) {	//왼쪽 없애주면 됨
//				left.pop();
//			}
//		}
//		else if (sth == 'P') {	//값 더하기는
//			char word;
//			scanf(" %c", &word);
//			left.push(word);	//push로 값 받은거 추가
//		}
//	}
//	while (!left.empty()) {	//왼쪽에 있는 값을 오른쪽으로 이동
//		right.push(left.top());
//		left.pop();
//	}
//	while (!right.empty()) {	//오른쪽 값 출력
//		printf("%c", right.top());
//		right.pop();
//	}
//
//	//	//일단 출력 잘됨 
//	//	while(!left.empty()){
//	//		printf("%c", left.top());
//	//		left.pop();
//	//	}
//	return 0;
//}