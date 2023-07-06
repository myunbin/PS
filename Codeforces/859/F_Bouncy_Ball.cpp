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

map<string,int> dir;
int n,m;
pii st,ed;
string d;

bool in(pii a) {
    return (1<=a.F && a.F<=n && 1<=a.S && a.S<=m);
}

void solve() {
    cin>>n>>m>>st.F>>st.S>>ed.F>>ed.S>>d;
    pii cur=st, fd=ed;
    int di=dir[d];
    
    int x=2*(n+m)+1;
    int cnt=0;
    while (x--) {
        pii nxt;
        int nd;
        if (di==0) { //DR
            int d=cur.F-cur.S;
            pii c1={n,n-d}, c2={m+d,m};
            if (in(c1) && in(c2)) {
                nxt=c1;
                nd=3;
            }
            else if (in(c1)) {
                nxt=c1;
                nd=2;
            }
            else {
                nxt=c2;
                nd=1;
            }
        }
        else if (di==1) { //DL
            int d=cur.F+cur.S;
            pii c1={n,d-n}, c2={d-1,1};
            if (in(c1) && in(c2)) {
                nxt=c1;
                nd=2;
            }
            else if (in(c1)) {
                nxt=c1;
                nd=3;
            }
            else {
                nxt=c2;
                nd=0;
            }
        }
        else if (di==2) {
            int d=cur.F+cur.S;
            pii c1={1,d-1}, c2={d-m,m};
            if (in(c1) && in(c2)) {
                nxt=c1;
                nd=1;
            }
            else if (in(c1)) {
                nxt=c1;
                nd=0;
            }
            else {
                nxt=c2;
                nd=3;
            }
        }
        else {
            int d=cur.F-cur.S;
            pii c1={1,1-d}, c2={d+1,1};
            if (in(c1)&&in(c2)) {
                nxt=c1;
                nd=0;
            }
            else if (in(c1)) {
                nxt=c1;
                nd=1;
            }
            else {
                nxt=c2;
                nd=2;
            }
        }
        
        //ans?
        if (min(cur.F, nxt.F)<=fd.F && fd.F<=max(cur.F, nxt.F)) {
            if (min(cur.S, nxt.S)<=fd.S && fd.S<=max(cur.S, nxt.S)) {
                if (di==0) {
                    int d=cur.F-cur.S;
                    int dd=fd.F-fd.S;
                    if (d==dd) {
                        cout<<cnt<<endl;
                        return;
                    }
                }
                else if (di==1) {
                    int d=cur.F+cur.S;
                    int dd=fd.F+fd.S;
                    if (d==dd) {
                        cout<<cnt<<endl;
                        return;
                    }
                }
                else if (di==2) {
                    int d=cur.F+cur.S;
                    int dd=fd.F+fd.S;
                    if (d==dd) {
                        cout<<cnt<<endl;
                        return;
                    }
                }
                else {
                    int d=cur.F-cur.S;
                    int dd=fd.F-fd.S;
                    if (d==dd) {
                        cout<<cnt<<endl;
                        return;
                    }
                }
            }
        }
        //
        cnt++;
        cur=nxt;
        di=nd;
    }
    cout<<-1<<endl;
}
int main() {
    fio();
    dir["DR"]=0;
    dir["DL"]=1;
    dir["UR"]=2;
    dir["UL"]=3;

    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}