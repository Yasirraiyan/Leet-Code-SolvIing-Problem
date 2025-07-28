🔶 প্রশ্ন থেকে সমাধানের ধারণা (Approach from Question):

> প্রশ্নে সাধারণত বলা থাকে, তুমি একটি Queue ক্লাস তৈরি করবে যেখানে নিচের ফাংশনগুলো থাকবে:



1. push(x) → queue-তে একটা সংখ্যা insert করবে।


2. pop() → queue-এর সামনের (first) এলিমেন্ট সরাবে এবং তা return করবে।


3. peek() → queue-এর সামনের (first) এলিমেন্ট দেখাবে কিন্তু সরাবে না।


4. empty() → queue খালি কিনা চেক করবে।



➡️ যেহেতু এটা FIFO (First-In-First-Out), তাই আমাদের C++ STL-এর queue<int> ব্যবহার করলেই হয়।


---

✅ কোড ব্যাখ্যা লাইন বাই লাইন (Line-by-line explanation):

class MyQueue {

➤ তুমি একটি MyQueue নামের ক্লাস তৈরি করছো, যেটা Queue এর কাজ করবে।

public:
    queue<int> q;

➤ এখানে তুমি C++ STL এর queue ডেটা স্ট্রাকচার ব্যবহার করছো যাতে int টাইপের ডেটা রাখা যাবে।


---

🔸 Constructor:

MyQueue() {
    // কিছু করার দরকার নেই এখানে কারণ queue নিজেই initialize হয়
}


---

🔸 Push Function:

void push(int x) {
    q.push(x); // নতুন এলিমেন্ট queue-এর শেষে insert হচ্ছে
}

🧠 Math/Logic: FIFO-এর নিয়ম – যাকে আগে insert করো, তাকেই আগে বের করতে হবে।
➡️ তাই আমরা queue.push(x) দিয়ে কাজ করে ফেলি।


---

🔸 Pop Function:

int pop() {
    int ans;
    int top = -1;
    if (!q.empty()) {
        top = q.front(); // প্রথম এলিমেন্ট (queue-এর মাথা)
        q.pop();         // সেটিকে queue থেকে সরিয়ে ফেলা হলো
    }
    return top;
}

🧠 Math:

Queue: [10, 20, 30]

Pop → প্রথম এলিমেন্ট 10 যাবে

q.front() = 10

q.pop() → 10 চলে গেল, queue হয় [20, 30]


✅ Return করি top = 10


---

🔸 Peek Function:

int peek() {
    int front = q.front();
    return front;
}

🧠 Logic: peek() শুধু দেখে যে সামনে কে আছে, কিন্তু সরায় না।
➡️ ধরো Queue = [5, 8, 9] → peek() → return 5


---

🔸 Empty Function:

bool empty() {
    bool empty = false;
    if (q.empty()) empty = true;
    return empty;
}

✴️ তুমি একটু ঘুরিয়ে লিখেছো, সহজভাবে লিখলে:

return q.empty();

🧠 Math: Queue খালি হলে q.empty() → true
➡️ না হলে → false


---

✅ কিভাবে প্রশ্ন পড়ে সমাধানের রোডম্যাপ বানাবে?

Step	কী ভাববে	কেন করবো

1️⃣	প্রশ্নে Queue বলেছে? FIFO কি?	তাহলে STL queue ব্যবহার করা যায়
2️⃣	push মানে insert at end	→ q.push(x)
3️⃣	pop মানে remove from front	→ q.front() নিয়ে q.pop()
4️⃣	peek মানে শুধু দেখবে	→ q.front() return
5️⃣	empty মানে খালি কিনা	→ q.empty()



---

✅ Testcase দিয়ে যাচাই

MyQueue* obj = new MyQueue();
obj->push(1);         // queue = [1]
obj->push(2);         // queue = [1, 2]
int a = obj->peek();  // a = 1 (front)
int b = obj->pop();   // b = 1 (front removed), queue = [2]
bool c = obj->empty();// false, কারণ queue তে এখনো 2 আছে


---

✅ Test Result:

Function	Return	Queue State

push(1)	void	[1]
push(2)	void	[1, 2]
peek()	1	[1, 2]
pop()	1	[2]
empty()	false	[2]



---

✅ কেন Accepted?

FIFO আচরণ ঠিকভাবে follow করেছে।

STL queue দিয়ে efficiently implement হয়েছে।

সমস্ত ফাংশন ঠিকভাবে কাজ করছে।

প্রশ্নে যেভাবে বলা হয়েছিল, তেমনই output এসেছে।



---

🔚 সংক্ষেপে:

✅ যখন প্রশ্নে queue implement করতে বলে:

যদি STL use allowed হয় → সরাসরি std::queue নাও।

FIFO মানে:

push → q.push(x)

pop → q.front(); q.pop();

peek → q.front()

empty → q.empty()

Full Code:
------------

class MyQueue 
{
public:
    queue<int>q;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        q.push(x);
    }
    
    int pop() 
    {
        int ans;
        int top=-1;
        if(!q.empty())
        {
            top=q.front();
            q.pop();
            //q.remove(top);
        }
      //  ans=top%st.size();
        return top;
    }
    
    int peek() 
    {
        int front=q.front();
        
        return front;
    }
    
    bool empty()
    {
        bool empty=false;
        if(q.empty()) empty=true;
         return empty;
    }
};
