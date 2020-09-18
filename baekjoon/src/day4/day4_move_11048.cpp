#include <iostream>

const int MAX = 1001;

int dx[3] = {-1, 0, -1};
int dy[3] = { 0, -1, -1 };

int N, M;

int candy[MAX][MAX] = {0};
int dp[MAX][MAX] = { 0 };

int max_candy = 0;

bool isInBox(int x, int y) {
	return (x > 0 && x <= N && y >0 && y<= M);
}

int main()
{

	std::cin >> N >> M;

	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			std::cin >> candy[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int max = 0;
			for (int k = 0; k < 3; k++)
			{
				int new_x = i + dx[k];
				int new_y = j + dy[k];
				if (isInBox(new_x, new_y)) {
					max = max < dp[new_x][new_y] ? dp[new_x][new_y] : max;
				}
			}

			dp[i][j] = max + candy[i][j];
		}
	}

	std::cout << dp[N][M];

	return 0;
}