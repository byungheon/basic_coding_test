#include<stdio.h>
#include<algorithm>

using namespace std;

int n, m;
int d[1000001];

int main() {
    int i;
    while (~scanf("%d %d", &m, &n)) {
        m *= 10000000;

        for (i = 1; i <= n; i++) {
            scanf("%d", &d[i]);
        }

        sort(d + 1, d + n + 1);

        int l = 1, r = n;

        while (l < r) {
            if (d[l] + d[r] > m)r--;
            else if (d[l] + d[r] < m)l++;

            if (d[l] + d[r] == m && l != r) {
                printf("yes %d %d\n", d[l], d[r]);
                break;
            }
        }
        if (l >= r)
            printf("danger\n");
    }
    return 0;
}