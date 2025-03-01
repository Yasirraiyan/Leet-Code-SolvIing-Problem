class Solution 
{
public:
    bool hasAlternatingBits(int n) 
{
        vector<int>reserve;
        //bool alternating=false;
        bool alternating=true;
        while(n>0)
        {
          int rem=n%2;
          reserve.push_back(rem);
          n=n/2;
        }
        for(int i=0;i<reserve.size()-1;i++)
        {
          if(reserve[i]==reserve[i+1])
          {
            alternating= false;
            break;
          }
          
        }
        return alternating;
    }
};
