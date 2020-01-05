#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V, E, a, b, c;
int parent[10001];

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator<  (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) {
		parent[y] = x;
	}
	else parent[x] = y;
}

int FindParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E;
	vector<Edge> v;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}
	sort(v.begin(), v.end());

	//�θ� ��� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	int answer = 0;
	for (int i = 0; i < E; i++) {
		//����Ŭ ����
		if (FindParent(v[i].node[0], v[i].node[1]) == 1) {
			//cout << "���� " << v[i].node[0] << "��(��) " << v[i].node[1] << "�� ����Ŭ �߻�!!!\n";
			continue;
		}
		else {
			//����Ŭ�� ���� ��
			//cout << "���� " << v[i].node[0] << "��(��) " << v[i].node[1] << "�� �����" << v[i].distance << "�Դϴ�\n";
			answer += v[i].distance;
			Union(v[i].node[0], v[i].node[1]);
		}
	}
	cout << answer;

	return 0;
}