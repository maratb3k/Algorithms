#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100000];
bool used[100000];
int dst[100000];
int pr[100000];   //имя prev уже используется библиотекой, поэтому назовём массив pr
int n, k, h;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }
    cin >> k >> h;
    k--;
    h--;

    for (int i = 0; i < 100000; i++) {
        dst[i] = -1;
    }

    queue<int> q;
    q.push(k);
    used[k] = true;
    dst[k] = 0;
    pr[k] = -1;   //Пометка, означающая, что у вершины k нет предыдущей.

    while (!q.empty()) {
        int cur = q.front();
        // cout << cur << endl;
        if (cur == h) {
            cout <<  dst[cur] << endl; break;
        }

        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (!used[i] && graph[cur][i]) {
                q.push(i);
                used[i] = true;
                dst[i] = dst[cur] + 1;
                pr[i] = cur;   //сохранение предыдущей вершины
            }
        }
        
        
    }

    //Восстановим кратчайший путь до вершины h (которую, предполагается, мы уже ввели)
    //Для восстановления пути пройдём его в обратном порядке, начиная с j, и развернём.

    if (dst[h] == -1 ) { cout << -1; return 0; }
    if (h == k) return 0;

    vector<int> path;

    int cur = h;         //текущая вершина пути
    path.push_back(cur);

    while (pr[cur] != -1) {   //пока существует предыдущая вершина
        cur = pr[cur];        //переходим в неё
        path.push_back(cur);    //и дописываем к пути
    }

    reverse(path.begin(), path.end());

    // cout << "Shortest path between vertices " << k + 1 << " and " << h + 1 << " is: " << endl;

    for (int v: path) {
        cout << v + 1 << " ";
    }
}