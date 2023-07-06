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

map<pii,int> v;
set<pii> e;

int main() {
    fio();
    int n; string s; 
    cin>>n>>s;

    int cnt=1;
    pii cur={0,0};

    v[cur]=cnt++;

    const int dx[]={0,1,1,1,0,-1,-1,-1};
    const int dy[]={1,1,0,-1,-1,-1,0,1};

    for (int i=0; i<n; i++) {
        int d=s[i]-'0';
        for (int j=0; j<2; j++) {
            cur.F+=dx[d], cur.S+=dy[d];
            v[cur]=cnt++;    
        }
    }

    cur={0,0};
    for (int i=0; i<n; i++) {
        pii nxt=cur;
        int d=s[i]-'0';

        for (int j=0; j<2; j++) {
            nxt.F+=dx[d], nxt.S+=dy[d];

            int x=v[cur], y=v[nxt];
            e.insert({min(x,y), max(x,y)});

            cur=nxt;
        }
    }   

    cout<<2+sz(e)-sz(v)-1;

    return 0;
}