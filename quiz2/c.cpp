#include <bits/stdc++.h>

using namespace std;

void print(vector<char> v, vector<char> c){
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    for (int i = 0; i < c.size(); i++)
        cout << c[i];
}

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<char> v;
    vector<char> c;
    for (int i = 0; i < n; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            v.push_back(str[i]);
        else 
            c.push_back(str[i]);
    }
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());
    print(v, c);
}