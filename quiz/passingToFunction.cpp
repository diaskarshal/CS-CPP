#include <iostream>
int& something( int x, int *y, int& z, int w[] ){
    w[0] = w[1]; 
    w[1] = w[0];
    x = 101;
    *y = 202;
    z = 303;
    return w[0];
}

void myfunction(){
    int a = 404, b = 505, c = 606, d[2]; 
    d[0] = 707; d[1] = 808;
    int& e = something (a, &b, c, d);
    std::cout << a << " " << b << " " << c << " " << d[1] << " " << e << std::endl;
    int f = something (909, &c, e, d);
    std::cout << c << " " << e << " " << d[0] << " " << d[1] << " " << f << std::endl;

    e = 50;
    std::cout << e << " " << d[0] << " " << f;
}
// [404] [202] [303] [808] [808]
// [202] [303] [303] [808] [303]
int main(){
    myfunction();
}