#include<iostream>
#include<queue> //priority_queue
using namespace std;

int n, temp;
priority_queue<int, vector<int>, less<int>> pq; //가장 큰 값을 pq.top()으로 = 최대 힙 = less(우선순위 큐는 반대)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (temp == 0) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            pq.push(temp);
        }
    }

    return 0;
}
