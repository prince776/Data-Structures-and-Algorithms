#pragma once

#include <bits/stdc++.h>
using namespace std;

/**
 * Segment Tree, currently recursive
 * 
 * @Data Data type of actual values
 * @Node Data type of what to store in segment tree nodes
 * 
 * Node must have constructor Node(const Data &d)
 */
template<typename Data, typename Node>
class SegTree
{
    int n;
    vector<Node> st;
    function<Node(const Node&, const Node&)> mergeFn;
public:
    SegTree() = default;
    SegTree(const vector<Data> &data, const function<Node(const Node&, const Node&)> &fn)
    {
        n = data.size();
        st = vector<Node>(4 * n);
        mergeFn = fn;
        build(data, 1, 0, n - 1);
    }

    Node query(int l, int r) { return queryImpl(l, r, 1, 0, n - 1); };
    void pointUpdate(int pos, const Data &val) { return pointUpdateImpl(pos, val, 1, 0, n - 1); }

private:
    void build(const vector<Data> &data, int v, int l, int r)
    {
        if (l == r)
            st[v] = data[l];
        else
        {
            int mid = (l + r) / 2;
            build(data, 2 * v, l, mid);
            build(data, 2 * v + 1, mid + 1, r);
            st[v] = mergeFn(st[v * 2], st[v * 2 + 1]);
        }
    }

    Node queryImpl(int l, int r, int v, int nL, int nR)
    {
        if (l > r) return Node{};
        if (nL == l && nR == r)
            return st[v];
	    int mid = (nL + nR) / 2;
        return mergeFn(
            queryImpl(l, min(r, mid), 2 * v, nL, mid),
            queryImpl(max(l, mid + 1), r, 2 * v + 1, mid + 1, nR)
        );
    }

    void pointUpdateImpl(int pos, const Data &val, int v, int nL, int nR)
    {
        if (nL == nR)
        {
            st[v] = val;
            return;
        }
        int mid = (nL + nR) / 2;
        if (pos <= mid)
            pointUpdateImpl(pos, val, 2 * v, nL, mid);
        else
            pointUpdateImpl(pos, val, 2 * v + 1, mid + 1, nR);
        st[v] = mergeFn(st[2 * v], st[2 * v + 1]);
    }
};
