//
// Created by Voltage on 1/11/2023.
//

//include needed libs:
#include <iostream>
#include <windows.h>

//include project libs:
#include "Form.hpp"
#include "Reg_Proc.hpp"
#include "Form.hpp"

using namespace std;

void ViewLicense(void);

//Start Main:
int main(void)
{
    //Create Object:
    Form::Inter_Face Menu;
    Reg_Proc::PhoneBook_WriteCreate Book_W;
    Reg_Proc::PhoneBook_ReadSearch Book_R;

    int SelectWriteMenu = 0;
    int SelectReadMenu = 0;
    int Select = 0;

    Select = Menu.DrawMainMenu_ProcessInput();

    //Check return val:
    switch(Select)
    {
        case 1:
            SelectWriteMenu = Menu.WriteMenu();
            //Check Selection:
            switch(SelectWriteMenu)
            {
                case 1:
                    Book_W.Create_DB();
                    break;
                case 2:
                    Book_W.Write_DB(true);
                    break;
                case 3:
                    //Exit:
                    //Clear Screen:
                    system("cls");
                    //Back before ground color:
                    system("color");
                    //return and exit:
                    return 0;
                    break;
            }
        break;

        case 2:
            SelectReadMenu = Menu.ReadSearchMenu();

            switch(SelectReadMenu)
            {
                case 1:
                    Book_R.ListBook();
                    break;
                case 2:
                    Book_R.SearchContact();
                    break;
                case 3:
                    //Exit:
                    //Clear Screen:
                    system("cls");
                    //Back before ground color:
                    system("color");
                    //return and exit:
                    return 0;
                    break;
            }
            break;

        case 3:
            ViewLicense();
            break;

        case 4:
            //Exit:
            //Clear Screen:
            system("cls");
            //Back before ground color:
            system("color");
            //return and exit:
            return 0;
            break;
    }

    //End of main
    return 0;
}

void ViewLicense(void)
{
    system("cls & color 10");
    Reg_Proc::Width = 120;
    Reg_Proc::High = 4;
    Reg_Proc::InputForm(15, 15, "Create By Voltage for C++ Practice. it's free on github. It's a simple program like DOS Programs.", "License");
    cin.get();
    return;
}
