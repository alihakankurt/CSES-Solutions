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

    constexpr auto INF = numeric_limits<u32>::max();

    usize valuesLength, queriesLength;
    cin >> valuesLength >> queriesLength;

    auto tree = vector<u32>(valuesLength << 1u, INF);

    for (usize index = 0u; index < valuesLength; index += 1u)
    {
        cin >> tree[valuesLength + index];
    }

    for (usize index = valuesLength - 1u; index > 0u; index -= 1u)
    {
        tree[index] = min(tree[index << 1u], tree[index << 1u | 1u]);
    }

    for (usize _ = 1u; _ <= queriesLength; _ += 1u)
    {
        usize type;
        cin >> type;

        if (type == 1u)
        {
            usize position;
            u32 value;
            cin >> position >> value;

            position += valuesLength - 1u;
            tree[position] = value;

            for (position >>= 1u; position > 0u; position >>= 1u)
            {
                tree[position] = min(tree[position << 1u], tree[position << 1u | 1u]);
            }
        }
        else if (type == 2u)
        {
            usize left, right;
            cin >> left >> right;

            left += valuesLength - 1u;
            right += valuesLength - 1u;

            u32 answer = INF;
            while (left <= right)
            {
                if ((left & 0b1u) == 0b1u)
                {
                    answer = min(answer, tree[left]);
                    left += 1u;
                }

                if ((right & 0b1u) == 0b0u)
                {
                    answer = min(answer, tree[right]);
                    right -= 1u;
                }

                left >>= 1u;
                right >>= 1u;
            }

            cout << answer << '\n';
        }
    }

    return 0;
}
