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
const int MAX = 101010; // PLZ CHK!

pll a[30];
string S="BESIGOM";
ll ans=0;

void go(int idx, vector<int> &t) {
    if (idx==7) {
        int b=t[0], e=t[1], s=t[2], i=t[3], g=t[4], o=t[5], m=t[6];
        int res=(b+e+s+s+i+e)*(g+o+e+s)*(m+o+o);
        if (res%2==0) {
            ll sum=1;
            for (int x=0; x<7; x++) {
                int y=S[x]-'A';
                if (t[x]) sum*=a[y].S;
                else sum*=a[y].F;
            }
            ans+=sum;
        }
        return;
    }

    t.pb(0);
    go(idx+1, t);
    t.pop_back();

    t.pb(1);
    go(idx+1, t);
    t.pop_back();
}

int main() {
    fio();
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        char c; int x;
        cin>>c>>x;
        if (x%2) a[c-'A'].S++;
        else a[c-'A'].F++;
    }

    vector<int> t;
    go(0,t);

    cout<<ans;
    
    return 0;
}