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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 height, width;
    cin >> height >> width;

    u16 startY, startX;
    queue<pair<u16, u16>> player;
    queue<pair<u16, u16>> monsters;

    auto isEmpty = vector<vector<bool>>(height, vector<bool>(width));
    for (u16 y = 0; y < height; ++y)
    {
        for (u16 x = 0; x < width; ++x)
        {
            char square;
            cin >> square;

            isEmpty[y][x] = square == '.';

            if (square == 'A')
            {
                player.emplace(y, x);
                startY = y;
                startX = x;
            }
            else if (square == 'M')
            {
                monsters.emplace(y, x);
                isEmpty[y][x] = false;
            }
        }
    }

    constexpr u8 directionCount = 4;
    const vector<pair<u16, u16>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    const vector<char> directionLetters = {'L', 'R', 'U', 'D'};

    auto cameFrom = vector<vector<u8>>(height, vector<u8>(width, directionCount));

    while (!player.empty())
    {
        usize positionsCount;

        positionsCount = monsters.size();
        while (positionsCount--)
        {
            auto [y, x] = monsters.front();
            monsters.pop();

            for (auto [dy, dx] : directions)
            {
                u16 ny = y + dy;
                u16 nx = x + dx;

                if (ny < height && nx < width && isEmpty[ny][nx])
                {
                    monsters.emplace(ny, nx);
                    isEmpty[ny][nx] = false;
                }
            }
        }

        positionsCount = player.size();
        while (positionsCount--)
        {
            auto [y, x] = player.front();
            player.pop();

            if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
            {
                vector<char> path;
                while (y != startY || x != startX)
                {
                    u16 directionIndex = cameFrom[y][x];
                    path.push_back(directionLetters[directionIndex]);

                    auto [dy, dx] = directions[directionIndex ^ 1];
                    y += dy;
                    x += dx;
                }

                cout << "YES" << '\n';
                cout << path.size() << '\n';
                for (auto it = path.rbegin(); it != path.rend(); ++it)
                {
                    cout << *it;
                }

                return 0;
            }

            for (u8 directionIndex = 0; directionIndex < directionCount; ++directionIndex)
            {
                auto [dy, dx] = directions[directionIndex];
                u16 ny = y + dy;
                u16 nx = x + dx;

                if (ny < height && nx < width && isEmpty[ny][nx] && cameFrom[ny][nx] == directionCount)
                {
                    player.emplace(ny, nx);
                    cameFrom[ny][nx] = directionIndex;
                }
            }
        }
    }

    cout << "NO";

    return 0;
}
