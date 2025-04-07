Amar 1 ta string ase .Jokhon ami string e i lettter pabo tokhon oi letter er index theke 0 porjonto reverse korbo r bakigula mane i er porer index er character same 
order e hbe and string return korbo
  So,
  Ami first e 1 ta function banai string reverse er jonno main function er baire.1 ta string nei ans="";
ব্যাখ্যা: কেন i = s.size() - 1 থেকে শুরু করে i >= 0 পর্যন্ত চলে?
🔷 ১. string s = "hello";
Index	Character
0	h
1	e
2	l
3	l
4	o
👉 এখানে s.size() = 5
👉 কিন্তু লাস্ট ক্যারেক্টার "o" এর ইনডেক্স = 4 = s.size() - 1

🔁 লুপ ব্যাখ্যা:
cpp
Copy
Edit
for(int i = s.size() - 1; i >= 0; i--)
👉 এই লুপটি কাজ করে পিছন দিক থেকে — অর্থাৎ:

প্রথমে i = 4 → s[4] = 'o'

তারপর i = 3 → s[3] = 'l'

...

শেষবার i = 0 → s[0] = 'h'

এভাবে লুপ চলতে চলতে পুরো স্ট্রিংটি উল্টে ans এ গিয়ে জমে যায়।

✅ কেন decreasing order?
কারণ আমরা স্ট্রিং-এর শেষ ক্যারেক্টার থেকে শুরু করে প্রথম ক্যারেক্টার পর্যন্ত যেতে চাই।

increasing হলে আমরা s[0], s[1], ... পেতাম (মানে forward direction),

কিন্তু reverse করতে হলে আমাদের দরকার: s[n-1], s[n-2], ..., s[0] (মানে backward direction)

🔚 সোজা কথায়:
এই লুপটি decreasing order এ চলে কারণ আমরা স্ট্রিংটিকে উল্টো দিক থেকে পড়তে চাই, যেন নতুন স্ট্রিংয়ে তা reverse আকারে জমে।
