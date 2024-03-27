#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  if ( !glfwInit() ) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow( 1000, 1000, "Predicted induced velocity of a rotor in hover using OpenGL with GLEW and GLFW", NULL, NULL );
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
    glVertex2f( -1, 0.0 );
    glVertex2f( 1.0 , 0.0 );
    glVertex2f( 0.0, -1.0 );
    glVertex2f( 0.0, 1.0 );
    glEnd();

    
    // initalizing variables for the equation for the average induced velocity for a rotor in hover
    // equation is: vh = sqrt(T/(2*rho*A))


    float rho = 0.00238; // sea level density of air (slugs/ft^3)
    float Area = 1.068; // area of a rotor with a diameter of 14 inches (reported in feet)
    float maxThrust = 5; // max thrust possible (lbf), arbitarily determined from some experimental data from my lab
    float maxvh = std::pow(maxThrust / (2 * rho * Area), 0.5); // maximum predicted induced velocity (ft/s)

    glBegin(GL_POINTS);

    glColor3f( 0.0, 1.0, 0.0 );

    for (float Thrust = 0; Thrust < maxThrust; Thrust +=0.001) // varies thrust from 0 to 5 lbf in 0.001 lbf increments
    {
      
        float vh = std::pow(Thrust / (2 * rho * Area), 0.5); // calculation of hover velocity (ft/s)
        glVertex2f( Thrust/maxThrust, vh/maxvh ); // plots individual points normalized by the maximum value
        // x axis is normalized thrust and y axis is normalized induced velocity for a rotor in hover

    }
    glEnd();

    glfwSwapBuffers( window );
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}