/* 
LIN OS made by Jimmy Lin

Followed guide to create basic bootloader to load kernel
link:
https://www.youtube.com/watch?v=MwPjvJ9ulSc

Notes: 
need to use debian derivative to cross complile this:
link:
https://github.com/mell-o-tron/MellOs/blob/main/A_Setup/setup-gcc.sh
NOTE: I experienced  many issues with the setuo and had to do it myself

Todo list:
clear function
keyboard driver
get the time from bios
commands:
    man
    cal
    time
    cal
    cls

file manipulation
file system
modules for functions to decluter kernel


*/



// VGA text
#define VID_MEM 0xb8000 //VID_MEM addr increments by 2 to move postion and 1 to switch colour
#define SCREEN_ROWS 25
#define SCREEN_COLUMNS 80

//Colours
#define BLACK 0
#define BLUE 1
#define GREEN 2	
#define CYAN 3
#define RED	4
#define PURPLE 5	
#define BROWN 6
#define GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define YELLOW 14
#define WHITE 15

// Defining functions
void print(int row, int colour, const char *string);
void clear();

// Need extern for assembly to load kernel
extern "C" void main(){
    volatile char *postion = (volatile char*)0xB8000; // where the current pointer is in VID_MEM to print afterwards
    
    print(0, LIGHT_CYAN, "   _      _          ____   _____ ");
    print(1, LIGHT_CYAN, "  | |    (_)        / __ \\ / ____|");
    print(2, LIGHT_CYAN, "  | |     _ _ __   | |  | | (___  ");
    print(3, LIGHT_CYAN, "  | |    | | '_ \\  | |  | |\\___ \\ ");
    print(4, LIGHT_CYAN, "  | |____| | | | | | |__| |____) |");
    print(5, LIGHT_CYAN, "  |______|_|_| |_|  \\____/|_____/ ");

    print(7, LIGHT_CYAN, "Successful boot! Welcome to Lin OS.");
    return;
}

void print(int row,int colour, const char *string){
    volatile char *video = (volatile char*)0xB8000 + (row * 160); // 160 because each row is 80 but there is 2 addrs for 1 column meaning 160 in a row
    while(*string != 0){
        *video++ = *string++;
        *video++ = colour;
    }
}

void clear(){
    // WIP loop to replace everything
    print(0,BLACK, " ");
}