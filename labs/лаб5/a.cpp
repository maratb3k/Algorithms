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

    void siftUp2(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        cout << i+1 << endl;
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void increaseKey(int i, int new_value) {
        i = i-1;
        a[i] += new_value;
        siftUp2(i);
    }

    void coutheap() {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }

};

int main() {
    int n, m, x, ind, value;
    cin >> n;
    MaxHeap *heap = new MaxHeap();
    for (int j = 0; j < n; j++) {
        cin >> x;
        heap->insert(x);
    }
    cin >> m;
    for (int j = 0; j < m; j++) { 
        cin >> ind >> value;
        heap->increaseKey(ind, value);        
    }      
    heap->coutheap();
    return 0;
}