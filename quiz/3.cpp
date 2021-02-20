#include<iostream>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    int b[q][4];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < q; i++)
    {   
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {   
            
            if((a[j] >= b[i][0] && a[j] <= b[i][1]) || (a[j] >= b[i][2] && a[j] <= b[i][3]))
                cnt++;
        }
        cout << cnt << endl;
    }  
}