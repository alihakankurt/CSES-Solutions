#include <bits/stdc++.h>
using namespace std;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ptrdiff_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f32 = float_t;
using f64 = double_t;

inline constexpr i32 Modulus = 1e9 + 7;

struct Mountain
{
    u32 Position;
    u32 Height;

    bool operator<(const Mountain& other) const
    {
        return Height > other.Height;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 n;
    cin >> n;

    vector<Mountain> mountains(n);
    for (u32 position = 1; position <= n; position += 1)
    {
        u32 height;
        cin >> height;
        mountains[position - 1] = {position, height};
    }

    sort(mountains.begin(), mountains.end());
    vector<u32> dp(n + 1);

    u32 lastHeight = 0;
    set<u32> lastPositions, lookupPositions;
    for (auto [position, height] : mountains)
    {
        if (height != lastHeight)
        {
            lookupPositions.merge(lastPositions);
            lastPositions.clear();
        }

        auto iter = lookupPositions.lower_bound(position);

        u32 right = (iter == lookupPositions.end()) ? 0 : dp[*iter];
        u32 left = (iter == lookupPositions.begin()) ? 0 : dp[*--iter];

        dp[position] = max(left, right) + 1;
        lastPositions.insert(position);
        lastHeight = height;
    }

    u32 answer = *max_element(dp.begin(), dp.end());
    cout << answer;

    return 0;
}
