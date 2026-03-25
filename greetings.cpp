#include <bits/stdc++.h>
using namespace std;

long long cal(vector<long long> &seg,long long index,long long l,long long r,long long s,long long e){
    if(l>r){
        return 0;
    }

    if(e<l || s>r){
        return 0;
    }

    if(l<=s && e<=r){
        return seg[index];
    }

    int m = s+(e-s)/2;
    
    return cal(seg,2*index+1,l,r,s,m)+cal(seg,2*index+2,l,r,m+1,e);
}

long long insert(vector<long long> &seg,long long index,long long r,long long s,long long e){
    if(e<r || s>r){
        return seg[index];
    }
    if(s==r && e==r){
        seg[index]++;
        return seg[index];
    }

    long long m = s+(e-s)/2;

    seg[index] = insert(seg,2*index+1,r,s,m)+insert(seg,2*index+2,r,m+1,e);

    return seg[index];
}



int main() {
    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        vector<vector<long long>> arr;
        vector<long long> s;
        for(long long i=0;i<n;i++){
            long long u,v;
            cin>>u>>v;
            arr.push_back({u,v});
            s.push_back(v);
        }

        vector<long long> seg(4*n,0);


        sort(arr.begin(),arr.end());
        sort(s.begin(),s.end());

        long long total = 0;

        for(long long i=0;i<arr.size();i++){
            long long num = arr[i][1];
            long long index = lower_bound(s.begin(),s.end(),num)-s.begin();
            long long rem = cal(seg,0,0,index-1,0,n-1);
            
            total+=(index-rem);
            insert(seg,0,index,0,n-1);
        }

        cout<<total<<endl;

    }
}