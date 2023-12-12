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

const int MAXN = 1010101; 
const int MAXM = 21;

struct Node {
    int dep; char c;
    int par[MAXM], chd[30];

    Node() {
        dep=0;
        for (int i=0; i<26; i++) chd[i]=-1;
        for (int i=0; i<MAXM; i++) par[i]=-1;
    }
    Node(int _dep, char _c, int _par) {
        dep=_dep, c=_c, par[0]=_par;
        for (int i=0; i<26; i++) chd[i]=-1;
        for (int i=1; i<MAXM; i++) par[i]=-1;
    }
};

Node ND[MAXN]; int ptr=0;
int A[MAXN], T=0;

int add(int dep, char c, int par) {
    ND[ptr]=Node(dep,c,par);
    for (int i=1; i<MAXM; i++) ND[ptr].par[i]=ND[ND[ptr].par[i-1]].par[i-1];
    return ptr++;
}

void init() {
    T=0;
    A[0]=add(0,'!',-1);
}

void t(char c) {
    T++;
    int cur=A[T-1];
    if (ND[cur].chd[c-'a']==-1) ND[cur].chd[c-'a']=add(ND[cur].dep+1,c,cur);
    A[T]=ND[cur].chd[c-'a'];
}

void u(int x) {
    T++;
    A[T]=A[T-1-x];
}

void p(int x) {
    int cur=A[T];
    x=ND[cur].dep-x-1;
    for (int i=MAXM-1; i>=0; i--) {
        if (x&(1<<i)) {
            cur=ND[cur].par[i];
            x^=(1<<i);
        }
    }

    cout<<ND[cur].c<<endl;
}

int L;

int main() {
    fio();
    init();
    
    cin>>L;
    for (int i=0; i<L; i++) {
        char op; cin>>op;
        if (op=='T') {
            char c; cin>>c;
            t(c);
        }
        if (op=='U') {
            int x; cin>>x;
            u(x);
        }
        if (op=='P') {
            int x; cin>>x;
            p(x);
        }
    }

    return 0;
}