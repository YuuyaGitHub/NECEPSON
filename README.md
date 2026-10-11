# NECEPSON
This program is extremely simple; it merely identifies whether the system is an NEC PC-9800 series or EPSON PC series.
## Mechanism
It checks for the presence of the string `"EPSON"` within the BIOS.  
This mechanism is very similar to the "EPSON check" method used at the time.

> [!Note]
> Since it only searches for the simple string `"EPSON"` and does not perform rigorous checks, the determination may vary depending on the circumstances.

# Compiler
The code for this program is designed for Microsoft QuickC 2.00; therefore, the aforementioned compiler is required to build it.  
Building with other compilers is not supported.

# How to run
Simply run `NECEPSON.EXE` to display the results.

The following are examples of execution results on _Neko Project 21/W_ and _FreeDOS(98)_.  
Therefore, the displayed output may differ on actual hardware, other emulators, or MS-DOS.
<img width="640" height="400" alt="image" src="https://github.com/user-attachments/assets/ead4d7b6-29c5-43fa-8325-aae2d0a3ac40" />

# Execution Environment
* NEC PC-9800 series or EPSON PC series
* Any DOS-based OS
> [!NOTE]
> It does not run on systems other than the NEC PC-98, such as the IBM PC.
