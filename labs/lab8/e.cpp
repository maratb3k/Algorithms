#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0;
vector<int> g[100];
int used[100];


void dfs(int v){
    used[v] = 1;
    for(int i = 0 ; i < g[v].size(); i++){
        if(used[g[v][i]] == 0)
            dfs(g[v][i]);
    }
}

int main() {
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                g[i].push_back(j);
                cnt++;
            }
        }
    }
    
    int h = 0;
    for(int i = 0 ; i < n ;i++){
        if(used[i] == 0){
           dfs(i);
           h++;
       }
    }

    if(cnt/2+1 == n && h == 1)    
        cout << "YES";
    else    cout << "NO";
}