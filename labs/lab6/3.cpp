#include <iostream>
#include <vector>

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
    string s, t;
    cin >> s >> t;
    string temp = s + "#" + t + t;
    int n = t.size();
    vector<int> p = prefix_function(temp);
    for (int i = n + 1; i < temp.size(); i++) {
        if (p[i] == n) {
            cout << i - n - n;
            return 0;
        }
    }
    cout << -1;
}