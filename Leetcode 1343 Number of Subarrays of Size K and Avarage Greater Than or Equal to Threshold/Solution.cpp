class Solution 
{
public:
 
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
{
        int count=0;
        int sum=0;
        for(int i=0;i<k;i++)
        {
              sum+=arr[i];
        }
        if(sum/k>=threshold)
        {
            count++;
        }
        int suum=0;
        int windowsum=sum;
        vector<int>v;
        for(int j=k;j<arr.size();j++)
        {
           suum+=arr[j];
           windowsum=windowsum-arr[j-k]+arr[j];
           if((windowsum/k)>=threshold)
           {
            count++;
           }
        }
        return count;
    }
};
