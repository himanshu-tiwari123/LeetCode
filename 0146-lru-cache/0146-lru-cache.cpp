struct Node{
   int key;
   int value;
   Node *next,*prev;

   Node(int key,int value){
    this->key = key;
    this->value = value;
    next = NULL;
    prev = NULL;
   }
};
class LRUCache {
    map<int,Node*>mp;
    Node *head,*tail;
    int capacity;

    void deleteNode(Node *node){
       Node *prevNode = node->prev;
       Node *nextNode = node->next;

       prevNode->next = nextNode;
       nextNode->prev = prevNode;


    //    delete node;
    }

    void insertAfterHead(Node *node){
        Node *nextNode = head->next;
        head->next = node;
        node->prev =head;

        nextNode->prev  = node;
        node->next = nextNode;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        //also we need to initialize list with head and tail;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            //the key exists:
            Node *node = mp[key];
            int val = node->value;
            deleteNode(node);
            insertAfterHead(node);
            return val;
           
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        //first we will check if key exists:
        if(mp.find(key)!= mp.end()){
            //we need to update the value:
            Node *node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            // we need to place it in cache,but first check if capacity is full or not:
            if(mp.size() == capacity){
                //we need to remove the LRU cache:
                Node *LRUnode = tail->prev;
                mp.erase(LRUnode->key);
                deleteNode(LRUnode);
            }
            Node *newNode = new Node(key,value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */