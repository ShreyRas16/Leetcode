class LFUCache {
public:
    int size=0;
    int all;
    struct Node{
        int value;
        int key;
        int freq=0;
        Node* prev;
        Node* next;
    };
    int minf=1;
    unordered_map<int,pair<Node*,Node*>> list;
    unordered_map<int,Node*> mp;
    LFUCache(int capacity) {
        all=capacity;
    }
    
    int get(int key) 
    {
        if(mp.contains(key)){
           Node* temp=mp[key];
           int x=temp->value;
            if(temp->prev==NULL && temp->next!=NULL){
            list[temp->freq].first=temp->next;
            list[temp->freq].first->prev=NULL;
            temp->next=NULL;
           } 
           else if(temp->next==NULL && temp->prev!=NULL){
            list[temp->freq].second=temp->prev;
            list[temp->freq].second->next=NULL;
            temp->prev=NULL;
           }
           else if(temp->next!=NULL && temp->prev!=NULL){
            Node* temp2=temp->prev;
            Node* temp3=temp->next;
            temp2->next=temp3;
            temp3->prev=temp2;
            temp->next=NULL;
            temp->prev=NULL;
           }
           else if(temp->prev==NULL && temp->next==NULL){
                list[temp->freq].first=NULL;
                list[temp->freq].second=NULL;
            }
            if(minf==temp->freq && list[temp->freq].first==NULL) minf++;
           temp->freq++;
           if(list.find(temp->freq) == list.end()) list[temp->freq] = {NULL, NULL};
           if(list[temp->freq].first==NULL){
            temp->next=NULL;
            temp->prev=NULL;
            list[temp->freq].first=temp;
            list[temp->freq].second=temp;
           }
           else{
            temp->next=list[temp->freq].first;
            temp->prev=NULL;
            list[temp->freq].first->prev=temp;
            list[temp->freq].first=temp;
           }
           return x;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(!mp.contains(key)){
        if(size==0){
            Node* temp=new Node;
            mp[key]=temp;
            temp->value=value;
            temp->key=key;
            temp->freq++;
            list[temp->freq].first=temp;
            list[temp->freq].second=temp;
            temp->next=NULL;
            temp->prev=NULL;
            size++;
            minf=1;
        }
        else{
            if(size!=all){
                Node* temp=new Node;
                mp[key]=temp;
                temp->value=value;
                temp->key=key;
                temp->freq++;
                size++;
                minf=1;
                 if(list[temp->freq].first==NULL){
            temp->next=NULL;
            temp->prev=NULL;
            list[temp->freq].first=temp;
            list[temp->freq].second=temp;
           }
           else{
            temp->next=list[temp->freq].first;
            temp->prev=NULL;
            list[temp->freq].first->prev=temp;
            list[temp->freq].first=temp;
           }
            }
            else{
                Node* temp3=list[minf].second;
                if(temp3->prev == NULL) list[minf].first = NULL;
                list[minf].second = temp3->prev;
                if(temp3->prev != NULL) temp3->prev->next = NULL;
                mp.erase(temp3->key);
                delete(temp3);
                Node* temp2=new Node;
                mp[key]=temp2;
                temp2->value=value;
                temp2->key=key;
                temp2->freq++;
                minf=1;
                if(list[temp2->freq].first==NULL){
                  temp2->next=NULL;
                  temp2->prev=NULL;
                  list[temp2->freq].first=temp2;
                  list[temp2->freq].second=temp2;
                }
               else{
                  temp2->next=list[temp2->freq].first;
                  temp2->prev=NULL;
                  list[temp2->freq].first->prev=temp2;
                  if(list[temp2->freq].first->next==NULL) list[temp2->freq].second=list[temp2->freq].first;
                  list[temp2->freq].first=temp2;
               }
            }
        }
        }
        else{
           Node* temp=mp[key];
           temp->value=value;
           if(minf==temp->freq && temp->next==NULL && temp->prev==NULL) minf++;
           if(temp->prev==NULL && temp->next!=NULL){
            list[temp->freq].first=temp->next;
            list[temp->freq].first->prev=NULL;
            temp->next=NULL;
           } 
           else if(temp->next==NULL && temp->prev!=NULL){
            list[temp->freq].second=temp->prev;
            list[temp->freq].second->next=NULL;
            temp->prev=NULL;
           }
           else if(temp->next!=NULL && temp->prev!=NULL){
            Node* temp2=temp->prev;
            temp2->next=temp->next;
            temp->next->prev=temp2;
            temp->next=NULL;
            temp->prev=NULL;
           }
           else if(temp->prev==NULL && temp->next==NULL){
                list[temp->freq].first=NULL;
                list[temp->freq].second=NULL;
            }
           temp->freq++;
           if(list[temp->freq].first==NULL){
            temp->next=NULL;
            temp->prev=NULL;
            list[temp->freq].first=temp;
            list[temp->freq].second=temp;
           }
           else{
            temp->next=list[temp->freq].first;
            temp->prev=NULL;
            list[temp->freq].first->prev=temp;
            list[temp->freq].first=temp;
           }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */