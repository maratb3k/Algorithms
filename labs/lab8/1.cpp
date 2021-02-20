#include<iostream>

using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    int a[n][n], b[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(a[i][j] == 1){
                if(b[i] != b[j])
                    cnt++;
            }
        }
    }
    cout << cnt;
}