//階乗を求めるプログラム．
//論文の例題に良く出るやつを書いてみた
#include <stdio.h>

code (*ret)();
void *env;

code 
print(int i)
{
    printf("result : %d\n", i);

    //main関数へreturnする．
    goto ret(0),env;
}

code 
fact(int n, int reslt, code (*print)(int))
{
    if (n>0) {
	reslt += n;
	n--;
	goto fact(n, reslt, print);
    } else {
	goto print(reslt);
    }
}

int
main()
{
    int input=10;
    int reslt=0;

    ret = return;
    env = environment;

    goto fact(input,reslt, print);
}
