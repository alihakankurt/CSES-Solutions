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
            Add(index, values[index]);
        }
    }

    void Add(usize index, TScalar delta)
    {
        if (index == 0)
        {
            _tree[0] += delta;
            return;
        }

        while (index < _tree.size())
        {
            _tree[index] += delta;
            index += index & -index;
        }
    }

    TScalar Sum(usize index)
    {
        TScalar result = _tree[0];
        while (index > 0)
        {
            result += _tree[index];
            index -= index & -index;
        }

        return result;
    }

    TScalar Sum(usize left, usize right)
    {
        return Sum(right) - Sum(left);
    }

    void Reset()
    {
        fill(_tree.begin(), _tree.end(), 0);
    }
};

struct Range
{
    usize Index;
    usize Start;
    usize End;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    set<usize> uniqueValues;
    vector<Range> ranges(n);
    for (usize index = 0; index < n; index += 1)
    {
        usize start, end;
        cin >> start >> end;
        ranges[index] = Range{index, start, end};
        uniqueValues.insert(start);
    }

    map<usize, usize> uniqueIndices;
    usize uniqueIndex = 1;
    for (usize value : uniqueValues)
    {
        uniqueIndices[value] = uniqueIndex;
        uniqueIndex += 1;
    }

    sort(ranges.begin(), ranges.end(), [](const Range& left, const Range& right) {
        return (left.End == right.End) ? left.Start > right.Start : left.End < right.End;
    });

    vector<usize> contains(n, 0), contained(n, 0);
    BinaryIndexedTree<usize> bit(n + 1);

    for (usize index = 0; index < n; index += 1)
    {
        usize sourceIndex = ranges[index].Index;
        usize targetIndex = uniqueIndices[ranges[index].Start];

        contains[sourceIndex] = index - bit.Sum(targetIndex - 1);
        bit.Add(targetIndex, 1);
    }

    bit.Reset();
    for (isize index = n - 1; index >= 0; index -= 1)
    {
        usize sourceIndex = ranges[index].Index;
        usize targetIndex = uniqueIndices[ranges[index].Start];

        contained[sourceIndex] = bit.Sum(targetIndex);
        bit.Add(targetIndex, 1);
    }

    for (usize index = 0; index < n; index += 1)
    {
        cout << contains[index] << ' ';
    }

    cout << '\n';

    for (usize index = 0; index < n; index += 1)
    {
        cout << contained[index] << ' ';
    }

    return 0;
}
