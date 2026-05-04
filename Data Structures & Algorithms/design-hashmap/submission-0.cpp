class MyHashMap {
public:
    MyHashMap() {
        for(int i = 0; i < 10000; i++){
            arr.push_back(std::make_shared<ListNode>(-1,-1));
        }
    }
    
    void put(int key, int value) {
        int hh = hash(key);
        std::shared_ptr<ListNode> chain = arr[hh];
        while(chain->next != nullptr){
            if(chain->next->key == key){
                chain->next->value = value;
                return;
            }
            chain = chain->next;
        }

        chain->next = std::make_shared<ListNode>(key,value);
    }
    
    int get(int key) {
        int ret = -1;
        std::shared_ptr<ListNode> chain = arr[hash(key)];
        while(chain->next != nullptr){
            if(chain->next->key == key){
                ret =  chain->next->value;
                break;
            }
            chain = chain->next;
        }
        return ret;
    }
    
    void remove(int key) {
        std::shared_ptr<ListNode> chain = arr[hash(key)];
        while(chain->next != nullptr){
            if(chain->next->key == key){
                chain->next = chain->next->next;
                break;
            }
            chain = chain->next;
        }
    }
private:
    struct ListNode{
        int key;
        int value;
        std::shared_ptr<ListNode> next;
        ListNode(){};
        ListNode(int key, int value): key{key}, value{value}, next{nullptr}{}
    };

    std::vector<std::shared_ptr<ListNode>> arr;

    int hash(int key){
        return key%10000;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */