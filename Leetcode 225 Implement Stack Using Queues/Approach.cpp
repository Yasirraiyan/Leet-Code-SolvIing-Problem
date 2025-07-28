🔍 তোমার সমাধানের ব্যাখ্যা (Bangla):

class MyStack {
public:
    stack<int> st;

    MyStack() {}

    void push(int x) {
        st.push(x);
    }

    int pop() {
        int top = -1;
        if (!st.empty()) {
            top = st.top();
            st.pop();
        }
        return top;
    }

    int top() {
        if (!st.empty()) return st.top();
        return -1;
    }

    bool empty() {
        return st.empty();
    }
};


---

✅ প্রতিটি ফাংশনের কাজ ব্যাখ্যা:

1️⃣ push(int x)

void push(int x) {
    st.push(x);
}

এটা x সংখ্যাটাকে স্ট্যাকে পুশ করে (স্ট্যাকের উপরের দিকে রাখে)।

STL stack এর push() ফাংশন সরাসরি ব্যবহার করছো।


2️⃣ pop()

int pop() {
    int top = -1;
    if (!st.empty()) {
        top = st.top(); // উপরের এলিমেন্টটা নিয়ে নিচ্ছো
        st.pop();       // উপরের এলিমেন্টটা সরিয়ে দিচ্ছো
    }
    return top;
}

যদি স্ট্যাক খালি না থাকে, তাহলে উপরের এলিমেন্টটা ফেরত দেয় এবং সরিয়ে দেয়।

যদি খালি থাকে, তাহলে -1 ফেরত দেয়।


3️⃣ top()

int top() {
    if (!st.empty()) return st.top();
    return -1;
}

উপরের এলিমেন্টটা শুধু দেখে (ফেরত দেয়), কিন্তু সরায় না।


4️⃣ empty()

bool empty() {
    return st.empty();
}

যদি স্ট্যাক খালি হয়, true দেয়। না হলে false দেয়।

