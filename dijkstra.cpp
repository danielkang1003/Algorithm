#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*다익스트라 알고리즘 (V: 노드 수, E: 엣지 수)
	1) 배열을 이용하는 경우 (Naive하게 접근해서 v^2)
		시간 복잡도: O(V^2)
	2) 힙(우선순위 큐)를 이용하는 경우
		시간 복잡도: O(ElogV)
		훨씬 빠르다.
*/

const int MAX_V = 100;
const int INF = 987654321;
int v;
vector<vector<pair<int, int>>> adj;
vector<int> dijkstra(int x) {
	vector<int> dist(v, INF);	//모든 점을 무한대로 설정
	dist[x] = 0;	//첫 정점은 0으로 초기화
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		//거리가 작은 정점부터 꺼내지도록(cost가 최소인 점을 선택)하는 이유: 
		//최단거리가 되는 가능성이 있는 점들을 먼저 탐색하고 d[v]를 기록하기 위함
		/*
		보충 설명
		큐에 음수를 넣고 다시 꺼낼때 음수를 사용하는 이유:
		우선순위큐는 가장 큰값이 제일위의값(top)임으로  " - " 를 곱해서
		음수로 넣게 되면 가장 큰 값이 가장 작은 값이 되고 가장 작은 값이
		가장 큰 값이 됨으로 " - " 를 곱해서 큐에 넣고 꺼낼때 
		다시 " - " 를 곱해서 꺼냅니다. 
		또는 이렇게 하지않을경우 
		priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > qu;
		 이런식으로 선언하면 가장 작은 값이 가장 위로 정렬됩니다.
		*/
		int cost = -pq.top().first;	//cost는 다음 방문할 점의 dist값을 뜻함
		int cur = pq.top().second;	//cur은 방문할 점의 번호를 뜻함
		pq.pop();

		//지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것 무시
		if (dist[cur] < cost) continue;

		//이후 그래프 순회랑 같음
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nextCost = adj[cur][i].first;
			int nextDist = adj[cur][i].second + cost;

			//더 짧은 경로를 발견하면 dist[] 갱신 후 우선순위 큐에 넣기
			if (dist[nextCost] > nextDist) {
				dist[nextCost] = nextDist;
				pq.push({ -nextDist, nextCost });
				//가중치가 붙은 그래프이므로 다음점과 지금까지 누적 cost queue에 넣기
			}
		}
	}
	return dist;
}

//정점의 수가 적거나 간선의 수가 매우 많을때 우선순위 큐 사용x
//대신 각 정점을 방문했는지 여부를 나타내는 배열 visited 사용하여 구현
bool visited[100];

int min(int a, int b) {
	return a > b ? b : a;
}

vector<int> dijkstra2(int start) {
	vector<int> dist(v, INF);
	dist[start] = 0;
	visited[start] = 1;
	while (1) {
		//가장 가깝고 방문하지 않은 정점 찾기
		int closest = INF;
		int cur;
		for (int i = 0; i < v; i++) {
			if (dist[i] < closest && visited[i] == 0) {
				cur = i;
				closest = dist[i];
			}
		}
		if (closest == INF) break;
		//가장 가까운 정점 방문
		visited[cur] = 1;
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nextCost = adj[cur][i].first;
			int nextDist = adj[cur][i].second;
			if (visited[nextCost] == 0) {
				dist[nextCost] = min(dist[nextCost], dist[cur] + nextDist);
			}
		}
	}
	return dist;
}

int main() {
	v = 7;
	adj = vector<vector<pair<int, int>>>(v, vector<pair<int, int>>());
	adj[0].push_back({ 1,5 });
	adj[0].push_back({ 2,1 });
	adj[1].push_back({ 0,5 });
	adj[1].push_back({ 3,1 });
	adj[1].push_back({ 6,3 });
	adj[1].push_back({ 5,3 });
	adj[2].push_back({ 0,1 });
	adj[2].push_back({ 3,2 });
	adj[3].push_back({ 2,2 });
	adj[3].push_back({ 1,1 });
	adj[3].push_back({ 4,5 });
	adj[3].push_back({ 5,3 });
	adj[4].push_back({ 3,5 });
	adj[5].push_back({ 1,3 });
	adj[5].push_back({ 6,2 });
	adj[5].push_back({ 3,3 });
	adj[6].push_back({ 1,3 });
	adj[6].push_back({ 5,2 });


	vector<int> answer = dijkstra(0);	//가장 작은 정점에서 시작한다.
	//dist에 저장된 각 정점들의 최단 거리 출력
	int ansSize = answer.size();
	for (int i = 0; i < ansSize; i++) {
		cout << "[" << i << "]";
	}
	cout << '\n';
	for (int i = 0; i < ansSize; i++) {
		cout << " " << answer[i] << ' ';
	}
	cout << '\n';


	//다익스트라 2
	vector<int> answer1 = dijkstra2(0);
	int ansSize1 = answer1.size();
	for (int i = 0; i < ansSize1; i++) {
		cout << "[" << i << "]";
	}
	cout << '\n';
	for (int i = 0; i < ansSize1; i++) {
		cout << " " << answer1[i] << ' ';
	}
	cout << '\n';
}


/*
//선형 탐색으로 하는 방식인데 n^2의 시간 복잡도이기에 시간 초과가 많이 뜰 것임.
//정점은 많은데 간선은 얼마 없으면 치명적이고 비효율적인 알고리즘
//가끔 빠르게 다익스트라 구현을 위해 사용되는 알고리즘
#include<iostream>

using namespace std;

int number = 6;
int INF = 1000000000; //약 10억이면 int 21억에 가깝게 가능

int a[6][6] = {
	{0, 2, 5, 1, INF,INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1,2,3,0,1, INF},
	{INF,INF, 1,1,0,2},
	{INF,INF, 5, INF, 2, 0}
};

bool check[6];	//방문 처리할 배열
int dist[6];	//최단 거리 저장할 배열

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (dist[i] < min && check[i] == 0) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		dist[i] = a[start][i];
	}
	check[start] = 1;
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		check[current] = 1;
		for (int j = 0; j < 6; j++) {
			if (check[j] == 0) {
				if (dist[current] + a[current][j] < dist[j]) {
					dist[j] = dist[current] + a[current][j];
				}
			}
		}
	}
}

int main() {
	dijkstra(0);
	for (int i = 0; i < number; i++) cout << dist[i] << ' ';

	return 0;
}

*/