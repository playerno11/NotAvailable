#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=1000005,inf=1e+18;
ll n,x,a[A]={},b[A]={},ans=inf;
void SangNt(){
    ll i=1;
    b[1]=1;
    while (i<=sqrt(A)){
        while (b[i]==1) i++;
        for (ll j=2;j<=A/i;j++)
            b[i*j]=1;
        i++;
    }
}
void Check(ll i){
    ll s=1;
    for (ll j=1;j<=a[i]+1;j++)
        if (s<=inf/i) s*=i;
        else return;
    ans=min(ans,s);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("Findnum.inp","r",stdin);
    freopen ("Findnum.out","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        for (ll j=2;j<=sqrt(x);j++)
            if (x%j==0){
                while (x%j==0){
                    x/=j;
                    a[j]++;
                }
            }
        a[x]+=(x>1);
    }
    SangNt();
    for (ll i=1;i<=A;i++)
        if (b[i]==0) Check(i);
    cout<<ans;
}
