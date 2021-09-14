#include<iostream>
#include<string>

using namespace std;

class Fraction{
    public:
    int num, den;
    Fraction(){
        num = 1;
        den = 1;
    }
    void setNum(int x){
        this->num = x;
    }
    void setDen(int x){
        this->den = x;
    }
    void displayFrac(Fraction x){
        cout << x.num;
        if(x.den!=1)
            cout << '/' << x.den;
    }
    int gcd(int x, int y){
        int r;
        while(x%y>0){
            r = x%y;
            x = y;
            y = r;
        }
        return y;
    }
    void simplify(Fraction sum){
        int g = gcd(sum.num, sum.den);
        Fraction s; 
        s.setNum(sum.num/g);
        s.setDen(sum.den/g);
        displayFrac(s);
    }
    void addition(Fraction x, Fraction y){
        int lcd = (x.den * y.den);
        Fraction sum;
        sum.setDen(lcd);
        sum.setNum((lcd/x.den)*x.num + (lcd/y.den)*y.num);
        sum.simplify(sum);
    }
    void subtraction(Fraction x, Fraction y){
        int lcd = (x.den*y.den);
        Fraction difference;
        difference.setDen(lcd);
        difference.setNum((lcd/x.den)*x.num - (lcd/y.den)*y.num);
        difference.simplify(difference);
    }
    void multiplication(Fraction x, Fraction y){
        Fraction product;
        product.setNum(x.num*y.num);
        product.setDen(x.den*y.den);
        product.simplify(product);
    }
    void division(Fraction x, Fraction y){
        Fraction quotient;
        quotient.setNum(x.num*y.den);
        quotient.setDen(x.den*y.num);
        quotient.simplify(quotient);
    }
};
    int strCheck(string x){ // checks for the 
        int len  = x.size();
        for(int i = 0; i<len; i++){
            if(x[i] == '/')
                return i;
        }
        return 0;
    }
    Fraction strToFrac(string x){
        Fraction temp;
        if(strCheck(x)!=0){
            temp.setNum(stoi(x.substr(0, strCheck(x))));
            temp.setDen(stoi(x.substr(strCheck(x)+1, x.size())));
        }
        else{
            temp.setNum(stoi(x));
            temp.setDen(1);
        }
        return temp;
    }
int main(){
    int choice;
    cin >> choice;
    string a, b;
    Fraction frac1, frac2, frac3;
    if(choice >= 1 && choice <=4){
        cin >> a >> b;
        frac1 = strToFrac(a);
        frac2 = strToFrac(b);
        switch(choice){
            case 1: frac3.addition(frac1, frac2); break;
            case 2: frac3.subtraction(frac1, frac2); break;
            case 3: frac3.multiplication(frac1, frac2); break;
            case 4: frac3.division(frac1, frac2); break;
        }
    }
    else{
        cin >> a;
        frac1 = strToFrac(a);
        frac1.simplify(frac1);
    }
}