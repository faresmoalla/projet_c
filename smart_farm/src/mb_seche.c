
#include <stdio.h>
#include <string.h>

int seche_f(int *s_2017,int *s_2018,int *s_2019,int *s_2020)
{
    FILE *f;

    int d1=0,d2=0,d3=0,d4=0;
    int s1=0,s2=0,s3=0,s4=0;
    float f1;

    f=fopen("temperature.txt","r");
    if(!f)
        g_print("temperature.txt couldnt be opened\n");
    else
    {
        while(fscanf(f,"%d %d %d %d %f\n",&d1,&d2,&d3,&d4,&f1)!=EOF)
        {
            switch(d4)
            {
                case 2017:
                    s1+=(int)f1;
                    break;
                case 2018:
                    s2+=(int)f1;
                    break;
                case 2019:
                    s3+=(int)f1;
                    break;
                case 2020:
                    s4+=(int)f1;
                    break;
            }
        }

        int max=s1;
        int max_a=2017;
        if(s2>max)
        {
            max=s2;
            max_a=2018;
        }
        if(s3>max)
        {
            max=s3;
            max_a=2019;
        }
        if(s4>max)
        {
            max=s4;
            max_a=2020;
        }
        g_print("max : %d\n",max);


        *s_2017=s1;
        *s_2018=s2;
        *s_2019=s3;
        *s_2020=s4;  

        g_print("%d %d \n",s_2017,s_2018);

        fclose(f);
        return max_a;
    }

    return 0;
}