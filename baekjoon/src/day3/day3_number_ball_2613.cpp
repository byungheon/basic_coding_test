#include <iostream>

const int MAX = 301;

int N, M;

int number[MAX];

bool isPossible(int x)
{
	int cnt = 1;
	int sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += number[i];
		if (sum > x) {
			sum = number[i];
			cnt++;
		}
	}

	return cnt <= M;
}

void printGroup(int x)
{
	int sum = 0;
	int cnt = 0;
	int m = M;
	for (size_t i = 0; i < N; i++)
	{
		sum += number[i];
		if (sum > x)
		{
			std::cout << cnt << " ";
			sum = number[i];
			cnt = 0;
			m--;
		}

		cnt++;

		if (N - i == m)
			break;
	}

	while (m--)
	{
		std::cout << cnt << " ";
		cnt = 1;
	}
}

int main()
{
	int start = 0;
	int end = 0;
	std::cin >> N >> M;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> number[i];
		if (start < number[i])
			start = number[i];

		end += number[i];
	}

	int mid = 0;
	int ans = 0;
	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (isPossible(mid)) {
			end = mid - 1;
			ans = mid;
		}
		else {
			start = mid + 1;
		}
	}

	std::cout << ans << std::endl;

	printGroup(ans);

	return 0;
}