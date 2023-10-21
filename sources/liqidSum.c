#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x603
#include <windows.h>


#define width 80
#define height 24
#define c_sand (char)176
#define c_water (char)219
#define c_wall '#'
#define c_space ' '

typedef char Tmap[height][width];
Tmap map;
POINT mousePos;
POINT sellSize;
enum {
    s_sand = 0,
    s_water,
    s_wall,
    s_last
} substance = s_sand;
char subChar[] = {s_sand, c_water, c_wall};
char *subName[] = {"sand", "water", "wall"};



void ClearMap() {
    memset(map, ' ', sizeof(map));
    map[height - 1][width - 1] = '\0';
}

POINT GetMousePos(HWND hwnd, POINT sellSz) {
    static POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hwnd, &pt);
    pt.x /= sellSz.x;
    pt.y /= sellSz.y;
    return pt;
}

POINT GetSellSize(HWND hwnd) {
    RECT rct;
    GetClientRect(hwnd, &rct);
    POINT sellSz;
    sellSz.x = (rct.right - rct.left) / width;
    sellSz.y = (rct.bottom - rct.top) / height;
    if (sellSz.y == 0)
        sellSz.y = 1;
    return sellSz;
}


void SetCurPos(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

void showMap(Tmap map) {
    SetCurPos(0, 0);
    printf("%s", map[0]);
}

void SelectSubstance() {
    for(int i = 0; i < s_last; i++){
        if(GetKeyState('1' + i) < 0)
            substance = i;
    }
}

void PutSubstance(POINT pt) {
    if (GetKeyState(VK_LBUTTON) < 0)
        map[pt.y][pt.x] = subChar[substance];
    else if (GetKeyState(VK_RBUTTON < 0))
        map[pt.y][pt.x] = c_space;
}


char IfPointInMap(int x, int y) {
    return !((x <0) || (y < 0) || (x >= width) || (y >= height));
}

void MoveSand(int x, int y) {
    for (int i = 0; i <= 1; i += (i == 0 ? -1 : 2)) {
        if (IfPointInMap(x + i, y + 1)) {
            if ((map[y + 1][x + i] == c_space) || (map[y + 1][x + i] == c_water)) {
                map[y][x] = map[y + 1][x + i];
                map[y + 1][x + i] = c_sand;
                break;
            }
        }
    }
}

void MoveSubstance() {
    for (int j = height - 1; j >= 0; j--) {
        for(int i = 0; i < width; i++){
            if (map[j][i] == c_sand)
                MoveSand(i, j);
        }
    }
}

int main() {

    HWND hwnd = GetConsoleWindow();
    sellSize = GetSellSize(hwnd);
    ClearMap();
    do {
        mousePos = GetMousePos(hwnd, sellSize);
        SelectSubstance();
        PutSubstance(mousePos);

        MoveSubstance();

        showMap(map);
        printf("\n%d %d", mousePos.x, mousePos.y);
        Sleep(50);

    } while (GetKeyState(VK_ESCAPE) >= 0);

    return 0;
}
