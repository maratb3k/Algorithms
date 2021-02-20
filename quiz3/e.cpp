#include <iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i]){
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main() {
    string s, sub = "";
    cin >> s;
    int cnt = 0;
    vector<int> p = prefix_function(s);
    for(int i = s.size() - p[s.size() - 1]; i < s.size(); i++){
        sub += s[i];
    }
    for(int i = 0; i < s.size(); i++){
        string s1 = s.substr(i, sub.size());
        if(s1 == sub)
            cnt++;
    }
    if(cnt >= 3)
        cout << sub;
    else    
        cout << "Just a legend";
    
    return 0;
}