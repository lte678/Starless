//
// Created by leon on 11/20/18.
//

#pragma once

#include <fstream>
#include <string>
#include <sys/utsname.h>

class Logger {
private:
    const std::string loggingPath = "./log.txt";

    std::ofstream logfile;
public:
    Logger();
    ~Logger();

    void info(const std::string &infoString);
    void warning(const std::string &warningString);
    void error(const std::string &errorString);
};
