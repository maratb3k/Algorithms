#include<iostream>
#include<vector>

using namespace std;

int lower_bin_search(vector<int> &a, int k){
    int l = 1;
    int r = a.size();
    int res = 0;
    while(r >= l){
        int m = (r + l)/2;
        if(a[m] >= k){
            res = m;
            r = m - 1;
        }
        else
        l = m + 1;
    }
    if (a[res] == k)
        return res; 
    else
        return 0;
}
int upper_bin_search(vector<int> &a, int k){
    int l = 1;
    int r = a.size();
    int res = 0;
    while(r >= l){
        int m = (r + l)/2;
        if(a[m] <= k){
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if (a[res] == k)
        return res;
    else    return 0;
}

int main(){
    int n , m; 
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= m; i++)
        cin>>b[i];
    
    for(int i = 1; i <= m; i++){
        if(lower_bin_search(a, b[i]) == 0)
            cout << 0 << endl;

        else
            cout << lower_bin_search(a, b[i]) << " " << upper_bin_search(a, b[i]) << endl;
    }

}