#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate_key(vector<vector<int>> key) {
    vector<vector<int>> rot = key;
    int size = key.size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            rot[i][j] = key[size - j - 1][i];
        }
    }

    return rot;
}

bool checkFeasibility(vector<vector<int>> key, vector<vector<int>> lock, int shift1, int shift2) { 

    int key_size = key.size();
    int lock_size = lock.size();
    int key1, key2;
    for (int i = 0; i < lock_size; i++)
    {
        for (int j = 0; j < lock_size; j++)
        {
            key1 = i - shift1;
            key2 = j - shift2;
            if (key1 >= 0 && key1 < key_size && key2 >= 0 && key2 < key_size) {
                if (key[key1][key2] * lock[i][j] == 1)
                    return false;
                else
                    lock[i][j] = key[key1][key2] == 1? key[key1][key2]: lock[i][j];
            }

            if (lock[i][j] != 1)
                return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int key_size = key.size();
    int lock_size = lock.size();

    for (int i_rot = 0; i_rot < 4; i_rot++)
    {
        for (int i = -key_size + 1; i < lock_size; i++)
        {
            for (int j = -key_size + 1; j < lock_size; j++)
            {
                if (checkFeasibility(key, lock, i, j)) {
                    answer = true;
                    break;
                }
            }
        }
        key = rotate_key(key);
    }

    return answer;
}

int main() {
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    bool answer = solution(key, lock);

    return 0;
}