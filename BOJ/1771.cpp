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
const int MAX = 505050; // PLZ CHK!

int N,A[MAX];
vector<array<int,3>> S;

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];

    vector<int> ans;
    for (int i=1; i<=N; i++) {
        array<int,3> cur={A[i],A[i],i};
        while (!S.empty() && (S.back()[1]+1==cur[0]||S.back()[0]==cur[1]+1)) {
            auto [mn,mx,idx]=S.back(); S.pop_back();
            ans.pb(idx);
            cur={min(cur[0],mn), max(cur[1],mx), i};
        }
        S.pb(cur);
    }

    for (int x:ans) cout<<x<<endl;
    return 0;
}