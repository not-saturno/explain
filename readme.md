# explain

**explain** is a fast C++ command-line utility for querying Google's Gemini API directly from your terminal.

Instead of leaving the terminal to search for an explanation, you can pass a question or request directly as command-line arguments:

```bash
explain how do I use curl?
```

The arguments provided to `explain` are combined into a query and sent to the Gemini API, which returns a customized response directly in your terminal.

## Requirements

* Linux
* A Google AI Studio API key
* An available `GEMINI_API_KEY` as an environment variable from GEMINI or Google AI Studio

## Installation

### Fedora / Nobara

`explain` is distributed through the [COPR](https://copr.fedorainfracloud.org/) build system.

Enable the COPR repository:

```bash
sudo dnf copr enable saturno/explain
```

Install the package:

```bash
sudo dnf install explain
```

The package is currently available for Fedora-based systems supported by the COPR project, including supported architectures built by COPR.

## Configuration

`explain` requires a Gemini API key to communicate with Google's AI services.

You can obtain an API key through [Google AI Studio](https://aistudio.google.com/).

After obtaining your key, export it as the `GEMINI_API_KEY` environment variable:

```bash
export GEMINI_API_KEY="your-api-key"
```

You can verify that the variable is set with:

```bash
echo "$GEMINI_API_KEY"
```

### Persisting the API key

The command above only sets the variable for the current shell session.

To make it available automatically in future terminal sessions, add the export to your shell configuration file.

For Bash:

```bash
echo 'export GEMINI_API_KEY="your-api-key"' >> ~/.bashrc
source ~/.bashrc
```

For Zsh:

```bash
echo 'export GEMINI_API_KEY="your-api-key"' >> ~/.zshrc
source ~/.zshrc
```

## Usage

Once the package is installed and `GEMINI_API_KEY` is configured, pass your question or request as command-line arguments.

For example:

```bash
explain how do I use curl?
```

You can ask about commands, tools, programming concepts, or other technical questions:

```bash
explain what does chmod 755 do?
```

```bash
explain how does a TCP handshake work?
```

```bash
explain how do I find a process using port 8080?
```

The application uses the complete command-line input as the query sent to Gemini and prints the generated response in the terminal.

## How It Works

The application follows a simple request flow:

```text
Command-line arguments
        │
        ▼
      explain
        │
        ▼
  Build user query
        │
        ▼
  Google Gemini API
        │
        ▼
  Generated response
        │
        ▼
      Terminal
```

At a high level, `explain`:

1. Reads the command-line arguments provided by the user.
2. Combines them into a natural-language query.
3. Sends the query to the Gemini API using the `GEMINI_API_KEY` environment variable.
4. Receives the generated response.
5. Displays the response in the terminal.

## Building From Source

### Dependencies

The project uses:

* C++20
* CMake
* [cpr](https://github.com/libcpr/cpr) for HTTP communication
* [nlohmann/json](https://github.com/nlohmann/json) for JSON handling
* vcpkg for dependency management

Clone the repository:

```bash
git clone https://github.com/not-saturno/explain.git
cd explain
```

Configure the project using CMake:

```bash
cmake --preset default
```

Build:

```bash
cmake --build --preset default
```

The exact CMake preset configuration may vary depending on your environment.

## Packaging

RPM packaging is included in the project for Fedora-based distributions.

The package is built and distributed through Fedora COPR.

The project uses:

* RPM spec files
* `rpmbuild`
* Mock
* Fedora COPR
* Fedora RPM packaging conventions

## Project Status

`explain` is an experimental project and is primarily intended as a personal learning project and a lightweight terminal interface for Gemini.

The project is actively being used to explore:

* Modern C++
* CMake
* C++ dependency management
* HTTP API integration
* JSON APIs
* RPM packaging
* Fedora packaging
* COPR distribution
* Multi-architecture Linux builds

## License

This project and its libraries are licensed under the MIT License in [License](readme.md)
