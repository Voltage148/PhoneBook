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
      char Selection = '';
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
  public:

      //Make constructor:
      Inter_Face()
      {
          //Value of variables:
          Width = 55;
          high = 35;
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
          ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
      }

      //Public Methods:

      void DrawMainMenu(void)
      {

          //Draw a Box in Screen:
          Set_Pos(30, 15);
          Set_Color(24);//Gray Color;

          for(int Counter_H = 0 ; Counter_H < high ; Counter_H++)
          {
              for(int Counter_W = 0 ; Counter_W < Width ; Counter_W++)
              {
                  Set_Pos(30+Counter_W, 15+Counter_H);
                  cout << (char)219;
              }
          }

          return;
      }

  };
};


#endif //PHONEBOOK_FORM_HPP
