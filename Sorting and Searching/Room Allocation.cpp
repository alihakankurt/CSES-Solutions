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

struct Customer
{
    usize Index;
    u32 Arrival;
    u32 Departure;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    vector<Customer> customers(n);
    for (usize index = 0; index < n; index += 1)
    {
        u32 arrival, departure;
        cin >> arrival >> departure;
        customers[index] = {index, arrival, departure};
    }

    sort(customers.begin(), customers.end(), [](const Customer& left, const Customer& right) -> bool {
        return left.Arrival < right.Arrival;
    });

    usize numberOfRooms = 0;
    vector<usize> allocatedRooms(n);
    priority_queue<pair<u32, usize>, vector<pair<u32, usize>>, greater<pair<u32, usize>>> customerQueue;
    for (const Customer& customer : customers)
    {
        if (customerQueue.empty() || customerQueue.top().first >= customer.Arrival)
        {
            numberOfRooms += 1;
            customerQueue.emplace(customer.Departure, numberOfRooms);
            allocatedRooms[customer.Index] = numberOfRooms;
        }
        else
        {
            auto [_, room] = customerQueue.top();
            customerQueue.pop();
            customerQueue.emplace(customer.Departure, room);
            allocatedRooms[customer.Index] = room;
        }
    }

    cout << numberOfRooms << '\n';
    for (usize index = 0; index < n; index += 1)
    {
        cout << allocatedRooms[index] << ' ';
    }

    return 0;
}
