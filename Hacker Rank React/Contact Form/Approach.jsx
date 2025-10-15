1. State Management (useState)
const [name, setName] = useState("");
const [email, setEmail] = useState("");
const [message, setMessage] = useState("");
const [submittedData, setSubmittedData] = useState(null);
const [error, setError] = useState("");


ব্যাখ্যা (Bangla):
React এ আমরা component-এর ভিতরে ডেটা পরিবর্তন করার জন্য state ব্যবহার করি।

useState হলো একটি React Hook যা আমাদের state variable এবং তার update function দেয়।

উদাহরণ:

name হলো state variable, setName হলো function যা name আপডেট করে।

এখানে আমরা form inputs, submitted data, এবং error message এর জন্য state ব্যবহার করেছি।

React Basic Concept:

Component re-render হয় যখন তার state পরিবর্তন হয়।

এখানে, state change হলে, UI অটোমেটিক আপডেট হয়।

2. Handling Input Changes (Controlled Components)
<input
  type="text"
  value={name}
  onChange={(e) => setName(e.target.value)}
  placeholder="Name"
/>


ব্যাখ্যা (Bangla):

React এ form input সাধারণত controlled component হয়।

Controlled component মানে input-এর value React state দ্বারা control হয়।

onChange event এ আমরা state update করি।

এখানে, user যেই নাম লিখবে তা name state-এ জমা হবে।

Similar for Email & Message inputs.

3. Form Submission & Validation
const handleSubmit = (e) => {
  e.preventDefault(); // page reload বন্ধ করা
  const isValid = name.trim() !== "" && email.trim() !== "" && message.trim() !== "";

  if (isValid) {
    setError(""); 
    setSubmittedData({ name, email, message }); 
    setName("");
    setEmail("");
    setMessage("");
  } else {
    setSubmittedData(null); 
    setError("All fields are required."); 
  }
};


ব্যাখ্যা (Bangla):

e.preventDefault() → browser default behavior (page reload) বন্ধ করে।

isValid → সব field খালি কিনা চেক করে।

যদি valid, তাহলে:

error message clear করা,

submitted data set করা,

input field reset করা।

যদি invalid, তাহলে:

submittedData null করা,

error message দেখানো।

React Concept:

Event handling → onSubmit & onChange

Conditional rendering → if (isValid) {...} else {...}

4. Conditional Rendering
{error && <p className="error">{error}</p>}
{submittedData && (
  <div className="submitted-data">
    ...
  </div>
)}


ব্যাখ্যা (Bangla):

React এ আমরা conditionally component render করতে পারি।

&& operator দিয়ে check করি যদি value truthy হয়।

এখানে:

error থাকলে error message দেখানো,

submittedData থাকলে submitted info দেখানো।

React Basic Concept:

JSX-এ logical operator (&&) ব্যবহার করে conditional rendering করা যায়।

5. Component Structure
<>
  <h8k-navbar header="Contact Form"></h8k-navbar>
  <div className="App">
    ...
  </div>
</>


ব্যাখ্যা (Bangla):

<h8k-navbar> → Custom component (external package h8k-components)

JSX-এ আমরা multiple elements wrap করার জন্য Fragment (<>...</>) ব্যবহার করেছি।

React Concept:

Components → reusable UI pieces

JSX → JavaScript + HTML

✅ Summary of React Concepts Applied Here
Concept	Usage in Code
State (useState)	name, email, message, submittedData, error
Controlled Component	Form inputs (value + onChange)
Event Handling	onSubmit, onChange
Conditional Rendering	Show error / submitted data based on state
Component Structure / JSX	<h8k-navbar> + <form> + wrapping with <>...</>
Form Validation	Simple empty field check before submitting
Resetting Inputs	setName(""), setEmail(""), setMessage("") after successful submission
Solution Approach Summary (Bangla)

প্রথমে form input-এর জন্য state তৈরি করা।

প্রতিটি input কে controlled component বানানো (value + onChange)।

Form submit হলে validation করা (সব field খালি নয় কিনা)।

Validation ঠিক হলে state update করে submitted data show করা।

Validation fail হলে error message show করা।

Conditional rendering দিয়ে error / submitted data UI-তে দেখানো।
