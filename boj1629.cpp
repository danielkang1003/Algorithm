#include<iostream>

using namespace std;
typedef long long ll;

ll pow(ll a, ll b, ll c) {
	if (b == 0) return 1;	//a ^ 0�� 1�̹Ƿ�
	ll val = pow(a, b / 2, c);	//��� ����
	val = val * val % c;
	if (b % 2 == 0) return val;	//a ^ b�� b�� ¦�� �� ��
	else return (val * a) % c;	//Ȧ����� �ѹ� �� ����� ����
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	int result = pow(a, b, c);
	cout << result << '\n';
	return 0;
}