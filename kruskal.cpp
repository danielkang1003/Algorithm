#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int V = 7;
int E = 11;
//int* parent = new int[V + 1];
int parent[V + 1];

class Edge {
public:
	int node[2];	//���� ����� �ΰ��� ����
	int distance;	//���

	//�����ڷ� �ʱ�ȭ
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	//���ı����� �Ÿ��� ������ ���� ��µǵ���
	bool operator< (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int Find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else {
		parent[x] = y;
	}
}

int FindParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 1;
	else return 0;
}


int main() {
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(4, 2, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(5, 7, 73));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 3, 20));
	v.push_back(Edge(6, 3, 37));

	sort(v.begin(), v.end());


	for (int i = 1; i <= V; i++) parent[i] = i;

	int sum = 0;
	for (int i = 0; i < E; i++) {
		//����Ŭ�� �߻����� ������(return ���� 0�� ��) ����
		if (FindParent(v[i].node[0], v[i].node[1]) == 0) {
			cout << "���� " << v[i].node[0] << "��(��) " << v[i].node[1] << "��(��) ��ġ��! �Ÿ��� " << v[i].distance << "�̱� ������!\n";
			sum += v[i].distance;
			Union(v[i].node[0], v[i].node[1]);
		}
		else {
			//����Ŭ �߻�
			cout << "���� " << v[i].node[0] << "��(��) " << v[i].node[1] << "��(��) ����Ŭ �߻�!!" << '\n';
		}
	}
	cout << "�ּ� �����" << sum;
	return 0;
}