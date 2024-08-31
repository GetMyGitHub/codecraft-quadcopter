#include <Arduino.h>
#include <communication/Interpretor.hpp>
#include <control/FlyController.hpp>
#include <tools/TextTools.hpp>
#include <configs/Configs.hpp>
#include <vector>


using namespace std;

Interpretor::Interpretor(){
}

Interpretor::Interpretor(FlyController *pFlyController){
    flyController = pFlyController;
}

void Interpretor::serialCommand(String &stringCommandValue, FlyController *flyController){

    TextTools::removeSpacesAndNewlines(stringCommandValue);
    if(stringCommandValue.startsWith(CODECRAFT_COMMAND_PREFIX.c_str())){
        vector<string> command = TextTools::split(stringCommandValue.c_str(), CODECRAFT_COMMAND_DELIMITER);
         TextTools::removeElementFromVector(command, CODECRAFT_COMMAND_PREFIX);
         flyController->serialPrint("Interpretor : command is : ", true);         
         for (const std::string str : command){
            flyController->serialPrint(str.c_str(), true);
            flyController->serialPrint("\t", true);
         }
         flyController->serialPrintln("  : fin", true);
        //  flyController->serialPrintln(to_string(command.size()), true);
        //  flyController->serialPrintln(command[0], true);   
         if(command[0] == "R") {
            flyController->readRotorCommand(command);
         }
    }
}

