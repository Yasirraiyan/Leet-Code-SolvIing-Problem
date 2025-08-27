class Solution
 {
public:
    vector<int> diStringMatch(string s) 
    {
      int  n=s.size();
      vector<int>perm(n+1);
      //perm.push_back(s.size());
        int low=0;
        int high=n;
        for(int i=0;i<s.size();i++)
        {
       /// while(low<high)
       // {
          if(s[i]=='I')
          {
            perm[i]=low;
            low++;
           
          }
          if(s[i]=='D')
          {
            perm[i]=high;
            high--;
          }
       // }
        }
        perm[n]=low;
        return perm;
    }
};
