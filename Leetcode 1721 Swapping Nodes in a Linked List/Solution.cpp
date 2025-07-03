class Solution
 {
public:
  void swap(int &a,int &b)
  {
    int temp=a;
    a=b;
    b=temp;
  }
    ListNode* swapNodes(ListNode* head, int k) 
    {
        vector<int>v;
        while(head!=nullptr)
        {
          v.push_back(head->val);
          head=head->next;
        }
        if(v.size()==0) return nullptr;
        int temp1;
        int temp2;
        int idx1=-1;
        int idx2=-1;
        for(int i=0;i<v.size();i++)
        {
          if(i+1==k)
          {
            temp1=v[i];
            idx1=i;
            break;
          }
        }
        for(int j=v.size()-1;j>=0;j--)
        {
        if((v.size()-j==k))
          {
            temp2=v[j];
            idx2=j;
            break;
          }
        if(v.size()-j==k)
            {
              temp2=v[j];
              idx2=j;
              break;
            }
        }
        if(idx1 != -1 && idx2 != -1)
      {
          swap(v[idx1],v[idx2]);
      }
        ListNode* newHead=new ListNode(v[0]);
        ListNode* curr= newHead;
        for(int j=1;j<v.size();j++)
        {
          curr->next=new ListNode(v[j]);
          curr=curr->next;
        }
        return newHead;
    }
};
