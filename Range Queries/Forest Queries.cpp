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

    usize forestSize, queriesLength;
    cin >> forestSize >> queriesLength;

    auto forest = vector<vector<u32>>(forestSize + 1u, vector<u32>(forestSize + 1u));

    for (usize y = 1u; y <= forestSize; y += 1u)
    {
        for (usize x = 1u; x <= forestSize; x += 1u)
        {
            char ch;
            cin >> ch;

            forest[y][x] = (ch == '*') ? 1u : 0u;
            forest[y][x] += forest[y][x - 1u] + forest[y - 1u][x];
            forest[y][x] -= forest[y - 1u][x - 1u];
        }
    }

    for (usize _ = 0u; _ < queriesLength; _ += 1u)
    {
        usize y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        u32 answer = forest[y2][x2] - forest[y2][x1 - 1u] - forest[y1 - 1u][x2] + forest[y1 - 1u][x1 - 1u];
        cout << answer << '\n';
    }

    return 0;
}
