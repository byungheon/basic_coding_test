#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<string> combinations;

vector<string> cand_key;

int n_att, n_people;

bool compare(const std::string& str1, const std::string& str2) {
    if (str1.length() == str2.length())
        return strcmp(str1.c_str(), str2.c_str()) < 0;
    else
        return str1.length() <= str2.length();
}

void dfs(int start, string comb) {
    for (int i = start; i < n_att; i++)
    {
        string temp = comb + to_string(i);
        combinations.push_back(temp);
        dfs(i + 1, temp);
    }
}

bool check_subset(const std::string& str) {
    if (str.length() == 1)
        return false;
    
    for (const auto& key: cand_key)
    {
        bool keyInStr = true;
        for (size_t i = 0; i < key.length(); i++)
        {
            if (str.find(key[i]) == std::string::npos) {
                keyInStr = false;
                break;
            }
        }
        if (keyInStr == true)
            return true;
    }

    return false;
}

bool check_uniqueness(const std::string& str, vector<vector<string>>& relation) {
    std::vector<string> characters(relation.size());
    for (size_t i = 0; i < relation.size(); i++)
    {
        string temp = "";
        for (size_t j = 0; j < str.length(); j++)
        {
            temp += relation[i][int(str[j] - '0')];
        }
        characters[i] = temp;
    }

    std::sort(characters.begin(), characters.end());

    for (size_t i = 0; i < characters.size() - 1; i++)
    {
        if (characters[i] == characters[i + 1]) {
            return false;
        }
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    n_people = relation.size();
    n_att = relation[0].size();

    dfs(0, "");


    std::sort(combinations.begin(), combinations.end(), compare);


    for (int i = 0; i < combinations.size(); i++)
    {
        if (!check_subset(combinations[i])) {
            if (check_uniqueness(combinations[i], relation)) {
                cand_key.push_back(combinations[i]);
            }
        }
    }

    return cand_key.size();
}



int main() {

    vector<vector<string>> list = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};

    int ans = solution(list);

    return 0;
}

///// simple answer
//
//#include <bits/stdc++.h>
//using namespace std;
//bool possi(vector<int>& vec, int now) {
//    for (int i = 0; i < vec.size(); i++)
//        if ((vec[i] & now) == vec[i])return false;
//    return true;
//}
//int solution(vector<vector<string>> relation) {
//    int n = relation.size();
//    int m = relation[0].size();
//    vector<int> ans;
//    for (int i = 1; i < (1 << m); i++) {
//        set<string> s;
//        for (int j = 0; j < n; j++) {
//            string now = "";
//            for (int k = 0; k < m; k++) {
//                if (i & (1 << k))now += relation[j][k];
//            }
//            s.insert(now);
//        }
//        if (s.size() == n && possi(ans, i))ans.push_back(i);
//    }
//    return ans.size();
//}