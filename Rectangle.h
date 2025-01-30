//
// Created by berke on 1/30/2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle {
    int length;
    int breadth;
public:
    Rectangle(int length, int breadth);
    int getLength() const;
    void setLength(int length);
    int getBreadth() const;
    void setBreadth(int breadth);
    int area() const;
    int perimeter() const;
};

#endif //RECTANGLE_H
