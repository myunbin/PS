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

int H,W,N;
ll X[MAX], Y[MAX];
pll P[MAX];

int main() {
    fio();
    cin>>W>>H>>N;
    for (int i=0; i<N; i++) {
        cin>>P[i].F>>P[i].S;
        X[i]=P[i].F, Y[i]=P[i].S;
    }    

    sort(X,X+N), sort(Y,Y+N);
    ll xm[]={X[(N-1)/2], X[N/2]}, ym[]={Y[(N-1)/2], Y[N/2]};
    ll sum=0;
    for (int i=0; i<N; i++) {
        sum+=2ll*abs(X[i]-xm[0]);
        sum+=2ll*abs(Y[i]-ym[0]);
    }

    if (N&1) {
        ll mx=0;
        for (int i=0; i<N; i++) {
            mx=max(mx, abs(P[i].F-xm[0])+abs(P[i].S-ym[0]));
        }
        cout<<sum-mx<<endl<<xm[0]<<sp<<ym[0];
    }
    else {
        ll mx=0; pll st;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<N; k++) {
                    if (mx<abs(P[k].F-xm[i])+abs(P[k].S-ym[j])) {
                        mx=abs(P[k].F-xm[i])+abs(P[k].S-ym[j]);
                        st={xm[i], ym[j]};
                    }
                    else if (mx==abs(P[k].F-xm[i])+abs(P[k].S-ym[j])) {
                        st=min(st, {xm[i], ym[j]});
                    }
                }
            }
        }
        cout<<sum-mx<<endl<<st.F<<sp<<st.S;
    }

    return 0;
}