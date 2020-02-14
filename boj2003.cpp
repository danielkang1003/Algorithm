#include<iostream>

using namespace std;

int n, m;
int arr[10000];
//투포인터 알고리즘
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int low = 0, high = 0, sum = arr[0], answer = 0;
	while (low <= high && high < n) {
		if (sum < m) sum += arr[++high];
		else if (sum == m) {
			sum += arr[++high];
			answer++;
		}
		else {
			sum -= arr[low++];
			if (low > high&& low < n) {
				//low 가 high보다 크면 low 부터 다시 시작한다.
				high = low;
				sum = arr[low];
			}
		}
	}
	cout << answer << '\n';
	return 0;
}