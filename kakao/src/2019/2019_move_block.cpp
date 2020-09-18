#include <string>
#include <vector>

using namespace std;

const int MAX = 102;

bool check[MAX][MAX][2] = { false };
int graph[MAX][MAX] = {1};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct point {
    int x, y;
};

struct status {
    point point1;
    point point2;
    void setPoint(int x1, int y1, int x2, int y2) {
        bool reverse = false;
        if (x1 < x2) {
            reverse = false;
        }
        else if (x1 > x2) {
            reverse = true;
        }
        else if (x1 == x2) {
            if (y1 < y2) {
                reverse = false;
            }
            else {
                reverse = false;
            }
        }

        if (reverse) {
            point2.x = x1;
            point2.y = y1;
            point1.x = x2;
            point1.y = y2;
        }
        else {
            point1.x = x1;
            point1.y = y1;
            point2.x = x2;
            point2.y = y2;
        }
    }
    int getCheckIdx() {
        if (point1.x == point2.x)
            return 0;
        else
            return 1;
    }
};

int bfs();

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    for (size_t i = 0; i < N; i++)
    {
        memcpy(&(graph[i + 1][i + 1]), board[i].data(), sizeof(int) * N);
    }
    
    return answer;
}