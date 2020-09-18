#include <iostream>
#include <memory.h>

char RGB[100][100];
bool check[100][100] = {false};

int N = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


bool isInBox(int x, int y)
{
	return (x >= 0 && x < N&& y >= 0 && y < N);
}


void dfs(int x, int y, char rgb)
{
	check[x][y] = true;
	for (size_t i = 0; i < 4; i++)
	{
		int xn = x + dx[i];
		int yn = y + dy[i];
		if (isInBox(xn, yn) && check[xn][yn] == false && rgb == RGB[xn][yn])
			dfs(xn, yn, rgb);
	}
}

int main()
{
	std::cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cin >> RGB[i][j];
		}
	}


	int n_rgb = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (check[i][j] == false) {
				n_rgb++;
				dfs(i, j, RGB[i][j]);
			}
		}
	}

	memset(check, 0, sizeof(check));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (RGB[i][j] == 'R')
				RGB[i][j] = 'G';
		}
	}

	int n_rb = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (check[i][j] == false) {
				n_rb++;
				dfs(i, j, RGB[i][j]);
			}
		}
	}

	std::cout << n_rgb << " " << n_rb;

	return 0;
}