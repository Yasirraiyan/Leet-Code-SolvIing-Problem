class Solution 
{
public:
    int reverseBits(int n)
     {
        vector<int>v(32,0);
        int idx=0;
        while(n>0)
        {
          v[idx]=n%2;
         // v.push_back(rem);
          n=n/2;
          idx++;
          
        }
        reverse(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
          ans+=pow(2,i)*v[i];
        }
        return ans;
    }
};
