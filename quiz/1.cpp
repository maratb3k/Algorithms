#include <bits/stdc++.h> 
using namespace std;

int main(){
    int q;
    cin >> q;
    int n, x;
    vector<int> a;
    for (int i = 0; i < q; i++){
        cin >> n;
        if (n == 1){
            cin >> x;
            a.push_back(x);
        }
        else
            reverse(a.begin(), a.end());
    }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    return 0;
}