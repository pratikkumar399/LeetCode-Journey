int sign = 1 ,  base = 0 , i = 0 ;
// what we have to do is that we have to ignore the whitespaces
// and also take casre that if there is a negative sign then the number remains negative at last
// so the approach can be that if there is any whitespace in the beginning simply ignore the whitespaces
// and also if there is a negiatuve sign then simply store the sign in a veriable and then simply what we can do is that at last multiply the number with that sign
// this will give us the requred answer
while(str[i] == ' '){
// ignoring the whitespaces
i++ ;
}
if (str[i] == '-' || str[i] == '+')
{
sign = 1 - 2 * (str[i++] == '-');
}
while(str[i] >= '0' && str[i] <= '9' ){
if (base > INT_MAX / 10
|| (base == INT_MAX / 10
&& str[i] - '0' > 7))
{
if (sign == 1)
return INT_MAX;
else
return INT_MIN;
}
base = 10 * base + (str[i++] - '0');
}
return base * sign;
}