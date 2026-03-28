#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<long long> arr(10,0);
    arr[0] = 1;
    for(long long i=1;i<=9;i++){
        for(long long j=0;j<=i;j++){
            for(long long k=0;k<=i-j;k++){
                arr[i]++;
            }
        }
    }
    
    long long t;

    cin>>t;
    
    while(t--){
        long long n;
        cin>>n;

        long long product = 1;

        while(n>0){
            long long x = n%10;
            n = n/10;
            product = product*arr[x];
        }

        cout<<product<<endl;
        
    }
}