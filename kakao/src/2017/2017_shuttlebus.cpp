#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int time_table[2000] = {};
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

	// convert string to minutes
	size_t n_crew = timetable.size();
	for (size_t i = 0; i < n_crew; i++)
	{
		time_table[i] = stoi(timetable[i].substr(0, 2)) * 60 +
			stoi(timetable[i].substr(3, 2));
	}

	// sort
	std::sort(time_table, time_table + n_crew);


	int accum = 0;
	int time = 9 * 60;
	int time_to_arrive = time + (n - 1) * t;

	int i_crew = 0, i_shuttle = 0;
	for (i_crew = 0, i_shuttle = 0; i_crew < n_crew && i_shuttle < n;)
	{
		if (time_table[i_crew] > time) {
			// shuttle left
			accum -= m;
			accum = accum > 0 ? accum : 0;
			time += t;
			i_shuttle++;

			continue;
		}

		accum += 1;

		// 마지막 셔틀인데 다 차버린 경우
		if (accum >= m * (n - i_shuttle)) {
			time_to_arrive = time_table[i_crew] - 1;
			break;
		}

		i_crew++;
	}

	int hour = time_to_arrive / 60;
	int min = time_to_arrive % 60;
	if (hour < 10) {
		answer += "0";
	}
	answer += to_string(hour) + ":";
	if (min < 10) {
		answer += "0";
	}
	answer += to_string(min);


    return answer;
}

int main() {

	int a = stoi("08");

	int n = 2;
	int t = 10;
	int m = 0;
	std::vector<string> list = { "08:00", "08:01", "08:02", "08:03" };

	string answer = solution(n, t, m, list);

	std::cout << answer << std::endl;

	return 0;
}