# SudoGS - Sudoku Generator and Solver in C++

SudoGS is a C++ based tool that provides functionalities for generating and solving Sudoku puzzles. The program is designed to be efficient and versatile, offering both puzzle creation and solution-solving capabilities.

---

## Table of Contents

- [About](#about)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [Uninstallation](#uninstallation)
- [To-Do](#to-do)
- [License](#license)

---

## About

![SudoGS Demo](gif/sudogs.gif)

SudoGS leverages C++ to create and solve Sudoku puzzles. Whether you're looking to challenge yourself with a new puzzle or need assistance solving one, SudoGS has you covered. The project is aimed at providing a reliable and fast solution for Sudoku enthusiasts.

---

## Dependencies

SudoGS relies on [ncurses](https://invisible-island.net/ncurses/), so please make sure to install it before building and running SudoGS.

### Installing the ncurses library in Debian/Ubuntu Linux

```bash
# Using apt
sudo apt-get install libncurses-dev
```

```bash
# Using pacman
sudo pacman -S git ncurses make gcc
```

### Installing the ncurses library in CentOS/RHEL/Scientific Linux 6.x/7.x+ and Fedora Linux

```bash
# Using yum
sudo yum install ncurses-devel
```

### Installing the ncurses library in Fedora Linux 22.x+

```bash
# Using dnf
 sudo dnf install ncurses-devel
```

---

## Installation

To Install SudoGS, follow the steps below.

```bash
# Clone the Repository (http)
git clone https://github.com/SahooBishwajeet/SudoGS.git
```

OR

```bash
# Clone the Repository (ssh)
git clone git@github.com:SahooBishwajeet/SudoGS.git
```

```bash
# Enter the Project Directory
cd SudoGS
```

```bash
# Compile and Install
sudo make install

# Remove generated Object files
make clean
```

---

## Usage

To run the Generator program, enter the TUI by typing the following command.
![SudoGS Generator Demo](gif/sudogs.gif)

```bash
# Run the Program
sudogs
```

---

To run the Solver program, enter the TUI by typing the following command.
![SudoGS Solver Demo](gif/sudogsSolve.gif)

```bash
# Run the Program
sudogs
```

---

Add the help flag to show Usage.
![SudoGS Help](gif/sudogsHelp.gif)

```bash
# Show Usage
sudogs --help 
```

---

Directly generate Sudoku by using the gen flag
![SudoGS Direct Generation](gif/sudogsGen.gif)

```bash
# Generate Sudoku direclty
# difficulty = [1,2,3,4,5]
sudogs --gen [difficulty]
```

---

## Uninstallation

To Uninstall SudoGS, follow the steps below.

```bash
# Uninstall & Delete all
sudo make clean uninstall
```

---

## To-Do

- [X] Code Initial Program
- [X] Implement TUI & CLI For User-Interaction
- [ ] Use ANSII Escapes or Notcurses
- [ ] Better Generation & Solving Algorithm

---

## License

SudoGS is licensed under the [MIT License](LICENSE).

The MIT License is a permissive open-source license that allows for the use, modification, and distribution of the software for any purpose, provided that the original copyright notice and the license text are included with any significant portions of the software or documentation.

For more details, please refer to the [MIT License](LICENSE) file.
