Amar 2 ta integer ase left right .Ei [left,right] ei range er moddhe self dividing kongula oita array akare return korte bolse.So, 1st e ami 1 ta array vector create 
kori jar nam ans.
  1 ta function banai alada isselfdividing  eta nei karon code er readability barai.
  Self dividing number hoilo jei number tar prottekta digit dia divisible hoy.Bar bar perform kori.1 ta variable nei selfdividing ja initial false. Eta dia test korbo.
  Tai 1 ta while loop nei jekhane n>0. 1 ta int nei rem=n%10;
seshe dei n=n/10; karon 128 first test 128%8==0 ;128%2==0;128%1==0
  check kori if(n%rem==0) true hoile 
selfdividing=true;
return kori selfdividing.
  Er por main function 
i=left theke i<=right porjonto for loop chalai
Selfdividing(i) 
true hoy taile
ans.push_back(i);
return kori ans.


  
