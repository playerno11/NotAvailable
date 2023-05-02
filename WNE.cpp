#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,ans=0;
unordered_map <ll,ll> cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("Wne.inp","r",stdin);
    freopen ("Wne.out","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        if (cnt[x]==0){
            ans++;
            cnt[x]=1;
        }
        else if (cnt[x]==1){
            ans--;
            cnt[x]=0;
        }
    }
    cout<<ans;
}
