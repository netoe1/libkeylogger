#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdbool.h>
typedef struct
{
    char key;
    bool isPressed;
} Keyboard;

bool IsKeyPressed(const int keycode);

#endif