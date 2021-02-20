#include<iostream>
#include<vector>
using namespace std;

bool bin_search(vector<int> &a, int x){
    int l = 0;
    int r = a.size() - 1;
    while(l - 1 < r)
    {
        int m = (l + r) / 2;
        if(a[m] == x){
            return true;
            
        }
        else if(a[m] > x)
            r = m - 1;
        else    
            l = m + 1;
    
    }
    return false;
}


int main()
{
    int n, k, x;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < k; i++)
    {
        cin >> x;       
        if(bin_search(a, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }   
}