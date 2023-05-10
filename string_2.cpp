#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define endl '\n'
#define debug(a) cerr<<#a<<'='<<(a)<<endl
const ll N=2e5+5;
void solve()
{
    ll n,a[5]={0},ans[N];
    cin>>n;
    string s;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='A') a[1]++;
        else if(s[i]=='C') a[2]++;
        else if(s[i]=='G') a[3]++;
        else if(s[i]=='T') a[4]++;
    }
    ll mx=0,idx=0;
    for(ll i=1;i<=4;i++)
    {
        if(a[i]>mx)
        {
            mx=a[i];
            idx=i;
        }
    }
    if(n%4!=0 || (mx>n/2))
    {
        cout<<"==="<<endl;
        return;
    }
    ll each=n/4;
    for(ll i=0;i<n;i++)
    {
        if(s[i]!='?')
            ans[i]=s[i];
        else
        {
            if(a[1]<each) ans[i]='A',a[1]++;
            else if(a[2]<each) ans[i]='C',a[2]++;
            else if(a[3]<each) ans[i]='G',a[3]++;
            else ans[i]='T',a[4]++;
        }
    }
    for(ll i=1;i<=4;i++)
    {
        if(a[i]!=each)
        {
            cout<<"==="<<endl;
            return;
        }
    }
    for(ll i=0;i<n;i++)
        cout<<(char)ans[i];
    cout<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}