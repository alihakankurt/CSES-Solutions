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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr usize ROOT_NODE = 1u;

    usize hotelsLength, groupsLength;
    cin >> hotelsLength >> groupsLength;

    usize treeSize = 1u;
    while (treeSize < hotelsLength) treeSize <<= 1u;

    auto segmentTree = vector<u32>(treeSize << 1u);
    for (usize index = 0u; index < hotelsLength; index += 1u)
    {
        cin >> segmentTree[index + treeSize];
    }

    for (usize node = treeSize - 1u; node >= ROOT_NODE; node -= 1u)
    {
        segmentTree[node] = max(segmentTree[node << 1u], segmentTree[node << 1u | 1u]);
    }

    for (usize group = 0u; group < groupsLength; group += 1u)
    {
        u32 groupSize;
        cin >> groupSize;

        if (segmentTree[ROOT_NODE] < groupSize)
        {
            cout << 0u << ' ';
            continue;
        }

        usize node = ROOT_NODE;
        while (node < treeSize)
        {
            node <<= 1u;
            if (segmentTree[node] < groupSize)
            {
                node |= 1u;
            }
        }

        usize hotel = node - treeSize + 1u;
        cout << hotel << ' ';

        segmentTree[node] -= groupSize;
        for (node >>= 1u; node >= ROOT_NODE; node >>= 1u)
        {
            segmentTree[node] = max(segmentTree[node << 1u], segmentTree[node << 1u | 1u]);
        }
    }

    return 0;
}
