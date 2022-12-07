// Chinese remainder

#include <bits/stdc++.h>
using namespace std;

// multiplicative-inverse-under-modulo-m/
int inv(int a, int m)
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

int gcd(int a,int b){

    if(!b)
     return a;
    return gcd(b,a%b);
}

// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
int findMinX(vector<int> &num,vector<int> &rem, int k)
{
	// Compute product of all numbers
	int prod = 1;
	for (int i = 0; i < k; i++)
		prod *= num[i];

    cout<<"\n\nvalue of M is : "<<prod<<endl;

	// Initialize result
	int result = 0;

	// Apply above formula
	for (int i = 0; i < k; i++) {
		int pp = prod / num[i];
		cout<<"value of Mi of "<<num[i]<<" is : "<<pp<<endl;
		int inverse=inv(pp, num[i]);
		cout<<"value of inverse of "<<pp<<" is : "<<inverse<<endl;
		result += rem[i] * inverse * pp;
	}
	return result % prod;
}

// Driver method
int main(void)
{
	int n,val;
    cin>>n;
    vector<int> num,rem;

    for(int i=0;i<n;i++){
      cin>>val;
      num.push_back(val);
    }


    for(int i=0;i<n;i++){
      cin>>val;
      rem.push_back(val);
    }

    // first we need to check pairwise whether the no's are co-prime or not;
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
           if(gcd(num[i],num[j])!=1){
             cout<<num[i]<<" "<<num[j]<<" are not co-prime hence can't proceed\n";
			 return 0;
           }
        }
    }
    cout<<"All pairs are co-prime can be move further...";
	int ans= findMinX(num, rem,n);;
	cout <<"\nx is " <<ans;
	return 0;
}

//sample

// 3   3 4 5 2 3 1
// 3   3 5 7 2 3 2