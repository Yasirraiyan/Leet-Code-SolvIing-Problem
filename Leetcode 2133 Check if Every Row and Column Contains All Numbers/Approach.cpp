প্রশ্নের ধরন (Problem Understanding):

n x n একটি স্কয়ার মেট্রিক্স দেওয়া আছে, যেখানে n হচ্ছে সারি এবং কলামের সংখ্যা।

ভ্যালিড বলতে বোঝায়:
প্রতিটি সারি (row) এবং প্রতিটি কলাম (column) তে অবশ্যই ১ থেকে n পর্যন্ত সব সংখ্যাগুলো থাকতে হবে, আর কোন সংখ্যা রিপিট হবে না।

অর্থাৎ:

প্রতিটি সারিতে থাকবে ১, ২, ৩, ..., n একবার করে।

প্রতিটি কলামেও থাকবে ১, ২, ৩, ..., n একবার করে।



তাহলে তোমার কাজ হচ্ছে যাচাই করা যে, এই শর্ত পূরণ হয়েছে কি না।


---

তোমার কোডের মোটামুটি লজিক (Summary of Code Logic):

1. প্রথমে মেট্রিক্সের সাইজ বের করো (n)।


2. ১ থেকে n পর্যন্ত সব সংখ্যাকে একটি সেটে (set1) রাখো।


3. সারি অনুযায়ী প্রতিটি সংখ্যার ফ্রিকোয়েন্সি চেক করো:
যদি কোন সংখ্যা set1 এর বাইরে হয় বা কোন সংখ্যা একবারের বেশি হয়, তাহলে ফ্ল্যাগ false করো।


4. কলাম অনুযায়ী একইভাবে ফ্রিকোয়েন্সি চেক করো।


5. সব সংখ্যার মোট ফ্রিকোয়েন্সি চেক করো (freq map থেকে) — প্রত্যেক সংখ্যার মোট ফ্রিকোয়েন্সি n হওয়া উচিত (কারণ প্রতি সারি ও কলামে ১ করে আসবে)।


6. সব চেক যদি পাস হয়, তাহলে true রিটার্ন করো, নয়তো false।




---

লাইন বাই লাইন ব্যাখ্যা (Brief line-by-line explanation):

int findsize(vector<vector<int>>& matrix)
{
    int size;
    for(int i=0; i<matrix.size(); i++)
    {
        size = matrix[i].size();
        break;
    }
    return size;
}

এখানে matrix এর সাইজ বের করার জন্য একটা ফাংশন।

প্রথম সারির কলামের সংখ্যা ধরে নেয়া হয়েছে, কারণ n x n মেট্রিক্স, তাই সব সারির কলাম সংখ্যা সমান।


bool checkValid(vector<vector<int>>& matrix) {
    bool checkcol=true;
    bool checkrow=true;
    bool isvalid=true;
    int size=findsize(matrix);

বুলিয়ান ভেরিয়েবল ডিফাইন করেছে, সারি এবং কলাম চেক করার জন্য।

size হচ্ছে n।


unordered_map<int,int>freq;
    unordered_set<int>set1;
    for(int i=1; i<=size; i++)
    {
        set1.insert(i);
    }

freq: পুরো মেট্রিক্সে প্রতিটি সংখ্যার মোট উপস্থিতি গননা করবে।

set1: ১ থেকে n পর্যন্ত সংখ্যার সেট, যেন আমরা চেক করতে পারি সংখ্যাগুলো লেগ্যাল (valid) কি না।


for(int j=0; j<matrix.size(); j++)
    {
        for(int k=0; k<matrix.size(); k++)
        {
            freq[matrix[j][k]]++;
        }
    }

পুরো মেট্রিক্সের প্রতিটি সংখ্যা গুনে freq ম্যাপে আপডেট করা হলো।


for(int i=0; i<matrix.size(); i++)
    {
        unordered_map<int,int>freqrow;
        for(int j=0; j<matrix[i].size(); j++)
        {
            freqrow[matrix[i][j]]++;
            if(set1.find(matrix[i][j]) != set1.end())
            {
                if(freqrow[matrix[i][j]] > 1)
                {
                    checkrow=false;
                    break;
                }
            }
            else
            {
                checkrow=false;
            }
            if(!checkrow) break;
        }
    }

প্রতিটি সারির জন্য:

নতুন একটি ফ্রিকোয়েন্সি ম্যাপ (freqrow) বানানো হয়েছে।

প্রতিটি সংখ্যার উপস্থিতি একবারের বেশি হলে, checkrow = false।

যদি সংখ্যা ১ থেকে n এর মধ্যে না থাকে, তখনও checkrow = false।



for(int i=0; i<matrix[0].size(); i++)
    {
        unordered_map<int,int>freqcol;
        for(int j=0; j<matrix.size(); j++)
        {
            freqcol[matrix[j][i]]++;
            if(set1.find(matrix[j][i]) != set1.end())
            {
                if(freqcol[matrix[j][i]] > 1)
                {
                    checkcol=false;
                    break;
                }
                else
                {
                    checkcol=true;
                }
            }
            else
            {
                checkcol=false;
                break;
            }
        }
        if(!checkcol) break;
    }

প্রতিটি কলামের জন্য:

একইভাবে ফ্রিকোয়েন্সি চেক করা হচ্ছে।

যদি কোন সংখ্যা নাও থাকে অথবা রিপিট হয়ে থাকে, checkcol false।



for(auto it: freq)
    {
        if(it.second != size)
        {
            isvalid=false;
            break;
        }
    }

এই অংশে চেক করছে যে, প্রতিটি সংখ্যা পুরো মেট্রিক্সে ঠিক n বার আছে কিনা (কারণ প্রতিটি সংখ্যা অবশ্যই প্রতিটি সারি এবং কলামে একবার থাকবে, অর্থাৎ মোট n বার থাকবে)।


if(!checkcol || !checkrow)
    {
        isvalid=false;
    }
    else
    {
        isvalid=true;
    }
    return isvalid;
}

