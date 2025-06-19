class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_set<string>r;
        for(int i=0;i<list1.size();i++)
            {
                r.insert(list1[i]);
            }
        int min=INT_MAX;
        vector<string>reserve;
        for(int j=0;j<list2.size();j++)
            {
                if(r.find(list2[j])!=r.end())
                {
                    for(int i=0;i<list1.size();i++)
                        {
                            
                        if(list1[i]==list2[j])
                        {
                            int sum=i+j;
                            
                        if(sum<min)
                            {
                                
                            reserve.clear();
                    reserve.push_back(list2[j]);
                              
                              min=sum  ;
                            }
                            else if(sum==min)
                            {
                                reserve.push_back(list2[j]);
                            }
                            break;
                        }
                        }
                }
            }
        return reserve;           
    }
};
