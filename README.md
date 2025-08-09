# cpp-tcp-server
A simple TCP server written in C++ using the Winsock API. Listens for incoming connections on port 5000 and responds with a basic HTML message.

Features -->

TCP Server: Built using the Winsock API for Windows.
Port 5000: Listens for incoming TCP connections on 127.0.0.1:5000.
Basic HTTP Response: Sends a "Hello, World!" message as an HTML response.


## How to Compile and Run in Visual Studio Code

## Step 1: Install Necessary Tools
Install Visual Studio Code: Download and install Visual Studio Code.

## Install a C++ Compiler:

If you are using MinGW, install it from MinGW-w64.
For Visual Studio, you can use the MSVC compiler.
Install the C++ Extension for VS Code: Open VS Code and install the "C/C++" extension by Microsoft.

## Step 2: Configure the Build Task
If you haven't already set up a build task in VS Code, here's how you can do it:

Open your project folder in VS Code.

Press Ctrl+Shift+B to open the Build Tasks.

If prompted to create a tasks.json file, VS Code will automatically generate one.


## Step 3: Build the Project
Press Ctrl+Shift+B (or Cmd+Shift+B on macOS) to build the project using the default task.
If the build is successful, it will generate the TCPserver.exe file in your project directory.


## Step 4: Run the Executable
Open the Terminal in VS Code by going to Terminal > New Terminal.

Navigate to the directory where the executable (TCPserver.exe) is located.

## Run the server using the following command:
./TCPserver.exe

## Step 5: Test the Server
Once the server is running, open a web browser to test the server:
http://127.0.0.1:5000 or localhost:5000
