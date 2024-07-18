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
char board[15][15];//��������������ʼ��board�Ϳ����ˣ�
// �ж��Ƿ����ĸ�������ͬ������
void judge_f(char piece, int& x1, int& y1) {
    // ���巽�����飬�ֱ��ʾˮƽ����ֱ�����Խ��ߺ͸��Խ��߷���
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

                    // ���߽�����
                    if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;

                    if (board[newX][newY] == piece) {
                        count++;
                    }
                    else {
                        break;
                    }
                }

                if (count >= 5) {
                    // �ҵ����������ͬ�����ӣ���¼���겢�˳�ѭ��
                    x1 = x + dx * 5;
                    y1 = y + dy * 5;
                    board[x][y] = originalPiece; // �ָ�ԭʼ����״̬
                    return;
                }
            }

            board[x][y] = originalPiece;
        }
    }
}


// �ж��Ƿ�������������ͬ������
void judge_th(char piece, int& x1, int& y1) {
    // ���巽�����飬�ֱ��ʾˮƽ����ֱ�����Խ��ߺ͸��Խ��߷���
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

                    // ���߽�����
                    if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;

                    if (board[newX][newY] == piece) {
                        count++;
                    }
                    else {
                        break;
                    }
                }

                if (count >= 4) {
                    // �ҵ������ĸ���ͬ�����ӣ���¼���겢�˳�ѭ��
                    x1 = x + dx * 4;
                    y1 = y + dy * 4;
                    board[x][y] = originalPiece; // �ָ�ԭʼ����״̬
                    return;
                }
            }

            board[x][y] = originalPiece;
        }
    }
}
// ���ָ��λ���Ƿ��Ѿ�������
bool isOccupied(int x, int y) {
    // ����������һ����ά���� board��'+' ��ʾ��λ��'B' ��ʾ�������ӣ�'W' ��ʾ�������
    return (board[x][y] == 'B' || board[x][y] == 'W');
}




