#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  if ( !glfwInit() ) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow( 1000, 1000, "Mach number Curve using OpenGL with GLEW and GLFW", NULL, NULL );
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

  glViewport(0, 0, 800, 800); // Set viewport to the first quadrant

  while ( !glfwWindowShouldClose( window ) ) {
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_LINES );
    // Draw X and Y axis
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex2f( 0.0, 0.0 );
    glVertex2f( 1000 , 0.0 );
    glVertex2f( 0.0, 0.0 );
    glVertex2f( 0.0,  5.0 );
    glEnd();

    // Plot dynamic pressure curve for a range of velocities
    // equation chosen: q = 0.5*rho*U^2, q is dynamic pressure (psf), rho is density (slugs/ft^3), U is velocity (ft/s)

    
    float a = 1; // average speed of sound

    glBegin(GL_POINTS);

    glColor3f( 0.0, 1.0, 0.0 );

    // vary the speed that is traveled from 0 to 1000 m/s
    for (float U = 0; U < 1; U+=0.001) 
    {
        float Ma = U / a; // calculation of mach number
        glVertex2f( U, Ma );
    }
    glEnd();

    glfwSwapBuffers( window );
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}