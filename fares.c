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
} while(b == 0);
printf("\n%d + %d= %d", a, b, sommer(a, b));
printf("\n%d - %d= %d", a, b, soustraire(a, b));
printf("\n%d / %d = %f\n", a, b, diviser(a, b));
return (0);
}
//programme
