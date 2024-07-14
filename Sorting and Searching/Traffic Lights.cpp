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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 x;
    cin >> x;

    usize n;
    cin >> n;

    set<u32> breakpoints = {0, x};
    map<u32, u32> distances = {{x, 1}};
    for (usize index = 0; index < n; index += 1)
    {
        u32 light;
        cin >> light;

        auto it = breakpoints.upper_bound(light);
        u32 right = *it;
        u32 left = *--it;

        breakpoints.insert(light);

        distances[right - left] -= 1;
        if (distances[right - left] == 0)
            distances.erase(right - left);

        distances[right - light] += 1;
        distances[light - left] += 1;

        cout << distances.rbegin()->first << ' ';
    }

    return 0;
}
