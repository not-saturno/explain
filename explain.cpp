#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>  
#include <query.h>
#include <commands.h>
#include <vector>

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);

    if(args.size() < 2 || args[1].find("-", 0) != std::string::npos) {
        show_help();
        return -1;
    }

    std::string question {"explain"};
    for(int i = 1; i != args.size(); ++i) {
        question.append(" ");
        question.append(args[i]);
    }

    std::cout << make_request(question) << "\n";

    return 0;
}