//
// Created by berke on 1/30/2025.
//
#include "Rectangle.h"

Rectangle::Rectangle(int length, int breadth) {
    this->length = length;
    this->breadth = breadth;
}

int Rectangle::getLength() const {
    return this->length;
}

void Rectangle::setLength(const int length) {
    this->length = length;
}

int Rectangle::getBreadth() const {
    return this->breadth;
}

void Rectangle::setBreadth(const int breadth) {
    this->breadth = breadth;
}

int Rectangle::area() const {
    return length * breadth;
}