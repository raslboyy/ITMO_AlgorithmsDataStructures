#include <iostream>

using namespace std;

const int N = 3;
const int M = 3;

void foo(int (*a)[M], int n, int m) {
    int maximum = a[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] > maximum)
                maximum = a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == maximum)
                a[i][j] = 0;
}

int main(){

    int a[N][M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    foo(a, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}