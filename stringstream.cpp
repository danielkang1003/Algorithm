#include<iostream>
#include<string>
#include<vector>
#include<sstream>	//��� �������־�� stringstream ��� ����

using namespace std;
//��Ʈ����Ʈ���� �־��� ���ڿ����� �ʿ��� ������ ���� �� �����ϰ� ����
//����
int main() {
	//1�� ���ڿ��� �Ǽ������� �ޱ�
	float num1;
	stringstream s1;
	string string1 = "25 1 3 .235\n1111111\n222222";
	s1.str(string1);
	while (s1 >> num1) cout << "num: " << num1 << '\n';
	//while(s1 >> num1)�� ���̻� num�� �ڷ���(�Ǽ�)�� �´� ������ ����������
	//��� ��Ʈ������ num���� �ڷḦ �����Ͽ� �����ϴ� ���̰� ���� �����ϸ� ����

	//2�� ���ڿ����� ���ڿ��� �ޱ�
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

	//���� ���ڸ� �ް� �ʹٸ� output�� string�� �ƴ� int������!
	int output1;
	s2.str(string2);
	while (s2 >> output1) cout << "int��: " << output1 << '\n';
	s2.clear();
	//string2������ �Ǽ����� .326 �������� �޾Ƽ� 23 259�� ��µȴ�.
	
	//�̹����� string3���� ������ �ޱ�
	s2.str(string3);
	while (s2 >> output1) cout << "string 3�� int��: " << output1 << '\n';
	s2.clear();
	//����� 1�� 263�� ��µȴ�. avj�� ���ڿ��̹Ƿ�!

	//-----------����-------------
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
		cout << "��ȣ: " <<num << " �̸�: " << firstname << " ����: " << score << '\n';
		//�̷��� ������ ���� ���� �����Ͽ� Ȱ���ϸ� �ɵ� �ϴ�.
	}


	return 0;
}