#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

//�ٽ� Ǯ� ����!
using namespace std;

int V, E, K, u, v, w;
int dist[20001];
vector<vector<pair<int, int>>> adj;
int main() {
	cin >> V >> E >> K;
	adj.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}

	memset(dist, -1, sizeof(dist));
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,K });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] != -1) continue;
		dist[cur] = cost;
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i].first;
			int nxtCost = adj[cur][i].second + cost;
			if (dist[nxt] != -1) continue;
			pq.push({ -nxtCost, nxt });
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}


//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
////priority queue�� ���ؼ� ��� ���� ���ؼ� ���� ����... �켱 ���� ť�� first�� ũ�⸦ ���� ���ϰ� second�� ũ�⸦ ���Ѵ�.
////������ ���� Ʋ�� Ǯ�̴� ���� ���� ����ġ�� ��� ������Ʈ�� �����־���ϴµ�, cost�� current idx�� �ݴ�� �־ ���� ��������.
////(��� pq�� �Ϻ��� �������� ���� ���¿��� �� Ʋ���� ��������.)
////pq�� push�� �� �� ����ġ�� �ݵ�� first�� �ְ� second�� ������ �־��־�� �Ѵ�.
////cost�� ����ȭ ��Ű�� �ʰ� �Ϸ���
////priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>�� ����ϸ� �ȴ�.
//
//
//int INF = 987654321;	//INF�� (���� ����ġ �ִ밪) * (�������� - 1) ���� ū ���� ����ؾ��Ѵ�.
//int v, e, stationNum, bus_start, bus_end, bus_cost, start, destination;
//vector<pair<int, int>> adj[20001];
//vector<int> dist[20001];
//
//vector<int> dijkstra() {
//	vector<int> dist(v + 1, INF);
//	dist[stationNum] = 0;
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0, stationNum });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//
//		if (dist[cur] < cost) continue;
//
//		int size = adj[cur].size();
//		for (int i = 0; i < size; i++) {
//			int next = adj[cur][i].first;
//			int nextCost = cost + adj[cur][i].second;
//			if (dist[next] > nextCost) {
//				dist[next] = nextCost;
//				pq.push({ -nextCost, next });
//			}
//		}
//	}
//	return dist;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> v >> e >> stationNum;
//	for (int i = 0; i < e; i++) {
//		cin >> bus_start >> bus_end >> bus_cost;
//		adj[bus_start].push_back({ bus_end, bus_cost });
//	}
//
//	vector<int> answer = dijkstra();
//	for (int i = 1; i <= v; i++) {
//		if (answer[i] == INF) cout << "INF\n";
//		else cout << answer[i] << '\n';
//	}
//	return 0;
//}


//Ʋ�� Ǯ��
/*
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int INF = 987654321;
int v, e, k, u1, u2, w;
vector<pair<int, int>> adj[20001];

vector<int> dijkstra() {
	vector<int> dist(v, INF);
	dist[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ k, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int next = adj[cur][i].first;
			int nextCost = cost + adj[cur][i].second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, -nextCost });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> v >> e >> k;
	v++;
	for (int i = 1; i <= e; i++) {
		cin >> u1 >> u2 >> w;
		adj[u1].push_back({ u2, w });
	}

	vector<int> answer = dijkstra();

	for (int i = 1; i < v; i++) {
		if (answer[i] == INF) cout << "INF\n";
		else cout << answer[i] << '\n';
	}
	return 0;
}
*/