class Solution 
{
public:
    int findmax(vector<int>&v)
    {
        int max=v[0];
        for(int i=1;i<v.size();i++)
            {
                if(v[i]>max)
                {
                    max=v[i];
                }
            }
        return max;
    }
    int findmin(vector<int>&v)
    {
        int min=v[0];
        for(int j=1;j<v.size();j++)
            {
                if(v[j]<min)
                {
                    min=v[j];
                }
            }
        return min;
    }
    double findavg(vector<int>&v)
    {
        int min=findmin(v);
        int max=findmax(v);
        double avg=(min+max)/2.0;
        return avg;
    }
    int distinctAverages(vector<int>& nums)
    {
        vector<double>vv;
        int n=nums.size();
         while(!nums.empty())
             {
                 int min=findmin(nums);
                 int max=findmax(nums);
                 double avg=(min+max)/2.0;
                 vv.push_back(avg);
                 nums.erase(std::find(nums.begin(),nums.end(),min));
                 nums.erase(std::find(nums.begin(),nums.end(),max));
             }
        unordered_map<double,int>freq;
        for(int k=0;k<vv.size();k++)
            {
                freq[vv[k]]++;
            }
        vector<double>v;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        int ans=v.size();
        return ans;
    }
};
