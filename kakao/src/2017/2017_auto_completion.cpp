#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool comp(const string& n1, const string& n2) {
    return strcmp(n1.c_str(), n2.c_str()) < 0;
}

int computeOverlap(string& n1, string& n2) {
    int max = min(n1.length(), n2.length());
    for (size_t i = 0; i < max; i++)
    {
        if (n1[i] != n2[i]) {
            return i;
        }
    }

    return max;
}

int solution(vector<string> words) {
    int answer = 0;
    std::sort(words.begin(), words.end(), comp);
    
    int overlap_pre = -1;
    int overlap_next = -1;
    for (int i = 0; i < words.size(); i++)
    {
        if (i < words.size() - 1)
            overlap_next = computeOverlap(words[i], words[i+1]);
        
        answer += min(max(overlap_pre, overlap_next) + 1, int(words[i].length()));

        overlap_pre = overlap_next;
        overlap_next = 0;
    }

    return answer;
}

int main() {
    vector<string> list = {"go", "gone", "guild"};

    int answer = solution(list);

    return 0;
}