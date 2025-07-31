class Solution
{
public:
    int divisorSubstrings(int num, int k) 
    {
        string nums=to_string(num);
       vector<string>v;
        for(int i=0;i<=nums.size()-k;i++)
            {
                v.push_back(nums.substr(i,k));
            }
        int beauty=0;
        for(int j=0;j<v.size();j++)
            {
                int val=stoi(v[j]);
                if(val!=0&&num%val==0)
                {
                    beauty++;
                }
            }
        return beauty;
    }
};
