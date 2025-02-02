#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, height;
stack<int> stk; //모든 빌딩은 일렬로 서 있고 오른쪽으로'만' 볼 수 있다? stack 활용
ll ret; //n의 범위가 8만이므로 ret은 최대 64억

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> height;

		while (!stk.empty() && stk.top() <= height) {
			stk.pop(); //본인을 오른쪽에서 볼 수 없는 빌딩들 제거
		}
		
		ret += stk.size(); //남아있는 본인을 내려다볼 수 있는 빌딩 수
		stk.push(height);
	}

	cout << ret; //본인을 내려다볼 수 있는 빌딩 수의 총합 = 본인이 내려다볼 수 있는 빌딩 수의 총합

	return 0;
}
