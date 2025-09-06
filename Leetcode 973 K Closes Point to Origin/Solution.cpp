class Solution {
public:
 int findDis(vector<int>&arr)
 {
    int d=arr[0]*arr[0]+arr[1]*arr[1];
    return d;
 }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
       auto cmp = [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
        return a.second > b.second; // smallest sum প্রথমে আসবে
    };

    // Step 2: Object বানানো
    priority_queue<
        pair<vector<int>, int>,              // pair<vector<int>, sum>
        vector<pair<vector<int>, int>>,      // underlying container
        decltype(cmp)                        // comparator type
    > minHeap(cmp);
for(auto &pt:points)
{
    minHeap.push({pt,findDis(pt)});
}
int count=0;
vector<vector<int>>ans;
while(count<k&&!minHeap.empty())
{
    ans.push_back(minHeap.top().first);
    minHeap.pop();
    count++;
    if(count==k) break;
   

}

return ans;
    }
};
