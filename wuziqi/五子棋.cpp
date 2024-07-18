#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<deque>
#include<memory.h>
#include<algorithm>
using namespace std;
int n = 1;
char board[15][15];//咱们在主函数初始化board就可以了；
// 判断是否有四个连续相同的棋子
void judge_f(char piece, int& x1, int& y1) {
    // 定义方向数组，分别表示水平、垂直、主对角线和副对角线方向
    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            char originalPiece = board[x][y];
            board[x][y] = piece;

            for (int i = 0; i < 4; ++i) {
                int count = 1;
                int dx = directions[i][0];
                int dy = directions[i][1];

                for (int step = 1; step <= 4; ++step) {
                    int newX = x + step * dx;
                    int newY = y + step * dy;

                    // 检查边界条件
                    if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;

                    if (board[newX][newY] == piece) {
                        count++;
                    }
                    else {
                        break;
                    }
                }

                if (count >= 5) {
                    // 找到连续五个相同的棋子，记录坐标并退出循环
                    x1 = x + dx * 5;
                    y1 = y + dy * 5;
                    board[x][y] = originalPiece; // 恢复原始棋盘状态
                    return;
                }
            }

            board[x][y] = originalPiece;
        }
    }
}


// 判断是否有三个连续相同的棋子
void judge_th(char piece, int& x1, int& y1) {
    // 定义方向数组，分别表示水平、垂直、主对角线和副对角线方向
    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            char originalPiece = board[x][y];
            board[x][y] = piece;

            for (int i = 0; i < 4; ++i) {
                int count = 1;
                int dx = directions[i][0];
                int dy = directions[i][1];

                for (int step = 1; step <= 4; ++step) {
                    int newX = x + step * dx;
                    int newY = y + step * dy;

                    // 检查边界条件
                    if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;

                    if (board[newX][newY] == piece) {
                        count++;
                    }
                    else {
                        break;
                    }
                }

                if (count >= 4) {
                    // 找到连续四个相同的棋子，记录坐标并退出循环
                    x1 = x + dx * 4;
                    y1 = y + dy * 4;
                    board[x][y] = originalPiece; // 恢复原始棋盘状态
                    return;
                }
            }

            board[x][y] = originalPiece;
        }
    }
}
// 检查指定位置是否已经有棋子
bool isOccupied(int x, int y) {
    // 假设棋盘是一个二维数组 board，'+' 表示空位，'B' 表示电脑棋子，'W' 表示玩家棋子
    return (board[x][y] == 'B' || board[x][y] == 'W');
}




