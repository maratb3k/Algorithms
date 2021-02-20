#include<iostream>

using namespace std;

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int a[n][m], max[n], min[m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int j = 0; j < m; j++) {
        max[j] = a[0][j];
        for (int i = 1; i < n; ++i) { 
            if (a[i][j] > max[j]) 
                max[j] = a[i][j];  
        }
    }

    for (int i = 0; i < n; i++) {
        min[i] = a[i][0];
        for (int j = 1; j < m; j++) { 
            if (a[i][j] < min[i])  
                min[i] = a[i][j];  
        }
    }
     

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (min[i] == a[i][j] && max[j] == a[i][j]) 
                cnt++; 
        }
    }
    cout << cnt;

}