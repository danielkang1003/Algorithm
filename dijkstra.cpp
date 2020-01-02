#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*���ͽ�Ʈ�� �˰��� (V: ��� ��, E: ���� ��)
	1) �迭�� �̿��ϴ� ��� (Naive�ϰ� �����ؼ� v^2)
		�ð� ���⵵: O(V^2)
	2) ��(�켱���� ť)�� �̿��ϴ� ���
		�ð� ���⵵: O(ElogV)
		�ξ� ������.
*/

const int MAX_V = 100;
const int INF = 987654321;
int v;
vector<vector<pair<int, int>>> adj;
vector<int> dijkstra(int x) {
	vector<int> dist(v, INF);	//��� ���� ���Ѵ�� ����
	dist[x] = 0;	//ù ������ 0���� �ʱ�ȭ
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		//�Ÿ��� ���� �������� ����������(cost�� �ּ��� ���� ����)�ϴ� ����: 
		//�ִܰŸ��� �Ǵ� ���ɼ��� �ִ� ������ ���� Ž���ϰ� d[v]�� ����ϱ� ����
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		//���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� �� ����
		if (dist[cur] < cost) continue;

		//���� �׷��� ��ȸ�� ����
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nextCost = adj[cur][i].first;
			int nextDist = adj[cur][i].second + cost;

			//�� ª�� ��θ� �߰��ϸ� dist[] ���� �� �켱���� ť�� �ֱ�
			if (dist[nextCost] > nextDist) {
				dist[nextCost] = nextDist;
				pq.push({ -nextDist, nextCost });
				//����ġ�� ���� �׷����̹Ƿ� �������� ���ݱ��� ���� cost queue�� �ֱ�
			}
		}
	}
	return dist;
}

//������ ���� ���ų� ������ ���� �ſ� ������ �켱���� ť ���x
//��� �� ������ �湮�ߴ��� ���θ� ��Ÿ���� �迭 visited ����Ͽ� ����
bool visited[100];

int min(int a, int b) {
	return a > b ? b : a;
}

vector<int> dijkstra2(int start) {
	vector<int> dist(v, INF);
	dist[start] = 0;
	visited[start] = 1;
	while (1) {
		//���� ������ �湮���� ���� ���� ã��
		int closest = INF;
		int cur;
		for (int i = 0; i < v; i++) {
			if (dist[i] < closest && visited[i] == 0) {
				cur = i;
				closest = dist[i];
			}
		}
		if (closest == INF) break;
		//���� ����� ���� �湮
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


	vector<int> answer = dijkstra(0);	//���� ���� �������� �����Ѵ�.
	//dist�� ����� �� �������� �ִ� �Ÿ� ���
	int ansSize = answer.size();
	for (int i = 0; i < ansSize; i++) {
		cout << "[" << i << "]";
	}
	cout << '\n';
	for (int i = 0; i < ansSize; i++) {
		cout << " " << answer[i] << ' ';
	}
	cout << '\n';


	//���ͽ�Ʈ�� 2
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
