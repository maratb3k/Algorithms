#include<iostream>
#include<deque>
using namespace std;

int main()
{
    int cnt = 0, x;
    deque<int> d, d1;
    for(int i = 0; i < 5; i++){
        cin >> x;
        d.push_back(x);
    }
    for(int i = 0; i < 5; i++)
    {
        cin >> x;
        d1.push_back(x);
    }
    while(cnt != 1000000)
    {
        if ((d.size() == 0) or (d1.size() == 0))
            break;
        
        if(d.front() == 0 && d1.front() == 9){
            int a = d.front();
            d.pop_front();
            int b = d1.front();
            d1.pop_front();
            d.push_back(a);
            d.push_back(b);
        }
        else if(d.front() == 9 && d1.front() == 0){
            int a = d.front();
            d.pop_front();
            int b = d1.front();
            d1.pop_front();
            d1.push_back(a);
            d1.push_back(b);
        }

        else if(d.front() > d1.front())
        {
            int a = d.front();
            d.pop_front();
            int b = d1.front();
            d1.pop_front();
            d.push_back(a);
            d.push_back(b);
        }
        else if(d.front() < d1.front()){
            int a = d.front();
            d.pop_front();
            int b = d1.front();
            d1.pop_front();
            d1.push_back(a);
            d1.push_back(b);
        }    
        cnt++;
        
    }
    if(cnt == 1000000)
        cout << "botva";    
    if(d.size() == 0)
    {
        cout << "second " << cnt; 
    }
    else
    {
        cout << "first " << cnt;
    }
    

}