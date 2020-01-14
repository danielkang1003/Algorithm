#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

//다시 풀어본 문제!
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
////priority queue에 대해서 깊게 알지 못해서 생긴 문제... 우선 순위 큐는 first의 크기를 먼저 비교하고 second의 크기를 비교한다.
////하지만 나의 틀린 풀이는 가장 작은 가중치로 계속 업데이트를 시켜주어야하는데, cost와 current idx를 반대로 넣어서 생긴 문제였다.
////(사실 pq를 완벽히 숙지하지 못한 상태여서 왜 틀린지 몰랐었다.)
////pq에 push를 할 때 가중치를 반드시 first에 넣고 second에 정점을 넣어주어야 한다.
////cost를 음수화 시키지 않고 하려면
////priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>를 사용하면 된다.
//
//
//int INF = 987654321;	//INF는 (간선 가중치 최대값) * (정점개수 - 1) 보다 큰 값을 사용해야한다.
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


//틀린 풀이
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