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
    int getMax(){
        return a[0];
    }
    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        cout << i + 1 << endl;
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
            i = j;
            a[i] = a[j];
        }
    
        else cout << j + 1 << " ";
    }
    void heapify2(int i) {
        int j = i;
        if (left(i) < a.size() && a[j] < a[left(i)])
            j = left(i);
        if (right(i) < a.size() && a[j] < a[right(i)])
            j = right(i);
        if (j!=i) {
            swap(a[i], a[j]);
            heapify(j);
            i = j;
            a[i] = a[j];
        }
    
    }

    void extractMax() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        if(a.size() > 0)
            cout << root_value << endl;
        if(a.size() == 0)
            cout << 0 << " " << root_value << endl;
    }
    void deleteel(int i){
        int el = a[i];
        swap(a[i], a[a.size() - 1]);
        a.pop_back();
        if (i > 0 && a[i] > a[parent(i)]) {
           siftUp(i);
        } 
        else 
            heapify2(i);
        cout << el << endl;
    
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
    int size(){
        return a.size();
    }
};

int main() {
    int n, cnt, x, number;
    cin >> n >> cnt;
    MaxHeap *heap = new MaxHeap();
    for (int j = 0; j < cnt; j++) {
        cin >> number;
        if(number == 1)
        {
           if(heap->size() == 0)
                cout << -1 << endl;
            else    
                heap->extractMax();
        }
        if(number == 2)
        {   
            cin >> x;
            if(heap->size() == n)
                cout << -1 << endl;
            else
                heap->insert(x);
        }
        if(number == 3){
            cin >> x;
            if(heap->size() < x)
                cout << -1 << endl;
            else
                heap->deleteel(x - 1);
            
        }
        
    }  
    heap->coutheap();
    return 0;
}