এই সমস্যার সমাধানে আমরা এমন একটি অক্ষর খুঁজতে চাই যা target অক্ষরের চেয়ে lexicographically greater (অর্থাৎ dictionary অনুসারে পরে আসে), এবং সেই রকম অক্ষরগুলোর মধ্যে যেটা সবচেয়ে ছোট।

🔍 প্রবলেমটি ভালোভাবে বুঝি:
তোমাকে একটি অক্ষরের অ্যারে letters[] দেওয়া আছে, যেটা ascending order-এ সাজানো (মানে ছোট থেকে বড়)।
আর একটা target অক্ষর দেওয়া আছে। তোমাকে letters[] থেকে এমন একটা অক্ষর রিটার্ন করতে হবে,
যেটা target-এর থেকে বড় এবং lexicographically সবচেয়ে ছোট।
যদি এমন অক্ষর না থাকে, তাহলে letters[0] রিটার্ন করতে হবে।

✅ উদাহরণ দিয়ে বুঝি:
Input: letters = ["c","f","j"], target = 'a'
Output: "c"

'a' এর পরে সবচেয়ে ছোট অক্ষর হলো 'c'

Input: letters = ["x","x","y","y"], target = 'z'
Output: "x"

'z'-এর পরে কিছুই নেই, তাই আবার শুরু থেকে letters[0] = 'x' রিটার্ন হবে।

🧠 সমাধান বুঝি (কোড বিশ্লেষণ):
cpp
Copy
Edit
char nextGreatestLetter(vector<char>& letters, char target) {
    char ans = letters[0];  // ধরে নিচ্ছি, খুঁজে না পেলে এইটা রিটার্ন করব

    for (int i = 0; i < letters.size(); i++) {
        if (letters[i] > target) {
            ans = letters[i];  // প্রথম যেই অক্ষরটি target এর চেয়ে বড়, সেটাই উত্তর
            break;  // পেয়েই বের হয়ে গেলাম
        }
    }

    return ans;
}
🔁 ধাপে ধাপে কী হচ্ছে:
ধরে নিচ্ছে letters[0] হচ্ছে উত্তর, যদি target-এর থেকে বড় কোনো অক্ষর না পাওয়া যায়।

তারপর পুরো অ্যারে ঘুরে দেখে letters[i] > target কিনা।

যেই অক্ষরটা target এর চেয়ে বড় পায়, সেটাই ans করে নেয় এবং break করে বেরিয়ে আসে।

না পেলে letters[0] রিটার্ন হয়।

