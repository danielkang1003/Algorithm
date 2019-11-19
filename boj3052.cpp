#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//B는 42로 고정입니다.
int A, B = 42;
//Array 대신 vector 사용
vector<int> arr;

int main() {
	//나머지 값을 vector에 푸시백해줍니다.
	for (int i = 0; i < 10; i++) {
		cin >> A;
		int divNum = A % B;
		arr.push_back(divNum);
	}

	
	//정렬을 해주고 unique 및 erase로 중복된 값을 제거해주어야 제대로 동작합니다.
	//벡터.erase()로 뒤에 붙은 쓰레기 값을 제거해주면 중복 원소 제거가 가능
	//Unique가 끝나면 반환되는 값은 Vector의 쓰레기 값의 첫번째 위치.
	//이로 인해 unique 후 erase 가능
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	
	cout <<'\n' << arr.size();

	return 0;
}