class Solution 
{
public:
    bool TestEqual(string a)
    {
        unordered_map<char,int>freq;
        for(int i=0;i<a.size();i++)
            {
                freq[a[i]]++;
            }
        vector<char>v;
        bool test=false;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        for(auto it:freq)
            {
        if(v.size()==1&&it.second==a.size())
        {
            test=true;
            break;
        }
            }
        return test;
    }
    bool hasSameDigits(string s)
    {
        while(s.size()>2)
            {
                string temp="";
                for(int j=0;j+1<(int)s.size();j++)
                    {
                        
        char digit=((s[j]-'0')+(s[j+1]-'0'))%10+'0';
                            temp.push_back(digit);
                    
                        
                        
            }
                s=temp;
            }  
            
                bool same=false;
                if(TestEqual(s))
                {
                    same=true;
                }
        return same;
    }
};
