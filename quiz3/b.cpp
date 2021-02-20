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
    string s, check = "";
    cin >> s;
    int n, l, r;
    cin >> n;
    int number = 0;
    while(number < n){
        cin >> l >> r;
        int cnt = 0;
        for(int i = l - 1; i < r; i++){
            check += s[i];
        }
        string temp = check + "#" + s;
        vector<int> p = prefix_function(temp);
        for (int i = check.size() + 1; i < temp.size(); i++){
            if (p[i] == check.size())
                cnt++;
        }
        cout << cnt << endl;
        number++;
        check.clear();
    }
   
    return 0;
}