void judge_t(char piece, int& x1, int& y1) {
    // ����Ƿ��ж���������ͬ������

    // ���巽�����飬�ֱ��ʾˮƽ����ֱ�����Խ��ߺ͸��Խ��߷���

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
                    int count = 1; // �ӵ�ǰ�㿪ʼ����
                    // ���һ������
                    for (int step = 1; step <= 4; ++step) {
                        newX = x + step * directions[i][0];
                        newY = y + step * directions[i][1];
                        // ���߽�����
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // ����ҵ���ͬ�����ӣ���������
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            a[0] = newX, a[1] = newY;
                            break;
                        }
                    }
                    // ����෴����
                    for (int step = 1; step <= 4; ++step) {
                        newX = x - step * directions[i][0];
                        newY = y - step * directions[i][1];
                        // ���߽�����
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // ����ҵ���ͬ�����ӣ���������
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            b[0] = newX, b[1] = newY;
                            break;
                        }
                    }
                    // ������ⷽ�����ҵ����������ͬ�����ӣ�����true
                    if (count >= 3)
                    {
                        if (board[a[0]][a[1]] == '+')
                        {
                            x1 = a[0] + 1, y1 = a[1] + 1;
                            //�˳�����
                            //��ԭ����
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
    // ����Ƿ���һ��������ͬ������

    // ���巽�����飬�ֱ��ʾˮƽ����ֱ�����Խ��ߺ͸��Խ��߷���

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
                    int count = 1; // �ӵ�ǰ�㿪ʼ����
                    // ���һ������
                    for (int step = 1; step <= 4; ++step) {
                        newX = x + step * directions[i][0];
                        newY = y + step * directions[i][1];
                        // ���߽�����
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // ����ҵ���ͬ�����ӣ���������
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            a[0] = newX, a[1] = newY;
                            break;
                        }
                    }
                    // ����෴����
                    for (int step = 1; step <= 4; ++step) {
                        newX = x - step * directions[i][0];
                        newY = y - step * directions[i][1];
                        // ���߽�����
                        if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
                        // ����ҵ���ͬ�����ӣ���������
                        if (board[newX][newY] == piece) {
                            count++;
                        }
                        else {
                            b[0] = newX, b[1] = newY;
                            break;
                        }
                    }
                    // ������ⷽ�����ҵ����������ͬ�����ӣ�����true
                    if (count >= 2)
                    {
                        if (board[a[0]][a[1]] == '+')
                        {
                            x1 = a[0] + 1, y1 = a[1] + 1;
                            //�˳�����
                            //��ԭ����
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
{//�ȼ������Ƿ��Ѿ���������
    int x1 = -1, y1 = -1;
    judge_f('W', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//�Ѿ��ҵ����Ž��ˣ����������£�
    }
    //���û�з�������������飬��Ѱ�ҵ����Լ��Ƿ��������飻
    judge_f('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//�Ѿ��ҵ����Ž��ˣ����������£�
    }
    //���û�з����Լ�������������飬���ж�����Ƿ��������飬������ֹ��
    judge_th('W', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//�Ѿ��ҵ����Ž��ˣ����������£�
    }
    //���û�з�������������飬��Ѱ���Լ��Ƿ��������飻
    judge_th('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//�Ѿ��ҵ����Ž��ˣ����������£�
    }
    //�����û�з��ֵĻ�������Ѱ���Լ��Ƿ�������飻
    judge_t('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//�Ѿ��ҵ����Ž��ˣ����������£�
    }
    //���û����Ѱ���Լ��ܷ��������
    judge_o('B', x1, y1);
    if (x1 != -1 && y1 != -1)
    {
        a[0] = x1, a[1] = y1;
        return;//�Ѿ��ҵ����Ž��ˣ����������£�
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

            cout << board[i][j];//�ú��������þ��ǰ�ÿ����һ��ǵ����������Ϸδ�����Ĵ����ӡ������

        }
        cout << endl;//ÿ�����뻻�з���


    }
    cout << endl << endl;
}
bool judge(int x, int y, char piece) {
    // ����Ƿ������������ͬ������

    // ���巽�����飬�ֱ��ʾˮƽ����ֱ�����Խ��ߺ͸��Խ��߷���

    const int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    board[x - 1][y - 1] = piece;
    for (int i = 0; i < 4; ++i) {
        int count = 1; // �ӵ�ǰ�㿪ʼ����
        // ���һ������
        for (int step = 1; step <= 4; ++step) {
            int newX = x + step * directions[i][0];
            int newY = y + step * directions[i][1];
            // ���߽�����
            if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
            // ����ҵ���ͬ�����ӣ���������
            if (board[newX][newY] == piece) {
                count++;
            }
            else {
                break;
            }
        }
        // ����෴����
        for (int step = 1; step <= 4; ++step) {
            int newX = x - step * directions[i][0];
            int newY = y - step * directions[i][1];
            // ���߽�����
            if (newX < 0 || newX >= 15 || newY < 0 || newY >= 15) break;
            // ����ҵ���ͬ�����ӣ���������
            if (board[newX][newY] == piece) {
                count++;
            }
            else {
                break;
            }
        }
        // ������ⷽ�����ҵ����������ͬ�����ӣ�����true
        if (count >= 5) return true;
    }
    print();
    return false;
}
void computer();
void player()
{
    void computer();//��������

    while (1)
    {
        int x, y;//�����������
        cin >> x >> y;
        n++;
        char piece = 'W';
        if (judge(x, y, piece))
        {
            cout << "���ʤ��\n";
            return;//��Ϸ������
        }
        if (n == 15 * 15)
        {
            cout << "ƽ��";
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
        }//�϶���Ϸû������Ŀ���Ǵ�ӡ���̣�
        n++;//�ж��Ƿ��ǵ�һ�����ӣ�����ʼ���õ����������֣�
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
            if (judge(x, y, piece))//�ж���Ϸ�Ƿ������
            {
                cout << "����ʤ��\n";
                return;
            }
            if (n == 15 * 15)
            {
                cout << "ƽ��";
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
    //��ʼ��Ϸ

}


int main()
{   //��ʼ�����̣�
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = '+';//���ڹ۲죬����qt;
        }
    }
    begin();
    return 0;
}