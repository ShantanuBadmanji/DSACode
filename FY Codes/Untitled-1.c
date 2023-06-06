#include<stdio.h>

int main(){
    int z;
    char x= 'a',y='b';
    z = x + y;          //the var store the ascii value of the char.

    printf("ok its %d \n\n",z);  

    //----------------------------------------------------------------------------------------------
    
    
    printf("div 9/2 is %d\n",9/2);   //if both oparands are int then div is also int  else the div is float.
    printf("div 9/2 is %f\n",9.0/2.0);
    printf("div 9/2 is %f\n",9.0/2);
    printf("div 9/2 is %f\n\n",9/2.0);

    //----------------------------------------------------------
    int p,q;
    float a,b;

    p = 5;q=6;
    a=5 + 6;
    b= p+q;

    printf("sum of int directly assigned to float var is %f\n",b); //the int sum upgrdes to float.

    a=5;b=6;
    p=5+6;
    q = a+b;

    printf("sum of float directly assigned to int var is %d\n",q); //the float sum degraded to int.

    return 0;
}