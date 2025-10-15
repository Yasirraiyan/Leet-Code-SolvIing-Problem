সমস্যা (Problem):

আপনি একটি Item List Manager তৈরি করতে চাইছেন যেখানে:

ব্যবহারকারী ইনপুট বক্সে আইটেম টাইপ করবে।

"Add Item" বাটনে ক্লিক করলে আইটেমটি লিস্টে যোগ হবে।

লিস্টটি ডাইনামিকভাবে দেখাবে।

সমাধানের পদ্ধতি (Solution Approach):
১️⃣ State (অবস্থা) ব্যবস্থাপনা

React-এ state ব্যবহার করা হয় এমন ডেটা সংরক্ষণের জন্য যা UI-তে পরিবর্তন ঘটালে স্বয়ংক্রিয়ভাবে রেন্ডার হবে।

const [items, setItems] = useState([]); // লিস্টের জন্য state
const [input, setInput] = useState(""); // ইনপুট বক্সের মানের জন্য state


items: লিস্টে যোগ হওয়া সমস্ত আইটেম রাখবে।

input: ইনপুট বক্সে বর্তমানে টাইপ করা মান রাখবে।

useState দ্বারা state শুরু হয় ([] বা "")।

কেন: React যখন state পরিবর্তিত হয় তখন UI স্বয়ংক্রিয়ভাবে রিফ্রেশ হয়।

২️⃣ Controlled Input

Input বক্সকে controlled component বানানো হয়েছে:

<input
  value={input}
  onChange={(e) => setInput(e.target.value)}
/>


value={input} → ইনপুটের মান state থেকে আসে।

onChange → ব্যবহারকারী যখন টাইপ করে, তখন state আপডেট করে।

কেন: এটা React-এর সঠিক পদ্ধতি যাতে input এবং state সবসময় সমন্বিত থাকে।

৩️⃣ আইটেম যোগ করা (Adding Items)

যখন ব্যবহারকারী Add Item বাটনে ক্লিক করে:

const handleAddItem = (e) => {
  e.preventDefault();          // পেজ রিফ্রেশ বন্ধ করে
  if(input.trim() !== "") {    // খালি মান যোগ না করার জন্য
    setItems([...items, input]); // নতুন আইটেম লিস্টে যোগ
    setInput("");               // ইনপুট ক্লিয়ার
  }
};


e.preventDefault() → ফর্মের ডিফল্ট রিফ্রেশ বন্ধ করে।

input.trim() !== "" → খালি স্ট্রিং যোগ করা রোধ করে।

setItems([...items, input]) → spread operator ব্যবহার করে পুরোনো লিস্টের আইটেমগুলো কপি করে নতুন আইটেম যোগ করা।

setInput("") → ইনপুট বক্স ফাঁকা করা।

React ধারণা: state immutable ভাবে আপডেট করা। সরাসরি পুরোনো array পরিবর্তন করা ঠিক নয়।

৪️⃣ লিস্ট রেন্ডার করা (Rendering List)

লিস্টটি ডাইনামিকভাবে দেখানো হয়েছে map ব্যবহার করে:

<ul>
  {items.map((item, index) => (
    <li key={index}>{item}</li>
  ))}
</ul>


map → items array এর প্রতিটি আইটেমে ইটারেট করে।

<li> → প্রতিটি আইটেম প্রদর্শন।

key={index} → React কে প্রতিটি আইটেম আলাদা চেনার জন্য।

React ধারণা: JSX + ডাইনামিক rendering।

৫️⃣ JSX এবং Component Structure

React component JSX ব্যবহার করে UI define করে:

<>
  <h8k-navbar header="Item List Manager" />
  <div className="App"> ... </div>
</>


<h8k-navbar> → কাস্টম component।

<div className="App"> → app container।

{} → JavaScript expressions JSX-এ embed করার জন্য।

৬️⃣ সবকিছু একত্রিত করা

পদ্ধতি:

State তৈরি করুন (input ও items)।

Controlled input তৈরি করুন।

Add button handler → state আপডেট।

List render → map + key।

React মূল ধারণা এখানে ব্যবহার হয়েছে:

useState → state management

Event handling → onChange, onClick

Controlled component → input value state-এ সংযুক্ত

JSX rendering → ডাইনামিক UI

Immutable update → [...items, input]

কী শিখলাম:

React UI reactive → state পরিবর্তন হলে স্বয়ংক্রিয় রেন্ডার।

Array/objects state immutable ভাবে আপডেট করতে হবে।

Controlled inputs ফর্মে React best practice।

map + key → ডাইনামিক list rendering।

💡 Extra Tip:
পরবর্তী ধাপে, প্রতিটি item-এর পাশে Remove button যুক্ত করলে আপনি আরও React concept শিখবেন, যেমন event per item এবং state filtering।
