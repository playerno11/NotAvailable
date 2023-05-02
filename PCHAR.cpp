#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,x[5][N],o=0;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("Pchar.inp","r",stdin);
    freopen ("Pchar.out","w",stdout);
    cin>>n>>s;
    x[1][0]=0,x[2][0]=0;
    for (ll i=0;i<n;i++)
        if (s[i]=='.'){
            x[1][i+1]=o;
            x[2][i+1]=min(x[1][i],x[2][i])+1;
        }
        else if (s[i]=='#'){
            x[1][i+1]=o+1;
            x[2][i+1]=min(x[1][i],x[2][i]);
            o++;
        }
    cout<<min(x[1][n],x[2][n]);
}
