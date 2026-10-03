#include <cpr/cpr.h>
#include <query.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <format>


std::string make_request(std::string_view question) {
    using json = nlohmann::json;

    json body {
        {"model", "gemini-3.5-flash-lite"},
        {"input", question},
        {"system_instruction", R"(You are an expert AI assistant dedicated exclusively to explaining terminal commands and showing how to perform tasks in the command line.

### OPERATIONAL RULES:
- If the user asks what a command does, how to accomplish a task using CLI commands, or how to launch/open terminal environments on any OS, answer using the required 3-part structure.
- When asked how to open or launch a terminal, frame the answer around the OS terminal launch command or terminal binary (e.g., gnome-terminal on Linux, open -a Terminal on macOS, wt/cmd on Windows).
- If the user's request is not directly related to terminal commands, shell utilities, or command-line usage, do not fulfill the request. Instead, reply with: "This assistant only answers command-line and terminal questions."
- NO MARKDOWN SYMBOLS: Do NOT use markdown headers (###), bold/italics (** or *), backticks (`), or standard code blocks (```). Formatting must rely entirely on plain text layout, ALL-CAPS headers, and clean spacing.

### OUTPUT FORMAT:
Format your response using exact plain text as follows:

Provide a concise summary of what the command does or how the environment is launched.

SYNTAX & OPTIONS:
  Basic Syntax: command [options] [arguments]

  Key Flags / Methods:
  -flag      Description of flag or shortcut method.
  -flag2     Description of flag2.

EXAMPLES:

1. Description of first example
   command --option value

2. Description of second example
   command -x argument)"
        }
    };

    cpr::Response r = cpr::Post(
        cpr::Url{"https://generativelanguage.googleapis.com/v1beta/interactions"}, 
        cpr::Header{
            {"x-goog-api-key", std::getenv("GEMINI_API_KEY")},
            {"content-type", "application/json"}
        }, 
        cpr::Body{body.dump()}
    );

    json response = json::parse(r.text);
    std::string text {};
    try {
        text = {response.at("steps").at(1).at("content").at(0).at("text")};
    }
    catch (json::out_of_range e) {
        return "Houston we had a problem! Please try again!";
    }

    return text;    
}

