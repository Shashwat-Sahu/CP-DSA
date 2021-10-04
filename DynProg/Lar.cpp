#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<string>

using namespace std;

enum direction {UP,DIG,LEFT,NONE};

void findSubSeq(vector<vector<int>>& vect, vector<vector<direction>>& dir, string a, string b, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[j] == a[i]) {
				if (i > 0 && j > 0) {
					vect[i][j] = vect[i - 1][j - 1] + 1;
				}
				else vect[i][j] = 1;
				dir[i][j] = DIG;
			}
			else {
				if (i > 0 && j > 0) {
					if (vect[i][j - 1] > vect[i - 1][j]) {
						vect[i][j] = vect[i][j - 1];
						dir[i][j] = LEFT;
					}
					else {
						vect[i][j] = vect[i - 1][j];
						dir[i][j] = UP;
					}
				}
				else if (i > 0) {
					vect[i][j] = vect[i - 1][j];
					dir[i][j] = UP;
				}
				else if (j > 0) {
					dir[i][j] = LEFT;
					vect[i][j] = vect[i][j - 1];
				}
			}
		}
	}
}

int main(){
	string a = "HJAFHDJKVBNVAFDAFDHJKAHJFHDJGFDJG", b = "AJKDSJFKLDSJFLKSDJFDLKSJLSJFDKJK";
	int n = a.size(), m = b.size();
	vector<vector<int>> vect(n);
	vector<vector<direction>> dir(n);

	for (auto& i : vect) {
		vector<int> temp(m, 0);
		i = temp;
	}
	for (auto& i : dir) {
		vector<direction> dTemp(m, NONE);
		i = dTemp;
	}
	findSubSeq(vect, dir, a, b, n, m);

	string ans = "";
	int i = n - 1, j = m - 1;

	while (i >= 0 && j >= 0 && dir[i][j] != NONE) {
		
		if (dir[i][j] == UP) i--;
		else if (dir[i][j] == LEFT) j--;
		else {
			ans = b[j] + ans;
			i--; j--;
		}
		
	}
	cout << ans << endl;

	return 0;
}