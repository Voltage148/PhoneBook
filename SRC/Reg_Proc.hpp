//
// Created by Voltage on 1/11/2023.
//

#ifndef PHONEBOOK_REG_PROC_HPP
#define PHONEBOOK_REG_PROC_HPP

//Include needed libs:
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "FormFounctions.hpp"
using namespace std;

//Main namespace:
namespace Reg_Proc
{
  //Class:
  class PhoneBook
  {
    private:

      //Vals:

      int Width = 0;
      int High = 0;

      string PhoneBook_Path = "";
      string PhoneNumber = "";
      string Contact_Name = "";


      //Private methods:

      void InputForm(void)
      {
          //Clear Screen:
          system("cls");

          //Set Background color:
          system("color 10");

          //Make A Box:

          //SetPos:
          Set_Pos(20, 15);
          Set_Color(24);

          //Start Drawing:
          //white bar:
          Set_Pos(20, 14);
          Set_Color(31);//white
          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)219;
          }

          //Input Box:
          for(int Counter_H = 0 ; Counter_H < High; Counter_H++)
          {
              for(int Counter_W = 0 ; Counter_W < Width; Counter_W++)
              {
                  //SetUp Color:
                  if(Counter_W < Width-2){Set_Color(24);}
                  else
                  {
                      Set_Color(16);
                  }

                  Set_Pos(20+Counter_W, 15+Counter_H);
                  cout << (char)219;
              }
          }

          //Print Down shadow:
          Set_Color(16);//Black
          Set_Pos(22, High+15);

          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)219;
          }

          //Print Black Line for model:
          Set_Color(128);//Black;
          Set_Pos(20, 16);

          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)196;
          }

          //Print Title:
          Set_Pos(Width/2, 14);
          Set_Color(112);//Black;

          cout << "Create a New PhoneBook";

          //Print Help:
          Set_Pos(21, 17);
          cout << "Enter File Path or Enter 'Exit' for Exit";
          return;
      }


    public:

      //Make Constructor:
      PhoneBook()
      {
          Width = 120;
          High = 7;
      }

      //Methods:

      //Write at PhoneBook:
      bool Write_DB(void)
      {

          return false;
      }

      //Create New Phonebook:
      bool Create_DB(void)
      {
          //Call:
          InputForm();

          //Print Text:
          Set_Color(128);//Black;

          //Make label for back:
          Back_input:

          //Input Text:
          Set_Pos(22, 18);
          cout << "Enter File Path:";
          //Start Input Process:

          cin >> PhoneBook_Path;

          //Make File:

          if(PhoneBook_Path == "Exit" or PhoneBook_Path == "exit")
          {
              return true;
          }

          else {

              ofstream File_DB;
              File_DB.open(PhoneBook_Path, ios::out);

              if (not File_DB.is_open()) {
                  //Set Color:
                  Set_Color(128);//Black
                  //Set Pos:
                  Set_Pos(22, 20);
                  cout << "Can't Open This Path:" << PhoneBook_Path;
                  Sleep(1500);
                  //Clear Error Line:
                  Set_Pos(22, 20);
                  Clear_Line(90);
                  //Clear Input Line:
                  Set_Pos(22, 18);
                  Clear_Line(90);
                  goto Back_input;
              } else {  //Close File:
                  File_DB.close();
                  //Set Color:
                  Set_Color(128);//Black;
                  //Set Pos:
                  Set_Pos(22, 20);
                  cout << "Phone Book Created!";
                  Sleep(1500);
                  Write_DB();
              }

          }
        return false;
      }
  };

};


#endif //PHONEBOOK_REG_PROC_HPP
