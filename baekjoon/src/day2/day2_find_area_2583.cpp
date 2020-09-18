#include <iostream>
#include <vector>
#include <algorithm>

bool filled[100][100] = {false};

int M = 0, N = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isInBox(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void dfs(int x, int y, int& cnt) {
	filled[x][y] = true;
	cnt++;

	for (size_t i = 0; i < 4; i++)
	{
		int xn = x + dx[i];
		int yn = y + dy[i];
		if (isInBox(xn, yn) && filled[xn][yn] == false)
			dfs(xn, yn, cnt);
	}
}

int main()
{
	int K = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2= 0;
	std::cin >> M >> N >> K;

	for (size_t i = 0; i < K; i++)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;

		for (size_t ix = x1; ix < x2; ix++)
		{
			for (size_t iy = y1; iy < y2; iy++)
			{
				filled[ix][iy] = true;
			}
		}
	}

	int area;
	std::vector<int> areas;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (filled[i][j] == false) {
				area = 0;
				dfs(i, j, area);
				areas.push_back(area);
			}
		}
	}

	std::sort(areas.begin(), areas.end());
	std::cout << areas.size() << std::endl;
	for (size_t i = 0; i < areas.size(); i++)
	{
		std::cout << areas[i] << " ";
	}
	return 0;
}