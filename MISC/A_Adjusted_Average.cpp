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
const int MAX = 1515; // PLZ CHK!

ll N,K,X,A[MAX],S;

ll sol0() {
    return abs(S-N*X);
}

ll sol1() {
    ll ret=1e18;
    for (int i=1; i<=N; i++) {
        ret=min(ret, abs(S-A[i]-X*(N-1)));
    }
    return ret;
}

ll sol2() {
    ll ret=1e18;
    for (int i=2; i<=N; i++) {
        for (int j=1; j<i; j++) {
            ret=min(ret, abs(S-A[i]-A[j]-X*(N-2)));
        }
    }
    return ret;
}

ll sol3() {
    multiset<ll> st;
    for (int i=1; i<=N; i++) st.insert(A[i]);

    ll ret=1e18;
    for (int i=1; i<=N; i++) {
        st.erase(st.find(A[i]));

        for (int j=1; j<i; j++) {
            ll t=S-X*(N-3ll)-A[i]-A[j];
            auto it1=st.ub(t); 
            if (it1!=st.begin()) {
                it1--;
                ret=min(ret, abs(S-A[i]-A[j]-*it1-X*(N-3)));
            }

            auto it2=st.lb(t);
            if (it2!=st.end()) {
                ret=min(ret, abs(S-A[i]-A[j]-*it2-X*(N-3)));
            }
        }
    }

    return ret;
}

ll sol4() {
    multiset<ll> st;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<i; j++) st.insert(A[i]+A[j]);
    }

    ll ret=1e18;
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            st.erase(st.find(A[i]+A[j]));
        }

        for (int j=1; j<i; j++) {
            ll t=S-X*(N-4ll)-A[i]-A[j];
            auto it1=st.ub(t); 
            if (it1!=st.begin()) {
                it1--;
                ret=min(ret, abs(S-A[i]-A[j]-*it1-X*(N-4)));
            }

            auto it2=st.lb(t);
            if (it2!=st.end()) {
                ret=min(ret, abs(S-A[i]-A[j]-*it2-X*(N-4)));
            }
        }
    }

    return ret;
}

int main() {
    fio();

    cin>>N>>K>>X;
    for (int i=1; i<=N; i++) cin>>A[i], S+=A[i];

    long double ans=(long double)sol0()/(1.0*N);

    if (K>=1) {
        ans=min(ans, (long double)sol1()/(1.0*N-1.0));
        if (K>=2) {
            ans=min(ans, (long double)sol2()/(1.0*N-2.0));
            if (K>=3) {
                ans=min(ans, (long double)sol3()/(1.0*N-3.0));
                if (K>=4) {
                    ans=min(ans, (long double)sol4()/(1.0*N-4.0));
                }
            }
        }
    }

    cout<<fixed; cout.precision(10);
    cout<<ans;
    return 0;
}