#include<iostream>
#include<string>
#include<list>
using namespace std;


//�ΰ��� ���
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string input;
	cin >> input;
	list<char> L;
	for (auto c : input) L.push_back(c);
	auto cursor = L.end();	//Ŀ�� �������� ��ġ
	int Q;
	cin >> Q;
	string tmp;	//�ٹٲ� �� �� ����
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
//		if (sth == 'L') {	//L�ԷµǸ� ������ �� ���������� push
//			if (!left.empty()) {	//���ʿ��� top�� pop
//				right.push(left.top());
//				left.pop();
//			}
//		}
//		else if (sth == 'D') {	//���� ���� ����	
//			if (!right.empty()) {
//				left.push(right.top());
//				right.pop();
//			}
//		}
//		else if (sth == 'B') {	//���� �κ���
//			if (!left.empty()) {	//���� �����ָ� ��
//				left.pop();
//			}
//		}
//		else if (sth == 'P') {	//�� ���ϱ��
//			char word;
//			scanf(" %c", &word);
//			left.push(word);	//push�� �� ������ �߰�
//		}
//	}
//	while (!left.empty()) {	//���ʿ� �ִ� ���� ���������� �̵�
//		right.push(left.top());
//		left.pop();
//	}
//	while (!right.empty()) {	//������ �� ���
//		printf("%c", right.top());
//		right.pop();
//	}
//
//	//	//�ϴ� ��� �ߵ� 
//	//	while(!left.empty()){
//	//		printf("%c", left.top());
//	//		left.pop();
//	//	}
//	return 0;
//}