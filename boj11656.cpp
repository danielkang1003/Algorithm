#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string input;
string arr[1000];

vector<string> v;

int main() {
	cin >> input;
	int size = input.size();
	for (int i = 0; i < size; i++) {
		/*string suffix = "";
		for (int j = i; j < size; j++) {
			suffix += input[j];
		}
		arr[i] = suffix;*/
		v.push_back(input.substr(i, size));


	}
	//sort(arr, arr + size);
	//for (int i = 0; i < size; i++) {
	//	cout << arr[i] << '\n';
	//}
	sort(v.begin(), v.end());
	for (int i = 0; i < size; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}