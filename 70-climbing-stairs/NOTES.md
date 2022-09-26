int prev = 1 ;
int next = 1 , current  ;
if(n < 2) return  n ;
for(int i = 2 ; i<=n ; i++){
current = prev + next ;
prev = next ;
next = current ;
}
return current ;