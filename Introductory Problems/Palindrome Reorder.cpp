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

    string str;
    cin >> str;

    u32 oddCount = 0;
    u32 counts[27]{0};
    for (usize index = 0; index < str.size(); index += 1)
    {
        usize letter = str[index] & 0x1F;
        counts[letter] += 1;
        oddCount += ((counts[letter] & 1) == 0) ? -1 : 1;
    }

    if (oddCount > (str.size() & 1))
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string palindrome;
    palindrome.resize(str.size());
    usize left = 0, right = str.size() - 1;
    for (usize letter = 1; letter <= 26; letter += 1)
    {
        while (counts[letter] >= 2)
        {
            palindrome[left] = letter | 64;
            palindrome[right] = letter | 64;
            left += 1;
            right -= 1;
            counts[letter] -= 2;
        }

        if (counts[letter] == 1)
        {
            palindrome[str.size() / 2] = letter | 64;
        }
    }

    cout << palindrome;

    return 0;
}
