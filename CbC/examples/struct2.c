extern int printf(char*,...);
struct enemy{
    float x;			// x location
    float y;			// y location
    int charno;			// image number
    int ap;			// armor point
};
void
print_param(struct enemy *e)
{
    printf("charno:%d   x,y:%f,%f   hp:%d\n",
	   e->charno,e->x,e->y,e->ap);
}
int
main()
{
    struct enemy e;
    e.charno=5; e.x=50.0; e.y=30.0; e.ap=100;
    print_param(&e);
    return(0);
}
