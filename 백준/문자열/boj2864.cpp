#include<iostream>
#include<string>

using namespace std;

string a, b;

int main() {
	cin >> a >> b;
	int alen = a.length(), blen = b.length();
	string aMin = a, aMax = a, bMin = b, bMax = b;
	for (int i = 0; i < alen; i++) {
		if (a[i] == '6') aMin[i] = '5';
		if (a[i] == '5') aMax[i] = '6';
	}
	for (int i = 0; i < blen; i++) {
		if (b[i] == '6') bMin[i] = '5';
		if (b[i] == '5') bMax[i] = '6';
	}


	int temp = stoi(aMin) + stoi(bMin);
	int minSum = temp;
	temp = stoi(aMax) + stoi(bMax);
	int maxSum = temp;
	cout << minSum << ' ' << maxSum << '\n';
}