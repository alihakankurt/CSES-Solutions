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

    u16 n, m;
    cin >> n >> m;

    vector<u32> a(n);
    for (u32& num : a)
    {
        cin >> num;
    }

    vector<u32> b(m);
    for (u32& num : b)
    {
        cin >> num;
    }

    auto lcs = vector<vector<u16>>(n + 1, vector<u16>(m + 1, 0));

    for (u16 lengthA = 1; lengthA <= n; lengthA += 1)
    {
        for (u16 lengthB = 1; lengthB <= m; lengthB += 1)
        {
            if (a[lengthA - 1] == b[lengthB - 1])
            {
                lcs[lengthA][lengthB] = lcs[lengthA - 1][lengthB - 1] + 1;
            }
            else
            {
                lcs[lengthA][lengthB] = max(
                    lcs[lengthA][lengthB - 1],
                    lcs[lengthA - 1][lengthB]
                );
            }
        }
    }

    auto sequence = std::vector<u32>(lcs[n][m]);

    u16 sequenceIndex = lcs[n][m] - 1, lengthA = n, lengthB = m;
    while (lengthA > 0 && lengthB > 0)
    {
        if (a[lengthA - 1] == b[lengthB - 1])
        {
            lengthA -= 1;
            lengthB -= 1;
            sequence[sequenceIndex] = a[lengthA];
            sequenceIndex -= 1;
            continue;
        }

        if (lcs[lengthA][lengthB - 1] < lcs[lengthA - 1][lengthB])
        {
            lengthA -= 1;
        }
        else
        {
            lengthB -= 1;
        }
    }

    cout << sequence.size() << '\n';
    for (u32 num : sequence)
    {
        cout << num << ' ';
    }

    return 0;
}
