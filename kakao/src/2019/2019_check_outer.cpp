#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void makeCombiUtil(vector<vector<int> >& ans,
    vector<int>& tmp, int n, int left, int k)
{
    // Pushing this vector to a vector of vector 
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }

    for (int i = left; i < n; i++)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);

        // Popping out last inserted element 
        // from the vector 
        tmp.pop_back();
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    vector<int> gaps;
    int n_weak = weak.size();
    int n_friend = dist.size();

    for (int i = 0; i < n_weak; i++)
    {
        int next_idx = (i + 1) % weak.size();
        int gap = weak[next_idx] - weak[i];
        if (gap < 0) gap += n;
        gaps.push_back(gap);
    }

    sort(dist.begin(), dist.end(), greater<int>());
    for (int i = 1; i <= n_friend; i++)
    {
        if (n_weak <= i)
            return i;

        vector<vector<int>> cands;
        vector<int> tmp;
        makeCombiUtil(cands, tmp, n_weak, 0, i);
        
        vector<int> cand_hours;
        for (const auto& cand : cands) {
            int accum = 0;
            cand_hours.clear();
            for (int j = 0; j < n_weak; j++)
            {
                if (find(cand.begin(), cand.end(), j) != cand.end()) {
                    cand_hours.push_back(accum);
                    accum = 0;
                }
                else {
                    accum += gaps[j];
                }
                if (j == n_weak - 1)
                    cand_hours[0] += accum;
            }

            sort(cand_hours.begin(), cand_hours.end(), greater<int>());
            bool possible = true;
            for (int j = 0; j < i; j++)
            {
                if (cand_hours[j] > dist[j]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                answer = i;
                break;
            }
        }
        
        if (answer != -1)
            break;
    }

    return answer;
}

int main() {
    int n = 12;
    vector<int> weak = {1, 5, 6, 10 };
    vector<int> dist = { 1, 2, 3, 4 };

    int answer = solution(n, weak, dist);
    return 0;
}