#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m,a,b,c;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(b*b-4*a*c>=0 && int(sqrt(d))*int(sqrt(d))==d){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}