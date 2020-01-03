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
		/*
		���� ����
		ť�� ������ �ְ� �ٽ� ������ ������ ����ϴ� ����:
		�켱����ť�� ���� ū���� �������ǰ�(top)������  " - " �� ���ؼ�
		������ �ְ� �Ǹ� ���� ū ���� ���� ���� ���� �ǰ� ���� ���� ����
		���� ū ���� ������ " - " �� ���ؼ� ť�� �ְ� ������ 
		�ٽ� " - " �� ���ؼ� �����ϴ�. 
		�Ǵ� �̷��� ����������� 
		priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > qu;
		 �̷������� �����ϸ� ���� ���� ���� ���� ���� ���ĵ˴ϴ�.
		*/
		int cost = -pq.top().first;	//cost�� ���� �湮�� ���� dist���� ����
		int cur = pq.top().second;	//cur�� �湮�� ���� ��ȣ�� ����
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


/*
//���� Ž������ �ϴ� ����ε� n^2�� �ð� ���⵵�̱⿡ �ð� �ʰ��� ���� �� ����.
//������ ������ ������ �� ������ ġ�����̰� ��ȿ������ �˰���
//���� ������ ���ͽ�Ʈ�� ������ ���� ���Ǵ� �˰���
#include<iostream>

using namespace std;

int number = 6;
int INF = 1000000000; //�� 10���̸� int 21�￡ ������ ����

int a[6][6] = {
	{0, 2, 5, 1, INF,INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1,2,3,0,1, INF},
	{INF,INF, 1,1,0,2},
	{INF,INF, 5, INF, 2, 0}
};

bool check[6];	//�湮 ó���� �迭
int dist[6];	//�ִ� �Ÿ� ������ �迭

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