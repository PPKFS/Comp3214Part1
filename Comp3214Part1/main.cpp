// Comp3214Part1.cpp : Defines the entry point for the console application.
//
#include <GL/glew.h>
#include <GL/glfw3.h>
#include "Window.h"
#include <iostream>


int main(int argc, char* argv[])
{
	Window window = Window();
	if (!window.IsInit())
		exit(EXIT_FAILURE);
	window.RunLoop();
	window.Destroy();
	exit(EXIT_SUCCESS);
}

