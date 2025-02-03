Amar 1 ta string ase jar nam move.Amar check korte hbe robot (0,0) position e ashe kina.Er jonno duita variable nai X,Y ja initial 0.
So, amar pura string traverse er jonno 1 ta for loop chali i=0 to i<moves.size() porjonto
Condition check
if(moves[i]=="U") kina hoile upore jay so y++;
if(moves[i]=="D") kina hoile upore jay so y--;
if(moves[i]=="R") kina hoile upore jay so x++;
if(moves[i]=="L") kina hoile upore jay so x--;
last chek
 if(x==0&&y==0) mane origin
return true;
else 
return false.

