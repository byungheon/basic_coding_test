#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string LZWCompression(string str, unordered_map<string, int>& dict, int max_len, int& cnt, int& indicator) {
    
    int len = 1;
    for (size_t i = 1; i <= min(max_len, int(str.length())); i++)
    {
        if (dict.find(str.substr(0, i)) != dict.end()) {
            len = i;
            indicator = dict[str.substr(0, i)];
        }
    }

    string w = str.substr(0, len);
    str = str.substr(len);
    if (str.length() > 0)
    {
        w.push_back(str[0]);
        dict[w] = ++cnt;
    }

    return str;
}

vector<int> solution(string msg) {
    vector<int> answer;

    unordered_map<string, int> dict;

    int cnt = 0;
    for (char a = 'A'; a <= 'Z'; a++)
    {
        dict[string(1, a)] = ++cnt;
    }

    int max_len = 1;
    while (1) {
        int indicator = 0;
        msg = LZWCompression(msg, dict, max_len, cnt, indicator);
        answer.push_back(indicator); max_len++;

        if (msg.length() == 0) break;
    }

    return answer;
}


#include <iostream>
int main() {
    string msg = "KAKAO";
    vector<int> answer = solution(msg);

    for (const auto& i: answer)
    {
        std::cout << i << ", ";
    }

    return 0;
}