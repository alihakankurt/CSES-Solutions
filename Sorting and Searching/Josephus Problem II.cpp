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

template <typename TScalar>
class BinaryIndexedTree
{
  private:
    vector<TScalar> _tree;

  public:
    BinaryIndexedTree(usize n)
    {
        _tree.resize(n, 0);
    }

    BinaryIndexedTree(const vector<TScalar>& values) :
        BinaryIndexedTree(values.size())
    {
        for (usize index = 0; index < values.size(); index += 1)
        {
            Update(index, values[index]);
        }
    }

    void Update(usize index, TScalar delta)
    {
        while (index < _tree.size())
        {
            _tree[index] += delta;
            index += index & -index;
        }
    }

    TScalar Sum(usize index)
    {
        TScalar result = 0;
        while (index > 0)
        {
            result += _tree[index];
            index -= index & -index;
        }

        return result;
    }

    TScalar Sum(usize left, usize right)
    {
        return Sum(right) - Sum(left - 1);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n, k;
    cin >> n >> k;

    BinaryIndexedTree<usize> bit(n + 1);
    for (usize num = 1; num <= n; num += 1)
    {
        bit.Update(num, 1);
    }

    usize p = k % n;
    for (usize turn = 1; turn <= n; turn += 1)
    {
        usize left = 0, right = n;
        while (left < right)
        {
            usize middle = left + (right - left) / 2;
            if (p < bit.Sum(middle))
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }

        bit.Update(left, -1);
        cout << left << ' ';

        if (turn < n)
        {
            p = (p + k) % (n - turn);
        }
    }

    return 0;
}
