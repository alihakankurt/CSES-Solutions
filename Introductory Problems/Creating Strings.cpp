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

bool NextPermutation(string& source)
{
    for (isize index = source.size() - 2; index >= 0; index -= 1)
    {
        isize origin = source.size() - 1;
        while (origin > index && source[origin] <= source[index])
            origin -= 1;

        if (origin == index)
            continue;

        char temp = source[index];
        source[index] = source[origin];
        source[origin] = temp;

        isize start = index + 1;
        isize end = source.size() - 1;
        while (start < end)
        {
            temp = source[start];
            source[start] = source[end];
            source[end] = temp;
            start += 1;
            end -= 1;
        }

        return true;
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    sort(str.begin(), str.end());

    vector<string> result = {str};
    while (NextPermutation(str))
    {
        result.push_back(str);
    }

    cout << result.size() << '\n';
    for (const string& permutation : result)
    {
        cout << permutation << '\n';
    }

    return 0;
}
