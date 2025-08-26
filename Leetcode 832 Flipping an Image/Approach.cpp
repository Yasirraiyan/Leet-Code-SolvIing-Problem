প্রশ্নটা বোঝা

তোমার কাছে একটা n x n বাইনারি ম্যাট্রিক্স আছে।
তোমাকে যা করতে হবে:

Horizontally flip: প্রতিটি row উল্টানো (reverse)
উদাহরণ: [1,1,0] → [0,1,1]

Invert: 0 → 1 এবং 1 → 0
উদাহরণ: [0,1,1] → [1,0,0]

Constraints: ছোট ম্যাট্রিক্স, তাই সহজে row-by-row কাজ করা যাবে।

Solution Approach
Step 1: Flip Row
vector<int> flip(vector<int>& v)
{
    vector<int> vv;
    for(int i=v.size()-1;i>=0;i--)
    {
        vv.push_back(v[i]);
    }
    return vv;
}


এখানে আমরা নতুন vector vv বানাই।

Row-এর শেষ index থেকে প্রথম পর্যন্ত traverse করি।

ফলে row reverse হয়ে যায়।
Technique: Simple iteration + reverse

Step 2: Invert Row
vector<int> invert(vector<int>& v)
{
    for(int j=0;j<v.size();j++)
    {
        if(v[j]==0) v[j]=1;
        else if(v[j]==1) v[j]=0;
    }
    return v;
}


প্রতিটি element check করা হচ্ছে।

0 হলে 1, 1 হলে 0 set করা হচ্ছে।

Alternative: v[j] ^= 1; ব্যবহার করলে এক লাইনে করা যাবে।
Technique: Bit manipulation / simple loop

Step 3: Apply on entire image
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
{
    for(int i=0;i<image.size();i++)
    {
        vector<int> row = image[i];
        row = flip(row);
        row = invert(row);
        image[i] = row;
    }
    return image;
}


প্রতিটি row-এ flip এবং invert sequentially apply করা হচ্ছে।

নতুন row image[i] তে overwrite করা হচ্ছে।

Technique: Row-wise processing

Step-by-Step Example

Input:

image = [[1,1,0],[1,0,1],[0,0,0]]

Iteration 1: row = [1,1,0]

Flip: [1,1,0] → [0,1,1]

Invert: [0,1,1] → [1,0,0]
→ image[0] = [1,0,0]

Iteration 2: row = [1,0,1]

Flip: [1,0,1] → [1,0,1] (palindrome, same after flip)

Invert: [1,0,1] → [0,1,0]
→ image[1] = [0,1,0]

Iteration 3: row = [0,0,0]

Flip: [0,0,0] → [0,0,0]

Invert: [0,0,0] → [1,1,1]
→ image[2] = [1,1,1]

Output:

[[1,0,0],
 [0,1,0],
 [1,1,1]]


✅ Output matches the example → solution correct

Key Points / Techniques

Row-wise operation: Imageকে row-by-row handle করা

Two separate functions: Flip এবং invert আলাদাভাবে করা → code readable

Loop + vector manipulation: Simple, small n জন্য efficient

Bitwise alternative: v[j] ^= 1; দিয়ে invert আরও concise করা যায়

Why accepted:

Complexity: O(n²) → n ≤ 20, perfectly fine

Logic: perfectly implements flip → invert

Complexity Analysis

n x n matrix → n rows, n elements per row

Flip: O(n) per row

Invert: O(n) per row

Total: O(n²) → small enough for constraints

How to think about this solution

Read the question carefully: flip horizontally → invert

Break it down:

Row reverse → simple vector traversal

Bit flip → simple loop or XOR

Apply row-by-row → easy to reason about

Test small examples manually → ensures correctness

Full Code:
----------

  class Solution {
public:
 vector<int>flip(vector<int>&v)
 {
    vector<int>vv;
    for(int i=v.size()-1;i>=0;i--)
    {
        vv.push_back(v[i]);
    }
    return vv;
 }
 vector<int>invert(vector<int>&v)
 {
    
    for(int j=0;j<v.size();j++)
    {
        if(v[j]==0)
        {
          v[j]=1;
        }
       else if(v[j]==1)
        {
          v[j]=0;
        }
        
        //v[j]^=1;
    }
    return v;
 }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
     {
        for(int i=0;i<image.size();i++)
        {
          vector<int> row=image[i];
          row=flip(row);
          row=invert(row);
          image[i]=row;
        }
        return image;
    }
};
