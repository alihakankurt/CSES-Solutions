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

constexpr i32 Modulus = 1e9 + 7;

const vector<pair<u16, u16>> Directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 height, width;
    cin >> height >> width;

    auto buildingMap = vector<string>(height);
    for (string& row : buildingMap)
    {
        cin >> row;
    }

    u32 numOfRooms = 0;
    for (u16 y = 0; y < height; y += 1)
    {
        for (u16 x = 0; x < width; x += 1)
        {
            if (buildingMap[y][x] == '#')
            {
                continue;
            }

            queue<pair<u16, u16>> qu;
            qu.emplace(y, x);

            while (!qu.empty())
            {
                auto [cy, cx] = qu.front();
                qu.pop();

                for (auto [dy, dx] : Directions)
                {
                    u16 ny = cy + dy;
                    u16 nx = cx + dx;

                    if (ny < height && nx < width && buildingMap[ny][nx] != '#')
                    {
                        qu.emplace(ny, nx);
                        buildingMap[ny][nx] = '#';
                    }
                }
            }

            numOfRooms += 1;
        }
    }

    cout << numOfRooms;

    return 0;
}
