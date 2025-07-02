🔍 Step-by-step Approach (Bangla + English mix)


---

🔸 Step 1: Linked List → Vector

vector<int> v;
while (head != nullptr) {
    v.push_back(head->val);
    head = head->next;
}

➡️ লিঙ্কড লিস্ট traversal করে সবগুলো value vector v তে তুলে নিচ্ছি।
এটা করার কারণ হলো:

লিঙ্কড লিস্টে আগের ও পরের node এ অ্যাক্সেস একসাথে করা কঠিন।

কিন্তু array/vector এ v[i-1], v[i], v[i+1] সহজে করা যায়।



---

🔸 Step 2: Find Critical Points

vector<int> cr;
for (int i = 1; i < v.size() - 1; i++) {
    if ((v[i] > v[i-1] && v[i] > v[i+1]) || (v[i] < v[i-1] && v[i] < v[i+1])) {
        cr.push_back(i);
    }
}

➡️ Critical Point এর শর্ত:

আগের এবং পরের node থাকতে হবে।

v[i] > v[i-1] && v[i] > v[i+1] → Local Maxima

v[i] < v[i-1] && v[i] < v[i+1] → Local Minima


তাই index 1 থেকে শুরু করে v.size()-2 পর্যন্ত চেক করছো।


---

🔸 Step 3: Handle corner case (critical point < 2)

if (cr.size() < 2)
    return {-1, -1};

➡️ যদি ২টির কম critical point থাকে, তাহলে প্রশ্ন অনুযায়ী [-1, -1] return করতে হবে।


---

🔸 Step 4: Calculate all distances

vector<int> vv;
for (int j = 0; j < cr.size() - 1; j++) {
    vv.push_back(abs(cr[j] - cr[j+1]));
}

➡️ পরপর যেকোনো ২টা critical point এর মধ্যকার দূরত্ব abs(index difference) হিসেব করছো।


---

🔸 Step 5: Final Answer

vector<int> ans;
ans.push_back(findmin(vv));
ans.push_back(cr.back() - cr.front());

✅ Minimum Distance: → পরপর critical point গুলোর মধ্যে যে কম দূরত্ব আছে vv array থেকে findmin() দিয়ে বের করা।

✅ Maximum Distance: → সবথেকে প্রথম critical point থেকে শেষ critical point এর index difference: cr.back() - cr.front()



---

✅ Helper Functions

🔸 Find Min from vector

int findmin(vector<int>& arr) {
    int min = arr[0];
    for (int k = 1; k < arr.size(); k++) {
        if (arr[k] < min) min = arr[k];
    }
    return min;
}


---

✅ Test Case 1: [3,1]

Vector: [3,1]
→ Too short, no critical point
Return: [-1, -1]


---

✅ Test Case 2: [5,3,1,2,5,1,2]

Index:   0 1 2 3 4 5 6
Value:   5 3 1 2 5 1 2

Critical Point Indices: [2, 4, 5]

- vv = [2, 1] → min = 1
- maxDist = 5 - 2 = 3
Return: [1, 3]


---

✅ Test Case 3: [1,3,2,2,3,2,2,2,7]

Index:   0 1 2 3 4 5 6 7 8
Value:   1 3 2 2 3 2 2 2 7

Critical Point Indices: [1, 4]

- vv = [3] → min = 3
- maxDist = 4 - 1 = 3
Return: [3, 3]


---

🔚 Summary (Bangla):

🔸 প্রথমে লিঙ্কড লিস্টকে ভেক্টরে রূপান্তর করি।
🔸 তারপর ১ থেকে n-2 পর্যন্ত লুপ চালিয়ে local minima/maxima চেক করি।
🔸 যদি ২টির কম critical point পাই, তাহলে [-1,-1] return করি।
🔸 না হলে, পরপর index-এর মধ্যে min gap বের করি (minDistance),
🔸 এবং প্রথম ও শেষ critical point-এর মধ্যে gap বের করি (maxDistance)।

Full Code:
-----------
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
