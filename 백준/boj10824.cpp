#include<iostream>
#include<string>
using namespace std;

int a, b, c, d;
string output1, output2;

int main() {
	cin >> a >> b >> c >> d;
	output1 = to_string(a) + to_string(b);
	output2 = to_string(c) + to_string(d);

	long long result = stoll(output1) + stoll(output2);
	cout << result;
	return 0;
}