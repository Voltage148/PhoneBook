//
// Created by Voltage on 1/11/2023.
//

//include needed libs:
#include <iostream>
#include <windows.h>

//include project libs:
#include "Form.hpp"
#include "Reg_Proc.hpp"


using namespace std;


//Start Main:
int main(void)
{
    //Create Object:
    Form::Inter_Face Menu;
    Reg_Proc::PhoneBook_WriteCreate Book;

    int SelectWriteMenu = 0;
    int Select = Menu.DrawMainMenu_ProcessInput();

    //Check return val:
    switch(Select)
    {
        case 1:
            SelectWriteMenu = Menu.WriteMenu();
            //Check Selection:
            switch(SelectWriteMenu)
            {
                case 1:
                    Book.Create_DB();
                    break;
                case 2:
                    Book.Write_DB(true);
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

            break;

        case 3:break;

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

    cin.get();
    //End of main
    return 0;
}

