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
const int MAX = 1010101; // PLZ CHK!

int N;
pii A[MAX], XP[MAX], YP[MAX];
vector<int> X[MAX],Y[MAX];
vector<int> ans(MAX,0);

void f(int i) {
    int y=A[i].S;
    ans[i]=1;

    if (YP[y].F==-1) {
        YP[y].F=i;
        return;
    }
    if (YP[y].S==-1) {
        YP[y].S=i;
        return;
    }
    
    vector<int> t={YP[y].F, YP[y].S, i};
    sort(all(t), [&](int a, int b){
        return A[a].F<A[b].F;
    });

    YP[y]={t[0],t[2]};

    i=t[1];
    auto [cx,cy]=A[i];
    ans[i]=0;

    if (XP[cx].F==XP[cx].S) XP[cx]={-1,-1};
    else {
        if (X[cx][XP[cx].F]==i) {
            if (++XP[cx].F!=XP[cx].S) f(X[cx][XP[cx].F]);
        }
        else {
            if (--XP[cx].S!=XP[cx].F) f(X[cx][XP[cx].S]);
        }
    }
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>A[i].F>>A[i].S;
        Y[A[i].S].pb(i);
    }

    for (int i=0; i<MAX; i++) {
        for (int j:Y[i]) X[A[j].F].pb(j);
    }

    fill(XP,XP+MAX,pii{-1,-1});
    fill(YP,YP+MAX,pii{-1,-1});

    for (int i=0; i<MAX; i++) {
        if (X[i].empty()) continue;

        if (sz(X[i])==1) {
            XP[i]={0,0};
            f(X[i][XP[i].F]);
        }
        else {
            XP[i].F=0;
            f(X[i][XP[i].F]);

            XP[i].S=sz(X[i])-1;
            f(X[i][XP[i].S]);
        }
    }

    for (int i=0; i<N; i++) cout<<ans[i];
    return 0;
}