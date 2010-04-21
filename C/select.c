#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


int
main()
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    //stdin (fd 0) を監視し，入力があった場合に表示する
    //FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    //5秒間監視する
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1) 
	perror("select()");
    else if (retval) 
	printf("データ取得\n");
    else
	printf("5秒以内にデータが入力されませんでした．\n");

    return 0;
}
