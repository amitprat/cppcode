#pragma once
#include "../Header.h"

/*
https://www.careercup.com/question?id=5197964926517248
You need to develop the game Snake. What data structures will you use? Code your solution.

Two parts:
1. 2D plate: 2D array of short, 0 for free, 1 for items to eat, 2 for blocks (including snake body);
2. Snake body: Queue of int pair indicating position like (x, y), every move enqueue new head position and dequeue tail position. Enqueue two nodes if a item eaten. Enqueue and dequeue operation includes set flag in its pixel.

For every move, only constant time (O(1)) needed.
*/
class SnakeGame
{
    class Game
    {
    public:
        enum class Dir {
            North,
            Right,
            Down,
            Left
        };
        struct Snake
        {
            Point head, tail;
            deque<Point> queue;
            Dir curDir;

            void init(Point start) {
                head = tail = start;
                queue.push_back(start);
                curDir = Dir::North;
            }
        };
        vector<vector<int>> board;
        Snake snake;

        Game(int n, Point startPos) {
            board.resize(n, vector<int>(n, 0));
            snake.init(startPos);
            board[startPos.x][startPos.y] = 3;
        }

        void init(int blocks, int food) {
            int n = board.size();
            srand(time(nullptr));
            while (blocks--) {
                int v = rand() % (n * n);
                int r = v / n;
                int c = v % n;
                board[r][c] = 1;
            }

            while (food--) {
                int v = rand() % (n * n);
                int r = v / n;
                int c = v % n;
                board[r][c] = 2;
            }
        }

        void move() {
            switch (snake.curDir)
            {
            case Dir::North:
                snake.head.y += 1;
                board[snake.head.x][snake.head.y] = 3;
                board[snake.tail.x][snake.tail.y] = 0;
                snake.tail.y += 1;
                snake.queue.push_front(snake.head);
                snake.queue.pop_back();
                if (board[snake.head.x][snake.head.y] == 2) {
                    snake.tail.y -= 1;
                    board[snake.tail.x][snake.tail.y] = 3;
                    snake.queue.push_back(snake.tail);
                }
                break;

            case Dir::Down:
                snake.head.y -= 1;
                snake.tail.y -= 1;
                board[snake.head.x][snake.head.y] = 3;
                board[snake.tail.x][snake.tail.y] = 0;
                snake.queue.push_front(snake.head);
                snake.queue.pop_back();
                if (board[snake.head.x][snake.head.y] == 2) {
                    snake.tail.y += 1;
                    board[snake.tail.x][snake.tail.y] = 1;
                    snake.queue.push_back(snake.tail);
                }
                break;

            case Dir::Right:
                snake.head.x += 1;
                snake.tail.x += 1;
                board[snake.head.x][snake.head.y] = 3;
                board[snake.tail.x][snake.tail.y] = 0;
                snake.queue.push_front(snake.head);
                snake.queue.pop_back();
                if (board[snake.head.x][snake.head.y] == 2) {
                    snake.tail.x -= 1;
                    board[snake.tail.x][snake.tail.y] = 3;
                    snake.queue.push_back(snake.tail);
                }
                break;

            case Dir::Left:
                snake.head.x -= 1;
                snake.tail.x -= 1;
                board[snake.head.x][snake.head.y] = 3;
                board[snake.tail.x][snake.tail.y] = 0;
                snake.queue.push_front(snake.head);
                snake.queue.pop_back();
                if (board[snake.head.x][snake.head.y] == 2) {
                    snake.tail.x += 1;
                    board[snake.tail.x][snake.tail.y] = 3;
                    snake.queue.push_back(snake.tail);
                }
                break;
            }
        }

        void left() {
            snake.curDir = (Dir)(((int)snake.curDir - 1 + 4) % 4);
        }

        void right() {
            snake.curDir = (Dir)(((int)snake.curDir + 1) % 4);
        }

        void print() {
            cout << "---------------------------------------\n";
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    cout << board[i][j] << "\t";
                }
                cout << endl;
            }
            cout << "---------------------------------------\n\n";
        }
    };

public:
    static void test() {
        Game game(5, { 0,0 });
        game.init(4, 4);

        game.print();

        game.move();
        game.right();
        game.move();
        game.move();
        game.move();

        game.print();
    }
};