# Robust Data Transformation Pipeline

A modular C++ application designed to demonstrate efficient file I/O operations and the **Separation of Concerns** principle. This project implements a pipeline that reads raw data, applies custom processing logic, and routes results to either a success terminal or an error log based on the data's integrity.



## 🚀 Core Concepts Demonstrated
* **Encapsulation:** Logic is strictly divided between file management (`FileHandler`) and data manipulation (`DataProcessor`).
* **Error Logging:** Implements a dedicated error-routing mechanism to ensure that malformed data does not interrupt the primary execution flow.
* **Buffer Management:** Demonstrates how to handle file streams (`fstream`) safely without memory leaks.
* **Modular Architecture:** The project is structured so that the processing logic can be swapped out without changing the I/O code.

## ✨ Features
* **Automated File Management:** Automatically opens, validates, and closes multiple file streams (Input, Output, and Error).
* **Custom Data Filters:** Includes logic to parse strings, identify errors, and format text for the output destination.
* **Robust Exception Handling:** Gracefully handles missing files or permission issues using C++ standard exceptions.
* **Clean CLI Output:** Provides real-time feedback in the console about the status of the processing task.

## 🛠️ Configuration & Installation

### Prerequisites
* A C++ compiler supporting C++11 or higher (e.g., `g++` or `clang`).

### Compilation
Use the following command to compile the project:
```bash
g++ main.cpp -o data_pipeline
```

### Running the Project
Before running, ensure an `input.txt` file exists in the directory.
```bash
./data_pipeline
```

## 🔄 Workflow
1.  **Read:** `FileManager` opens the `input.txt` and reads data line-by-line or block-by-block.
2.  **Process:** `StreamProcessor` receives the data, cleans it, and performs transformations (e.g., case conversion or filtering).
3.  **Route:** * **Success:** Clean data is written to `output.txt`.
    * **Failure:** Any parsing errors or invalid entries are timestamped and sent to `error.txt`.

## 📁 Project Structure
* `main.cpp`: Orchestrates the flow between the handler and the processor.
* `StreamProcessor.h`: Contains the core logic for data transformation.
* `FileManager.h`: Wraps the C++ Standard Library `fstream` for simplified read/write operations.
* `input.txt`: Your raw source data.
* `output.txt`: The final, processed result.
* `error.txt`: A detailed log of any issues encountered during runtime.
