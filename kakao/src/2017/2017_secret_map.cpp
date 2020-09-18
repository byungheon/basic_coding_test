#include <string>
#include <vector>

using namespace std;

bool array1[17][17];
bool array2[17][17];

void convertToMap(int num, int n, bool* array) {
    memset(array, false, sizeof(bool) * n);
    int idx = n - 1;
    while (1) {
        array[idx--] = num % 2 == 1? true : false;
        num = num / 2;
        if (num == 0)
            break;
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (size_t i = 0; i < n; i++)
    {
        convertToMap(arr1[i], n, array1[i]);
        convertToMap(arr2[i], n, array2[i]);

        string line;
        line.resize(n);
        for (size_t j = 0; j < n; j++)
        {
            if (array1[i][j] || array2[i][j])
                line[j] = '#';
            else
                line[j] = ' ';
        }
        answer.push_back(line);
    }

    return answer;
}

int main()
{
    int n = 5;
    std::vector<int> arr1 = { 9, 20, 28, 18, 11 };
    std::vector<int> arr2 = { 30, 1, 21, 17, 28 };

    std::vector<string> answer = solution(n, arr1, arr2);

    return 0;
}