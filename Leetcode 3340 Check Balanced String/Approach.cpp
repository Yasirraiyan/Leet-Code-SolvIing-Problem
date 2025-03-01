Amar 1 ta string deya ase number ba int er.jar nam num.String ta balanced hbe jodi ei string er even index er value gular sum ar odd index value gular sum same hoy.

Approach:
---------
  1st e 1 ta variable nei bool isbalanced ja initial true;
duita variable nei int type ans1 ans2 eder moddhe even index er  value r sum r odd index value r sum rakbo.Ete compare korte subidha hbe equal kina.

so,
  1 st e 1 ta for loop chlai i=0 to i<num.size() porjonto and protibar i++ kori.Eta dia string traverse kori.


check even index:
------------------
  if(i%2==0)
        {
          ans1+=num[i]-'0';
        }
true hoile if(i%2==0) true hoile ans1+=num[i]-'0'

Note:
------
  Jodi string k integer convert korte chai mane jdi string er index value (0-9) porjonto thake taile ei system  (ans1+=num[i]-'0')

  check odd index:
------------------
  if(i%2!=0)
        {
          ans2+=num[i]-'0';
        }
check for balanced:
--------------------

   if(ans1!=ans2)
       {
        isbalanced=false;
       }
not equal test karon initial value of isbalanced=true.
tai opposite test for extract from the for loop quickly.
  By this runtime or time complexity is reduced.
  
return kori isbalanced.
