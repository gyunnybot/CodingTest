#include<iostream>
#include<vector>
#include<string> //to_string
using namespace std;

struct info {
	string number;
	int strike, ball;
};
vector<info> v;

string num;
int n, s, b, ret;

void recur(int idx, int cnt, string temp_num, vector<info>& v) {
	if (idx == n) {
		if (cnt == n) {
			ret++;
		}

		return;
	}

	int strike = 0;
	int ball = 0;

	if (temp_num[0] == v[idx].number[0]) strike++;
	if (temp_num[1] == v[idx].number[1]) strike++;
	if (temp_num[2] == v[idx].number[2]) strike++;

	if (temp_num[0] == v[idx].number[1] || temp_num[0] == v[idx].number[2]) ball++;
	if (temp_num[1] == v[idx].number[0] || temp_num[1] == v[idx].number[2]) ball++;
	if (temp_num[2] == v[idx].number[0] || temp_num[2] == v[idx].number[1]) ball++;

	if (v[idx].strike == strike && v[idx].ball == ball) {
		recur(idx + 1, cnt + 1, temp_num, v);
	}
	else {
		recur(idx + 1, cnt, temp_num, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num >> s >> b;
		v.push_back({ num,s,b });
	}

	for (int temp = 111; temp <= 999; temp++) {
		string temp_num = to_string(temp);

		if (temp_num[0] == '0' || temp_num[1] == '0' || temp_num[2] == '0') continue;
		if (temp_num[0] == temp_num[1] || temp_num[1] == temp_num[2] || temp_num[2] == temp_num[0]) continue;

		recur(0, 0, temp_num, v);
	}

	cout << ret;

	return 0;
}
