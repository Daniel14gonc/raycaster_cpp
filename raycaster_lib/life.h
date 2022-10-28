#pragma once

class Life
{
    private:
        int* lifeData;
        int width;
        int height;
        void createMatrix();
    
    public:
        Life(int, int);
        void setPixel(int, int, int value = 1);
        bool isAlive(int, int, int identifier = 1);
        void kill(int, int, int value = 0);
        void clear(int, int);
};