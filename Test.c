#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day;
    do{ printf("Enter the number b/w 1 to7:");
        scanf("%d",&day);
        switch(day){
        case 1:printf("Monday \n");
        break;
        case 2:printf("Tuesday \n");
        break;
        case 3:printf("Wednesday\n");
        break;
        case 4:printf("Thursday\n");
        break;
        case 5:printf("Friday\n");
        break;
        case 6:printf("Saturday\n");
        break;
        case 7:printf("Sunday\n");
        break;
        default:printf("invalid \n");

        }

    }while(day<0 || day>=7);
    return 0;
}