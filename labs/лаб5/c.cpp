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
    int getMax() {
        return a[0];
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

    void heapify(int i) {
        int j = i;
        if (left(i) < a.size() && a[j] < a[left(i)])
            j = left(i);
        if (right(i) < a.size() && a[j] < a[right(i)])
            j = right(i);
        if (j!=i) {
            swap(a[i], a[j]);
            heapify(j);

        }
    
        else cout << j + 1 << " ";
    }


    void extractMax() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0){
            heapify(0);
            cout << root_value << endl;
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
    
    for (int i = 0; i < n; i++) { 
        heap->extractMax();        
    }
    return 0;
}