/*
  ファイルの読み込み(fopen, fclose, fgetsとか)の練習
  いまさらか....
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*
open_file(char *file)
{
    FILE *fp;
    if (!(fp=fopen(file, "r"))) {
	fprintf(stderr, "error : read file : %s\n", file);
	exit(EXIT_FAILURE);
    }
    return fp;
}

void
print_data(FILE *fp)
{
    char *buf_ptr, buf[BUFSIZ];
    char *tmp;

    tmp = (char *)malloc(sizeof(char));

    while ((buf_ptr=fgets(buf, sizeof(buf), fp))!=NULL) {
	fprintf(stdout, "line buf : %s", buf_ptr);
	fprintf(stdout, "strlen : %d\n", strlen(buf_ptr));

	strncpy(tmp, buf_ptr, strlen(buf_ptr)-1);
	fprintf(stdout, "copy buf : %s\n", tmp);
	fprintf(stdout, "copylen : %d\n", strlen(tmp));
    }
}
    
void
close_file(FILE *fp)
{
    fclose(fp);
}

int
main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2) {
	fprintf(stderr, "Usage : %s [file_name]\n", argv[0]);
	return EXIT_FAILURE;
    } else {
	fp = open_file(argv[1]);
	print_data(fp);
	close_file(fp);
    }
    return 0;
}
