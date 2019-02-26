//
//  Renderer.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "Window.hpp"

#define SOURCE_SIZE 1024

class Renderer
{
public:
    Renderer(const unsigned short windowWidth, const unsigned short windowHeight);
    ~Renderer();
    
    void render();
private:
    
    bool loadShader(const char* shaderFileName, char* shaderSourceCode);
    unsigned getShaderFileSize(const char* shaderFileName);
    
    Window window;
    
    char* vertexSourceCode;
    char* fragmentSourceCode;
    
    const char* vertexShaderFileName;
    const char* fragmentShaderFileName;
};
#endif /* Renderer_hpp */
