/*

Type is like a local variable to the macro. &type gives the address of the variable 
(double x) declared in the program and incrementing it with 1 gives the address where the 
next variable of type x can be stored (here addr_of(x) + 8, for the size of a double is 8B).
The difference gives the result that how many variables of type of x can be stored in that 
amount of memory which will obviously be 1 for the type x (for incrementing it with 1 and 
taking the difference is what we’ve done). Typecasting it into char* and taking the 
difference will tell us how many variables of type char can be stored in the given memory 
space (the difference). Since each char requires the only 1B of memory, therefore 
(amount of memory)/1 will give the number of bytes between two successive memory locations 
of the type of the variable passed on to the macro and hence the amount of memory that the 
variable of type x requires.But you won’t be able to pass any literal to this macro and 
know their size.

*/

#include<stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
int main()
{
    int x;
    printf("%ld", my_sizeof(x));
    getchar();
    return 0;
}

