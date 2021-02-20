#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int graph[30][30];
int dst[30][30];
pair<int, int> pr[30][30];   
int n, x1, y1, x2, y2;

int dx[] = {-1, +1, -1, +1, +2, +2, -2, -2};
int dy[] = {-2, -2, +2, +2, -1, +1, -1, +1};


bool check(int x, int y) {
    return x >= 0 && x < n && y >=0 && y < n && graph[x][y] == 0;
}

// void bfs() {
//     queue<int> q;
//     q.push(k);
//     used[k] = true;
//     dst[k] = 0;
//     pr[k] = -1; 

//     while (!q.empty()) {
//         int cur = q.front();
//         // cout << cur << endl;
//         if (cur == h) {
//             cout <<  dst[cur] << endl; break;
//         }

//         q.pop();

//         for (int i = 0; i < n; i++)
//         {
//             if (!used[i] && graph[cur][i]) {
//                 q.push(i);
//                 used[i] = true;
//                 dst[i] = dst[cur] + 1;
//                 pr[i] = cur;   //сохранение предыдущей вершины
//             }
//         }
        
//     }
// }

void dfs (int x, int y) {

    queue<pair<int, int>> q;
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            dst[i][j] = -1;

    q.emplace(x, y);
    graph[x][y] = 1;
    dst[x][y] = 0;
    pr[x][y].first = -1;
    pr[x][y].second = -1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        // cout << cur.first+1 << " " << cur.second+1 << endl;

        if (cur.first == x2-1 && cur.second == y2-1) {
            cout << dst[cur.first][cur.second] << endl;

            vector<pair<int, int>> result;
            
            result.push_back(cur);
            while (pr[cur.first][cur.second] != make_pair(-1, -1))
            {
                cur = pr[cur.first][cur.second];
                result.push_back(cur);
            }

            for (int i = result.size() - 1; i >= 0; i--)
            {
                cout << result[i].first + 1 << " " << result[i].second + 1 << endl;
            }

            break;
        }

        for (int i = 0; i < 8; i++)
        {
            if (check(cur.first+dx[i], cur.second+dy[i])) {
                q.emplace(cur.first+dx[i], cur.second+dy[i]);
                graph[cur.first+dx[i]][cur.second+dy[i]] = 1;
                dst[cur.first+dx[i]][cur.second+dy[i]] = dst[cur.first][cur.second] + 1;

                pr[cur.first+dx[i]][cur.second+dy[i]].first = cur.first;
                pr[cur.first+dx[i]][cur.second+dy[i]].second = cur.second;
            }
        }
    
    }
    
}



int main() {
    cin >> n >> x1 >> y1 >> x2 >> y2;

    dfs(x1-1, y1-1);
}