void judge_t(char piece, int& x1, int& y1) {
    // 检查是否有二个连续相同的棋子

    // 定义方向数组，分别表示水平、垂直、主对角线和副对角线方向

    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    for (int newx = 0; newx < 15; newx++)
    {
        for (int newy = 0; newy < 15; newy++)
        {
            int x, y, newX, newY;
            int a[2], b[2];
            x = newx;
            y = newy;
            char home = board[x][y];
            board[x][y] = piece;
            if (home == '+')
            {
                for (int i = 0; i < 4; ++i) {
                    int count = 1; // 从当前点开始计数
                    // 检查一个方向
                    for (int step = 1; step <= 4; ++step) {
                        newX = x + step * directions[i][0];
                        newY = y + step * directions[i][1];
                        // 检查边界条件
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // 如果找到相同的棋子，计数增加
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            a[0] = newX, a[1] = newY;
                            break;
                        }
                    }
                    // 检查相反方向
                    for (int step = 1; step <= 4; ++step) {
                        newX = x - step * directions[i][0];
                        newY = y - step * directions[i][1];
                        // 检查边界条件
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // 如果找到相同的棋子，计数增加
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            b[0] = newX, b[1] = newY;
                            break;
                        }
                    }
                    // 如果任意方向上找到五个连续相同的棋子，返回true
                    if (count >= 3)
                    {
                        if (board[a[0]][a[1]] == '+')
                        {
                            x1 = a[0] + 1, y1 = a[1] + 1;
                            //退出函数
                            //复原棋盘
                            board[x][y] = '+';
                            return;
                        }
                        if (board[b[0]][b[1]] == '+')
                        {
                            x1 = b[0] + 1, y1 = b[1] + 1;
                            board[x][y] = '+';
                            return;
                        }
                        else break;
                    }
                }
            }
            board[x][y] = home;
        }
    }

}
void judge_o(char piece, int& x1, int& y1) {
    // 检查是否有一个连续相同的棋子

    // 定义方向数组，分别表示水平、垂直、主对角线和副对角线方向

    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    for (int newx = 0; newx < 15; newx++)
    {
        for (int newy = 0; newy < 15; newy++)
        {
            int x, y, newX, newY;
            int a[3], b[3];
            x = newx;
            y = newy;
            char home = board[x][y];
            board[x][y] = piece;
            if (home == '+')
            {
                for (int i = 0; i < 4; ++i) {
                    int count = 1; // 从当前点开始计数
                    // 检查一个方向
                    for (int step = 1; step <= 4; ++step) {
                        newX = x + step * directions[i][0];
                        newY = y + step * directions[i][1];
                        // 检查边界条件
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // 如果找到相同的棋子，计数增加
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            a[0] = newX, a[1] = newY;
                            break;
                        }
                    }
                    // 检查相反方向
                    for (int step = 1; step <= 4; ++step) {
                        newX = x - step * directions[i][0];
                        newY = y - step * directions[i][1];
                        // 检查边界条件
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // 如果找到相同的棋子，计数增加
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            b[0] = newX, b[1] = newY;
                            break;
                        }
                    }
                    // 如果任意方向上找到五个连续相同的棋子，返回true
                    if (count >= 2)
                    {
                        if (board[a[0]][a[1]] == '+')
                        {
                            x1 = a[0] + 1, y1 = a[1] + 1;
                            //退出函数
                            //复原棋盘
                            board[x][y] = '+';
                            return;
                        }
                        if (board[b[0]][b[1]] == '+')
                        {
                            x1 = b[0] + 1, y1 = b[1] + 1;
                            board[x][y] = '+';
                            return;
                        }
                        else break;
                    }
                }
            }
            board[x][y] = home;
        }
    }

}
void evaluate(int a[])
{//先检查玩家是否已经四子连珠
    int x1 = -1, y1 = -1;
    judge_f('W', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//已经找到最优解了，不必再往下；
    }
    //如果没有发现玩家四子连珠，则寻找电脑自己是否四子连珠；
    judge_f('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//已经找到最优解了，不必再往下；
    }
    //如果没有发现自己和玩家三子连珠，则判断玩家是否三子连珠，有则阻止；
    judge_th('W', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//已经找到最优解了，不必再往下；
    }
    //如果没有发现玩家三子连珠，则寻找自己是否三子连珠；
    judge_th('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//已经找到最优解了，不必再往下；
    }
    //如果都没有发现的话，优先寻找自己是否二子连珠；
    judge_t('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//已经找到最优解了，不必再往下；
    }
    //如果没有则寻找自己能否二子连珠
    judge_o('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//已经找到最优解了，不必再往下；
    }

}
void print()
{
    cout << " 123456789012345" << endl;
    for (int i = 0; i < 15; i++)
    {

        cout << (i + 1) % 10;
        for (int j = 0; j < 15; j++)
        {

            cout << board[i][j];//该函数的作用就是把每次玩家或是电脑下棋后游戏未结束的代码打印出来；

        }
        cout << endl;//每行输入换行符；


    }
    cout << endl << endl;
}
bool judge(int x, int y, char piece) {
    // 检查是否有五个连续相同的棋子

    // 定义方向数组，分别表示水平、垂直、主对角线和副对角线方向

    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    board[x - 1][y - 1] = piece;
    for (int i = 0; i < 4; ++i) {
        int count = 1; // 从当前点开始计数
        // 检查一个方向
        for (int step = 1; step <= 4; ++step) {
            int newX = x + step * directions[i][0];
            int newY = y + step * directions[i][1];
            // 检查边界条件
            if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
            // 如果找到相同的棋子，计数增加
            if (board[newX][newY] == piece) {
                count++;
            }
            else {
                break;
            }
        }
        // 检查相反方向
        for (int step = 1; step <= 4; ++step) {
            int newX = x - step * directions[i][0];
            int newY = y - step * directions[i][1];
            // 检查边界条件
            if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
            // 如果找到相同的棋子，计数增加
            if (board[newX][newY] == piece) {
                count++;
            }
            else {
                break;
            }
        }
        // 如果任意方向上找到五个连续相同的棋子，返回true
        if (count >= 5) return true;
    }
    print();
    return false;
}
void computer();
void player()
{
    void computer();//声明函数

    while (1)
    {
        int x, y;//玩家输入坐标
        cin >> x >> y;
        n++;
        char piece = 'W';
        if (judge(x, y, piece))
        {
            cout << "玩家胜利\n";
            return;//游戏结束；
        }
        if (n == 15 * 15)
        {
            cout << "平局";
            return;
        }
        else
        {
            computer();
        }
    }
}
void computer()
{

    if (n == 1)
    {
        int x = 7, y = 7;
        char piece = 'B';
        if (judge(x, y, piece))
        {
        }//肯定有戏没结束，目的是打印棋盘；
        n++;//判断是否是第一个棋子，我们始终让电脑来下先手；
        player();
    }
    else
    {
        while (1)
        {

            int x, y;
            char piece = 'B';
            int a[3] = { 0 };
            evaluate(a);
            x = a[0], y = a[1];
            n++;
            if (judge(x, y, piece))//判断游戏是否结束；
            {
                cout << "电脑胜利\n";
                return;
            }
            if (n == 15 * 15)
            {
                cout << "平局";
                return;
            }
            else
                player();

        }
    }

}




void begin()
{
    computer();
    //开始游戏

}


int main()
{   //初始化棋盘；
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = '+';//便于观察，不用qt;
        }
    }
    begin();
    return 0;
}