#include <iostream>
using namespace std;

//最小堆实现优先级队列
template <typename T>
class PriorityQueue {
    T* min_heap;//最小堆元素存储数组
    int heap_size = 0;
    int heap_capacity = 1000000;    /*bug：越界*/

    void siftDown(int start, int m) {
        //从结点start开始到m为止, 自上向下比较, 
        //如果子女的值小于父结点的值,  则关键码小的上浮, 
        //继续向下层比较, 将一个集合局部调整为最小堆。
        int i = start,
            j = 2 * i + 1;//i的左子女
        T temp = min_heap[i];
        while (j <= m) {
            if (j < m && min_heap[j] > min_heap[j + 1])//让j指向两子女中的小者
                j++;
            if (temp <= min_heap[j])
                break;
            min_heap[i] = min_heap[j];
            i = j;
            j = 2 * j + 1;
        }
        min_heap[i] = temp;	      	//回放temp中暂存的元素
    };
    void siftUp(int start) {
        //私有函数: 从结点start开始到结点0为止, 自下向上
        //比较, 如果子女的值小于父结点的值, 则相互交换
        int j = start,
            i = (j - 1) / 2;
        T temp = min_heap[j];
        while (j > 0 && min_heap[i] > temp) {
            min_heap[j] = min_heap[i];
            j = i;
            i = (i - 1) / 2;
        }
        min_heap[j] = temp;
    }
public:
    PriorityQueue() { min_heap = new T[heap_capacity](); }

    PriorityQueue(T a[], int n) {
        min_heap = new T[heap_capacity]();
        for (int i = 0; i < n; i++)
            min_heap[i] = a[i];
        heap_size = n;

        for (int i = (heap_size - 2) / 2; i >= 0; i--)//i指向最后一个分支节点
            siftDown(i, heap_size - 1);
    }
    ~PriorityQueue() { delete[]min_heap; }

    void push(T& x) {
        if (heap_size == heap_capacity);    /*bug：堆满*/
        min_heap[heap_size] = x;
        siftUp(heap_size++);
    }
    void pop() {
        if (heap_size == 0);    /*bug：堆空*/
        min_heap[0] = min_heap[--heap_size];
        siftDown(0, heap_size - 1);
    }
    bool empty() const { return  heap_size == 0; }
    T size() const { return heap_size; }
    T top() const { return min_heap[0]; }
    void print()const {
        for (int i = 0; i < heap_size; i++)
            cout << min_heap[i] << ' ';
        cout << endl;
    }
};
