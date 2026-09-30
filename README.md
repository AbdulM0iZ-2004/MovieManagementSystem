# Movie Management System (C++)

An Object-Oriented C++ console application designed to manage and categorize different genres of movies using inheritance and polymorphism.

---

## Overview

The **Movie Management System** models a collection of movies categorized into specific genres (Action, Animation, and Sci-Fi). Built with modern C++ OOP principles, it demonstrates base class inheritance, method overriding, and modular file organization.

---

## Features

- **Inheritance & Polymorphism:** A shared base `Movie` class extended by genre-specific classes (`ActionMovie`, `AnimationMovie`, `SciFiMovie`)[cite: 9].
- **Genre Specialization:** Custom attributes and specialized behaviors tailored for Action, Animation, and Science Fiction movies[cite: 9].
- **Clean Architecture:** Fully separated header files (`.h`) and implementation files (`.cpp`) for maintainability[cite: 9].

---

## Project Structure

```text
MovieManagementSystem/
├── Movie.h / Movie.cpp              # Base Movie class definition and implementation
├── ActionMovie.h / ActionMovie.cpp  # Action movie derived class
├── AnimationMovie.h / .cpp          # Animation movie derived class
├── SciFiMovie.h / SciFiMovie.cpp    # Sci-Fi movie derived class
├── main.cpp                         # Program entry point and runtime demonstration
├── Run command.txt                  # Build and compilation instructions
└── movie_program.exe                # Precompiled executable (Windows)
