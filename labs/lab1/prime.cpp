#include<iostream>

using namespace std;
bool isPrime = true;
void primes(int n){
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << "prime";
    else
        cout << "composite";
}

int main()
{
    int n;
    cin >> n;
    primes(n);
    return 0;
}