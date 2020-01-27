#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int t, answer;
string input;
int arr[10];
int check[10];
int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> input;
        answer = 0;
        memset(arr, 0, sizeof(arr));
        int len = input.length();
        for (int i = 0; i < len; i++) {
            arr[input[i] - '0']++;
        }

        ////출력 확인
        //for (int i = 0; i < 10; i++) {
        //  cout << arr[i] << ' ';
        //}
        //cout << '\n';

        for (int i = 0; i < 10; i++) {
            if (arr[i] % 2 == 1) {
                //숫자가 써져있다는 뜻
                answer++;
            }
        }

        cout << "#" << tc << ' ' << answer << '\n';
    }
    return 0;
}