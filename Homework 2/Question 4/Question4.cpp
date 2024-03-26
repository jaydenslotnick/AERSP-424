#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

int main() {
  if ( !glfwInit() ) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow( 500, 500, "Dynamic Pressure Curve using OpenGL with GLEW and GLFW", NULL, NULL );
  if ( !window ) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent( window );

  if ( glewInit() != GLEW_OK ) {
    std::cerr << "Failed to initialize GLEW" << std::endl;
    return -1;
  }

  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

  while ( !glfwWindowShouldClose( window ) ) {
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_LINES );
    // Draw X and Y axis
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex2f( -1.0, 0.0 );
    glVertex2f( 1.0, 0.0 );
    glVertex2f( 0.0, 1.0 );
    glVertex2f( 0.0, -1.0 );

    // Plot dynamic pressure curve for a range of velocities
    // equation chosen: q = 0.5*rho*U^2, q is dynamic pressure (psf), rho is density (slugs/ft^3), U is velocity (ft/s)

    double rho = 0.00238; // sea level density, slugs/ft^3, assumed as constant for low speeds
    double maxVelocity = 45; // sets maximum velocity as 45 ft/s (numbers comparable to an experiment I did)
    int numPoints = 100; // breaks the velocity into 100 points

    glColor3f( 0.0, 1.0, 0.0 );
    for (int i = 0; i <= numPoints; ++i) 
    {
        double U = (maxVelocity / numPoints) * i;
        double q = 0.5 * rho * U * U;
      glVertex2f( U, q );
    }
    glEnd();

    glfwSwapBuffers( window );
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}