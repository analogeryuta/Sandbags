#include <stdio.h>
#include <string.h>



int
main()
{
    char *str = "hogefuga";
    char *spce = " ";

    fprintf(stdout, "%s\n", str);
    fprintf(stdout, "%s%s%s\n", str, spce, str);

    return 0;
}
