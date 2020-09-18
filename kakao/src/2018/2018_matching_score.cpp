#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string word, vector<string> pages) {
    // make it lower
    std::transform(word.begin(), word.end(), word.begin(), 
        [](unsigned char c) -> unsigned char { return std::tolower(c); });

    int n_pages = pages.size();
    std::unordered_map<string, int> link_to_idx;
    std::vector<std::pair<int, std::vector<string>>> score_links(n_pages, { 0, {} });

    for (size_t i = 0; i < n_pages; i++)
    {
        string html = pages[i];

        string current_link = "";
        int ind = 0;
        while (current_link == "") {
            // <meta ~ 시작 인덱스 찾기
            ind = html.find("<meta") + 5;
            int last = html.substr(ind).find(">");
            html = html.substr(ind);
            ind = html.find("https://");

            // meta 태그 안에 있는 링크가 아닌경우 거르기
            if (last < ind)
                continue;

            last = html.substr(ind).find("\"");
            current_link = html.substr(ind, last);

            link_to_idx[current_link] = i;
        }


        // find link
        // 링크 점수 구하기
        ind = html.find("<a href");
        while (ind != string::npos) {
            html = html.substr(ind + 7);
            html = html.substr(html.find("https://"));
            score_links[i].second.push_back(html.substr(0, html.find("\"")));
            ind = html.find("<a href");
        }

        html = pages[i];
        std::transform(html.begin(), html.end(), html.begin(),
            [](unsigned char c) -> unsigned char { return std::tolower(c); });

        ind = html.find(word, 0);
        while (ind != string::npos) {
            score_links[i].first += 1;
            if ((ind >= 1 && html.at(ind - 1) >= 'a' && html.at(ind - 1) <= 'z') ||
                (ind + word.length() < html.length() - 1 && html.at(ind + word.length()) >= 'a' && html.at(ind + word.length()) <= 'z')) {
                score_links[i].first -= 1;
            }

            ind = html.find(word, ind + word.length());
        }

    }

    std::vector<double> scores(n_pages, 0);
    for (size_t i = 0; i < n_pages; i++)
    {
        scores[i] += score_links[i].first;
        double link_score = double(score_links[i].first) / score_links[i].second.size();
        for (const auto& link : score_links[i].second)
        {
            if (link_to_idx.find(link) != link_to_idx.end()) {
                scores[link_to_idx[link]] += link_score;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n_pages; i++) {
        if (scores[answer] < scores[i]) {
            answer = i;
        }
    }

    return answer;
}

int main() {
    vector<string> htmls = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
    string word = "blind";

    int answer = solution(word, htmls);

    return 0;
}