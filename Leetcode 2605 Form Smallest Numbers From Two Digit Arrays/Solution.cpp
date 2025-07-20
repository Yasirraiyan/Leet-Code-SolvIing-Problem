class Solution 
{
public:
 int findMin(const vector<int>& arr) 
 {
    int mini = arr[0]; // Assume first element is minimum

    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i] < mini) {
            mini = arr[i]; // Update if a smaller value is found
        }
    }

    return mini;
}
    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int>set1;
        vector<int>reserve;
        vector<int>v;
        int ans;
       
        for(int j=0;j<nums1.size();j++)
        {
          set1.insert(nums1[j]);
        }
        for(int k=0;k<nums2.size();k++)
        {
            if(set1.find(nums2[k])!=set1.end())
            {
                reserve.push_back(nums2[k]);
            }
            
          
        }
        if(!reserve.empty())
        {

        
      ans=findMin(reserve);
        }
        else{
        int a;
        int b;
        a=findMin(nums1);
         b=findMin(nums2);
      if(a<b)
      {
        ans=a*10+b;
      }
      else if(a>b)
      {
        ans=b*10+a;
      }
        }
      return ans;
    }
};
