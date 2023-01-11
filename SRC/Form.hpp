//
// Created by Voltage on 1/11/2023.
//

#ifndef PHONEBOOK_FORM_HPP
#define PHONEBOOK_FORM_HPP

//include needed libs:
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <winuser.h>

using namespace std;

//Main namespace:
namespace Form
{
  //Main Class:
  class Inter_Face
  {
  private:
      char Selection = ' ';
      int Width = 0;
      int high = 0;


      HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD Pos;
      //Funcs:

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
  public:

      //Make constructor:
      Inter_Face()
      {
          //Value of variables:
          Width = 110;
          high = 15;
          Selection = 'N';

          //Graphic Process:

          //Clear Screen:
          system("cls");

          //Set System Console background color:
          system("color 10");

          //Full Screen windows:
          system("mode con COLS=700");
          ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);

          //Delete scroll bar:
          RD_ScrollBar();

          //Hide Cursor:
          HANDLE Cursor_Hide = GetStdHandle(STD_OUTPUT_HANDLE);
          CONSOLE_CURSOR_INFO Cursor_info;
          GetConsoleCursorInfo(Cursor_Hide, &Cursor_info);
          Cursor_info.bVisible = false;
          GetConsoleCursorInfo(Cursor_Hide, &Cursor_info);

      }

      //Public Methods:

      void DrawMainMenu(void)
      {
          //Draw Title Bar:
          Set_Color(23);//White;
          Set_Pos(25, 11);

          for(int Counter_W = 0 ; Counter_W < Width - 2; Counter_W++)
          {
              cout << (char)219;
          }

          //Draw a Box in Screen:
          Set_Color(24);//Gray Color;
          for(int Counter_H = 0 ; Counter_H < high ; Counter_H++)
          {
              for(int Counter_W = 0 ; Counter_W < Width ; Counter_W++)
              {
                  //Set Up shadow color:
                  if(Counter_W < Width-2){ Set_Color(24);}
                  else{ Set_Color(16);}

                  Set_Pos(25+Counter_W, 12+Counter_H);
                  cout << (char)219;
              }
          }

          //Draw Box down Shadow:
          Set_Pos(26,12+high);
          Set_Color(16);//Black;

          for(int Counter = 0 ; Counter < Width-1 ; Counter++)
          {
              cout << (char)219;
          }

          //Print Texts:

          Set_Color(112);//Black;

          //Write title:
          Set_Pos(Width / 2 + 25, 11);
          cout << "PhoneBook";


          Set_Color(128);
          //Write options:
          Set_Pos(Width / 2, 14);
          cout << "1->Write at Phone Book";

          Set_Pos(Width / 2, 16);
          cout << "2->Search at Phone Book";

          Set_Pos(Width / 2, 18);
          cout << "3->View License";

          Set_Pos(Width / 2, 20);
          cout << "4->Exit";

          //Select:
          Set_Pos(25+3, 23);
          cout << "Enter a Char:";
          return;
      }

  };
};


#endif //PHONEBOOK_FORM_HPP
