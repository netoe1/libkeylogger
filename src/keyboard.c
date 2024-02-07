#include "keyboard.h"
#include <windows.h>
#define HEX_IS_PRESSED 0x8000

bool IsKeyPressed(const int keycode)
{
    if (GetAsyncKeyState(keycode) && HEX_IS_PRESSED)
    {
        return true;
    }
    return false;
}
