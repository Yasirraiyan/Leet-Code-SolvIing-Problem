class Solution
{
public:
    string triangleType(vector<int>& nums) 
{
        unordered_map<int,int>freq;
        string ans="";
        for(int i=0;i<nums.size();i++)
            {
                freq[nums[i]]++;
            }
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(a+b<=c||b+c<=a||c+a<=b)
        {
            return "none";
            //return ans;
        }
        bool three=false;
        bool two=false;
        for(int j=0;j<nums.size();j++)
            {
                if(freq[nums[j]]==3)
                {
                   /* ans=*///return "equilateral";
                    three=true;
                }
                else if(freq[nums[j]]==2)
                {
                    /*ans=*///return "isosceles";
                    two=true;
                }
            }
        if(three) 
        {
          ans= "equilateral";
        }
       else if(two) 
       {
         ans= "isosceles";
       }
        else 
       {
         ans="scalene";
       }
       return ans;
}
    
};
