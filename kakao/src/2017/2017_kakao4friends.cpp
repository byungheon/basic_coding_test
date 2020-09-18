#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

char blank = '0';
char table[31][31] = {blank};
bool check[31][31] = { false };

bool check4Friends(int i, int j) {
	if (table[i][j] == blank ||  // blank
		table[i][j] != table[i][j + 1] ||
		table[i][j] != table[i + 1][j] ||
		table[i][j] != table[i + 1][j + 1])
		return false;

	return true;
}

int subSolution(int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check4Friends(i, j)) {
				check[i][j] = true;
				check[i+1][j] = true;
				check[i][j+1] = true;
				check[i+1][j+1] = true;
			}
		}
	}

	// adjust table & count solution
	int answer = 0;
	std::vector<int> alive(m);
	for (int j = 0; j < n; j++)
	{
		int cnt_alive = 0;
		int cnt_blank = 0;
		for (int i = 0; i < m; i++)
		{
			if (table[i][j] == blank) {
				cnt_blank++;
			} else if (check[i][j] == false)
			{
				alive[cnt_alive] = i;
				cnt_alive++;
			}
		}
		answer += (m - cnt_alive - cnt_blank);
		
		// shift blocks to bottom
		for (int i = 1;  i <= cnt_alive;  i++)
		{
			table[m - i][j] = table[alive[cnt_alive - i]][j];
		}
		// set remained as blank
		for (int i = cnt_blank; i < m - cnt_alive; i++)
		{
			table[i][j] = blank;
		}
	}

	return answer;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		memcpy(table[i], board[i].c_str(), sizeof(char) * n);
	}

	while (1) {
		int cnt = subSolution(m, n);
		answer += cnt;
		if (cnt == 0)
			break;

		memset(check, 0, sizeof(check));
	}

	return answer;
}

int main() {
	int m = 4;
	int n = 5;
	vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};

	std::cout << solution(m, n, board) << std::endl;

	return 0;
}