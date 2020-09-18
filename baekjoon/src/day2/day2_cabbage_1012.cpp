#include <iostream>
#include <vector>
#include <memory.h>

int cabbage[50][50];
int width = 0, height = 0;
int n_cabbage = 0;

int x_delta[4] = {-1, 0, 1, 0};
int y_delta[4] = { 0, -1, 0, 1 };

bool isInBox(int x, int y)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

void dfs(int x, int y)
{
	cabbage[x][y] = 0;
	
	for (size_t i = 0; i < 4; i++)
	{
		int next_x = x + x_delta[i];
		int next_y = y + y_delta[i];

		if (isInBox(next_x, next_y) && cabbage[next_x][next_y] == 1)
			dfs(next_x, next_y);
	}
}

int printCabbage()
{
	int x, y;
	std::cin >> width >> height >> n_cabbage;

	memset(cabbage, 0, sizeof(cabbage));

	std::vector<std::vector<int>> xy_cabbage(n_cabbage, std::vector<int>(2));

	for (size_t i = 0; i < n_cabbage; i++)
	{
		std::cin >> x >> y;
		cabbage[x][y] = 1;
		xy_cabbage[i][0] = x;
		xy_cabbage[i][1] = y;
	}

	int n_answer = 0;
	for (size_t i = 0; i < n_cabbage; i++)
	{
		if (cabbage[xy_cabbage[i][0]][xy_cabbage[i][1]] != 0) {
			n_answer++;
			dfs(xy_cabbage[i][0], xy_cabbage[i][1]);
		}
	}

	return n_answer;
}

int main()
{
	int n_test;

	std::cin >> n_test;

	std::vector<int> answer(n_test);
	for (size_t i = 0; i < n_test; i++)
	{
		answer[i] = printCabbage();
	}

	for (size_t i = 0; i < n_test; i++)
	{
		std::cout << answer[i] << std::endl;
	}

	return 0;
}