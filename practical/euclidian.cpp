// euclidian algorithm

#include<iostream>
using namespace std;

long long int gcd(long long int a,long long int b,long long int t1,long long int t2){

    if(!b)
     return a;
    cout<<"\n"<<a/b<<"    "<<a<<"    "<<b<<"    "<<a%b<<"    "<<t1<<"   "<<t2<<"    "<<(t1-(a/b)*t2)<<"\n";
    return gcd(b,a%b,t2,(t1-(a/b)*t2));
}

int main(){

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   // enter  two numbers
   long long int a,b;
   cin>>a>>b;
   
   cout<<"\n\n-----------------\n";
   cout<<"Eculidian Algorithm";
   cout<<"\n-----------------\n";
   cout<<"q    "<<"r1    "<<"r2    "<<"r    "<<"t1    "<<"t2    "<<"t\n";
   long long int ans=gcd(a,b,0,1);
   cout<<"\nGCD of "<<a<<" and "<<b<<" is: "<<ans;
   return 0;
}
