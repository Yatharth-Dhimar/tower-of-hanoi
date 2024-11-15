//Tower Of Hanoi 


#include <stdio.h>

void display_game(int t1[], int t2[], int t3[], int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%d   %d   %d", t1[i], t2[i], t3[i]);
        printf("\n");
    }
    printf("----------\nA   B   C\n");
}


int game_end(int t[], int ans[], int n)
{
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        if(t[i] == ans[i])
        {
            ++count;
        }
    }
    if(count == n)
        return 1;
    else 
        return 0;
}


//index before index with non-zero value or last index
int last_idx(int arr[], int size)   //size = n number of stacks
{
    int i = 0;
    for(i; (arr[i+1] == 0) && (i != size-1); ++i);
    return i;
}


int main()
{
    int t1[10], t2[10], t3[10], ans[10];
    int n, count;
    char temp1;
    char temp2;

    printf("enter the number of stacks : ");
    scanf("%d", &n);

    //towers in the beginning
    for(int i=0; i<n; ++i)
    {
        t1[i] = i+1;        //original tower containing n stacks
        ans[i] = i+1;       //will be used to compare t2 or t3 at the end
    }
    for(int i=0; i<n; ++i)
    {
        t2[i] = 0;
        t3[i] = 0;
    }

    display_game(t1, t2, t3, n);

    while(1)
    {
        printf("change from _ to _ tower : ");
        scanf(" %c %c", &temp1, &temp2);        //space before %c is IMP

        if((temp1 == 'A') && (temp2 == 'B'))
        {
            for(int i=0; i<n; ++i)
            {
                if(t1[i] != 0)
                {
                    t2[last_idx(t2, n)] = t1[i];
                    t1[i] = 0;
                    break;
                }
            }
        }
        else if((temp1 == 'A') && (temp2 == 'C'))
        {
            for(int i=0; i<n; ++i)
            {
                if(t1[i] != 0)
                {
                    t3[last_idx(t3, n)] = t1[i];
                    t1[i] = 0;
                    break;
                }
            }
        }
        else if((temp1 == 'B') && (temp2 == 'A'))
        {
            for(int i=0; i<n; ++i)
            {
                if(t2[i] != 0)
                {
                    t1[last_idx(t1, n)] = t2[i];
                    t2[i] = 0;
                    break;
                }
            }
        }
        else if((temp1 == 'B') && (temp2 == 'C'))
        {
            for(int i=0; i<n; ++i)
            {
                if(t2[i] != 0)
                {
                    t3[last_idx(t3, n)] = t2[i];
                    t2[i] = 0;
                    break;
                }
            }
        }
        else if((temp1 == 'C') && (temp2 == 'A'))
        {
            for(int i=0; i<n; ++i)
            {
                if(t3[i] != 0)
                {
                    t1[last_idx(t1, n)] = t3[i];
                    t3[i] = 0;
                    break;
                }
            }
        }
        else if(temp1 == 'C' && temp2 == 'B')
        {
            for(int i=0; i<n; ++i)
            {
                if(t3[i] != 0)
                {
                    t2[last_idx(t2, n)] = t3[i];
                    t3[i] = 0;
                    break;
                }
            }
        }

        display_game(t1, t2, t3, n);

        if(game_end(t2, ans, n) == 1)
        {
            printf("\nCONGRATULATIONS.\nGAME CLEARED!!!");
            break;
        }
        if(game_end(t3, ans, n) == 1)
        {
            printf("\nCONGRATULATIONS.\nGAME CLEARED!!!");
            break;
        }
    }

    return 0;
}