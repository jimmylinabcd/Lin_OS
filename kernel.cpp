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

it's written in C but for somereason it only works when it's a CPP file

Todo list:
clear function
keyboard driver
get the time from bios
commands:
    man
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
#define ROW_SIZE (SCREEN_COLUMNS * 2)

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
void print(int row, int column, int colour, const char *string);
void clear(int row);
void scroll();
void scroll_up();
void input();

int current_line = 0;

// Need extern for assembly to load kernel
extern "C" void main(){
    volatile char *postion = (volatile char*)0xB8000; // where the current pointer is in VID_MEM to print afterwards
    
    //Start up
    print(0, 0, LIGHT_CYAN, "   _      _          ____   _____ ");
    print(1, 0, LIGHT_CYAN, "  | |    (_)        / __ \\ / ____|");
    print(2, 0, LIGHT_CYAN, "  | |     _ _ __   | |  | | (___  ");
    print(3, 0, LIGHT_CYAN, "  | |    | | '_ \\  | |  | |\\___ \\ ");
    print(4, 0, LIGHT_CYAN, "  | |____| | | | | | |__| |____) |");
    print(5, 0, LIGHT_CYAN, "  |______|_|_| |_|  \\____/|_____/ ");

    print(7, 0,GREEN, "Successful boot! Welcome to Lin OS.");

    //while(true){
    print(9, 0, WHITE, ">>>");
    current_line = 9;
    input();
    scroll();
    //}
    return;
}

void print(int row, int column,int colour, const char *string){
    volatile char *VRAM = (volatile char*)0xB8000 + (row * SCREEN_COLUMNS * 2) + (column * 2); // * 2 because each row has 160 vals because 2 addrs for each location
    while(*string != 0){
        *VRAM++ = *string++;
        *VRAM++ = colour;
    }
}

void clear(int row){
    // 0 for clear all
    if(row == 0){
        volatile char *VRAM = (volatile char*)0xB8000;
        int pos = 0;
        while(pos<(SCREEN_COLUMNS * SCREEN_ROWS * 2))
        {
            *VRAM = 0;
            *VRAM++;
            *VRAM = 1;
            pos++;
        }
    }else{
        volatile char *VRAM = (volatile char*)0xB8000 + (row * ROW_SIZE);
        for(int i = 0; i < SCREEN_COLUMNS; i++){
            *VRAM = 0;
            *VRAM++;
            *VRAM = BLACK;
            *VRAM++;
        }
    }  
}

void scroll(){
    current_line -= 1;
    volatile char *VRAM = (volatile char*)0xB8000;
    for(int i = 0; i < SCREEN_COLUMNS; i++){
            *VRAM = 0;
            *VRAM++;
            *VRAM = BLACK;
            *VRAM++;
    }
    VRAM = (volatile char*)0xB8000 + ROW_SIZE; //leave initial line blank
    for(int i = 0; i < SCREEN_ROWS; i++){
        for(int x = 0; x < SCREEN_COLUMNS; x++){
            char *ptr = (char *)VRAM + ROW_SIZE;
            int *ptrc = (int *)VRAM + ROW_SIZE;
            *VRAM = *ptr;
            *VRAM++;
            *VRAM = ptr[1];
            *VRAM++;
        }
    }
    
}

void scroll_up(){
    //WIP
}

void input(){
    // WIP
}