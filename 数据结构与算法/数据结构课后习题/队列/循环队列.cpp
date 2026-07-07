/*
假设将循环队列定义为：以域变量rear和length分别指示循环队列中的队尾元素的位置和内含元素的个数。
给出此循环队列的队满条件，并写出相应的入队列、出队列、遍历队列的算法（在出队列的算法中要返回对头元素）。
使用：少用一个 判断队空 队满
*/
#include <iostream>
using namespace std;
template <typename T>
class CircularQueue {
private:
    T* data;        
    int rear;       
    int length;     
    int maxSize;    
public:
     CircularQueue(int size) {
        maxSize = size;
        data = new T[maxSize];
        length = 0;
        rear = maxSize - 1; 
    }
    ~CircularQueue() {
        delete[] data;
    }
    bool isFull() {
        return length == maxSize;
    }
    bool isEmpty() {
        return length == 0;
    }
    bool enQueue(T x) {
        if (isFull()) {
            cout << "队满" << endl;
            return false;
        }
        rear = (rear + 1) % maxSize;
        data[rear] = x;
        length++;
        return true;
    }
    bool deQueue(T &x) {
        if (isEmpty()) {
            cout << "队空" << endl;
            return false;
        }
        int front = (rear - length + 1 + maxSize) % maxSize;
        x = data[front];
        length--;
        return true;
    }
    void Printquene() {
        if (isEmpty()) {
            cout << "队空" << endl;
            return;
        }
        cout << "当前队列元素: ";
        int front = (rear - length + 1 + maxSize) % maxSize;
        for (int i = 0; i < length; i++) {
            int currentPos = (front + i) % maxSize;
            cout << data[currentPos] << " ";
        }
        cout << endl;
    }
};
int main() {
    CircularQueue<int> q(5); 
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    q.Printquene(); 
    int val;
    if (q.deQueue(val)) {
        cout << "出队元素: " << val << endl; 
    }
    q.Printquene();
    return 0;
}