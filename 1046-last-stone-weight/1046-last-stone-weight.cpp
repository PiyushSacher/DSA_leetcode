class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //making a max heap
        priority_queue<int>pq;
        for (int i=0;i<stones.size();i++) pq.push(stones[i]);
        while(pq.size()>1){
            int heaviestStone=pq.top();
            pq.pop();
            int secondHeaviestStone=pq.top();
            pq.pop();
            int result=heaviestStone-secondHeaviestStone;
            if(result!=0) pq.push(result);
        }

        //test case, if [2,2] then we get op as 2 but ans is 0,so we have written if pq.empty() return 0;
        return pq.empty()?0:pq.top();
        
    }
};