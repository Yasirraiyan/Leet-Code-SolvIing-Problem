Is Prev in React have autometically:?
---------------------------------------

Ans:
------

  is prev are in react autometically


হ্যাঁ ✅, React automatically পাঠায় prev (বা যেটা তুমি parameter নাম দাও) যখন তুমি state updater callback ব্যবহার করো।

ব্যাখ্যা:
const [currIndex, setCurrIndex] = useState(0);

setCurrIndex(prev => prev + 1);


এখানে prev কোনো variable যা তুমি আগে declare করো নি।

এটা React automatically provide করে বর্তমান state value হিসেবে।

তাই তুমি শুধু prev => prev + 1 লিখলেই React internally জানে:
prev = currIndex (current state value)

আরও পরিষ্কারভাবে:

ধরো এখন currIndex = 2

তুমি লিখছো:

setCurrIndex(prev => prev + 1);


React internally করে:

prev = 2;
currIndex = prev + 1; // currIndex becomes 3


আর তুমি সরাসরি prev declare করতে হবে না। React handle করে।

মূল ধারণা:

prev = আগের state

React automatically provide করে যখন তুমি callback updater ব্যবহার করো।

এটা safe approach, বিশেষ করে যখন নতুন state পুরোনোর state এর উপর নির্ভর করে।


Approach:
-----------

  ১. কোডটা কি করছে (Problem Understanding)

Component: Slides
Props: slides → একটা array, যার মধ্যে অনেক slide data আছে।

State:

const [currIndex, setCurrIndex] = useState(0);


currIndex → এখন কোন slide দেখাচ্ছে তার index।

শুরুতে 0, অর্থাৎ প্রথম slide।

Function ১: handleNext

if(currIndex < slides.length - 1){
    setCurrIndex(prev => prev + 1);
}


বোঝাচ্ছে: যদি আমরা এখনও last slide এ না পৌঁছেছি, তখন next এ যেতে পারি।

setCurrIndex(prev => prev + 1) → আগের index থেকে ১ বাড়াচ্ছে।

Function ২: handlePrev

if(currIndex > 0){
    setCurrIndex(prev => prev - 1);
}


বোঝাচ্ছে: যদি আমরা first slide না হয়ে থাকি, previous এ যেতে পারি।

setCurrIndex(prev => prev - 1) → আগের index থেকে ১ কমাচ্ছে।

Function ৩: handleRestart

setCurrIndex(0);


সব সময় slide 0 (প্রথম slide) এ নিয়ে যাবে।

২. Problem-solving Approach (কীভাবে চিন্তা করবে)

১. State চিন্তা করা

তোমার slide কোনটাতে আছো সেটা track করতে হবে।

তাই currIndex state ঠিক আছে।

২. Next ও Prev button handle করা

Next → শুধুমাত্র তখন কাজ করবে যখন last slide এ পৌঁছাইনি।

Prev → শুধুমাত্র তখন কাজ করবে যখন first slide এ নেই।

৩. Restart button handle করা

সবসময় প্রথম slide এ নিয়ে যাবে।

৪. UI Logic

Slide দেখানোর জন্য slides[currIndex] ব্যবহার করা যায়।

Buttons disable/enable করতে পারো যদি first বা last slide এ থাকো।

৩. How to write your approach (Bangla)

প্রথমে বুঝো slide data আছে একটা array তে।

কোন slide দেখাচ্ছে সেটা state দিয়ে track করবে (currIndex)।

Next button চাপলে, check করবে last slide এ কি? না হলে index +1।

Prev button চাপলে, check করবে first slide এ কি? না হলে index -1।

Restart button সবসময় index = 0 set করবে।

Slide দেখানোর জন্য slides[currIndex] ব্যবহার করবে।

৪. Example Diagram (Optional)
slides = ['Slide1','Slide2','Slide3']

currIndex = 0 -> Slide1
Next -> currIndex = 1 -> Slide2
Next -> currIndex = 2 -> Slide3
Next -> can't go (last slide)

Prev -> currIndex = 1 -> Slide2
Prev -> currIndex = 0 -> Slide1
Prev -> can't go (first slide)

Restart -> currIndex = 0 -> Slide1


যদি চাও আমি এই logic দিয়ে পুরো React functional component code লিখে দিই যা slide দেখাবে এবং buttons disable করবে first/last slide অনুযায়ী।
