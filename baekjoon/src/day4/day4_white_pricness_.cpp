#include <iostream>
#include <vector>
#include <algorithm>

const int n_real = 7;
const int n_fake = 9;
const int SUM = 100;

int height[n_fake];

struct Dwards
{
	int sum;
	std::vector<int> heights;
	int last_height;

	Dwards(int _sum, int _last, std::vector<int> _heights) :
		sum(_sum), heights(_heights), last_height(_last) {}
};

bool dfs(Dwards dward)
{
	if (dward.heights.size() == n_real) {
		if (dward.sum == SUM) {
			for (const auto& h : dward.heights)
			{
				std::cout << h << std::endl;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	for (size_t i = 0; i < n_fake; i++)
	{
		if (dward.last_height < height[i])
		{
			if (dward.sum + height[i] <= SUM) {
				Dwards next = dward;
				next.sum += height[i];
				next.heights.push_back(height[i]);
				next.last_height = height[i];

				bool success = dfs(next);
				if (success)
					return true;
			}
		}
	}

	return false;
}

int main()
{
	for (size_t i = 0; i < n_fake; i++)
	{
		std::cin >> height[i];
	}

	std::sort(height, height + n_fake);

	dfs(Dwards(0, 0, std::vector<int> {}));

	return 0;
}