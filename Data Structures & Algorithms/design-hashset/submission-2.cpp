class MyHashSet {
private:
    struct ListNode{
        int key;
        ListNode* next;
        ListNode(int k): key(k), next(nullptr) {}
    };
    vector<ListNode*> sett;

    int hash(int key){
        return key % sett.size();
    }
public:
    MyHashSet() {
        sett.resize(10000);
        for(auto& bucket: sett){
            bucket = new ListNode(0); //add dummy key
        }
    }

    void add(int key) {
        ListNode* curr = sett[hash(key)];
        while(curr->next){
            if(curr->next->key == key){ // if we already have found the key
                return;
            }
            curr = curr->next;
        }

        curr->next = new ListNode(key);
    }

    void remove(int key) {
        ListNode* curr = sett[hash(key)];
        while(curr->next){
            if(curr->next->key == key){
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }

    bool contains(int key) {
        ListNode* curr = sett[hash(key)];
        while(curr->next){
            if(curr->next->key == key){
                return true;
            }
            curr = curr->next;
        }

        return false;
    }
};