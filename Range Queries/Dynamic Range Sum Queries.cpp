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

template <typename T>
class BinaryIndexedTree
{
    vector<T> _data;

  public:
    explicit BinaryIndexedTree(usize n)
    {
        _data.resize(n + 1u, T{});
    }

    explicit BinaryIndexedTree(const vector<T>& values) :
        BinaryIndexedTree(values.size())
    {
        for (usize index = 0u; index < values.size(); index += 1u)
        {
            Update(index + 1u, values[index]);
        }
    }

    T Query(usize position) const
    {
        auto result = T{};
        while (position > 0u)
        {
            result += _data[position];
            position -= position & -position;
        }

        return result;
    }

    T Query(usize from, usize to) const
    {
        return Query(to) - Query(from - 1u);
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
        fill(_data.begin(), _data.end(), T{});
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize valuesLength, queriesLength;
    cin >> valuesLength >> queriesLength;

    auto bit = BinaryIndexedTree<u64>(valuesLength);

    for (usize position = 1u; position <= valuesLength; position += 1u)
    {
        u64 value;
        cin >> value;
        bit.Update(position, value);
    }

    for (usize _ = 1u; _ <= queriesLength; _ += 1u)
    {
        usize type;
        cin >> type;

        if (type == 1u)
        {
            usize position;
            u64 value;
            cin >> position >> value;
            bit.Update(position, value - bit.Query(position, position));
        }
        else if (type == 2u)
        {
            usize left, right;
            cin >> left >> right;
            u64 answer = bit.Query(left, right);
            cout << answer << '\n';
        }
    }

    return 0;
}
