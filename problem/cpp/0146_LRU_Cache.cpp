// 本程序只是Leetcode风格 + 高粒度互斥锁 不能作为工程级别的项目
class LRUCache {
private:

    struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k,int v) : key(k), value(v), prev(nullptr), next(nullptr){}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    std::mutex mutex_;
public:
    LRUCache(int capacity) : cap(capacity){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        std::lock_guard<std::mutex> lk{mutex_};
        if(!mp.count(key)) return -1;
        Node *node = mp[key];
        move_to_tail(node);
        return node->value;
    }
    
    void put(int key, int value) {
        std::lock_guard<std::mutex> lk{mutex_};
        if(mp.count(key)){
            Node *old = mp[key];
            move_to_tail(old);
            old->value = value;
        }
        else {
            if(cap == mp.size()) {
                Node *old = head->next;
                remove(old);
                mp.erase(old->key);
            }
            Node *node = new Node(key, value);
            add_to_tail(node);
            mp[key] = node;
        }
    }
private:
    void move_to_tail(Node *node) {
        remove(node);
        add_to_tail(node);
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add_to_tail(Node *node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */