✅ Step-by-step বোঝা — প্রশ্ন পড়ে কীভাবে চিন্তা করতে পারো:

প্রশ্নটা বুঝে প্রথমে কিছু বিষয় মাথায় রাখো:

লিংকড লিস্টে মধ্যের নোড খুঁজতে হবে।

যদি odd length হয়, তাহলে সোজা মাঝখানেরটা (একটাই থাকবে)।

যদি even length হয়, তাহলে দুইটা মাঝখানের নোড থাকে — তখন দ্বিতীয়টা রিটার্ন করতে হবে।



---

✅ উদাহরণ ১:

Input: [1, 2, 3, 4, 5] → total = 5 (odd)

mid = 5 / 2 = 2 (0-based index)
=> Return index 2 → node value = 3
Output: [3, 4, 5] (because we return the pointer starting from node 3)


---

✅ উদাহরণ ২:

Input: [1, 2, 3, 4, 5, 6] → total = 6 (even)

mid = (6 + 1) / 2 = 3 (0-based index)
=> Return index 3 → node value = 4
Output: [4, 5, 6]


---

✅ তুমি যেভাবে চিন্তা করেছো তোমার কোডে:

int low = 0;
vector<ListNode*> reserve;
while(head != nullptr)
{
    reserve.push_back(head);
    head = head->next;
}

🔸 এখানে তুমি একটা ভেক্টর reserve বানাও, যেখানে প্রতিটা লিংকড লিস্টের ListNode* পয়েন্টার রাখো।

🔸 মানে, পুরো লিংকড লিস্টকে তুমি array-এর মতো access করতে পারো reserve[0], reserve[1], ...


---

int high = reserve.size() - 1;
int mid;
if(reserve.size()%2 != 0)
{
    mid = reserve.size() / 2;
}এখানে তুমি লিংকড লিস্টের size চেক করো – odd নাকি even।

যদি odd হয় → mid = size / 2 → যেমন 5 হলে 5 / 2 = 2

যদি even হয় → mid = (size + 1) / 2 → যেমন 6 হলে (6+1)/2 = 3


📌 0-based index এ এইভাবে করলে সঠিক second middle পাবে।


---

return reserve[mid];

🔸 অবশেষে তুমি reserve[mid] রিটার্ন করো → যেটা একটা ListNode* পয়েন্টার → মানে, সেই নোড থেকে শুরু করে বাকি লিস্ট।


---

✅ কেন তোমার কোড Accepted হয়েছে?

কারণ:

1. তুমি পুরো লিংকড লিস্ট একটা ভেক্টরে store করেছো → O(n) time & O(n) space।


2. তারপর size দেখে সঠিকভাবে মিডল ইন্ডেক্স বের করেছো (সেকেন্ড মিডলও ঠিকঠাক)।


3. অবশেষে সেই নোড পয়েন্টার রিটার্ন করেছো → যা লিস্টের বাকি অংশ দেখায়।




---

✅ Sample Test:

ListNode* head = new ListNode(1,
    new ListNode(2,
    new ListNode(3,
    new ListNode(4,
    new ListNode(5)))));

Solution s;
ListNode* mid = s.middleNode(head);

// Output: mid->val = 3
// Print: 3 -> 4 -> 5


---

✅ বোঝা যাচ্ছে এই approach একদম ঠিক কাজ করে।

তবে চাইলে তুমি Floyd's slow-fast pointer টেকনিক ব্যবহার করে আরো efficient ভাবে (O(1) space) এটা
Full Code:
-------------
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        int low=0;
        vector<ListNode*>reserve;
        while(head!=nullptr)
            {
                reserve.push_back(head);
                head=head->next;
            }
        int high=reserve.size()-1;
        int mid;
        if(reserve.size()%2!=0)
        {
           mid=reserve.size()/2;
               
            
        }
        else
        {
            mid=(reserve.size()+1)/2;
        }
        
    
        return reserve[mid];
    }
};
