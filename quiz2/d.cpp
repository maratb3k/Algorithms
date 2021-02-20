#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, max = -1000, max2 = -1000, max3 = -1000, number;
    cin >> n;
    vector<int> a;
    while(a.size() < n){
        cin >> number;
        a.push_back(number);
        if(a.size() < 3)
            cout << -1 << endl;
        else
        {
            for(int i = 0; i < a.size(); i++){
            if(a[i] > max)
                max = a[i];
            }
            for(int i = 0; i < a.size(); i++){
                if(a[i] > max2 && a[i] != max)
                    max2 = a[i];
            }
            for(int i = 0; i < a.size(); i++){
                if(a[i] > max3 && a[i] != max && a[i] != max2)
                max3 = a[i];
            }
            cout << max*max2*max3 << endl;
        }
    }
    return 0;
}
