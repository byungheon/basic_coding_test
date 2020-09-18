#include <iostream>
#include <queue>

const int MAX = 1000;
int M, N;
int rotten[MAX][MAX] = { -1 };


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInBox(int x, int y)
{
	return (x >= 0 && x < M && y >= 0 && y < N);
}


int bfs()
{
	std::queue<std::pair<int, int>> q;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (rotten[i][j] == 1)
			{
				q.push(std::make_pair(i, j));
				rotten[i][j] = -1;
			}
		}
	}


	int n_time = 0;
	while(!q.empty())
	{
		int q_size = q.size();
		for (size_t i = 0; i < q_size; i++)
		{
			int now_x = q.front().first;
			int now_y = q.front().second;
			q.pop();


			for (size_t j = 0; j < 4; j++)
			{
				int next_x = now_x + dx[j];
				int next_y = now_y + dy[j];

				if (isInBox(next_x, next_y) && rotten[next_x][next_y] == 0)
				{
					rotten[next_x][next_y] = -1;
					q.push(std::make_pair(next_x, next_y));
				}
			}
		}

		if (q.size() != 0) {
			n_time++;
		}
	}

	return n_time;
}

int main()
{
	std::cin >> M >> N;

	int tomato = -1;
	int n_tomato = 0;
	int n_rotten = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cin >> tomato;
			rotten[j][i] = tomato;
			if (tomato == 1)
				n_rotten++;
		}
	}

	if (n_rotten == 0) {
		std::cout << -1;
		return 0;
	}

	int n_time = bfs();
	
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (rotten[i][j] == 0)
			{
				std::cout << "-1";
				return 0;
			}
		}
	}

	std::cout << n_time;

	return 0;
}