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

    //Create a object:
    Form::Inter_Face Menu;
    Menu.DrawMainMenu();
    cin.get();

    //End of main
    return 0;
}

