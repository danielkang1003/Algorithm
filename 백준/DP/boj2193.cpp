#include<iostream>
using namespace std;
//2차원 DP 풀이
//N자리 이친수의 개수를 구하는 문제
//점화식: D[N][L] = N자리 이친수 마지막 수 L
//1. D[N][0] = D[N-1][0] + D[N-1][1]
//2. D[N][1] = D[N-1][0]
//초기 값: 길이가 가장 짧은 이친수는 길이가 1
//D[1][0] = 0
//D[1][1] = 1

//1차원 DP 풀이
//DP[N] = N자리 이친수
//1. DP[N-1] 자리에는 0 과 1 모두 가능
//2. DP[N-2] 는 D[N-1]자리에 0 만 가능 D[N]이 1일때
//즉 DP[N] = DP[N-1] + DP[N-2]


long long d[91]; //피보나치와 같음. 40이 넘어가면 안되서 long long
int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n] << '\n';
	return 0;
}
