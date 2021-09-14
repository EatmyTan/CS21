#include<iostream>
using namespace std;
class Package{
    public:
    double cost, weight;
    void setVar(double weight, double cost){
        this->cost = cost;
        this->weight = weight;
    }
    double calculateCost(void){
        return (cost*weight);
    }
};
class TwoDayPackage: public Package{
    public:
    double addFee;
    void setFee(double fee){
        this->addFee = fee;
    }
    double calculateCost(void){
        return ((cost*weight)+addFee);
    }
};
class OvernightPackage: public Package{
    public: 
    double addFee;
    void setFee(double fee){
        this->addFee = fee;
    }
    double calculateCost(void){
        return ((cost*weight)+(addFee*weight));
    }
};
int main(){
    Package a; TwoDayPackage b; OvernightPackage c;
    double weight, cost, addFee1, addFee2;
    cin >> weight >> cost >> addFee1 >> addFee2;
    a.setVar(weight, cost); b.setVar(weight, cost); c.setVar(weight, cost);
    b.setFee(addFee1); c.setFee(addFee2);
    printf("%.02f ", a.calculateCost());
    printf("%.02f ", b.calculateCost());
    printf("%.02f ", c.calculateCost());
}