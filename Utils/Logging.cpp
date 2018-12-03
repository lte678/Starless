//
// Created by leon on 11/20/18.
//

#include "Logging.h"

Logger::Logger() {
    logfile.open(loggingPath);
    logfile << "---Application Start---" << std::endl;
    if(__linux__) {
        struct utsname sysInfo; // NOLINT
        uname(&sysInfo);
        info("OS: " + std::string(sysInfo.sysname) + " " + std::string(sysInfo.machine));
    }
}

Logger::~Logger() {
    info("No errors");
    logfile << "---Application Finished---" << std::endl;
    logfile.close();
}

void Logger::info(const std::string &infoString) {
    logfile << "[INFO]    " << infoString << std::endl;
}

void Logger::warning(const std::string &warningString) {
    logfile << "[WARNING] " << warningString << std::endl;
}

void Logger::error(const std::string &errorString) {
    logfile << "[ERROR]   " << errorString << std::endl;

    logfile << "---Application Terminated---" << std::endl;


    logfile.close();
    exit(EXIT_FAILURE);
}