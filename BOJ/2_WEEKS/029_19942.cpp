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
	if (p >= mp && f >= mf && s >= ms && v >= mv) { //조건을 만족하는 경우
		if (ret > cost) { //ret은 가장 먼저 조건에 만족할 때 최소가 된다(단 한 번만 갱신)
			ret = cost;
			mini = temp;

			return; //이후 재귀는 최솟값이 아니거나 사전 순이 아니므로 return
		}
	}

	if (idx == n) { //모든 재료를 검사한 경우
		return; //더 이상 선택할 재료가 없으므로 return
	}

	//재료를 선택하는 경우(같은 비용의 집합이 하나 이상이면 사전 순으로 가장 빠른 것을 출력한다)
	temp.push_back(idx + 1);
	recur(idx + 1, p + ingre[idx].p, f + ingre[idx].f, s + ingre[idx].s, v + ingre[idx].v, cost + ingre[idx].cost);
	temp.pop_back();

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
