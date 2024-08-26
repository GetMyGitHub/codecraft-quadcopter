#include <Arduino.h>
#include <tools/TextTools.hpp>

using namespace std;

TextTools::TextTools(){
    Serial.println("TextTools : constructor");
}

vector<string> TextTools::split(const string str, const string delim){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

string TextTools::removeSpacesAndNewlines(const string str)
{
  string result;
  for (char c : str) {
    if (c != ' ' && c != '\n' && c != '\r') {
      result += c;
    }
  }
  return result;
}

void TextTools::removeElementFromVector(std::vector<std::string>& vector, const std::string& target) {
    Serial.print("TextTools : removing from list : ");
    Serial.println(target.c_str());
    
    auto it = std::remove(vector.begin(), vector.end(), target);
    vector.erase(it, vector.end());
}