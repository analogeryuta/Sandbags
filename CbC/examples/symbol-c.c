extern int printf(char*,...);
void test_func(){
}
unsigned long addrs[]={
     (unsigned long)test_func,
     0,
};
int main()
{
     int i;
     for(i=0;addrs[i]>0;i++) printf("%lx\n",addrs[i]);
     printf("%lx\n",(unsigned long)test_func);
     return(0);
}
