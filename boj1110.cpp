#include<iostream>

using namespace std;

int main() {
	// �� �ޱ�
	int N;
	cin >> N;
	
	// �ʱ� ���� �����ϱ� ���� init
	int init = 0, result = 0;
	init = N;

	//N �� ���� �ڸ��� ���� �ڸ��� �������� ���ο� ���� �Ǳ⿡ �������ֱ�
	do{
		int before = N / 10;
		int after = N % 10;
		int sum = before + after;

		N = after * 10 + sum % 10;
		result++;
	} while (N != init);

	cout << result <<'\n';

	return 0;
}