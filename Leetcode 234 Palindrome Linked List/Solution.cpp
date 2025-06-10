**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 #include<stack>
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<ListNode*>st;
        ListNode* current=head;
        while(current!=nullptr)
        {
          st.push(current);
          current=current->next;
        }
        string reserve="";
        while(!st.empty())
        {
          reserve+=to_string(st.top()->val);
          st.pop();
        }
        string reverese="";
        for(int i=reserve.size()-1;i>=0;i--)
        {
          reverese+=reserve[i];
        }
        bool ispalindrome=false;
        if(reverese==reserve)
        {
          ispalindrome=true;
        }
        return ispalindrome;
    }
};
