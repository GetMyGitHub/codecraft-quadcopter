#include <Arduino.h>
#include <communication/Interpretor.hpp>
#include <tools/TextTools.hpp>
#include <configs/Configs.hpp>
#include <vector>


using namespace std;

Interpretor::Interpretor(){
    if(CODECRAFT_LOG_DEBUG) Serial.println("Interpretor : constructor");    
}

void Interpretor::serialCommand(std::string stringCommandValue){
    if(CODECRAFT_LOG_DEBUG) Serial.println("Interpretor : serialCommand");
    string test = TextTools::removeSpacesAndNewlines(stringCommandValue);
    if(CODECRAFT_LOG_DEBUG) Serial.print("Test : ");
    Serial.println(test.c_str());
    if (stringCommandValue.rfind("CMD", 0) == 0) {
        if(CODECRAFT_LOG_DEBUG) Serial.println("Interpretor : command detected");
        vector<string> result = TextTools::split(stringCommandValue, CODECRAFT_COMMAND_DELIMITER);
        TextTools::removeElementFromVector(result, "CMD");
        if(CODECRAFT_LOG_DEBUG) Serial.print("Test cmd is : " );
        for (const std::string str : result){            
            if(CODECRAFT_LOG_DEBUG) Serial.print(str.c_str());
            if(CODECRAFT_LOG_DEBUG) Serial.print(" \t ");
        }
        Serial.print("");
    }
}

