#include<stdio.h>
int main()
{
    int data[10]={12,7,25,18,31,9,42,15,27,36};
    int searchValue;
    int position=-1;
    printf("Enter a number to seach:");
    scanf("%d",&searchValue);
    for(int i=0;i<10;i++)
    {
        if(data[i]==searchValue)
        {
            position=i;
            break;
        }
    }

    if(position!=-1)
        {
            printf("%d is found at index %d\n",searchValue,position);
        }
        else{
            printf("%d is not found in array.\n",searchValue);

        }
        return 0;




}

