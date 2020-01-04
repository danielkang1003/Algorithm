#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m, n, h;
int answer;
int box[100][100][100];	//���̰� �߰��� �丶�� �ڽ�
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };	//���̰� �ִ� 3���� �迭�̹Ƿ� height�� ������ dh�� ����
bool check;
queue<pair<pair<int, int>, int>> q;

//�� �;����� Ȯ��
bool check_mature() {
	for (int height = 0; height < h; height++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j][height] == 0) return false;
			}
		}
	}
	return true;
}

void bfs() {
	while (!q.empty()) {
		int size = q.size();	//�̸� ��Ƴ��� ť ������ ��ŭ bfs�� ���� ����
		for (int qs = 0; qs < size; qs++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int hei = q.front().second;
			q.pop();
			for (int dir = 0; dir < 6; dir++) {	//����(�� �Ʒ�)���� ����
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nh = hei + dh[dir];
				if (nx < 0 || ny < 0 || nh < 0 || nx >= n || ny >= m || nh >= h)
					continue;
				if (box[nx][ny][nh] == 0) {	//0�̶��
					box[nx][ny][nh] = 1;	//1�� �ٲپ��ְ�
					q.push({ {nx,ny}, nh });	//�ٽ� Ǫ��
				}
			}
			//bfs�� �� ������
			//���࿡ -1 ���� �� ĭ�� �ְ� 0�� �����־ �ٲ��� ���ϴ�
			//��Ȳ�� Ȯ���ϱ� ���� ��ü�� �����༭ 0�� �߰��� �ȴٸ�
			//check_mature (�ڽ����� �丶�䰡 �;����� Ȯ���ϴ� �Լ�)��
			//false��. -1 ����ϰ� bfs ����
			if (q.empty() && check_mature() == false) {
				cout << -1 << '\n';
				return;
			}
			//��� ���� ����. ť�� ��������ϱ� �� ���Ҵٴ� �̾߱�
			else if (q.empty() && check_mature() == true) {
				cout << answer << '\n';
				return;
			}
		}
		//ť�� �Ⱥ���ְ� bfs�� �ѹ� ���Ҵٸ� ��¥ �Ϸ�++
		answer++;
	}

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> m >> n >> h;
	check = 1;	//�丶�䰡 �̸� �� �; �������� Ȯ���� ����
	for (int height = 0; height < h; height++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[i][j][height];
				if (box[i][j][height] == 0) check = 0;	//������ �丶�䰡 �ִٸ� false�� ����
				if (box[i][j][height] == 1) {
					q.push({ {i,j}, height });	// �̸� x,y,z�� ����ش�.
				}
			}
		}
	}
	//bfs ������ ���� �̹� �� ���� ���·� �־����� 0 ����ϱ� ����
	//������ ���� �Է����� 0�� �ѹ��̶� ���Դٸ� ������ check = 1�̴� ���� 0���� ����Ǿ�����.
	//0�� �Է����� �ȵ��Դٸ� ��� 1�� ���̹Ƿ� 1�̶��(��� ��������) 0 ����ϰ� ����
	if (check == 1) {
		cout << 0 << '\n';
		return 0;
	}

	//�� ������ �ƴ϶�� Ȯ���ϱ� ���� bfs�� �����ش�.
	bfs();

	return 0;
}