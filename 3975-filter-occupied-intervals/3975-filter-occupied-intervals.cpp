class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

vector<vector<int>> merged;
for(auto& interval : occupiedIntervals){
    if(!merged.empty() && interval[0]<=merged.back()[1]+1)
        merged.back()[1] = max(merged.back()[1], interval[1]);
    else
        merged.push_back(interval);
}

vector<vector<int>> result;
for(auto& interval : merged){
    if(interval[1]<freeStart || interval[0]>freeEnd){
        result.push_back(interval);
    } else {
        if(interval[0]<freeStart) result.push_back({interval[0], freeStart-1});
        if(interval[1]>freeEnd) result.push_back({freeEnd+1, interval[1]});
    }
}
return result;
    }
};