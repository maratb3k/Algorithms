#include<iostream>
#include<stack>
using namespace std;


int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else {
            if (st.empty())
            {
                cout << "no";
                break;
            }
            if (s[i] == '}' && st.top() != '{')
            {
                cout << "no";
                break;
            }
            if (s[i] == ']' && st.top() != '[')
            {
                cout << "no";
                break;
            }
            if (s[i] == ')' && st.top() != '(')
            {
                cout << "no";
                break;
            }
            st.pop();                
        }
    }
    if(st.empty())
        cout << "yes";
} 