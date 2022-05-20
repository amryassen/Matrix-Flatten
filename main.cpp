#include <iostream>

using namespace std;

int *Create1dArray(int n, int m, int p) {
    int *arr = new int[n, m, p];
    return arr;
}

int ConvertTo1dIndex(int i, int j, int k, int n, int m) {
    return (k * n * m) + (j * n) + i;
}

int main() {
    int n = 2, m = 2, p = 2;
    // you can pass n,m,p values as you want from here
    // cin >> n >> m >> p;
    int *Flattened_array = Create1dArray(n, m, p);
    int Original_array[n][m][p];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                cin >> Original_array[i][j][k];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                *(Flattened_array + ConvertTo1dIndex(i, j, k, n, m)) = Original_array[i][j][k];
            }
        }
    }
    for (int i = 0; i < n * m * p; ++i) {
        cout << Flattened_array[i] << " ";
    }

    return 0;
}
