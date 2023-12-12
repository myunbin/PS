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

ll R,L,B,A[MAX],P[MAX];

bool ok(int x) {
    for (int i=1; i+x-1<=R; i++) {
        int l=i, r=i+x-1, m=(l+r)>>1;
        ll t=(P[r]-P[m])-(P[m-1]-P[l-1])+A[m]*1ll*(2*m-l-r);
        if (t<=B) return 1;
    }
    return 0;
}

int main() {
    fio();
    cin>>R>>L>>B;
    for (int i=1; i<=R; i++) cin>>A[i], P[i]=P[i-1]+A[i];

    int le=1, ri=R, ans=1;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            le=md+1;
            ans=md;
        }
        else ri=md-1;
    }

    cout<<ans;
    return 0;
}