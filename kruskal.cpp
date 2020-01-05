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
	int node[2];	//서로 연결된 두개의 정점
	int distance;	//비용

	//생성자로 초기화
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	//정렬기준은 거리가 작은게 먼저 출력되도록
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
		//사이클이 발생하지 않으면(return 값이 0일 때) 실행
		if (FindParent(v[i].node[0], v[i].node[1]) == 0) {
			cout << "정점 " << v[i].node[0] << "과(와) " << v[i].node[1] << "을(를) 합치자! 거리는 " << v[i].distance << "이기 때문에!\n";
			sum += v[i].distance;
			Union(v[i].node[0], v[i].node[1]);
		}
		else {
			//사이클 발생
			cout << "정점 " << v[i].node[0] << "과(와) " << v[i].node[1] << "은(는) 사이클 발생!!" << '\n';
		}
	}
	cout << "최소 비용은" << sum;
	return 0;
}