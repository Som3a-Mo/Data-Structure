#include <bits/stdc++.h>

using namespace std;

// implementation of priority queue using MAX Heap 

template<class T>
class priority_queue<T> {
    vector<T> pq;
    int sz;

    void heapify(int i) {
        int s = i;
        int lc = left_child(i);
        int rc = right_child(i);
        if (lc < sz && pq[lc] > pq[s]) s = lc;
        if (rc < sz && pq[rc] > pq[s]) s = rc;
        if (s != i) {
            swap(pq[i], pq[s]);
            heapify(s);
        }
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left_child(int i) {
        return (i * 2 + 1);
    }

    int right_child(int i) {
        return (i * 2 + 2);
    }

public:
    priority_queue() {
        sz = 0;
    }

    bool isEmpty() {
        return !sz;
    }

    void enqueue(T val) {
        pq.push_back(val);
        sz++;
        int cur = sz - 1;
        while (cur != 0 && pq[parent(cur)] < pq[cur]) {
            swap(pq[parent(cur)], pq[cur]);
            cur = parent(cur);
        }
    }

    T top() {
        return pq[0];
    }

    T dequeue() {
        sz--;
        T val = pq[0];
        pq[0] = pq[sz];
        pq.pop_back();
        heapify(0);
        return val;
    }

};


int main() {
    priority_queue<int> priorityQueue;
    priorityQueue.enqueue(5);
    priorityQueue.enqueue(4);
    priorityQueue.enqueue(13);
    priorityQueue.enqueue(9);
    while (!priorityQueue.isEmpty()) {
        cout << priorityQueue.top() << " ";
        priorityQueue.dequeue();
    }
}
