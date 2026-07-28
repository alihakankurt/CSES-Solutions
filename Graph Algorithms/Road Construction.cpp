#include <bits/stdc++.h>
using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using uptr = uintptr_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = make_signed_t<size_t>;
using iptr = intptr_t;

using f32 = float_t;
using f64 = double_t;

constexpr i32 Modulus = 1e9 + 7;

template <typename T>
class DisjointSet
{
    vector<T> _sizes;
    vector<T> _parents;

  public:
    explicit DisjointSet(usize n)
    {
        _sizes.resize(n, 1);
        _parents.resize(n);
        iota(_parents.begin(), _parents.end(), T{});
    }

    T Find(T node)
    {
        while (node != _parents[node])
        {
            _parents[node] = _parents[_parents[node]];
            node = _parents[node];
        }

        return node;
    }

    bool Unite(T node1, T node2)
    {
        node1 = Find(node1);
        node2 = Find(node2);

        if (node1 == node2)
        {
            return false;
        }

        if (_sizes[node1] < _sizes[node2])
        {
            swap(node1, node2);
        }

        _sizes[node1] += _sizes[node2];
        _parents[node2] = node1;
        return true;
    }

    T GetSize(T node)
    {
        return _sizes[Find(node)];
    }

    bool IsConnected(T node1, T node2)
    {
        return Find(node1) == Find(node2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 n, m;
    cin >> n >> m;

    DisjointSet<u32> dsu(n + 1);

    u32 size = 1;
    while (m--)
    {
        u32 a, b;
        cin >> a >> b;

        if (dsu.Unite(a, b))
        {
            --n;
        }

        size = max(size, dsu.GetSize(a));
        cout << n << ' ' << size << '\n';
    }

    return 0;
}
