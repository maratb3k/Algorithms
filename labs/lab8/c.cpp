#include<iostream>
#include<vector>
using namespace std;

int n, s;
vector<int> g[100];
int used[100];
vector<int> vec;

void dfs(int v) {
    used[v] = 1;
    vec.push_back(v);
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0){
            dfs(g[v][i]); 
        }
    }
}

int main() {
    cin >> n >> s;
    s--;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                g[i].push_back(j);
            }
        }
    }
    dfs(s);
    cout << vec.size();
    return 0;
}
