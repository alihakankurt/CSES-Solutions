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

struct Edge
{
    u16 Source;
    u16 Target;
    i32 Weight;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    auto edges = vector<Edge>(edgeCount + 1);
    for (Edge& edge : edges)
    {
        cin >> edge.Source >> edge.Target >> edge.Weight;
    }

    auto distance = vector<i64>(nodeCount + 1, numeric_limits<i64>::max());
    auto parent = vector<u16>(nodeCount + 1, 0);

    for (u16 node = 1; node <= nodeCount; ++node)
    {
        distance[node] = 0;

        u16 relaxations = nodeCount;
        u16 lastUpdate = 1;
        while (relaxations-- && lastUpdate != 0)
        {
            lastUpdate = 0;
            for (const Edge& edge : edges)
            {
                if (distance[edge.Source] < numeric_limits<i64>::max())
                {
                    if (distance[edge.Target] > distance[edge.Source] + edge.Weight)
                    {
                        distance[edge.Target] = distance[edge.Source] + edge.Weight;
                        parent[edge.Target] = edge.Source;
                        lastUpdate = edge.Target;
                    }
                }
            }
        }

        if (lastUpdate > 0)
        {
            u16 cycleNode = lastUpdate;
            for (u16 turn = 0; turn < nodeCount; ++turn)
            {
                cycleNode = parent[cycleNode];
            }

            vector<u16> path;
            u16 currentNode = cycleNode;

            do
            {
                path.push_back(currentNode);
                currentNode = parent[currentNode];
            }
            while (currentNode != cycleNode);

            cout << "YES" << '\n';
            for (auto it = path.rbegin(); it != path.rend(); ++it)
            {
                cout << *it << ' ';
            }
            cout << path.back();

            return 0;
        }
    }

    cout << "NO";
    return 0;
}
