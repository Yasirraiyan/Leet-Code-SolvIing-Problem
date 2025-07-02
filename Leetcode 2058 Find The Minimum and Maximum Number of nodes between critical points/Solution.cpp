class Solution
{
public:
    int findmax(vector<int>&arr)
    {
        int max=arr[0];
        for(int k=1;k<arr.size();k++)
            {
                if(arr[k]>max)
                {
                    max=arr[k];
                }
            }
        return max;
    }
    int findmin(vector<int>& arr)
{
    int min = arr[0];
    for(int k = 1; k < arr.size(); k++)
    {
        if(arr[k] < min)
        {
            min = arr[k];
        }
    }
    return min;
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>v;
        while(head!=nullptr)
            {
                v.push_back(head->val);
                head=head->next;
            }
        vector<int>cr;
        for(int i=1;i<v.size()-1;i++)
            {
                if(((v[i]>v[i-1])&&(v[i]>v[i+1]))||((v[i])<v[i-1])&&(v[i])<v[i+1])
                {
                    cr.push_back(i);
                }
            }
        if(cr.size()<2) return {-1,-1};
        vector<int>vv;
        for(int j=0;j<cr.size()-1;j++ )
            {
                vv.push_back(abs(cr[j]-cr[j+1]));
            }
        vector<int>ans;
        ans.push_back(findmin(vv));
        ans.push_back(cr.back()-cr.front());
        return ans;
    }
};
