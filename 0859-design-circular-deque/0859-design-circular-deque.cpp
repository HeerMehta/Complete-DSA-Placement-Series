class MyCircularDeque {
public:

    int capacity = 0;
    int size;
    int rear;
    int front;
    vector<int> arr;

    MyCircularDeque(int k) {
        arr.resize(k);
        capacity = k;
        front = k-1;
        rear = 0;
        size = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        arr[front] = value;
        front = (front + capacity - 1)%capacity;
        size++;

        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        arr[rear] = value;
        rear = (rear + 1)%capacity;
        size++;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front+1)%capacity;
        size--;

        return true;
    }
    
    bool deleteLast() {
       if(isEmpty()) return false;

       rear = (rear + capacity -1)%capacity;
       size--;

       return true; 
    }
    
    int getFront() {
        if(isEmpty()) return -1;

        return arr[(front+1)%capacity];
    }
    
    int getRear() {
        if(isEmpty()) return -1;

        return arr[(rear + capacity - 1)%capacity];
    }
    
    bool isEmpty() {
       return size == 0; 
    }
    
    bool isFull() {
       return size == capacity; 
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */