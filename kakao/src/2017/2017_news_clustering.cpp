#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

#include <ctype.h>

using namespace std;

const int MAX_LENGTH = 1000;

string alpha_list1[MAX_LENGTH] = {};
string alpha_list2[MAX_LENGTH] = {};

bool comp(string& s1, string& s2) {
    return strcmp(s1.c_str(), s2.c_str()) < 0;
}

int convertStringToList(string st, string* list) {
    int n_elem = 0;
    for (size_t i = 0; i < st.length() - 1; i++)
    {
        if (isalpha(st[i]) && isalpha(st[i + 1])) {
            list[n_elem] = st.substr(i,2);

            list[n_elem][0] = std::tolower(list[n_elem][0]);
            list[n_elem][1] = std::tolower(list[n_elem][1]);
            n_elem += 1;
        }
    }

    return n_elem;
}



int solution(string str1, string str2) {
    int n1 = convertStringToList(str1, alpha_list1);
    int n2 = convertStringToList(str2, alpha_list2);

    std::sort(alpha_list1, alpha_list1 + n1, comp);
    std::sort(alpha_list2, alpha_list2 + n2, comp);

    int n_sum = 0;
    int n_inter = 0;
    int i = 0, j = 0;
    for (i = 0, j = 0; i < n1 && j < n2;) {
        int comp = strcmp(alpha_list1[i].c_str(), alpha_list2[j].c_str());
        if (comp < 0) {
            n_sum += 1;
            i++;
        }
        else if (comp > 0) {
            n_sum += 1;
            j++;
        }
        else {
            n_inter += 1;
            n_sum += 1;
            i++;
            j++;
        }
    }

    n_sum += (n1 - i) + (n2 - j);
    double j_score = 0;
    if (n_sum == 0) {
        j_score = 1;
    }
    else {
        j_score = static_cast<double>(n_inter) / static_cast<double>(n_sum);
    }
    j_score *= 65536;
    j_score = floor(j_score);

    return static_cast<int>(j_score);
}

int main()
{
    string s1 = "E=M*C^2";
    string s2 = "e=m*c^2";

    int ans = solution(s1, s2);

    std::cout << "ans: " << ans << std::endl;

    return 0;
}