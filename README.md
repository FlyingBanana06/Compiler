# 📦 Code Runner for C / C++ / Python

A lightweight command-line tool that compiles and runs **single-source files** in **C**, **C++**, or **Python**. Designed for quick testing and simple workflows, this utility validates input, handles compilation, and executes code with user-friendly prompts and error messages.

---

## 📁 Project Structure

```
.
├── bin/           # Final compiled executable goes here (e.g., compiler)
├── input/         # Input source files (.c, .cpp, .py)
├── output/        # Output directory for compiled executables
├── src/
│   ├── main.cpp         # Main logic and user interaction
│   ├── header.hpp       # Function declarations and macros
│   └── header.cpp       # Implementation for file checks and validation
└── README.md      # Project documentation (you’re reading it!)
```

---

## 🛠️ How to Build

To compile the runner, use the following command:

```bash
g++ src/main.cpp src/header.cpp -std=c++17 -o bin/compiler
```

> ✅ Make sure all the `bin/`,  `input/` and `output/` directories exists before running the command. If it doesn’t, create it with:

```bash
mkdir bin input output
```

Once compiled and folders are ready, run the tool using:

```bash
./bin/compiler
```

---

## 🚀 Features

* ✅ Supports **C**, **C++**, and **Python**
* 🧠 Validates filenames to prevent invalid or reserved names (cross-platform)
* 📂 Automatically detects source files in a predefined `input/` directory
* 🎨 Uses colored terminal output for better feedback
* 🔐 Exception-safe with detailed error handling
* ⚠️ **Single-file compilation only**

---

## 🧑‍💻 What I Learned

Through this project, I gained hands-on experience with:

* Managing files and directories using `std::filesystem`
* Using `std::regex` to validate filenames and user input
* Parsing strings with `stringstream` and `getline`
* Implementing platform-independent logic (e.g., path separators)
* Writing modular C++ code with headers and source files
* Handling errors safely with `try-catch` blocks
* Understanding how different languages are compiled or interpreted

This small project brought together many core C++ concepts and taught me how to design a usable, extensible tool from scratch.

---

## 🔮 Future Potential & Extensibility

Although currently designed for single-file compilation, the structure makes it easy to extend:

* 🔧 **Add more languages**: Java, C#, JavaScript, Go, Rust, etc.
* 🧪 **Integrate with judge systems**: As the execution core for an auto-grader or Online Judge platform
* 🗃️ **Support multi-file builds**: By scanning and compiling all relevant `.cpp` and `.h` files
* 🌐 **Add UI or Web Interface**: Wrap with a GUI (Qt) or browser front-end
* 🔐 **Improve security**: Replace `system()` with safer process execution mechanisms

This makes the tool not just a project, but a solid foundation for future software development tooling.

---

## 📌 AI Usage

GPT-4o is used for:

- Modular structure and cross-platform design ideas
- Regex-based filename validation (Windows/Linux safe)
- Clean command-line prompts and error handling
- README writing, formatting, and project clarity
