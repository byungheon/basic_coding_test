#include <iostream>
#include <vector>
const int MAX = 1000001;

long long N, M;

long long height[MAX];

int main()
{
	std::cin >> N >> M;

	long long start = 0;
	long long end = 0;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> height[i];
		if (height[i] > end)
			end = height[i];
	}

	long long mid = (start + end) / 2;
	long long ans = 0;
	while (start <= end)
	{
		long long temp = 0;
		mid = (start + end) / 2;
		for (size_t i = 0; i < N; i++)
		{
			temp += height[i] > mid? (height[i] - mid): 0;
		}

		if (temp >= M) {
			start = mid + 1;
			if (mid > ans) {
				ans = mid;
			}
		}
		else
		{
			end = mid - 1;
		}
	}
	std::cout << ans;

	return 0;
}