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

    vector<u32> towers;
    for (usize index = 0; index < n; index += 1)
    {
        u32 cube;
        cin >> cube;

        usize left = 0, right = towers.size();
        while (left < right)
        {
            usize middle = left + (right - left) / 2;
            if (cube < towers[middle])
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }

        if (left == towers.size())
        {
            towers.push_back(cube);
        }
        else
        {
            towers[left] = cube;
        }
    }

    cout << towers.size();

    return 0;
}
