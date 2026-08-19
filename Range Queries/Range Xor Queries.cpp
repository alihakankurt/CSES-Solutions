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

    usize valuesLength, queriesLength;
    cin >> valuesLength >> queriesLength;

    auto prefixXor = vector<u32>(valuesLength + 1u);
    for (usize index = 1u; index <= valuesLength; index += 1u)
    {
        cin >> prefixXor[index];
        prefixXor[index] ^= prefixXor[index - 1u];
    }

    for (usize _ = 1u; _ <= queriesLength; _ += 1u)
    {
        usize left, right;
        cin >> left >> right;
        cout << (prefixXor[right] ^ prefixXor[left - 1u]) << '\n';
    }

    return 0;
}
