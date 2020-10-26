#include <stdio.h>
#include "fonctions.h"
int main () {
int a ;
int b ;
printf("\nsaisie du premier nombre:");
scanf("%d",a);
do{
printf("\nsaisie du second nombre:");
scanf("%d",b);
}
while (b==0);
printf("\n %d + %d = %d",a,b,a+b);
printf("\n %d - %d = %d",a,b,a-b);
printf("\n %d / %d = %f",a,b,(float) a/b);
return(0); 
}
