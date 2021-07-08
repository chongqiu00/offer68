#include <iostream>
#include <string>
int main()
{
    std::string s = "Im am h";
      s.replace(1, 1, "%20");
        std::cout << s << std::endl;
}