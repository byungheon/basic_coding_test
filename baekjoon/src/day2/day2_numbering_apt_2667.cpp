#include <iostream>
#include <vector>
#include <algorithm>

bool apt[25][25] = { false };

int N = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isInBox(int x, int y)
{
	return (x >= 0 && x < N&& y >= 0 && y < N);
}


void dfs(int x, int y, int& cnt)
{
	apt[x][y] = false;
	cnt++;
	for (size_t i = 0; i < 4; i++)
	{
		int xn = x + dx[i];
		int yn = y + dy[i];
		if (isInBox(xn, yn) && apt[xn][yn] == true)
			dfs(xn, yn, cnt);
	}
}

int main()
{
	std::cin >> N;
	char a;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cin >> a;
			if (a == '1')
				apt[i][j] = true;
		}
	}

	int area = 0;
	std::vector<int> areas;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (apt[i][j] == true)
			{
				area = 0;
				dfs(i, j, area);
				areas.push_back(area);
			}
		}
	}

	std::sort(areas.begin(), areas.end());

	std::cout << areas.size() << std::endl;
	for (const auto _area: areas)
	{
		std::cout << _area << std::endl;
	}

	return 0;
}