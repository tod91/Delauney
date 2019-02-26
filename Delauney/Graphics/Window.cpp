//
//  Window.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <stdio.h>
#include "Window.hpp"

Window::Window()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    
    // Used only for MacOS. Make this usable only when u are compiling for Apples OS (hint: Use guards)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}


Window::~Window()
{
    glfwTerminate();
}


bool Window::createWindow(const unsigned short width, const unsigned short heigh)
{
    window = glfwCreateWindow(width, heigh, "Delaunay Triangulation", NULL, NULL);
    if(window == NULL)
    {
        fprintf(stderr, "Error, cannot create window \"Delaunay Triangulation\"\n");
        return false;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    return true;
}