#pragma once
#include <string>
#include <string.h>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdarg.h>
using namespace std;

namespace fenli{
namespace utility{
#define debug(format, ...) \
    Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define info(format, ...) \
    Logger::instance()->log(Logger::INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define warn(format, ...) \
    Logger::instance()->log(Logger::WARN, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define error(format, ...) \
    Logger::instance()->log(Logger::ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define fatal(format, ...) \
    Logger::instance()->log(Logger::FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

class Logger
{
public:
    enum Level
    {
        DEBUG = 0,
        INFO,
        WARN,
        ERROR,
        FATAL,
        LEVEL_COUNT
    };
    //定义方法去获取这个唯一实例
    static Logger *instance();
    //声明打开文件的方法
    void open(const string &filename);
    void close();
    void log(Level level,const char *file,int line,const char *format,...);
    void level(Level level)
    {
        m_level = level;
    }
    void max(int bytes)
    {
        m_max = bytes;
    }
private:
    //文件名字
    string m_filename;
    //定义一个流
    ofstream m_fout;
    //为了方便记录声明一个静态的字符串数组
    static const char * s_level[LEVEL_COUNT];
    //定义静态的指针指向唯一实例
    static Logger *m_instance; 
    //存储等级
    Level m_level;
    //记录日志最大
    int m_max;
    //记录当前长度
    int m_len;
    //实现日志翻滚
    void rotate();


//用单例设计模式
private:
    Logger();
    ~Logger();








};

}}
