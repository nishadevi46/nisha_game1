#include "bits/stdc++.h"
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
enum edirection
{
    stop = 0,
    l,
    r,
    up,
    down
};
edirection dir;
int bodyx[100], bodyy[100];
int Ssize;
void setup()
{
    gameover = false;
    dir = stop;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < width; i++)
    {
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "*";
            else if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruity && j == fruitx)
            {
                cout << "@";
            }
            else if (j == width - 1)
                cout << "*";

            else
            {
                bool display = false;
                for (int k = 0; k < Ssize; k++)
                {

                    if (bodyx[k] == j && bodyy[k] == i)
                    {
                        cout << "O";
                        display = true;
                    }
                }
                if (!display)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "Score:" << score << endl;
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = l;
            break;
        case 'd':
            dir = r;
            break;
        case 'w':
            dir = up;
            break;
        case 's':
            dir = down;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}
void logic()
{
    // speed control code
    // if (dir == l || dir == r)
    // {
    //     Sleep(5);
    // }

    // Sleep(100);

    // if (dir == up || dir == down)
    // {
    //     Sleep(60);
    // }
    // reesizing body
    bodyx[0]=x;
    bodyy[0]=y;
    int x2 = bodyx[0];
    int y2 = bodyy[0];

    int prevx, prevy;
    for (int i = 1; i < Ssize; i++)
    {
        prevx = bodyx[i];
        prevy = bodyy[i];
        bodyx[i] = x2;
        bodyy[i] = y2;
        x2 = prevx;
        y2 = prevy;
    }

    switch (dir)
    {
    case l:
        x--;
        break;
    case r:
        x++;
        break;

    case up:
        y--;
        break;
    case down:
        y++;
        break;

    default:
        break;
    }
    // if (x < 0 || x > width || y < 0 || y > height)
    // {
    //     gameover = true;
    // }
    if(x>=width )x=0;
    else if(x<0)
    x=width-1;
    if(y>=height )y=0;
    else if(y<0)
    y=height-1;
    for(int i=0;i<Ssize;i++){
     if(bodyx[i] == x && bodyy[i] == y)
     gameover=true;
    }
    if (x == fruitx && y == fruity)
    {
        score += 1;
        fruitx = rand() % width;
        fruity = rand() % height;
        Ssize++;
    }
}
int main()
{
    setup();
    while (!gameover)
    {
        draw();
         Sleep(50);
        input();
        logic();
    }
    return 0;
}