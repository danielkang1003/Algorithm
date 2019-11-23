#include<iostream>
#include<cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string input;
	int count = 0;
	cin >> input;
	if (input.empty()) {
		cout << count;
		return 0;
	}
	//��� input�� .at(i) �� �ϸ� ��Ÿ�� ������ �ߴµ�,
	// []�� �̿��� ������ ������ üũ���� �ʾƼ� ������
	//��� ������ �õ��� ��� ���� �߻����� �ʰ� ���� �߻�
	// �ݸ�, at()�� �̿��� ������ ������ üũ�Ͽ� ��� ������ �õ��ϸ�
	// out of range ���ܸ� �߻��Ѵ�.
	//���� �� ���� �����Ѵٸ� ���� ���� üũ�� �ʿ� �����Ƿ� []�� ���� ����
	//�׷��� ������ at()���� �����Ͽ� ���� ó�����ֱ�
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'c') {
			if(input[i + 1] == '=' || input[i + 1] == '-')
				i++;
		}
		else if (input[i] == 'd') {
			if (input[i+1] == '-') {
				i++;
			}
			else if (input[i+1] == 'z' && input[i+2] == '=') {
				i += 2;
			}
		}
		else if (input[i] == 'l' && input[i+1] == 'j') {
			i++;
		}
		else if (input[i] == 'n' && input[i+1] == 'j') {
			i++;
		}
		else if (input[i] == 's' && input[i+1] == '=') {
			i++;
		}
		else if (input[i] == 'z' && input[i+1] == '=') {
			i++;
		}
		count++;
		
	}
	cout << count << '\n';
	return 0;
}