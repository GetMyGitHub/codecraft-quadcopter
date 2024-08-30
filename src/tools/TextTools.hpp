
#include <vector>
#include <string>

using namespace std;

class TextTools
{
public:
    TextTools(/* args */);
    virtual ~TextTools(){};
    static vector<string> split(const string str, const string delim);
    static void removeSpacesAndNewlines(String &str);
    static void removeElementFromVector(std::vector<std::string>& vector, const std::string& target);
};

