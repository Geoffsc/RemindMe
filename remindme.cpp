#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>

int parse_duration(const std::string& arg) {
    int multiplier = 1;
    if (arg.back() == 'm') {
        multiplier = 60;
    }
    std::string numberPart = (arg.back() == 'm') ? arg.substr(0, arg.size() - 1) : arg;
    return std::stoi(numberPart) * multiplier;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: remindme <seconds|Nm> [message] [--notify] [--speak]\n";
        return 1;
    }

    int duration = parse_duration(argv[1]);
    std::string message = "Time's up!";
    bool notify = false;
    bool speak = false;

    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--notify") {
            notify = true;
        } else if (arg == "--speak") {
            speak = true;
        } else {
            message = arg;
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds(duration));
    std::cout << "🔔 Reminder: " << message << std::endl;

    if (notify) {
        std::string cmd = "notify-send \"Reminder\" \"" + message + "\"";
        system(cmd.c_str());
    }

    if (speak) {
        std::string cmd = "espeak \"" + message + "\"";
        system(cmd.c_str());
    }

    return 0;
}
