Amar 1 ta string ase command.
Amar jodi string e G pawa jay taile G thakbe change nai
Amar jodi string e () pawa jay taile etar pori borte o add hbe
Amar jodi  string e (al) pawa jay taile etar pori borte al add hbe
Amar final string chaise
So,
as string chaise return type tai first e 1 ta string nei ans ja initial empty ba "";
1 st e 1 ta for loop chalai i=0 to i<command.size() porjonto i++ kori string travesre kori
check charcter 
if(command[i]=='G')
hoy taile 
 ans+="G"; kori
So,
  if(command[i]=='G')
          {
            ans+="G";
          }
check () etar jonno breakdown kore check korbo
pashapashi ba adjacent i=( and i+1=)
jodi "()" hoy taile "o" add hbe
So,
   if(command[i]=='('&&command[i+1]==')')
          {
            ans+="o";
          }
check (al)
4 ta character :(,a,l,)
So,
  i,i+1,i+2,i+3
  So,
   if(command[i]=='('&&command[i+1]=='a'&&command[i+2]=='l'&&command[i+3]==')')
  hoy 
taile 
(al) add hbe 
Condition:
----------

  if(command[i]=='('&&command[i+1]=='a'&&command[i+2]=='l'&&command[i+3]==')')
          {
            ans+="al";
          }
Chaise utimate string 
So,
return ans.
