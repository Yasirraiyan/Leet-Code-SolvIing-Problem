🧠 প্রাথমিক বোঝাপড়া (Problem Understanding):

প্রশ্নে বলা হয়েছে, দুইটি singly linked list দেওয়া থাকবে — headA এবং headB। এগুলো কোনো এক জায়গা থেকে একসাথে মিলে যেতে পারে (intersect)। অর্থাৎ, একটি নির্দিষ্ট node থেকে তারা একই linked list হিসাবে চলতে পারে।

তুমি ওই common intersection node টা return করবে, যদি তারা intersect করে। আর যদি না করে, তাহলে return করবে nullptr বা null।

Example:

ListA: 4 → 1 → 8 → 4 → 5  
ListB: 5 → 6 → 1 ↘  
                  8 → 4 → 5

এইখানে 8 node থেকে দুইটা list একসাথে হয়ে গেছে। সুতরাং উত্তর হবে 8 এর pointer।


---

✅ কী চাই?

দুইটি linked list আছে।

যদি তারা কোনো common node এ intersect করে, ওই node return করতে হবে।

না করলে, nullptr return করতে হবে।



---

🔍 Approach বুঝি (Set দিয়ে Solution)

তুমি যে কোডটি করেছো, সেটা হলো:

> Approach 1: HashSet / unordered_set ব্যবহার করে



➤ Step-by-step:

1. প্রথমে headA এর সব node গুলো একে একে একটি unordered_set এ রাখো।


2. এরপর headB এর প্রতিটি node check করো — যদি সেটার pointer (address) set এর মধ্যে পাওয়া যায়, তাহলে বুঝবে এটিই intersection point।


3. তখন সেই node return করো।


4. যদি একটাও না মিলে, তাহলে return করো nullptr.



✨ Core Logic:

> তুমি node এর value না দেখে pointer দেখে check করছো।
কারণ দুইটি list এর value একই হলেও যদি pointer আলাদা হয়, তাহলে সেগুলো ভিন্ন node।




---

✅ Time & Space Complexity:

Time Complexity: O(m + n)
(m = listA এর দৈর্ঘ্য, n = listB এর দৈর্ঘ্য)

Space Complexity: O(m)
(তুমি listA এর mটি node set এ রাখছো)



---

🧪 Test Case Analysis:

✅ Test Case 1:

listA = [4,1,8,4,5]
listB = [5,6,1,8,4,5]
skipA = 2, skipB = 3, intersectVal = 8

তুমি প্রথমে listA এর সব node set এ রাখলে: {4, 1, 8, 4, 5} → (but actually memory address)

তারপর listB traverse করো:

5 → 6 → 1 → 8 → ম্যাচ! কারণ pointer match করে।


So, return 8.


✅ Test Case 2:

listA = [1,9,1,2,4], skipA=3
listB = [3,2,4], skipB=1, intersectVal=2

তোমার set: {1,9,1,2,4}

listB traverse:

3 → 2 → pointer match!


Return 2.


✅ Test Case 3:

listA = [2,6,4], listB = [1,5], intersectVal = 0

Set: {2,6,4}

Traverse B: 1 → 5 → কোনটা match করলো না।

Return nullptr.



---

🔍 তুমি কীভাবে ভাববে সমাধান করার সময়?

প্রশ্নটা পড়ার সময় চিন্তা করো:

দুইটি linked list এর structure retain করতে হবে (modify করা যাবে না)

pointer comparison করতে হবে (value না)

তাই, একটার সব pointer আগে collect করে রাখি → অন্যটা পরে check করি।


এই ভাবনা থেকে তুমি naturally unordered_set বা HashSet এর solution এ আসতে পারো।


Full Code:
------------

  class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_set<ListNode*> set1;
        ListNode* ans=nullptr;
        while(headA!=nullptr)
            {
                set1.insert(headA);
                headA=headA->next;
            }
       while(headB!=nullptr)
           {
               if(set1.find(headB)!=set1.end())
               {
                   ans=headB;
                   break;
               }
               headB=headB->next;
           }
        return ans;
    }
};
