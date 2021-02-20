#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int first, second;
    int cnt1 = 0, cnt2 = 0;
    deque<int> d1;
    deque<int> d2;
    deque<int>::iterator it;
    while(true)
    {
        cin >> first;
        cin >> second;
        d1.push_back(first);
        d2.push_back(second);
        if(d1.size() == 0 || d2.size() == 0)
            break;
        else if((d1.front()>0 && d1.front() < 9) && (d2.front()>0 && d2.front()<9))
        {
            if(d1.front() > d2.front())
            {
                d1.push_back(d2.front());
                d2.erase(d2.begin(), d2.begin() + 1);
                cnt1++;
            }
            else{
                d2.push_back(d1.front());
                d1.erase(d1.begin(), d1.begin() + 1);
                cnt2++;
            }
        }
        else
        {
            if(d1.front() == 0)
            {
                d1.push_back(d2.front());
                d2.erase(d2.begin(), d2.begin() + 1);
                cnt1++;
            }
            else
            {
                d2.push_back(d1.front());
                d1.erase(d1.begin(), d1.begin() + 1);
                cnt2++;
            }

        }
    }
    if(d1.size() == 0)
        cout << "second" << " " << cnt2;
    else
        cout << "first" << " " << cnt1;

}