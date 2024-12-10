#include <stdio.h>

#define MAXN 100010

typedef long long ll;

ll seg[4*MAXN], lazy[4*MAXN], pot[MAXN], inv[MAXN], vet[MAXN], B, P;

ll fexp(ll base, ll exp) {
    ll ans = 1;
    while(exp) {
        if(exp & 1) ans = (ans*base)%P;
        base = (base*base)%P;
        exp >>= 1;
    }
    return ans;
}

void build(int node, int start, int end) {
    lazy[node] = -1;
    if(start == end) {
        seg[node] = vet[start];
    } else {
        int mid = (start+end)>>1;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        seg[node] = (seg[2*node]*pot[end-mid] + seg[2*node+1])%P;
    }
}

void update(int node, int start, int end, int l, int r, ll val) {
    if(lazy[node] != -1) {
        seg[node] = (lazy[node]*pot[end-start+1])%P;
        if(start != end) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(start > r || end < l) return;
    if(start >= l && end <= r) {
        seg[node] = (val*pot[end-start+1])%P;
        if(start != end) {
            lazy[2*node] = val;
            lazy[2*node+1] = val;
        }
        return;
    }
    int mid = (start+end)>>1;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    seg[node] = (seg[2*node]*pot[end-mid] + seg[2*node+1])%P;
}

ll query(int node, int start, int end, int l, int r) {
    if(start > r || end < l) return 0;
    if(lazy[node] != -1) {
        seg[node] = (lazy[node]*pot[end-start+1])%P;
        if(start != end) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(start >= l && end <= r) return seg[node];
    int mid = (start+end)>>1;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1*pot[end-mid] + p2)%P;
}

int main() {
    int L, N;
    while(scanf("%lld %lld %d %d", &B, &P, &L, &N), B || P || L || N) {
        for(int i = 0; i <= L; i++) vet[i] = 0;
        pot[0] = 1;
        for(int i = 1; i <= L; i++) pot[i] = (pot[i-1]*B)%P;
        build(1, 0, L-1);
        for(int i = 0; i < N; i++) {
            char op;
            int a, b;
            scanf(" %c %d %d", &op, &a, &b);
            if(op == 'E') {
                update(1, 0, L-1, a-1, a-1, b);
                vet[a-1] = b;
            } else {
                printf("%lld\n", query(1, 0, L-1, a-1, b-1));
            }
        }
        printf("-\n");
    }
    return 0;
}