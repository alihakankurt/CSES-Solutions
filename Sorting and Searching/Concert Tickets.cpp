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

    multiset<u32, greater<>> tickets;
    for (usize index = 0; index < n; index += 1)
    {
        u32 ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    while (m > 0)
    {
        m -= 1;

        u32 customer;
        cin >> customer;

        auto it = tickets.lower_bound(customer);
        if (it == tickets.end())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << *it << '\n';
            tickets.erase(it);
        }
    }

    return 0;
}
