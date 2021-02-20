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

    void heapify(int i,int x) {
        a[i]=x;
        int j = i;
        if (left(i) < a.size() && a[j] < a[left(i)])
            j = left(i);
        if (right(i) < a.size() && a[j] < a[right(i)])
            j = right(i);
        if (j!=i) {
            swap(a[i], a[j]);
            heapify(j,a[j]);
        }
    
        else cout << j + 1 << endl;
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
    void coutheap() {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }
};

int main() {
    int n, x, m, ind, value;
    cin >> n;
    MaxHeap *heap = new MaxHeap();
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    cin >> m;
    for (int j = 0; j < m; j++) { 
        cin >> ind >> value;
        heap->heapify(ind-1, heap->a[ind-1]-value);        
    }          

    heap->coutheap();
    return 0;
}