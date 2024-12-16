#include<iostream>
#include<vector>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int t, n, m, fire_visited[1001][1001], s_visited[1001][1001], ret;
char a[1001][1001];
string s;
pair<int, int> sPos;
vector<pair<int, int>> firePos;

void fire_bfs() {
    for (pair<int, int> fire : firePos) {
        fire_visited[fire.first][fire.second] = 1;
    }

    queue<pair<int, int>> q;
    for (pair<int, int> fire : firePos) {
        q.push(fire);
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (a[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] != INT_MAX) continue; //좌표에 이미 불이 붙었다면

            if (fire_visited[ny][nx] == INT_MAX) {
                fire_visited[ny][nx] = fire_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void s_bfs() {
    s_visited[sPos.first][sPos.second] = 1;

    queue<pair<int, int>> q;
    q.push({ sPos.first, sPos.second });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (cur.first == 0 || cur.first == m - 1 || cur.second == 0 || cur.second == n - 1) {
            ret = s_visited[cur.first][cur.second];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (a[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] <= s_visited[cur.first][cur.second] + 1) continue; //좌표에 이미 불이 붙었다면

            if (!s_visited[ny][nx]) {
                s_visited[ny][nx] = s_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INT_MAX);
        fill(&s_visited[0][0], &s_visited[0][0] + 1001 * 1001, 0);

        firePos.clear();

        ret = 0;

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> s;

            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];

                if (a[i][j] == '@') {
                    sPos = { i,j };
                }
                else if (a[i][j] == '*') {
                    firePos.push_back({ i,j });
                }
            }
        }

        fire_bfs();
        s_bfs();

        if (ret) {
            cout << ret << '\n';
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}