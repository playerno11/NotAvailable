#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll n,a[N][N];
string x[N][N],m="0";
string cong(string a, string b){
    while (a.size()>b.size()) b='0'+b;
    while (a.size()<b.size()) a='0'+a;
    string c=a;
    ll nho=0;
    for (ll i=a.size()-1;i>=0;i--){
        ll kq=int(a[i])+int(b[i])+nho-96;
        c[i]=char(kq%10+48);
        nho=kq/10;
    }
    c=char(nho+48)+c;
    while (c[0]=='0' && c.size()>1) c.erase(0,1);
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("CNTPATH.INP","r",stdin);
    freopen ("CNTPATH.OUT","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            cin>>a[i][j];
            x[i][j]="0";
        }
    x[1][1]="1";
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
            if (a[i][j]!=0){
                if (i+a[i][j]<=n) x[i+a[i][j]][j]=cong(x[i+a[i][j]][j],x[i][j]);
                if (j+a[i][j]<=n) x[i][j+a[i][j]]=cong(x[i][j+a[i][j]],x[i][j]);
            }
    cout<<x[n][n];
}
