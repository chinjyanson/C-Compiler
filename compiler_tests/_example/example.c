int g()
{
    int x = 15;
    int *y=&x;
    y=&x;
    return *y;
}
