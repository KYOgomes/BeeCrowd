#include <stdio.h>
#define MAXN 100010
#define MAXQ 100010

int tree[4*MAXN], lazy[4*MAXN], arr[MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = (tree[2*node] > tree[2*node+1]) ? tree[2*node] : tree[2*node+1];
    }
}

void update(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        tree[node] = (tree[node] + lazy[node]) % 9;
        if (start != end) {
            lazy[node*2] = (lazy[node*2] + lazy[node]) % 9;
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node]) % 9;
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (start >= l && end <= r) {
        tree[node] = (tree[node] + val) % 9;
        if (start != end) {
            lazy[node*2] = (lazy[node*2] + val) % 9;
            lazy[node*2+1] = (lazy[node*2+1] + val) % 9;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, l, r, val);
    update(node*2+1, mid+1, end, l, r, val);
    tree[node] = (tree[node*2] > tree[node*2+1]) ? tree[node*2] : tree[node*2+1];
}

int query(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) return -1;
    if (lazy[node] != 0) {
        tree[node] = (tree[node] + lazy[node]) % 9;
        if (start != end) {
            lazy[node*2] = (lazy[node*2] + lazy[node]) % 9;
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node]) % 9;
        }
        lazy[node] = 0;
    }
    if (start >= l && end <= r) return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(node*2, start, mid, l, r);
    int p2 = query(node*2+1, mid+1, end, l, r);
    return (p1 > p2) ? p1 : p2;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) arr[i] = 1;
    build(1, 0, n-1);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int val = query(1, 0, n-1, a, b);
        update(1, 0, n-1, a, b, val);
    }
    for (int i = 0; i < n; i++) {
        if(query(1, 0, n-1, i, i) == 3)
        {
            printf("%d\n", query(1, 0, n-1, i, i)-1);
        }
        else{printf("%d\n", query(1, 0, n-1, i, i)-2);}
        
    }
    return 0;
}