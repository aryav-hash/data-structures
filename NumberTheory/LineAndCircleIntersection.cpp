#include<bits/stdc++.h>
using namespace std;
class intersectionOfCircleAndLine{
    public:
    bool check(int radius, int x, int y, int a, int b, int c){
        int dis = (abs(a*x + b*y + c))/sqrt(a*a + b*b);
        
        if (dis <= radius){
            return true;
        }
        return false;
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int radius;
        cin >> radius; // Radius of the circle.
        int x, y;
        cin >> x >> y; // Center of the circle.
        int a, b, c;
        cin >> a >> b >> c;
        intersectionOfCircleAndLine obj;
        if (obj.check(radius, x, y, a, b, c)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
