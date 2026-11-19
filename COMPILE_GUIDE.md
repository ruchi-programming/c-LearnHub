# Compile Guide

Compile an individual program from the repository root. Example:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic 02_number_operations/number_operations.c -o number_demo
```

Run on Linux/macOS:

```bash
./number_demo
```

Run on Windows PowerShell:

```powershell
.\number_demo.exe
```

In VS Code, open the repository folder, open the `.c` file you want to run, and use the integrated terminal. Avoid compiling all `.c` files together because each demonstration has its own `main()` function.

For a classroom projector, compile with warnings enabled. Warnings are useful learning feedback; do not simply suppress them.
