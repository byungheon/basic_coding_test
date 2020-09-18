#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;

const int MAX = 20 + 1;

int N, doorNum;

int order[MAX];

int cache[MAX][MAX][MAX]; //���� ���� �ε���, (�� ���� �� �� ��)



int minMove(int orderIdx, int open1, int open2)

{

    //���� ���: ��� ������ �����ϸ�

    if (orderIdx > doorNum)

        return 0;



    int result = cache[orderIdx][open1][open2];

    if (result != -1)

        return result;



    //open1 �̵� Ȥ�� open2 �̵�

    //���� ������ �����ִ� ���� open1�� open2���� ���� ��쵵 �����Ƿ� ���밪 abs

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