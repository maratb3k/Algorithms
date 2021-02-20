#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void heapel(){
        for (int i = 0; i < a.size(); i++) { 
        cout << a[i] << " "; 
        }       
    }
};

int main() {
    int n, x;
    cin >> n;
    MaxHeap *heap = new MaxHeap();
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    heap->heapel();
    
    return 0;
}