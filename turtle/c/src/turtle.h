//by Raneczech

#include <iostream>
#include <termios.h>
#include <unistd.h>

#ifndef TURTLE_H
#define TURTLE_H

extern int plocha[20][20];

class turtle{
    public:
    turtle();
    int pos[20][20] = {0};
    int smer = 0; // 0 = nahoru, 1 = doprava, 2 = dolu, 3 = doleva
    int x = 10;
    int y = 10;
    int lx = 10;
    int ly = 10;
    int pen = 0; // 1 = pero dolu, 0 = pero nahoru
    void goTo(int newX, int newY);
    void penUp();
    void penDown();
    void forward(int distance);
    void backward(int distance);
    void right(int angle_quarters);
    void left(int angle_quarters);
};

void color(std::string color);
void grafika();
char getch();
inline bool valid(int x, int y);
void delay(float ms);
void sleep(float sec);
#endif // TURTLE_H
