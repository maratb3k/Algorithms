#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, max = -1000, ind, a;
    vector<int> v;
    cin >> n;
    while(v.size() != n)
    {
        cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > max){
            max = v[i];
            ind = i;}
    }
}