/*
  NULLはstdlibで定義されている. stdlibはcのために書かれているので、
  cbcに読み込むと多くがコンパイルエラーになる。
 */
#define NULL ((void*)0)

code
s0(char** w, char *p, int i, (*exit0)(char**, char*), void* env)
{
    if (*p=='\0') {
	w[i] = NULL;
	goto exit0(w, p), env;
	
    } else if (*p==' ') {
	*p='\0';
	w[i++] = ++p;
	goto s0(w, p, i, exit0, env);
    } else {
	p++;
    }
    goto s0(w, p, i, exit0, env);
}

void
separate(char** w, char *buf)
{
    /*
      この場合のreturn, environmentは特別な変数
     */
    goto s0(w, buf, 0, return, environment);
}
