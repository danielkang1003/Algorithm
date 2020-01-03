#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m, bus_start, bus_end, weight, start, destination;
int INF = 987654321;
vector<pair<int, int>> adj[1001];	//그래프 인접 리스트. (연결 정점 번호, 가중치)

vector<int> dijkstra(int start) {
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int next = adj[cur][i].first;
			int nextDist = adj[cur][i].second + cost;
			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push({ next, -nextDist });
			}
		}
	}
	return dist;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> bus_start >> bus_end >> weight;
		adj[bus_start].push_back({ bus_end, weight });
	}

	cin >> start >> destination;

	vector<int> answer = dijkstra(start);
	cout << answer[destination];

	return 0;
}