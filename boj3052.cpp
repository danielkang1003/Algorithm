#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//B�� 42�� �����Դϴ�.
int A, B = 42;
//Array ��� vector ���
vector<int> arr;

int main() {
	//������ ���� vector�� Ǫ�ù����ݴϴ�.
	for (int i = 0; i < 10; i++) {
		cin >> A;
		int divNum = A % B;
		arr.push_back(divNum);
	}

	
	//������ ���ְ� unique �� erase�� �ߺ��� ���� �������־�� ����� �����մϴ�.
	//����.erase()�� �ڿ� ���� ������ ���� �������ָ� �ߺ� ���� ���Ű� ����
	//Unique�� ������ ��ȯ�Ǵ� ���� Vector�� ������ ���� ù��° ��ġ.
	//�̷� ���� unique �� erase ����
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	
	cout <<'\n' << arr.size();

	return 0;
}