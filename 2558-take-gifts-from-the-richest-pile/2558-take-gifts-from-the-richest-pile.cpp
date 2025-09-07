class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        //by default max heap
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();i++) pq.push(gifts[i]);
        long long res=0;
        while(k>0 && !pq.empty()){
            long long maxGifts=pq.top();
            pq.pop();
            if(sqrt(maxGifts)!=0) pq.push(sqrt(maxGifts));
            k--;
        }
        if(pq.empty()) return 0;
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
        
    }
};