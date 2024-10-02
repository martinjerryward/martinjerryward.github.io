// include the library header files
#include <gl/freeglut.h>
#include <stdlib.h>
#include <math.h>

// a point data type
typedef GLfloat point2[2];

// the vectors
point2 vectorA = { 0.0, 0.0 };
point2 vectorB = { 0.0, 0.0 };
point2 vectorC = { 0.0, 0.0 };

// Define setupVectors to initialize the vectors
void setupVectors() {
    vectorA[0] = 0.2f; vectorA[1] = 0.5f;  // Example values for vector A
    vectorB[0] = 0.7f; vectorB[1] = 0.7f;  // Example values for vector B
    vectorC[0] = -0.3f; vectorC[1] = 0.8f; // Example values for vector C
}

void initializeGL(void)
{
    // enter GL_PROJECTION mode
    glMatrixMode(GL_PROJECTION);
    // clear the projection matrix
    glLoadIdentity();
    // set window mode to 2D orthographic
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    // setup the vectors
    setupVectors();
}

void myDisplay(void)
{
    // Variables for projection
    GLfloat dotProductAB, magnitudeB, scalarProj;
    GLfloat projAB[2]; // To store the projection result

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES); // draw the lines

    // draw vector A red
    glColor3f(1, 0, 0);
    glVertex2f(0, 0);
    glVertex2fv(vectorA);

    // draw vector B green
    glColor3f(0, 1, 0); // Green color
    glVertex2f(0, 0); // Starting from the origin
    glVertex2fv(vectorB); // End point of vector B

    // Calculate projection of A onto B
    // 1. Compute the dot product of A and B
    dotProductAB = (vectorA[0] * vectorB[0]) + (vectorA[1] * vectorB[1]);

    // 2. Compute the magnitude squared of B (B dot B)
    magnitudeB = (vectorB[0] * vectorB[0]) + (vectorB[1] * vectorB[1]);

    // 3. Compute the scalar projection of A onto B
    scalarProj = dotProductAB / magnitudeB;

    // 4. Multiply vector B by this scalar to get the projection of A onto B
    projAB[0] = scalarProj * vectorB[0];
    projAB[1] = scalarProj * vectorB[1];

    // draw projection of A onto B yellow
    glColor3f(1, 1, 0); // Yellow color for the projection
    glVertex2f(0, 0); // Starting from the origin
    glVertex2fv(projAB); // End point of the projection

    // draw vector C blue
    glColor3f(0, 0, 1); // Blue color
    glVertex2f(0, 0); // Starting from the origin
    glVertex2fv(vectorC); // End point of vector C

    glEnd();
    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);      // Set display mode to single-buffered
    glutInitWindowSize(400, 400);          // Set window size
    glutCreateWindow("Vector Drawing");    // Create the window

    initializeGL();                        // Initialize OpenGL settings
    glutDisplayFunc(myDisplay);            // Register display callback

    glutMainLoop();                        // Enter the main loop

    return 0;
}
