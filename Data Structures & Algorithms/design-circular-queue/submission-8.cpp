class MyCircularQueue {
public:
    
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int v, ListNode* n = nullptr)
            : val(v), next(n) {}
    };

    ListNode* head = NULL;
    ListNode* tail = NULL;

    int i, size = 0;

    MyCircularQueue(int k) {
        i = k;
    }

    bool enQueue(int value) {

        if (size >= i)
            return false;

        if (head == NULL) {

            ListNode* newNode = new ListNode(value);

            head = newNode;
            tail = newNode;

            tail->next = head;

            size++;

            return true;
        }
        else {

            ListNode* newNode = new ListNode(value);

            tail->next = newNode;

            tail = tail->next;

            tail->next = head;

            size++;

            return true;
        }
    }

    bool deQueue() {

        if (size == 0)
            return false;

        if (head == tail) {

            ListNode* temp = head;

            head = NULL;
            tail = NULL;

            delete temp;

            size--;

            return true;
        }

        ListNode* temp = head->next;

        tail->next = temp;

        head->next = NULL;

        ListNode* x = head;

        head = temp;

        delete x;

        size--;

        return true;
    }

    int Front() {

        if (size == 0)
            return -1;

        return head->val;
    }

    int Rear() {

        if (size == 0)
            return -1;

        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == i;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 *
 * MyCircularQueue* obj = new MyCircularQueue(k);
 *
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */