#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,a[N],b[N],f1[N],f2[N],f3[N],f4[N],m1=-inf,m2=-inf,m3=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("LSSLEN.INP","r",stdin);
    freopen ("LSSLEN.OUT","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        b[n-i+1]=a[i];
        f1[i]=inf;
        f2[i]=inf;
    }
    for (ll i=1;i<=n;i++){
        ll x=lower_bound(f1+1,f1+n+1,a[i])-f1;
        ll y=lower_bound(f2+1,f2+n+1,b[i])-f2;
        f1[x]=a[i];
        f2[y]=b[i];
        f3[i]=x;
        f4[i]=y;
        m1=max(m1,x);
        m2=max(m2,y);
    }
    for (ll i=1;i<=n;i++)
        m3=max(m3,f3[i]+f4[n-i+1]-1);
    cout<<max(m1,max(m2,m3));
}
