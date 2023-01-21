//
// Created by Voltage on 1/12/2023.
//

#ifndef PHONEBOOK_FORMFOUNCTIONS_HPP
#define PHONEBOOK_FORMFOUNCTIONS_HPP

//include needed libs:
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Pos;
//Funcs:

//Remove Console Scroll Bar method:
void RD_ScrollBar(void)
{
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

    // Get console handle and get screen buffer information from that handle.
    GetConsoleScreenBufferInfo(Console, &screenBufferInfo);

    // Get rid of the scrollbar by setting the screen buffer size the same as
    // the console window size.
    COORD new_screen_buffer_size;

    // screenBufferInfo.srWindow allows us to obtain the width and height info
    // of the visible console in character cells.
    // That visible portion is what we want to set the screen buffer to, so that
    // no scroll bars are needed to view the entire buffer.
    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right -
                               screenBufferInfo.srWindow.Left + 1; // Columns
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom -
                               screenBufferInfo.srWindow.Top + 1; // Rows

    // Set new buffer size
    SetConsoleScreenBufferSize(Console, new_screen_buffer_size);
    return;


}

//Clear a Line
void Clear_Line(int Len)
{
    for(int Counter = 0 ; Counter < Len ; Counter++)
    {
        cout << " ";
    }
    return;
}

//Set Cursor pos method:
void Set_Pos(int x, int y)
{
    Pos.Y = y;
    Pos.X = x;

    SetConsoleCursorPosition(Console, Pos);
    return;
}

//Set Color method:
void Set_Color(int Color)
{
    SetConsoleTextAttribute(Console, Color);
    return;
}

string GetWinUserName(void)
{
    string WinUser= "";
    char nUserName[100];
    DWORD dUserName = sizeof(nUserName);

    if(GetUserName(nUserName, &dUserName))
    {
        WinUser = nUserName;
        return WinUser;
    }
    else
    {
        return "NULL";
    }

}
#endif //PHONEBOOK_FORMFOUNCTIONS_HPP
