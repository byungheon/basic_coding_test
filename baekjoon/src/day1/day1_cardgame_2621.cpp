#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> numbers(5);
std::vector<char> colors(5);
std::vector<int> cnt(10, 0);

int three = 0;
int four = 0;
int two = 0;
int two_pair[2] = {0};

bool isSameColor() {
	for (size_t i = 1; i < 5; i++)
	{
		if (colors[i] != colors[0])
		{
			return false;
		}
	}
	return true;
}

bool isStraight()
{
	std::sort(numbers.begin(), numbers.end());

	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		if (numbers[i] + 1 != numbers[i + 1])
			return false;
	}

	return true;
}

bool isFour()
{
	for (const auto& n: numbers)
	{
		if (cnt[n] == 4) {
			four = n;
			return true;
		}
	}

	return false;
}

bool isThree()
{
	for (const auto& n : numbers)
	{
		if (cnt[n] == 3) {
			three = n;
			return true;
		}
	}

	return false;
}

bool isTwo()
{
	for (const auto& n : numbers)
	{
		if (cnt[n] == 2) {
			two = n;
			return true;
		}
	}

	return false;
}

bool isTwoPair()
{
	int two_cnt = 0;
	for (const auto& n : numbers)
	{
		if (cnt[n] == 2 && two_cnt == 0) {
			two_cnt += 1;
			two_pair[0] = n;
		}
		else if (cnt[n] == 2 && two_cnt == 1 && n != two_pair[0]) {
			int min = two_pair[0] < n ? two_pair[0] : n;
			two_pair[1] = two_pair[0] < n ? n : two_pair[0];
			two_pair[0] = min;

			return true;
		}
	}

	return false;
}

int main() {
	// order RBYG: 0, 1, 2, 3
	
	int max = 0;
	for (size_t i = 0; i < 5; i++)
	{
		std::cin >> colors[i] >> numbers[i];
		cnt[numbers[i]] += 1;
		if (max < numbers[i])
			max = numbers[i];
	}

	int score = 0;
	if (isSameColor() && isStraight()) {
		score = max + 900;
	}
	else if (isFour()) {
		score = four + 800;
	}
	else if (isThree() && isTwo()) {
		score = three * 10 + two + 700;
	}
	else if (isSameColor()) {
		score = max + 600;
	}
	else if (isStraight()) {
		score = max + 500;
	}
	else if (isThree()) {
		score = three + 400;
	}
	else if (isTwoPair()) {
		score = two_pair[1] * 10 + two_pair[0] + 300;
	}
	else if (isTwo()) {
		score = two + 200;
	}
	else {
		score = max + 100;
	}

	std::cout << score << std::endl;

	return 0;
}