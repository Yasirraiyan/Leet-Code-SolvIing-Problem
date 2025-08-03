class Solution 
{
public:
    int findgcd(int a,int b)
    {
        int ans;
        while(b!=0)
            {
                int temp=b;
                b=a%b;
                a=temp;
            }
        return a;
    }
    int findfirst(int n)
    {
        vector<int>v;
        while(n>0)
            {
                int rem=n%10;
                v.push_back(rem);
                n=n/10;
            }
        reverse(v.begin(),v.end());
        int first=v[0];
        return first;
        
    }
    int findlast(int n)
    {
        vector<int>v;
        while(n>0)
            {
                int rem=n%10;
                v.push_back(rem);
                n=n/10;
            }
        reverse(v.begin(),v.end());
        int last=v[v.size()-1];
        return last;
        
    }
    int countBeautifulPairs(vector<int>& nums) 
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                    {
                        if(i!=j)
                        {
                            if(findgcd(findfirst(nums[i]),findlast(nums[j]))==1)
                            {
                                count++;
                            }
                        }
                    }
            }
        return count;
    }
};
