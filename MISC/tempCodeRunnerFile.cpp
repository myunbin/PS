
            int mn=D[i];
            for (int x=i; nv(x)!=i; x=nv(x)) mn=min(mn,D[x]), cout<<x<<sp;
            for (int x=i; nv(x)!=i; x=nv(x)) D[x]=mn,V[x]=1;
        }