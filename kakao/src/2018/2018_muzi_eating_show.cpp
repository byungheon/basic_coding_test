#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1;

    int min = 0;
    int max = *max_element(food_times.begin(), food_times.end());
   
    int cut_level = -1;
    long long sum = 0;
    while (min <= max) {
        int med = min + (max - min) / 2;
        long long temp = 0;
        for (size_t i = 0; i < food_times.size(); i++)
        {
            temp += food_times[i] > med ? med : food_times[i];
        }

        if (temp > k) {
            max = med - 1;
        }
        else {
            min = med + 1;
            if (cut_level < med) {
                cut_level = med;
                sum = temp;
            }
        }
    }

    long long gap = k - sum;
    long long cnt = 0;
    for (size_t i = 0; i < food_times.size(); i++)
    {
        if (food_times[i] > cut_level) {
            cnt++;
            if (cnt > gap) {
                answer = i + 1;
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> list = {3, 1, 2};
    long long k = 4;

    int answer = solution(list, k);
    return 0;
}


// others solution
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//using ll = long long;
//
//vector<pair<ll, int>> food_map;
//
//bool cmp(const pair<ll, int>& a, const pair<ll, int>& b)
//{
//    return a.second < b.second;
//}
//
//int solution(vector<int> food_times, long long k) {
//    int answer = 0;
//    ll n = food_times.size();
//    for (int i = 0; i < n; ++i)
//        food_map.push_back(make_pair((ll)food_times[i], i + 1));
//
//    sort(food_map.begin(), food_map.end());
//    ll i = 0;
//    for (; i < n; ++i) {
//        ll diff = i == 0 ? food_map[i].first : food_map[i].first - food_map[i - 1].first;
//        if (k - diff * (n - i) < 0) break;
//        k -= diff * (n - i);
//    }
//
//    if (i == food_map.size()) return -1;
//
//    sort(food_map.begin() + i, food_map.end(), cmp);
//    answer = food_map[i + k % (n - i)].second;
//    return answer;
//}