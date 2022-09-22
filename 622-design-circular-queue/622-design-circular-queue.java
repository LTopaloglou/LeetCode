class MyCircularQueue {
    int[] list;
    int size;
    int cap;
    int pointer;
    
    public MyCircularQueue(int k) {
        cap = k;
        list = new int[cap];
        size = 0;
        pointer = 0;
    }
    
    public boolean enQueue(int value) {
        if (size < cap) {
            list[(pointer+size)%cap] = value;
            ++size;
            return true;
        }
        return false;
    }
    
    public boolean deQueue() {
        if (size == 0) {
            return false;
        }
        pointer = (pointer+1)%cap;
        --size;
        return true;
    }
    
    public int Front() {
        if (size == 0) {
            return -1;
        }
        return list[pointer];
    }
    
    public int Rear() {
        if (size == 0) {
            return -1;
        }
        return list[(pointer+size-1)%cap];
    }
    
    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
    
    public boolean isFull() {
        if (size == cap) {
            return true;
        }
        return false;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */