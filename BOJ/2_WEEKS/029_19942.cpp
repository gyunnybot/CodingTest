#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

struct info {
	int p, f, s, v, cost;
};
vector<info> ingre;

int n, mp, mf, ms, mv;
int p, f, s, v, cost;
int ret = INT_MAX;
vector<int> temp, mini;

void recur(int idx, int p, int f, int s, int v, int cost) {
	if (p >= mp && f >= mf && s >= ms && v >= mv) {
		if (ret > cost) {
			ret = cost;
			mini = temp;
		}
	}

	if (idx == n) return;

	//재료를 선택하는 경우. 같은 비용의 집합이 하나 이상이면 사전 순으로 가장 빠른 것을 출력한다
	temp.push_back(idx + 1); //조합 선택
	recur(idx + 1, p + ingre[idx].p, f + ingre[idx].f, s + ingre[idx].s, v + ingre[idx].v, cost + ingre[idx].cost);
	temp.pop_back(); //조합 원상 복구

	//재료를 선택하지 않는 경우
	recur(idx + 1, p, f, s, v, cost);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> p >> f >> s >> v >> cost;
		ingre.push_back({ p,f,s,v,cost });
	}

	recur(0, 0, 0, 0, 0, 0);

	if (ret == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ret << '\n';

		for (int i : mini) {
			cout << i << ' ';
		}
	}

	return 0;
}
