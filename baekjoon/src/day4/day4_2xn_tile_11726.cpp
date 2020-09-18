#include <iostream>

const int MAX = 1001;

int dp[MAX] = {0};

int n;
int main() {
	std::cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	int ans = dp[n] % 10007;

	std::cout << ans;

	return 0;
}