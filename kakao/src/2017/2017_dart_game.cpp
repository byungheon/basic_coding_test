#include <string>
#include <vector>
#include <cmath>
using namespace std;

int getNumber(char a) {
    return a - '0';
}

int getBonus(char a) {
    if (a == 'S')
        return 1;
    else if (a == 'D')
        return 2;
    else if (a == 'T')
        return 3;

    return -1;
}

int getOption(char a) {
    if (a == '*')
        return 1;
    else if (a == '#')
        return 2;
    else
        return 0;
}

int solution(string dartResult) {
    int answer = 0;

    std::vector<int> scores;
    int str_idx = 0;
    int n_idx = 0;
    while (1) {
        if (str_idx >= dartResult.length())
            break;

        int number = getNumber(dartResult[str_idx++]);
        int number2 = getNumber(dartResult[str_idx]);

        if (number2 >= 0 && number2 <= 9) {
            number = number * 10 + number2;
            str_idx++;
        }
        
        int bonus = getBonus(dartResult[str_idx++]);
        number = std::pow(number, bonus);
        int option = getOption(dartResult[str_idx]);
        if (option == 1) {
            number *= 2;
            if (n_idx >= 1)
                scores[n_idx - 1] *= 2;
            str_idx++;
        }
        else if (option == 2) {
            number *= -1;
            str_idx++;
        }
        scores.push_back(number);
        n_idx++;
    }

    for (size_t i = 0; i < scores.size(); i++)
    {
        answer += scores[i];
    }

    return answer;
}

int main() {
    std::string a = "1D2S#10S";

    int answer = solution(a);

    return 0;
}