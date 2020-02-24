#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;
	map<string, int> pokemon;
	vector<string> pokemonIdx(n + 1);

	for (int i = 1; i <= n; i++) {
		string poke;
		cin >> poke;
		pokemonIdx[i] = poke;
		pokemon[poke] = i;
	}
	while (m--) {
		string cmd;
		cin >> cmd;
		if (atoi(cmd.c_str()) != 0) {
			cout << pokemonIdx[atoi(cmd.c_str())] << '\n';
		}
		else cout << pokemon[cmd] << '\n';
	}
	return 0;
}