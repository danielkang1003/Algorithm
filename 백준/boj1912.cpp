#include<iostream>
#include<climits>

using namespace std;
int mx = INT_MIN;	//정수 중 가장 작은 값
int n, temp;
int input[100000];
int arr[100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		temp = arr[i] + input[i];
		arr[i + 1] = (input[i] > temp ? input[i] : temp);
		if (arr[i + 1] > mx) mx = arr[i + 1];
	}
	cout << mx;
}