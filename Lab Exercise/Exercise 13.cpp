#include<iostream>
using namespace std;
class Point{ // stores the x and y coordinates 
    public:
        float x,y;
        Point(){
            x = 0; y = 0;
        }
        Point(int A, int B){
            this->x = A; this->y = B;
        }
        void setCoords(float A, float B){
            this->x = A; this->y = B;
        }
};
class Rectangle{
    private:
        Point topLeft, bottomRight;
    public:
        Rectangle(int A, int B, int C, int D){
            topLeft.setCoords(A,B);
            bottomRight.setCoords(C,D);
        }
        // Multiplies length and width, length and width is calculated by bottomright - topleft
        void area(){
            int ans = ((bottomRight.x-topLeft.x)*(bottomRight.y-topLeft.y));
            cout << "area: " << ans;
        }
        // perimeter = 2(length + width)
        void perimeter(){
            int perimeter = (2*((bottomRight.x-topLeft.x)+(bottomRight.y-topLeft.y)));
            cout << "\nperimeter: " << perimeter;
        }
        // Calculates the centerpoint of the rectangle
        void centerPoint(){ 
            Point center;
            float x = (bottomRight.x + topLeft.x)/2;
            float y = (bottomRight.y + topLeft.y)/2;
            center.setCoords(x,y);
            printf("\ncenter: (%.02f, %.02f)", center.x, center.y);
        }
        // if length and width are equal that means that the rectangle is a square
        void square(){
            if((bottomRight.x-topLeft.x) == (bottomRight.y-topLeft.y))
                cout << "\nsquare: yes";
            else 
                cout << "\nsquare: no";
        }
        // displays the rectangle 
        void display(){
            cout << "\n";
            for(int j=0; j<=bottomRight.y; j++){
                for(int i=0; i<=bottomRight.x; i++){
                    if(((i==topLeft.x||i==bottomRight.x)&&j>=topLeft.y)||((j==topLeft.y||j==bottomRight.y)&&i>=topLeft.x))
                        cout << "# ";
                    else 
                        cout << "  ";
                }
                cout << "\n";
            }
        }
};

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    Rectangle r(A,B,C,D);
    r.area(); r.perimeter(); r.centerPoint(); r.square(); r.display();
}