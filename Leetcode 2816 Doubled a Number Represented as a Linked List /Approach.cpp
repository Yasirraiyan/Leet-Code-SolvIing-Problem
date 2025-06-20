সমস্যার ব্যাখ্যা (Problem Explanation)

ধরা যাক,

Input: head = [1,8,9]
➤ এটি 189 কে represent করে।
➤ Double করলে: 189 × 2 = 378
➤ Output: [3,7,8]

Input: head = [9,9,9]
➤ এটি 999 কে represent করে।
➤ Double করলে: 999 × 2 = 1998
➤ Output: [1,9,9,8]



---

✅ তুমি যে সমাধান দিয়েছো, সেটার ধাপ-ধাপে ব্যাখ্যা বাংলা + ম্যাথমেটিকালি


---

🔷 Step 1: Linked List → Vector (Digit Collection)

vector<int> reserve;
while(head != nullptr) {
    reserve.push_back(head->val);
    head = head->next;
}

➤ ব্যাখ্যা:

তুমি প্রথমে linked list-এর প্রতিটি node থেকে digit নিয়ে reserve নামে একটা vector-এ রাখছো।

কারণ: linked list-এ পেছন থেকে যাওয়াটা সহজ নয়, কিন্তু vector-এ তা সহজ — আর double করার সময় আমরা right to left যেতে চাই (যেমন হাতে carry নিয়ে কাজ করি)।



---

🔷 Step 2: Right to Left → Double with Carry

int carry = 0;
vector<int> result;
for(int i = reserve.size() - 1; i >= 0; i--) {
    int sum = reserve[i] * 2 + carry;
    result.push_back(sum % 10);  // নতুন digit
    carry = sum / 10;            // carry
}

➤ ব্যাখ্যা (ম্যাথমেটিকালি):

প্রতিটি digit কে double করা হচ্ছে এবং carry যোগ করা হচ্ছে।

উদাহরণ:
[1,8,9] → reserve = [1,8,9]
চলবে i = 2 থেকে শুরু করে i = 0 পর্যন্ত।

i = 2 → 9 × 2 + 0 = 18 → result.push_back(8) + carry = 1

i = 1 → 8 × 2 + 1 = 17 → result.push_back(7) + carry = 1

i = 0 → 1 × 2 + 1 = 3 → result.push_back(3) + carry = 0


👉 result = [8, 7, 3]


---

🔷 Step 3: Extra Carry থাকলে Handle

if(carry > 0) {
    result.push_back(carry);
}

যদি সব শেষে কোনো carry থেকে যায় (যেমন: 999 × 2 = 1998 → carry = 1), তাহলে সেটা একটা নতুন digit হয়ে যায়।


---

🔷 Step 4: Reverse করে New Linked List বানানো

reverse(result.begin(), result.end());
ListNode* headd = new ListNode(result[0]);
ListNode* current = headd;
for(int j = 1; j < result.size(); j++) {
    current->next = new ListNode(result[j]);
    current = current->next;
}

➤ ব্যাখ্যা:

আমরা যেহেতু right to left করে result তৈরি করছিলাম, এখন সেটা reverse করতে হয়।

তারপর নতুন linked list বানিয়ে return করি।



---

🔍 উদাহরণ দিয়ে Test Case ব্যাখ্যা:

✅ Test Case 1:

Input: [1,8,9]
→ reserve = [1,8,9]
→ Doubling with carry:

9×2 = 18 → push 8, carry 1  
8×2+1 = 17 → push 7, carry 1  
1×2+1 = 3 → push 3, carry 0  
Result before reverse: [8,7,3] → After reverse: [3,7,8]

✔ Output = [3,7,8]


---

✅ Test Case 2:

Input: [9,9,9]
→ reserve = [9,9,9]
→ Doubling with carry:

9×2 = 18 → push 8, carry 1  
9×2+1 = 19 → push 9, carry 1  
9×2+1 = 19 → push 9, carry 1  
→ push carry = 1  
Result: [8,9,9,1] → After reverse: [1,9,9,8]

✔ Output = [1,9,9,8]


---

  Full Code:
--_------------
class Solution 
{
public:
    ListNode* doubleIt(ListNode* head) 
    {
             vector<int>reserve;
        while(head!=nullptr)
            {
                reserve.push_back(head->val);
                head=head->next;
            }
        long long gen=0;
        //for(int i=0;i<reserve.size();i++)
   int carry=0;
        vector<int>result;
        for(int i=reserve.size()-1;i>=0;i--)
            {
            int  sum=reserve[i]*2+carry;
                result.push_back(sum%10);
                carry=sum/10;
            }
         
             
        if(carry>0)
        {
            result.push_back(carry);
        }
        
        reverse(result.begin(),result.end());
        ListNode* headd=new ListNode(result[0]);ListNode* current=headd;
       for(int j=1;j<result.size();j++)
           {
               
               
               current->next=new ListNode(result[j]);
               current =current->next;
           }
        return headd;
    }
    
}; 
