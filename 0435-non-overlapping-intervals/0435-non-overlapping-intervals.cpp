class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>>temp;
        for(int i=0;i<start.size();i++){
            temp.push_back({end[i],start[i]});
        }
        sort(temp.begin(),temp.end());
        int ans=1;//kyunki hum 1 meeting toh krwa hi skte hai
        int last=temp[0].first;
        for(int i=1;i<start.size();i++){
            if(temp[i].second>=last){ 
                ans++;
                last=temp[i].first;
            }
        }
        return ans;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int>start,end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        return intervals.size()-maxMeetings(start,end);
        
    }
};
