#include<stdio.h>
int
aho()
{
    static int count=0;
    printf("aho%d\n", count++);
    return(0);
}
int (*lis[])()={
    aho,
    aho,
    aho,
    aho,
    aho,
    aho,
    aho,
    (void*)0,
};
int
main()
{
    int i;
    for(i=0;lis[i]!=(void*)0;i++){
	lis[i]();
    }
    return(0);
}
