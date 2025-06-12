/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        //stack<ListNode*>st2;
        while(head!=nullptr)
        {
          st.push(head);
          head=head->next;
        }
         if (st.empty()) return nullptr;

        // Pop from stack to build reversed list
        ListNode* newHead = st.top();
         st.pop();
        ListNode* current = newHead;

        while (!st.empty())
         {
            current->next = st.top();
            st.pop();
            current = current->next;
        }

        // Last node should point to nullptr
        current->next = nullptr;

        return newHead;
       
    }
};
