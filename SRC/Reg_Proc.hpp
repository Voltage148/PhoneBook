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

      //Val's:

      int Width = 0;
      int High = 0;

      string PhoneBook_Path = "";
      string PhoneNumber = "";
      string Contact_Name = "";
      int Contact_Number = 0;


      //Private methods:

      void InputForm(int Start_W, int Start_H, string Help_Text, string Title)
      {
          //Clear Screen:
          system("cls");

          //Set Background color:
          system("color 10");

          //Make A Box:

          //SetPos:
          Set_Pos(Start_W, Start_H);
          Set_Color(24);

          //Start Drawing:
          //white bar:
          Set_Pos(Start_W, Start_H-1);
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

                  Set_Pos(Start_W+Counter_W, Start_H+Counter_H);
                  cout << (char)219;
              }
          }

          //Print Down shadow:
          Set_Color(16);//Black
          Set_Pos(Start_W+2, High+Start_H);

          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)219;
          }

          //Print Black Line for model:
          Set_Color(128);//Black;
          Set_Pos(Start_W, Start_H);

          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)196;
          }

          //Print Title:
          Set_Pos((Width+Start_W)/2, Start_H-1);
          Set_Color(112);//Black;

          cout << Title;

          //Print Help:
          Set_Color(128);
          Set_Pos(Start_W+2, Start_H+1);
          cout << Help_Text;
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
          //Clear Screen And Set background color:
          system("cls & color 10");
          Width = 60;
          High = 15;
          InputForm(50, 12, "Enter Name and Phone Number or 'exit' for Exit", "Writing");

          //Print a Line:
          Set_Pos(50, 15);

          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)196;
          }
          Set_Pos(50, 20);
          for(int Counter_W = 0 ; Counter_W < Width-2 ; Counter_W++)
          {
              cout << (char)196;
          }


          //Write Text:
          //Set Pos:
          Set_Pos(53, 21);
          cout << "Number:0";

          Set_Pos(53, 22);
          cout << "Enter 'Exit' in Contact Name for Exit or";
          Set_Pos(53, 23);
          cout << "Press CTRL+C";


          //Open File for write:
          ofstream File(PhoneBook_Path, ios::out);
          if(File.is_open())
          {
              Set_Color(128);//Black
              while (true) {

                  Set_Pos(53, 16);
                  cout << "Content Name:";
                  cin >> Contact_Name;

                  if(Contact_Name == "Exit" or Contact_Name == "exit")
                  {
                      File.close();
                      return true;
                  }
                  else
                  {
                      //Set Pos:

                      Set_Pos(53, 18);
                      cout << Contact_Name + " Number:";
                      cin >> PhoneNumber;

                      File << Contact_Name << " " << PhoneNumber << endl;

                      Set_Pos(53, 16);
                      Clear_Line(55);

                      Set_Pos(53, 18);
                      Clear_Line(55);


                      Set_Pos(53, 21);
                      Contact_Number++;
                      cout << "Number:" << Contact_Number;

                  }

              }
          }
          return false;
      }

      //Create New Phonebook:
      bool Create_DB(void)
      {
          //Call:
          InputForm(20, 15,
           "Enter Path or 'Exit' for exit.'@'= Create book.pb on your Desktop or '&'= Create book.pb in Documents folder.",
           "Create New Book");

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

                if(PhoneBook_Path[0] == '@')
                {
                    PhoneBook_Path = "C:\\Users\\" + GetWinUserName() + "\\Desktop\\Book.pb";
                }

                else if(PhoneBook_Path[0] == '&')
                {
                    PhoneBook_Path = "C:\\Users\\" + GetWinUserName() + "\\Documents\\Book.pb";
                }

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
