Project: Programming Principles and Practice Using C++ Donage
Description
This project is an implementation of exercises from "Programming Principles and Practice Using C++" by Bjarne Stroustrup, developed in Visual Studio. It provides functionality for registering and managing exercises across different chapters.

Users can easily add new exercises (pages) by following the instructions provided.

Prerequisites
Visual Studio 2022 or newer.
C++20 or higher support enabled in Visual Studio.
Project Setup Instructions
1. Clone the Repository or Copy Files
Clone or copy the solution (.sln) and source code files to your local machine.
2. Configure Visual Studio
Enable C++20
Go to Project > Properties.
Navigate to Configuration Properties > C/C++ > Language.
Set C++ Language Standard to ISO C++20 Standard (/std
++20).
Set Additional Include Directories
Right-click on your project in Solution Explorer.

Select Properties.

Navigate to Configuration Properties > C/C++ > General.

Under Additional Include Directories, add the following paths:

$(ProjectDir)Chapter_1\Chapter_1_H\;
$(ProjectDir)Chapter_2\Chapter_2_H\;
$(ProjectDir)Chapter_3\Chapter_3_H\;


Adding New Exercises
Create a New Chapter Folder (If Needed)
Inside your project folder, create a new directory for the chapter if it doesn’t already exist.
Example: Chapter_4\Chapter_4_H\
Create New Header and Source Files
Inside the new chapter's header folder (Chapter_4_H), create your header file.
Header File: chapter_4_exercises_1.h
In the chapter's main folder (Chapter_4), create your implementation file.
Source File: chapter_4_exercises_1.cpp
chapter_4_exercises_1.h

#pragma once
void chapter_4_exercises_1();

chapter_4_exercises_1.cpp


#include "chapter_4_exercises_1.h"
#include <iostream>

void chapter_4_exercises_1() {
    std::cout << "Chapter 4 Exercise 1" << std::endl;
    // Your exercise implementation here
}

Register the New Exercise
Open register_all_pages.cpp.

Add the following #include statement at the top with the other includes:


#include "chapter_4_exercises_1.h"

Inside the register_all_pages() function, add:
// Chapter 4
register_page("4", "1", "Chapter 4 Exercise 1", chapter_4_exercises_1, 1);


Explanation of register_page Parameters:

register_page(
    "4",                      // Chapter Key
    "1",                      // Exercise Key
    "Chapter 4 Exercise 1",   // Display Name
    chapter_4_exercises_1,    // Function to Call
    1                         // Order within Chapter
);


Usage
Running the Program
Build the solution by pressing Ctrl + Shift + B or selecting Build Solution from the Build menu.
Run the solution by pressing Ctrl + F5 or clicking Start Without Debugging.
The Main Menu will appear in the console.
Follow the prompts to select chapters and exercises.
Navigating the Menus
Main Menu: Lists all registered chapters.
Chapter Menu: Lists all exercises within the selected chapter.
Commands:
Enter the number corresponding to your choice.
Enter b to go back to the previous menu.
Enter e to exit the program.
Viewing Output Files
If exercises generate output files, they will be located in the project's runtime directory (usually the same directory as the executable).
Open the files using any text editor to view the results.
Troubleshooting
Common Issues
Include Errors:

Ensure your Additional Include Directories are correctly set in the project settings.
Verify that the paths are correct and that they point to the folders containing your header files.
Missing Functions or Unresolved Externals:

Make sure you've registered new exercises correctly in register_all_pages.cpp.
Check that you've included all necessary headers.
Compilation Errors:

Verify that all syntax is correct.
Ensure all necessary files are included and that there are no typos.
Runtime Errors:

Use debugging tools in Visual Studio to step through your code.
Check for uninitialized variables or invalid memory access.

Folder Structure
A visual representation of the folder hierarchy:

Project Root/
├── Chapter_1/
│   ├── Chapter_1_H/
│   │   └── chapter_1_exercises_1.h
│   └── chapter_1_exercises_1.cpp
├── Chapter_2/
│   ├── Chapter_2_H/
│   │   └── chapter_2_exercises_1.h
│   └── chapter_2_exercises_1.cpp
├── Chapter_3/
│   ├── Chapter_3_H/
│   │   └── chapter_3_exercises_1.h
│   └── chapter_3_exercises_1.cpp
├── Chapter_4/
│   ├── Chapter_4_H/
│   │   └── chapter_4_exercises_1.h
│   └── chapter_4_exercises_1.cpp
├── register_all_pages.cpp
└── ...


Additional Notes
Dependencies:

This project uses standard C++ libraries. No additional dependencies are required.
Sample Output:

You can expect console output similar to:

Main Menu:
1. Chapter 1
2. Chapter 2
3. Chapter 3
4. Chapter 4
e. Exit
Enter your choice:


