#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

void splitString(std::string str, std::string& head, int& number) {
    int i_number = 0;
    for (int i = 0; i < int(str.length()); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') {
            i_number = i;
            break;
        }

        str[i] = tolower(str[i]);
    }

    head = str.substr(0, i_number);

    int i_tail = i_number + 5;
    for (int i = i_number; i <= i_number + 5; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            i_tail = i;
    }
    number = stoi(str.substr(i_number, i_tail - i_number));
}

bool compare(const std::string& str1, const std::string& str2) {
    string head1, head2;
    int num1, num2;

    splitString(str1, head1, num1);
    splitString(str2, head2, num2);
    
    int str_cmp = strcmp(head1.c_str(), head2.c_str());
    if (str_cmp != 0) {
        return str_cmp < 0;
    }
    else {
        return num1 < num2;
    }
}

vector<string> solution(vector<string> files) {
    
    stable_sort(files.begin(), files.end(), compare);

    return files;
}

int main()
{
    vector<string> list = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", 
        "img2.JPG" };
    vector<string> answer = solution(list);
    return 0;
}