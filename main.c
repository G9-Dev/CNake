#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "rlutil.h"



//functions
void showLogo();
void checkDie();
void drawMap();
void drawSnake();

//variables
char key='-';

int quit=1;
int direction=3;
int x=40;
int y=12;
int coinx;
int coiny;
int score=0;



int main()
{
    srand(time(0));
    randomCoin(1);
    SetConsoleTitle("CNake");
    hidecursor();
    system("MODE 80,26");
    showLogo();
    msleep(1200);

    cls();
    drawMap();
    drawSnake();
    printf("Press any key to start ...");
    while(!kbhit())
    {

    }

    while(quit)
    {
        cls();
        drawMap();
        if (kbhit()) //keyboard controls
        {

            key=getch();
            if (key=='x' || key=='X'){quit = 0;}
            if (key==72){direction=1;} //up
            if (key==75){direction=2;} //left
            if (key==77){direction=3;} //right
            if (key==80){direction=4;} //down
        }



        switch (direction) //gets keyboard input
        {
            case 1: //up
                y--;
                break;;
            case 2: //left
                x--;
                break;;
            case 3: //right
                x++;
                break;;
            case 4: //down
                y++;
                break;;
            default :
                break;;
        }

        drawSnake();
        checkDie();
        msleep(70);
    }
    return 0;
}


void drawSnake() //draws the snake
{
    setColor(2);
    locate(x,y);
    printf("0");
    setColor(15);
}


int randomCoin(int ins)
{
    if (!ins)
    {
        locate(coinx,coiny);
        setColor(1);
        printf(".");
        score=score+100;
    }
    coinx=(rand()%78)+1;
    coiny=(rand()%23)+1;

    return score;
}


void showLogo() //draws my logo as an ASCII art
{
    setColor(10);
    printf("\n\n\n                                                 .*********,                    \n");
    printf("               /*********************      **********************               \n");
    printf("            *************************    ***************************            \n");
    printf("         ,***********         *,****   ,********            **********/         \n");
    printf("       /*********                      *******                 *********        \n");
    printf("      ********                        *******                    ,*******       \n");
    printf("     *******                          /******,                     ********     \n");
    printf("    *******                            *******                      *******     \n");
    printf("    *******                            *******                      *******     \n");
    printf("   /******           ************************************            *******    \n");
    printf("    *******           ********************************//             ******,    \n");
    printf("    ********                   ******(                             ,*******     \n");
    printf("     .********                 ******(                             ********     \n");
    printf("       *********               ******                            *********,     \n");
    printf("         **********          ,,*******                   ,**************        \n");
    printf("           ,*************************       ,*************************          \n");
    printf("               ********************         *********************               \n");
    printf("                  **************              (*.*//////.                       \n\n");
    printf("                        P  R  E  S  E  N  T  S  .  .  .                         \n");
    setColor(15);
}



void drawMap() //draws the map
{
    int i=0;
    setColor(1);
    locate(0,0);
    printf("################################################################################\n");
    for (i=1 ; i<=23 ; i++) { printf("#..............................................................................#\n") ;}
    printf("################################################################################");

    locate(0,25);
    setColor(15);
    printf("Score : %d",score);

    setColor(14);
    locate(coinx,coiny);
    printf("+");

    setColor(15);
}


void checkDie()
{
    if (x<1 || x>80 || y<1 || y>25)
    {
        MessageBox(0,"You Died !","Ooops...",0);
        quit=0;
    }
    if (x==coinx && y==coiny)
    {
        score=randomCoin(0);
    }
}
