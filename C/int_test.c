#include <stdio.h>


int
main()
{
    int class1, class2;
    int num;

    for (num=0; num<=20; num++) {
	class1 = num/10;
        //class2 = num - ((class1)*10);
	class2 = num%10;

	printf("%d %d\n", class1, class2);
    }

    return 0;
}
