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


Concept of React:
--------------------

  ১. useState Hook
const [currIndex, setCurrIndex] = useState(0);


Concept: State Management

কেন ব্যবহার: React component re-render করতে state দরকার। এখানে আমরা track করছি কোন slide দেখানো হচ্ছে।

কীভাবে কাজ করছে:

currIndex → current slide-এর index।

setCurrIndex() → এই function দিয়ে আমরা currIndex update করি।

State update হলে React আবার component re-render করে এবং নতুন slide দেখায়।

Bangla Example:

currIndex = 0   // প্রথম slide
setCurrIndex(1) // next click করলে currIndex=1 হবে, slide 2 দেখাবে

২. Event Handling
<button onClick={handleNext}>Next</button>


Concept: Handling user interactions

কেন ব্যবহার: Button click এ আমরা slide change করতে চাই।

কীভাবে কাজ করছে:

React-এ onClick event দিয়ে function bind করা হয়।

Click করলে handleNext run হয়, এবং state update হয়।

Bangla Example:

Next button চাপলে handleNext() run হবে।

৩. Conditional Rendering / Props Use
disabled={currIndex === slides.length - 1}


Concept: Conditional rendering / dynamic props

কেন ব্যবহার: Button disable করতে চাই যখন last slide এ পৌঁছেছি।

কীভাবে কাজ করছে:

JavaScript condition দিয়ে JSX element props dynamic set করা যায়।

যদি currIndex === slides.length - 1 সত্য হয়, Next button disable হবে।

Bangla Example:

if(currIndex === 0){
   Prev button disabled
}
if(currIndex === slides.length-1){
   Next button disabled
}

৪. Props
function Slides({ slides })


Concept: Passing data to components

কেন ব্যবহার: Slide data parent থেকে child component এ পাঠানোর জন্য।

কীভাবে কাজ করছে:

slides array parent component থেকে Slides component এ পাঠানো হচ্ছে।

আমরা slides[currIndex].title এবং slides[currIndex].text ব্যবহার করে display করছি।

৫. JSX
<div id="slide" className="card text-center">
  <h1>{slides[currIndex].title}</h1>
  <p>{slides[currIndex].text}</p>
</div>


Concept: Declarative UI / JSX

কেন ব্যবহার: UI element তৈরি করতে।

কীভাবে কাজ করছে:

আমরা variable (slides[currIndex].title) সরাসরি JSX-এ inject করতে পারি।

React automatically re-render করে যখন state change হয়।

৬. Functional Component
function Slides({ slides }) { ... }


Concept: Functional Components

কেন ব্যবহার: Modern React-এ functional component state ও hooks support করে।

কীভাবে কাজ করছে:

Component একটি function যা props নেয়।

Return করে JSX UI।

State change হলে React পুনরায় function run করে এবং নতুন UI দেখায়।

✅ সংক্ষেপে

useState: state tracking & re-rendering

Event handling: handle user actions like Next/Prev/Restart

Props: parent থেকে data receive করা

Conditional Rendering: buttons disable করা based on state

JSX: declarative UI

Functional Component: modern React style
