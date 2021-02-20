#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, max = -1000, max2 = -1000, number;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> number;
        a.push_back(number);
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] > max)
            max = a[i];
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] > max2 && a[i] != max)
            max2 = a[i];
    }
    cout << max2;
}
