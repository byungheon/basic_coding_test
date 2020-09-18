#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool comp(const pair<double, int>& s1, const pair<double, int>& s2) {
    if (s1.first == s2.first)
        return s1.second < s2.second;
    return s1.first > s2.first;
}

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end(), std::greater<int>());
    
    vector<pair<double, int>> failure(N);
    for (size_t i = 0; i < N; i++)
    {
        failure[i] = make_pair(0, i + 1);
    }

    int sum = 0;
    int local_sum = 0;
    int pre = -1;
    for (size_t i = 0; i < stages.size(); i++)
    {
        sum++;
        if (stages[i] == N + 1) {
            continue;
        }

        local_sum += 1;
        if (i == stages.size() - 1 || stages[i] != stages[i + 1]) {
            failure[stages[i] - 1] = make_pair(double(local_sum) / double(sum), stages[i]);
            local_sum = 0;
        }
    }

    sort(failure.begin(), failure.end(), comp);

    vector<int> answer(N);
    for (size_t i = 0; i < N; i++)
    {
        answer[i] = failure[i].second;
    }

    return answer;
}

int main() {
    int n = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    vector<int> answer = solution(n, stages);
    return 0;
}