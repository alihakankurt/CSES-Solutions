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

    constexpr auto log2 = [](usize value) -> usize {
        return 63 - __builtin_clzll(value);
    };

    usize valuesLength, queriesLength;
    cin >> valuesLength >> queriesLength;

    usize maxExponent = log2(valuesLength);
    auto sparseTable = vector<vector<u32>>(maxExponent + 1u, vector<u32>(valuesLength));

    for (usize index = 0u; index < valuesLength; index += 1u)
    {
        cin >> sparseTable[0][index];
    }

    for (usize exponent = 1u; exponent <= maxExponent; exponent += 1)
    {
        for (usize index = 0u; index + (1u << exponent) <= valuesLength; index += 1)
        {
            sparseTable[exponent][index] = min(sparseTable[exponent - 1][index], sparseTable[exponent - 1][index + (1u << (exponent - 1u))]);
        }
    }

    for (usize _ = 1u; _ <= queriesLength; _ += 1u)
    {
        usize left, right;
        cin >> left >> right;
        usize exponent = log2(right - left + 1);
        u32 answer = min(sparseTable[exponent][left - 1u], sparseTable[exponent][right - (1u << exponent)]);
        cout << answer << '\n';
    }

    return 0;
}
