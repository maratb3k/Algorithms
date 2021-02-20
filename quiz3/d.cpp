#include <iostream>
#include <vector>
#include<string>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> n >> s2;
    int cnt = 0;
    string temp = s1 + "#" + s2;
    vector<int> p = prefix_function(temp);
    for (int i = s1.size() + 1; i < temp.size(); i++){
        if (p[i] == s1.size())
            cnt++;
    }
    if(cnt >= n)
        cout << "YES";
    else    cout << "NO";
    return 0;
}