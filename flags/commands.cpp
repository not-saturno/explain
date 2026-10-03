#include <iostream>
#include <format>
#include <commands.h>


void show_help() {
    std::cout << std::format(R"(explain is a tool for explaining command line tools and guiding users towards using them effectively.

Usage:

        explain <question>
        
The commands or arguments are:

        -h | --help for reading this help page.

Use "explain <question>" for basic usage of this command line application.
)");
}


void show_help_question() {
    std::cout << std::format(R"(Usage: explain [question]
        
The question runs a question through an external LLM using a customized profile.
It turns your input into a prompt that when processed will turn into a useful and practical explanation
of how to run the bash command or a set of bash commands through a single question.
)");
}