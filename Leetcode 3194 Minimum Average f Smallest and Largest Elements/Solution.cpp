class Solution
 {
public:
double findmin(vector<double>&arr)
{
    double min=arr[0];
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]<min)
        {
            min=arr[j];
        }
    }
    return min;
}
    double minimumAverage(vector<int>& nums)
     {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        vector<double>v;
        while(low<high&&!nums.empty())
        {
            //nums.erase(nums.begin()+low);
            // nums.erase(nums.begin()+high);
             double avg=(nums[low]+nums[high])/2.0;
             v.push_back(avg);
             low++;
             high--;
             if(nums.empty()) break;
        }
        double ans=findmin(v);
        return ans;
    }
};
