Amar 1 ta number ase int type.Eta k binary te convert kore duita adjacent 1 er moddhe max distance ber korbo.
  So, ami first e 1 ta vector nei ans.
  Ei vector e ami int er binary convertion er bit gula rakhbo.
  Aro 1 ta vector nei reserve etate ami duita adjacent 1 er moddhe distance calculate kore rakhbo.Karon amr chaise max distance.Taile ami ei array r max number ber kore return korbo.Ete amar kaj easy hbe.

  First Convert binary:
------------------------
  1 ta while loop chalai where n>0. Ekta variable nei rem ja n%2 eta hoilo bit. n=n/2 kori karon ami 2 dia vag kore oita k abr vag korbo.while loop nibo karon bar bar iterate kori jotto n positive hoy.
rem k ans vector e push kori.

  Binary conversation:
------------------------

      while(n>0)
        {
          int rem=n%2;
          ans.push_back(rem);
          n=n/2;
        }
Akhon kaj distance ber kora adjacent 1 gular 1 ta array reserve banai vector ete distance push korbo. Karon amr lagbe max.distance array te push korle max ber kora easy hbe.
  1 ta for loop chalai i=0 to i<ans.size() porjonto ;i++ kori ete first pura array traveerse kori
nested for loop chalai j=i+1 to j<ans.size() porjonto karon ami protitar sathe compare kore distance ber korbo nijer bade so j=i+1
  check kori differene index
if(i!=j) eta dia different index check ensure kori. True hoile Check kori dui index er moddhe store value 1 kina.
  So, 1 ta condition dei:
-------------------------

  if(i!=j)
              {
                if((ans[i]==1)&&(ans[j]==1))
  true hoile distance ber kori
     distance=abs(i-j).
  reserve vector e distance push kori
  So,
   reserve.push_back(abs(j-i));
 Runtime komanor jonno break dei

The full code from if to break:
---------------------------------
  
if(i!=j)
              {
                if((ans[i]==1)&&(ans[j]==1))
                {
                reserve.push_back(abs(j-i));
                break;
                }
              }

Full Code from loop:
---------------------

   for(int i=0;i<ans.size();i++)
        {
          for(int j=i+1;j<ans.size();j++)
          {
              if(i!=j)
              {
                if((ans[i]==1)&&(ans[j]==1))
                {
                reserve.push_back(abs(j-i));
                break;
                }
              }
          }
         
        }

Runtime komanor jonno ekta condition dei reserve e kisu na thakle mane empty hoile 0 return.
  So,
  if(reserve.empty()) 
         {
            return 0;
        }

Ekhon Max distance ber kori:
----------------------------

  Distance ase reserve array te. 
  max ber korar jonno initial max nei reserve[0].
1 ta for loop chalai k=1 to k<reserve.size() porjonto k++ kori
check max:
---------
   if(reserve[k]>max)
          {
            max=reserve[k];
          }

First e 1 ta loop chalai for k=1 to k<reserve.size() porjonto k++ kori

  k=1 theke karon ami 0 index value k max dhorsi nijer sathe compare korbo na ete runtime kome.

  Check max:
--------------
   if(reserve[k]>max)
          {
            max=reserve[k];
          }

Code from for loop:
------------------

   int max=reserve[0];
        for(int k=1;k<reserve.size();k++)
        {
          if(reserve[k]>max)
          {
            max=reserve[k];
          }
        }

As amr chaise max distance tai ami return kori max.
  So,
    return max.
  
