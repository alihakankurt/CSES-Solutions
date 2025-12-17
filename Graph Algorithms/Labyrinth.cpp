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

const vector<pair<u16, u16>> Directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
const vector<char> DirectionLetters = {'L', 'R', 'U', 'D'};
const u8 DirectionCount = Directions.size();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 height, width;
    cin >> height >> width;

    auto labyrinthMap = vector<string>(height);
    u16 startY, startX;
    u16 endY, endX;
    for (u16 y = 0; y < height; y += 1)
    {
        string& row = labyrinthMap[y];
        cin >> row;

        for (u16 x = 0; x < width; x += 1)
        {
            if (row[x] == 'A')
            {
                startY = y;
                startX = x;
            }
            else if (row[x] == 'B')
            {
                endY = y;
                endX = x;
            }
        }
    }

    auto moveDirections = vector<vector<u8>>(height, vector<u8>(width, DirectionCount));
    queue<pair<u16, u16>> qu;

    moveDirections[startY][startX] = 0;
    qu.emplace(startY, startX);

    while (!qu.empty())
    {
        auto [y, x] = qu.front();
        qu.pop();

        if (y == endY && x == endX)
        {
            string path;
            while (y != startY || x != startX)
            {
                u8 directionIndex = moveDirections[y][x];
                path += DirectionLetters[directionIndex];
                auto [dy, dx] = Directions[directionIndex ^ 1];
                y += dy;
                x += dx;
            }

            reverse(path.begin(), path.end());
            cout << "YES" << '\n';
            cout << path.length() << '\n';
            cout << path;
            return 0;
        }

        for (u8 directionIndex = 0; directionIndex < DirectionCount; directionIndex += 1)
        {
            auto [dy, dx] = Directions[directionIndex];
            u16 ny = y + dy;
            u16 nx = x + dx;
            if (ny < height && nx < width && labyrinthMap[ny][nx] != '#' && moveDirections[ny][nx] == DirectionCount)
            {
                moveDirections[ny][nx] = directionIndex;
                qu.emplace(ny, nx);
            }
        }
    }

    cout << "NO" << '\n';

    return 0;
}
