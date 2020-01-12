#include<iostream>
#include<string>
#include<deque>

using namespace std;

int tc, n;
string order, arrNum, temp;
deque<int> dq;

int main() {
	cin >> tc;
	while (tc--) {
		cin >> order >> n >> arrNum;
		int size = arrNum.size();
		temp = "";	//숫자가 100까지 크기이므로 정수에서 숫자로 바꾸어줄 작업을 위해 필요
		for (int i = 0; i < size; i++) {
			char cur = arrNum[i];
			//cout << "cur은 : " << cur <<'\n';

			////////temp = ""; //이부분때문에 모두 error로 떳음.. 계속 돌면서 Null로 초기화하니까.. for 문 위로 빼주어야함.

			if (cur == '[') {
				//cout << cur << "이 [ 이기에 넘어갑니다.\n";
				continue;
			}
			else if (cur >= '0' && cur <= '9') {
				//cout << "temp 는 " << temp << " cur은 " << cur <<'\n';
				temp += cur;		//숫자라면 temp에 붙여줌
				//cout << "temp 업데이트 : " << temp <<'\n';
			}
			else if (cur == ',' || cur == ']') {	// 콤마가 나오면 숫자가 끝낫다는 이야기 덱에 넣어주기
				//cout << "temp는 " << temp << "이고, cur은 " << cur << '\n';
				if (!temp.empty()) {	//temp가 비어있다(NULL)은 없는 수이므로 넣으면 안됨
					//cout << "temp가 비어있지 않습니다. temp : " << temp;
					dq.push_back(stoi(temp));	//stoi로 문자열을 정수로 변경
					temp = "";					//이후 숫자가 끝나므로 초기화
				}
			}
		}
		bool check = 1, reverseNum = 1;	//check는 에러 확인용, reverse는 R입력 들어온것 확인
		int orderSize = order.size();
		for (int i = 0; i < orderSize; i++) {
			if (order[i] == 'R') {
				//리버스가 몇번 나왔는지 확인(만약 리버스가 두번 나온다면 안뒤집어도 되므로)
				reverseNum = !reverseNum;	//1은 뒤집어지지 않은, 0은 뒤집은
			}
			else {
				//D이면
				if (dq.empty()) {
					//D인데 덱이 비어있으면(숫자가 입력안됫다는 이야기)
					check = 0;
					cout << "error\n";
					break;
				}
				else {
					//D이고 비어있지 않으면
					if (reverseNum) dq.pop_front();	//뒤집지 않은 상태
					else dq.pop_back();			//뒤집은 상태이므로 뒤를 빼기
				}
			}
		}
		if (check) {	//에러가 아니라면 프린트해주어야하기에 진행
			if (reverseNum) {//뒤집지 않은 상태
				cout << '[';
				while (!dq.empty()) {//덱이 빌때까지 출력
					int curNum = dq.front();
					cout << curNum;	//뒤집지 않은 상태이므로 앞부분을 출력
					dq.pop_front();
					if (!dq.empty()) cout << ',';	//숫자뒤에 콤마도 붙여주어야함
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!dq.empty()) {
					int curNum = dq.back();
					cout << curNum;
					dq.pop_back();		//뒤집어진 상태이므로 뒤를 빼주어야함
					if (!dq.empty()) cout << ',';
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}