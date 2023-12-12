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
const int MAX = 20; // PLZ CHK!

int N;
ll A1[MAX],B1[MAX],A2[MAX],B2[MAX];
map<ll,string> H1[MAX],H2[MAX];

int main() {
    fio();
    cin>>N;
    int H=N/2;
    for (int i=0; i<H; i++) cin>>A1[i];
    for (int i=0; i<H; i++) cin>>A2[i];
    for (int i=0; i<H; i++) cin>>B1[i];
    for (int i=0; i<H; i++) cin>>B2[i];

    for (int i=0; i<(1<<H); i++) {
        int ii=__builtin_popcount(i);
        string t;
        ll sum=0;
        for (int j=0; j<H; j++) {
            if (i&(1<<j)) sum-=B1[j], t+='2';
            else sum+=A1[j], t+='1';
        }
        
        if (H1[ii].find(sum)!=H1[ii].end()) H1[ii][sum]=min(H1[ii][sum],t);
        else H1[ii][sum]=t;
    }

    for (int i=0; i<(1<<H); i++) {
        int ii=__builtin_popcount(i);
        string t;
        ll sum=0;
        for (int j=0; j<H; j++) {
            if (i&(1<<j)) sum-=B2[j], t+='2';
            else sum+=A2[j], t+='1';
        }

        if (H2[ii].find(sum)!=H2[ii].end()) H2[ii][sum]=min(H2[ii][sum],t);
        else H2[ii][sum]=t;
    }

    ll ans=LINF; string ret;
    for (int i=0; i<=H; i++) {
        for (auto [x,t1]:H1[i]) {
            auto j1=H2[H-i].lb(-x);
            
            if (j1!=H2[H-i].end()) {
                auto [y,t2]=*j1;
            
                if (ans>abs(x+y)) {
                    ans=abs(x+y);
                    ret=t1+t2;
                }
                else if (ans==abs(x+y)) {
                    ret=min(ret, t1+t2);
                }
            }

            if (j1!=H2[H-i].begin()) {
                j1--;
                auto [y,t2]=*j1;

                if (ans>abs(x+y)) {
                    ans=abs(x+y);
                    ret=t1+t2;
                }
                else if (ans==abs(x+y)) {
                    ret=min(ret, t1+t2);
                }
            }
        }
    }

    // cout<<ans<<endl;
    for (char c:ret) cout<<c<<' ';
    return 0;
}