#include "Utils/Logging.h"
#include "GameManager.h"

int main() {
    Logger *log;
    log = new Logger();
    Starless::GameManager::init(log);

    while(Starless::GameManager::running()) {
        Starless::GameManager::update();
    }

    Starless::GameManager::close();

    return EXIT_SUCCESS;
}