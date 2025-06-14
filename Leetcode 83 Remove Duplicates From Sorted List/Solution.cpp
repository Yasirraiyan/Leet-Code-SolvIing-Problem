class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        
    vector<int> v;
        unordered_map<int,int>map1;
        vector<int>vv;
        while(head!=nullptr)
            {
                v.push_back(head->val);
                head=head->next;
            }
        for(int i=0;i<v.size();i++)
            {
                map1[v[i]]++;
            }
        for(auto it:map1)
            {
                vv.push_back(it.first);
            }
      sort(vv.begin(),vv.end());
        if(vv.size()==0)
        {
            return nullptr;
        }
        ListNode* headd=new ListNode(vv[0]);
       ListNode* current=headd;
        for(int j=1;j<vv.size();j++)
            {
            current->next=new ListNode(vv[j]);
              current=current->next;
            }
        return headd;
    }
};

// Utility function to create a linked list from vector


// Utility function to print linked list
