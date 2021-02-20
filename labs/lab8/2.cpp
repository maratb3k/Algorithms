#include<iostream>

using namespace std;

int n, mini = 1000, res[3], a[101][101];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (a[i][j] > 0 && a[i][k] > 0 && a[j][k] > 0) {
                    int sum = a[i][j] + a[j][k] + a[k][i];
                    if (sum < mini) {
                        mini = sum;
                        res[0] = i;
                        res[1] = j;
                        res[2] = k;
                    }
                } 
            }
        }
    }

    cout << res[0] << " " << res[1] << " " << res[2];

  return 0;
}
