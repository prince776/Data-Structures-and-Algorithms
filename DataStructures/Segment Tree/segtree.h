#pragma once

#include <bits/stdc++.h>
using namespace std;

/**
 * Segment Tree, currently recursive
 * 
 * @Data Data type of actual values
 * @Node Data type of what to store in segment tree nodes
 * 
 * identity is Node indentity element on mergeFn i.e mergeFn(x, identity) = x
 * Node(const Data& data) should be possible
 */
template<typename Data, typename Node, typename MergeFnType>
class SegTree
{
    int n;
    vector<Node> st;
    MergeFnType mergeFn;
	Node identity;
public:
    SegTree() = default;
    SegTree(const vector<Data> &data, const Node& identity, MergeFnType &&fn)
		: mergeFn(forward<MergeFnType>(fn)), identity(identity), n(data.size())
    {
        st = vector<Node>(2 * n - 1);
        build(data, 0, 0, n - 1);
    }

    Node query(int l, int r) { return queryImpl(l, r, 0, 0, n - 1); };
    void pointUpdate(int pos, const Data &val) { return pointUpdateImpl(pos, val, 0, 0, n - 1); }

private:
    void build(const vector<Data> &data, int v, int l, int r)
    {
        if (l == r)
            st[v] = data[l];
        else
        {
			auto [lv, rv, mid] = getChildren(v, l, r);
            build(data, lv, l, mid);
            build(data, rv, mid + 1, r);
            st[v] = mergeFn(st[lv], st[rv]);
        }
    }

    Node queryImpl(int l, int r, int v, int nL, int nR)
    {
        if (l > r) return identity;
        if (nL == l && nR == r)
            return st[v];
		auto [lv, rv, mid] = getChildren(v, nL, nR);
        return mergeFn(
            queryImpl(l, min(r, mid), lv, nL, mid),
            queryImpl(max(l, mid + 1), r, rv, mid + 1, nR)
        );
    }

    void pointUpdateImpl(int pos, const Data &val, int v, int nL, int nR)
    {
        if (nL == nR)
        {
            st[v] = val;
            return;
        }
		auto [lv, rv, mid] = getChildren(v, nL, nR);
        if (pos <= mid)
            pointUpdateImpl(pos, val, lv, nL, mid);
        else
            pointUpdateImpl(pos, val, rv, mid + 1, nR);
        st[v] = mergeFn(st[lv], st[rv]);
    }

	tuple<int, int, int> getChildren(int v, int nL, int nR) const
	{
		int mid = (nL + nR) / 2;
		return make_tuple(v + 1, v + 2 * (mid - nL + 1), mid);
	}
};
