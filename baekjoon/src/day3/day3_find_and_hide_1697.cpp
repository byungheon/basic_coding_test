#include <iostream>
#include <queue>

const int MAX = 100001;
bool check[MAX] = {false};
int nexts[3];

int N, K;

int bfs(int x)
{
	if (x == K)
		return 0;

	std::queue<int> q;
	q.push(x);
	check[x] = true;

	int time = 1;
	while (!q.empty())
	{
		int q_size = q.size();
		for (size_t i = 0; i < q_size; i++)
		{
			int now = q.front();
			q.pop();

			nexts[0] = now + 1;
			nexts[1] = now - 1;
			nexts[2] = now * 2;

			for (int j = 0; j < 3; j++)
			{
				int next = nexts[j];
				if (next >= 0 && next < MAX)
				{
					if (check[next] == false)
					{
						q.push(next);
						check[next] = true;
					}

					if (next == K)
						return time;
				}
			}
		}

		time++;
	}
}

int main()
{
	std::cin >> N >> K;
	
	std::cout << bfs(N);

	return 0;
}