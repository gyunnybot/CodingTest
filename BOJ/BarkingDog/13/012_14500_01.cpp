#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[501][501], ret;
bool visited[501][501];
vector<int> v;

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 4) {
        ret = max(ret, sum);
        return;
    }

    v.push_back(a[y][x]);
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (!visited[ny][nx]) {
            dfs(ny, nx, cnt + 1, sum + a[ny][nx]);
        }
    }

    v.pop_back();
    visited[y][x] = false;
}

//combi_dfs는 ㅗ,ㅜ,ㅏ,ㅓ로 뻗어나갈 수 없기 때문에 배열의 값을 직접 더해 블록을 완성한다
void check_extra_shape(int y, int x) {
    if (y >= 1 && x >= 1 && x + 1 < m) {
        ret = max(ret, a[y][x] + a[y - 1][x] + a[y][x - 1] + a[y][x + 1]); //ㅗ
    }

    if (y + 1 < n && x >= 1 && x + 1 < m) {
        ret = max(ret, a[y][x] + a[y + 1][x] + a[y][x - 1] + a[y][x + 1]); //ㅜ
    }

    if (y >= 1 && y + 1 < n && x + 1 < m) {
        ret = max(ret, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x + 1]); //ㅏ
    }

    if (y >= 1 && y + 1 < n && x >= 1) {
        ret = max(ret, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x - 1]); //ㅓ
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, a[i][j]); //이어진 4개의 좌표를 선택하는 경우의 수를 조사 후 점수 계산
            check_extra_shape(i, j); //dfs로 만들 수 없는 모양을 조사 후 점수 계산
        }
    }

    cout << ret;

    return 0;
}
