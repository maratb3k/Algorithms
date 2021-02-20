#include<iostream>
#include<stack>
using namespace std;

bool check(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else {
            if (st.empty() or (str[i] == '}' && st.top() != '{') or (str[i] == ']' && st.top() != '[') or (str[i] == ')' && st.top() != '('))
                return false;
            st.pop();                
        }
    }
    return (st.empty());
}

int main() {
    string str;
    cin >> str;
    if (check(str))
        cout << "yes";
    else
    {
        cout << "no";
    }

    return 0;
} 