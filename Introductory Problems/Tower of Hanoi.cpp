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

    u16 allDisksMask = (1 << n) - 1;

    cout << allDisksMask << '\n';

    u16 move = 0;
    u16 state[3] = {allDisksMask, 0, 0};

    while (state[2] != allDisksMask)
    {
        u16 nextMove = move ^ (move + 1);
        move += 1;

        u16 disk = 0;
        for (u16 bit = 0; bit < n; bit += 1)
        {
            u16 mask = 1 << (n - bit - 1);
            if ((nextMove & mask) == mask)
            {
                disk = n - bit;
                break;
            }
        }

        u16 diskMask = 1 << (disk - 1);
        u16 lowerMask = diskMask - 1;

        usize from = 3;
        for (usize index = 0; index < 3; index += 1)
        {
            if ((state[index] & diskMask) == diskMask)
            {
                from = index;
            }
        }

        usize to = 3;
        for (usize offset = 1; offset < 3; offset += 1)
        {
            usize index = (from + offset) % 3;
            if ((state[index] & lowerMask) == 0)
            {
                to = index;
                if ((n & 1) == 0)
                    break;
            }
        }

        state[from] ^= diskMask;
        state[to] ^= diskMask;

        cout << (from + 1) << ' ' << (to + 1) << '\n';
    }

    return 0;
}
