#include <iostream>
#include <conio.h> // _kbhit() �� _getch()���Ӽ���������win
#include <vector>
#include <string>
#include <cstdlib> // �����
#include <ctime>   // ʱ��������ڻ�ȡϵͳʱ�������������
#include <chrono>  // ��������
#include <thread>
#include "Def.h"
#include<snakelib.cpp>


using namespace std;


int main() {
    srand(static_cast<unsigned>(time(0)));      //rand���������������

    SnakeSegment head;
    bomb bomb;
    vector<SnakeSegment> snake;
    SnakeSegment food;
    bool gameOver;

    Setup(head, snake, food, gameOver,bomb);

    while (!gameOver) {    //����Ϊ������Ϸ������
        Draw(head, snake, food,bomb);
        Input(gameOver);
        Logic(head, snake, food, gameOver,bomb);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // ˯�߷�����Դ������

    }

    cout << "Game Over!" << endl;
    return 0;
}




//������һ��xy�Ķ�ά�ռ䣬ͨ������cout��ʱ��ˢ��/���£�x��y����λ�á��߳���ʹ��vec����¼�����塣