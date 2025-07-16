class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
{
        int low=1;
        int high=arr.size()-2;
        int ans=-1;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if((arr[mid]>arr[mid-1])&&(arr[mid]>arr[mid+1]))
                   {
                ans= mid;
                    break;
                    
                   }
                if(arr[mid]<arr[mid+1])
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
                
            }
        return ans;
    }
};
