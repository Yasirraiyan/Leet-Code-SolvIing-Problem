🧠 প্রশ্নটা কী বলছে?

তোমাকে একটা Linked List দেওয়া আছে। তুমি শেষ থেকে n-তম node টা মুছে ফেলবে এবং বাকি list return করবে।


---

📌 উদাহরণ ১:

Input: head = [1,2,3,4,5], n = 2  
Output: [1,2,3,5]

শেষ থেকে 2-তম node → 4
তাহলে 4 বাদ দিলে বাকিগুলা থাকে: 1 → 2 → 3 → 5


---

✅ তুমি যে পদ্ধতিতে সমাধান করেছো (Approach):

তুমি দুই ধাপে কাজ করেছো—

Step 1: Stack-এ সব node রেখে দিয়েছো

👉 এর মানে head থেকে শেষ পর্যন্ত যত node আছে, সবকে stack-এ রেখে দিয়েছো।

while(head != nullptr){
    st.push(head);
    head = head->next;
}

এতে stack এর top এ থাকবে লিস্টের শেষ node।
ধরা যাক লিস্ট [1, 2, 3, 4, 5] → stack হবে:

Top → 5  
       4  
       3  
       2  
Bottom→1


---

Step 2: Stack থেকে pop করে n-th node বাদ দাও

int count = 0;
vector<ListNode*> v;

while(!st.empty()){
    ListNode* top = st.top();
    count++;
    if(count != n){  // skip nth node from end
        v.push_back(top); 
    }
    st.pop();
}

এখানে count দিয়ে track করছো কতটি element পপ করছো। যখন count == n হয়, তখন ঐ node কে বাদ দিচ্ছো।


---

Step 3: Vector উল্টে আবার নতুন Linked List বানাচ্ছো

reverse(v.begin(), v.end());  // কারণ এখন লিস্ট উল্টানো

ListNode* headd = v[0];
ListNode* curr = headd;
for(int i = 1; i < v.size(); i++){
    curr->next = v[i];
    curr = curr->next;
}
curr->next = nullptr;
return headd;

এইভাবে তুমি n-th node বাদ দিয়ে আবার নতুন list বানিয়ে দিচ্ছো।


---

✅ কেন এটা Accepted হয়?

তোমার কোড সময়সীমার মধ্যে চলে এবং সব edge case (ছোট বড় লিস্ট, একমাত্র element থাকলে) ঠিকঠাক হ্যান্ডেল করে। Let's test:


---

🔍 Test Case বিশ্লেষণ

Case 1:

head = [1, 2, 3, 4, 5], n = 2

Stack → 5(top), 4, 3, 2, 1
Count করতে করতে count == 2 হলে 4 বাদ যাবে
Vector → [5, 3, 2, 1] → reverse → [1, 2, 3, 5] ✅ ঠিক


---

Case 2:

head = [1], n = 1

Stack → 1
Count → 1
count == n, তাই 1 বাদ
Vector → খালি
Return → nullptr ✅ ঠিক


---

Case 3:

head = [1, 2], n = 1

Stack → 2, 1
count == 1 হলে → 2 বাদ
Vector → [1] → Reverse → [1] ✅ ঠিক


---

📌 Time Complexity:

Stack তৈরি: O(N)

Stack থেকে pop করে vector: O(N)

Vector reverse: O(N)

নতুন list তৈরি: O(N)


👉 মোটামুটি O(N) time এবং O(N) space লাগছে।


---

✅ Summary (Bangla):

ধাপ	কাজ

Step 1	Stack-এ সব node রাখো যেন শেষ থেকে n-th খুঁজতে পারো
Step 2	Stack থেকে পপ করে n-th বাদ দাও
Step 3	বাকি node-দের নিয়ে নতুন linked list বানাও
Step 4	Return করো নতুন head

Full Code:
------------

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
{
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
