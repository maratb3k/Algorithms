#include<iostream>
#include<vector>
using namespace std;

int lower_bound_bin_search(vector<int> &a, int k) {

    // a[x] >= k
    int l = 0; 
    int r = a.size() - 1;
    int res = -1;
    while (l < r)  {
        int m = (l + r) / 2;
        if (a[m] >= k) { 
            res = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (a[r] >= k)
        res = r;
    return res;
}

int upper_bound_bin_search(vector<int> &a, int k) {

    // a[x] > k
    int l = 0; 
    int r = a.size() - 1;
    int res = -1;
    while (l < r)  {
        int m = (l + r) / 2;
        if (a[m] > k) { 
            res = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (a[r] >= k)
        res = r;
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0;i < m; i++){
        cin >> k;
        int indexu = upper_bound_bin_search(a, k);
        int indexl = lower_bound_bin_search(a, k);
        if(indexl == -1)
            cout << 0 << endl;
        else 
            cout << indexl+1 << " " << indexu+1 << endl;    
    }
    
    return 0;
}