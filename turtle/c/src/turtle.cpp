//by Raneczech

#include "turtle.h"
#include <iostream>
#include <unistd.h>
#include <termios.h>

int plocha[20][20] = {0};

turtle::turtle() {
    // Initialize position grid to zero
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            pos[i][j] = 0;
        }
    }
    penUp();
    pos[y][x] = 1; // Starting position
    goTo(0,0);
}

void turtle::penUp() {
    pen = 0;
}

void turtle::penDown() {
    pen = 1;
}

void turtle::goTo(int newX, int newY) {
    if(!valid(newX, newY)) return; // Check for valid position
    if(!valid(x, y)) return;
    // Update the last position
    lx = x;
    ly = y;

    // Move to the new position
    x = newX;
    y = newY;

    // Mark the new position on the grid
    if(lx != x || ly != y) {
            if(pen) pos[ly][lx] = 2;
            if(!pen) pos[ly][lx] = 0;
            pos[y][x] = 1; // Assuming 1 indicates the turtle's presence
    }
}

char getch() {
    char buf = 0;
    termios old = {};
    tcgetattr(0, &old);
    termios nw = old;
    nw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &nw);
    read(0, &buf, 1);
    tcsetattr(0, TCSANOW, &old);
    return buf;
}

void grafika(){
    using namespace std;
	cout << "\033[20A";
        for(int i = 0;i<20;i++){
                for(int j=0;j<20;j++){
                        if(plocha[i][j]==1) cout << " ■ ";
                        else if(plocha[i][j]==0) cout << "   ";
                        else cout << "###";
                }
                cout << "\n";
        }
}

void turtle::right(int angle_quarters) {
    smer = (smer + angle_quarters) % 4;
}

void turtle::left(int angle_quarters) {
    smer = (smer - angle_quarters + 4) % 4;
}

void turtle::forward(int distance) {
    if(smer == 0) { // nahoru
        for(int i = 0; i < distance; i++) {
            goTo(x, y - 1);
        }
    } else if(smer == 1) { // doprava
        for(int i = 0; i < distance; i++) {
            goTo(x + 1, y);
        }
    } else if(smer == 2) { // dolu
        for(int i = 0; i < distance; i++) {
            goTo(x, y + 1);
        }
    } else if(smer == 3) { // doleva
        for(int i = 0; i < distance; i++) {
            goTo(x - 1, y);
        }
    }
}

void turtle::backward(int distance) {
    if(smer == 0) { // nahoru
        for(int i = 0; i < distance; i++) {
            goTo(x, y + 1);
        }
    } else if(smer == 1) { // doprava
        for(int i = 0; i < distance; i++) {
            goTo(x - 1, y);
        }
    } else if(smer == 2) { // dolu
        for(int i = 0; i < distance; i++) {
            goTo(x, y - 1);
        }
    } else if(smer == 3) { // doleva
        for(int i = 0; i < distance; i++) {
            goTo(x + 1, y);
        }
    }
}

void delay(float ms){
    usleep(ms*1000);
}

void sleep(float sec){
    delay(sec*1000);
}

inline bool valid(int x, int y) {
    return x >= 0 && x < 20 && y >= 0 && y < 20;
}

void color(std::string color){
	using namespace std;
	if(color == "black") cout << "\033[30m";
	if(color == "red") cout << "\033[31m";
	if(color == "green") cout << "\033[32m";
	if(color == "yellow") cout << "\033[33m";
	if(color == "blue") cout << "\033[34m";
	if(color == "purple") cout << "\033[35m";
	if(color == "aqua") cout << "\033[36m";
	if(color == "white") cout << "033[37m";
}