যদি সারি বা কলাম চেক ব্যর্থ হয়, তাহলে false রিটার্ন করবে।

সব ঠিক থাকলে true রিটার্ন করবে।



---

কেন এই কোড accepted হয়?

সারি এবং কলাম দুইটাতে ১ থেকে n পর্যন্ত সব সংখ্যা আছে কি না চেক করে।

প্রতিটি সংখ্যার মাত্র একবার আছে কিনা চেক করে।

অতিরিক্ত বা অনুপস্থিত সংখ্যা থাকলে false রিটার্ন করে।

n এর সর্বোচ্চ মান ১০০, তাই এই জটিলতা (O(n^2)) সময়সীমার মধ্যে ঠিক আছে।



---

উদাহরণ দিয়ে ব্যাখ্যা:

matrix = [[1,2,3],[3,1,2],[2,3,1]]

set1 = {1,2,3}

প্রথম সারি: {1,2,3} → একবার করে আছে, OK

দ্বিতীয় সারি: {3,1,2} → একবার করে আছে, OK

তৃতীয় সারি: {2,3,1} → একবার করে আছে, OK

প্রথম কলাম: {1,3,2} → একবার করে আছে, OK

দ্বিতীয় কলাম: {2,1,3} → একবার করে আছে, OK

তৃতীয় কলাম: {3,2,1} → একবার করে আছে, OK

সব সংখ্যার freq = 3 (n=3) → সঠিক


সুতরাং, true রিটার্ন করে।


---

সংক্ষেপে:

প্রশ্ন অনুযায়ী শর্ত বুঝে নিয়েছো (সারি এবং কলামে ১ থেকে n এর সংখ্যা একবার করে থাকা).

সেট ব্যবহার করে সংখ্যাগুলোর বৈধতা চেক করেছো।

সারি ও কলামের প্রতিটি সংখ্যা একবার আছে কিনা দেখা হয়েছে।

শেষে freq চেক করে নিশ্চিত হয়েছো যে সব সংখ্যা n বার আছে।

যদি সব ঠিক থাকে, তাহলে true রিটার্ন করেছো, অন্যথায় false।



Full Code:
-----------

class Solution {
public:
    int findsize(vector<vector<int>>& matrix)
    {
        int size;
        for(int i=0;i<matrix.size();i++)
            {
                //for(int j=0;j<matrix.size();j++)
                   // {
                        size=matrix[i].size();
                        break;
                       // size++;
                    //}
            }
        return size;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        bool checkcol=true;
        bool checkrow=true;
        bool isvalid=true;
        int size=findsize(matrix);
        unordered_map<int,int>freq;
        unordered_set<int>set1;
        for(int i=1;i<=size;i++)
            {
                set1.insert(i);
            }
        for(int j=0;j<matrix.size();j++)
            {
                for(int k=0;k<matrix.size();k++)
                    {
                        freq[matrix[j][k]]++;
                    }
            }
        //unordered_map<int,int>freqrow;
        for(int i=0;i<matrix.size();i++)
            {
                unordered_map<int,int>freqrow;
                for(int j=0;j<matrix[i].size();j++)
                    {
                        freqrow[matrix[i][j]]++;
                        if(set1.find(matrix[i][j])!=set1.end())
                        {
                        if(freqrow[matrix[i][j]]>1)
                        {
                            checkrow=false;
                            break;
                        }
                    
                        
                    }
                        else{
                            checkrow=false;
                        }
                if(!checkrow) break;
                    }
                    }
        for(int i=0;i<matrix[0].size();i++)
            {
                unordered_map<int,int>freqcol;
                for(int j=0;j<matrix.size();j++)
                    {
                        freqcol[matrix[j][i]]++;
                        if(set1.find(matrix[j][i])!=set1.end())
                        {
                            
                        
                        if(freqcol[matrix[j][i]]>1)
                        {
                            checkcol=false;
                            break;
                        }
                            else{
                                checkcol=true;
                            }
                        }
                        else{
                            checkcol=false;
                            break;
                        }
                    }
                if(!checkcol) break;
            }
        for(auto it:freq)
            {
                if(it.second!=size)
                {
                    isvalid=false;
                    break;
                }
            }
        if(!checkcol||!checkrow)
        {
            isvalid=false;
        }
        else
        {
            isvalid=true;
        }
        return isvalid;
    
    }
    
};
