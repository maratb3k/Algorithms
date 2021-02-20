#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n);  
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p = prefix_function(s);
    int k = n - p[s.size() - 1];
    if (n % k == 0)
        cout << n / k;
    else
        cout << 1;
}