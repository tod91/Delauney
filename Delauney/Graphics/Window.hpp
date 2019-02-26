//
//  Window.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <GLFW/glfw3.h>

//=============================================================================
/// @brief  A window class for displaying the graphic renderings on the screen.
///         The windowing library we will be using is glfw.
///
//=============================================================================
class Window
{
public:
    
    //=============================================================================
    /// @fn default ctor
    ///
    /// @NOTE glfwInit() must be successfully called before any of the functions in
    ///       the Window class. This includes the ctor.
    //=============================================================================
    Window();
    ~Window();
    
    bool createWindow(const unsigned short width, const unsigned short heigh);
    GLFWwindow* getWindow(){return window;}
    
private:
    GLFWwindow* window;
};
#endif /* Window_hpp */
