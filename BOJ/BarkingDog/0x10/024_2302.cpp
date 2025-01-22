#include<iostream>
using namespace std;

int n, m, temp, a[41], dp[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	dp[0] = 1; //문제 오류인 듯?
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int ret = 1;
	int start = 0;

	for (int i = 0; i < m; i++) {
		int ed = a[i];

		ret *= dp[ed - start - 1];
		start = ed;
	}

	ret *= dp[n - start];

	cout << ret;

	return 0;
}