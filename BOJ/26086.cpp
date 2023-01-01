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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();
    int n,q,k;
    cin>>n>>q>>k;
    vector<pii> op(q);
    int si=-1;
    for (int i=0; i<q; i++) {
        cin>>op[i].F;
        if (op[i].F==0) cin>>op[i].S;
        else {
            if (op[i].F==1) si=i;
            op[i].S=op[i].F;
        }
    }

    vector<int> srt;
    for (int i=0; i<si; i++) {
        if (op[i].F==0) srt.pb(op[i].S);
    }
    sort(all(srt));

    bool frt=1, lst=0;

    deque<int> dq;
    for (int x:srt) dq.push_back(x);
    
    for (int i=si+1; i<q; i++) {
        if (op[i].F==0) {
            if (frt) dq.push_front(op[i].S);
            else dq.push_back(op[i].S);
        }
        else frt^=1, lst^=1;
    }
    int ans=0;
    if (frt) {
        while (k--) ans=dq.front(), dq.pop_front();
    }
    else {
        while (k--) ans=dq.back(), dq.pop_back();
    }

    cout<<ans;
    return 0;
}