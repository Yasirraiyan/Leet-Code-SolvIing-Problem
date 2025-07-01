class Solution
{
public:
    int findmax(vector<int>&arr)
    {
        int max=arr[0];
        for(int j=1;j<arr.size();j++)
            {
                if(arr[j]>max)
                {
                    max=arr[j];
                }
            }
        return max;
    }
    int pairSum(ListNode* head) 
    {
        vector<int>v;
        while(head!=nullptr)
            {
                v.push_back(head->val);
                head=head->next;
            }
        vector<int>vv(v.size(),0);
        for(int i=0;i<v.size();i++)
            {
                vv[i]=v[i]+v[v.size()-i-1];
            }
        int ans=findmax(vv);
        return ans;
    }
};
