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

      string PhoneBook_Path = "";
      string PhoneNumber = "";
      string Contact_Name = "";

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

      //Clear a Line
      void Clear_Line(int Len)
      {
          for(int Counter = 0 ; Counter < Len ; Counter++)
          {
              cout << " ";
          }
          return;
      }

      //Draw Select Box function:
      void Box_Up(void)
      {          //Draw Title Bar:
          Set_Color(23);//White;
          Set_Pos(45, 11);

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

                  Set_Pos(45+Counter_W, 12+Counter_H);
                  cout << (char)219;
              }
          }

          //Draw Box down Shadow:
          Set_Pos(46,12+high);
          Set_Color(16);//Black;

          for(int Counter = 0 ; Counter < Width-1 ; Counter++)
          {
              cout << (char)219;
          }

          return;
      }
  public:

      //Make constructor:
      Inter_Face()
      {
          //Value of variables:
          Width = 80;
          high = 12;
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


          //Make Box:
          Box_Up();
      }

      //Public Methods:

      //Draw Options and process input:
      int DrawMainMenu_ProcessInput(void)
      {

          //Print Texts:

          Set_Color(112);//Black;

          //Write title:
          Set_Pos(Width / 2 + 45, 11);
          cout << "PhoneBook";


          Set_Color(128);
          //Write options:
          Set_Pos(Width-10, 14);
          cout << "1->Write at Phone Book";

          Set_Pos(Width-10, 16);
          cout << "2->Search at Phone Book";

          Set_Pos(Width-10, 18);
          cout << "3->View License";

          Set_Pos(Width-10, 20);
          cout << "4->Exit";

          //Make a label for back:
          Input_Back:
          //Select:
          Set_Pos(45+3, 23);
          cout << "Enter a Char:";
          //Var:
          Set_Pos(45+16, 23);

          switch(getch())
          {
              case '1':return 1;break;
              case '2':return 2;break;
              case '3':return 3;break;
              case '4':return 4;break;

              default:
                  Set_Pos(45+3, 23);
                  cout << "Please Enter a valid Char!";
                  Sleep(1500);
                  //Clear Line:
                  Set_Pos(45+3,23);
                  Clear_Line(26);
                  //back:
                  goto Input_Back;
                  break;
          }
      }



      //Write phonebook menu:
      int WriteMenu(void)
      {
          //Clear Options Text:
          for(int Counter = 0 ; Counter < 4*2 ; Counter+=2)
          {
              Set_Pos(Width - 10, 14+Counter);
              Clear_Line(30);
          }

          //Print options:

          Set_Color(128);

          Set_Pos(Width-10, 14);
          cout << "1->Create New Book";

          Set_Pos(Width-10, 17);
          cout << "2->Write in Book";

          Set_Pos(Width-10, 20);
          cout << "3->Exit";

          //Input Char:

          //Make a label for back:
          Input_Back:
          //Select:
          Set_Pos(45+3, 23);
          cout << "Enter Char for Continue:";
          //Var:
          Set_Pos(72, 23);

          switch(getch())
          {
              case '1':
                  return 1;
                  break;

              case '2':
                  return 2;
                  break;

              case '3':
                    return 3;
                  break;
              default:
                  Set_Pos(45+3, 23);
                  cout << "Please Enter a valid Char!";
                  Sleep(1500);
                  //Clear Line:
                  Set_Pos(45+3,23);
                  Clear_Line(26);
                  //back:
                  goto Input_Back;
                  break;
          }

      }

  };
};


#endif //PHONEBOOK_FORM_HPP
