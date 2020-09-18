#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

const char qkey = '?';
class Trie{
public:
    Trie() : last(false), cnt(1) {}
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (nodes[i] != nullptr) delete nodes[i];
        }
    }

    void insert(const char* key) {
        if (*key == '\0')
            last = true;
        else {
            int val = *key - 'a';
            if (nodes[val] != nullptr)
                nodes[val]->cnt++;
            else
                nodes[val] = new Trie();

            nodes[val]->insert(key + 1);
        }
    }

    int find(const char* key) {
        int val = *key - 'a';
        if (*key == qkey) {
            int sum = 0;
            for (size_t i = 0; i < 26; i++)
            {
                if (nodes[i] != nullptr) sum += nodes[i]->cnt;
            }
            return sum;
        }
        else {
            if (nodes[val] == nullptr)
                return 0;
            if (*(key + 1) == qkey)
                return nodes[val]->cnt;

            return nodes[val]->find(key + 1);
        }
    }

private:
    Trie* nodes[26] = {nullptr}; // a ~ z
    bool last;
    int cnt;
};

Trie* root[10001];
Trie* root_re[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);

    int n_word = words.size();
    int n_query = queries.size();

    for (const auto& word : words) {
        int len = word.length();

        if (root[len] == nullptr) root[len] = new Trie();
        root[len]->insert(word.c_str());

        string reversed = word;
        reverse(reversed.begin(), reversed.end());

        const char* r = reversed.c_str();
        if (root_re[len] == nullptr) root_re[len] = new Trie();
        root_re[len]->insert(reversed.c_str());
    }

    for (int i = 0; i < n_query; i++)
    {
        string query = queries[i];
        int len = query.length();
        
        if (query[0] == '?') {
            string reversed = query;
            reverse(reversed.begin(), reversed.end());
            if (root_re[len] == nullptr)
                continue;
            answer[i] = root_re[len]->find(reversed.c_str());
        }
        else {
            if (root[len] == nullptr)
                continue;
            answer[i] = root[len]->find(query.c_str());
        }
    }

    return answer;
}

int main() {
    std::vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    std::vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    
    std::vector<int> answer = solution(words, queries);
    return 0;
}