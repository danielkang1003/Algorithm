#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int rev(int n) {
	int a, b, c, d;
	
	a = n % 10;	//���� �ڸ� ���� ��ȯ
	b = (n / 10) % 10;	//���� �ڸ� �� ��ȯ
	c = n / 100;	//���� �ڸ� �� ��ȯ
	d = a * 100 + b * 10 + c;

	return d;
}

int main() {
	int a, b;
	cin >> a >> b;
	
	int c = rev(a);
	int d = rev(b);
	
	if (c > d) cout << c;
	else cout << d;
	
	return 0;
}