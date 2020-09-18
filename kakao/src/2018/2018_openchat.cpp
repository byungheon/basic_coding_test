#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class OpenChat
{
public:
    void changeNickName(string id, string nickname);
    void enter(string id, string nickname);
    void leave (string id, string nickname);
    vector<string> printChat();
private:
    // store references of key in cache 
    unordered_map<string, string> id_to_name_;
    vector<string> verb_ = {"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.", "´ÔÀÌ ³ª°¬½À´Ï´Ù."};
    vector<pair<string, int>> chat_list_;
};

void OpenChat::changeNickName(string id, string nickname) {
    id_to_name_[id] = nickname;
}

void OpenChat::enter(string id, string nickname) {
    id_to_name_[id] = nickname;
    chat_list_.push_back(make_pair(id, 0));
}

void OpenChat::leave(string id, string nickname) {
    chat_list_.push_back(make_pair(id, 1));
}

vector<string> OpenChat::printChat()
{
    vector<string> chat(chat_list_.size());
    for (size_t i = 0; i < chat_list_.size(); i++)
    {
        chat[i] = id_to_name_[chat_list_[i].first] + verb_[chat_list_[i].second];
    }
    return chat;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    OpenChat chat;
    for (const auto& single: record)
    {
        int cnt = 0;
        int prev = 0;
        vector<string> verb_id_nick(3);
        for (size_t i = 0; i < single.length(); i++)
        {
            if (single[i] == ' ') {
                verb_id_nick[cnt++] = single.substr(prev, i - prev); 
                prev = i + 1;
            }
        }
        verb_id_nick[cnt++] = single.substr(prev);

        if (verb_id_nick[0] == "Enter") {
            chat.enter(verb_id_nick[1], verb_id_nick[2]);
        }else if (verb_id_nick[0] == "Leave") {
            chat.leave(verb_id_nick[1], verb_id_nick[2]);
        }else if (verb_id_nick[0] == "Change") {
            chat.changeNickName(verb_id_nick[1], verb_id_nick[2]);
        }
    }

    answer = chat.printChat();

    return answer;
}

int main() {

    vector<string> msg = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> answer = solution(msg);

    return 0;
}