#include <iostream>
#include <vector>
int main()
{
	int n = 0;
	std::cin >> n;

	int n_row = 0, n_col = 0;
	int empty_cnt = 0;
	int cur_block = -1;

	std::vector<std::vector<int>> map(n, std::vector<int>(n, 0)); // height x width
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			char in;
			std::cin >> in;
			if (in == '.')
				map[i][j] = 1;
			else if (in == 'X')
				map[i][j] = 0;
			else
				break;
		}

		empty_cnt = 0;
		cur_block = -1;
		for (size_t j = 0; j < n; j++)
		{
			cur_block = map[i][j];
			if (cur_block == 0) {
				if (empty_cnt >= 2)
					n_row += 1;
				empty_cnt = 0;
			}
			else{
				empty_cnt++;
			}

			if (j == n - 1 && empty_cnt >= 2) {
				n_row += 1;
			}
		}
	}

	for (size_t j = 0; j < n; j++)
	{
		empty_cnt = 0;
		cur_block = -1;
		for (size_t i = 0; i < n; i++)
		{
			cur_block = map[i][j];
			if (cur_block == 0) {
				if (empty_cnt >= 2)
					n_col += 1;

				empty_cnt = 0;
			}
			else {
				empty_cnt++;
			}

			if (i == n - 1 && empty_cnt >= 2) {
				n_col += 1;
			}
		}
	}

	std::cout << n_row << " " << n_col;

	return 0;
}