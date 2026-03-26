#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        vector<long long> prefix = b;

        for(int i=1;i<prefix.size();i++){
            prefix[i]+=prefix[i-1];
        }

        vector<long long> cnt(n+1,0);
        vector<long long> ans(n,0);

        for(int i=0;i<n;i++){
            long long t = a[i];
            if(i-1>=0){
                t+=prefix[i-1];
            }
            int index = upper_bound(prefix.begin(),prefix.end(),t)-prefix.begin();
            cnt[i]++;
            cnt[index]--;
            if(index<n){
                ans[index]+=t;
                if(i-1>=0){
                    ans[index]-=prefix[i-1];
                }
                if(index-1>=0){
                    ans[index]-=prefix[index-1];
                    if(i-1>=0){
                        ans[index]+=prefix[i-1];
                    }
                }
            }
        }
    

        for(int i=1;i<cnt.size();i++){
            cnt[i]+=cnt[i-1];
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]+cnt[i]*b[i]<<" ";
        }
        cout<<endl;

    }
}