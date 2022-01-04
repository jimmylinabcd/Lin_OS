
# Lin_OS
A simple kernel I've been coding for fun and learning. I haven't tested it on a actually computer just on a QEMU VM. 

# Features
* Boots up 
* Able to print text in colours!
* Scrolling

# Future plans
- [ ] Keyboard driver (version 1)
- [ ] Can type (Version 1.01)
- [x] Scrolling (version 1.1)
- [ ] Basic commands (version 1.2)
- [ ] User login system (version 1.3)
- [ ] More commands (version 1.4)

# How to use
### Cross Compiling
== Note: When I followed this guide, I experienced multiple issues possibly because it is outdated==
1.  Use a Debian derivative and install gcc. 
2. I followed this guide: [MellOs/setup-gcc.sh at main · mell-o-tron/MellOs (github.com)](https://github.com/mell-o-tron/MellOs/blob/main/A_Setup/setup-gcc.sh)
3. Afterwards use this command to compile all the files.
4. [OS-Reference/run.sh at main · mell-o-tron/OS-Reference (github.com)](https://github.com/mell-o-tron/OS-Reference/blob/main/7/run.sh)

### Or just run OS.bin
1. Use this command `qemu-system-x86_64 -drive file=OS.bin,format=raw,index=0,media=disk  -L "C:\Program Files\qemu"`

# More info
### More resources:
Info on OS development:
[Expanded Main Page - OSDev Wiki](https://wiki.osdev.org/Main_Page)
YouTube Tutorial that walks you through to creating kernel
[Making an OS (x86) Chapter 1 - CPU, Assembly, Booting ](https://www.youtube.com/watch?v=MwPjvJ9ulSc)
Seting up the environment: (needs Debian derivative )
[MellOs/setup-gcc.sh at main · mell-o-tron/MellOs (github.com)](https://github.com/mell-o-tron/MellOs/blob/main/A_Setup/setup-gcc.sh)
Compiling the OS:
[OS-Reference/run.sh at main · mell-o-tron/OS-Reference (github.com)](https://github.com/mell-o-tron/OS-Reference/blob/main/7/run.sh)
