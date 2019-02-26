//
//  Renderer.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <stdio.h>
#include "Renderer.hpp"


Renderer::Renderer(const unsigned short windowWidth, const unsigned short windowHeight)
: vertexShaderFileName("Shaders/VertexShader.vs")
, fragmentShaderFileName("Shaders/FragmentShader.fs")
{
    window.createWindow(windowWidth, windowHeight);
}


Renderer::~Renderer()
{
}


void Renderer::render()
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());
        
        /* Poll for and process events */
        glfwPollEvents();
    }
}


bool Renderer::loadShader(const char* shadeFileName, char* shaderSourceCode)
{
    FILE* file = fopen(vertexShaderFileName, "r");
    if(!file)
    {
        fprintf(stderr, "Error, cannot open file %s\n", vertexShaderFileName);
        fclose(file);
        return false;
    }
    
    int i = 0;
    char tempArr[SOURCE_SIZE/2];
    while(fgets(tempArr, SOURCE_SIZE, file))
    {
        int j = 0;
        while(tempArr[j])
        {
            vertexSourceCode[i] = tempArr[j];
        }
    }
    
    fclose(file);
    return true;
}


unsigned getShaderFileSize(const char* shaderFileName)
{
    FILE* file = fopen(shaderFileName, "r");
    if(!file)
    {
        fprintf(stderr, "Error, cannot open file %s\n", shaderFileName);
        fclose(file);
        return false;
    }
    return 0;
}