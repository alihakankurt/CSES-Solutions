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

template <typename T>
class BinaryIndexedTree
{
    vector<T> _data;

  public:
    explicit BinaryIndexedTree(usize n)
    {
        _data.resize(n + 1, 0);
    }

    explicit BinaryIndexedTree(const vector<T>& values) :
        BinaryIndexedTree(values.size())
    {
        for (usize index = 0; index < values.size(); index += 1)
        {
            Update(index + 1, values[index]);
        }
    }

    T Sum(usize position) const
    {
        T result = 0;
        while (position > 0)
        {
            result += _data[position];
            position -= position & -position;
        }

        return result;
    }

    T Sum(usize from, usize to) const
    {
        return Sum(to) - Sum(from - 1);
    }

    void Update(usize position, T delta)
    {
        while (position < _data.size())
        {
            _data[position] += delta;
            position += position & -position;
        }
    }

    void Reset()
    {
        fill(_data.begin(), _data.end(), 0);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    vector<u32> nums(n);
    for (u32& num : nums)
    {
        cin >> num;
    }

    vector<u32> uniqueNums = nums;
    sort(uniqueNums.begin(), uniqueNums.end());
    uniqueNums.erase(unique(uniqueNums.begin(), uniqueNums.end()), uniqueNums.end());
    usize m = uniqueNums.size();

    BinaryIndexedTree<u64> bit(m + 1);
    for (u32 num : nums)
    {
        auto iter = lower_bound(uniqueNums.begin(), uniqueNums.end(), num);
        usize position = iter - uniqueNums.begin() + 1;

        u64 subsequenceCount = bit.Sum(position - 1);
        subsequenceCount = (subsequenceCount + 1) % Modulus;
        bit.Update(position, subsequenceCount);
    }

    u32 totalSubsequenceCount = bit.Sum(m) % Modulus;
    cout << totalSubsequenceCount;

    return 0;
}
