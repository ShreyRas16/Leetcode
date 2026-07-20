class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        vector<int> news;
        int count=1;
        bool inc=true;
        for(int i=1;i<ratings.size();i++){
            if(count==1 && ratings[i]>ratings[i-1]) inc=true;
            else if(count==1 && ratings[i]<ratings[i-1]) inc=false;
           if(ratings[i]>ratings[i-1] && inc) count++;
           else if(ratings[i]<ratings[i-1] && !inc) count++;
           else if(ratings[i]<ratings[i-1] && inc){
             news.push_back(count);
             inc=false;
             count=2;
           }
           else if(ratings[i]>ratings[i-1] && !inc){
            news.push_back(-count);
            inc=true;
            count=2;
           }
           else if(ratings[i]==ratings[i-1]){
              if(inc) news.push_back(count);
              else news.push_back(-count);
              news.push_back(0);
              count=1;
           }
        }
        if (count>1 || (!news.empty() && news.back()==0)) {
           if(inc) news.push_back(count);
           else news.push_back(-count);
        }
        int sum=0;
        for(int i=0;i<news.size()-1;i++){
            if(news[i]>0 && news[i+1]<0){
                long long L=news[i]-1;
                sum=sum+ L*(L+1)/2;
                long long D=-news[i+1]-1;
                if(D>L) sum=sum+(D-L);
            }
            else if(news[i]>0 && news[i+1]==0) sum=sum+((news[i]*(news[i]-1))/2);
            else if(news[i]<0 && news[i+1]>0){
                sum=sum+(((abs(news[i])-2)*(abs(news[i])-1))/2);
                if(i==0 || news[i-1]<=0) sum=sum+abs(news[i])-1;
            }
            else if(news[i]<0 && news[i+1]==0){
                sum=sum+(((abs(news[i])-2)*(abs(news[i])-1))/2);
                if(i==0 || news[i-1]<=0) sum=sum+abs(news[i])-1;
            }
            else if(news[i]==0) continue;
        }
        if(!news.empty()){
            long long last=news[news.size()-1];
            if(last>0) sum=sum+((last-1)*last)/2;
            else if(last<0){
                sum=sum+((abs(last)-2)*(abs(last)-1))/2;
                if(news.size()<2 || news[news.size()-2]<=0) sum=sum+abs(last)-1;
            }
            else sum++;
        }
        return sum+ratings.size();
    }
};