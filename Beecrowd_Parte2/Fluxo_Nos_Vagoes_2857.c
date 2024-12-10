#include <stdio.h>

#define MAXN 100005
#define MAXM 100005

int tree[4*MAXN], arr[MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] += val;
        tree[node] += val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2*node, start, mid, idx, val);
        } else {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return p1 + p2;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
    }
    build(1, 0, N-1);
    while (M--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            update(1, 0, N-1, x-1, y);
        } else {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            int total = query(1, 0, N-1, a-1, b-1) + query(1, 0, N-1, c-1, d-1);
            printf("%d\n", total);
        }
    }
    return 0;
}