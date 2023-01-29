//
// Created by Voltage on 1/11/2023.
//

#ifndef PHONEBOOK_REG_PROC_HPP
#define PHONEBOOK_REG_PROC_HPP

//Include needed libs:
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include "FormFounctions.hpp"
using namespace std;

//Main namespace:
namespace Reg_Proc
{
    int Width = 0;
    int High = 0;

    string PhoneBook_Path = "";
    string PhoneNumber = "";
    string Contact_Name = "";
    int Contact_Number = 0;

    //Methods:

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


    void GetFilePath(void)
    {
        //Call:
        Width = 120;
        High = 7;
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

        if(PhoneBook_Path == "@")
        {
            PhoneBook_Path = {"C:\\Users\\" + GetWinUserName() + "\\Desktop\\Book.pb"};
        }
        else if(PhoneBook_Path == "&")
        {
            PhoneBook_Path = {"C:\\Users\\" + GetWinUserName() + "\\Documents\\Book.pb"};
        }
        return;
    }

    string Extract_Name(string Text)
    {
        string Name = "";

        for(int Counter = 0 ; Counter < Text.length() ; Counter++)
        {
            if(Text[Counter] != '=')
            {
                Name = Name + Text[Counter];
            }
            else
            {
                break;
            }
        }
        return Name;
    }

    string Extract_PhoneNumber(string Text)
    {
        string Phone_Number = "";

        for(int Counter = Text.length() -1 ; Counter >= 0 ; Counter--)
        {
            if(Text[Counter] != '=')
            {
                Phone_Number += Text[Counter];
            }
            else
            {
                break;
            }
        }

        reverse(Phone_Number.begin(), Phone_Number.end());
        return Phone_Number;
    }

  //Class:
  class PhoneBook_WriteCreate
  {
  private:

      bool is_exist_equals(string Text)
      {
          bool is_exist = false;

          for(int Counter = 0 ; Counter < Text.length() ; Counter++)
          {
              if(Text[Counter] == '=') {
                  is_exist = true;
                  break;
              }
          }
              return is_exist;
      }

    public:

      //Make Constructor:
      PhoneBook_WriteCreate()
      {
          Width = 120;
          High = 7;
      }

      //Methods:


      //Write at PhoneBook:
      bool Write_DB(bool is_app)
      {
          vector <string> Names;
          ofstream File;

          if(is_app == true)
          {
              GetFilePath();
              ifstream File_Book(PhoneBook_Path, ios::in);
              string Tmp;
              while(File_Book >> Tmp)
              {
                  if(Tmp[0] != '0')
                  {
                      Names.push_back(Extract_Name(Tmp));
                  }
              }
              File_Book.close();

              //Open File for write:

              File.open(PhoneBook_Path, ios::out | ios::app);

          }

          else{File.open(PhoneBook_Path, ios::out);}

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


          if(File.is_open())
          {
            Set_Color(128);//Black
            while (true) 
            {

                Set_Pos(53+13, 16);

                Clear_Line(40);
                Set_Pos(53, 16);
                cout << "Content Name:";
                cin >> Contact_Name;


                if(is_exist_equals(Contact_Name) == false)
                {
                    if (Contact_Name == "Exit" or Contact_Name == "exit") {
                        File.close();
                        Names.clear();
                        return true;
                    }
                    else {
                        bool is_exist = false;
                        if (Names.size() > 0) {
                            for (int index = 0; index < Names.size(); index++) {
                                if (Names.at(index) == Contact_Name) {
                                    is_exist = true;
                                    break;
                                }

                            }
                        } else {
                            Names.push_back(Contact_Name);
                            is_exist = false;
                        }

                        if (is_exist == false) {
                            Names.push_back(Contact_Name);


                            Set_Pos(53, 18);
                            cout << Contact_Name + " Number:";
                            cin >> PhoneNumber;

                            File << Contact_Name << "=" << PhoneNumber << endl;

                            Set_Pos(53, 16);
                            Clear_Line(55);

                            Set_Pos(53, 18);
                            Clear_Line(55);


                            Set_Pos(53, 21);
                            cout << "Number:" << Names.size();

                        }
                        else {
                            Set_Pos(53, 25);
                            cout << Contact_Name << " is already exist!";
                            Sleep(1500);
                            Set_Pos(53, 25);
                            Clear_Line(40);
                        }

                    }
                }

                else
                {
                    Set_Pos(53, 25);
                    cout << "You can't use '='!";
                    Sleep(1500);
                    Set_Pos(53, 25);
                    Clear_Line(40);
                }
            }

          }

          return false;
      }

      //Create New Phonebook:
      bool Create_DB(void)
      {
         //Call:
         Back_input:
         GetFilePath();

          //Make File:

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
          }
          else
          {
              //Close File:
              File_DB.close();
              //Set Color:
              Set_Color(128);//Black;
              //Set Pos:
              Set_Pos(22, 20);
              cout << "Phone Book Created!";
              Sleep(1500);


              Write_DB(false);


          }
        return false;
      }
  };

  class PhoneBook_ReadSearch
  {
      /*
       * Search at book and read book
       */



  public:

      bool SearchContact(void)
      {
          //Make a Gui for input name:

          system("cls & color 10");
          Set_Color(24);//Gray

          GetFilePath();

          //Make an Input Box:

          Width = 70;
          High = 8;
          InputForm(44, 15, "Enter Your Contact Name or 'exit' -> Exit ", "Search At Book");

          //Start Process:

          ifstream Base_File(PhoneBook_Path, ios::in);

          if(Base_File.is_open())
          {
              vector<string> Names;
              vector<string> Phone_Numbers;
              string Tmp_Line = "";

              bool is_found = false;
              int User_Number = 0;

              while(Base_File >> Tmp_Line)
              {
                  Names.push_back(Extract_Name(Tmp_Line));
                  Phone_Numbers.push_back(Extract_PhoneNumber(Tmp_Line));
              }

              while(true)
              {
                  Set_Pos(46, 20);
                  Clear_Line(Width-8);

                  Set_Pos(46, 18);
                  Clear_Line(Width-8);

                  Set_Pos(46, 18);
                  cout << "Contact:";
                  cin >> Contact_Name;

                  if(Contact_Name == "exit" or Contact_Name == "Exit")
                  {
                      return false;
                  }

                  else
                  {
                      for(int Index = 0 ; Index < Names.size() ; Index++)
                      {
                          if(Names.at(Index) == Contact_Name)
                          {
                              is_found = true;
                              User_Number = Index;
                              break;
                          }
                      }

                      switch(is_found)
                      {
                          case true:
                              Set_Pos(46, 20);
                              cout << Contact_Name + ": " + Phone_Numbers.at(User_Number);
                              is_found = false;
                              getch();
                              break;

                          case false:
                              Set_Pos(46, 20);
                              cout << "Can't found it!";
                              getch();
                              break;
                      }
                  }
              }

              Base_File.close();
          }
        return true;
      }

      bool ListBook(void)
      {

        return true;
      }

  };

};


#endif //PHONEBOOK_REG_PROC_HPP
