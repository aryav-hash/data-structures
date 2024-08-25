#include<bits/stdc++.h>
using namespace std;

class orientationOf3Points{
    public:
    int collinear(int x1, int y1, int x2, int y2, int x3, int y3){
        // Calculation of sign of slope to determine the curve.
        // If the curve is positive then the curve is clockwise.
        // If the curve is negative then the curve is anticlockwise.
        int val = (x3 - x2)*(y2 - y1) - (y3 - y2)*(x2 - x1);
        
        if (val > 0){
            return 1;
        }
        else if (val < 0){
            return 2;
        }else{
            return 0;
            // If the val comes 0 then the curves are collinear for being equal and parallel.
        }
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        orientationOf3Points obj;
        if (obj.collinear(x1, y1, x2, y2, x3, y3) == 1){
            cout << "Clockwise" << endl;
        }else if (obj.collinear(x1, y1, x2, y2, x3, y3) == 2){
            cout << "Anticlockwise" << endl;
        }else{
            cout << "Collinear" << endl;
        }
    }
    return 0;
}
