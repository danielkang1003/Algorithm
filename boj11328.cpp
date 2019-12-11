#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
string input1, input2;
char arr1[1001], arr2[1001];


int main() {
	cin >> n;
	while (n--) {
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));

		cin >> input1 >> input2;
		int len = input1.length();
		for (int i = 0; i < len; i++) {
			arr1[i] = input1[i];
			arr2[i] = input2[i];
		}

		sort(arr1, arr1 + len);
		sort(arr2, arr2 + len);
		bool flag = false;
		for (int i = 0; i < len; i++) {
			if (arr1[i] != arr2[i]) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "Impossible\n";
		else cout << "Possible\n";

	}

	return 0;
}