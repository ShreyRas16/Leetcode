class Twitter {
public:
    Twitter() {
        
    }
    struct Node{
        int user;
        vector<pair<int,int>> tweet;
        vector<Node*> followers;
        vector<Node*> followee;
    };
    int time=0;
    vector<Node*> regist;
    void postTweet(int userId, int tweetId) {
        bool found=false;
        Node* temp=NULL;
        for(int i=0;i<regist.size();i++){
            if(regist[i]->user==userId){
                found=true;
                temp=regist[i];
            }    
        }
        if(!found){
            temp=new Node;
            temp->user=userId;
            temp->tweet.push_back({time,tweetId});
            regist.push_back(temp);
        }
        else temp->tweet.push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        bool found=false;
        Node* temp=NULL;
        for(int i=0;i<regist.size();i++){
            if(regist[i]->user==userId){
                found=true;
                temp=regist[i];
            }    
        }
        if(!found) return {};
        else{
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(int i=0;i<temp->tweet.size();i++){
                if(pq.size()<10) pq.push(temp->tweet[i]);
                else{
                    if(temp->tweet[i]>pq.top()){
                        pq.pop();
                        pq.push(temp->tweet[i]);
                    }
                }
            }
            for(int i=0;i<temp->followee.size();i++){
                for(int j=0;j<temp->followee[i]->tweet.size();j++){
                    if(pq.size()<10) pq.push(temp->followee[i]->tweet[j]);
                    else{
                        if(temp->followee[i]->tweet[j]>pq.top()){
                            pq.pop();
                            pq.push(temp->followee[i]->tweet[j]);
                        }
                    }
                }
            }
            vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
    }
    
    void follow(int followerId, int followeeId) {
        bool found=false;
        bool found2=false;
        Node* temp=NULL;
        Node* temp2=NULL;
        for(int i=0;i<regist.size();i++){
            if(regist[i]->user==followerId){
                found=true;
                temp=regist[i];
            }   
            if(regist[i]->user==followeeId){
                found2=true;
                temp2=regist[i];
            } 
        }
        if(!found){
            temp=new Node;
            temp->user=followerId;
            regist.push_back(temp);
        }
        if(!found2){
            temp2=new Node;
            temp2->user=followeeId;
            regist.push_back(temp2);
        }
        if(temp2!=temp){
            bool x=false;
            for(int i=0;i<temp->followee.size();i++) if(temp->followee[i]==temp2) x=true;
            if(!x){
              temp2->followers.push_back(temp);
              temp->followee.push_back(temp2);
            }
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        bool found=false;
        bool found2=false;
        Node* temp=NULL;
        Node* temp2=NULL;
        for(int i=0;i<regist.size();i++){
            if(regist[i]->user==followerId){
                found=true;
                temp=regist[i];
            }   
            if(regist[i]->user==followeeId){
                found2=true;
                temp2=regist[i];
            } 
        }
        if(found && found2 && temp2!=temp){
            bool found3=false;
            for(int i=0;i<temp2->followers.size();i++){
                if(temp2->followers[i]==temp){
                    found3=true;
                    temp2->followers.erase(temp2->followers.begin()+i);
                }
            }
            if(found3){
                for(int i=0;i<temp->followee.size();i++){
                    if(temp->followee[i]==temp2) temp->followee.erase(temp->followee.begin()+i);
                }
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */