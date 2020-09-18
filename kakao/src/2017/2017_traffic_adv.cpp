#include <string>
#include <vector>
#include <iostream>

using namespace std;

int times[2000][2] = {};

void convertStringToStartNEndTime(string& line, int& start, int& end)
{
    char zero = '0';

    // end time
    int hour = (int)(line[11] - zero) * 10 + (line[12] - zero);
    int min = (int)(line[14] - zero) * 10 + (line[15] - zero);
    int sec = (int)(line[17] - zero) * 10 + (line[18] - zero);
    int milli = (int)(line[20] - zero) * 100 + (line[21] - zero) * 10 + (line[22] - zero);

    end = milli + 1000 * (sec + 60 * (min + 60 * hour));
    
    // time taken
    int idx = 24;
    int gap = 0;
    int coeff = 1000;
    bool dotAppear = false;
    while (1) {
        if (line[idx] == 's') {
            break;
        }
        else if (line[idx] == '.'){
            dotAppear = true;
        }
        else {
            if (dotAppear) {
                coeff *= 0.1;
            }

            gap += (int)(line[idx] - zero) * coeff;
        }

        idx += 1;
    }

    start = end - gap + 1;
}

bool overlap(int s1, int e1, int s2, int e2) {
    return ((s1 >= s2) && (s1 <= e2)) || ((s2 >= s1) && (s2 <= e1));
}

int solution(vector<string> lines) {
    int n_log = lines.size();

    for (int i = 0; i < n_log; i++)
    {
        convertStringToStartNEndTime(lines[i], times[i][0], times[i][1]);
    }

    int max_traffic = 0;
    int gap = 999;
    for (int i = 0; i < n_log; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int traffic = 0;
            int start, end;
            if (j == 0) {
                start = times[i][j] - gap;
                end = times[i][j];
            }
            else {
                start = times[i][j];
                end = times[i][j] + gap;
            }

            for (int k = 0; k < n_log; k++)
            {
                if (overlap(start, end, times[k][0], times[k][1]))
                    traffic++;
            }

            if (traffic > max_traffic)
                max_traffic = traffic;
        }
    }

    return max_traffic;
}

int main()
{
    vector<string> input = { "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s" };
    
    int ans = solution(input);

    cout << "answer: " << ans << endl;

    return 0;
}