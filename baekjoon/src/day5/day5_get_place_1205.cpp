#include <iostream>

const int MAX = 50+1;

int N, P; // N: 점수 개수, P: 올라갈 수 있는 점수 개수

long long song;

long long templates[MAX];
int main()
{
	std::cin >> N >> song >> P;

	int ans = N + 1;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> templates[i];
		if (templates[i] <= song) {
			ans = ans < i? ans : i;
		}
	}

	if (N >= P && song <= templates[N]) {
		std::cout << -1;
	}
	else {
		std::cout << ans;
	}

	return 0;
}