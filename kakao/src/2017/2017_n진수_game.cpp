#include <string>
#include <vector>

using namespace std;

string convertNumberToString(int number, int system) {
    if (number == 0)
        return "0";

    string answer = "";
    while (number > 0) {
        int remain = number % system;
        if (remain >= 10) {
            char add = 'A' + (remain - 10);
            answer = add + answer;
        }
        else {
            answer = to_string(remain) + answer;
        }
        number /= system;
    }

    return answer;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int total_idx = 0;
    int number = 0;
    string num_str;
    while (1) {
        num_str = convertNumberToString(number++, n);
        for (size_t i = 0; i < num_str.length(); i++)
        {
            if (total_idx % m == (p - 1))
                answer.push_back(num_str[i]);
            
            if (answer.length() >= t)
                return answer;
            total_idx++;
        }
    }
    return answer;
}

int main() {
    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;

    string answer = solution(n, t, m, p);

    return 0;
}