#include <iostream>
using namespace std;

#include "./utility/Logger.h"
using namespace fenli::utility;



int main()
{   
    //Logger::instance();
    Logger::instance()->open("./test.log");
    Logger::instance()->level(Logger::INFO);
    Logger::instance()->max(1024);
    //Logger::instance()->log(Logger::DEBUG,__FILE__,__LINE__,"hello");
    //Logger::instance()->log(Logger::DEBUG,__FILE__,__LINE__,"name is %s, age is %d","wad",12);
    debug("debug"); 
    info("info");
    warn("warn");
    error("error");
    return 0;
}
