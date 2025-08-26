class Solution
 {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<double>v;
        int low=0;
        int high=nums.size()-1;
        while(low<high)
        {
            double avg=(nums[low]+nums[high])/2.0;
            v.push_back(avg);
            low++;
            high--;
        }
        unordered_map<double,int>freq;
        for(int j=0;j<v.size();j++)
        {
            freq[v[j]]++;
        }
        vector<double>vv;
        for(auto it:freq)
        {
            vv.push_back(it.first);
        }
        int ans=vv.size();
        return ans;
    }
};
