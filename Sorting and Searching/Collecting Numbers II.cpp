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

    usize n, m;
    cin >> n >> m;

    vector<u32> nums(n + 2);
    vector<usize> positions(n + 2);
    for (usize position = 1; position <= n; position += 1)
    {
        usize num;
        cin >> num;
        nums[position] = num;
        positions[num] = position;
    }

    nums[0] = 0;
    nums[n + 1] = n + 1;

    positions[0] = 0;
    positions[n + 1] = n + 1;

    usize rounds = 1;
    for (usize num = 1; num < n; num += 1)
    {
        if (positions[num] > positions[num + 1])
        {
            rounds += 1;
        }
    }

    while (m > 0)
    {
        m -= 1;

        usize position1, position2;
        cin >> position1 >> position2;

        u32 num1 = nums[position1];
        u32 num2 = nums[position2];

        nums[position1] = num2;
        nums[position2] = num1;

        if (positions[num1] > positions[num1 - 1] && position2 <= positions[num1 - 1])
        {
            rounds += 1;
        }
        else if (positions[num1] < positions[num1 - 1] && position2 >= positions[num1 - 1])
        {
            rounds -= 1;
        }

        if (positions[num1] < positions[num1 + 1] && position2 >= positions[num1 + 1])
        {
            rounds += 1;
        }
        else if (positions[num1] > positions[num1 + 1] && position2 <= positions[num1 + 1])
        {
            rounds -= 1;
        }

        positions[num1] = position2;

        if (positions[num2] > positions[num2 - 1] && position1 <= positions[num2 - 1])
        {
            rounds += 1;
        }
        else if (positions[num2] < positions[num2 - 1] && position1 >= positions[num2 - 1])
        {
            rounds -= 1;
        }

        if (positions[num2] < positions[num2 + 1] && position1 >= positions[num2 + 1])
        {
            rounds += 1;
        }
        else if (positions[num2] > positions[num2 + 1] && position1 <= positions[num2 + 1])
        {
            rounds -= 1;
        }

        positions[num2] = position1;

        cout << rounds << '\n';
    }

    return 0;
}
