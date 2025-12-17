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
    vector<T> _ranks;
    vector<T> _roots;

  public:
    explicit DisjointSet(usize n)
    {
        _ranks = vector<T>(n, 1);
        _roots = vector<T>(n);
        iota(_roots.begin(), _roots.end(), 0);
    }

    T Find(T node)
    {
        T root = _roots[node];
        if (root != node)
        {
            root = Find(root);
            _roots[node] = root;
        }

        return root;
    }

    void Unite(T node1, T node2)
    {
        node1 = Find(node1);
        node2 = Find(node2);

        if (node1 == node2)
        {
            return;
        }

        if (_ranks[node1] < _ranks[node2])
        {
            swap(node1, node2);
        }

        _ranks[node1] += _ranks[node2];
        _roots[node2] = node1;
    }

    bool IsConnected(T node1, T node2) const
    {
        node1 = Find(node1);
        node2 = Find(node2);
        return node1 == node2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 cities, roads;
    cin >> cities >> roads;

    DisjointSet<u32> dsu(cities + 1);
    for (u32 index = 0; index < roads; index += 1)
    {
        u32 city1, city2;
        cin >> city1 >> city2;
        dsu.Unite(city1, city2);
    }

    unordered_set<u32> roots;
    for (u32 city = 1; city <= cities; city += 1)
    {
        roots.insert(dsu.Find(city));
    }

    u32 requiredRoads = roots.size() - 1;
    cout << requiredRoads << '\n';

    for (auto it1 = roots.begin(), it2 = next(roots.begin()); it2 != roots.end(); ++it2)
    {
        cout << *it1 << ' ' << *it2 << '\n';
        it1 = it2;
    }

    return 0;
}
