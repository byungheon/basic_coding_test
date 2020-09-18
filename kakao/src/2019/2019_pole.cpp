#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int map[101][101] = { -1 };
// 0: ±‚µ’
// 1: ∫∏
// 2: ±‚µ’ & ∫∏


struct frame {
    vector<vector<int>> map;
    bool isPole(int x, int y) {
        int N = map.size();
        if (x >= 0 && x < N && y >= 0 && y < N)
            if (map[x][y] == 0 || map[x][y] == 2)
                return true;

        return false;
    }

    bool isPlate(int x, int y) {
        int N = map.size();
        if (x >= 0 && x < N && y >= 0 && y < N)
            if (map[x][y] >= 1)
                return true;

        return false;
    }

    void add(int x, int y, int type) {

        if (map[x][y] == -1)
            map[x][y] = type;
        else
            map[x][y] = 2;
    }

    void remove(int x, int y, int type) {
        if (map[x][y] == type)
            map[x][y] = -1;
        else
            map[x][y] = std::abs(type - 1);
    }
};

bool isFeasible(frame& building) {
    int n = building.map.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (building.isPole(i, j)){
                if (j == 0 || 
                    building.isPlate(i - 1, j) ||
                    building.isPlate(i, j) ||
                    building.isPole(i, j - 1))
                { }
                else
                    return false;
            }
            
            if (building.isPlate(i, j)) {
                if (building.isPole(i, j - 1) ||
                    building.isPole(i + 1, j - 1) ||
                    (building.isPlate(i - 1, j) && building.isPlate(i + 1, j)))
                { }
                else
                    return false;
            }
        }
    }

    return true;
}

void conduct(frame& build, const vector<int>& task) {
    if (task[3] == 0) {
        // ªË¡¶
        build.remove(task[0], task[1], task[2]);
        if (isFeasible(build)) {
        }
        else {
            build.add(task[0], task[1], task[2]);
        }
    }
    else {
        // √ﬂ∞°
        build.add(task[0], task[1], task[2]);
        if (isFeasible(build)) {
        }
        else {
            build.remove(task[0], task[1], task[2]);
        }
    }
}

bool compare(const std::vector<int>& s1, const std::vector<int>& s2) {
    if (s1[0] == s2[0]) {
        if (s1[1] == s2[1]) {
            return s1[2] < s2[2];
        }
        else {
            return s1[1] < s2[1];
        }
    }
    else {
        return s1[0] < s2[0];
    }
}

void convertBuildToAnswer(frame& build, vector<vector<int>>& answer) {
    for (int i = 0; i < build.map.size(); i++)
    {
        for (int j = 0; j < build.map.size(); j++)
        {
            if (build.isPole(i, j)) {
                answer.push_back({i, j, 0});
            }

            if (build.isPlate(i, j)) {
                answer.push_back({i, j, 1});
            }
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    frame build;
    build.map = vector<vector<int>>(n+1, vector<int>(n+1, -1));
    for (const auto& task: build_frame)
    {
        conduct(build, task);
    }

    convertBuildToAnswer(build, answer);

    sort(answer.begin(), answer.end(), compare);

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> build_frame = {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}};
    vector<vector<int>> sol = solution(n, build_frame);
    return 0;
}