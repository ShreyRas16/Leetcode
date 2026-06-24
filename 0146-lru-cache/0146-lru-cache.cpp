class LRUCache {
public:
    struct Node{
      int key;
      int value;
      Node* prev;
      Node* next;
    };
    unordered_map<int,Node*> mp;
    Node* head=NULL;
    Node* tail=NULL;
    int size=0;
    int all;
    LRUCache(int capacity) {
        all=capacity;
    }
    int get(int key) {
        if(mp.contains(key)){
            Node* temp=mp[key];
            if(temp->next==NULL && temp->prev!=NULL){
                tail=temp->prev;
                tail->next=NULL;
                temp->next=head;
                head->prev=temp;
                temp->prev=NULL;
                head=temp;
            }
            else if(temp->next!=NULL && temp->prev!=NULL){
                Node* temp2=temp->prev;
                temp2->next=temp->next;
                temp->next->prev=temp2;
                temp->next=head;
                head->prev=temp;
                temp->prev=NULL;
                head=temp;
            }
            return head->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(!mp.contains(key)){
        if(size==0){
            Node* temp=new Node;
            head=temp;
            tail=temp;
            head->next=NULL;
            head->prev=NULL;
            head->value=value;
            head->key=key;
            mp[key]=head;
            size++;
        }
        else{
            if(size<all){
                Node* temp=new Node;
                temp->next=head;
                head->prev=temp;
                temp->value=value;
                temp->key=key;
                temp->prev=NULL;
                head=temp;
                size++;
                mp[key]=head;
            }
            else{
                if(size==1){
                    mp.erase(tail->key);
                    delete head;
                    head=NULL;
                    tail=NULL;
                    Node* temp=new Node;
                    temp->key=key;
                    temp->value=value;
                    temp->next=NULL;
                    temp->prev=NULL;
                    head=temp;
                    tail=temp;
                    mp[key]=head;
                }
                else{
                mp.erase(tail->key);
                tail->prev->next = NULL;
                Node* temp=tail;
                tail=tail->prev;
                delete temp;
                Node* temp2=new Node;
                temp2->key=key;
                temp2->value=value;
                temp2->next=head;
                head->prev=temp2;
                temp2->prev=NULL;
                head=temp2;
                mp[key]=head;
            }
            }
        }
        }
        else{
            Node* temp=mp[key];
            temp->value=value;
            if(temp->next==NULL && temp->prev!=NULL){
                tail=temp->prev;
                tail->next=NULL;
                temp->next=head;
                head->prev=temp;
                temp->prev=NULL;
                head=temp;
            }
            else if(temp->next!=NULL && temp->prev!=NULL){
                Node* temp2=temp->prev;
                temp2->next=temp->next;
                temp->next->prev=temp2;
                temp->next=head;
                head->prev=temp;
                temp->prev=NULL;
                head=temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */