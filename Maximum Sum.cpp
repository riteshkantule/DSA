
#include <bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define make make_pair
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define sortarr sort(arr, arr + n)
#define sortav sort(v.begin(), v.end())
#define rsortarr sort(arr, arr + n, greater<int>())
#define rsortv sort(v.begin(), v.end(), greater<>())
#define forl(i, j, k) for (int i = j; i < k; i += 1)
#define forlr(i, j, k) for (int i = j; i >= k; i -= 1)
#define vin(x, v)     \
    for (auto &x : v) \
        cin >> x;
#define vout(x, v)    \
    for (auto &x : v) \
        cout << x << " ";
#define endl "\n"
#define MOD 1000000007

using namespace std;

int power(long long x, unsigned int y, int p)
{
    int res = 1; 
    x = x % p;   
    if (x == 0)
        return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}

 
void solve()
{
 
    int n, k;
    cin >> n >> k;
    vi v(n);
    vin(x, v);
    vi pre(n);
    sort(all(v));
 
    pre[0] = v[0];
    forl(i, 1, n)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    int sum = 0, ans = 0;
    forl(i, 0, n) sum += v[i];
 
    for (int minElement = 0; minElement <= k; minElement++)
    {
        int maxElement = k - minElement;
 
        int avail = 0;
        if (minElement == 0)
        {
            avail = pre[n - 1 - maxElement];
        }
        else
            avail = pre[n - 1 - maxElement] - pre[2 * minElement - 1];
        // cout<<avail<<" ";
        ans = max(ans, avail);
    }
    cout << ans << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
