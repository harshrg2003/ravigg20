#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c,Deno,i=sqrt(-1);
    float discre,r1,r2;
    printf("Enter the values for a,b,c\n");
    scanf("%d%d%d",&a,&b,&c);
    Deno=2*a;
    discre=b*b-4*a*c;
    if(discre>0)
    {
        r1=-b+sqrt(discre)/Deno;
        r2=-b-sqrt(discre)/Deno;
        printf("Root 1=%f\n",r1);
        printf("Root 2=%f\n",r2);
    }
    else if(discre==0)
    {
        r1=-b/Deno;
        r2=-b/Deno;
        printf("Root1=%f\n",r1);
        printf("Root2=%f\n",r2);
    }
    else if(discre<0)
    {
        r1=a+(i*b);
        r2=a-(i*b);
        printf("Imaginary root=%f\n",r1);
        printf("Imaginary root=%f\n",r2);
    }
    else
    printf("Not valid\n");
}
