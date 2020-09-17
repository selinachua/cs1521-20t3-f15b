/**
 * This file looks at the scope of variables.
 * 
 * a) Which variables are accessible from within main()?
 * 
 * b) Which variables are accessible from within fun2()?
 * 
 * c) Which variables are accessible from within fun1()?
 * 
 * d) Which variables are removed when fun1() returns?
 * 
 * e) Which variables are removed when fun2() returns?
 * 
 * f) How long does the variable f exist during program execution?
 * 
 * g) How long does the variable g exist during program execution?
 * 
 */

int  a;
char b[100];

int fun1() {
    int c, d;
    ...
}

double e;

int fun2() {
    int f;
    static int ff;
    ...
    fun1();
    ...
}

int g;

int main(void) {
    char h[10];
    int i;
    ...
    fun2()
    ...
}