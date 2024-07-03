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

    u16 n;
    cin >> n;

    vector<u16> codes = {0, 1};
    for (u16 bit = 1; bit < n; bit += 1)
    {
        for (isize index = codes.size() - 1; index >= 0; index -= 1)
        {
            codes.push_back((1 << bit) | codes[index]);
        }
    }

    for (u16 code : codes)
    {
        for (u16 mask = 1 << (n - 1); mask > 0; mask >>= 1)
        {
            cout << ((code & mask) == mask);
        }
        cout << '\n';
    }

    return 0;
}
