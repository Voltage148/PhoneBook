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
#include "Form.hpp"

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

      Form::Inter_Face Menu2;

      //Private methods:

      void InputForm(void)
      {
          //Clear Screen:
          system("cls");

          //Make A Box:

          //SetPos:
          Menu2.Set_Pos(20, 15);
          Menu2.Set_Color(24);

          //Start Drawing:
          for(int Counter_H = 0 ; Counter_H < High; Counter_H++)
          {
              for(int Counter_W = 0 ; Counter_W < Width; Counter_W++)
              {
                  //SetUp Color:
                  if(Counter_W < Width-2){Menu2.Set_Color(24);}
                  else{Menu2.Set_Color(16);//Black}

                  Menu2.Set_Pos(20+Counter_W, 15+Counter_H);
                  cout << (char)219;
              }
          }

          return;
      }


  public:

      //Make Constructor:
      PhoneBook()
      {
        //Val:
        Width = 120;
        High = 5;

        //Make Box:
        InputForm();
      }

      //Methods:
      bool Create_DB(void)
      {
        return false;
      }
  };
};


#endif //PHONEBOOK_REG_PROC_HPP
