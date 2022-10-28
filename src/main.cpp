#include <iostream>
#include <GLFW/glfw3.h>
#include "life.h"

using namespace std;

const int WIDTH = 100 * 4;
const int HEIGHT = 100 * 4;
const float COLOR[4] = {1.0, 0.0, 0.0, 0.0};

Life life(WIDTH, HEIGHT);

void pixel(int x, int y)
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(x * 4, y * 4, 4, 4);
    glClearColor(COLOR[0], COLOR[1], COLOR[2], COLOR[3]);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
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
    createStable(20, 20);
    life.setPixel(40, 30);
    life.setPixel(41, 30);
    life.setPixel(42, 30);
    penta(30, 30);
    updateLife();

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