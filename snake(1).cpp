#include <iostream>
#include <conio.h> // _kbhit() 和 _getch()，从键盘输入至win
#include <vector>
#include <string>
#include <cstdlib> // 随机数
#include <ctime>   // 时间戳，用于获取系统时间生成随机种子
#include <chrono>  // 生成种子
#include <thread>
#include "Def.h"
#include<snakelib.cpp>


using namespace std;


int main() {
    srand(static_cast<unsigned>(time(0)));      //rand的随机数种子生成

    SnakeSegment head;
    bomb bomb;
    vector<SnakeSegment> snake;
    SnakeSegment food;
    bool gameOver;

    Setup(head, snake, food, gameOver,bomb);

    while (!gameOver) {    //布尔为正则游戏不结束
        Draw(head, snake, food,bomb);
        Input(gameOver);
        Logic(head, snake, food, gameOver,bomb);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 睡眠方法来源于网络

    }

    cout << "Game Over!" << endl;
    return 0;
}




//创造了一个xy的二维空间，通过反复cout来时间刷新/更新，x，y定义位置。蛇长度使用vec来记录并定义。