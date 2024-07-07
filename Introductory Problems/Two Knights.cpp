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

    usize n;
    cin >> n;
    cout << 0 << '\n';
    for (usize size = 2; size <= n; size += 1)
    {
        u64 square = size * size;

        u64 allPositions = square * (square - 1) / 2;
        u64 attackPositions = 4 * (size - 1) * (size - 2);

        u64 safePositions = allPositions - attackPositions;
        cout << safePositions << '\n';
    }

    return 0;
}
