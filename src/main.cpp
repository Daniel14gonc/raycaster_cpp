#include <iostream>
#include <GLFW/glfw3.h>
#include "life.h"
#include <cmath>

using namespace std;

const int WIDTH = 100 * 4;
const int HEIGHT = 100 * 4;
const float COLOR[4] = {1.0, 0.0, 0.0, 0.0};

Life life(WIDTH, HEIGHT);

bool isOutOfBounds(int x, int y)
{
    if (x < 0 || x >= WIDTH)
    {
        return true;
    }
    if (y < 0 || y >= HEIGHT)
    {
        return true;
    }

    return false;
}

void pixel(int x, int y)
{
    if (!isOutOfBounds(x, y))
    {
        glEnable(GL_SCISSOR_TEST);
        glScissor(x * 4, y * 4, 4, 4);
        glClearColor(COLOR[0], COLOR[1], COLOR[2], COLOR[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        glDisable(GL_SCISSOR_TEST);
    }
}

void hydro(int x, int y)
{
    life.setPixel(x, y);
    life.setPixel(x + 1, y);
    life.setPixel(x - 1, y);
    life.setPixel(x, y - 3);
    life.setPixel(x + 2, y - 2);
    life.setPixel(x + 3, y);
    life.setPixel(x + 2, y + 2);
    life.setPixel(x, y + 3);
    life.setPixel(x - 2, y + 2);
    life.setPixel(x - 2, y);
    life.setPixel(x - 2, y - 2);
}

void drawRightTopPulsar(int x, int y)
{
    life.setPixel(x, y);
    life.setPixel(x, y - 1);
    life.setPixel(x, y - 2);
    life.setPixel(x + 1, y - 4);
    life.setPixel(x + 2, y - 4);
    life.setPixel(x + 3, y - 4);
    life.setPixel(x + 1, y + 1);
    life.setPixel(x + 2, y + 1);
    life.setPixel(x + 3, y + 1);
    life.setPixel(x + 5, y);
    life.setPixel(x + 5, y - 1);
    life.setPixel(x + 5, y - 2);
}

void drawLeftTopPulsar(int x, int y)
{
    life.setPixel(x, y);
    life.setPixel(x, y - 1);
    life.setPixel(x, y - 2);
    life.setPixel(x - 1, y - 4);
    life.setPixel(x - 2, y - 4);
    life.setPixel(x - 3, y - 4);
    life.setPixel(x - 1, y + 1);
    life.setPixel(x - 2, y + 1);
    life.setPixel(x - 3, y + 1);
    life.setPixel(x - 5, y);
    life.setPixel(x - 5, y - 1);
    life.setPixel(x - 5, y - 2);
}

void drawRightBottomPulsar(int x, int y)
{
    life.setPixel(x, y - 1);
    life.setPixel(x, y - 2);
    life.setPixel(x, y - 3);
    life.setPixel(x + 1, y - 4);
    life.setPixel(x + 2, y - 4);
    life.setPixel(x + 3, y - 4);
    life.setPixel(x + 1, y + 1);
    life.setPixel(x + 2, y + 1);
    life.setPixel(x + 3, y + 1);
    life.setPixel(x + 5, y);
    life.setPixel(x + 5, y - 1);
    life.setPixel(x + 5, y - 2);
}

void drawLeftBottomPulsar(int x, int y)
{
    life.setPixel(x, y - 1);
    life.setPixel(x, y - 2);
    life.setPixel(x, y - 3);
    life.setPixel(x - 1, y - 4);
    life.setPixel(x - 2, y - 4);
    life.setPixel(x - 3, y - 4);
    life.setPixel(x - 1, y + 1);
    life.setPixel(x - 2, y + 1);
    life.setPixel(x - 3, y + 1);
    life.setPixel(x - 5, y);
    life.setPixel(x - 5, y - 1);
    life.setPixel(x - 5, y - 2);
}



void leftTopPulsar(int x, int y)
{
    drawLeftTopPulsar(x - 1, y - 2);
}

void rightTopPulsar(int x, int y)
{
    drawRightTopPulsar(x + 1, y - 2);
}

void leftBottomPulsar(int x, int y)
{
    drawLeftBottomPulsar(x - 1, y + 5);
}

void rightBottomPulsar(int x, int y)
{
    drawRightBottomPulsar(x + 1, y + 5);
}



void pulsar(int x, int y)
{
    leftTopPulsar(x, y);
    leftBottomPulsar(x, y);
    rightTopPulsar(x, y);
    rightBottomPulsar(x, y);
}

void glider(int x, int y)
{
    life.setPixel(x, y);
    life.setPixel(x, y + 1);
    life.setPixel(x, y + 2);
    life.setPixel(x - 1, y + 2);
    life.setPixel(x - 2, y + 1);
}

void penta(int x, int y)
{
    life.setPixel(x, y);
    life.setPixel(x , y + 1);
    life.setPixel(x - 1, y + 1);
    life.setPixel(x + 1, y + 1);

    life.setPixel(x - 1 , y + 4);
    life.setPixel(x, y + 4);
    life.setPixel(x + 1 , y + 4);

    life.setPixel(x - 1 , y + 6);
    life.setPixel(x - 1 , y + 7);
    life.setPixel(x + 1 , y + 6);
    life.setPixel(x + 1 , y + 7);

    life.setPixel(x - 1 , y + 9);
    life.setPixel(x, y + 9);
    life.setPixel(x + 1 , y + 9);

    life.setPixel(x - 1 , y + 12);
    life.setPixel(x, y + 12);
    life.setPixel(x + 1 , y + 12);
    life.setPixel(x, y + 13);
}

void createStable(int x, int y)
{
    life.setPixel(x, y);
    life.setPixel(x + 1, y);
    life.setPixel(x, y + 1);
    life.setPixel(x + 1, y + 1);
}

bool isNeighbour(int neighbourX, int neighbourY, int identifier)
{
    if (!isOutOfBounds(neighbourX, neighbourY))
    {
        if (life.isAlive(neighbourX, neighbourY, identifier))
        {
            return true;
        }
    }
    
    return false;
}

void initialConfiguration()
{
    hydro(20, 20);
    hydro(20, 80);
    hydro(80, 20);
    hydro(80, 80);
    pulsar(50, 50);
}

int getNeighbourCount(int x, int y, int identifier)
{
    int count = 0;

    int neighbours[16] = {
        x, y - 1,
        x + 1, y - 1,
        x + 1, y,
        x + 1, y + 1,
        x, y + 1,
        x - 1, y + 1,
        x - 1, y,
        x - 1, y - 1
    };

    for (int x = 0; x < 16; x += 2)
    {
        int neighbourX = neighbours[x];
        int neighbourY = neighbours[x + 1];
        if (isNeighbour(neighbourX, neighbourY, identifier))
        {
            count++;
        }
    }
    
    return count;
}

void kill(int x, int y)
{
    int neighbourCount = getNeighbourCount(x, y, 1);
    neighbourCount += getNeighbourCount(x, y, 2);
    if (life.isAlive(x, y))
    {
        if (neighbourCount < 2)
        {
            life.kill(x, y, 2);
        }
        if (neighbourCount > 3)
        {
            life.kill(x, y, 2);
        }
    }
}

void create(int x, int y)
{
    int neighbourCount = getNeighbourCount(x, y, 2);
    neighbourCount += getNeighbourCount(x, y, 1);
    if (life.isAlive(x, y, 0))
    {
        if (neighbourCount == 3)
        {
            life.setPixel(x, y, 3);
            pixel(x, y);
        }
    }
    if (life.isAlive(x, y))
    {
        pixel(x, y);
    }
}

void clear()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (life.isAlive(x, y, 2))
            {
                life.kill(x, y);
            }
            if (life.isAlive(x, y, 3))
            {
                life.setPixel(x, y);
            }
        }
    }
}


void updateLife()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (life.isAlive(x, y) == 1)
            {
                life.setPixel(x, y);
            }
            kill(x, y);
        }
    }
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            create(x, y);
        }
    }
    clear();
}

int main(void)
{
    GLFWwindow* window;
    /*createStable(20, 20);
    life.setPixel(40, 30);
    life.setPixl(41, 30);
    life.setPixel(42, 30);
    penta(30, 30);
    hydro(70, 70);*/
    initialConfiguration();
    // updateLife();

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        updateLife();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}