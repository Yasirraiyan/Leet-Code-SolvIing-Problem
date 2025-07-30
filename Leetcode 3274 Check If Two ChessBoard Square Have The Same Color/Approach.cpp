✅ 🔍 সমস্যা বোঝার জন্য Step by Step ভাবনা:
চলো আগে প্রশ্নটা বুঝি:

চেসবোর্ডে ৮×৮ স্কয়ার থাকে।

প্রত্যেকটি স্কয়ারের অবস্থান "a1" থেকে "h8" পর্যন্ত হয়।

প্রতি বিকল্প স্কয়ারে রং পরিবর্তন হয় (Black-White-Black-White...)।

📌 উদাহরণ:

a1 → Black

a2 → White

b1 → White

b2 → Black

👉 মানে হচ্ছে যদি (column + row) এর যোগফল জোড় (even) হয়, তাহলে সেটা Black,
আর যদি বিজোড় (odd) হয়, তাহলে সেটা White।

✅ তোমার কোডের আইডিয়া:
তুমি একটি sum(string s) ফাংশন লিখেছো, যেখানে:

s[0] হলো column letter (যেমন 'a' → 1, 'b' → 2, …)

s[1] হলো row digit (যেমন '1' → 1, '2' → 2, …)

তুমি এই দুইটা ASCII ভ্যালু থেকে নাম্বার বের করেছো এবং যোগফল বের করেছো।

তারপর sum1 % 2 এবং sum2 % 2 দেখে বোঝার চেষ্টা করেছো তারা একি parity (even/odd) এর কিনা।

🔄 Step by Step Execution (Test Case: "a1" and "c3")
cpp
Copy
Edit
int sum(string s)
For "a1":
s[0] = 'a' → 'a' - 'a' + 1 = 1

s[1] = '1' → '1' - '0' = 1

Total sum = 1 + 1 = 2 → Even → Black

For "c3":
s[0] = 'c' → 'c' - 'a' + 1 = 3

s[1] = '3' → '3' - '0' = 3

Total sum = 3 + 3 = 6 → Even → Black

Both sums are even ⇒ both are black ⇒ return true ✅

✅ কেন তোমার কোড কাজ করেছে:
তুমি খুব সুন্দরভাবে character থেকে number বের করেছো:

cpp
Copy
Edit
if(s[i]>='a'&&s[i]<='z') sum += s[i]-'a'+1;
if(isdigit(s[i])) sum += s[i]-'0';
👉 এইভাবে a কে 1 এবং 1 কে 1 এ রূপান্তর করেছো। তার মানে রঙ নির্ধারণ করতে (column + row) % 2 ই যথেষ্ট।

🛠 তোমার কোডের ছোট optimization পরামর্শ:
তোমার sum() ফাংশন অনেক বড় কিন্তু তুমি শুধুই ২ ক্যারেক্টার দেখছো, তাই এটাকে আরো সহজভাবে লেখা যায়:

cpp
Copy
Edit
int sum(string s) {
    return (s[0] - 'a' + 1) + (s[1] - '0');
}
বা একদম color parity return করাই ভালো:

cpp
Copy
Edit
int color(string s) {
    return (s[0] - 'a' + s[1] - '0') % 2;
}

bool checkTwoChessboards(string coordinate1, string coordinate2) {
    return color(coordinate1) == color(coordinate2);
}
🔁 Test Case Walkthrough:
1. Input: a1, c3
'a' → 1, '1' → 1 ⇒ sum = 2 → even → black

'c' → 3, '3' → 3 ⇒ sum = 6 → even → black
✅ Output: true

2. Input: a1, h3
'a' → 1, '1' → 1 ⇒ sum = 2 → even → black

'h' → 8, '3' → 3 ⇒ sum = 11 → odd → white
❌ Output: false

📌 সারসংক্ষেপ (Summary in Bangla):
প্রতিটি স্কয়ারের রং নির্ধারণ করা যায় (column + row) % 2 দেখে।

যদি দুটি স্কয়ারের এই যোগফল একই parity (even/odd) হয় তাহলে রঙ একই হবে।

তুমি সুন্দরভাবে ASCII ব্যাবহার করে সেটা বের করেছো।

কোড Accepted কারণ তোমার Logic ছিল 100% ঠিক।

Full Code:
-----------

class Solution {
public:
 int sum(string s)
 {
  int sum=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]>='a'&&s[i]<='z')
    {
    
      sum+=s[i]-'a'+1;
    }
    if(isdigit(s[i]))
    {
      sum+=s[i]-'0';
    }
    
    /*if(s[i] == 'b') sum += 2;
        if(s[i] == 'c') sum += 3;
        if(s[i] == 'd') sum += 4;
        if(s[i] == 'e') sum += 5;
        if(s[i] == 'f') sum += 6;
        if(s[i] == 'g') sum += 7;
        if(s[i] == 'h') sum += 8;
        if(s[i] == 'i') sum += 9;
        if(s[i] == 'j') sum += 10;
        if(s[i] == 'k') sum += 11;
        if(s[i] == 'l') sum += 12;
        if(s[i] == 'm') sum += 13;
        if(s[i] == 'n') sum += 14;
        if(s[i] == 'o') sum += 15;
        if(s[i] == 'p') sum += 16;
        if(s[i] == 'q') sum += 17;
        if(s[i] == 'r') sum += 18;
        if(s[i] == 's') sum += 19;
        if(s[i] == 't') sum += 20;
        if(s[i] == 'u') sum += 21;
        if(s[i] == 'v') sum += 22;
        if(s[i] == 'w') sum += 23;
        if(s[i] == 'x') sum += 24;
        if(s[i] == 'y') sum += 25;
        if(s[i] == 'z') sum += 26;
        
        if(s[i]=='0') sum+=0;
        if(s[i]=='1') sum+=1;
        if(s[i] == '2') sum += 2;
if(s[i] == '3') sum += 3;
if(s[i] == '4') sum += 4;
if(s[i] == '5') sum += 5;
if(s[i] == '6') sum += 6;
if(s[i] == '7') sum += 7;
if(s[i] == '8') sum += 8;
if(s[i] == '9') sum += 9;
*/
  }
  return sum;
 }
    bool checkTwoChessboards(string coordinate1, string coordinate2) 
    {
        int sum1=sum(coordinate1);
        int sum2=sum(coordinate2);
        bool check=false;
        if((sum1%2==0&&sum2%2==0)||(sum1%2!=0&&sum2%2!=0))
        {
          check=true;
        }
        return check;
    }
};
