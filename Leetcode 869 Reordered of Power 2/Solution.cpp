class Solution 
{
public:
bool Valid(string s)
{
    return s[0]!='0';
}
bool TestPowerOfTwo(int n)
{
    bool test=false;
   if(n==1) return true;
   if (n <= 0) return false;  
while(n%2==0)
   {
    
    n/=2;
   }
   return n==1;
}
    bool reorderedPowerOf2(int n) 
    {
        if(n==1) return true;
        string a=to_string(n);
        sort(a.begin(), a.end());  
        vector<string>v;
        bool poss=false;
        do
        {
            v.push_back(a);
        }while(next_permutation(a.begin(),a.end()));
        vector<int>vv;
        for(int j=0;j<v.size();j++)
        {
            if(Valid(v[j]))
            {
               vv.push_back(stoi(v[j]));
            }
        }
      
for(int k=0;k<vv.size();k++)
{
    if(TestPowerOfTwo(vv[k]))
    {
        poss=true;
        break;
    }
}
return poss;
    }
};
