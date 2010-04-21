struct huga0 {
    char c;
    short s;
    int i;
    long l;
    float f;
};
struct huga {
    char c;
    short s;
    int i;
    long l;
    float f;
    struct huga0 hh;
};
int main()
{
    struct huga h;
    h.c = 10;
    h.s = 20;
    h.i = 30;
    h.l = 40;
    h.f = 50;
    h.hh.c = 10;
    h.hh.s = 20;
    h.hh.i = 30;
    h.hh.l = 40;
    h.hh.f = 50;
    return (0);
}
