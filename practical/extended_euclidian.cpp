// euclidian algorithm

#include<iostream>
using namespace std;

long long int gcd(long long int a,long long int b,long long int &t1,long long int &t2){

    if(!b)
     return a;
    cout<<"\n"<<a/b<<"    "<<a<<"    "<<b<<"    "<<a%b<<"    "<<t1<<"   "<<t2<<"    "<<(t1-(a/b)*t2)<<"\n";
    t1=(t1-(a/b)*t2);
    return gcd(b,a%b,t2,t1);
}

long long int inv(long long int a, long long int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
        return 0;
 
    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
 
    return x1;
}
 

int main(){

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   // enter  two numbers
   long long int a,b;
   cin>>a>>b;
   
   cout<<"\n\n-----------------\n";
   cout<<"Extended Eculidian Algorithm";
   cout<<"\n-----------------\n";

   cout<<"\nTo find Multiplicative inverse first we need to check no's are co-prime or not....\n\n";
   cout<<"q    "<<"r1    "<<"r2    "<<"r    "<<"t1    "<<"t2    "<<"t\n";
   long long int t1=0,t2=1;
   long long int ans=gcd(a,b,t1,t2);
   if(ans!=1){
      cout<<"No's are Not Co-prime...end...";
      return 0;
   }
   cout<<"No's are co-prime hence multiplicative inverse of "<<a<<" and "<<b<<" is: "<<inv(b,a);
   return 0;
}


//samples

// 20 7
//13 7