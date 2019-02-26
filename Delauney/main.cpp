//
//  main.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/4/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

//  NOTE:   <GL/glew.h> MUST BE INCLUDED FIRST!!!
//          glew overrides some includes(ex gl.h) from glfw
//          and must be included first otherwise it throws an error.
#include <GL/glew.h>
#include "Renderer.hpp"
#include "Delaunay.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main(int argc, char * argv[])
{
        if (!glfwInit())
        {
            fprintf(stderr, "Error, failed to initialize glfwInit");
            //return FAILED;
        }
    
    Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    renderer.render();
    float vertices[] = {
        -0.5, -0.5, 0.0,
         0.5, -0.5, 0.0,
         0.0,  0.5, 0.0
    };
    unsigned int VBO;
//    glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    unsigned int vertexShader;
    //vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    
    
    
    
    
    
    
    
    
//    /* Initialize the library glfw */
//    if (!glfwInit())
//    {
//        fprintf(stderr, "Error, failed to initialize glfwInit");
//        //return FAILED;
//    }
//    
//    const char * sht="\
//#    ";
//    Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
//    renderer.render();
//
//    const char* name = "../../../ProjectDelone/Shaders/VertexShader.vs";
//    FILE* file = fopen(name, "r");
//    if(!file)
//    {
//        fprintf(stderr, "Error, cannot open file %s\n", name);
//        fclose(file);
////        return FAILED;
//    }
//    char tempArr[512];
//    Delaunay delone;
//    delone.Triangulate("../../../ProjectDelone/SamplePointFiles/RANDOM.DAT");
    return 0;
}
