#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 55; // PLZ CHK!

int n,sum,a[MAX],sz;
int v[MAX];

int go(int len, int idx, int curl, vector<int> &ans) {
    if (sz(ans)==n) {
        cout<<len<<endl;
        // int sl=0;
        // for (int i=0; i<n; i++) {
        //     cout<<ans[i]<<sp;
        //     sl+=ans[i];
        //     if (sl%len==0) cout<<endl;
        // }
        exit(0);
    }

    if (curl==len) return go(len, 0, 0, ans);
    for (int i=idx; i<n; i++) {
        if (!v[i] && curl+a[i]<=len) {
            v[i]=1;
            ans.pb(a[i]);
            if (go(len, i+1, curl+a[i], ans)) return 1;
            v[i]=0;
            ans.pop_back();
            if (curl==0) return 0;
        }
    }
    return 0;
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i], sum+=a[i];
    sort(a,a+n,greater<int>());

    vector<int> div;
    
    for (int i=1; i*i<=sum; i++) {
        if (sum%i==0) {
            div.pb(i);
            if (i*i!=sum) div.pb(sum/i);
        }
    }

    sort(all(div));
    for (int len:div) {
        sz=sum/len;
        if (len<a[0]) continue;
        vector<int> ans;
        go(len, 0, 0, ans);
    }
    
    return 0;
}