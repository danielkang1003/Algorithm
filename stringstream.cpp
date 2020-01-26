#include<iostream>
#include<string>
#include<vector>
#include<sstream>	//헤더 선언해주어야 stringstream 사용 가능

using namespace std;
//스트링스트림은 주어진 문자열에서 필요한 정보를 빼낼 때 유용하게 사용됨
//예시
int main() {
	//1번 문자열을 실수형으로 받기
	float num1;
	stringstream s1;
	string string1 = "25 1 3 .235\n1111111\n222222";
	s1.str(string1);
	while (s1 >> num1) cout << "num: " << num1 << '\n';
	//while(s1 >> num1)은 더이상 num의 자료형(실수)에 맞는 정보가 없을때까지
	//계속 스트림에서 num으로 자료를 추출하여 복사하는 것이고 끝에 도달하면 종료

	//2번 문자열에서 문자열로 받기
	string output;
	string string2 = "23 259 .326 22 a 15";
	string string3 = "1 263avj 3135df 3235 baij af9i39a fklk30";

	stringstream s2;
	s2.str(string2);
	while (s2 >> output) cout << "string2: "<< output << '\n';
	s2.clear();
	s2.str(string3);
	while (s2 >> output) cout <<"string3: " << output << '\n';
	s2.clear();

	//만약 숫자만 받고 싶다면 output을 string이 아닌 int형으로!
	int output1;
	s2.str(string2);
	while (s2 >> output1) cout << "int형: " << output1 << '\n';
	s2.clear();
	//string2에서는 실수형인 .326 전까지만 받아서 23 259만 출력된다.
	
	//이번에는 string3에서 정수만 받기
	s2.str(string3);
	while (s2 >> output1) cout << "string 3의 int형: " << output1 << '\n';
	s2.clear();
	//결과는 1과 263만 출력된다. avj는 문자열이므로!

	//-----------응용-------------
	vector<string> input(3,"");
	input[0] = "1 Kim 89"; 
	input[1] = "2 Moon 100"; 
	input[2] = "3 Chan 78";

	for (int i = 0; i < input.size(); i++) {
		int num, score;
		string firstname;
		stringstream sss;
		sss.str(input[i]);
		sss >> num;
		sss >> firstname;
		sss >> score;
		cout << "번호: " <<num << " 이름: " << firstname << " 성적: " << score << '\n';
		//이렇게 구분한 것을 따로 저장하여 활용하면 될듯 하다.
	}


	return 0;
}