


#include <iostream>
/**
 * @brief 求两数之和
 * @param a 第一个加数
 * @param b 第二个加数
 * @return int 两个数的和
 */
int Sum(int a, int b)
{
    int sum = a + b; // 两数和
    return sum;
}

class Point2D
{
private:
    /* data */
    int x;
    int y;

public:
    Point2D(/* args */);
    Point2D(int x, int y);
    ~Point2D();

public:
    void setX(const int &x);
    void setY(const int &x);

    int getX() const;
    int getY() const;
};

Point2D::Point2D(/* args */)
{
}

Point2D::~Point2D()
{
}
