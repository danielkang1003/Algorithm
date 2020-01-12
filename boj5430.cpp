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
		temp = "";	//���ڰ� 100���� ũ���̹Ƿ� �������� ���ڷ� �ٲپ��� �۾��� ���� �ʿ�
		for (int i = 0; i < size; i++) {
			char cur = arrNum[i];
			//cout << "cur�� : " << cur <<'\n';

			////////temp = ""; //�̺κж����� ��� error�� ����.. ��� ���鼭 Null�� �ʱ�ȭ�ϴϱ�.. for �� ���� ���־����.

			if (cur == '[') {
				//cout << cur << "�� [ �̱⿡ �Ѿ�ϴ�.\n";
				continue;
			}
			else if (cur >= '0' && cur <= '9') {
				//cout << "temp �� " << temp << " cur�� " << cur <<'\n';
				temp += cur;		//���ڶ�� temp�� �ٿ���
				//cout << "temp ������Ʈ : " << temp <<'\n';
			}
			else if (cur == ',' || cur == ']') {	// �޸��� ������ ���ڰ� �����ٴ� �̾߱� ���� �־��ֱ�
				//cout << "temp�� " << temp << "�̰�, cur�� " << cur << '\n';
				if (!temp.empty()) {	//temp�� ����ִ�(NULL)�� ���� ���̹Ƿ� ������ �ȵ�
					//cout << "temp�� ������� �ʽ��ϴ�. temp : " << temp;
					dq.push_back(stoi(temp));	//stoi�� ���ڿ��� ������ ����
					temp = "";					//���� ���ڰ� �����Ƿ� �ʱ�ȭ
				}
			}
		}
		bool check = 1, reverseNum = 1;	//check�� ���� Ȯ�ο�, reverse�� R�Է� ���°� Ȯ��
		int orderSize = order.size();
		for (int i = 0; i < orderSize; i++) {
			if (order[i] == 'R') {
				//�������� ��� ���Դ��� Ȯ��(���� �������� �ι� ���´ٸ� �ȵ���� �ǹǷ�)
				reverseNum = !reverseNum;	//1�� ���������� ����, 0�� ������
			}
			else {
				//D�̸�
				if (dq.empty()) {
					//D�ε� ���� ���������(���ڰ� �Է¾ȵ̴ٴ� �̾߱�)
					check = 0;
					cout << "error\n";
					break;
				}
				else {
					//D�̰� ������� ������
					if (reverseNum) dq.pop_front();	//������ ���� ����
					else dq.pop_back();			//������ �����̹Ƿ� �ڸ� ����
				}
			}
		}
		if (check) {	//������ �ƴ϶�� ����Ʈ���־���ϱ⿡ ����
			if (reverseNum) {//������ ���� ����
				cout << '[';
				while (!dq.empty()) {//���� �������� ���
					int curNum = dq.front();
					cout << curNum;	//������ ���� �����̹Ƿ� �պκ��� ���
					dq.pop_front();
					if (!dq.empty()) cout << ',';	//���ڵڿ� �޸��� �ٿ��־����
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!dq.empty()) {
					int curNum = dq.back();
					cout << curNum;
					dq.pop_back();		//�������� �����̹Ƿ� �ڸ� ���־����
					if (!dq.empty()) cout << ',';
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}