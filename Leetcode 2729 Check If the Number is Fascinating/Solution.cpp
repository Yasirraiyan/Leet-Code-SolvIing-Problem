class Solution 
{
public:
    bool isFascinating(int n) 
    {
        string a=to_string(n);
        int p=2*n;
        string b=to_string(p);
        int q=3*n;
        string c=to_string(q);
        string require=a+b+c;
        unordered_map<char,int>freq;
        bool isfascinate=true;
        for(int i=0;i<require.size();i++)
        {
          freq[require[i]]++;
        }
        for(auto it:freq)
        {
           if (it.first < '1' || it.first > '9') 
           {
                isfascinate = false;
                break;
            }
          
          if(it.second!=1)
          {
            isfascinate=false;
            break;
          }
          
          
        }
        return isfascinate;
    }
};
