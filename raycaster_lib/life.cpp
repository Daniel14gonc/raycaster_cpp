#include "life.h"
#include <iostream>

using namespace std;

Life::Life(int width, int height)
{
    this->width = width;
    this->height = height;
    createMatrix();
}

void Life::createMatrix()
{
    lifeData = new int[width * height];
    for (int x = 0; x < (width * height); x++)
    {
        lifeData[x] = 0;
    }
}

void Life::setPixel(int x, int y, int value)
{
    int j = y * width;
    int i = j + x;
    lifeData[i] = value;
}

bool Life::isAlive(int x, int y, int identifier)
{
    int j = y * width;
    int i = j + x;
    return lifeData[i] == identifier;
}


void Life::kill(int x, int y, int value)
{
    int j = y * width;
    int i = j + x;
    lifeData[i] = value;
}

void Life::clear(int x, int y)
{
    int j = y * width;
    int i = j + x;
    lifeData[i] = 0;
}

