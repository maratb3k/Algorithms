#include<bits/stdc++.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "русский");
    ifstream file(C:\Users\ромашка\Desktop\c++\lab1\"class.txt")

    vector<pair<int, string>> v;
    if(!file)
        return 1;
    else
    {
        int n = sizeof(a)/sizeof(a[0]);
        for (int i=0; i<n; i++) 
            v.push_back( make_pair(a[i],b[i]));
        sort(v.begin(), v.end());  
        for (int i=0; i<n; i++) 
        { 
            cout << v[i].first << " "
             << v[i].second << endl; 
        }  
    }
    
    file.close();
}

