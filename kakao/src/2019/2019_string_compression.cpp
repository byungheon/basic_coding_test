#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    string s_ans;
    for (size_t i = 1; i < len / 2 + 1; i++)
    {
        string tmp;
        string repeat;
        int idx = 0;

        while (idx < len) {
            if (idx >= len - i) {
                tmp.append(s.substr(idx));
                break;
            }

            repeat = s.substr(idx, i);
            int idx_local = idx + i;
            int cnt = 1;
            while (idx_local + i <= len) {
                if (repeat == s.substr(idx_local, i)) {
                    cnt++;
                    idx_local += i;
                }
                else {
                    break;
                }
            }

            idx += i * cnt;
            if (cnt > 1) {
                tmp += to_string(cnt) + repeat;
            }
            else {
                tmp += repeat;
            }
        }

        if (answer > tmp.length()) {
            answer = tmp.length();
            s_ans = tmp;
        }
    }

    return answer;
}

int main() {
    string s = "abcabcdede";
    int answer = solution(s);

    return 0;
}