class LRUCache {
public:
    unordered_map<int,int>m;
    int size,curr=0;
    struct Node
    {
        int val;
        Node* next;

        Node(int data)
        {
            val=data;
            next = NULL;
        }
    };
    Node* head=NULL;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            // int res=m[key];
            Node* temp=head;
            Node* prev=NULL;
            while(temp->val!=key)
            {
                prev=temp;
                temp=temp->next;
            }
            if(prev==NULL)
            {
                int x=m[temp->val];
                return x;
            }
            else
            {
                prev->next=temp->next;
                temp->next=head;
                head=temp;
                return m[temp->val];
            }
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // m[key]=value;
        if(m.find(key)==m.end())
        {
            m[key]=value;
            if(curr<size)
            {
                Node* newnode=new Node(key);
                newnode->next=head;
                head=newnode;
                m[key]=value;
                curr++;
                return;
            }
            else
            {
                Node* newnode=new Node(key);
                Node* temp=head;
                Node* prev=NULL;
                // m[key]=value;
                while(temp->next)
                {
                    prev=temp;
                    temp=temp->next;
                }
                if(prev==NULL)
                {
                    m.erase(temp->val);
                    delete temp;
                    head=newnode;
                    return;
                }
                else
                {
                    prev->next=NULL;

                    m.erase(temp->val);
                    delete temp;
                    newnode->next=head;
                    head=newnode;
                }
            }
        }
        else
        {
            m[key]=value;
            Node* temp=head;
            Node* prev=NULL;
            while(temp->val!=key)
            {
                prev=temp;
                temp=temp->next;
            }
            if(prev==NULL)return;
            else
            {
                prev->next=temp->next;
                temp->next=head;
                head=temp;
                return;
            }
        }
    }
};
