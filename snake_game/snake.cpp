#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

bool game_over;
// map size
const int width = 20;
const int height = 20;
// head and fruit
int x_head, y_head, fruit_x, fruit_y, score;
// direction
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;
// tail
int tail_x[100], tail_y[100];
int tail_length;

void set_up()
{
    game_over = false;
    dir = STOP;
    x_head = width / 2;
    y_head = height / 2;
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    score = 0;
}

void draw()
{
    system("cls");
    //printing top wall
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // game map
    for (int i = 0; i < height; i++) {
        for(int j = 0; j< width; j++) {
            if(j == 0)
                cout << "#";

            // print snake head
            if( i == y_head && j == x_head)
                cout << "O";
            // print the fruit
            else if(i == fruit_y && j == fruit_x)
                cout << "F";
            else {
                // tail draw logic
                bool printed_tail_segment = false;
                for(int k = 0; k < tail_length; k++) {
                    if(tail_x[k] == j && tail_y[k] == i) {
                        cout << "o";
                        printed_tail_segment = true;
                    }
                }
                if(!printed_tail_segment)
                        cout << " ";
            }

            if(j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    // printing bottom wall
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << endl;
    cout << "Score: " << score << endl;
}

void input()
{
    if(kbhit()) {
        switch(getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                game_over = true;
                break;
        }
    }
}

void logic()
{
    // first tail element should follow the head
    tail_x[0] = x_head;
    tail_y[0] = y_head;

    for(int i = tail_length; i > 0; i--) {
        tail_x[i] = tail_x[i - 1];
        tail_y[i] = tail_y[i - 1];
    }

    switch(dir) {
        case LEFT:
            x_head--;
            break;
        case RIGHT:
            x_head++;
            break;
        case UP:
            y_head--;
            break;
        case DOWN:
            y_head++;
            break;
        default:
            break;
    }

    if(x_head > width || x_head < 0 || y_head > height || y_head < 0)
        game_over = true;

    /* if we eat the fruit, the score and tail length get increased,
        and another fruit gets placed randomly on the map*/
    if(x_head == fruit_x && y_head == fruit_y) {
        tail_length++;
        score += 10;
        fruit_x = rand() % width;
        fruit_y = rand() % height;
    }
}

int main()
{
    srand((unsigned) time(0));
    set_up();

    while(!game_over) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    return 0;
}
