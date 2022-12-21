int size = nums.size() ;
int breakPoint= 0 ;
for(int i = 0 ; i < size ; i++){
if(nums[i] >  nums[(i+1) % size]) breakPoint++ ;
if(breakPoint == 2) return false ;
}
return breakPoint<=1 ;