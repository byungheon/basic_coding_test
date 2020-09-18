#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;

const int MAX = 20 + 1;

int N, doorNum;

int order[MAX];

int cache[MAX][MAX][MAX]; //벽장 순서 인덱스, (문 열린 곳 두 곳)



int minMove(int orderIdx, int open1, int open2)

{

    //기저 사례: 모든 순서를 도달하면

    if (orderIdx > doorNum)

        return 0;



    int result = cache[orderIdx][open1][open2];

    if (result != -1)

        return result;



    //open1 이동 혹은 open2 이동

    //현재 순서에 열려있는 문이 open1과 open2보다 작을 경우도 있으므로 절대값 abs

    result = min(abs(order[orderIdx] - open1) + minMove(orderIdx + 1, order[orderIdx], open2), abs(order[orderIdx] - open2) + minMove(orderIdx + 1, open1, order[orderIdx]));



    return result;

}



int main(void)

{

    cin >> N;

    int open1, open2;

    cin >> open1 >> open2;

    cin >> doorNum;

    for (int i = 1; i <= doorNum; i++)

    {
        cin >> order[i];
    }


    cout << minMove(1, open1, open2) << endl;

    return 0;

}