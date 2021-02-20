#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];
long long n, q;

bool check(int x, int y){
    for(int i = 0; i < g[x].size(); i++){
        if(g[x][i] == y)  
            return true;
    }
    return false;
}

int main() {
    cin >> n >> q;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                g[i].push_back(j);
            }
        }
    }

    while (q > 0) {
        int a, b, c;
        cin >> a >> b >> c;\
        a--;
        b--;
        c--;
        if(check(a, b) && check(a, c) && check(b, c))
            cout << "YES" << endl;
        else    cout << "NO" << endl;
        q--;
    }
    
    return 0;
}