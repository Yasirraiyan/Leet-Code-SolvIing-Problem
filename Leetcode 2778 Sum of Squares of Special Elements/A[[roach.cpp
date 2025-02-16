Amar 1 ta array ase 1-indexed. Amar chaise sum sobgula element er square der.Jara array te ase.
First e 1 ta variable nei sum ja initial 0.
1 ta for loop chalai i=1 to i<=n porjonto karon array 1 indexed.
Jodi array r size 4 hoy
  1- indexed array te index gula hoilo 1,2,3,4
  But cpp ba C++ e array hoilo 0-indexed ja built in
So, 1 indexed array r indexed gula 0-indexed banaite hobe
Mane jokhon 4 size array te 0-indexed e index gula hoilo  0,1,2,3
4 size array te 1 indexed gula hoilo 1,2,3,4
  as 1-indexed ke 0-indexed e nibo 
so,
  1 hbe 0
  2 hbe 1
  3 hbe 2
  4 hbe 3
  0=1-1;=i-1; i hoilo 1 indexed measeure i-1 0-indexed rupantor;
 1=2-1;
2=3-1;
3=4-1;
Jodi if(nums.size()%i==0) hoy taile .Karon Eita condition ja qu te ase.
So, Every time sum+=nums[i-1]*nums[i-1]; caron chaise index value gular square sum
return kori sum.
