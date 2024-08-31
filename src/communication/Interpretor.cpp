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
        vector<string> result = TextTools::split(stringCommandValue.c_str(), CODECRAFT_COMMAND_DELIMITER);
         TextTools::removeElementFromVector(result, CODECRAFT_COMMAND_PREFIX);
         flyController->serialPrint("Interpretor : command is : ", true);         
         for (const std::string str : result){
            flyController->serialPrint(str.c_str(), true);
            flyController->serialPrint("\t", true);
         }
         flyController->serialPrintln("  : fin", true);
    }

    // if(CODECRAFT_LOG_DEBUG) Serial.println("Interpretor : serialCommand");
    // TextTools::removeSpacesAndNewlines(stringCommandValue);    
    // Serial.println(stringCommandValue);
    // if(stringCommandValue.startsWith("CMD")){
    //     if(CODECRAFT_LOG_DEBUG) Serial.print("Test : startWith");
    // }

    // if (stringCommandValue.rfind("CMD", 0) == 0) {
    //     if(CODECRAFT_LOG_DEBUG) Serial.println("Interpretor : command detected");
    //     // vector<string> result = TextTools::split(stringCommandValue, CODECRAFT_COMMAND_DELIMITER);
    //     // TextTools::removeElementFromVector(result, "CMD");
    //     if(CODECRAFT_LOG_DEBUG) Serial.print("Test cmd is : " );
    //     // for (const std::string str : result){            
    //     //     if(CODECRAFT_LOG_DEBUG) Serial.print(str.c_str());
    //     //     if(CODECRAFT_LOG_DEBUG) Serial.print(" \t ");
    //     // }
    //     Serial.print("");
    // }
}

