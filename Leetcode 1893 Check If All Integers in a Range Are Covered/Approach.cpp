Aamar 2 ta pointer ase left, right ar 1 ta array ase 2-D integer er.Amar check korte hbe array te integer ranges [left,right] er moddhe kina.
Ami first e 1 ta function crete kori vector typr ja left r right er moddhe integer print kore vector ans e push kore
vector<int> rangesinteger(int left,int right)
{
    vector<int>ans;
    for(int i=left;i<=right;i++)
    {
        ans.push_back(i);
    }
    return ans;
}
main function e aro 1 ta vector create kori c name e jate rakhbo left to rght range er number gula eta main function e call kori
 vector<int> c=  rangesinteger( left, right);

1 ta for loop chalai i=0 to ranges.size() porjonto ranges hoilo given array
nested for loop chalai j=0 to ranges.size() porjonto 
duita for chalai nested karon eta 2-D array.
  bound check j range er moddhe ase kina
 if(ranges[j][0]<=c[i]&&c[i]<=ranges[j][1])
                {
                    //cover=true;
                     currentCovered = true;
                    break;

                }
return kori cover.

  Full code:
----------
  class Solution {
public:
vector<int> rangesinteger(int left,int right)
{
    vector<int>ans;
    for(int i=left;i<=right;i++)
    {
        ans.push_back(i);
    }
    return ans;
}
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        bool cover=true;
      vector<int> c=  rangesinteger( left, right);
        for(int i=0;i<c.size();i++)
        {
             bool currentCovered = false;
            for(int j=0;j<ranges.size();j++)
            {
                if(ranges[j][0]<=c[i]&&c[i]<=ranges[j][1])
                {
                    //cover=true;
                     currentCovered = true;
                    break;

                }
            }
             if (!currentCovered) 
             {
                cover = false;
                break;
            }
        }
        return cover;
    }
};
