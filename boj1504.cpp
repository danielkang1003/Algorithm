#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, e, a, b, c, must_pass1, must_pass2;
int INF = 987654321;
vector<pair<int, int>> adj[801];
int check[801];	//이 배열로 경로를 파악함
vector<int> dijkstra(int start, int v) {
	vector<int> dist(v + 1, INF);
	priority_queue<pair<int, int>> pq;
	//최소힙으로 하려면
	//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });	//가중치, 시작정점
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i].first;
			int nxtCost = adj[cur][i].second + cost;
			if (dist[nxt] > nxtCost) {
				dist[nxt] = nxtCost;
				pq.push({ -nxtCost, nxt });
				check[nxt] = cur;	//경로 또한 업데이트
			}
		}
	}
	return dist;
}

int main() {
	cin >> n >> e;
	n++;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		//양방향
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	cin >> must_pass1 >> must_pass2;
	vector<int> answer = dijkstra(1, n);
	vector<int> try1 = dijkstra(must_pass1, n);
	vector<int> try2 = dijkstra(must_pass2, n);

	//어디를 먼저 거쳐서 가는 게 최단 거리인지 확인 하기 위해 min으로 비교
	int comp = min(answer[must_pass1] + try1[must_pass2] + try2[n - 1], answer[must_pass2] + try2[must_pass1] + try1[n - 1]);
	if (comp >= INF || comp < 0) cout << "-1\n";
	else cout << comp << '\n';
	return 0;
}