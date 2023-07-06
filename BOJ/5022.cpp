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
const int MAX = 111; // PLZ CHK!

int n,m;
pii as,ae,bs,be;
int v[MAX][MAX];
bool fst=1;

int b1() {
    queue<pii> q;
    q.push(as);
    v[as.F][as.S]=1;
    int d[MAX][MAX]={0};
    pii p[MAX][MAX];
    while (!q.empty()) {
        pii cur=q.front(); q.pop();
        if (cur==ae) {
            if (fst) {
                memset(v,0,sizeof v);
                pii x=cur;
                while (1) {
                    v[x.F][x.S]=1;
                    x=p[x.F][x.S];
                    if (x==as) {
                        v[x.F][x.S]=1;
                        break;
                    }
                }
                fst=0;
            }
            return d[cur.F][cur.S];
        }
        
        for (int i=0; i<4; i++) {
            pii nxt={cur.F+dx[i], cur.S+dy[i]};
            if (nxt.F<0||nxt.F>n||nxt.S<0||nxt.S>m||v[nxt.F][nxt.S]) continue;
            q.push(nxt);
            v[nxt.F][nxt.S]=1;
            d[nxt.F][nxt.S]=d[cur.F][cur.S]+1;
            p[nxt.F][nxt.S]=cur;
        }
    }
    return INF;
}

int b2() {
    queue<pii> q;
    q.push(bs);
    v[bs.F][bs.S]=1;
    int d[MAX][MAX]={0};
    pii p[MAX][MAX];
    while (!q.empty()) {
        pii cur=q.front(); q.pop();
        if (cur==be) {
            if (fst) {
                memset(v,0,sizeof v);
                pii x=cur;
                while (1) {
                    v[x.F][x.S]=1;
                    x=p[x.F][x.S];
                    if (x==bs) {
                        v[x.F][x.S]=1;
                        break;
                    }
                }
                fst=0;
            }
            return d[cur.F][cur.S];
        }
        
        for (int i=0; i<4; i++) {
            pii nxt={cur.F+dx[i], cur.S+dy[i]};
            if (nxt.F<0||nxt.F>n||nxt.S<0||nxt.S>m||v[nxt.F][nxt.S]) continue;
            q.push(nxt);
            v[nxt.F][nxt.S]=1;
            d[nxt.F][nxt.S]=d[cur.F][cur.S]+1;
        }
    }
    return INF;
}

int main() {
    fio();
    cin>>n>>m;
    cin>>as.F>>as.S>>ae.F>>ae.S;
    cin>>bs.F>>bs.S>>be.F>>be.S;
    
    int a1=b1()+b2();
    cout<<a1<<endl;
    memset(v,0,sizeof v); fst=1;
    int a2=b2()+b1();
    cout<<a2<<endl;
    // if (a1>=INF && a2>=INF) cout<<"IMPOSSIBLE";
    // else cout<<min(a1,a2);

    return 0;
}