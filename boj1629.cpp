#include<iostream>

using namespace std;
typedef long long ll;

ll pow(ll a, ll b, ll c) {
	if (b == 0) return 1;	//a ^ 0은 1이므로
	ll val = pow(a, b / 2, c);	//재귀 시작
	val = val * val % c;
	if (b % 2 == 0) return val;	//a ^ b의 b가 짝수 일 때
	else return (val * a) % c;	//홀수라면 한번 더 나누어서 리턴
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	int result = pow(a, b, c);
	cout << result << '\n';
	return 0;
}