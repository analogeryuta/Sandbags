extern int printf(char*,...);
code test_code(int a){
     goto test_code(a);
}
void test_func(){}
unsigned long addrs[]={
     test_code,
     test_func,
     0,
};
int
main()
{
     int i;
     for(i=0;addrs[i]>0;i++){
	  printf("%lx\n",addrs[i]);
     }
     printf("%lx\n",(unsigned long)test_code);
     printf("%lx\n",(unsigned long)test_func);
}
