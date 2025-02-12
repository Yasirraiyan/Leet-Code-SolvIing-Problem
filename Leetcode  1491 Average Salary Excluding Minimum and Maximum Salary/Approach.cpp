Amar 1 ta array ase jar nam salary.Amar ei array minimum ar maximum value total theke bad dia remain valuer avarage chaise.
So, at first 1 ta varaible nei sum ja initial 0.
1 ta loop chalai for i=0 to i<n porjonto
protibar 
sum+=salary[i] kori Eta dia sum bair kori array r sob valuer.
min max ber korar jonno
initial dhori 
min=salary[0];
max=salary[0];
check kori
if(salary[i]>max)
{
max=salary[i];
}
if(salary[i]<min)
{
min=salary[i];
}
min max bad dite hoy
taile 
sum=sum-min-max;
array r size hobe 2 ta bad disi so, (salary.size()-2);
1 tavariable nei avg ja double chaise double e ans;
avg=(sum=sum-min-max)/(salary.size()-2);
return kori avg.
