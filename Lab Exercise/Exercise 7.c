#include<stdio.h>
typedef struct{
    int num, den;
} fraction;
fraction a, b;
char slash;
int gcd(int x, int y){
    int r;
    while(x%y>0){
        r = x%y;
        x = y;
        y = r;
    }
    return y;
}
fraction print(fraction c){
    if(c.den == 1){
        printf("%i", c.num);
    }
    else 
        printf("%i/%i", c.num, c.den);
}
fraction simplify(fraction sum){
    int g = gcd(sum.num, sum.den);
    fraction s; 
    s.num = sum.num/g;
    s.den = sum.den/g;
    return s;
}
fraction addition(){
    printf("Fraction Addition\n");
    scanf("%i%c%i %i%c%i", &a.num,&slash,&a.den, &b.num,&slash,&b.den);
    int lcd = (a.den*b.den);
    fraction sum ;
    sum.den = lcd;
    sum.num = ((lcd/a.den)*a.num + (lcd/b.den)*b.num);
    fraction c = simplify(sum);
    print(c);
}
fraction subtraction(){
    printf("Fraction Subtraction\n");
    scanf("%i%c%i %i%c%i", &a.num,&slash,&a.den, &b.num,&slash,&b.den);
    int lcd = (a.den*b.den);
    fraction difference;
    difference.den = lcd;
    difference.num = ((lcd/a.den)*a.num - (lcd/b.den)*b.num);
    fraction c = simplify(difference);
    print(c);
}
fraction multiplication(){
    printf("Fraction Multiplication\n");
    scanf("%i%c%i %i%c%i", &a.num,&slash,&a.den, &b.num,&slash,&b.den);
    fraction product;
    product.num = a.num*b.num;
    product.den = a.den*b.den;
    fraction c = simplify(product);
    print(c);
}
fraction division(){
    printf("Fraction Division\n");
    scanf("%i%c%i %i%c%i", &a.num,&slash,&a.den, &b.num,&slash,&b.den);
    fraction quotient;
    quotient.num = a.num*b.den;
    quotient.den = a.den*b.num;
    fraction c = simplify(quotient);
    print(c);
}
fraction simplification(){
    printf("Fraction Simplification\n");
    scanf("%i%c%i", &a.num,&slash,&a.den);
    fraction c= simplify(a);
    print(c);
}
void checkChoice(int choice){
    if(choice==1)
        addition();
    else if(choice==2)
        subtraction();
    else if(choice==3)
        multiplication();
    else if(choice==4)
        division();
    else if(choice==5)
        simplification();
}
int main(){
    int choice;
    printf("Choice input 1: 2 strings representing fractions follow---A and B; print out result of A + B\n");
    printf("Choice input 2: 2 strings representing fractions follow---A and B; print out result of A - B\n");
    printf("Choice input 3: 2 strings representing fractions follow---A and B; print out result of A * B\n");
    printf("Choice input 4: 2 strings representing fractions follow---A and B; print out result of A / B\n");
    printf("Choice input 5: 1 string representing a fraction follows---A; print out simplified fraction of A\n");
    scanf("%i", &choice);
    checkChoice(choice);
}