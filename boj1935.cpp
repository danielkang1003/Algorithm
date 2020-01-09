#include<iostream>
#include<stack>

using namespace std;

int n;
double answer;
string input, ret;
int arr[27];

stack<double> s;
int main() {
	cin >> n >> input;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int size = input.size();
	for (int i = 0; i < size; i++) {
		char cur = input[i];
		if (cur >= 'A' && cur <= 'Z') {
			s.push(arr[cur - 'A' + 1]);
		}
		else {
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();

			switch (cur) {
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(b * a);
				break;
			case '/':
				s.push(b / a);
				break;
			}
		}
	}
	printf("%.2f", s.top());

	return 0;
}