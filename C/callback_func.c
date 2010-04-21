#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//メインループ
void 
mainLoop(int (*call_back)(int ));

//コールバック関数
int
fact(int i);

int
main(int argc, char *argv[])
{
    mainLoop(&fact);
    return 0;
}

//メインループ
void 
mainLoop(int (*call_back)(int ))
{
    int sum=0;
    int i=0;

    while (i<10) {
	sum=call_back(i);
	printf("result : %d! = %d\n", i, sum);
	i++;
    }
    return;
}

//コールバック関数
int
fact(int i)
{
    int kekka=1;
    int cnt=i;
    while (cnt>0) {
	kekka *= cnt;
	cnt--;
    }
    return kekka;
}
