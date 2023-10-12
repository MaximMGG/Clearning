#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x603
#include <windows.h>


#define width 80
#define heitht 24
#define c_sand (char)176
#define c_water (char)219
#define c_wall '#'
#define c_space ' '

typedef char Tmap[heitht][width];
Tmap map;
POINT mousePos;
POINT sellSize;

void ClearMap() {
    memset(map, ' ', sizeof(map));
    map[heitht - 1][width - 1] = '\0';
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
    sellSz.y = (rct.bottom - rct.top) / heitht;
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


void PutSubstance(POINT pt) {
    if (GetKeyState(VK_LBUTTON) < 0)
        map[pt.y][pt.x] = c_sand;
    else if (GetKeyState(VK_RBUTTON < 0))
        map[pt.y][pt.x] = c_space;
}

int main() {

    HWND hwnd = GetConsoleWindow();
    sellSize = GetSellSize(hwnd);
    ClearMap();
    do {
        mousePos = GetMousePos(hwnd, sellSize);
        PutSubstance(mousePos);

        showMap(map);
        printf("\n%d %d", mousePos.x, mousePos.y);
        Sleep(50);

    } while (GetKeyState(VK_ESCAPE) >= 0);

    return 0;
}
