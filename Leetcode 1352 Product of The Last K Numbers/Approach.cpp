✅ সমস্যা বুঝি (Problem Summary - বাংলা):
আমাদেরকে একটা ProductOfNumbers ক্লাস বানাতে হবে।

দুটি মেথড থাকবে: add(int num) ও getProduct(int k)

প্রতিবার getProduct(k) কল করার সময়, শেষের k সংখ্যার গুণফল রিটার্ন করতে হবে।

✅ Naive/সোজা সমাধান (তোমার দেওয়া কোড):
cpp
Copy
Edit
class ProductOfNumbers {
public:
    vector<int>stream;

    ProductOfNumbers() {
        stream.clear();
    }

    void add(int num) {
        stream.push_back(num);
    }

    int getProduct(int k) {
        if(k > stream.size()) return 0;

        int p = 1;
        for(int i = stream.size() - k; i < stream.size(); i++) {
            p *= stream[i];
            if(p == 0) return 0; // shortcut: যদি 0 হয়, গুণফল 0
        }
        return p;
    }
};
✅ উদাহরণ দিয়ে দেখি:
cpp
Copy
Edit
ProductOfNumbers productOfNumbers;
productOfNumbers.add(3);        // stream = [3]
productOfNumbers.add(0);        // stream = [3, 0]
productOfNumbers.add(2);        // stream = [3, 0, 2]
productOfNumbers.add(5);        // stream = [3, 0, 2, 5]
productOfNumbers.add(4);        // stream = [3, 0, 2, 5, 4]

productOfNumbers.getProduct(2); // 5*4 = 20
productOfNumbers.getProduct(3); // 2*5*4 = 40
productOfNumbers.getProduct(4); // 0*2*5*4 = 0
productOfNumbers.add(8);        // stream = [3, 0, 2, 5, 4, 8]
productOfNumbers.getProduct(2); // 4*8 = 32
⚠️ সমস্যা (Time Complexity):
getProduct(k) করার জন্য প্রতি বার k এলিমেন্টের ওপর লুপ চালাতে হচ্ছে → O(k)।

প্রশ্নে বলেছে, k হতে পারে 4*10^4 পর্যন্ত! তাই এই কোড Slow হয়ে যাবে।

✅ Efficient (Optimized) সমাধান → Prefix Product approach (O(1))
আমরা একটা prefix product array রাখব — যেখানে prefix[i] মানে হল stream[0]*stream[1]*...*stream[i] পর্যন্ত গুণফল।

যেমন:

makefile
Copy
Edit
stream:       [3, 0, 2, 5, 4, 8]
prefixProd:   [3, 0, 2, 10, 40, 320] (wrong if zero in between)

➡️ তাই আমরা কিছু পরিবর্তন করব:
- যখন 0 আসবে, prefixProduct লিস্ট আবার শুরু করব।
💡 নতুন Strategy:
cpp
Copy
Edit
class ProductOfNumbers {
public:
    vector<int> prefixProd; // store running product
    int zeroIndex = -1;     // index where last 0 occurred

    ProductOfNumbers() {
        prefixProd.push_back(1); // initial 1 (neutral element of multiplication)
    }

    void add(int num) {
        if(num == 0) {
            prefixProd.clear();
            prefixProd.push_back(1); // reset after 0
        } else {
            int last = prefixProd.back();
            prefixProd.push_back(last * num);
        }
    }

    int getProduct(int k) {
        if(k >= prefixProd.size()) return 0; // contains 0

        int n = prefixProd.size();
        return prefixProd[n - 1] / prefixProd[n - 1 - k];
    }
};
✅ ব্যাখ্যা (বাংলায়):
prefixProd[i] হচ্ছে গুণফল product(stream[0..i-1])

যদি 0 আসে, তাহলে পুরা prefix খালি করে দাও। কারণ 0 এর পরের সব প্রোডাক্ট 0 হয়ে যাবে।

getProduct(k) করার জন্য:

আমরা শুধু দুইটা prefix মান ভাগ করে দেই → prefix[n] / prefix[n-k]

এতে করে টাইম কমপ্লেক্সিটি হয় O(1)

✅ উদাহরণ দিয়ে দেখি:
cpp
Copy
Edit
Input:
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Prefix এর অবস্থান:
- add(3) => [1, 3]
- add(0) => reset → [1]
- add(2) => [1, 2]
- add(5) => [1, 2, 10]
- add(4) => [1, 2, 10, 40]

getProduct(2) => 40 / 10 = 4  
getProduct(3) => 40 / 2 = 20  
getProduct(4) => 40 / 1 = 40, but stream has 0 → reset point → ❌ wrong! → handled by size check → return 0

add(8) => [1, 2, 10, 40, 320]
getProduct(2) => 320 / 40 = 8
🧠 Time & Space Complexity:
Operation	Time Complexity
add(num)	O(1)
getProduct(k)	O(1)

Space: O(n), where n is number of non-zero elements added since last 0.

🔎 Bonus Test Code (LeetCode style):
cpp
Copy
Edit
ProductOfNumbers productOfNumbers;
productOfNumbers.add(3);        
productOfNumbers.add(0);        
productOfNumbers.add(2);        
productOfNumbers.add(5);        
productOfNumbers.add(4);        
cout << productOfNumbers.getProduct(2) << endl; // 20
cout << productOfNumbers.getProduct(3) << endl; // 40
cout << productOfNumbers.getProduct(4) << endl; // 0
productOfNumbers.add(8);        
cout << productOfNumbers.getProduct(2) << endl; // 32
🔚 উপসংহার:
তুমি যেটা করছিলে সেটা O(k) time এ কাজ করত, ঠিক কাজ করলেও large input এ slow।

Prefix product ধারণা ব্যবহার করলে O(1) time এ করা যায়।

Prefix array reset করতে হবে যখন 0 পাওয়া যাবে।

Full Code:
----------

class ProductOfNumbers 
{
public:
// ProductOfNumbers p;
vector<int>stream;
    ProductOfNumbers()
     {
       // this->p=stream;
       this->stream=stream;
    }
    
    void add(int num)
     {
        stream.push_back(num);
    }
    
    int getProduct(int k) 
    {
      if(k>stream.size()) return 0;
       int p=stream[stream.size()-1];
      if (k == 1) return p == 0 ? 0 : p;
        //int p=stream[stream.size()-1];
        int count=0;
      for(int j=stream.size()-2;j>=0;j--)
      {
         p*=stream[j];
         count++;
         if(count==k-1)
         {
          break;
         }
      }
      return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
