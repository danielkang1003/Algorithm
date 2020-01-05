#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, a, b, c;
int computer[1001];

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = dist;
	}
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int Find(int x) {
	if (x == computer[x]) return x;
	else return computer[x] = Find(computer[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) computer[y] = x;
	else computer[x] = y;
}

int FindParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 1;
	else return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) computer[i] = i;
	vector<Edge> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}
	sort(v.begin(), v.end());

	int minimumcost = 0;
	for (int i = 0; i < m; i++) {
		if (FindParent(v[i].node[0], v[i].node[1]) == 0) {
			//����Ŭ ����. �����ְ� �ּ� ��� ���ϱ�
			minimumcost += v[i].distance;
			Union(v[i].node[0], v[i].node[1]);
			//cout << "���� " << v[i].node[0] << "��(��) " << v[i].node[1] << "��(��) ��Ĩ�ϴ�.\n";
		}
		else {
			//cout << "���� " << v[i].node[0] << "��(��) " << v[i].node[1] << "�� ����Ŭ�� �߻��߽��ϴ�.\n";
			continue;
		}
	}
	cout << minimumcost;
	return 0;
}