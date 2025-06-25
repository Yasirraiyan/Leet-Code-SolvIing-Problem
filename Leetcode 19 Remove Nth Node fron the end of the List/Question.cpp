Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

Accepted
3,519,791/7.2M
Acceptance Rate
49.0%
C++




1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
⌄
⌄
⌄
⌄
⌄
⌄
⌄
⌄
⌄
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*>st;
        while(head!=nullptr)
            {
                st.push(head);
                head=head->next;
            }
        int count=0;
        vector<ListNode*>v;
        while(!st.empty())
            {
                ListNode* top=st.top();
               // v.push_back(top);
               
                count++;
                if(count!=n)
                {
                    v.push_back(top);
                        }
                st.pop();
                
            }
        if(v.empty())return nullptr;
        reverse(v.begin(),v.end());
        ListNode* headd=(v[0]);
        ListNode* curr=headd;
        for(int i=1;i<v.size();i++)
            {
  //  curr=new ListNode(v[i]);
                curr->next=v[i];
                
                curr=curr->next;
            }
        curr->next=nullptr;
        return headd;
    }
};

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
/*class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*>st;
        while(head!=nullptr)
            {
                st.push(head);
                head=head->next;
            }
        int count=0;
Saved
Testcase
1
2
3
4
5
6
[1,2,3,4,5]
2
[1]
1
[1,2]
1
3/8 testcases
Line 1
Case 1: head

Submission Result
Accepted
208 / 208 testcases passed
submitted at Jun 25, 2025 16:46

Copyright © 2025 LeetCode. All rights reserved.

20.1K


264

