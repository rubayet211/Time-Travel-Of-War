#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#define PI 3.141516
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// for  -1
static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.1;

float spin_x = 0;
float spin_y = 0;
float spin_z = 1;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;

unsigned char key;

GLfloat positionBoat = 0.0f;
GLfloat positionSky = 0.0f;
GLfloat positionSun = 0.0f;
GLfloat positionRedDino = 0.0f;
GLfloat positionMamoth = 0.0f;
GLfloat positionBrownDino = 0.0f;
GLfloat positionOrangeDino = 0.0f;
GLfloat positionActor = 0.0f;

// Speed
GLfloat speedBoat = 0.05f;
GLfloat speedSky = 0.05f;
GLfloat speedSun = 0.05f;
GLfloat speedRedDino = 0.01f;
GLfloat speedMamoth = 0.001f;
GLfloat speedBrownDino = 0.0025f;
GLfloat speedOrangeDino = 0.0045f;
GLfloat positionSmoke = 0.0f;
GLfloat speedSmoke = 0.1f;
GLfloat speedActor = 0.0f;

// for   -1
int i;

GLfloat position = 0.0f;
GLfloat positiongun = 0.0f;
GLfloat positionwater = 0.0f;
GLfloat positioncloud = 0.0f;
GLfloat positiontank = 0.0f;
GLfloat positionBigBoat = 0.0f;
GLfloat positionPiretBoat = 0.0f;
GLfloat positionSoldiersSword = 0.0f;
GLfloat speedPiretBoat = 0.00f;
GLfloat speedSoldiersSword = 0.001f;
// GLfloat positionActor = 0.0f;
GLfloat positionArmy = 0.0f;

GLfloat positionBg = 0.0f;
GLfloat speedBg = 0.1f;


GLfloat speed = 0.00f;
GLfloat speedwater = 0.05f;
GLfloat speedcloud = 0.05f;
GLfloat speedtank = 0.05f;
GLfloat speedBigBoat = 0.01f;
// GLfloat speedActor = 0.0f;
GLfloat speedArmy = 0.05f;
GLfloat positionBullet = 0.0f;
GLfloat speedBullet = 0.04f;
GLfloat ScaleBullet = 0.0f;
GLfloat srateBullet = 0.5f;
// GLfloat positionSmoke = 0.0f;
// GLfloat speedSmoke = 0.1f;
GLfloat speedGun = 0.1f;

// GLfloat speedBoat = 0.07f;

int pntX1, pntY1, choice = 0, edges;
// vector<int> pntX;
// vector<int> pntY;
int transX, transY;
double scaleX, scaleY;
int triangle2 = 50;
int tringle2 = 50;
GLfloat tp2 = 2.0f * PI;

// GLfloat tp2 = 2.0f * PI;
// int tringle2 = 40;
// int i;

void update(int value)
{
    if (positionBoat < -1.5)
        positionBoat = 1.5f;
    if (positionSky < -1.5)
        positionSky = 1.5f;
    if (positionSun < -1.5)
        positionSun = 1.5f;
    if (positionSmoke < -1.0)
        positionSmoke = 1.0f;
    if (positionRedDino < -1.2)
        positionRedDino = 1.5f;
    if (positionBrownDino < -1.2)
        positionBrownDino = 1.5f;
    if (positionOrangeDino < -1.2)
        positionOrangeDino = 1.5f;
    if (positionMamoth < -0.3)
        positionMamoth = 0.2f;
    if (positionActor < -7.5)
        positionActor = 1.0f;

    positionBoat -= speedBoat;
    positionSky -= speedSky;
    positionSun -= speedSun;
    positionSmoke -= speedSmoke;
    positionRedDino -= speedRedDino;
    positionMamoth -= speedMamoth;
    positionBrownDino -= speedBrownDino;
    positionOrangeDino -= speedOrangeDino;
    positionActor -= speedActor;

    glutPostRedisplay();

    glutTimerFunc(100, update, 0);
}

// for -1

void myInit(void)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void reshape(int w, int h)
{
    glViewport(100, 100, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spinDisplay(void)
{
    spin = spin + 0;
    if (spin > 360.0)
    {
        spin = spin - 360.0;
    }
    glutPostRedisplay();
}

void spinDisplayStop(void)
{
    spin = spin - spin_speed;
    if (spin < 360.0)
    {
        spin = spin + 360.0;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        speedPiretBoat += 0.01f;
    }
    if (button == GLUT_MIDDLE_BUTTON)
    {
        speedPiretBoat = 0.0f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        speedPiretBoat -= 0.01f;
    }
    glutPostRedisplay();
}

double round(double d)
{
    return floor(d + 0.5);
}

// update for -1
void updateFor1(int value)
{

    if (position < -0.5)
        position = .5f;
    if (positiongun < -0.1)
        positiongun = 0.2f;
    if (positionwater < -1.8)
        positionwater = 1.8f;
    if (positioncloud < -1.5)
        positioncloud = 1.5f;
    if (positiontank < -5.0)
        positiontank = 5.0f;
    if (positionActor < -7.5)
        positionActor = 1.0f;
    if (positionBigBoat < -7.0)
        positionBigBoat = 1.0f;
    if (positionArmy < -11.0)
        positionArmy = 2.0f;
    if (positionBullet < -1.0)
        positionBullet = 1.0f;
    if (ScaleBullet < -1.0)
        ScaleBullet = 1.0f;
    if (positionSmoke < -1.5)
        positionSmoke = 1.5f;
    if (positionBoat < -2.5)
        positionBoat = 2.5f;

    position -= speed;
    positiongun -= speedGun;
    positionBoat -= speedBoat;
    positionwater -= speedwater;
    positioncloud -= speedcloud;
    positiontank -= speedtank;
    positionActor -= speedActor;
    positionArmy -= speedArmy;
    positionBigBoat -= speedBigBoat;
    positionBullet -= speedBullet;
    ScaleBullet -= srateBullet;
    positionSmoke -= speedSmoke;

    glutPostRedisplay();

    glutTimerFunc(100, updateFor1, 0);
}

void updateFor2(int value)
{
    if(positionBg <-1.0 && positionActor == 0.1f)
        positionBg = -1.0f;

    positionBg -= speedBg;

    glutPostRedisplay();

    glutTimerFunc(100, updateFor2, 0);

}

void updateFor3(int value)
{
    if (positionPiretBoat < -1.5)
        positionPiretBoat = 1.2f;
    if (positionSoldiersSword < -1.5)
        positionSoldiersSword = 1.2f;

    positionPiretBoat -= speedPiretBoat;
    positionSoldiersSword -= speedSoldiersSword;

    glutPostRedisplay();

    glutTimerFunc(100, updateFor3, 0);
}

void soldiersSword()
    {
        //Body
        glBegin(GL_QUADS);
        glColor3ub(59, 59, 59);

        glVertex2f(-0.05f, 0.0f);
        glVertex2f(0.05f, 0.0f);

        glVertex2f(0.05f, 0.45f);
        glVertex2f(-0.05f, 0.45f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(117, 102, 90);

        glVertex2f(-0.05f, 0.0f);
        glVertex2f(-0.05f, -0.45f);
        glVertex2f(0.03f, -0.45f);
        glVertex2f(0.03f, 0.0f);
        glEnd();

        //Head
        GLfloat p8 = 0.0f;
        GLfloat q8 = 0.61f;
        GLfloat r8 = 0.16f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(196, 128, 59);
        glVertex2f(p8, q8);
        for (i = 0; i <= tringle2; i++)
        {
            glVertex2f(
                p8 + (0.5*r8 * cos(i * tp2 / tringle2)),
                q8 + (r8 * sin(i * tp2 / tringle2)));
        }
        glEnd();

        //helmet
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(43, 43, 43);
        glVertex2f(0.013f, 0.69f);
        glVertex2f(0.015f, 0.603f);
        glVertex2f(0.084f, 0.548f);
        glVertex2f(0.077f, 0.888f);
        glVertex2f(-0.072f, 0.797f);
        glVertex2f(-0.078f, 0.69f);
        glEnd();


        // sward
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(122,122,122);
        glVertex2f(-0.294f, 0.801f);
        glVertex2f(-0.330f, 0.888f);
        glVertex2f(-0.361f, 0.801f);
        glVertex2f(-0.341f, 0.418f);
        glVertex2f(-0.305f, 0.422f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(134,54,14);
        glVertex2f(-0.307f, 0.267f);
        glVertex2f(-0.307f, 0.398f);
        glVertex2f(-0.341f, 0.398f);
        glVertex2f(-0.341f, 0.267f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(82,27,0);
        glVertex2f(-0.358f, 0.398f);
        glVertex2f(-0.285f, 0.398f);
        glVertex2f(-0.285f, 0.422f);
        glVertex2f(-0.358f, 0.422f);
        glEnd();

        //Hands
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(232,191,171);
        glVertex2f(-0.290f, 0.358f);
        glVertex2f(-0.090f, 0.374f);
        glVertex2f(-0.090f, 0.299f);
        glVertex2f(-0.290f, 0.299f);
        glVertex2f(-0.305f, 0.287f);
        glVertex2f(-0.332f, 0.283f);
        glVertex2f(-0.345f, 0.303f);
        glVertex2f(-0.345f, 0.331f);
        glVertex2f(-0.336f, 0.354f);
        glVertex2f(-0.305f, 0.358f);
        glVertex2f(-0.318f, 0.37f);
        glVertex2f(-0.312f, 0.39f);
        glVertex2f(-0.294f, 0.374f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(107, 107, 107);
        glVertex2f(-0.092f, 0.39f);
        glVertex2f(0.030f, 0.394f);
        glVertex2f(0.030f, 0.287f);
        glVertex2f(-0.092f, 0.287f);
        glEnd();

        //Shoe
        GLfloat p3 = -0.015f;
        GLfloat q3 = -0.47f;
        GLfloat r3 = 0.05f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(75, 105, 222);
        glVertex2f(p3, q3);
        for (i = 0; i <= tringle2; i++)
        {
            glVertex2f(
                p3 + (1.2*r3 * cos(i * tp2 / tringle2)),
                q3 + (r3 * sin(i * tp2 / tringle2)));
        }
        glEnd();

        glFlush();
    }


// Soldiers Translate and Scale
void translateSoldiersSword(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
}
void scaleSoldiersSword(float trans_X, float trans_Y, float trans_Z)
{

    glScalef(trans_X, trans_Y, trans_Z);
    soldiersSword();

    glRotatef(180,0.0,1.0,0.0);
    glTranslated(0.7,0,0);
    soldiersSword();

    glRotatef(180,0.0,1.0,0.0);
    glTranslated(-0.5,-1,0);
    soldiersSword();

    glRotatef(180,0.0,1.0,0.0);
    glTranslated(0.7,0,0);
    soldiersSword();

    glRotatef(180,0.0,1.0,0.0);
    glTranslated(0.3,1.6,0);
    soldiersSword();

    glRotatef(180,0.0,1.0,0.0);
    glTranslated(0.7,0,0);
    soldiersSword();
}


void river()
    {
            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(50,169,203);
            glVertex2f(0.433f, -0.855f);
            glVertex2f(1.004f, -1.001f);
            glVertex2f(1.004f, 0.212f);
            glVertex2f(-0.118f, 0.224f);
            glEnd();
    }

void Boat()
    {
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(173,116,71);
        glVertex2f(0.215f, -0.906f);
        glVertex2f(0.268f, -0.902f);
        glVertex2f(0.306f, -0.895f);
        glVertex2f(0.342f, -0.887f);
        glVertex2f(0.373f, -0.875f);
        glVertex2f(0.402f, -0.855f);
        glVertex2f(0.428f, -0.831f);
        glVertex2f(0.444f, -0.808f);
        glVertex2f(0.455f, -0.776f);
        glVertex2f(0.464f, -0.74f);
        glVertex2f(0.475f, -0.705f);
        glVertex2f(0.484f, -0.677f);
        glVertex2f(0.497f, -0.642f);
        glVertex2f(0.510f, -0.61f);
        glVertex2f(0.526f, -0.582f);
        glVertex2f(0.544f, -0.559f);
        glVertex2f(0.557f, -0.539f);
        glVertex2f(0.504f, -0.539f);
        glVertex2f(-0.352f, -0.602f);
        glVertex2f(-0.343f, -0.63f);
        glVertex2f(-0.316f, -0.721f);
        glVertex2f(-0.298f, -0.772f);
        glVertex2f(-0.272f, -0.823f);
        glVertex2f(-0.245f, -0.855f);
        glVertex2f(-0.210f, -0.883f);
        glVertex2f(-0.176f, -0.895f);
        glVertex2f(-0.125f, -0.906f);
        glVertex2f(-0.050f, -0.918f);
        glVertex2f(0.128f, -0.914f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(96,96,96);
        glVertex2f(0.139f, 0.133f);
        glVertex2f(0.190f, 0.271f);
        glVertex2f(0.199f, 0.299f);
        glVertex2f(0.544f, 0.473f);
        glVertex2f(0.490f, 0.335f);
        glVertex2f(0.453f, 0.232f);
        glVertex2f(0.424f, 0.141f);
        glVertex2f(0.410f, 0.082f);
        glVertex2f(0.397f, 0.011f);
        glVertex2f(0.390f, -0.08f);
        glVertex2f(0.390f, -0.144f);
        glVertex2f(0.393f, -0.187f);
        glVertex2f(0.397f, -0.223f);
        glVertex2f(0.402f, -0.246f);
        glVertex2f(0.417f, -0.321f);
        glVertex2f(0.417f, -0.594f);
        glVertex2f(-0.296f, -0.59f);
        glVertex2f(-0.296f, -0.456f);
        glVertex2f(-0.296f, -0.456f);
        glVertex2f(-0.347f, -0.321f);
        glVertex2f(-0.372f, -0.231f);
        glVertex2f(-0.387f, -0.155f);
        glVertex2f(-0.392f, -0.065f);
        glVertex2f(-0.385f, 0.003f);
        glVertex2f(-0.367f, 0.074f);
        glVertex2f(-0.345f, 0.137f);
        glVertex2f(-0.341f, 0.149f);
        glVertex2f(-0.174f, 0.271f);
        glVertex2f(-0.112f, 0.54f);
        glVertex2f(0.335f, 0.766f);
        glVertex2f(0.264f, 0.639f);
        glVertex2f(0.219f, 0.544f);
        glVertex2f(0.188f, 0.461f);
        glVertex2f(0.155f, 0.335f);
        glVertex2f(0.144f, 0.256f);
        glVertex2f(0.139f, 0.2f);
        glVertex2f(0.139f, 0.157f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,98,54);
        glVertex2f(-0.345f, 0.181f);
        glVertex2f(-0.027f, 0.35f);
        glVertex2f(-0.025f, 0.299f);
        glVertex2f(-0.347f, 0.141f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,98,54);
        glVertex2f(-0.152f, 0.477f);
        glVertex2f(-0.145f, -0.567f);
        glVertex2f(-0.178f, -0.567f);
        glVertex2f(-0.185f, 0.477f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,98,54);
        glVertex2f(-0.125f, 0.544f);
        glVertex2f(0.337f, 0.785f);
        glVertex2f(0.337f, 0.746f);
        glVertex2f(-0.127f, 0.513f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,98,54);
        glVertex2f(0.033f, 0.912f);
        glVertex2f(0.059f, 0.916f);
        glVertex2f(0.075f, -0.563f);
        glVertex2f(0.046f, -0.563f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,98,54);
        glVertex2f(0.324f, 0.607f);
        glVertex2f(0.339f, -0.563f);
        glVertex2f(0.310f, -0.563f);
        glVertex2f(0.297f, 0.647f);
        glVertex2f(0.464f, 0.73f);
        glVertex2f(0.464f, 0.694f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,98,54);
        glVertex2f(0.186f, 0.307f);
        glVertex2f(0.542f, 0.493f);
        glVertex2f(0.544f, 0.453f);
        glVertex2f(0.186f, 0.279f);
        glEnd();

        //body
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(141,84,39);
        glVertex2f(-0.118f, -0.527f);
        glVertex2f(-0.152f, -0.527f);
        glVertex2f(-0.172f, -0.519f);
        glVertex2f(-0.198f, -0.511f);
        glVertex2f(-0.225f, -0.503f);
        glVertex2f(-0.256f, -0.495f);
        glVertex2f(-0.285f, -0.476f);
        glVertex2f(-0.307f, -0.464f);
        glVertex2f(-0.336f, -0.444f);
        glVertex2f(-0.361f, -0.428f);
        glVertex2f(-0.385f, -0.408f);
        glVertex2f(-0.412f, -0.389f);
        glVertex2f(-0.427f, -0.377f);
        glVertex2f(-0.476f, -0.333f);
        glVertex2f(-0.514f, -0.286f);
        glVertex2f(-0.598f, -0.187f);
        glVertex2f(-0.558f, -0.234f);
        glVertex2f(-0.523f, -0.282f);
        glVertex2f(-0.492f, -0.325f);
        glVertex2f(-0.458f, -0.373f);
        glVertex2f(-0.434f, -0.42f);
        glVertex2f(-0.418f, -0.452f);
        glVertex2f(-0.398f, -0.495f);
        glVertex2f(-0.387f, -0.531f);
        glVertex2f(-0.374f, -0.574f);
        glVertex2f(-0.365f, -0.618f);
        glVertex2f(-0.361f, -0.653f);
        glVertex2f(-0.332f, -0.677f);
        glVertex2f(-0.341f, -0.626f);
        glVertex2f(-0.270f, -0.701f);
        glVertex2f(-0.227f, -0.736f);
        glVertex2f(-0.176f, -0.772f);
        glVertex2f(-0.136f, -0.792f);
        glVertex2f(-0.092f, -0.808f);
        glVertex2f(-0.045f, -0.816f);
        glVertex2f(0.035f, -0.816f);
        glVertex2f(0.210f, -0.816f);
        glVertex2f(0.273f, -0.804f);
        glVertex2f(0.315f, -0.788f);
        glVertex2f(0.355f, -0.764f);
        glVertex2f(0.390f, -0.736f);
        glVertex2f(0.417f, -0.701f);
        glVertex2f(0.442f, -0.665f);
        glVertex2f(0.464f, -0.626f);
        glVertex2f(0.508f, -0.543f);
        glVertex2f(0.557f, -0.539f);
        glVertex2f(0.590f, -0.282f);
        glVertex2f(0.604f, -0.282f);
        glVertex2f(0.604f, -0.227f);
        glVertex2f(0.588f, -0.282f);
        glVertex2f(0.390f, -0.278f);
        glVertex2f(0.379f, -0.298f);
        glVertex2f(0.375f, -0.329f);
        glVertex2f(0.373f, -0.353f);
        glVertex2f(0.373f, -0.381f);
        glVertex2f(0.370f, -0.408f);
        glVertex2f(0.368f, -0.432f);
        glVertex2f(0.362f, -0.448f);
        glVertex2f(0.357f, -0.472f);
        glVertex2f(0.348f, -0.48f);
        glVertex2f(0.342f, -0.495f);
        glVertex2f(0.326f, -0.511f);
        glVertex2f(0.308f, -0.519f);
        glVertex2f(0.277f, -0.527f);
        glVertex2f(0.248f, -0.527f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.346f, 0.611f);
        glVertex2f(0.513f, -0.254f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.346f, 0.611f);
        glVertex2f(0.513f, -0.254f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.388f, 0.655f);
        glVertex2f(0.548f, -0.337f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.388f, 0.655f);
        glVertex2f(0.548f, -0.337f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.446f, 0.71f);
        glVertex2f(0.570f, -0.306f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.446f, 0.71f);
        glVertex2f(0.570f, -0.306f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.355f, 0.568f);
        glVertex2f(0.457f, 0.627f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.355f, 0.568f);
        glVertex2f(0.457f, 0.627f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.368f, 0.493f);
        glVertex2f(0.466f, 0.548f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.368f, 0.493f);
        glVertex2f(0.466f, 0.548f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.433f, 0.157f);
        glVertex2f(0.508f, 0.204f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.433f, 0.157f);
        glVertex2f(0.508f, 0.204f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.448f, 0.086f);
        glVertex2f(0.517f, 0.129f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.448f, 0.086f);
        glVertex2f(0.517f, 0.129f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.459f, 0.03f);
        glVertex2f(0.524f, 0.07f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.459f, 0.03f);
        glVertex2f(0.524f, 0.07f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.468f, -0.013f);
        glVertex2f(0.530f, 0.022f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.468f, -0.013f);
        glVertex2f(0.530f, 0.022f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.475f, -0.053f);
        glVertex2f(0.535f, -0.017f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.475f, -0.053f);
        glVertex2f(0.535f, -0.017f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.490f, -0.128f);
        glVertex2f(0.544f, -0.092f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.490f, -0.128f);
        glVertex2f(0.544f, -0.092f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.504f, -0.203f);
        glVertex2f(0.553f, -0.171f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.504f, -0.203f);
        glVertex2f(0.553f, -0.171f);
        glEnd();

        //flag
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(64,64,64);
        glVertex2f(-0.130f, 0.789f);
        glVertex2f(-0.118f, 0.813f);
        glVertex2f(-0.105f, 0.841f);
        glVertex2f(-0.087f, 0.888f);
        glVertex2f(-0.072f, 0.916f);
        glVertex2f(-0.061f, 0.92f);
        glVertex2f(-0.050f, 0.92f);
        glVertex2f(-0.043f, 0.912f);
        glVertex2f(-0.043f, 0.896f);
        glVertex2f(-0.043f, 0.884f);
        glVertex2f(-0.041f, 0.841f);
        glVertex2f(0.028f, 0.896f);
        glVertex2f(0.028f, 0.916f);
        glVertex2f(0.062f, 0.916f);
        glVertex2f(0.057f, 0.801f);
        glVertex2f(0.019f, 0.797f);
        glVertex2f(-0.012f, 0.777f);
        glVertex2f(-0.038f, 0.742f);
        glVertex2f(-0.054f, 0.714f);
        glVertex2f(-0.067f, 0.69f);
        glVertex2f(-0.078f, 0.686f);
        glVertex2f(-0.083f, 0.698f);
        glVertex2f(-0.078f, 0.726f);
        glVertex2f(-0.058f, 0.762f);
        glVertex2f(-0.041f, 0.801f);
        glVertex2f(-0.047f, 0.829f);
        glVertex2f(-0.070f, 0.821f);
        glVertex2f(-0.085f, 0.797f);
        glVertex2f(-0.096f, 0.766f);
        glVertex2f(-0.112f, 0.734f);
        glVertex2f(-0.118f, 0.718f);
        glVertex2f(-0.132f, 0.698f);
        glVertex2f(-0.147f, 0.679f);
        glVertex2f(-0.172f, 0.663f);
        glVertex2f(-0.190f, 0.659f);
        glVertex2f(-0.194f, 0.682f);
        glVertex2f(-0.194f, 0.722f);
        glVertex2f(-0.218f, 0.686f);
        glVertex2f(-0.238f, 0.663f);
        glVertex2f(-0.267f, 0.643f);
        glVertex2f(-0.287f, 0.639f);
        glVertex2f(-0.314f, 0.635f);
        glVertex2f(-0.258f, 0.686f);
        glVertex2f(-0.241f, 0.718f);
        glVertex2f(-0.307f, 0.73f);
        glVertex2f(-0.267f, 0.742f);
        glVertex2f(-0.234f, 0.758f);
        glVertex2f(-0.216f, 0.785f);
        glVertex2f(-0.198f, 0.813f);
        glVertex2f(-0.181f, 0.833f);
        glVertex2f(-0.174f, 0.825f);
        glVertex2f(-0.172f, 0.809f);
        glVertex2f(-0.176f, 0.789f);
        glVertex2f(-0.176f, 0.762f);
        glVertex2f(-0.176f, 0.754f);
        glVertex2f(-0.161f, 0.762f);
        glVertex2f(-0.145f, 0.773f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(-0.281f, -0.519f);
        glVertex2f(-0.247f, -0.523f);
        glVertex2f(-0.247f, -0.57f);
        glVertex2f(-0.281f, -0.567f);
        glVertex2f(-0.281f, -0.519f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(-0.150f, -0.606f);
        glVertex2f(-0.178f, -0.602f);
        glVertex2f(-0.174f, -0.547f);
        glVertex2f(-0.145f, -0.555f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(-0.072f, -0.574f);
        glVertex2f(-0.043f, -0.574f);
        glVertex2f(-0.043f, -0.63f);
        glVertex2f(-0.072f, -0.63f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.033f, -0.626f);
        glVertex2f(0.030f, -0.574f);
        glVertex2f(0.059f, -0.574f);
        glVertex2f(0.059f, -0.626f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.137f, -0.63f);
        glVertex2f(0.135f, -0.578f);
        glVertex2f(0.164f, -0.578f);
        glVertex2f(0.164f, -0.63f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.237f, -0.57f);
        glVertex2f(0.235f, -0.57f);
        glVertex2f(0.266f, -0.567f);
        glVertex2f(0.266f, -0.622f);
        glVertex2f(0.237f, -0.622f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.368f, -0.594f);
        glVertex2f(0.339f, -0.594f);
        glVertex2f(0.339f, -0.539f);
        glVertex2f(0.370f, -0.547f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.430f, -0.373f);
        glVertex2f(0.395f, -0.373f);
        glVertex2f(0.395f, -0.318f);
        glVertex2f(0.433f, -0.318f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.455f, -0.321f);
        glVertex2f(0.488f, -0.318f);
        glVertex2f(0.488f, -0.373f);
        glVertex2f(0.455f, -0.373f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.550f, -0.318f);
        glVertex2f(0.553f, -0.373f);
        glVertex2f(0.517f, -0.373f);
        glVertex2f(0.517f, -0.318f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.519f, -0.416f);
        glVertex2f(0.555f, -0.412f);
        glVertex2f(0.555f, -0.476f);
        glVertex2f(0.519f, -0.476f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.457f, -0.472f);
        glVertex2f(0.455f, -0.42f);
        glVertex2f(0.490f, -0.416f);
        glVertex2f(0.493f, -0.476f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(146,146,146);
        glVertex2f(0.395f, -0.476f);
        glVertex2f(0.395f, -0.42f);
        glVertex2f(0.430f, -0.42f);
        glVertex2f(0.430f, -0.48f);
        glEnd();
    }

void background()
    {
        // Hill
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(192,183,174);
        glVertex2f(-0.385f, 0.74f);
        glVertex2f(-0.425f, 0.74f);
        glVertex2f(-0.494f, 0.793f);
        glVertex2f(-0.634f, 0.837f);
        glVertex2f(-0.736f, 0.86f);
        glVertex2f(-0.872f, 0.868f);
        glVertex2f(-1.003f, 0.864f);
        glVertex2f(-1.003f, 0.078f);
        glVertex2f(-0.078f, 0.07f);
        glVertex2f(0.090f, 0.125f);
        glVertex2f(-0.214f, 0.548f);
        glVertex2f(-0.227f, 0.56f);
        glVertex2f(-0.250f, 0.568f);
        glVertex2f(-0.263f, 0.576f);
        glVertex2f(-0.276f, 0.588f);
        glVertex2f(-0.287f, 0.607f);
        glVertex2f(-0.296f, 0.631f);
        glVertex2f(-0.307f, 0.659f);
        glVertex2f(-0.323f, 0.679f);
        glVertex2f(-0.341f, 0.694f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(128,114,101);
        glVertex2f(-0.401f, 0.433f);
        glVertex2f(-0.383f, 0.41f);
        glVertex2f(-0.370f, 0.402f);
        glVertex2f(-0.363f, 0.402f);
        glVertex2f(-0.378f, 0.469f);
        glVertex2f(-0.367f, 0.469f);
        glVertex2f(-0.354f, 0.457f);
        glVertex2f(-0.345f, 0.441f);
        glVertex2f(-0.338f, 0.418f);
        glVertex2f(-0.332f, 0.398f);
        glVertex2f(-0.323f, 0.374f);
        glVertex2f(-0.310f, 0.354f);
        glVertex2f(-0.285f, 0.319f);
        glVertex2f(-0.267f, 0.291f);
        glVertex2f(-0.241f, 0.26f);
        glVertex2f(-0.214f, 0.24f);
        glVertex2f(-0.194f, 0.224f);
        glVertex2f(-0.187f, 0.224f);
        glVertex2f(-0.187f, 0.24f);
        glVertex2f(-0.201f, 0.264f);
        glVertex2f(-0.214f, 0.283f);
        glVertex2f(-0.225f, 0.311f);
        glVertex2f(-0.236f, 0.354f);
        glVertex2f(-0.241f, 0.39f);
        glVertex2f(-0.245f, 0.426f);
        glVertex2f(-0.247f, 0.457f);
        glVertex2f(-0.252f, 0.493f);
        glVertex2f(-0.214f, 0.441f);
        glVertex2f(-0.196f, 0.41f);
        glVertex2f(-0.178f, 0.394f);
        glVertex2f(-0.163f, 0.398f);
        glVertex2f(-0.172f, 0.445f);
        glVertex2f(-0.138f, 0.41f);
        glVertex2f(-0.116f, 0.374f);
        glVertex2f(-0.096f, 0.339f);
        glVertex2f(-0.078f, 0.295f);
        glVertex2f(-0.058f, 0.256f);
        glVertex2f(-0.036f, 0.224f);
        glVertex2f(-0.001f, 0.192f);
        glVertex2f(0.028f, 0.184f);
        glVertex2f(0.042f, 0.184f);
        glVertex2f(0.093f, 0.137f);
        glVertex2f(0.066f, 0.133f);
        glVertex2f(0.035f, 0.133f);
        glVertex2f(0.004f, 0.145f);
        glVertex2f(-0.023f, 0.165f);
        glVertex2f(-0.092f, 0.034f);
        glVertex2f(-0.741f, 0.323f);
        glVertex2f(-0.732f, 0.402f);
        glVertex2f(-0.741f, 0.461f);
        glVertex2f(-0.750f, 0.513f);
        glVertex2f(-0.750f, 0.54f);
        glVertex2f(-0.747f, 0.56f);
        glVertex2f(-0.738f, 0.576f);
        glVertex2f(-0.730f, 0.584f);
        glVertex2f(-0.716f, 0.588f);
        glVertex2f(-0.707f, 0.572f);
        glVertex2f(-0.703f, 0.552f);
        glVertex2f(-0.703f, 0.52f);
        glVertex2f(-0.701f, 0.501f);
        glVertex2f(-0.696f, 0.477f);
        glVertex2f(-0.690f, 0.449f);
        glVertex2f(-0.678f, 0.426f);
        glVertex2f(-0.665f, 0.402f);
        glVertex2f(-0.654f, 0.374f);
        glVertex2f(-0.661f, 0.43f);
        glVertex2f(-0.667f, 0.449f);
        glVertex2f(-0.667f, 0.477f);
        glVertex2f(-0.663f, 0.532f);
        glVertex2f(-0.607f, 0.35f);
        glVertex2f(-0.545f, 0.418f);
        glVertex2f(-0.545f, 0.457f);
        glVertex2f(-0.550f, 0.477f);
        glVertex2f(-0.558f, 0.497f);
        glVertex2f(-0.567f, 0.513f);
        glVertex2f(-0.578f, 0.54f);
        glVertex2f(-0.590f, 0.56f);
        glVertex2f(-0.603f, 0.58f);
        glVertex2f(-0.614f, 0.607f);
        glVertex2f(-0.627f, 0.643f);
        glVertex2f(-0.634f, 0.663f);
        glVertex2f(-0.636f, 0.679f);
        glVertex2f(-0.636f, 0.69f);
        glVertex2f(-0.632f, 0.702f);
        glVertex2f(-0.618f, 0.698f);
        glVertex2f(-0.592f, 0.686f);
        glVertex2f(-0.567f, 0.667f);
        glVertex2f(-0.534f, 0.635f);
        glVertex2f(-0.501f, 0.596f);
        glVertex2f(-0.467f, 0.556f);
        glVertex2f(-0.452f, 0.52f);
        glVertex2f(-0.443f, 0.501f);
        glVertex2f(-0.427f, 0.469f);
        glVertex2f(-0.416f, 0.453f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(76,61,54);
        glVertex2f(-0.198f, 0.319f);
        glVertex2f(-0.214f, 0.354f);
        glVertex2f(-0.221f, 0.382f);
        glVertex2f(-0.230f, 0.43f);
        glVertex2f(-0.230f, 0.445f);
        glVertex2f(-0.216f, 0.41f);
        glVertex2f(-0.205f, 0.382f);
        glVertex2f(-0.190f, 0.358f);
        glVertex2f(-0.167f, 0.327f);
        glVertex2f(-0.147f, 0.303f);
        glVertex2f(-0.127f, 0.291f);
        glVertex2f(-0.105f, 0.271f);
        glVertex2f(-0.087f, 0.248f);
        glVertex2f(-0.065f, 0.216f);
        glVertex2f(-0.045f, 0.188f);
        glVertex2f(-0.023f, 0.165f);
        glVertex2f(-0.003f, 0.149f);
        glVertex2f(0.022f, 0.129f);
        glVertex2f(0.055f, 0.129f);
        glVertex2f(0.075f, 0.129f);
        glVertex2f(0.093f, 0.137f);
        glVertex2f(0.093f, 0.117f);
        glVertex2f(0.079f, 0.109f);
        glVertex2f(0.055f, 0.109f);
        glVertex2f(0.030f, 0.105f);
        glVertex2f(0.022f, 0.09f);
        glVertex2f(-0.025f, 0.078f);
        glVertex2f(-0.696f, 0.157f);
        glVertex2f(-0.698f, 0.343f);
        glVertex2f(-0.714f, 0.497f);
        glVertex2f(-0.667f, 0.271f);
        glVertex2f(-0.498f, 0.37f);
        glVertex2f(-0.503f, 0.445f);
        glVertex2f(-0.510f, 0.481f);
        glVertex2f(-0.521f, 0.52f);
        glVertex2f(-0.532f, 0.556f);
        glVertex2f(-0.550f, 0.596f);
        glVertex2f(-0.521f, 0.552f);
        glVertex2f(-0.505f, 0.516f);
        glVertex2f(-0.490f, 0.477f);
        glVertex2f(-0.476f, 0.441f);
        glVertex2f(-0.463f, 0.402f);
        glVertex2f(-0.447f, 0.362f);
        glVertex2f(-0.438f, 0.323f);
        glVertex2f(-0.032f, 0.125f);
        glVertex2f(-0.032f, 0.125f);
        glVertex2f(-0.023f, 0.137f);
        glVertex2f(-0.036f, 0.149f);
        glVertex2f(-0.063f, 0.181f);
        glVertex2f(-0.087f, 0.196f);
        glVertex2f(-0.110f, 0.212f);
        glVertex2f(-0.145f, 0.248f);
        glVertex2f(-0.176f, 0.287f);
        glEnd();

        // leaf

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(137,178,15);
        glVertex2f(-0.856f, 0.766f);
        glVertex2f(-0.821f, 0.722f);
        glVertex2f(-0.821f, 0.698f);
        glVertex2f(-0.814f, 0.718f);
        glVertex2f(-0.812f, 0.655f);
        glVertex2f(-0.803f, 0.675f);
        glVertex2f(-0.796f, 0.596f);
        glVertex2f(-0.787f, 0.679f);
        glVertex2f(-0.772f, 0.651f);
        glVertex2f(-0.790f, 0.71f);
        glVertex2f(-0.776f, 0.698f);
        glVertex2f(-0.783f, 0.754f);
        glVertex2f(-0.765f, 0.702f);
        glVertex2f(-0.765f, 0.726f);
        glVertex2f(-0.756f, 0.651f);
        glVertex2f(-0.752f, 0.671f);
        glVertex2f(-0.750f, 0.596f);
        glVertex2f(-0.741f, 0.627f);
        glVertex2f(-0.745f, 0.532f);
        glVertex2f(-0.725f, 0.603f);
        glVertex2f(-0.721f, 0.564f);
        glVertex2f(-0.714f, 0.647f);
        glVertex2f(-0.705f, 0.631f);
        glVertex2f(-0.743f, 0.742f);
        glVertex2f(-0.734f, 0.734f);
        glVertex2f(-0.765f, 0.777f);
        glVertex2f(-0.747f, 0.781f);
        glVertex2f(-0.798f, 0.805f);
        glVertex2f(-0.767f, 0.817f);
        glVertex2f(-0.774f, 0.825f);
        glVertex2f(-0.745f, 0.797f);
        glVertex2f(-0.756f, 0.825f);
        glVertex2f(-0.727f, 0.797f);
        glVertex2f(-0.736f, 0.829f);
        glVertex2f(-0.705f, 0.797f);
        glVertex2f(-0.714f, 0.829f);
        glVertex2f(-0.687f, 0.797f);
        glVertex2f(-0.692f, 0.821f);
        glVertex2f(-0.652f, 0.789f);
        glVertex2f(-0.665f, 0.817f);
        glVertex2f(-0.621f, 0.785f);
        glVertex2f(-0.667f, 0.849f);
        glVertex2f(-0.690f, 0.872f);
        glVertex2f(-0.738f, 0.892f);
        glVertex2f(-0.774f, 0.884f);
        glVertex2f(-0.801f, 0.868f);
        glVertex2f(-0.778f, 0.908f);
        glVertex2f(-0.794f, 0.908f);
        glVertex2f(-0.778f, 0.955f);
        glVertex2f(-0.818f, 0.912f);
        glVertex2f(-0.818f, 0.939f);
        glVertex2f(-0.836f, 0.884f);
        glVertex2f(-0.841f, 0.904f);
        glVertex2f(-0.843f, 0.852f);
        glVertex2f(-0.861f, 0.9f);
        glVertex2f(-0.885f, 0.935f);
        glVertex2f(-0.912f, 0.963f);
        glVertex2f(-0.947f, 0.979f);
        glVertex2f(-0.974f, 0.979f);
        glVertex2f(-1.003f, 0.971f);
        glVertex2f(-0.981f, 0.951f);
        glVertex2f(-0.994f, 0.935f);
        glVertex2f(-0.954f, 0.935f);
        glVertex2f(-0.967f, 0.916f);
        glVertex2f(-0.934f, 0.92f);
        glVertex2f(-0.954f, 0.896f);
        glVertex2f(-0.916f, 0.904f);
        glVertex2f(-0.934f, 0.884f);
        glVertex2f(-0.901f, 0.88f);
        glVertex2f(-0.914f, 0.872f);
        glVertex2f(-0.883f, 0.864f);
        glVertex2f(-0.896f, 0.856f);
        glVertex2f(-0.874f, 0.833f);
        glVertex2f(-0.925f, 0.852f);
        glVertex2f(-0.910f, 0.833f);
        glVertex2f(-0.947f, 0.829f);
        glVertex2f(-0.932f, 0.817f);
        glVertex2f(-0.998f, 0.766f);
        glVertex2f(-0.981f, 0.766f);
        glVertex2f(-0.992f, 0.647f);
        glVertex2f(-0.974f, 0.718f);
        glVertex2f(-0.970f, 0.69f);
        glVertex2f(-0.947f, 0.758f);
        glVertex2f(-0.945f, 0.73f);
        glVertex2f(-0.916f, 0.797f);
        glVertex2f(-0.918f, 0.758f);
        glVertex2f(-0.894f, 0.793f);
        glVertex2f(-0.925f, 0.722f);
        glVertex2f(-0.912f, 0.722f);
        glVertex2f(-0.930f, 0.647f);
        glVertex2f(-0.901f, 0.714f);
        glVertex2f(-0.894f, 0.686f);
        glVertex2f(-0.881f, 0.75f);
        glVertex2f(-0.876f, 0.726f);
        glEnd();

        // tree
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(121,75,25);
        glVertex2f(-0.850f, 0.675f);
        glVertex2f(-0.838f, 0.702f);
        glVertex2f(-0.830f, 0.706f);
        glVertex2f(-0.821f, 0.714f);
        glVertex2f(-0.816f, 0.73f);
        glVertex2f(-0.814f, 0.746f);
        glVertex2f(-0.814f, 0.758f);
        glVertex2f(-0.803f, 0.773f);
        glVertex2f(-0.801f, 0.789f);
        glVertex2f(-0.803f, 0.801f);
        glVertex2f(-0.807f, 0.817f);
        glVertex2f(-0.816f, 0.821f);
        glVertex2f(-0.825f, 0.825f);
        glVertex2f(-0.830f, 0.817f);
        glVertex2f(-0.832f, 0.809f);
        glVertex2f(-0.836f, 0.805f);
        glVertex2f(-0.845f, 0.817f);
        glVertex2f(-0.850f, 0.821f);
        glVertex2f(-0.856f, 0.817f);
        glVertex2f(-0.865f, 0.809f);
        glVertex2f(-0.870f, 0.797f);
        glVertex2f(-0.870f, 0.781f);
        glVertex2f(-0.870f, 0.766f);
        glVertex2f(-0.865f, 0.762f);
        glVertex2f(-0.861f, 0.758f);
        glVertex2f(-0.863f, 0.746f);
        glVertex2f(-0.861f, 0.726f);
        glVertex2f(-0.858f, 0.718f);
        glVertex2f(-0.872f, 0.69f);
        glVertex2f(-0.883f, 0.659f);
        glVertex2f(-0.894f, 0.627f);
        glVertex2f(-0.901f, 0.599f);
        glVertex2f(-0.912f, 0.556f);
        glVertex2f(-0.921f, 0.509f);
        glVertex2f(-0.927f, 0.453f);
        glVertex2f(-0.930f, 0.41f);
        glVertex2f(-0.930f, 0.366f);
        glVertex2f(-0.876f, 0.37f);
        glVertex2f(-0.881f, 0.414f);
        glVertex2f(-0.883f, 0.453f);
        glVertex2f(-0.883f, 0.509f);
        glVertex2f(-0.878f, 0.556f);
        glVertex2f(-0.872f, 0.596f);
        glVertex2f(-0.861f, 0.639f);
        glEnd();

        // desert
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255,218,156);
        glVertex2f(-0.296f, 0.291f);
        glVertex2f(-0.183f, 0.208f);
        glVertex2f(-0.083f, 0.157f);
        glVertex2f(0.019f, 0.09f);
        glVertex2f(0.266f, -0.1f);
        glVertex2f(0.493f, -0.29f);
        glVertex2f(0.382f, -0.298f);
        glVertex2f(0.715f, -0.574f);
        glVertex2f(0.524f, -0.582f);
        glVertex2f(1.002f, -0.97f);
        glVertex2f(1.004f, -1.005f);
        glVertex2f(-1.001f, -1.005f);
        glVertex2f(-1.003f, 0.343f);
        glVertex2f(-0.987f, 0.366f);
        glVertex2f(-0.967f, 0.382f);
        glVertex2f(-0.932f, 0.402f);
        glVertex2f(-0.903f, 0.402f);
        glVertex2f(-0.865f, 0.394f);
        glVertex2f(-0.830f, 0.394f);
        glVertex2f(-0.801f, 0.394f);
        glVertex2f(-0.754f, 0.394f);
        glVertex2f(-0.723f, 0.398f);
        glVertex2f(-0.681f, 0.414f);
        glVertex2f(-0.650f, 0.426f);
        glVertex2f(-0.618f, 0.433f);
        glVertex2f(-0.581f, 0.433f);
        glVertex2f(-0.554f, 0.426f);
        glVertex2f(-0.512f, 0.414f);
        glVertex2f(-0.474f, 0.398f);
        glVertex2f(-0.387f, 0.35f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(252,210,126);
        glVertex2f(-0.252f, 0.09f);
        glVertex2f(-0.258f, 0.109f);
        glVertex2f(-0.261f, 0.133f);
        glVertex2f(-0.258f, 0.161f);
        glVertex2f(-0.247f, 0.188f);
        glVertex2f(-0.232f, 0.208f);
        glVertex2f(-0.265f, 0.192f);
        glVertex2f(-0.290f, 0.173f);
        glVertex2f(-0.330f, 0.129f);
        glVertex2f(-0.476f, -0.033f);
        glVertex2f(-0.452f, 0.034f);
        glVertex2f(-0.447f, 0.066f);
        glVertex2f(-0.447f, 0.09f);
        glVertex2f(-0.452f, 0.113f);
        glVertex2f(-0.458f, 0.133f);
        glVertex2f(-0.472f, 0.161f);
        glVertex2f(-0.476f, 0.177f);
        glVertex2f(-0.612f, 0.43f);
        glVertex2f(-0.630f, 0.433f);
        glVertex2f(-0.661f, 0.43f);
        glVertex2f(-0.678f, 0.422f);
        glVertex2f(-0.694f, 0.418f);
        glVertex2f(-0.716f, 0.41f);
        glVertex2f(-0.745f, 0.402f);
        glVertex2f(-0.772f, 0.398f);
        glVertex2f(-0.798f, 0.398f);
        glVertex2f(-0.827f, 0.398f);
        glVertex2f(-0.856f, 0.402f);
        glVertex2f(-0.894f, 0.406f);
        glVertex2f(-0.918f, 0.41f);
        glVertex2f(-0.943f, 0.406f);
        glVertex2f(-0.967f, 0.394f);
        glVertex2f(-0.985f, 0.378f);
        glVertex2f(-1.001f, 0.362f);
        glVertex2f(-1.003f, 0.362f);
        glVertex2f(-1.001f, -1.005f);
        glVertex2f(0.015f, -0.997f);
        glVertex2f(0.053f, -0.97f);
        glVertex2f(0.093f, -0.93f);
        glVertex2f(0.117f, -0.891f);
        glVertex2f(0.133f, -0.855f);
        glVertex2f(0.148f, -0.804f);
        glVertex2f(0.155f, -0.76f);
        glVertex2f(0.153f, -0.725f);
        glVertex2f(0.146f, -0.693f);
        glVertex2f(0.128f, -0.646f);
        glVertex2f(0.104f, -0.602f);
        glVertex2f(0.079f, -0.57f);
        glVertex2f(0.057f, -0.543f);
        glVertex2f(0.013f, -0.487f);
        glVertex2f(-0.001f, -0.464f);
        glVertex2f(-0.007f, -0.44f);
        glVertex2f(-0.010f, -0.408f);
        glVertex2f(-0.007f, -0.373f);
        glVertex2f(0.002f, -0.341f);
        glVertex2f(0.017f, -0.314f);
        glVertex2f(0.033f, -0.302f);
        glVertex2f(0.048f, -0.298f);
        glVertex2f(-0.025f, -0.203f);
        glVertex2f(-0.034f, -0.191f);
        glVertex2f(-0.041f, -0.171f);
        glVertex2f(-0.041f, -0.148f);
        glVertex2f(-0.038f, -0.128f);
        glVertex2f(-0.032f, -0.104f);
        glVertex2f(-0.023f, -0.084f);
        glVertex2f(-0.012f, -0.072f);
        glVertex2f(-0.058f, -0.1f);
        glVertex2f(-0.085f, -0.124f);
        glVertex2f(-0.103f, -0.144f);
        glVertex2f(-0.158f, -0.207f);
        glVertex2f(-0.143f, -0.163f);
        glVertex2f(-0.138f, -0.124f);
        glVertex2f(-0.143f, -0.096f);
        glVertex2f(-0.147f, -0.072f);
        glVertex2f(-0.156f, -0.049f);
        glVertex2f(-0.172f, -0.017f);
        glVertex2f(-0.192f, 0.011f);
        glEnd();
    }

void CanonLeftOne()
    {
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(45,30,34);
        glVertex2f(-0.823f, 0.244f);
        glVertex2f(-0.814f, 0.271f);
        glVertex2f(-0.798f, 0.287f);
        glVertex2f(-0.781f, 0.291f);
        glVertex2f(-0.767f, 0.283f);
        glVertex2f(-0.752f, 0.271f);
        glVertex2f(-0.745f, 0.157f);
        glVertex2f(-0.774f, 0.149f);
        glVertex2f(-0.801f, 0.145f);
        glVertex2f(-0.816f, 0.165f);
        glVertex2f(-0.825f, 0.2f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(160,116,77);
        glVertex2f(-0.454f, 0.754f);
        glVertex2f(-0.485f, 0.702f);
        glVertex2f(-0.490f, 0.679f);
        glVertex2f(-0.485f, 0.627f);
        glVertex2f(-0.478f, 0.596f);
        glVertex2f(-0.490f, 0.69f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(42,28,28);
        glVertex2f(-0.767f, 0.157f);
        glVertex2f(-0.767f, 0.221f);
        glVertex2f(-0.760f, 0.256f);
        glVertex2f(-0.756f, 0.304f);
        glVertex2f(-0.756f, 0.304f);
        glVertex2f(-0.727f, 0.387f);
        glVertex2f(-0.687f, 0.462f);
        glVertex2f(-0.631f, 0.513f);
        glVertex2f(-0.578f, 0.529f);
        glVertex2f(-0.513f, 0.529f);
        glVertex2f(0.420f, 0.537f);
        glVertex2f(0.420f, -0.202f);
        glVertex2f(-0.582f, -0.202f);
        glVertex2f(-0.644f, -0.179f);
        glVertex2f(-0.664f, -0.167f);
        glVertex2f(-0.687f, -0.135f);
        glVertex2f(-0.724f, -0.076f);
        glVertex2f(-0.740f, -0.017f);
        glVertex2f(-0.758f, 0.039f);
        glVertex2f(-0.762f, 0.094f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(67,45,47);
        glVertex2f(-0.162f, 0.232f);
        glVertex2f(-0.256f, 0.24f);
        glVertex2f(-0.340f, 0.252f);
        glVertex2f(-0.473f, 0.28f);
        glVertex2f(-0.589f, 0.319f);
        glVertex2f(-0.673f, 0.359f);
        glVertex2f(-0.722f, 0.406f);
        glVertex2f(-0.696f, 0.442f);
        glVertex2f(-0.660f, 0.489f);
        glVertex2f(-0.616f, 0.513f);
        glVertex2f(-0.567f, 0.529f);
        glVertex2f(0.424f, 0.529f);
        glVertex2f(0.398f, 0.493f);
        glVertex2f(0.367f, 0.418f);
        glVertex2f(0.340f, 0.343f);
        glVertex2f(0.333f, 0.28f);
        glVertex2f(0.324f, 0.256f);
        glVertex2f(0.224f, 0.24f);
        glVertex2f(0.093f, 0.232f);
        glVertex2f(-0.033f, 0.232f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(67,45,47);
        glVertex2f(0.349f, 0.252f);
        glVertex2f(0.360f, 0.355f);
        glVertex2f(0.373f, 0.426f);
        glVertex2f(0.391f, 0.477f);
        glVertex2f(0.411f, 0.525f);
        glVertex2f(0.431f, 0.549f);
        glVertex2f(0.458f, 0.572f);
        glVertex2f(0.496f, 0.584f);
        glVertex2f(0.522f, 0.572f);
        glVertex2f(0.549f, 0.545f);
        glVertex2f(0.576f, 0.489f);
        glVertex2f(0.598f, 0.426f);
        glVertex2f(0.613f, 0.323f);
        glVertex2f(0.618f, 0.185f);
        glVertex2f(0.618f, 0.062f);
        glVertex2f(0.607f, -0.044f);
        glVertex2f(0.587f, -0.147f);
        glVertex2f(0.553f, -0.222f);
        glVertex2f(0.509f, -0.246f);
        glVertex2f(0.473f, -0.246f);
        glVertex2f(0.447f, -0.234f);
        glVertex2f(0.409f, -0.191f);
        glVertex2f(0.382f, -0.127f);
        glVertex2f(0.353f, -0.017f);
        glVertex2f(0.340f, 0.145f);
        glVertex2f(0.340f, 0.193f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(30,20,21);
        glVertex2f(0.407f, 0.169f);
        glVertex2f(0.407f, 0.232f);
        glVertex2f(0.413f, 0.319f);
        glVertex2f(0.429f, 0.422f);
        glVertex2f(0.456f, 0.489f);
        glVertex2f(0.484f, 0.509f);
        glVertex2f(0.518f, 0.513f);
        glVertex2f(0.538f, 0.497f);
        glVertex2f(0.558f, 0.45f);
        glVertex2f(0.571f, 0.394f);
        glVertex2f(0.584f, 0.315f);
        glVertex2f(0.589f, 0.205f);
        glVertex2f(0.591f, 0.098f);
        glVertex2f(0.584f, 0.019f);
        glVertex2f(0.573f, -0.072f);
        glVertex2f(0.560f, -0.123f);
        glVertex2f(0.536f, -0.167f);
        glVertex2f(0.509f, -0.187f);
        glVertex2f(0.484f, -0.187f);
        glVertex2f(0.460f, -0.163f);
        glVertex2f(0.444f, -0.127f);
        glVertex2f(0.433f, -0.092f);
        glVertex2f(0.424f, -0.06f);
        glVertex2f(0.413f, 0.003f);
        glVertex2f(0.411f, 0.062f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(46,32,32);
        glVertex2f(0.447f, 0.118f);
        glVertex2f(0.478f, 0.185f);
        glVertex2f(0.509f, 0.236f);
        glVertex2f(0.544f, 0.288f);
        glVertex2f(0.573f, 0.319f);
        glVertex2f(0.580f, 0.331f);
        glVertex2f(0.587f, 0.236f);
        glVertex2f(0.587f, 0.161f);
        glVertex2f(0.587f, 0.078f);
        glVertex2f(0.580f, -0.009f);
        glVertex2f(0.564f, -0.092f);
        glVertex2f(0.549f, -0.147f);
        glVertex2f(0.527f, -0.191f);
        glVertex2f(0.487f, -0.187f);
        glVertex2f(0.467f, -0.175f);
        glVertex2f(0.451f, -0.143f);
        glVertex2f(0.438f, -0.108f);
        glVertex2f(0.424f, -0.06f);
        glVertex2f(0.411f, -0.001f);
        glVertex2f(0.411f, 0.035f);
        glVertex2f(0.411f, 0.043f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(42,28,26);
        glVertex2f(-0.436f, 0.6f);
        glVertex2f(-0.540f, 0.6f);
        glVertex2f(-0.558f, 0.572f);
        glVertex2f(-0.558f, 0.533f);
        glVertex2f(-0.416f, 0.533f);
        glVertex2f(-0.416f, 0.568f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(211,153,90);
        glVertex2f(-0.416f, -0.088f);
        glVertex2f(0.187f, -0.092f);
        glVertex2f(0.193f, -0.127f);
        glVertex2f(0.207f, -0.159f);
        glVertex2f(0.220f, -0.183f);
        glVertex2f(0.260f, -0.206f);
        glVertex2f(0.293f, -0.202f);
        glVertex2f(0.356f, -0.202f);
        glVertex2f(0.351f, -0.238f);
        glVertex2f(0.242f, -0.238f);
        glVertex2f(0.224f, -0.238f);
        glVertex2f(0.207f, -0.218f);
        glVertex2f(0.191f, -0.191f);
        glVertex2f(0.187f, -0.171f);
        glVertex2f(0.180f, -0.135f);
        glVertex2f(-0.958f, -0.775f);
        glVertex2f(-0.987f, -0.748f);
        glVertex2f(-0.993f, -0.712f);
        glVertex2f(-0.993f, -0.665f);
        glVertex2f(-0.993f, -0.617f);
        glVertex2f(-0.980f, -0.586f);
        glVertex2f(-0.958f, -0.562f);
        glVertex2f(-0.916f, -0.558f);
        glVertex2f(-0.880f, -0.542f);
        glVertex2f(-0.842f, -0.523f);
        glVertex2f(-0.796f, -0.463f);
        glVertex2f(-0.747f, -0.388f);
        glVertex2f(-0.702f, -0.325f);
        glVertex2f(-0.647f, -0.258f);
        glVertex2f(-0.598f, -0.214f);
        glVertex2f(-0.522f, -0.159f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(45,30,34);
        glVertex2f(0.368f, -0.65f);
        glVertex2f(0.342f, -0.709f);
        glVertex2f(0.313f, -0.744f);
        glVertex2f(0.266f, -0.768f);
        glVertex2f(0.233f, -0.764f);
        glVertex2f(0.222f, -0.76f);
        glVertex2f(0.350f, -0.349f);
        glVertex2f(0.368f, -0.389f);
        glVertex2f(0.382f, -0.44f);
        glVertex2f(0.388f, -0.511f);
        glVertex2f(0.384f, -0.582f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(127,44,38);
        glVertex2f(-0.238f, -0.772f);
        glVertex2f(-0.956f, -0.772f);
        glVertex2f(-0.969f, -0.728f);
        glVertex2f(-0.973f, -0.685f);
        glVertex2f(-0.967f, -0.625f);
        glVertex2f(-0.958f, -0.598f);
        glVertex2f(-0.938f, -0.582f);
        glVertex2f(-0.904f, -0.574f);
        glVertex2f(-0.876f, -0.57f);
        glVertex2f(-0.838f, -0.55f);
        glVertex2f(-0.796f, -0.507f);
        glVertex2f(-0.753f, -0.443f);
        glVertex2f(-0.716f, -0.384f);
        glVertex2f(-0.667f, -0.317f);
        glVertex2f(-0.620f, -0.27f);
        glVertex2f(-0.576f, -0.222f);
        glVertex2f(-0.527f, -0.191f);
        glVertex2f(-0.469f, -0.159f);
        glVertex2f(-0.413f, -0.147f);
        glVertex2f(0.176f, -0.143f);
        glVertex2f(0.184f, -0.175f);
        glVertex2f(0.196f, -0.198f);
        glVertex2f(0.209f, -0.222f);
        glVertex2f(0.227f, -0.234f);
        glVertex2f(0.264f, -0.242f);
        glVertex2f(0.351f, -0.242f);
        glVertex2f(0.351f, -0.665f);
        glVertex2f(0.269f, -0.665f);
        glVertex2f(0.260f, -0.712f);
        glVertex2f(0.242f, -0.74f);
        glVertex2f(0.231f, -0.768f);
        glVertex2f(-0.104f, -0.768f);
        glVertex2f(-0.124f, -0.76f);
        glVertex2f(-0.142f, -0.736f);
        glVertex2f(-0.149f, -0.704f);
        glVertex2f(-0.187f, -0.744f);
        glVertex2f(-0.207f, -0.76f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(186,71,62);
        glVertex2f(0.250f, -0.246f);
        glVertex2f(0.350f, -0.246f);
        glVertex2f(0.353f, -0.669f);
        glVertex2f(0.177f, -0.665f);
        glVertex2f(0.179f, -0.167f);
        glVertex2f(0.190f, -0.207f);
        glVertex2f(0.206f, -0.227f);
        glVertex2f(0.224f, -0.246f);
        glEnd();

        glBegin(GL_LINES);
        glLineWidth(3);
        glColor3ub(104,36,33);
        glVertex2f(-0.669f, -0.32f);
        glVertex2f(0.349f, -0.32f);

        glVertex2f(-0.782f, -0.49f);
        glVertex2f(0.349f, -0.498f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(50,32,33);
        glVertex2f(-0.594f, -0.539f);
        glVertex2f(-0.592f, -0.472f);
        glVertex2f(-0.583f, -0.412f);
        glVertex2f(-0.563f, -0.357f);
        glVertex2f(-0.536f, -0.31f);
        glVertex2f(-0.496f, -0.274f);
        glVertex2f(-0.454f, -0.262f);
        glVertex2f(-0.412f, -0.278f);
        glVertex2f(-0.370f, -0.321f);
        glVertex2f(-0.341f, -0.381f);
        glVertex2f(-0.323f, -0.444f);
        glVertex2f(-0.318f, -0.531f);
        glVertex2f(-0.330f, -0.614f);
        glVertex2f(-0.352f, -0.673f);
        glVertex2f(-0.381f, -0.725f);
        glVertex2f(-0.423f, -0.764f);
        glVertex2f(-0.465f, -0.776f);
        glVertex2f(-0.501f, -0.764f);
        glVertex2f(-0.541f, -0.725f);
        glVertex2f(-0.570f, -0.677f);
        glVertex2f(-0.587f, -0.606f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(28,17,17);
        glVertex2f(-0.563f, -0.598f);
        glVertex2f(-0.572f, -0.527f);
        glVertex2f(-0.567f, -0.464f);
        glVertex2f(-0.552f, -0.397f);
        glVertex2f(-0.523f, -0.349f);
        glVertex2f(-0.490f, -0.325f);
        glVertex2f(-0.443f, -0.325f);
        glVertex2f(-0.403f, -0.369f);
        glVertex2f(-0.381f, -0.428f);
        glVertex2f(-0.370f, -0.511f);
        glVertex2f(-0.376f, -0.59f);
        glVertex2f(-0.396f, -0.653f);
        glVertex2f(-0.425f, -0.697f);
        glVertex2f(-0.463f, -0.717f);
        glVertex2f(-0.496f, -0.713f);
        glVertex2f(-0.523f, -0.689f);
        glVertex2f(-0.547f, -0.65f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(71,50,49);
        glVertex2f(-0.512f, -0.555f);
        glVertex2f(-0.516f, -0.527f);
        glVertex2f(-0.512f, -0.484f);
        glVertex2f(-0.498f, -0.448f);
        glVertex2f(-0.483f, -0.432f);
        glVertex2f(-0.465f, -0.428f);
        glVertex2f(-0.445f, -0.444f);
        glVertex2f(-0.427f, -0.487f);
        glVertex2f(-0.425f, -0.539f);
        glVertex2f(-0.436f, -0.578f);
        glVertex2f(-0.452f, -0.598f);
        glVertex2f(-0.476f, -0.606f);
        glVertex2f(-0.492f, -0.598f);
        glVertex2f(-0.503f, -0.582f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(51,30,32);
        glVertex2f(-0.116f, -0.539f);
        glVertex2f(-0.116f, -0.48f);
        glVertex2f(-0.110f, -0.432f);
        glVertex2f(-0.107f, -0.428f);
        glVertex2f(-0.098f, -0.385f);
        glVertex2f(-0.078f, -0.341f);
        glVertex2f(-0.050f, -0.298f);
        glVertex2f(-0.010f, -0.274f);
        glVertex2f(0.030f, -0.266f);
        glVertex2f(0.077f, -0.29f);
        glVertex2f(0.113f, -0.333f);
        glVertex2f(0.137f, -0.389f);
        glVertex2f(0.153f, -0.468f);
        glVertex2f(0.155f, -0.543f);
        glVertex2f(0.142f, -0.634f);
        glVertex2f(0.122f, -0.689f);
        glVertex2f(0.095f, -0.729f);
        glVertex2f(0.055f, -0.764f);
        glVertex2f(0.017f, -0.768f);
        glVertex2f(-0.030f, -0.756f);
        glVertex2f(-0.058f, -0.725f);
        glVertex2f(-0.081f, -0.689f);
        glVertex2f(-0.098f, -0.646f);
        glVertex2f(-0.112f, -0.59f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(37,27,27);
        glVertex2f(-0.081f, -0.491f);
        glVertex2f(-0.072f, -0.436f);
        glVertex2f(-0.054f, -0.385f);
        glVertex2f(-0.030f, -0.349f);
        glVertex2f(-0.003f, -0.333f);
        glVertex2f(0.030f, -0.329f);
        glVertex2f(0.062f, -0.365f);
        glVertex2f(0.084f, -0.416f);
        glVertex2f(0.099f, -0.472f);
        glVertex2f(0.099f, -0.551f);
        glVertex2f(0.090f, -0.61f);
        glVertex2f(0.070f, -0.665f);
        glVertex2f(0.044f, -0.705f);
        glVertex2f(0.010f, -0.721f);
        glVertex2f(-0.023f, -0.709f);
        glVertex2f(-0.050f, -0.681f);
        glVertex2f(-0.070f, -0.638f);
        glVertex2f(-0.078f, -0.594f);
        glVertex2f(-0.083f, -0.539f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(71,50,49);
        glVertex2f(-0.036f, -0.503f);
        glVertex2f(-0.025f, -0.456f);
        glVertex2f(-0.005f, -0.436f);
        glVertex2f(0.013f, -0.432f);
        glVertex2f(0.037f, -0.452f);
        glVertex2f(0.048f, -0.495f);
        glVertex2f(0.048f, -0.547f);
        glVertex2f(0.033f, -0.586f);
        glVertex2f(0.013f, -0.606f);
        glVertex2f(-0.012f, -0.602f);
        glVertex2f(-0.027f, -0.582f);
        glVertex2f(-0.036f, -0.547f);
        glVertex2f(-0.041f, -0.515f);
        glEnd();

    }

void CanonLeftTwo()
    {
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(122,60,36);
        glVertex2f(-0.267f, -0.78f);
        glVertex2f(-0.181f, -0.452f);
        glVertex2f(-0.430f, -0.203f);
        glVertex2f(-0.641f, -0.78f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,91,62);
        glVertex2f(-0.707f, -0.768f);
        glVertex2f(-0.234f, -0.768f);
        glVertex2f(-0.214f, -0.788f);
        glVertex2f(-0.203f, -0.816f);
        glVertex2f(-0.198f, -0.847f);
        glVertex2f(-0.201f, -0.883f);
        glVertex2f(-0.210f, -0.906f);
        glVertex2f(-0.223f, -0.926f);
        glVertex2f(-0.241f, -0.938f);
        glVertex2f(-0.710f, -0.938f);
        glVertex2f(-0.725f, -0.926f);
        glVertex2f(-0.738f, -0.902f);
        glVertex2f(-0.738f, -0.902f);
        glVertex2f(-0.745f, -0.867f);
        glVertex2f(-0.745f, -0.831f);
        glVertex2f(-0.736f, -0.796f);
        glVertex2f(-0.723f, -0.776f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(42,43,44);
        glVertex2f(-0.465f, 0.105f);
        glVertex2f(-0.461f, 0.165f);
        glVertex2f(-0.450f, 0.228f);
        glVertex2f(-0.434f, 0.291f);
        glVertex2f(-0.414f, 0.354f);
        glVertex2f(-0.381f, 0.433f);
        glVertex2f(-0.336f, 0.501f);
        glVertex2f(-0.303f, 0.536f);
        glVertex2f(-0.274f, 0.556f);
        glVertex2f(-0.194f, 0.588f);
        glVertex2f(0.495f, 0.864f);
        glVertex2f(0.615f, 0.335f);
        glVertex2f(-0.072f, -0.44f);
        glVertex2f(-0.107f, -0.46f);
        glVertex2f(-0.152f, -0.464f);
        glVertex2f(-0.190f, -0.46f);
        glVertex2f(-0.241f, -0.436f);
        glVertex2f(-0.307f, -0.385f);
        glVertex2f(-0.356f, -0.333f);
        glVertex2f(-0.387f, -0.29f);
        glVertex2f(-0.425f, -0.211f);
        glVertex2f(-0.458f, -0.065f);
        glVertex2f(-0.467f, 0.022f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(-0.183f, -0.017f);
        glVertex2f(-0.232f, -0.013f);
        glVertex2f(-0.274f, -0.001f);
        glVertex2f(-0.314f, 0.015f);
        glVertex2f(-0.356f, 0.042f);
        glVertex2f(-0.394f, 0.07f);
        glVertex2f(-0.427f, 0.109f);
        glVertex2f(-0.461f, 0.157f);
        glVertex2f(-0.467f, 0.078f);
        glVertex2f(-0.465f, -0.005f);
        glVertex2f(-0.458f, -0.068f);
        glVertex2f(-0.427f, -0.203f);
        glVertex2f(-0.387f, -0.294f);
        glVertex2f(-0.354f, -0.345f);
        glVertex2f(-0.321f, -0.381f);
        glVertex2f(-0.283f, -0.412f);
        glVertex2f(-0.236f, -0.444f);
        glVertex2f(-0.176f, -0.46f);
        glVertex2f(-0.147f, -0.464f);
        glVertex2f(-0.114f, -0.46f);
        glVertex2f(-0.078f, -0.44f);
        glVertex2f(0.086f, -0.262f);
        glVertex2f(0.615f, 0.335f);
        glVertex2f(0.570f, 0.536f);
        glVertex2f(0.077f, 0.105f);
        glVertex2f(-0.143f, -0.017f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,90,62);
        glVertex2f(0.330f, 0.825f);
        glVertex2f(0.482f, 0.157f);
        glVertex2f(0.419f, 0.086f);
        glVertex2f(0.262f, 0.793f);
        glVertex2f(0.264f, 0.793f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,90,62);
        glVertex2f(0.593f, 0.939f);
        glVertex2f(0.715f, 0.41f);
        glVertex2f(0.622f, 0.315f);
        glVertex2f(0.488f, 0.892f);
        glVertex2f(0.488f, 0.888f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(154,91,62);
        glVertex2f(0.130f, 0.113f);
        glVertex2f(0.177f, 0.09f);
        glVertex2f(0.215f, 0.058f);
        glVertex2f(0.250f, 0.015f);
        glVertex2f(0.286f, -0.045f);
        glVertex2f(0.313f, -0.108f);
        glVertex2f(0.333f, -0.167f);
        glVertex2f(0.350f, -0.246f);
        glVertex2f(0.364f, -0.361f);
        glVertex2f(0.364f, -0.452f);
        glVertex2f(0.355f, -0.543f);
        glVertex2f(0.335f, -0.634f);
        glVertex2f(0.306f, -0.717f);
        glVertex2f(0.273f, -0.788f);
        glVertex2f(0.237f, -0.839f);
        glVertex2f(0.186f, -0.891f);
        glVertex2f(0.128f, -0.926f);
        glVertex2f(0.062f, -0.938f);
        glVertex2f(0.010f, -0.93f);
        glVertex2f(-0.047f, -0.902f);
        glVertex2f(-0.101f, -0.855f);
        glVertex2f(-0.145f, -0.792f);
        glVertex2f(-0.183f, -0.713f);
        glVertex2f(-0.210f, -0.63f);
        glVertex2f(-0.227f, -0.543f);
        glVertex2f(-0.238f, -0.44f);
        glVertex2f(-0.238f, -0.381f);
        glVertex2f(-0.232f, -0.29f);
        glVertex2f(-0.218f, -0.223f);
        glVertex2f(-0.201f, -0.148f);
        glVertex2f(-0.165f, -0.057f);
        glVertex2f(-0.125f, 0.015f);
        glVertex2f(-0.072f, 0.074f);
        glVertex2f(-0.023f, 0.109f);
        glVertex2f(0.026f, 0.125f);
        glVertex2f(0.082f, 0.129f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(-0.041f, -0.017f);
        glVertex2f(-0.014f, 0.003f);
        glVertex2f(0.019f, 0.018f);
        glVertex2f(0.042f, 0.022f);
        glVertex2f(0.042f, -0.262f);
        glVertex2f(0.022f, -0.274f);
        glVertex2f(-0.090f, -0.076f);
        glVertex2f(-0.065f, -0.041f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.150f, -0.005f);
        glVertex2f(0.177f, -0.025f);
        glVertex2f(0.199f, -0.053f);
        glVertex2f(0.219f, -0.076f);
        glVertex2f(0.106f, -0.278f);
        glVertex2f(0.086f, -0.262f);
        glVertex2f(0.086f, 0.022f);
        glVertex2f(0.124f, 0.011f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.286f, -0.234f);
        glVertex2f(0.295f, -0.274f);
        glVertex2f(0.302f, -0.318f);
        glVertex2f(0.306f, -0.369f);
        glVertex2f(0.144f, -0.369f);
        glVertex2f(0.137f, -0.333f);
        glVertex2f(0.248f, -0.128f);
        glVertex2f(0.264f, -0.159f);
        glVertex2f(0.275f, -0.191f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.293f, -0.551f);
        glVertex2f(0.279f, -0.606f);
        glVertex2f(0.266f, -0.646f);
        glVertex2f(0.248f, -0.681f);
        glVertex2f(0.135f, -0.484f);
        glVertex2f(0.146f, -0.444f);
        glVertex2f(0.306f, -0.444f);
        glVertex2f(0.299f, -0.503f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(0.166f, -0.796f);
        glVertex2f(0.137f, -0.816f);
        glVertex2f(0.110f, -0.831f);
        glVertex2f(0.084f, -0.835f);
        glVertex2f(0.084f, -0.547f);
        glVertex2f(0.108f, -0.535f);
        glVertex2f(0.219f, -0.736f);
        glVertex2f(0.195f, -0.768f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(-0.025f, -0.812f);
        glVertex2f(-0.054f, -0.788f);
        glVertex2f(-0.078f, -0.76f);
        glVertex2f(-0.094f, -0.736f);
        glVertex2f(0.022f, -0.531f);
        glVertex2f(0.044f, -0.547f);
        glVertex2f(0.042f, -0.835f);
        glVertex2f(0.010f, -0.827f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(-0.163f, -0.563f);
        glVertex2f(-0.172f, -0.519f);
        glVertex2f(-0.176f, -0.491f);
        glVertex2f(-0.178f, -0.44f);
        glVertex2f(-0.016f, -0.44f);
        glVertex2f(-0.007f, -0.48f);
        glVertex2f(-0.123f, -0.685f);
        glVertex2f(-0.141f, -0.642f);
        glVertex2f(-0.154f, -0.602f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
        glVertex2f(-0.163f, -0.25f);
        glVertex2f(-0.147f, -0.195f);
        glVertex2f(-0.134f, -0.155f);
        glVertex2f(-0.123f, -0.132f);
        glVertex2f(-0.010f, -0.333f);
        glVertex2f(-0.018f, -0.365f);
        glVertex2f(-0.178f, -0.369f);
        glVertex2f(-0.174f, -0.306f);
        glEnd();
    }

void Temple()
    {
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(198,161,80);
        glVertex2f(0.219f, 0.228f);
        glVertex2f(0.204f, 0.208f);
        glVertex2f(0.182f, 0.192f);
        glVertex2f(0.157f, 0.181f);
        glVertex2f(0.133f, 0.173f);
        glVertex2f(0.106f, 0.173f);
        glVertex2f(0.048f, 0.173f);
        glVertex2f(0.048f, 0.153f);
        glVertex2f(0.322f, 0.153f);
        glVertex2f(0.317f, 0.184f);
        glVertex2f(0.308f, 0.22f);
        glVertex2f(0.297f, 0.252f);
        glVertex2f(0.279f, 0.283f);
        glVertex2f(0.262f, 0.311f);
        glVertex2f(0.242f, 0.331f);
        glVertex2f(0.222f, 0.347f);
        glVertex2f(0.199f, 0.354f);
        glVertex2f(0.213f, 0.335f);
        glVertex2f(0.219f, 0.315f);
        glVertex2f(0.228f, 0.283f);
        glVertex2f(0.228f, 0.252f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(196,109,86);
        glVertex2f(-0.336f, 0.418f);
        glVertex2f(-0.336f, 0.287f);
        glVertex2f(-0.543f, 0.287f);
        glVertex2f(-0.543f, 0.418f);
        glVertex2f(-0.567f, 0.418f);
        glVertex2f(-0.567f, 0.433f);
        glVertex2f(-0.307f, 0.433f);
        glVertex2f(-0.307f, 0.418f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(219,193,122);
        glVertex2f(0.104f, 0.307f);
        glVertex2f(0.124f, 0.327f);
        glVertex2f(0.148f, 0.343f);
        glVertex2f(0.173f, 0.35f);
        glVertex2f(0.204f, 0.358f);
        glVertex2f(0.235f, 0.343f);
        glVertex2f(0.259f, 0.149f);
        glVertex2f(0.048f, 0.145f);
        glVertex2f(0.048f, 0.165f);
        glVertex2f(0.053f, 0.196f);
        glVertex2f(0.066f, 0.24f);
        glVertex2f(0.084f, 0.275f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(222,193,123);
        glVertex2f(0.004f, 0.149f);
        glVertex2f(0.190f, 0.153f);
        glVertex2f(0.190f, 0.082f);
        glVertex2f(0.004f, 0.078f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(173,115,74);
        glVertex2f(0.193f, 0.078f);
        glVertex2f(0.364f, 0.078f);
        glVertex2f(0.364f, 0.153f);
        glVertex2f(0.190f, 0.153f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(240,220,161);
        glVertex2f(-0.392f, 0.145f);
        glVertex2f(-0.392f, 0.283f);
        glVertex2f(-0.332f, 0.283f);
        glVertex2f(-0.332f, 0.149f);
        glVertex2f(-0.294f, 0.149f);
        glVertex2f(-0.294f, 0.283f);
        glVertex2f(-0.223f, 0.287f);
        glVertex2f(-0.223f, -0.744f);
        glVertex2f(-0.587f, -0.74f);
        glVertex2f(-0.585f, 0.283f);
        glVertex2f(-0.530f, 0.283f);
        glVertex2f(-0.530f, 0.145f);
        glVertex2f(-0.490f, 0.145f);
        glVertex2f(-0.490f, 0.283f);
        glVertex2f(-0.432f, 0.283f);
        glVertex2f(-0.432f, 0.145f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(213,161,114);
        glVertex2f(-0.161f, 0.204f);
        glVertex2f(-0.161f, 0.287f);
        glVertex2f(-0.110f, 0.283f);
        glVertex2f(-0.110f, 0.208f);
        glVertex2f(-0.090f, 0.208f);
        glVertex2f(-0.090f, 0.287f);
        glVertex2f(-0.036f, 0.287f);
        glVertex2f(-0.038f, -0.744f);
        glVertex2f(-0.232f, -0.74f);
        glVertex2f(-0.232f, 0.279f);
        glVertex2f(-0.181f, 0.279f);
        glVertex2f(-0.181f, 0.204f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(240,219,161);
        glVertex2f(0.255f, 0.082f);
        glVertex2f(0.257f, -0.74f);
        glVertex2f(-0.076f, -0.744f);
        glVertex2f(-0.078f, 0.082f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(213,161,114);
        glVertex2f(0.255f, -0.736f);
        glVertex2f(0.255f, 0.078f);
        glVertex2f(0.413f, 0.078f);
        glVertex2f(0.413f, -0.74f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(219,193,122);
        glVertex2f(0.104f, 0.307f);
        glVertex2f(0.124f, 0.327f);
        glVertex2f(0.148f, 0.343f);
        glVertex2f(0.173f, 0.35f);
        glVertex2f(0.204f, 0.358f);
        glVertex2f(0.235f, 0.343f);
        glVertex2f(0.259f, 0.149f);
        glVertex2f(0.048f, 0.145f);
        glVertex2f(0.048f, 0.165f);
        glVertex2f(0.053f, 0.196f);
        glVertex2f(0.066f, 0.24f);
        glVertex2f(0.084f, 0.275f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(219,193,122);
        glVertex2f(0.104f, 0.307f);
        glVertex2f(0.124f, 0.327f);
        glVertex2f(0.148f, 0.343f);
        glVertex2f(0.173f, 0.35f);
        glVertex2f(0.204f, 0.358f);
        glVertex2f(0.235f, 0.343f);
        glVertex2f(0.259f, 0.149f);
        glVertex2f(0.048f, 0.145f);
        glVertex2f(0.048f, 0.165f);
        glVertex2f(0.053f, 0.196f);
        glVertex2f(0.066f, 0.24f);
        glVertex2f(0.084f, 0.275f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(-0.296f, -0.744f);
        glVertex2f(-0.372f, -0.744f);
        glVertex2f(-0.372, -0.444f);
        glVertex2f(-0.296f, -0.444f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(-0.525f, -0.361f);
        glVertex2f(-0.492f, -0.361f);
        glVertex2f(-0.492f, -0.503f);
        glVertex2f(-0.525f, -0.503f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(-0.445f, -0.171f);
        glVertex2f(-0.412f, -0.171f);
        glVertex2f(-0.412f, -0.31f);
        glVertex2f(-0.445f, -0.31f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(-0.527f, -0.041f);
        glVertex2f(-0.490f, -0.041f);
        glVertex2f(-0.490f, -0.183f);
        glVertex2f(-0.527f, -0.183f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(-0.165f, -0.061f);
        glVertex2f(-0.127f, -0.061f);
        glVertex2f(-0.127f, -0.199f);
        glVertex2f(-0.165f, -0.199f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(-0.165f, -0.337f);
        glVertex2f(-0.130f, -0.337f);
        glVertex2f(-0.130f, -0.472f);
        glVertex2f(-0.165f, -0.472f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(0.070f, -0.128f);
        glVertex2f(0.070f, -0.258f);
        glVertex2f(-0.041f, -0.258f);
        glVertex2f(-0.041f, -0.128f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(0.037f, -0.412f);
        glVertex2f(0.070f, -0.412f);
        glVertex2f(0.070f, -0.551f);
        glVertex2f(0.037f, -0.551f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(0.115f, -0.744f);
        glVertex2f(0.115f, -0.448f);
        glVertex2f(0.190f, -0.448f);
        glVertex2f(0.190f, -0.748f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(0.279f, -0.148f);
        glVertex2f(0.279f, -0.278f);
        glVertex2f(0.322f, -0.278f);
        glVertex2f(0.322f, -0.144f);
        glVertex2f(0.302f, -0.112f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(109,82,65);
        glVertex2f(0.344f, -0.151f);
        glVertex2f(0.364f, -0.112f);
        glVertex2f(0.384f, -0.151f);
        glVertex2f(0.384f, -0.282f);
        glVertex2f(0.344f, -0.282f);
        glEnd();
    }

void translateCanon(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
}
void scaleCanon(float trans_X, float trans_Y, float trans_Z)
{
    glScalef(trans_X, trans_Y, trans_Z);
    CanonLeftOne();
    glTranslated(0,1.5,0);
    CanonLeftOne();
    glTranslated(0,-3,0);
    CanonLeftOne();
}

void translateCanonTwo(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
}
void scaleCanonTwo(float trans_X, float trans_Y, float trans_Z)
{
    glScalef(trans_X, trans_Y, trans_Z);
    CanonLeftTwo();
    glTranslated(0,2,0);
    CanonLeftTwo();
}

void translateDesertTemple(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
}
void scaleDesertTemple(float trans_X, float trans_Y, float trans_Z)
{

    glScalef(trans_X, trans_Y, trans_Z);
    Temple();
}

void translatePiretBoat(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
}
void scalePiretBoat(float trans_X, float trans_Y, float trans_Z)
{

    glScalef(trans_X, trans_Y, trans_Z);
    Boat();
    glTranslated(1,-1,0);
    Boat();
}


void SunFor1()
{

    glPushMatrix();
    glTranslatef(0.0f, position, 0.0f);
    // Sun
    GLfloat p1 = 0.73f;
    GLfloat q1 = 0.80f;
    GLfloat r1 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 0);
    glVertex2f(p1, q1);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p1 + (r1 * (0.7) * cos(i * tp2 / triangle2)),
            q1 + (r1 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    glPopMatrix();
}

void Road()
{
    // Road
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 0.1f);
    glEnd();

    // RoadLines
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, 0.07f);
    glVertex2f(1.0f, 0.07f);
    glEnd();
}

void YellowLand()
{
    // Yellow Land-1
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.2f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.55f, -0.1f);
    glVertex2f(-0.55f, 0.0f);
    glEnd();

    // Yellow Land-2
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.2f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
}

void Water()
{
    // WaterLines
    glPushMatrix();
    glTranslatef(-positionwater, 0.0f, 0.0f);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.7f, -0.31f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.26f, -0.38f);
    glVertex2f(-0.15f, -0.37f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.1f, -0.25f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.7f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.4f, -0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.45f);
    glVertex2f(0.4f, -0.45f);
    glEnd();

    glPopMatrix();
}

// for -1
void Cloud()
{
    // Cloud-1
    glPushMatrix();
    glTranslatef(-positioncloud, 0.0f, 0.0f);

    // Cloud-1 Middle
    GLfloat p2 = -0.2f;
    GLfloat q2 = 0.8f;
    GLfloat r2 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p2, q2);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p2 + (r2 * cos(i * tp2 / triangle2)),
            q2 + (r2 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Cloud-1 Left

    GLfloat p3 = -0.28f;
    GLfloat q3 = 0.8f;
    GLfloat r3 = 0.06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p3, q3);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p3 + (r3 * cos(i * tp2 / triangle2)),
            q3 + (r3 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Cloud-1 Right

    GLfloat p4 = -0.18f;
    GLfloat q4 = 0.8f;
    GLfloat r4 = 0.06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p4, q4);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p4 + (r4 + 0.05 * cos(i * tp2 / triangle2)),
            q4 + (r4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(positioncloud, 0.0f, 0.0f);

    // Cloud-2 Middle

    GLfloat p5 = -0.6f;
    GLfloat q5 = 0.4f;
    GLfloat r5 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p5, q5);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p5 + (r5 * cos(i * tp2 / triangle2)),
            q5 + (r5 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Cloud-2 Left

    GLfloat p6 = -0.70f;
    GLfloat q6 = 0.4f;
    GLfloat r6 = 0.06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p6, q6);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p6 + (r6 * cos(i * tp2 / triangle2)),
            q6 + (r6 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Cloud-2 Right

    GLfloat p7 = -0.58f;
    GLfloat q7 = 0.4f;
    GLfloat r7 = 0.06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p7, q7);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p7 + (r7 + 0.06 * cos(i * tp2 / triangle2)),
            q7 + (r7 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    glPopMatrix();
}

void GreenLand()
{
    // Green Land
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.6f);
    glEnd();
}

void River()
{

    // River
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 0.9f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 0.9f);
    glVertex2f(-0.55f, 0.0f);
    glVertex2f(-0.55f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.2f, 0.0f);
    glEnd();
}

void Sky()
{
    // Sky
    glBegin(GL_QUADS);
    glBegin(GL_QUADS);
    if (positionSun <= 0.001)
    {
        glColor3ub(235, 230, 183);
    }
    else if (positionSun > 0.05 && positionSun < 0.8)
    {
        glColor3ub(132, 193, 251);
    }
    else
    {
        glColor3ub(3, 55, 84);
    }
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}

void Bridge()
{
    // Bridge Bar
    glBegin(GL_QUADS);
    glColor3ub(139, 27, 35);
    glVertex2f(-0.60, 0.04);
    glVertex2f(-0.60, -0.02);
    glVertex2f(-0.15, -0.02);
    glVertex2f(-0.15, 0.04);
    glEnd();

    // Bridge Pillar1
    glBegin(GL_QUADS);
    glColor3ub(37, 5, 4);
    glVertex2f(-0.52, -0.02);
    glVertex2f(-0.52, -0.04);
    glVertex2f(-0.45, -0.04);
    glVertex2f(-0.45, -0.02);
    glEnd();

    // Bridge Pillar1 ext
    glBegin(GL_QUADS);
    glColor3ub(111, 36, 35);
    glVertex2f(-0.51, -0.04);
    glVertex2f(-0.51, -0.12);
    glVertex2f(-0.46, -0.12);
    glVertex2f(-0.46, -0.04);
    glEnd();

    // Bridge Pillar2
    glBegin(GL_QUADS);
    glColor3ub(37, 5, 4);
    glVertex2f(-0.41, -0.02);
    glVertex2f(-0.41, -0.04);
    glVertex2f(-0.34, -0.04);
    glVertex2f(-0.34, -0.02);
    glEnd();

    // Bridge Pillar2 ext
    glBegin(GL_QUADS);
    glColor3ub(111, 36, 35);
    glVertex2f(-0.40, -0.04);
    glVertex2f(-0.40, -0.12);
    glVertex2f(-0.35, -0.12);
    glVertex2f(-0.35, -0.04);
    glEnd();

    // Bridge Pillar3
    glBegin(GL_QUADS);
    glColor3ub(37, 5, 4);
    glVertex2f(-0.30, -0.02);
    glVertex2f(-0.30, -0.04);
    glVertex2f(-0.23, -0.04);
    glVertex2f(-0.23, -0.02);
    glEnd();

    // Bridge Pillar3 ext
    glBegin(GL_QUADS);
    glColor3ub(111, 36, 35);
    glVertex2f(-0.29, -0.04);
    glVertex2f(-0.29, -0.12);
    glVertex2f(-0.24, -0.12);
    glVertex2f(-0.24, -0.04);
    glEnd();

    // Bridge UpLeft1
    glBegin(GL_QUADS);
    glColor3ub(77, 15, 15);
    glVertex2f(-0.6, 0.04);
    glVertex2f(-0.59, 0.04);
    glVertex2f(-0.54, 0.18);
    glVertex2f(-0.55, 0.18);
    glEnd();

    // Bridge UpRight1
    glBegin(GL_QUADS);
    glColor3ub(77, 15, 15);
    glVertex2f(-0.16, 0.04);
    glVertex2f(-0.15, 0.04);
    glVertex2f(-0.21, 0.18);
    glVertex2f(-0.22, 0.18);
    glEnd();

    // Bridge UpBar
    glBegin(GL_QUADS);
    glColor3ub(77, 15, 15);
    glVertex2f(-0.55, 0.18);
    glVertex2f(-0.55, 0.16);
    glVertex2f(-0.21, 0.16);
    glVertex2f(-0.21, 0.18);
    glEnd();

    // Bridge Crossbar1
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.555, 0.17);
    glVertex2f(-0.485, 0.04);
    glVertex2f(-0.475, 0.04);
    glVertex2f(-0.545, 0.17);
    glEnd();

    // Bridge Crossbar2
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.555, 0.17);
    glVertex2f(-0.485, 0.04);
    glVertex2f(-0.475, 0.04);
    glVertex2f(-0.545, 0.17);
    glEnd();

    // Bridge Crossbar3
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.485, 0.04);
    glVertex2f(-0.475, 0.04);
    glVertex2f(-0.425, 0.17);
    glVertex2f(-0.435, 0.17);
    glEnd();

    // Bridge Crossbar4
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.435, 0.17);
    glVertex2f(-0.425, 0.17);
    glVertex2f(-0.375, 0.04);
    glVertex2f(-0.385, 0.04);
    glEnd();

    // Bridge Crossbar5
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.385, 0.04);
    glVertex2f(-0.375, 0.04);
    glVertex2f(-0.325, 0.17);
    glVertex2f(-0.335, 0.17);
    glEnd();

    // Bridge Crossbar6
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.335, 0.17);
    glVertex2f(-0.325, 0.17);
    glVertex2f(-0.275, 0.04);
    glVertex2f(-0.285, 0.04);
    glEnd();

    // Bridge Crossbar7
    glBegin(GL_QUADS);
    glColor3ub(53, 29, 27);
    glVertex2f(-0.275, 0.04);
    glVertex2f(-0.29, 0.04);
    glVertex2f(-0.22, 0.17);
    glVertex2f(-0.21, 0.17);
    glEnd();
}

void Boat1()
{
    glPushMatrix();
    glTranslatef(positionBoat, 0.0, 0.0);
    // Boat Body
    glBegin(GL_QUADS);
    glColor3ub(70, 70, 70);
    glVertex2f(0.75, -0.43);
    glVertex2f(.86, -.43);
    glVertex2f(0.88, -0.37);
    glVertex2f(.72, -.37);
    glEnd();

    // Boat Lines

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3b(20, 20, 20);
    glVertex2f(0.75, -0.43);
    glVertex2f(.86, -.43);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3b(20, 20, 20);
    glVertex2f(.72, -.37);
    glVertex2f(0.75, -0.43);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3b(20, 20, 20);
    glVertex2f(.86, -.43);
    glVertex2f(0.88, -0.37);
    glEnd();

    // Up Square
    glBegin(GL_QUADS);
    glColor3ub(70, 70, 70);
    glVertex2f(0.82, -0.37);
    glVertex2f(.86, -.37);
    glVertex2f(0.86, -0.340);
    glVertex2f(.83, -.340);
    glEnd();

    // Up Square
    glBegin(GL_QUADS);
    glColor3ub(70, 70, 70);
    glVertex2f(0.73, -0.37);
    glVertex2f(.74, -.34);
    glVertex2f(0.73, -0.32);
    glVertex2f(.72, -.34);
    glEnd();

    // Boat Line Up
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3b(20, 20, 20);
    glVertex2f(.72, -.37);
    glVertex2f(0.88, -0.37);
    glEnd();

    glPopMatrix();
}

void Boat2()
{

    glPushMatrix();
    glTranslatef(-positionBigBoat, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 50, 56);
    glVertex2f(-0.356f, -0.254f);
    glVertex2f(0.296f, -0.25f);
    glVertex2f(0.298f, -0.376f);
    glVertex2f(-0.358f, -0.38f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 89, 103);
    glVertex2f(-0.396f, 0.015f);
    glVertex2f(0.402f, 0.015f);
    glVertex2f(0.402f, -0.064f);
    glVertex2f(-0.398f, -0.06f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 89, 103);
    glVertex2f(-0.396f, 0.015f);
    glVertex2f(0.402f, 0.015f);
    glVertex2f(0.402f, -0.064f);
    glVertex2f(-0.398f, -0.06f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 89, 103);
    glVertex2f(0.293f, -0.254f);
    glVertex2f(-0.356f, -0.258f);
    glVertex2f(-0.356f, -0.202f);
    glVertex2f(-0.358f, -0.171f);
    glVertex2f(-0.364f, -0.123f);
    glVertex2f(-0.382f, -0.076f);
    glVertex2f(-0.396f, -0.056f);
    glVertex2f(0.396f, -0.064f);
    glVertex2f(0.396f, -0.064f);
    glVertex2f(0.376f, -0.084f);
    glVertex2f(0.362f, -0.104f);
    glVertex2f(0.349f, -0.123f);
    glVertex2f(0.338f, -0.139f);
    glVertex2f(0.322f, -0.171f);
    glVertex2f(0.309f, -0.194f);
    glVertex2f(0.300f, -0.222f);
    glVertex2f(0.296f, -0.246f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 89, 103);
    glVertex2f(0.293f, -0.254f);
    glVertex2f(-0.356f, -0.258f);
    glVertex2f(-0.356f, -0.202f);
    glVertex2f(-0.358f, -0.171f);
    glVertex2f(-0.364f, -0.123f);
    glVertex2f(-0.382f, -0.076f);
    glVertex2f(-0.396f, -0.056f);
    glVertex2f(0.396f, -0.064f);
    glVertex2f(0.396f, -0.064f);
    glVertex2f(0.376f, -0.084f);
    glVertex2f(0.362f, -0.104f);
    glVertex2f(0.349f, -0.123f);
    glVertex2f(0.338f, -0.139f);
    glVertex2f(0.322f, -0.171f);
    glVertex2f(0.309f, -0.194f);
    glVertex2f(0.300f, -0.222f);
    glVertex2f(0.296f, -0.246f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(0.191f, 0.244f);
    glVertex2f(0.253f, 0.09f);
    glVertex2f(0.253f, 0.011f);
    glVertex2f(-0.062f, 0.011f);
    glVertex2f(-0.062f, 0.24f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(0.191f, 0.244f);
    glVertex2f(0.253f, 0.09f);
    glVertex2f(0.253f, 0.011f);
    glVertex2f(-0.062f, 0.011f);
    glVertex2f(-0.062f, 0.24f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(-0.062f, 0.659f);
    glVertex2f(-0.020f, 0.659f);
    glVertex2f(0.022f, 0.58f);
    glVertex2f(0.022f, 0.505f);
    glVertex2f(-0.104f, 0.505f);
    glVertex2f(-0.104f, 0.584f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(-0.062f, 0.659f);
    glVertex2f(-0.020f, 0.659f);
    glVertex2f(0.022f, 0.58f);
    glVertex2f(0.022f, 0.505f);
    glVertex2f(-0.104f, 0.505f);
    glVertex2f(-0.104f, 0.584f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(-0.144f, 0.47f);
    glVertex2f(0.064f, 0.47f);
    glVertex2f(0.062f, 0.355f);
    glVertex2f(-0.147f, 0.355f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(-0.144f, 0.47f);
    glVertex2f(0.064f, 0.47f);
    glVertex2f(0.062f, 0.355f);
    glVertex2f(-0.147f, 0.355f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(-0.104f, 0.236f);
    glVertex2f(-0.102f, 0.252f);
    glVertex2f(-0.100f, 0.272f);
    glVertex2f(-0.096f, 0.284f);
    glVertex2f(-0.091f, 0.296f);
    glVertex2f(-0.084f, 0.304f);
    glVertex2f(-0.080f, 0.308f);
    glVertex2f(-0.071f, 0.315f);
    glVertex2f(-0.062f, 0.315f);
    glVertex2f(-0.209f, 0.319f);
    glVertex2f(-0.271f, 0.165f);
    glVertex2f(-0.273f, 0.09f);
    glVertex2f(-0.102f, 0.094f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.107f, 0.225f);
    glVertex2f(-0.107f, 0.225f);
    glVertex2f(-0.102f, 0.098f);
    glVertex2f(-0.102f, 0.098f);
    glVertex2f(-0.249f, 0.094f);
    glVertex2f(-0.249f, 0.09f);
    glVertex2f(-0.249f, 0.011f);
    glVertex2f(-0.060f, 0.015f);
    glVertex2f(-0.060f, 0.24f);
    glVertex2f(0.067f, 0.24f);
    glVertex2f(0.067f, 0.319f);
    glVertex2f(-0.071f, 0.315f);
    glVertex2f(-0.080f, 0.308f);
    glVertex2f(-0.087f, 0.3f);
    glVertex2f(-0.093f, 0.292f);
    glVertex2f(-0.100f, 0.272f);
    glVertex2f(-0.104f, 0.252f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 157);
    glVertex2f(-0.104f, 0.236f);
    glVertex2f(-0.102f, 0.252f);
    glVertex2f(-0.100f, 0.272f);
    glVertex2f(-0.096f, 0.284f);
    glVertex2f(-0.091f, 0.296f);
    glVertex2f(-0.084f, 0.304f);
    glVertex2f(-0.080f, 0.308f);
    glVertex2f(-0.071f, 0.315f);
    glVertex2f(-0.062f, 0.315f);
    glVertex2f(-0.209f, 0.319f);
    glVertex2f(-0.271f, 0.165f);
    glVertex2f(-0.273f, 0.09f);
    glVertex2f(-0.102f, 0.094f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.256f, 0.197f);
    glVertex2f(-0.233f, 0.256f);
    glVertex2f(-0.349f, 0.315f);
    glVertex2f(-0.362f, 0.244f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.256f, 0.197f);
    glVertex2f(-0.233f, 0.256f);
    glVertex2f(-0.349f, 0.315f);
    glVertex2f(-0.362f, 0.244f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.062f, 0.505f);
    glVertex2f(-0.020f, 0.505f);
    glVertex2f(-0.020f, 0.466f);
    glVertex2f(-0.062f, 0.466f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.062f, 0.505f);
    glVertex2f(-0.020f, 0.505f);
    glVertex2f(-0.020f, 0.466f);
    glVertex2f(-0.062f, 0.466f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.020f, 0.355f);
    glVertex2f(-0.020f, 0.355f);
    glVertex2f(-0.020f, 0.315f);
    glVertex2f(-0.062f, 0.315f);
    glVertex2f(-0.062f, 0.355f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(-0.020f, 0.355f);
    glVertex2f(-0.020f, 0.355f);
    glVertex2f(-0.020f, 0.315f);
    glVertex2f(-0.062f, 0.315f);
    glVertex2f(-0.062f, 0.355f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 111, 122);
    glVertex2f(0.227f, 0.149f);
    glVertex2f(0.204f, 0.209f);
    glVertex2f(0.376f, 0.276f);
    glVertex2f(0.384f, 0.209f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(57, 69, 81);
    glVertex2f(-0.187f, 0.236f);
    glVertex2f(-0.144f, 0.24f);
    glVertex2f(-0.147f, 0.161f);
    glVertex2f(-0.189f, 0.161f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(57, 69, 81);
    glVertex2f(0.087f, 0.165f);
    glVertex2f(0.129f, 0.165f);
    glVertex2f(0.129f, 0.09f);
    glVertex2f(0.087f, 0.09f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(57, 69, 81);
    glVertex2f(0.002f, 0.165f);
    glVertex2f(0.044f, 0.165f);
    glVertex2f(0.044f, 0.09f);
    glVertex2f(0.002f, 0.09f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 50, 56);
    glVertex2f(0.251f, -0.131f);
    glVertex2f(0.204f, -0.131f);
    glVertex2f(0.198f, -0.123f);
    glVertex2f(0.193f, -0.115f);
    glVertex2f(0.191f, -0.1f);
    glVertex2f(0.193f, -0.092f);
    glVertex2f(0.193f, -0.08f);
    glVertex2f(0.196f, -0.072f);
    glVertex2f(0.204f, -0.064f);
    glVertex2f(0.260f, -0.064f);
    glVertex2f(0.267f, -0.068f);
    glVertex2f(0.271f, -0.076f);
    glVertex2f(0.273f, -0.084f);
    glVertex2f(0.273f, -0.096f);
    glVertex2f(0.273f, -0.108f);
    glVertex2f(0.273f, -0.119f);
    glVertex2f(0.267f, -0.127f);
    glVertex2f(0.260f, -0.131f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 49, 56);
    glVertex2f(0.204f, -0.064f);
    glVertex2f(0.260f, -0.064f);
    glVertex2f(0.273f, -0.096f);
    glVertex2f(0.256f, -0.135f);
    glVertex2f(0.204f, -0.135f);
    glVertex2f(0.191f, -0.1f);
    glVertex2f(0.191f, -0.1f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53, 72, 79);
    glVertex2f(-0.149f, 0.169f);
    glVertex2f(-0.184f, 0.169f);
    glVertex2f(-0.187f, 0.24f);
    glVertex2f(-0.147f, 0.24f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53, 72, 79);
    glVertex2f(0.042f, 0.102f);
    glVertex2f(0.042f, 0.102f);
    glVertex2f(0.002f, 0.102f);
    glVertex2f(0.000f, 0.161f);
    glVertex2f(0.042f, 0.161f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53, 72, 79);
    glVertex2f(0.087f, 0.102f);
    glVertex2f(0.084f, 0.161f);
    glVertex2f(0.127f, 0.161f);
    glVertex2f(0.127f, 0.102f);
    glEnd();

    glPopMatrix();
}

void Boat3()
{
    glPushMatrix();
    glTranslatef(-positionBigBoat, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 100, 56);
    glVertex2f(-0.356f, -0.254f);
    glVertex2f(0.296f, -0.25f);
    glVertex2f(0.298f, -0.376f);
    glVertex2f(-0.358f, -0.38f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 140, 60);
    glVertex2f(-0.396f, 0.015f);
    glVertex2f(0.402f, 0.015f);
    glVertex2f(0.402f, -0.064f);
    glVertex2f(-0.398f, -0.06f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 120, 80);
    glVertex2f(0.293f, -0.254f);
    glVertex2f(-0.356f, -0.258f);
    glVertex2f(-0.356f, -0.202f);
    glVertex2f(-0.358f, -0.171f);
    glVertex2f(-0.364f, -0.123f);
    glVertex2f(-0.382f, -0.076f);
    glVertex2f(-0.396f, -0.056f);
    glVertex2f(0.396f, -0.064f);
    glVertex2f(0.396f, -0.064f);
    glVertex2f(0.376f, -0.084f);
    glVertex2f(0.362f, -0.104f);
    glVertex2f(0.349f, -0.123f);
    glVertex2f(0.338f, -0.139f);
    glVertex2f(0.322f, -0.171f);
    glVertex2f(0.309f, -0.194f);
    glVertex2f(0.300f, -0.222f);
    glVertex2f(0.296f, -0.246f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 110);
    glVertex2f(0.191f, 0.244f);
    glVertex2f(0.253f, 0.09f);
    glVertex2f(0.253f, 0.011f);
    glVertex2f(-0.062f, 0.011f);
    glVertex2f(-0.062f, 0.24f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 145, 90);
    glVertex2f(-0.062f, 0.659f);
    glVertex2f(-0.020f, 0.659f);
    glVertex2f(0.022f, 0.58f);
    glVertex2f(0.022f, 0.505f);
    glVertex2f(-0.104f, 0.505f);
    glVertex2f(-0.104f, 0.584f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 145, 90);
    glVertex2f(-0.144f, 0.47f);
    glVertex2f(0.064f, 0.47f);
    glVertex2f(0.062f, 0.355f);
    glVertex2f(-0.147f, 0.355f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 145, 90);
    glVertex2f(-0.107f, 0.225f);
    glVertex2f(-0.107f, 0.225f);
    glVertex2f(-0.102f, 0.098f);
    glVertex2f(-0.102f, 0.098f);
    glVertex2f(-0.249f, 0.094f);
    glVertex2f(-0.249f, 0.09f);
    glVertex2f(-0.249f, 0.011f);
    glVertex2f(-0.060f, 0.015f);
    glVertex2f(-0.060f, 0.24f);
    glVertex2f(0.067f, 0.24f);
    glVertex2f(0.067f, 0.319f);
    glVertex2f(-0.071f, 0.315f);
    glVertex2f(-0.080f, 0.308f);
    glVertex2f(-0.087f, 0.3f);
    glVertex2f(-0.093f, 0.292f);
    glVertex2f(-0.100f, 0.272f);
    glVertex2f(-0.104f, 0.252f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 110);
    glVertex2f(-0.104f, 0.236f);
    glVertex2f(-0.102f, 0.252f);
    glVertex2f(-0.100f, 0.272f);
    glVertex2f(-0.096f, 0.284f);
    glVertex2f(-0.091f, 0.296f);
    glVertex2f(-0.084f, 0.304f);
    glVertex2f(-0.080f, 0.308f);
    glVertex2f(-0.071f, 0.315f);
    glVertex2f(-0.062f, 0.315f);
    glVertex2f(-0.209f, 0.319f);
    glVertex2f(-0.271f, 0.165f);
    glVertex2f(-0.273f, 0.09f);
    glVertex2f(-0.102f, 0.094f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 145, 90);
    glVertex2f(-0.256f, 0.197f);
    glVertex2f(-0.233f, 0.256f);
    glVertex2f(-0.349f, 0.315f);
    glVertex2f(-0.362f, 0.244f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 110);
    glVertex2f(-0.062f, 0.505f);
    glVertex2f(-0.020f, 0.505f);
    glVertex2f(-0.020f, 0.466f);
    glVertex2f(-0.062f, 0.466f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(121, 145, 110);
    glVertex2f(-0.020f, 0.355f);
    glVertex2f(-0.020f, 0.355f);
    glVertex2f(-0.020f, 0.315f);
    glVertex2f(-0.062f, 0.315f);
    glVertex2f(-0.062f, 0.355f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(70, 145, 90);
    glVertex2f(0.227f, 0.149f);
    glVertex2f(0.204f, 0.209f);
    glVertex2f(0.376f, 0.276f);
    glVertex2f(0.384f, 0.209f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(57, 69, 81);
    glVertex2f(-0.187f, 0.236f);
    glVertex2f(-0.144f, 0.24f);
    glVertex2f(-0.147f, 0.161f);
    glVertex2f(-0.189f, 0.161f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(57, 69, 81);
    glVertex2f(0.087f, 0.165f);
    glVertex2f(0.129f, 0.165f);
    glVertex2f(0.129f, 0.09f);
    glVertex2f(0.087f, 0.09f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(57, 69, 81);
    glVertex2f(0.002f, 0.165f);
    glVertex2f(0.044f, 0.165f);
    glVertex2f(0.044f, 0.09f);
    glVertex2f(0.002f, 0.09f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 50, 56);
    glVertex2f(0.251f, -0.131f);
    glVertex2f(0.204f, -0.131f);
    glVertex2f(0.198f, -0.123f);
    glVertex2f(0.193f, -0.115f);
    glVertex2f(0.191f, -0.1f);
    glVertex2f(0.193f, -0.092f);
    glVertex2f(0.193f, -0.08f);
    glVertex2f(0.196f, -0.072f);
    glVertex2f(0.204f, -0.064f);
    glVertex2f(0.260f, -0.064f);
    glVertex2f(0.267f, -0.068f);
    glVertex2f(0.271f, -0.076f);
    glVertex2f(0.273f, -0.084f);
    glVertex2f(0.273f, -0.096f);
    glVertex2f(0.273f, -0.108f);
    glVertex2f(0.273f, -0.119f);
    glVertex2f(0.267f, -0.127f);
    glVertex2f(0.260f, -0.131f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 49, 56);
    glVertex2f(0.204f, -0.064f);
    glVertex2f(0.260f, -0.064f);
    glVertex2f(0.273f, -0.096f);
    glVertex2f(0.256f, -0.135f);
    glVertex2f(0.204f, -0.135f);
    glVertex2f(0.191f, -0.1f);
    glVertex2f(0.191f, -0.1f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53, 72, 79);
    glVertex2f(-0.149f, 0.169f);
    glVertex2f(-0.184f, 0.169f);
    glVertex2f(-0.187f, 0.24f);
    glVertex2f(-0.147f, 0.24f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53, 72, 79);
    glVertex2f(0.042f, 0.102f);
    glVertex2f(0.042f, 0.102f);
    glVertex2f(0.002f, 0.102f);
    glVertex2f(0.000f, 0.161f);
    glVertex2f(0.042f, 0.161f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53, 72, 79);
    glVertex2f(0.087f, 0.102f);
    glVertex2f(0.084f, 0.161f);
    glVertex2f(0.127f, 0.161f);
    glVertex2f(0.127f, 0.102f);
    glEnd();
    glPopMatrix();
}

void BrokeHouse1()
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(199, 119, 108);
    glVertex2f(-0.444f, -0.151f);
    glVertex2f(-0.464f, -0.135f);
    glVertex2f(-0.480f, -0.108f);
    glVertex2f(-0.491f, -0.064f);
    glVertex2f(-0.536f, -0.06f);
    glVertex2f(-0.536f, -0.06f);
    glVertex2f(-0.531f, -0.447f);
    glVertex2f(-0.336f, -0.443f);
    glVertex2f(-0.342f, -0.234f);
    glVertex2f(-0.396f, -0.179f);
    glVertex2f(-0.409f, -0.183f);
    glVertex2f(-0.413f, -0.194f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(142, 63, 59);
    glVertex2f(-0.327f, -0.23f);
    glVertex2f(-0.342f, -0.246f);
    glVertex2f(-0.336f, -0.443f);
    glVertex2f(-0.264f, -0.44f);
    glVertex2f(-0.264f, -0.23f);
    glVertex2f(-0.273f, -0.218f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(142, 63, 59);
    glVertex2f(-0.262f, -0.44f);
    glVertex2f(-0.256f, -0.44f);
    glVertex2f(-0.264f, -0.388f);
    glEnd();
}

void BrokeHouse2()
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(246, 225, 197);
    glVertex2f(-0.227f, 0.363f);
    glVertex2f(-0.091f, 0.371f);
    glVertex2f(-0.096f, -0.416f);
    glVertex2f(-0.229f, -0.412f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 221, 198);
    glVertex2f(0.076f, 0.13f);
    glVertex2f(0.076f, 0.24f);
    glVertex2f(0.071f, 0.268f);
    glVertex2f(0.062f, 0.284f);
    glVertex2f(0.058f, 0.292f);
    glVertex2f(0.051f, 0.343f);
    glVertex2f(-0.067f, 0.335f);
    glVertex2f(-0.044f, 0.296f);
    glVertex2f(-0.038f, -0.42f);
    glVertex2f(0.104f, -0.416f);
    glVertex2f(0.104f, 0.082f);
    glVertex2f(0.098f, 0.09f);
    glVertex2f(0.098f, 0.118f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 123, 122);
    glVertex2f(-0.073f, 0.335f);
    glVertex2f(-0.076f, -0.412f);
    glVertex2f(-0.093f, -0.412f);
    glVertex2f(-0.091f, 0.367f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 138, 137);
    glVertex2f(-0.044f, 0.304f);
    glVertex2f(-0.040f, -0.416f);
    glVertex2f(-0.073f, -0.412f);
    glVertex2f(-0.073f, 0.339f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(214, 125, 121);
    glVertex2f(0.118f, 0.035f);
    glVertex2f(0.118f, -0.416f);
    glVertex2f(0.104f, -0.416f);
    glVertex2f(0.104f, 0.07f);
    glVertex2f(0.116f, 0.066f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 137, 139);
    glVertex2f(0.120f, -0.096f);
    glVertex2f(0.120f, -0.345f);
    glVertex2f(0.120f, -0.416f);
    glVertex2f(0.153f, -0.416f);
    glVertex2f(0.149f, -0.001f);
    glVertex2f(0.136f, 0.015f);
    glVertex2f(0.120f, 0.043f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(226, 188, 170);
    glVertex2f(0.191f, -0.017f);
    glVertex2f(0.193f, -0.416f);
    glVertex2f(0.153f, -0.416f);
    glVertex2f(0.151f, -0.005f);
    glVertex2f(0.162f, -0.013f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 223, 200);
    glVertex2f(0.218f, -0.416f);
    glVertex2f(0.193f, -0.416f);
    glVertex2f(0.191f, -0.017f);
    glVertex2f(0.220f, -0.017f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(209, 128, 125);
    glVertex2f(0.256f, -0.001f);
    glVertex2f(0.269f, 0.015f);
    glVertex2f(0.276f, 0.039f);
    glVertex2f(0.293f, 0.058f);
    glVertex2f(0.302f, 0.058f);
    glVertex2f(0.300f, -0.416f);
    glVertex2f(0.218f, -0.416f);
    glVertex2f(0.222f, -0.025f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 134, 98);
    glVertex2f(-0.224f, -0.412f);
    glVertex2f(-0.229f, -0.404f);
    glVertex2f(-0.236f, -0.416f);
    glVertex2f(-0.236f, -0.447f);
    glVertex2f(0.309f, -0.447f);
    glVertex2f(0.309f, -0.42f);
    glVertex2f(0.302f, -0.42f);
    glEnd();
}

void BrokeHouse3()
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(181, 136, 156);
    glVertex2f(0.351f, -0.021f);
    glVertex2f(0.347f, -0.005f);
    glVertex2f(0.344f, 0.066f);
    glVertex2f(0.376f, 0.074f);
    glVertex2f(0.382f, 0.078f);
    glVertex2f(0.447f, 0.078f);
    glVertex2f(0.442f, -0.443f);
    glVertex2f(0.349f, -0.443f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 61, 89);
    glVertex2f(0.469f, -0.044f);
    glVertex2f(0.482f, -0.044f);
    glVertex2f(0.480f, 0.039f);
    glVertex2f(0.449f, 0.082f);
    glVertex2f(0.444f, 0.074f);
    glVertex2f(0.440f, -0.443f);
    glVertex2f(0.471f, -0.443f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(141, 98, 128);
    glVertex2f(0.500f, -0.214f);
    glVertex2f(0.496f, -0.408f);
    glVertex2f(0.513f, -0.392f);
    glVertex2f(0.511f, -0.044f);
    glVertex2f(0.471f, -0.048f);
    glVertex2f(0.473f, -0.416f);
    glVertex2f(0.473f, -0.416f);
    glVertex2f(0.484f, -0.412f);
    glVertex2f(0.482f, -0.064f);
    glVertex2f(0.496f, -0.064f);
    glVertex2f(0.502f, -0.068f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 195, 194);
    glVertex2f(0.498f, -0.408f);
    glVertex2f(0.482f, -0.412f);
    glVertex2f(0.484f, -0.179f);
    glVertex2f(0.500f, -0.179f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(67, 31, 62);
    glVertex2f(0.482f, -0.175f);
    glVertex2f(0.482f, -0.068f);
    glVertex2f(0.502f, -0.068f);
    glVertex2f(0.502f, -0.179f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 185, 186);
    glVertex2f(0.509f, -0.064f);
    glVertex2f(0.511f, -0.044f);
    glVertex2f(0.547f, -0.044f);
    glVertex2f(0.544f, -0.36f);
    glVertex2f(0.544f, -0.36f);
    glVertex2f(0.511f, -0.388f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(141, 98, 128);
    glVertex2f(0.478f, -0.068f);
    glVertex2f(0.507f, -0.072f);
    glVertex2f(0.504f, -0.04f);
    glVertex2f(0.482f, -0.04f);
    glVertex2f(0.464f, -0.04f);
    glVertex2f(0.467f, -0.424f);
    glVertex2f(0.478f, -0.416f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(231, 180, 169);
    glVertex2f(0.562f, -0.175f);
    glVertex2f(0.547f, -0.175f);
    glVertex2f(0.544f, -0.044f);
    glVertex2f(0.549f, -0.048f);
    glVertex2f(0.578f, -0.048f);
    glVertex2f(0.571f, -0.38f);
    glVertex2f(0.560f, -0.38f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(118, 61, 94);
    glVertex2f(0.542f, -0.357f);
    glVertex2f(0.542f, -0.171f);
    glVertex2f(0.564f, -0.171f);
    glVertex2f(0.562f, -0.364f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(142, 76, 87);
    glVertex2f(0.616f, -0.068f);
    glVertex2f(0.609f, -0.447f);
    glVertex2f(0.569f, -0.447f);
    glVertex2f(0.578f, -0.052f);
    glVertex2f(0.576f, -0.025f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 186, 201);
    glVertex2f(0.547f, -0.357f);
    glVertex2f(0.564f, -0.372f);
    glVertex2f(0.562f, -0.384f);
    glVertex2f(0.571f, -0.38f);
    glVertex2f(0.569f, -0.455f);
    glVertex2f(0.471f, -0.447f);
    glVertex2f(0.469f, -0.416f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(220, 173, 188);
    glVertex2f(0.533f, -0.017f);
    glVertex2f(0.542f, 0.003f);
    glVertex2f(0.562f, -0.001f);
    glVertex2f(0.573f, -0.017f);
    glVertex2f(0.576f, -0.028f);
    glVertex2f(0.578f, -0.056f);
    glVertex2f(0.513f, -0.048f);
    glVertex2f(0.504f, -0.048f);
    glVertex2f(0.502f, -0.005f);
    glVertex2f(0.524f, -0.005f);
    glEnd();
}

void BrokeHouse4()
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 132, 121);
    glVertex2f(0.667f, -0.147f);
    glVertex2f(0.667f, -0.447f);
    glVertex2f(0.724f, -0.447f);
    glVertex2f(0.727f, -0.143f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(151, 72, 57);
    glVertex2f(0.753f, -0.179f);
    glVertex2f(0.760f, -0.447f);
    glVertex2f(0.724f, -0.447f);
    glVertex2f(0.727f, -0.147f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 122, 110);
    glVertex2f(0.753f, -0.179f);
    glVertex2f(0.727f, -0.151f);
    glVertex2f(0.707f, -0.151f);
    glVertex2f(0.707f, -0.151f);
    glVertex2f(0.702f, -0.013f);
    glVertex2f(0.878f, -0.005f);
    glVertex2f(0.878f, -0.151f);
    glVertex2f(0.844f, -0.155f);
    glVertex2f(0.853f, -0.447f);
    glVertex2f(0.762f, -0.447f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(210, 129, 126);
    glVertex2f(0.842f, -0.155f);
    glVertex2f(0.913f, -0.139f);
    glVertex2f(0.911f, -0.447f);
    glVertex2f(0.851f, -0.447f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 122, 110);
    glVertex2f(0.758f, -0.451f);
    glVertex2f(0.771f, -0.451f);
    glVertex2f(0.753f, -0.179f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(126, 50, 60);
    glVertex2f(0.916f, -0.052f);
    glVertex2f(0.878f, -0.009f);
    glVertex2f(0.880f, -0.147f);
    glVertex2f(0.916f, -0.143f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(126, 50, 60);
    glVertex2f(0.933f, -0.329f);
    glVertex2f(0.936f, -0.384f);
    glVertex2f(0.944f, -0.443f);
    glVertex2f(0.909f, -0.443f);
    glVertex2f(0.913f, -0.147f);
    glVertex2f(0.942f, -0.179f);
    glVertex2f(0.938f, -0.274f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(223, 179, 187);
    glVertex2f(0.789f, 0.055f);
    glVertex2f(0.804f, 0.055f);
    glVertex2f(0.820f, 0.058f);
    glVertex2f(0.840f, 0.058f);
    glVertex2f(0.840f, 0.003f);
    glVertex2f(0.827f, 0.011f);
    glVertex2f(0.816f, 0.003f);
    glVertex2f(0.784f, 0.007f);
    glVertex2f(0.758f, 0.007f);
    glVertex2f(0.744f, 0.011f);
    glVertex2f(0.742f, 0.023f);
    glVertex2f(0.742f, 0.047f);
    glVertex2f(0.780f, 0.051f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 210, 207);
    glVertex2f(0.824f, -0.009f);
    glVertex2f(0.822f, 0.003f);
    glVertex2f(0.829f, 0.011f);
    glVertex2f(0.827f, -0.013f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 210, 207);
    glVertex2f(0.760f, 0.003f);
    glVertex2f(0.760f, -0.017f);
    glVertex2f(0.756f, -0.017f);
    glVertex2f(0.756f, 0.003f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 132, 121);
    glVertex2f(0.658f, -0.191f);
    glVertex2f(0.658f, -0.242f);
    glVertex2f(0.629f, -0.242f);
    glVertex2f(0.629f, -0.187f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(223, 128, 91);
    glVertex2f(0.644f, -0.258f);
    glVertex2f(0.658f, -0.258f);
    glVertex2f(0.658f, -0.277f);
    glVertex2f(0.644f, -0.277f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 210, 209);
    glVertex2f(0.667f, -0.202f);
    glVertex2f(0.667f, -0.21f);
    glVertex2f(0.656f, -0.206f);
    glVertex2f(0.656f, -0.198f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 210, 209);
    glVertex2f(0.656f, -0.23f);
    glVertex2f(0.656f, -0.222f);
    glVertex2f(0.667f, -0.222f);
    glVertex2f(0.667f, -0.234f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 210, 209);
    glVertex2f(0.656f, -0.262f);
    glVertex2f(0.656f, -0.262f);
    glVertex2f(0.669f, -0.262f);
    glVertex2f(0.667f, -0.27f);
    glVertex2f(0.656f, -0.27f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 122, 110);
    glVertex2f(0.871f, -0.131f);
    glVertex2f(0.882f, -0.068f);
    glVertex2f(0.882f, -0.151f);
    glEnd();
}

void BrokeHouse5()
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(228, 179, 182);
    glVertex2f(-0.929f, -0.274f);
    glVertex2f(-0.936f, -0.155f);
    glVertex2f(-0.873f, -0.151f);
    glVertex2f(-0.878f, -0.277f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(219, 172, 183);
    glVertex2f(-0.929f, -0.277f);
    glVertex2f(-0.929f, -0.277f);
    glVertex2f(-0.876f, -0.274f);
    glVertex2f(-0.880f, -0.443f);
    glVertex2f(-0.936f, -0.443f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(152, 83, 88);
    glVertex2f(-0.853f, -0.183f);
    glVertex2f(-0.856f, -0.285f);
    glVertex2f(-0.878f, -0.277f);
    glVertex2f(-0.876f, -0.155f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138, 76, 88);
    glVertex2f(-0.853f, -0.285f);
    glVertex2f(-0.853f, -0.443f);
    glVertex2f(-0.880f, -0.443f);
    glVertex2f(-0.878f, -0.277f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164, 98, 106);
    glVertex2f(-0.833f, -0.198f);
    glVertex2f(-0.838f, -0.447f);
    glVertex2f(-0.853f, -0.443f);
    glVertex2f(-0.853f, -0.175f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(231, 177, 177);
    glVertex2f(-0.833f, -0.198f);
    glVertex2f(-0.853f, -0.175f);
    glVertex2f(-0.758f, -0.171f);
    glVertex2f(-0.751f, -0.443f);
    glVertex2f(-0.838f, -0.443f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 173, 182);
    glVertex2f(-0.758f, -0.175f);
    glVertex2f(-0.758f, -0.143f);
    glVertex2f(-0.691f, -0.143f);
    glVertex2f(-0.693f, -0.384f);
    glVertex2f(-0.753f, -0.4f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(191, 152, 182);
    glVertex2f(-0.691f, -0.443f);
    glVertex2f(-0.749f, -0.447f);
    glVertex2f(-0.751f, -0.396f);
    glVertex2f(-0.691f, -0.388f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138, 77, 93);
    glVertex2f(-0.667f, -0.171f);
    glVertex2f(-0.669f, -0.38f);
    glVertex2f(-0.691f, -0.388f);
    glVertex2f(-0.691f, -0.147f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(115, 62, 106);
    glVertex2f(-0.691f, -0.392f);
    glVertex2f(-0.667f, -0.38f);
    glVertex2f(-0.662f, -0.443f);
    glVertex2f(-0.691f, -0.443f);
    glEnd();
}

void Nuclear()
{
    // Yellow Pipes

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(248, 237, 126);
    glVertex2f(-0.270f, -0.814f);
    glVertex2f(-0.163f, -0.814f);
    glVertex2f(-0.161f, -0.794f);
    glVertex2f(-0.283f, -0.791f);
    glVertex2f(-0.292f, -0.802f);
    glVertex2f(-0.294f, -0.818f);
    glVertex2f(-0.294f, -0.905f);
    glVertex2f(-0.279f, -0.905f);
    glVertex2f(-0.279f, -0.814f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(248, 237, 126);
    glVertex2f(-0.239f, -0.858f);
    glVertex2f(-0.176f, -0.858f);
    glVertex2f(-0.174f, -0.834f);
    glVertex2f(-0.248f, -0.834f);
    glVertex2f(-0.254f, -0.838f);
    glVertex2f(-0.259f, -0.842f);
    glVertex2f(-0.263f, -0.85f);
    glVertex2f(-0.263f, -0.874f);
    glVertex2f(-0.263f, -0.905f);
    glVertex2f(-0.248f, -0.905f);
    glVertex2f(-0.248f, -0.866f);
    glVertex2f(-0.248f, -0.858f);
    glEnd();

    // Yellow Bar
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 162, 107);
    glVertex2f(-0.163f, -0.771f);
    glVertex2f(0.030f, -0.771f);
    glVertex2f(0.032f, -0.905f);
    glVertex2f(-0.201f, -0.905f);
    glEnd();

    // Nuclear1

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 136, 160);
    glVertex2f(-0.599f, -0.312f);
    glVertex2f(-0.610f, -0.47f);
    glVertex2f(-0.625f, -0.648f);
    glVertex2f(-0.643f, -0.806f);
    glVertex2f(-0.654f, -0.905f);
    glVertex2f(-0.310f, -0.901f);
    glVertex2f(-0.345f, -0.605f);
    glVertex2f(-0.359f, -0.455f);
    glVertex2f(-0.365f, -0.348f);
    glVertex2f(-0.374f, -0.221f);
    glVertex2f(-0.381f, -0.075f);
    glVertex2f(-0.390f, 0.134f);
    glVertex2f(-0.572f, 0.142f);
    glVertex2f(-0.579f, 0.012f);
    glVertex2f(-0.588f, -0.15f);
    glEnd();

    // Nuclear2

    // Building
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 206, 192);
    glVertex2f(0.304f, 0.066f);
    glVertex2f(0.444f, 0.066f);
    glVertex2f(0.444f, -0.306f);
    glVertex2f(0.302f, -0.306f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 193, 180);
    glVertex2f(0.073f, -0.306f);
    glVertex2f(0.493f, -0.302f);
    glVertex2f(0.493f, -0.504f);
    glVertex2f(0.073f, -0.504f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(201, 163, 157);
    glVertex2f(0.026f, -0.903f);
    glVertex2f(0.026f, -0.5f);
    glVertex2f(0.553f, -0.5f);
    glVertex2f(0.553f, -0.903f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(87, 83, 93);
    glVertex2f(0.123f, -0.312f);
    glVertex2f(0.120f, 0.146f);
    glVertex2f(0.149f, 0.146f);
    glVertex2f(0.147f, -0.312f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(87, 83, 93);
    glVertex2f(0.176f, 0.142f);
    glVertex2f(0.200f, 0.142f);
    glVertex2f(0.200f, -0.312f);
    glVertex2f(0.176f, -0.312f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(87, 83, 93);
    glVertex2f(0.254f, -0.312f);
    glVertex2f(0.229f, -0.312f);
    glVertex2f(0.229f, 0.142f);
    glVertex2f(0.256f, 0.142f);
    glEnd();

    /*glBegin(GL_LINES);
    glColor3ub(83,81,91);
        glVertex2f(-0.722f, 0.909f);
        glVertex2f(0.604f, 0.905f);
    glEnd();*/
}

void Tank1()
{

    glPushMatrix();
    glTranslatef(-positiontank, 0.0f, 0.0f);
    glBegin(GL_QUADS);       // Each set of 4 vertices form a quad
    glColor3ub(66, 146, 78); // Red

    glVertex2f(-0.5f, 0.65f); // x, y
    glVertex2f(-0.5f, 0.37f); // x, y
    glVertex2f(0.02f, 0.4f);  // x, y
    glVertex2f(0.02f, 0.65f); // x, y
    glEnd();

    // Tank Head Lines
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.5f, 0.65f);
    glVertex2f(-0.5f, 0.37f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.5f, 0.37f);
    glVertex2f(0.02f, 0.4f);
    glEnd();

    // Tank Pipe
    glBegin(GL_QUADS);       // Each set of 4 vertices form a quad
    glColor3ub(66, 146, 78); // Red
    glVertex2f(0.02f, 0.58f);
    glVertex2f(0.02f, 0.49f);
    glVertex2f(0.5f, 0.49f); // x, y
    glVertex2f(0.5f, 0.58f);
    glEnd();

    // Tank Pipe Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.58f);
    glVertex2f(0.02f, 0.58f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.02f, 0.49f);
    glVertex2f(0.5f, 0.49f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.49f);
    glVertex2f(0.5f, 0.58f);
    glEnd();

    // Tank Pipe Head
    glBegin(GL_QUADS);       // Each set of 4 vertices form a quad
    glColor3ub(66, 146, 78); // Red
    glVertex2f(0.5f, 0.60f); // x, y
    glVertex2f(0.5f, 0.47f);
    glVertex2f(0.72f, 0.47f);
    glVertex2f(0.72f, 0.60f);
    glEnd();

    // Tank Pipe Head Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.60f); // x, y
    glVertex2f(0.5f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.47f);
    glVertex2f(0.72f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.72f, 0.47f);
    glVertex2f(0.72f, 0.60f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.60f);
    glVertex2f(0.72f, 0.60f);
    glEnd();

    // Tank Head Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(0.02f, 0.65f);
    glEnd();

    // TankTop
    glBegin(GL_QUADS);       // Each set of 4 vertices form a quad
    glColor3ub(66, 146, 78); // Red

    glVertex2f(-0.34f, 0.65f); // x, y
    glVertex2f(-0.12f, 0.65f); // x, y
    glVertex2f(-0.12f, 0.73f); // x, y
    glVertex2f(-0.34f, 0.73f); // x, y
    glEnd();
    // Tank Top Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.12f, 0.65f);
    glVertex2f(-0.12f, 0.73f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.12f, 0.73f);
    glVertex2f(-0.34f, 0.73f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.34f, 0.73f);
    glVertex2f(-0.34f, 0.65f);
    glEnd();

    // Tank Head Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.02f, 0.65f);
    glVertex2f(-0.5f, 0.65f);
    glEnd();

    // Tank Tire
    GLfloat p2 = -0.2f;
    GLfloat q2 = 0.0f;
    GLfloat r2 = 0.7f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(p2, q2);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p2 + (r2 * cos(i * tp2 / triangle2)),
            q2 + (r2 * .4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire2
    GLfloat p3 = -0.2f;
    GLfloat q3 = 0.0f;
    GLfloat r3 = 0.65f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(p3, q3);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p3 + (r3 * cos(i * tp2 / triangle2)),
            q3 + (r3 * .4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire2
    GLfloat p4 = -0.2f;
    GLfloat q4 = 0.0f;
    GLfloat r4 = 0.60f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(147, 131, 115);
    glVertex2f(p4, q4);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p4 + (r4 * cos(i * tp2 / triangle2)),
            q4 + (r4 * .4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Wheel Outline
    GLfloat p5 = -0.2f;
    GLfloat q5 = -0.05f;
    GLfloat r5 = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p5, q5);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p5 + (r5 * .6 * cos(i * tp2 / triangle2)),
            q5 + (r5 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Wheel
    GLfloat p6 = -0.2f;
    GLfloat q6 = -0.05f;
    GLfloat r6 = 0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p6, q6);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p6 + (r6 * .6 * cos(i * tp2 / triangle2)),
            q6 + (r6 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_1
    GLfloat p7 = -0.2f;
    GLfloat q7 = -0.05f;
    GLfloat r7 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p7, q7);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p7 + (r7 * .6 * cos(i * tp2 / triangle2)),
            q7 + (r7 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_2
    GLfloat p8 = -0.2f;
    GLfloat q8 = -0.05f;
    GLfloat r8 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p8, q8);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p8 + (r8 * .6 * cos(i * tp2 / triangle2)),
            q8 + (r8 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel 2

    // Tank Tire Whee2 Outline
    GLfloat p9 = -0.5f;
    GLfloat q9 = -0.05f;
    GLfloat r9 = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p9, q9);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p9 + (r9 * .6 * cos(i * tp2 / triangle2)),
            q9 + (r9 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee2
    GLfloat p10 = -0.5f;
    GLfloat q10 = -0.05f;
    GLfloat r10 = 0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p10, q10);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p10 + (r10 * .6 * cos(i * tp2 / triangle2)),
            q10 + (r10 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_1
    GLfloat p11 = -0.5f;
    GLfloat q11 = -0.05f;
    GLfloat r11 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p11, q11);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p11 + (r11 * .6 * cos(i * tp2 / triangle2)),
            q11 + (r11 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_2
    GLfloat p12 = -0.5f;
    GLfloat q12 = -0.05f;
    GLfloat r12 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p12, q12);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p12 + (r12 * .6 * cos(i * tp2 / triangle2)),
            q12 + (r12 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel 3

    // Tank Tire Wheel3 Outline
    GLfloat p13 = 0.1f;
    GLfloat q13 = -0.035f;
    GLfloat r13 = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p13, q13);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p13 + (r13 * .6 * cos(i * tp2 / triangle2)),
            q13 + (r13 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3
    GLfloat p14 = 0.1f;
    GLfloat q14 = -0.035f;
    GLfloat r14 = 0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p14, q14);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p14 + (r14 * .6 * cos(i * tp2 / triangle2)),
            q14 + (r14 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_1
    GLfloat p15 = 0.1f;
    GLfloat q15 = -0.035f;
    GLfloat r15 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p15, q15);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p15 + (r15 * .6 * cos(i * tp2 / triangle2)),
            q15 + (r15 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_2
    GLfloat p16 = 0.1f;
    GLfloat q16 = -0.035f;
    GLfloat r16 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p16, q16);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p16 + (r16 * .6 * cos(i * tp2 / triangle2)),
            q16 + (r16 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel Small 1

    // Tank Tire Small Wheel Outline
    GLfloat p17 = 0.30f;
    GLfloat q17 = 0.0f;
    GLfloat r17 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p17, q17);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p17 + (r17 * .6 * cos(i * tp2 / triangle2)),
            q17 + (r17 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3
    GLfloat p18 = 0.3f;
    GLfloat q18 = 0.0f;
    GLfloat r18 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p18, q18);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p18 + (r18 * .6 * cos(i * tp2 / triangle2)),
            q18 + (r18 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_1
    GLfloat p19 = 0.3f;
    GLfloat q19 = 0.0f;
    GLfloat r19 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p19, q19);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p19 + (r19 * .6 * cos(i * tp2 / triangle2)),
            q19 + (r19 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_2
    GLfloat p20 = 0.3f;
    GLfloat q20 = 0.0f;
    GLfloat r20 = 0.03f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p20, q20);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p20 + (r20 * .6 * cos(i * tp2 / triangle2)),
            q20 + (r20 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel Small 2

    // Tank Tire Small Wheel Outline
    GLfloat p21 = -0.70f;
    GLfloat q21 = 0.0f;
    GLfloat r21 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p21, q21);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p21 + (r21 * .6 * cos(i * tp2 / triangle2)),
            q21 + (r21 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee Small 2
    GLfloat p22 = -0.7f;
    GLfloat q22 = 0.0f;
    GLfloat r22 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p22, q22);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p22 + (r22 * .6 * cos(i * tp2 / triangle2)),
            q22 + (r22 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee SMall 2
    GLfloat p23 = -0.7f;
    GLfloat q23 = 0.0f;
    GLfloat r23 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p23, q23);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p23 + (r23 * .6 * cos(i * tp2 / triangle2)),
            q23 + (r23 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee Small 2
    GLfloat p24 = -0.7f;
    GLfloat q24 = 0.0f;
    GLfloat r24 = 0.03f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p24, q24);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p24 + (r24 * .6 * cos(i * tp2 / triangle2)),
            q24 + (r24 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Body

    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(66, 146, 78);   // Red
    glVertex2f(-0.71f, 0.35f); // x, y
    glVertex2f(-0.84f, 0.11f); // x, y
    glVertex2f(0.41f, 0.19f);  // x, y
    glVertex2f(0.3f, 0.42f);   // x, y
    glEnd();

    // Tank body lines

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.71f, 0.35f); // x, y
    glVertex2f(-0.84f, 0.11f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.84f, 0.11f); // x, y
    glVertex2f(0.41f, 0.19f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.41f, 0.19f); // x, y
    glVertex2f(0.3f, 0.42f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.71f, 0.35f); // x, y
    glVertex2f(0.3f, 0.42f);
    glEnd();
    glPopMatrix();
}

void explode()
{
    glPushMatrix();
    glScalef(0.8 * -ScaleBullet, 0.8 * -ScaleBullet, 0);

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(231, 116, 35, 200);
    glVertex2f(-0.016f, 0.082f);
    glVertex2f(-0.020f, 0.09f);
    glVertex2f(-0.013f, 0.114f);
    glVertex2f(0.004f, 0.189f);
    glVertex2f(0.020f, 0.236f);
    glVertex2f(0.042f, 0.296f);
    glVertex2f(0.064f, 0.355f);
    glVertex2f(0.093f, 0.442f);
    glVertex2f(0.102f, 0.47f);
    glVertex2f(0.073f, 0.426f);
    glVertex2f(0.040f, 0.367f);
    glVertex2f(-0.002f, 0.315f);
    glVertex2f(-0.027f, 0.256f);
    glVertex2f(-0.036f, 0.232f);
    glVertex2f(-0.049f, 0.185f);
    glVertex2f(-0.056f, 0.177f);
    glVertex2f(-0.064f, 0.228f);
    glVertex2f(-0.062f, 0.323f);
    glVertex2f(-0.064f, 0.438f);
    glVertex2f(-0.062f, 0.56f);
    glVertex2f(-0.062f, 0.667f);
    glVertex2f(-0.071f, 0.64f);
    glVertex2f(-0.078f, 0.596f);
    glVertex2f(-0.082f, 0.525f);
    glVertex2f(-0.082f, 0.394f);
    glVertex2f(-0.093f, 0.391f);
    glVertex2f(-0.104f, 0.359f);
    glVertex2f(-0.111f, 0.319f);
    glVertex2f(-0.116f, 0.232f);
    glVertex2f(-0.131f, 0.177f);
    glVertex2f(-0.149f, 0.169f);
    glVertex2f(-0.176f, 0.228f);
    glVertex2f(-0.202f, 0.3f);
    glVertex2f(-0.233f, 0.331f);
    glVertex2f(-0.251f, 0.383f);
    glVertex2f(-0.302f, 0.458f);
    glVertex2f(-0.304f, 0.43f);
    glVertex2f(-0.282f, 0.383f);
    glVertex2f(-0.253f, 0.339f);
    glVertex2f(-0.253f, 0.311f);
    glVertex2f(-0.236f, 0.272f);
    glVertex2f(-0.207f, 0.189f);
    glVertex2f(-0.229f, 0.185f);
    glVertex2f(-0.251f, 0.193f);
    glVertex2f(-0.240f, 0.165f);
    glVertex2f(-0.209f, 0.122f);
    glVertex2f(-0.204f, 0.09f);
    glVertex2f(-0.193f, 0.07f);
    glVertex2f(-0.171f, 0.058f);
    glVertex2f(-0.180f, 0.043f);
    glVertex2f(-0.211f, 0.035f);
    glVertex2f(-0.211f, 0.019f);
    glVertex2f(-0.227f, -0.025f);
    glVertex2f(-0.269f, -0.096f);
    glVertex2f(-0.291f, -0.108f);
    glVertex2f(-0.296f, -0.139f);
    glVertex2f(-0.320f, -0.155f);
    glVertex2f(-0.364f, -0.226f);
    glVertex2f(-0.411f, -0.305f);
    glVertex2f(-0.336f, -0.238f);
    glVertex2f(-0.264f, -0.175f);
    glVertex2f(-0.211f, -0.131f);
    glVertex2f(-0.180f, -0.115f);
    glVertex2f(-0.147f, -0.111f);
    glVertex2f(-0.136f, -0.092f);
    glVertex2f(-0.138f, -0.08f);
    glVertex2f(-0.129f, -0.076f);
    glVertex2f(-0.120f, -0.092f);
    glVertex2f(-0.116f, -0.115f);
    glVertex2f(-0.120f, -0.127f);
    glVertex2f(-0.122f, -0.218f);
    glVertex2f(-0.124f, -0.297f);
    glVertex2f(-0.131f, -0.428f);
    glVertex2f(-0.131f, -0.483f);
    glVertex2f(-0.124f, -0.487f);
    glVertex2f(-0.102f, -0.349f);
    glVertex2f(-0.116f, -0.349f);
    glVertex2f(-0.113f, -0.325f);
    glVertex2f(-0.096f, -0.281f);
    glVertex2f(-0.080f, -0.163f);
    glVertex2f(-0.067f, -0.104f);
    glVertex2f(-0.051f, -0.143f);
    glVertex2f(-0.033f, -0.175f);
    glVertex2f(0.000f, -0.222f);
    glVertex2f(0.056f, -0.333f);
    glVertex2f(0.073f, -0.353f);
    glVertex2f(0.076f, -0.345f);
    glVertex2f(0.051f, -0.289f);
    glVertex2f(0.018f, -0.198f);
    glVertex2f(0.000f, -0.127f);
    glVertex2f(-0.002f, -0.088f);
    glVertex2f(-0.018f, -0.068f);
    glVertex2f(-0.016f, -0.056f);
    glVertex2f(0.013f, -0.048f);
    glVertex2f(0.051f, -0.056f);
    glVertex2f(0.098f, -0.064f);
    glVertex2f(0.124f, -0.06f);
    glVertex2f(0.147f, -0.06f);
    glVertex2f(0.149f, -0.044f);
    glVertex2f(0.176f, -0.048f);
    glVertex2f(0.224f, -0.044f);
    glVertex2f(0.262f, -0.048f);
    glVertex2f(0.298f, -0.044f);
    glVertex2f(0.320f, -0.028f);
    glVertex2f(0.342f, -0.021f);
    glVertex2f(0.369f, -0.017f);
    glVertex2f(0.398f, -0.017f);
    glVertex2f(0.418f, -0.005f);
    glVertex2f(0.453f, 0.003f);
    glVertex2f(0.447f, 0.019f);
    glVertex2f(0.433f, 0.019f);
    glVertex2f(0.418f, 0.031f);
    glVertex2f(0.384f, 0.035f);
    glVertex2f(0.351f, 0.035f);
    glVertex2f(0.320f, 0.062f);
    glVertex2f(0.296f, 0.058f);
    glVertex2f(0.278f, 0.055f);
    glVertex2f(0.264f, 0.062f);
    glVertex2f(0.262f, 0.074f);
    glVertex2f(0.256f, 0.086f);
    glVertex2f(0.247f, 0.074f);
    glVertex2f(0.233f, 0.066f);
    glVertex2f(0.227f, 0.066f);
    glVertex2f(0.209f, 0.082f);
    glVertex2f(0.198f, 0.09f);
    glVertex2f(0.178f, 0.086f);
    glVertex2f(0.149f, 0.062f);
    glVertex2f(0.138f, 0.07f);
    glVertex2f(0.118f, 0.09f);
    glVertex2f(0.104f, 0.098f);
    glVertex2f(0.084f, 0.106f);
    glVertex2f(0.064f, 0.106f);
    glVertex2f(0.042f, 0.094f);
    glVertex2f(0.022f, 0.094f);
    glVertex2f(0.002f, 0.09f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(254, 253, 14, 200);
    glVertex2f(-0.116f, -0.42f);
    glVertex2f(-0.124f, -0.44f);
    glVertex2f(-0.122f, -0.372f);
    glVertex2f(-0.107f, -0.36f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(254, 253, 14, 200);
    glVertex2f(-0.162f, -0.06f);
    glVertex2f(-0.193f, -0.076f);
    glVertex2f(-0.233f, -0.111f);
    glVertex2f(-0.262f, -0.131f);
    glVertex2f(-0.236f, -0.072f);
    glVertex2f(-0.182f, -0.001f);
    glVertex2f(-0.136f, 0.035f);
    glVertex2f(-0.118f, 0.027f);
    glVertex2f(-0.120f, -0.021f);
    glVertex2f(-0.129f, -0.044f);
    glVertex2f(-0.151f, -0.068f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(254, 253, 14, 200);
    glVertex2f(-0.324f, -0.21f);
    glVertex2f(-0.338f, -0.238f);
    glVertex2f(-0.327f, -0.198f);
    glVertex2f(-0.311f, -0.183f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(254, 253, 14, 200);
    glVertex2f(-0.353f, -0.23f);
    glVertex2f(-0.371f, -0.246f);
    glVertex2f(-0.338f, -0.187f);
    glVertex2f(-0.316f, -0.179f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(254, 253, 14, 200);
    glVertex2f(-0.187f, 0.161f);
    glVertex2f(-0.198f, 0.213f);
    glVertex2f(-0.207f, 0.256f);
    glVertex2f(-0.191f, 0.228f);
    glVertex2f(-0.178f, 0.177f);
    glVertex2f(-0.158f, 0.161f);
    glVertex2f(-0.140f, 0.13f);
    glVertex2f(-0.136f, 0.074f);
    glVertex2f(-0.160f, 0.074f);
    glVertex2f(-0.180f, 0.102f);
    glVertex2f(-0.189f, 0.122f);
    glVertex2f(-0.196f, 0.145f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(254, 253, 14, 200);
    glVertex2f(0.029f, 0.047f);
    glVertex2f(0.002f, 0.055f);
    glVertex2f(-0.029f, 0.066f);
    glVertex2f(-0.036f, 0.11f);
    glVertex2f(-0.031f, 0.138f);
    glVertex2f(-0.009f, 0.201f);
    glVertex2f(0.024f, 0.304f);
    glVertex2f(0.018f, 0.319f);
    glVertex2f(0.004f, 0.292f);
    glVertex2f(-0.011f, 0.244f);
    glVertex2f(-0.029f, 0.201f);
    glVertex2f(-0.047f, 0.165f);
    glVertex2f(-0.067f, 0.161f);
    glVertex2f(-0.084f, 0.173f);
    glVertex2f(-0.087f, 0.209f);
    glVertex2f(-0.084f, 0.248f);
    glVertex2f(-0.078f, 0.284f);
    glVertex2f(-0.076f, 0.327f);
    glVertex2f(-0.078f, 0.359f);
    glVertex2f(-0.082f, 0.379f);
    glVertex2f(-0.093f, 0.339f);
    glVertex2f(-0.102f, 0.248f);
    glVertex2f(-0.111f, 0.169f);
    glVertex2f(-0.127f, 0.134f);
    glVertex2f(-0.122f, 0.058f);
    glVertex2f(-0.107f, 0.027f);
    glVertex2f(-0.102f, -0.013f);
    glVertex2f(-0.118f, -0.048f);
    glVertex2f(-0.124f, -0.08f);
    glVertex2f(-0.107f, -0.104f);
    glVertex2f(-0.109f, -0.171f);
    glVertex2f(-0.116f, -0.23f);
    glVertex2f(-0.120f, -0.266f);
    glVertex2f(-0.118f, -0.285f);
    glVertex2f(-0.109f, -0.277f);
    glVertex2f(-0.098f, -0.222f);
    glVertex2f(-0.091f, -0.127f);
    glVertex2f(-0.080f, -0.088f);
    glVertex2f(-0.062f, -0.072f);
    glVertex2f(-0.044f, -0.1f);
    glVertex2f(-0.033f, -0.135f);
    glVertex2f(-0.013f, -0.183f);
    glVertex2f(0.004f, -0.202f);
    glVertex2f(0.004f, -0.167f);
    glVertex2f(-0.011f, -0.135f);
    glVertex2f(-0.024f, -0.1f);
    glVertex2f(-0.033f, -0.064f);
    glVertex2f(-0.031f, -0.036f);
    glVertex2f(0.011f, -0.021f);
    glVertex2f(0.058f, -0.028f);
    glVertex2f(0.116f, -0.028f);
    glVertex2f(0.158f, -0.017f);
    glVertex2f(0.200f, -0.013f);
    glVertex2f(0.233f, -0.025f);
    glVertex2f(0.304f, -0.021f);
    glVertex2f(0.344f, -0.001f);
    glVertex2f(0.353f, 0.007f);
    glVertex2f(0.338f, 0.023f);
    glVertex2f(0.307f, 0.019f);
    glVertex2f(0.260f, 0.011f);
    glVertex2f(0.233f, 0.023f);
    glVertex2f(0.213f, 0.039f);
    glVertex2f(0.198f, 0.027f);
    glVertex2f(0.182f, 0.035f);
    glVertex2f(0.167f, 0.043f);
    glVertex2f(0.138f, 0.027f);
    glVertex2f(0.104f, 0.031f);
    glVertex2f(0.073f, 0.039f);
    glEnd();
    glPopMatrix();
}

void scaleExplode(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    explode();
}
void translateExplode(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleExplode(0.5, 0.5, 0.0);
}

void Tank1Shoot()
{

    glPushMatrix();
    translateExplode(1.1, 0.53, 0.0);
    glPopMatrix();
}

void Tank2()
{
    glPushMatrix();
    glTranslatef(-positiontank, 0.0f, 0.0f);
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(120, 120, 120); // Red

    glVertex2f(-0.5f, 0.65f); // x, y
    glVertex2f(-0.5f, 0.37f); // x, y
    glVertex2f(0.02f, 0.4f);  // x, y
    glVertex2f(0.02f, 0.65f); // x, y
    glEnd();

    // Tank Head Lines
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.5f, 0.65f);
    glVertex2f(-0.5f, 0.37f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.5f, 0.37f);
    glVertex2f(0.02f, 0.4f);
    glEnd();

    // Tank Pipe
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(100, 100, 100); // Red
    glVertex2f(0.02f, 0.58f);
    glVertex2f(0.02f, 0.49f);
    glVertex2f(0.5f, 0.49f); // x, y
    glVertex2f(0.5f, 0.58f);
    glEnd();

    // Tank Pipe Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.58f);
    glVertex2f(0.02f, 0.58f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.02f, 0.49f);
    glVertex2f(0.5f, 0.49f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.49f);
    glVertex2f(0.5f, 0.58f);
    glEnd();

    // Tank Pipe Head
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(150, 150, 150); // Red
    glVertex2f(0.5f, 0.60f);   // x, y
    glVertex2f(0.5f, 0.47f);
    glVertex2f(0.72f, 0.47f);
    glVertex2f(0.72f, 0.60f);
    glEnd();

    // Tank Pipe Head Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.60f); // x, y
    glVertex2f(0.5f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.47f);
    glVertex2f(0.72f, 0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.72f, 0.47f);
    glVertex2f(0.72f, 0.60f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.5f, 0.60f);
    glVertex2f(0.72f, 0.60f);
    glEnd();

    // Tank Head Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(0.02f, 0.65f);
    glEnd();

    // TankTop
    glBegin(GL_QUADS);      // Each set of 4 vertices form a quad
    glColor3ub(80, 80, 80); // Red

    glVertex2f(-0.34f, 0.65f); // x, y
    glVertex2f(-0.12f, 0.65f); // x, y
    glVertex2f(-0.12f, 0.73f); // x, y
    glVertex2f(-0.34f, 0.73f); // x, y
    glEnd();
    // Tank Top Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.12f, 0.65f);
    glVertex2f(-0.12f, 0.73f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.12f, 0.73f);
    glVertex2f(-0.34f, 0.73f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.34f, 0.73f);
    glVertex2f(-0.34f, 0.65f);
    glEnd();

    // Tank Head Lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.02f, 0.65f);
    glVertex2f(-0.5f, 0.65f);
    glEnd();

    // Tank Tire
    GLfloat p2 = -0.2f;
    GLfloat q2 = 0.0f;
    GLfloat r2 = 0.7f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(p2, q2);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p2 + (r2 * cos(i * tp2 / triangle2)),
            q2 + (r2 * .4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire2
    GLfloat p3 = -0.2f;
    GLfloat q3 = 0.0f;
    GLfloat r3 = 0.65f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(p3, q3);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p3 + (r3 * cos(i * tp2 / triangle2)),
            q3 + (r3 * .4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire2
    GLfloat p4 = -0.2f;
    GLfloat q4 = 0.0f;
    GLfloat r4 = 0.60f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(147, 131, 115);
    glVertex2f(p4, q4);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p4 + (r4 * cos(i * tp2 / triangle2)),
            q4 + (r4 * .4 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Wheel Outline
    GLfloat p5 = -0.2f;
    GLfloat q5 = -0.05f;
    GLfloat r5 = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p5, q5);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p5 + (r5 * .6 * cos(i * tp2 / triangle2)),
            q5 + (r5 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Wheel
    GLfloat p6 = -0.2f;
    GLfloat q6 = -0.05f;
    GLfloat r6 = 0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p6, q6);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p6 + (r6 * .6 * cos(i * tp2 / triangle2)),
            q6 + (r6 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_1
    GLfloat p7 = -0.2f;
    GLfloat q7 = -0.05f;
    GLfloat r7 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p7, q7);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p7 + (r7 * .6 * cos(i * tp2 / triangle2)),
            q7 + (r7 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_2
    GLfloat p8 = -0.2f;
    GLfloat q8 = -0.05f;
    GLfloat r8 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p8, q8);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p8 + (r8 * .6 * cos(i * tp2 / triangle2)),
            q8 + (r8 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel 2

    // Tank Tire Whee2 Outline
    GLfloat p9 = -0.5f;
    GLfloat q9 = -0.05f;
    GLfloat r9 = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p9, q9);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p9 + (r9 * .6 * cos(i * tp2 / triangle2)),
            q9 + (r9 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee2
    GLfloat p10 = -0.5f;
    GLfloat q10 = -0.05f;
    GLfloat r10 = 0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p10, q10);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p10 + (r10 * .6 * cos(i * tp2 / triangle2)),
            q10 + (r10 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_1
    GLfloat p11 = -0.5f;
    GLfloat q11 = -0.05f;
    GLfloat r11 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p11, q11);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p11 + (r11 * .6 * cos(i * tp2 / triangle2)),
            q11 + (r11 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee1_2
    GLfloat p12 = -0.5f;
    GLfloat q12 = -0.05f;
    GLfloat r12 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p12, q12);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p12 + (r12 * .6 * cos(i * tp2 / triangle2)),
            q12 + (r12 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel 3

    // Tank Tire Wheel3 Outline
    GLfloat p13 = 0.1f;
    GLfloat q13 = -0.035f;
    GLfloat r13 = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p13, q13);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p13 + (r13 * .6 * cos(i * tp2 / triangle2)),
            q13 + (r13 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3
    GLfloat p14 = 0.1f;
    GLfloat q14 = -0.035f;
    GLfloat r14 = 0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p14, q14);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p14 + (r14 * .6 * cos(i * tp2 / triangle2)),
            q14 + (r14 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_1
    GLfloat p15 = 0.1f;
    GLfloat q15 = -0.035f;
    GLfloat r15 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p15, q15);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p15 + (r15 * .6 * cos(i * tp2 / triangle2)),
            q15 + (r15 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_2
    GLfloat p16 = 0.1f;
    GLfloat q16 = -0.035f;
    GLfloat r16 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p16, q16);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p16 + (r16 * .6 * cos(i * tp2 / triangle2)),
            q16 + (r16 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel Small 1

    // Tank Tire Small Wheel Outline
    GLfloat p17 = 0.30f;
    GLfloat q17 = 0.0f;
    GLfloat r17 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p17, q17);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p17 + (r17 * .6 * cos(i * tp2 / triangle2)),
            q17 + (r17 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3
    GLfloat p18 = 0.3f;
    GLfloat q18 = 0.0f;
    GLfloat r18 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p18, q18);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p18 + (r18 * .6 * cos(i * tp2 / triangle2)),
            q18 + (r18 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_1
    GLfloat p19 = 0.3f;
    GLfloat q19 = 0.0f;
    GLfloat r19 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p19, q19);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p19 + (r19 * .6 * cos(i * tp2 / triangle2)),
            q19 + (r19 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee3_2
    GLfloat p20 = 0.3f;
    GLfloat q20 = 0.0f;
    GLfloat r20 = 0.03f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p20, q20);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p20 + (r20 * .6 * cos(i * tp2 / triangle2)),
            q20 + (r20 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Wheel Small 2

    // Tank Tire Small Wheel Outline
    GLfloat p21 = -0.70f;
    GLfloat q21 = 0.0f;
    GLfloat r21 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p21, q21);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p21 + (r21 * .6 * cos(i * tp2 / triangle2)),
            q21 + (r21 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee Small 2
    GLfloat p22 = -0.7f;
    GLfloat q22 = 0.0f;
    GLfloat r22 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 113, 114);
    glVertex2f(p22, q22);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p22 + (r22 * .6 * cos(i * tp2 / triangle2)),
            q22 + (r22 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee SMall 2
    GLfloat p23 = -0.7f;
    GLfloat q23 = 0.0f;
    GLfloat r23 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p23, q23);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p23 + (r23 * .6 * cos(i * tp2 / triangle2)),
            q23 + (r23 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Tire Whee Small 2
    GLfloat p24 = -0.7f;
    GLfloat q24 = 0.0f;
    GLfloat r24 = 0.03f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 179, 180);
    glVertex2f(p24, q24);
    for (i = 0; i <= triangle2; i++)
    {
        glVertex2f(
            p24 + (r24 * .6 * cos(i * tp2 / triangle2)),
            q24 + (r24 * sin(i * tp2 / triangle2)));
    }
    glEnd();

    // Tank Body

    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(70, 70, 70);    // Red
    glVertex2f(-0.71f, 0.35f); // x, y
    glVertex2f(-0.84f, 0.11f); // x, y
    glVertex2f(0.41f, 0.19f);  // x, y
    glVertex2f(0.3f, 0.42f);   // x, y
    glEnd();

    // Tank body lines

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.71f, 0.35f); // x, y
    glVertex2f(-0.84f, 0.11f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.84f, 0.11f); // x, y
    glVertex2f(0.41f, 0.19f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.41f, 0.19f); // x, y
    glVertex2f(0.3f, 0.42f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.71f, 0.35f); // x, y
    glVertex2f(0.3f, 0.42f);
    glEnd();
    glPopMatrix();
}

void OpenLab()
{
    // Body

    glBegin(GL_TRIANGLE_FAN);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 200, 181);
    glVertex2f(-0.245f, -0.013f);
    glVertex2f(-0.436f, -0.104f);
    glVertex2f(-0.014f, -0.148f);
    glVertex2f(0.173f, -0.053f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 200, 181);
    glVertex2f(-0.245f, -0.013f);
    glVertex2f(-0.436f, -0.104f);
    glVertex2f(-0.014f, -0.148f);
    glVertex2f(0.173f, -0.053f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130, 158, 132);
    glVertex2f(-0.012f, -0.144f);
    glVertex2f(0.086f, -0.903f);
    glVertex2f(-0.432f, -0.836f);
    glVertex2f(-0.425f, -0.1f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130, 158, 132);
    glVertex2f(-0.012f, -0.144f);
    glVertex2f(0.086f, -0.903f);
    glVertex2f(-0.432f, -0.836f);
    glVertex2f(-0.425f, -0.1f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(190, 216, 187);
    glVertex2f(0.168f, -0.049f);
    glVertex2f(0.306f, -0.725f);
    glVertex2f(0.080f, -0.895f);
    glVertex2f(-0.018f, -0.144f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(190, 216, 187);
    glVertex2f(0.168f, -0.049f);
    glVertex2f(0.306f, -0.725f);
    glVertex2f(0.080f, -0.895f);
    glVertex2f(-0.018f, -0.144f);
    glEnd();

    // Open

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(68, 80, 72);
    glVertex2f(0.251f, -0.77f);
    glVertex2f(0.126f, -0.863f);
    glVertex2f(0.064f, -0.377f);
    glVertex2f(0.173f, -0.326f);
    glEnd();

    // Door
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(104, 114, 105);
    glVertex2f(0.173f, -0.353f);
    glVertex2f(0.177f, -0.338f);
    glVertex2f(0.308f, -0.255f);
    glVertex2f(0.382f, -0.685f);
    glVertex2f(0.235f, -0.753f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(104, 114, 105);
    glVertex2f(0.173f, -0.353f);
    glVertex2f(0.177f, -0.338f);
    glVertex2f(0.308f, -0.255f);
    glVertex2f(0.382f, -0.685f);
    glVertex2f(0.235f, -0.753f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(194, 216, 197);
    glVertex2f(0.163f, -0.362f);
    glVertex2f(0.230f, -0.769f);
    glVertex2f(0.243f, -0.761f);
    glVertex2f(0.174f, -0.35f);
    glEnd();
}

void CloseLab()
{
    // Body

    glBegin(GL_TRIANGLE_FAN);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 200, 181);
    glVertex2f(-0.245f, -0.013f);
    glVertex2f(-0.436f, -0.104f);
    glVertex2f(-0.014f, -0.148f);
    glVertex2f(0.173f, -0.053f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 200, 181);
    glVertex2f(-0.245f, -0.013f);
    glVertex2f(-0.436f, -0.104f);
    glVertex2f(-0.014f, -0.148f);
    glVertex2f(0.173f, -0.053f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130, 158, 132);
    glVertex2f(-0.012f, -0.144f);
    glVertex2f(0.086f, -0.903f);
    glVertex2f(-0.432f, -0.836f);
    glVertex2f(-0.425f, -0.1f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130, 158, 132);
    glVertex2f(-0.012f, -0.144f);
    glVertex2f(0.086f, -0.903f);
    glVertex2f(-0.432f, -0.836f);
    glVertex2f(-0.425f, -0.1f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(190, 216, 187);
    glVertex2f(0.168f, -0.049f);
    glVertex2f(0.306f, -0.725f);
    glVertex2f(0.080f, -0.895f);
    glVertex2f(-0.018f, -0.144f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(190, 216, 187);
    glVertex2f(0.168f, -0.049f);
    glVertex2f(0.306f, -0.725f);
    glVertex2f(0.080f, -0.895f);
    glVertex2f(-0.018f, -0.144f);
    glEnd();

    // Close

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(117, 132, 123);
    glVertex2f(0.180f, -0.329f);
    glVertex2f(0.251f, -0.772f);
    glVertex2f(0.122f, -0.839f);
    glVertex2f(0.056f, -0.38f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(192, 223, 192);
    glVertex2f(0.077f, -0.411f);
    glVertex2f(0.171f, -0.364f);
    glVertex2f(0.233f, -0.747f);
    glVertex2f(0.131f, -0.806f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(218, 210, 166);
    glVertex2f(0.137f, -0.617f);
    glVertex2f(0.124f, -0.542f);
    glVertex2f(0.171f, -0.522f);
    glVertex2f(0.182f, -0.601f);
    glEnd();
}

void Actor()
{
    glPushMatrix();
    glTranslatef(positionActor, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.0f, .9f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(0.05f, 0.0f);  // x, y

    glVertex2f(0.05f, 0.45f);  // x, y
    glVertex2f(-0.05f, 0.45f); // x, y
    glEnd();

    glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.7f, 1.0f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(0.03f, -0.45f); // x, y
    glVertex2f(0.03f, 0.0f);   // x, y
                               // x, y
    glEnd();

    // Head
    GLfloat p1 = 0.0f;
    GLfloat q1 = 0.61f;
    GLfloat r1 = 0.16f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (0.5 * r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Shoulder
    glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
    glColor3f(0.3f, 0.0f, 0.8f); // Red

    glVertex2f(-0.03f, 0.4f);  // x, y
    glVertex2f(-0.03f, 0.25f); // x, y

    glVertex2f(0.03f, 0.25f); // x, y
    glVertex2f(0.03f, 0.4f);  // x, y
    glEnd();

    // Hands
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3ub(232, 190, 172);

    glVertex2f(-0.02f, 0.25f); // x, y
    glVertex2f(-0.02f, 0.0f);  // x, y

    glVertex2f(0.02f, 0.0f);  // x, y
    glVertex2f(0.02f, 0.25f); // x, y
    glEnd();

    // Palm
    GLfloat p2 = 0.0f;
    GLfloat q2 = -0.05f;
    GLfloat r2 = 0.065f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (0.4 * r2 * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Shoe
    GLfloat p3 = -0.015f;
    GLfloat q3 = -0.47f;
    GLfloat r3 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (1.2 * r3 * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    glPopMatrix();
}

void rifle()
{
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.47f, 0.38f);
    glVertex2f(-0.47f, 0.35f);
    glVertex2f(-0.41f, 0.35f);
    glVertex2f(-0.41f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.33f, 0.23f);
    glVertex2f(-0.41f, 0.39f);
    glVertex2f(-0.41f, 0.34f);
    glVertex2f(-0.3f, 0.34f);
    glVertex2f(-0.3f, 0.39f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.3f, 0.39f);
    glVertex2f(-0.3f, 0.34f);
    glVertex2f(-0.1f, 0.34f);
    glVertex2f(-0.115f, 0.39f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.33f, 0.23f);
    glVertex2f(-0.115f, 0.39f);
    glVertex2f(-0.1f, 0.34f);
    glVertex2f(0.02f, 0.27f);
    glVertex2f(0.02f, 0.39f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.33f, 0.23f);
    glVertex2f(-0.2f, 0.34f);
    glVertex2f(-0.18f, 0.28f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(-0.13f, 0.34f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.32f, 0.34f);
    glVertex2f(-0.34f, 0.19f);
    glVertex2f(-0.28f, 0.19f);
    glVertex2f(-0.26f, 0.34f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.38f, 0.41f);
    glVertex2f(-0.38f, 0.39f);
    glVertex2f(-0.31f, 0.39f);
    glVertex2f(-0.35f, 0.41f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.26f, 0.34f);
    glVertex2f(-0.24f, 0.31f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.24f, 0.31f);
    glVertex2f(-0.22f, 0.31f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.2f, 0.34f);
    glVertex2f(-0.22f, 0.31f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.23f, 0.34f);
    glVertex2f(-0.23f, 0.32f);
    glEnd();
}

void greenArmy()
{

    glPushMatrix();
    glTranslatef(positionArmy, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.1f, 0.7f, .2f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(0.05f, 0.0f);  // x, y

    glVertex2f(0.05f, 0.45f);  // x, y
    glVertex2f(-0.05f, 0.45f); // x, y
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.2f, 0.6f, .2f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(0.03f, -0.45f); // x, y
    glVertex2f(0.03f, 0.0f);   // x, y
                               // x, y
    glEnd();

    // Head
    GLfloat p1 = 0.0f;
    GLfloat q1 = 0.61f;
    GLfloat r1 = 0.16f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (0.5 * r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Shoulder
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.1f, 0.5f, .2f); // Red

    glVertex2f(-0.03f, 0.35f); // x, y
    glVertex2f(-0.03f, 0.24f); // x, y

    glVertex2f(0.03f, 0.24f); // x, y
    glVertex2f(0.03f, 0.35f); // x, y
    glEnd();

    // Hands

    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3ub(232, 190, 172);

    glVertex2f(-0.21f, 0.33f); // x, y
    glVertex2f(-0.21f, 0.26f); // x, y

    glVertex2f(-0.03f, 0.26f); // x, y
    glVertex2f(-0.03f, 0.33f); // x, y
    glEnd();

    // Palm
    GLfloat p2 = -0.235f;
    GLfloat q2 = 0.295f;
    GLfloat r2 = 0.04f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (.7 * r2 * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    // Shoe
    GLfloat p3 = -0.015f;
    GLfloat q3 = -0.47f;
    GLfloat r3 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.5f, .2f);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (1.2 * r3 * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // War Helmet
    GLfloat p4 = 0.00f;
    GLfloat q4 = 0.72f;
    GLfloat r4 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(100, 170, 100);
    glVertex2f(p4, q4);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p4 + (0.8 * r4 * cos(i * PI / tringle2)),
            q4 + (r4 * sin(i * PI / tringle2)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 170, 100);
    glVertex2f(-0.08f, 0.72f); // x, y
    glVertex2f(-0.08f, 0.65f); // x, y
    glVertex2f(0.08f, 0.65f);  // x, y
    glVertex2f(0.08f, 0.72f);  // x, y
    glEnd();

    // War Helmet Strap
    glBegin(GL_TRIANGLES);     //
    glColor3ub(100, 170, 100); // rgb color picker

    glVertex2f(+.035f, .65f); // x, y
    glVertex2f(+0.005f, .65f);
    glVertex2f(+0.02f, 0.56f);
    glEnd();

    rifle();

    glPopMatrix();
}

void ashArmy()
{
    glPushMatrix();
    glTranslatef(positionArmy, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.6f, 0.6f, .6f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(0.05f, 0.0f);  // x, y

    glVertex2f(0.05f, 0.45f);  // x, y
    glVertex2f(-0.05f, 0.45f); // x, y
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.4f, .4f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(0.03f, -0.45f); // x, y
    glVertex2f(0.03f, 0.0f);   // x, y
                               // x, y
    glEnd();

    // Head
    GLfloat p1 = 0.0f;
    GLfloat q1 = 0.61f;
    GLfloat r1 = 0.16f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (0.5 * r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Shoulder
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.5f, .5f); // Red

    glVertex2f(-0.03f, 0.35f); // x, y
    glVertex2f(-0.03f, 0.24f); // x, y

    glVertex2f(0.03f, 0.24f); // x, y
    glVertex2f(0.03f, 0.35f); // x, y
    glEnd();

    // Hands

    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3ub(232, 190, 172);

    glVertex2f(-0.21f, 0.33f); // x, y
    glVertex2f(-0.21f, 0.26f); // x, y

    glVertex2f(-0.03f, 0.26f); // x, y
    glVertex2f(-0.03f, 0.33f); // x, y
    glEnd();

    // Palm
    GLfloat p2 = -0.235f;
    GLfloat q2 = 0.295f;
    GLfloat r2 = 0.04f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (.7 * r2 * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    // Shoe
    GLfloat p3 = -0.015f;
    GLfloat q3 = -0.47f;
    GLfloat r3 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.3f, 0.3f, .3f);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (1.2 * r3 * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // War Helmet
    GLfloat p4 = 0.00f;
    GLfloat q4 = 0.72f;
    GLfloat r4 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(80, 80, 80);
    glVertex2f(p4, q4);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p4 + (0.8 * r4 * cos(i * PI / tringle2)),
            q4 + (r4 * sin(i * PI / tringle2)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex2f(-0.08f, 0.72f); // x, y
    glVertex2f(-0.08f, 0.65f); // x, y
    glVertex2f(0.08f, 0.65f);  // x, y
    glVertex2f(0.08f, 0.72f);  // x, y
    glEnd();

    // War Helmet Strap
    glBegin(GL_TRIANGLES);  //
    glColor3ub(80, 80, 80); // rgb color picker

    glVertex2f(+.035f, .65f); // x, y
    glVertex2f(+0.005f, .65f);
    glVertex2f(+0.02f, 0.56f);
    glEnd();

    rifle();
    glPopMatrix();
}

void Muzzle()
{
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-.48, .365);
    glVertex2f(-.55, .365);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0, .5, 0.0);
    glVertex2f(-.50, .3625);
    glVertex2f(-.53, .3625);
    glEnd();
}

void greenArmyShoot()
{

    glPushMatrix();
    glTranslatef(positionArmy, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.1f, 0.7f, .2f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(0.05f, 0.0f);  // x, y

    glVertex2f(0.05f, 0.45f);  // x, y
    glVertex2f(-0.05f, 0.45f); // x, y
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.2f, 0.6f, .2f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(0.03f, -0.45f); // x, y
    glVertex2f(0.03f, 0.0f);   // x, y
                               // x, y
    glEnd();

    // Head
    GLfloat p1 = 0.0f;
    GLfloat q1 = 0.61f;
    GLfloat r1 = 0.16f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (0.5 * r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Shoulder
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.1f, 0.5f, .2f); // Red

    glVertex2f(-0.03f, 0.35f); // x, y
    glVertex2f(-0.03f, 0.24f); // x, y

    glVertex2f(0.03f, 0.24f); // x, y
    glVertex2f(0.03f, 0.35f); // x, y
    glEnd();

    // Hands

    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3ub(232, 190, 172);

    glVertex2f(-0.21f, 0.33f); // x, y
    glVertex2f(-0.21f, 0.26f); // x, y

    glVertex2f(-0.03f, 0.26f); // x, y
    glVertex2f(-0.03f, 0.33f); // x, y
    glEnd();

    // Palm
    GLfloat p2 = -0.235f;
    GLfloat q2 = 0.295f;
    GLfloat r2 = 0.04f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (.7 * r2 * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    // Shoe
    GLfloat p3 = -0.015f;
    GLfloat q3 = -0.47f;
    GLfloat r3 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.5f, .2f);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (1.2 * r3 * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // War Helmet
    GLfloat p4 = 0.00f;
    GLfloat q4 = 0.72f;
    GLfloat r4 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(100, 170, 100);
    glVertex2f(p4, q4);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p4 + (0.8 * r4 * cos(i * PI / tringle2)),
            q4 + (r4 * sin(i * PI / tringle2)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 170, 100);
    glVertex2f(-0.08f, 0.72f); // x, y
    glVertex2f(-0.08f, 0.65f); // x, y
    glVertex2f(0.08f, 0.65f);  // x, y
    glVertex2f(0.08f, 0.72f);  // x, y
    glEnd();

    // War Helmet Strap
    glBegin(GL_TRIANGLES);     //
    glColor3ub(100, 170, 100); // rgb color picker

    glVertex2f(+.035f, .65f); // x, y
    glVertex2f(+0.005f, .65f);
    glVertex2f(+0.02f, 0.56f);
    glEnd();

    rifle();
    Muzzle();
    glPopMatrix();
}

void ashArmyShoot()
{
    glPushMatrix();
    glTranslatef(positionArmy, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.6f, 0.6f, .6f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(0.05f, 0.0f);  // x, y

    glVertex2f(0.05f, 0.45f);  // x, y
    glVertex2f(-0.05f, 0.45f); // x, y
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.4f, .4f); // Red

    glVertex2f(-0.05f, 0.0f); // x, y
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(0.03f, -0.45f); // x, y
    glVertex2f(0.03f, 0.0f);   // x, y
                               // x, y
    glEnd();

    // Head
    GLfloat p1 = 0.0f;
    GLfloat q1 = 0.61f;
    GLfloat r1 = 0.16f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (0.5 * r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Shoulder
    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.5f, .5f); // Red

    glVertex2f(-0.03f, 0.35f); // x, y
    glVertex2f(-0.03f, 0.24f); // x, y

    glVertex2f(0.03f, 0.24f); // x, y
    glVertex2f(0.03f, 0.35f); // x, y
    glEnd();

    // Hands

    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3ub(232, 190, 172);

    glVertex2f(-0.21f, 0.33f); // x, y
    glVertex2f(-0.21f, 0.26f); // x, y

    glVertex2f(-0.03f, 0.26f); // x, y
    glVertex2f(-0.03f, 0.33f); // x, y
    glEnd();

    // Palm
    GLfloat p2 = -0.235f;
    GLfloat q2 = 0.295f;
    GLfloat r2 = 0.04f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232, 190, 172);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (.7 * r2 * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    // Shoe
    GLfloat p3 = -0.015f;
    GLfloat q3 = -0.47f;
    GLfloat r3 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.3f, 0.3f, .3f);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (1.2 * r3 * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // War Helmet
    GLfloat p4 = 0.00f;
    GLfloat q4 = 0.72f;
    GLfloat r4 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(80, 80, 80);
    glVertex2f(p4, q4);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p4 + (0.8 * r4 * cos(i * PI / tringle2)),
            q4 + (r4 * sin(i * PI / tringle2)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex2f(-0.08f, 0.72f); // x, y
    glVertex2f(-0.08f, 0.65f); // x, y
    glVertex2f(0.08f, 0.65f);  // x, y
    glVertex2f(0.08f, 0.72f);  // x, y
    glEnd();

    // War Helmet Strap
    glBegin(GL_TRIANGLES);  //
    glColor3ub(80, 80, 80); // rgb color picker

    glVertex2f(+.035f, .65f); // x, y
    glVertex2f(+0.005f, .65f);
    glVertex2f(+0.02f, 0.56f);
    glEnd();

    rifle();
    Muzzle();
    glPopMatrix();
}

void scaleGreenArmy(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    greenArmy();
}
void translateGreenArmy(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleGreenArmy(0.08, 0.08, 0.0);
}

void scaleAshArmy(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    ashArmy();
}
void translateAshArmy(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleAshArmy(0.08, 0.08, 0.0);
}

void scaleActor(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    Actor();
}
void translateActor(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleActor(0.2, 0.2, 0.0);
}

void scaleOpenLab(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    OpenLab();
}

void scaleCloseLab(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    CloseLab();
}

void translateOpenLab(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleOpenLab(0.6, 0.6, 0.0);
}

void translateCloseLab(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleCloseLab(0.6, 0.6, 0.0);
}

void scaleTank2(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    Tank2();
}
void translateTank2(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleTank2(0.15, 0.15, 0.15);
}

void scaleBrokeHouse1(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    BrokeHouse1();
}

void scaleTank1(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    Tank1();
}

void translateTank1(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleTank1(0.15, 0.15, 0.0);
}

void scaleTank1Shoot(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    Tank1Shoot();
}

void translateTank1Shoot(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleTank1Shoot(0.15, 0.15, 0.0);
}

void translateBrokeHouse1(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBrokeHouse1(0.6, 0.6, 0.0);
}

void scaleBrokeHouse2(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    BrokeHouse2();
}
void translateBrokeHouse2(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBrokeHouse2(0.52, 0.52, 0.0);
}

void scaleBrokeHouse3(float scale_X, float scale_Y, float scale_Z)
{

    glScalef(scale_X, scale_Y, scale_Z);
    BrokeHouse3();
}
void translateBrokeHouse3(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBrokeHouse3(0.6, 0.6, 0.0);
}

void scaleBrokeHouse4(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    BrokeHouse4();
}
void translateBrokeHouse4(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBrokeHouse4(0.6, 0.6, 0.0);
}

void scaleBrokeHouse5(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    BrokeHouse5();
}
void translateBrokeHouse5(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBrokeHouse5(0.7, 0.7, 0.0);
}

// translation function
void translateBoat1(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    Boat1();
}

void scaleBoat2(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    Boat2();
}
void translateBoat2(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBoat2(0.3, 0.3, 0.0);
}

void scaleBoat3(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    Boat3();
}
void translateBoat3(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBoat3(0.3, 0.3, 0.0);
}

void scaleBoat1(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    Boat1();
}

void scaleNuclear(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    Nuclear();
}

void translateNuclear(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleNuclear(0.5, 0.5, 0.0);
}

void ShowBoat1()
{
    scaleBoat1(0.7, 0.7, 0.0);
}

void ShowBoat2()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateBoat2(-0.85, -0.4, 0.0);
}

void ShowBoat3()
{

    translateBoat3(-0.85, -0.1, 0.0);
}

void ShowBrokeHouse1()
{
    translateBrokeHouse1(0.43, 0.365, 0.0);
}

void ShowBrokeHouse2()
{
    translateBrokeHouse2(0.43, 0.33, 0.0);
}

void ShowBrokeHouse3()
{
    translateBrokeHouse3(0.41, 0.365, 0.0);
}

void ShowBrokeHouse4()
{
    translateBrokeHouse4(0.42, 0.365, 0.0);
}

void ShowBrokeHouse5()
{
    translateBrokeHouse5(0.55, 0.41, 0.0);
}

void ShowNuclear()
{
    translateNuclear(-0.62, 0.55, 0.0);
}

void ShowTank1()
{
    translateTank1(-1.0, 0.1, 0.0);
}

void ShowTank1Shoot()
{
    translateTank1Shoot(-0.315, 0.1, 0.0);
}

void ShowTank2()
{

    glRotatef(180, 0.0, 1.0, 0.0);
    translateTank2(-1., 0.1, 0.0);
}

void ShowOpenLab()
{
    glPushMatrix();
    translateOpenLab(-0.80, -0.4, 0.0);
    glPopMatrix();
}

void ShowCloseLab()
{
    glPushMatrix();
    translateCloseLab(-0.80, -0.4, 0.0);
    glPopMatrix();
}

void ShowActor()
{
    translateActor(0.8, -0.8, 0.0);
}

void actor()
    {
        //Body
        glBegin(GL_QUADS);
        glColor3f(0.4f, 0.0f, .9f);

        glVertex2f(-0.05f, 0.0f);
        glVertex2f(0.05f, 0.0f);

        glVertex2f(0.05f, 0.45f);
        glVertex2f(-0.05f, 0.45f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 1.0f);

        glVertex2f(-0.05f, 0.0f);
        glVertex2f(-0.05f, -0.45f);
        glVertex2f(0.03f, -0.45f);
        glVertex2f(0.03f, 0.0f);

        glEnd();

        //Head
        GLfloat p8 = 0.0f;
        GLfloat q8 = 0.61f;
        GLfloat r8 = 0.16f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(196, 128, 59);
        glVertex2f(p8, q8);
        for (i = 0; i <= tringle2; i++)
        {
            glVertex2f(
                p8 + (0.5*r8 * cos(i * tp2 / tringle2)),
                q8 + (r8 * sin(i * tp2 / tringle2)));
        }
        glEnd();


        // sward
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(122,122,122);
        glVertex2f(-0.294f, 0.801f);
        glVertex2f(-0.330f, 0.888f);
        glVertex2f(-0.361f, 0.801f);
        glVertex2f(-0.341f, 0.418f);
        glVertex2f(-0.305f, 0.422f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(134,54,14);
        glVertex2f(-0.307f, 0.267f);
        glVertex2f(-0.307f, 0.398f);
        glVertex2f(-0.341f, 0.398f);
        glVertex2f(-0.341f, 0.267f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(82,27,0);
        glVertex2f(-0.358f, 0.398f);
        glVertex2f(-0.285f, 0.398f);
        glVertex2f(-0.285f, 0.422f);
        glVertex2f(-0.358f, 0.422f);
        glEnd();

        //Hands
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(232,191,171);
        glVertex2f(-0.290f, 0.358f);
        glVertex2f(-0.090f, 0.374f);
        glVertex2f(-0.090f, 0.299f);
        glVertex2f(-0.290f, 0.299f);
        glVertex2f(-0.305f, 0.287f);
        glVertex2f(-0.332f, 0.283f);
        glVertex2f(-0.345f, 0.303f);
        glVertex2f(-0.345f, 0.331f);
        glVertex2f(-0.336f, 0.354f);
        glVertex2f(-0.305f, 0.358f);
        glVertex2f(-0.318f, 0.37f);
        glVertex2f(-0.312f, 0.39f);
        glVertex2f(-0.294f, 0.374f);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(75,0,204);
        glVertex2f(-0.092f, 0.39f);
        glVertex2f(0.030f, 0.394f);
        glVertex2f(0.030f, 0.287f);
        glVertex2f(-0.092f, 0.287f);
        glEnd();


        //Shoe
        GLfloat p3 = -0.015f;
        GLfloat q3 = -0.47f;
        GLfloat r3 = 0.05f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.4f, 0.4f, 0.4f);
        glVertex2f(p3, q3);
        for (i = 0; i <= tringle2; i++)
        {
            glVertex2f(
                p3 + (1.2*r3 * cos(i * tp2 / tringle2)),
                q3 + (r3 * sin(i * tp2 / tringle2)));
        }
        glEnd();

    }

void ShowAshActor()
{
    translateAshArmy(0.8, 0.08, 0.0);
}

void ShowAshActor2()
{
    translateAshArmy(0.9, 0.08, 0.0);
}

void ShowAshActor3()
{
    translateAshArmy(0.95, 0.08, 0.0);
}

void ShowAshActor4()
{
    translateAshArmy(0.85, 0.08, 0.0);
}

void ShowGreenActor()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.8, 0.08, 0.0);
}

void ShowGreenActor2()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.9, 0.08, 0.0);
}
void ShowGreenActor3()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.95, 0.08, 0.0);
}

void ShowGreenActor4()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.85, 0.08, 0.0);
}

void ShowAshActorShoot()
{
    translateAshArmy(0.8, 0.08, 0.0);
}

void ShowAshActor2Shoot()
{
    translateAshArmy(0.9, 0.08, 0.0);
}

void ShowAshActor3Shoot()
{
    translateAshArmy(0.95, 0.08, 0.0);
}

void ShowAshActor4Shoot()
{
    translateAshArmy(0.85, 0.08, 0.0);
}

void ShowGreenActorShoot()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.8, 0.08, 0.0);
}

void ShowGreenActor2Shoot()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.9, 0.08, 0.0);
}
void ShowGreenActor3Shoot()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.95, 0.08, 0.0);
}

void ShowGreenActor4Shoot()
{
    glRotatef(180, 0.0, 1.0, 0.0);
    translateGreenArmy(0.85, 0.08, 0.0);
}

void Fire()
{
    glPushMatrix();
    glRotatef(180, positionBullet, 0, 0);

    // Red Coloring
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(216, 0, 26, 150);
    glVertex2f(0.060f, -0.558f);
    glVertex2f(0.080f, -0.566f);
    glVertex2f(0.069f, -0.629f);
    glVertex2f(0.089f, -0.657f);
    glVertex2f(0.111f, -0.661f);
    glVertex2f(0.129f, -0.669f);
    glVertex2f(0.131f, -0.708f);
    glVertex2f(0.144f, -0.724f);
    glVertex2f(0.144f, -0.783f);
    glVertex2f(0.189f, -0.898f);
    glVertex2f(0.164f, -0.708f);
    glVertex2f(0.193f, -0.712f);
    glVertex2f(0.220f, -0.768f);
    glVertex2f(0.251f, -0.704f);
    glVertex2f(0.260f, -0.661f);
    glVertex2f(0.242f, -0.633f);
    glVertex2f(0.260f, -0.586f);
    glVertex2f(0.258f, -0.562f);
    glVertex2f(0.287f, -0.57f);
    glVertex2f(0.304f, -0.562f);
    glVertex2f(0.309f, -0.487f);
    glVertex2f(0.296f, -0.447f);
    glVertex2f(0.342f, -0.538f);
    glVertex2f(0.358f, -0.554f);
    glVertex2f(0.338f, -0.499f);
    glVertex2f(0.311f, -0.428f);
    glVertex2f(0.300f, -0.384f);
    glVertex2f(0.316f, -0.372f);
    glVertex2f(0.327f, -0.412f);
    glVertex2f(0.342f, -0.463f);
    glVertex2f(0.358f, -0.459f);
    glVertex2f(0.364f, -0.432f);
    glVertex2f(0.360f, -0.416f);
    glVertex2f(0.371f, -0.392f);
    glVertex2f(0.382f, -0.396f);
    glVertex2f(0.387f, -0.455f);
    glVertex2f(0.402f, -0.471f);
    glVertex2f(0.422f, -0.447f);
    glVertex2f(0.429f, -0.372f);
    glVertex2f(0.427f, -0.345f);
    glVertex2f(0.409f, -0.325f);
    glVertex2f(0.418f, -0.297f);
    glVertex2f(0.411f, -0.262f);
    glVertex2f(0.442f, -0.297f);
    glVertex2f(0.478f, -0.329f);
    glVertex2f(0.473f, -0.297f);
    glVertex2f(0.442f, -0.242f);
    glVertex2f(0.427f, -0.226f);
    glVertex2f(0.436f, -0.202f);
    glVertex2f(0.444f, -0.175f);
    glVertex2f(0.462f, -0.198f);
    glVertex2f(0.480f, -0.175f);
    glVertex2f(0.496f, -0.155f);
    glVertex2f(0.502f, -0.115f);
    glVertex2f(0.496f, -0.096f);
    glVertex2f(0.476f, -0.08f);
    glVertex2f(0.464f, -0.08f);
    glVertex2f(0.464f, -0.056f);
    glVertex2f(0.480f, -0.032f);
    glVertex2f(0.456f, -0.009f);
    glVertex2f(0.504f, -0.001f);
    glVertex2f(0.533f, -0.005f);
    glVertex2f(0.540f, 0.007f);
    glVertex2f(0.518f, 0.023f);
    glVertex2f(0.484f, 0.023f);
    glVertex2f(0.440f, 0.023f);
    glVertex2f(0.464f, 0.074f);
    glVertex2f(0.440f, 0.114f);
    glVertex2f(0.420f, 0.126f);
    glVertex2f(0.429f, 0.142f);
    glVertex2f(0.453f, 0.149f);
    glVertex2f(0.429f, 0.189f);
    glVertex2f(0.413f, 0.24f);
    glVertex2f(0.433f, 0.264f);
    glVertex2f(0.447f, 0.311f);
    glVertex2f(0.416f, 0.335f);
    glVertex2f(0.393f, 0.367f);
    glVertex2f(0.418f, 0.414f);
    glVertex2f(0.444f, 0.458f);
    glVertex2f(0.389f, 0.418f);
    glVertex2f(0.382f, 0.418f);
    glVertex2f(0.351f, 0.442f);
    glVertex2f(0.373f, 0.493f);
    glVertex2f(0.358f, 0.509f);
    glVertex2f(0.333f, 0.517f);
    glVertex2f(0.351f, 0.541f);
    glVertex2f(0.373f, 0.557f);
    glVertex2f(0.378f, 0.604f);
    glVertex2f(0.393f, 0.616f);
    glVertex2f(0.409f, 0.624f);
    glVertex2f(0.427f, 0.687f);
    glVertex2f(0.382f, 0.663f);
    glVertex2f(0.376f, 0.636f);
    glVertex2f(0.362f, 0.62f);
    glVertex2f(0.344f, 0.604f);
    glVertex2f(0.322f, 0.588f);
    glVertex2f(0.318f, 0.557f);
    glVertex2f(0.289f, 0.588f);
    glVertex2f(0.267f, 0.62f);
    glVertex2f(0.287f, 0.643f);
    glVertex2f(0.258f, 0.647f);
    glVertex2f(0.224f, 0.636f);
    glVertex2f(0.211f, 0.675f);
    glVertex2f(0.189f, 0.659f);
    glVertex2f(0.156f, 0.667f);
    glVertex2f(0.138f, 0.655f);
    glVertex2f(0.120f, 0.726f);
    glVertex2f(0.133f, 0.798f);
    glVertex2f(0.129f, 0.841f);
    glVertex2f(0.096f, 0.853f);
    glVertex2f(0.080f, 0.841f);
    glVertex2f(0.073f, 0.794f);
    glVertex2f(0.073f, 0.762f);
    glVertex2f(0.022f, 0.73f);
    glVertex2f(0.002f, 0.778f);
    glVertex2f(-0.027f, 0.809f);
    glVertex2f(-0.033f, 0.857f);
    glVertex2f(-0.053f, 0.873f);
    glVertex2f(-0.084f, 0.869f);
    glVertex2f(-0.078f, 0.833f);
    glVertex2f(-0.116f, 0.873f);
    glVertex2f(-0.140f, 0.873f);
    glVertex2f(-0.158f, 0.833f);
    glVertex2f(-0.176f, 0.79f);
    glVertex2f(-0.193f, 0.77f);
    glVertex2f(-0.231f, 0.762f);
    glVertex2f(-0.227f, 0.73f);
    glVertex2f(-0.249f, 0.754f);
    glVertex2f(-0.284f, 0.794f);
    glVertex2f(-0.302f, 0.794f);
    glVertex2f(-0.302f, 0.734f);
    glVertex2f(-0.311f, 0.687f);
    glVertex2f(-0.316f, 0.647f);
    glVertex2f(-0.304f, 0.64f);
    glVertex2f(-0.318f, 0.596f);
    glVertex2f(-0.336f, 0.636f);
    glVertex2f(-0.349f, 0.643f);
    glVertex2f(-0.340f, 0.6f);
    glVertex2f(-0.362f, 0.572f);
    glVertex2f(-0.389f, 0.557f);
    glVertex2f(-0.422f, 0.58f);
    glVertex2f(-0.424f, 0.56f);
    glVertex2f(-0.458f, 0.584f);
    glVertex2f(-0.462f, 0.549f);
    glVertex2f(-0.469f, 0.513f);
    glVertex2f(-0.453f, 0.493f);
    glVertex2f(-0.449f, 0.462f);
    glVertex2f(-0.460f, 0.477f);
    glVertex2f(-0.496f, 0.501f);
    glVertex2f(-0.460f, 0.43f);
    glVertex2f(-0.469f, 0.379f);
    glVertex2f(-0.473f, 0.335f);
    glVertex2f(-0.571f, 0.402f);
    glVertex2f(-0.591f, 0.406f);
    glVertex2f(-0.551f, 0.371f);
    glVertex2f(-0.516f, 0.351f);
    glVertex2f(-0.464f, 0.315f);
    glVertex2f(-0.476f, 0.276f);
    glVertex2f(-0.536f, 0.292f);
    glVertex2f(-0.544f, 0.272f);
    glVertex2f(-0.476f, 0.24f);
    glVertex2f(-0.496f, 0.201f);
    glVertex2f(-0.500f, 0.161f);
    glVertex2f(-0.531f, 0.149f);
    glVertex2f(-0.547f, 0.114f);
    glVertex2f(-0.567f, 0.066f);
    glVertex2f(-0.629f, 0.031f);
    glVertex2f(-0.564f, 0.023f);
    glVertex2f(-0.549f, -0.021f);
    glVertex2f(-0.533f, -0.028f);
    glVertex2f(-0.549f, -0.076f);
    glVertex2f(-0.564f, -0.076f);
    glVertex2f(-0.582f, -0.108f);
    glVertex2f(-0.580f, -0.159f);
    glVertex2f(-0.656f, -0.179f);
    glVertex2f(-0.611f, -0.187f);
    glVertex2f(-0.576f, -0.175f);
    glVertex2f(-0.553f, -0.202f);
    glVertex2f(-0.567f, -0.25f);
    glVertex2f(-0.576f, -0.313f);
    glVertex2f(-0.589f, -0.333f);
    glVertex2f(-0.616f, -0.36f);
    glVertex2f(-0.636f, -0.408f);
    glVertex2f(-0.722f, -0.511f);
    glVertex2f(-0.647f, -0.436f);
    glVertex2f(-0.613f, -0.416f);
    glVertex2f(-0.596f, -0.424f);
    glVertex2f(-0.591f, -0.451f);
    glVertex2f(-0.567f, -0.487f);
    glVertex2f(-0.549f, -0.475f);
    glVertex2f(-0.524f, -0.424f);
    glVertex2f(-0.511f, -0.44f);
    glVertex2f(-0.478f, -0.424f);
    glVertex2f(-0.467f, -0.416f);
    glVertex2f(-0.467f, -0.467f);
    glVertex2f(-0.429f, -0.455f);
    glVertex2f(-0.447f, -0.515f);
    glVertex2f(-0.518f, -0.677f);
    glVertex2f(-0.478f, -0.633f);
    glVertex2f(-0.420f, -0.491f);
    glVertex2f(-0.409f, -0.503f);
    glVertex2f(-0.389f, -0.519f);
    glVertex2f(-0.364f, -0.495f);
    glVertex2f(-0.342f, -0.542f);
    glVertex2f(-0.358f, -0.582f);
    glVertex2f(-0.351f, -0.617f);
    glVertex2f(-0.382f, -0.744f);
    glVertex2f(-0.340f, -0.637f);
    glVertex2f(-0.318f, -0.657f);
    glVertex2f(-0.300f, -0.633f);
    glVertex2f(-0.296f, -0.613f);
    glVertex2f(-0.273f, -0.692f);
    glVertex2f(-0.249f, -0.696f);
    glVertex2f(-0.231f, -0.677f);
    glVertex2f(-0.244f, -0.736f);
    glVertex2f(-0.231f, -0.764f);
    glVertex2f(-0.209f, -0.791f);
    glVertex2f(-0.187f, -0.835f);
    glVertex2f(-0.151f, -0.835f);
    glVertex2f(-0.127f, -0.807f);
    glVertex2f(-0.111f, -0.93f);
    glVertex2f(-0.100f, -0.772f);
    glVertex2f(-0.084f, -0.76f);
    glVertex2f(-0.073f, -0.783f);
    glVertex2f(-0.060f, -0.807f);
    glVertex2f(-0.044f, -0.835f);
    glVertex2f(-0.049f, -0.874f);
    glVertex2f(-0.036f, -0.898f);
    glVertex2f(-0.016f, -0.894f);
    glVertex2f(0.002f, -0.866f);
    glVertex2f(0.000f, -0.823f);
    glVertex2f(-0.011f, -0.803f);
    glVertex2f(-0.007f, -0.756f);
    glVertex2f(-0.007f, -0.72f);
    glVertex2f(-0.004f, -0.685f);
    glVertex2f(-0.009f, -0.669f);
    glVertex2f(0.009f, -0.645f);
    glVertex2f(0.018f, -0.613f);
    glVertex2f(0.033f, -0.637f);
    glVertex2f(0.038f, -0.692f);
    glVertex2f(0.049f, -0.768f);
    glVertex2f(0.058f, -0.748f);
    glVertex2f(0.049f, -0.665f);
    glVertex2f(0.047f, -0.633f);
    glVertex2f(0.056f, -0.613f);
    glVertex2f(0.060f, -0.59f);
    glEnd();
    // Orange coloring

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(255, 122, 36, 150);
    glVertex2f(-0.044f, -0.4f);
    glVertex2f(-0.022f, -0.44f);
    glVertex2f(-0.007f, -0.432f);
    glVertex2f(-0.016f, -0.479f);
    glVertex2f(0.002f, -0.519f);
    glVertex2f(0.040f, -0.463f);
    glVertex2f(0.053f, -0.428f);
    glVertex2f(0.076f, -0.455f);
    glVertex2f(0.100f, -0.459f);
    glVertex2f(0.091f, -0.534f);
    glVertex2f(0.127f, -0.566f);
    glVertex2f(0.124f, -0.613f);
    glVertex2f(0.144f, -0.629f);
    glVertex2f(0.169f, -0.645f);
    glVertex2f(0.189f, -0.613f);
    glVertex2f(0.193f, -0.578f);
    glVertex2f(0.187f, -0.507f);
    glVertex2f(0.180f, -0.408f);
    glVertex2f(0.198f, -0.44f);
    glVertex2f(0.224f, -0.44f);
    glVertex2f(0.253f, -0.408f);
    glVertex2f(0.240f, -0.392f);
    glVertex2f(0.240f, -0.364f);
    glVertex2f(0.231f, -0.345f);
    glVertex2f(0.251f, -0.297f);
    glVertex2f(0.282f, -0.305f);
    glVertex2f(0.320f, -0.345f);
    glVertex2f(0.300f, -0.305f);
    glVertex2f(0.347f, -0.301f);
    glVertex2f(0.367f, -0.274f);
    glVertex2f(0.373f, -0.234f);
    glVertex2f(0.353f, -0.191f);
    glVertex2f(0.320f, -0.171f);
    glVertex2f(0.304f, -0.143f);
    glVertex2f(0.311f, -0.111f);
    glVertex2f(0.324f, -0.096f);
    glVertex2f(0.336f, -0.115f);
    glVertex2f(0.362f, -0.111f);
    glVertex2f(0.376f, -0.104f);
    glVertex2f(0.387f, -0.092f);
    glVertex2f(0.362f, -0.076f);
    glVertex2f(0.360f, -0.044f);
    glVertex2f(0.367f, -0.021f);
    glVertex2f(0.400f, 0.051f);
    glVertex2f(0.398f, 0.074f);
    glVertex2f(0.384f, 0.106f);
    glVertex2f(0.367f, 0.118f);
    glVertex2f(0.384f, 0.169f);
    glVertex2f(0.367f, 0.197f);
    glVertex2f(0.353f, 0.221f);
    glVertex2f(0.353f, 0.264f);
    glVertex2f(0.331f, 0.288f);
    glVertex2f(0.304f, 0.296f);
    glVertex2f(0.287f, 0.319f);
    glVertex2f(0.273f, 0.347f);
    glVertex2f(0.291f, 0.379f);
    glVertex2f(0.307f, 0.414f);
    glVertex2f(0.300f, 0.434f);
    glVertex2f(0.287f, 0.442f);
    glVertex2f(0.273f, 0.426f);
    glVertex2f(0.262f, 0.398f);
    glVertex2f(0.249f, 0.387f);
    glVertex2f(0.238f, 0.387f);
    glVertex2f(0.211f, 0.398f);
    glVertex2f(0.207f, 0.446f);
    glVertex2f(0.198f, 0.489f);
    glVertex2f(0.191f, 0.533f);
    glVertex2f(0.187f, 0.572f);
    glVertex2f(0.178f, 0.608f);
    glVertex2f(0.153f, 0.616f);
    glVertex2f(0.131f, 0.628f);
    glVertex2f(0.109f, 0.576f);
    glVertex2f(0.084f, 0.557f);
    glVertex2f(0.071f, 0.557f);
    glVertex2f(0.064f, 0.568f);
    glVertex2f(0.060f, 0.604f);
    glVertex2f(0.060f, 0.659f);
    glVertex2f(0.049f, 0.699f);
    glVertex2f(0.042f, 0.703f);
    glVertex2f(0.033f, 0.671f);
    glVertex2f(0.033f, 0.651f);
    glVertex2f(0.033f, 0.62f);
    glVertex2f(0.018f, 0.588f);
    glVertex2f(0.002f, 0.588f);
    glVertex2f(-0.004f, 0.62f);
    glVertex2f(-0.011f, 0.62f);
    glVertex2f(-0.013f, 0.568f);
    glVertex2f(-0.024f, 0.549f);
    glVertex2f(-0.038f, 0.584f);
    glVertex2f(-0.040f, 0.62f);
    glVertex2f(-0.076f, 0.675f);
    glVertex2f(-0.091f, 0.715f);
    glVertex2f(-0.104f, 0.75f);
    glVertex2f(-0.122f, 0.723f);
    glVertex2f(-0.102f, 0.655f);
    glVertex2f(-0.118f, 0.651f);
    glVertex2f(-0.140f, 0.695f);
    glVertex2f(-0.158f, 0.723f);
    glVertex2f(-0.171f, 0.726f);
    glVertex2f(-0.158f, 0.663f);
    glVertex2f(-0.184f, 0.6f);
    glVertex2f(-0.189f, 0.541f);
    glVertex2f(-0.213f, 0.537f);
    glVertex2f(-0.258f, 0.521f);
    glVertex2f(-0.258f, 0.477f);
    glVertex2f(-0.273f, 0.45f);
    glVertex2f(-0.289f, 0.422f);
    glVertex2f(-0.313f, 0.43f);
    glVertex2f(-0.367f, 0.446f);
    glVertex2f(-0.391f, 0.493f);
    glVertex2f(-0.402f, 0.474f);
    glVertex2f(-0.407f, 0.414f);
    glVertex2f(-0.367f, 0.363f);
    glVertex2f(-0.340f, 0.315f);
    glVertex2f(-0.378f, 0.296f);
    glVertex2f(-0.398f, 0.308f);
    glVertex2f(-0.436f, 0.343f);
    glVertex2f(-0.442f, 0.327f);
    glVertex2f(-0.418f, 0.28f);
    glVertex2f(-0.393f, 0.248f);
    glVertex2f(-0.396f, 0.228f);
    glVertex2f(-0.422f, 0.225f);
    glVertex2f(-0.442f, 0.225f);
    glVertex2f(-0.433f, 0.173f);
    glVertex2f(-0.462f, 0.138f);
    glVertex2f(-0.460f, 0.09f);
    glVertex2f(-0.489f, 0.11f);
    glVertex2f(-0.500f, 0.074f);
    glVertex2f(-0.511f, 0.051f);
    glVertex2f(-0.487f, 0.043f);
    glVertex2f(-0.478f, 0.007f);
    glVertex2f(-0.520f, -0.032f);
    glVertex2f(-0.504f, -0.048f);
    glVertex2f(-0.480f, -0.044f);
    glVertex2f(-0.473f, -0.076f);
    glVertex2f(-0.487f, -0.108f);
    glVertex2f(-0.478f, -0.151f);
    glVertex2f(-0.456f, -0.155f);
    glVertex2f(-0.444f, -0.171f);
    glVertex2f(-0.462f, -0.214f);
    glVertex2f(-0.496f, -0.242f);
    glVertex2f(-0.460f, -0.222f);
    glVertex2f(-0.460f, -0.266f);
    glVertex2f(-0.471f, -0.293f);
    glVertex2f(-0.491f, -0.317f);
    glVertex2f(-0.484f, -0.337f);
    glVertex2f(-0.453f, -0.333f);
    glVertex2f(-0.442f, -0.357f);
    glVertex2f(-0.427f, -0.36f);
    glVertex2f(-0.404f, -0.368f);
    glVertex2f(-0.387f, -0.349f);
    glVertex2f(-0.371f, -0.317f);
    glVertex2f(-0.353f, -0.345f);
    glVertex2f(-0.349f, -0.392f);
    glVertex2f(-0.336f, -0.424f);
    glVertex2f(-0.309f, -0.443f);
    glVertex2f(-0.291f, -0.44f);
    glVertex2f(-0.276f, -0.467f);
    glVertex2f(-0.291f, -0.495f);
    glVertex2f(-0.291f, -0.507f);
    glVertex2f(-0.302f, -0.534f);
    glVertex2f(-0.282f, -0.55f);
    glVertex2f(-0.271f, -0.53f);
    glVertex2f(-0.251f, -0.534f);
    glVertex2f(-0.244f, -0.483f);
    glVertex2f(-0.244f, -0.455f);
    glVertex2f(-0.238f, -0.479f);
    glVertex2f(-0.213f, -0.487f);
    glVertex2f(-0.189f, -0.459f);
    glVertex2f(-0.178f, -0.471f);
    glVertex2f(-0.153f, -0.443f);
    glVertex2f(-0.149f, -0.507f);
    glVertex2f(-0.131f, -0.538f);
    glVertex2f(-0.158f, -0.574f);
    glVertex2f(-0.167f, -0.598f);
    glVertex2f(-0.178f, -0.649f);
    glVertex2f(-0.153f, -0.661f);
    glVertex2f(-0.129f, -0.657f);
    glVertex2f(-0.093f, -0.606f);
    glVertex2f(-0.069f, -0.479f);
    glVertex2f(-0.060f, -0.538f);
    glVertex2f(-0.047f, -0.566f);
    glVertex2f(-0.044f, -0.526f);
    glVertex2f(-0.053f, -0.471f);
    glVertex2f(-0.049f, -0.432f);
    glEnd();

    // Yellow Coloring

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(245, 233, 40, 150);
    glVertex2f(-0.044f, -0.266f);
    glVertex2f(-0.027f, -0.341f);
    glVertex2f(-0.007f, -0.353f);
    glVertex2f(0.004f, -0.4f);
    glVertex2f(0.018f, -0.392f);
    glVertex2f(0.011f, -0.337f);
    glVertex2f(0.022f, -0.321f);
    glVertex2f(0.031f, -0.305f);
    glVertex2f(0.049f, -0.345f);
    glVertex2f(0.082f, -0.38f);
    glVertex2f(0.127f, -0.436f);
    glVertex2f(0.153f, -0.499f);
    glVertex2f(0.151f, -0.424f);
    glVertex2f(0.129f, -0.341f);
    glVertex2f(0.133f, -0.297f);
    glVertex2f(0.164f, -0.297f);
    glVertex2f(0.182f, -0.27f);
    glVertex2f(0.207f, -0.281f);
    glVertex2f(0.233f, -0.281f);
    glVertex2f(0.251f, -0.23f);
    glVertex2f(0.227f, -0.198f);
    glVertex2f(0.196f, -0.194f);
    glVertex2f(0.171f, -0.159f);
    glVertex2f(0.202f, -0.127f);
    glVertex2f(0.216f, -0.119f);
    glVertex2f(0.251f, -0.139f);
    glVertex2f(0.262f, -0.123f);
    glVertex2f(0.242f, -0.092f);
    glVertex2f(0.244f, -0.052f);
    glVertex2f(0.271f, -0.048f);
    glVertex2f(0.313f, -0.044f);
    glVertex2f(0.322f, -0.025f);
    glVertex2f(0.260f, -0.028f);
    glVertex2f(0.296f, 0.007f);
    glVertex2f(0.340f, 0.007f);
    glVertex2f(0.331f, 0.039f);
    glVertex2f(0.278f, 0.023f);
    glVertex2f(0.358f, 0.035f);
    glVertex2f(0.447f, 0.047f);
    glVertex2f(0.411f, 0.082f);
    glVertex2f(0.311f, 0.086f);
    glVertex2f(0.280f, 0.102f);
    glVertex2f(0.282f, 0.138f);
    glVertex2f(0.304f, 0.157f);
    glVertex2f(0.316f, 0.181f);
    glVertex2f(0.353f, 0.225f);
    glVertex2f(0.396f, 0.28f);
    glVertex2f(0.304f, 0.252f);
    glVertex2f(0.198f, 0.256f);
    glVertex2f(0.211f, 0.3f);
    glVertex2f(0.227f, 0.327f);
    glVertex2f(0.207f, 0.367f);
    glVertex2f(0.211f, 0.41f);
    glVertex2f(0.189f, 0.387f);
    glVertex2f(0.196f, 0.43f);
    glVertex2f(0.171f, 0.414f);
    glVertex2f(0.144f, 0.383f);
    glVertex2f(0.136f, 0.45f);
    glVertex2f(0.124f, 0.489f);
    glVertex2f(0.107f, 0.41f);
    glVertex2f(0.084f, 0.414f);
    glVertex2f(0.084f, 0.446f);
    glVertex2f(0.093f, 0.489f);
    glVertex2f(0.080f, 0.529f);
    glVertex2f(0.049f, 0.537f);
    glVertex2f(0.011f, 0.525f);
    glVertex2f(-0.007f, 0.466f);
    glVertex2f(-0.027f, 0.442f);
    glVertex2f(-0.051f, 0.481f);
    glVertex2f(-0.071f, 0.533f);
    glVertex2f(-0.082f, 0.557f);
    glVertex2f(-0.087f, 0.477f);
    glVertex2f(-0.107f, 0.501f);
    glVertex2f(-0.118f, 0.576f);
    glVertex2f(-0.153f, 0.647f);
    glVertex2f(-0.158f, 0.557f);
    glVertex2f(-0.176f, 0.537f);
    glVertex2f(-0.158f, 0.513f);
    glVertex2f(-0.176f, 0.474f);
    glVertex2f(-0.178f, 0.458f);
    glVertex2f(-0.216f, 0.466f);
    glVertex2f(-0.247f, 0.414f);
    glVertex2f(-0.267f, 0.367f);
    glVertex2f(-0.273f, 0.339f);
    glVertex2f(-0.280f, 0.323f);
    glVertex2f(-0.358f, 0.43f);
    glVertex2f(-0.349f, 0.359f);
    glVertex2f(-0.318f, 0.304f);
    glVertex2f(-0.291f, 0.256f);
    glVertex2f(-0.293f, 0.205f);
    glVertex2f(-0.316f, 0.161f);
    glVertex2f(-0.336f, 0.142f);
    glVertex2f(-0.336f, 0.118f);
    glVertex2f(-0.393f, 0.122f);
    glVertex2f(-0.353f, 0.094f);
    glVertex2f(-0.447f, 0.082f);
    glVertex2f(-0.400f, 0.039f);
    glVertex2f(-0.376f, 0.003f);
    glVertex2f(-0.316f, 0.003f);
    glVertex2f(-0.371f, -0.06f);
    glVertex2f(-0.322f, -0.068f);
    glVertex2f(-0.320f, -0.131f);
    glVertex2f(-0.356f, -0.175f);
    glVertex2f(-0.351f, -0.218f);
    glVertex2f(-0.358f, -0.27f);
    glVertex2f(-0.320f, -0.297f);
    glVertex2f(-0.282f, -0.289f);
    glVertex2f(-0.278f, -0.266f);
    glVertex2f(-0.253f, -0.321f);
    glVertex2f(-0.229f, -0.309f);
    glVertex2f(-0.193f, -0.301f);
    glVertex2f(-0.187f, -0.341f);
    glVertex2f(-0.171f, -0.329f);
    glVertex2f(-0.167f, -0.297f);
    glVertex2f(-0.162f, -0.333f);
    glVertex2f(-0.131f, -0.317f);
    glVertex2f(-0.124f, -0.274f);
    glVertex2f(-0.111f, -0.25f);
    glVertex2f(-0.107f, -0.341f);
    glVertex2f(-0.098f, -0.388f);
    glVertex2f(-0.091f, -0.412f);
    glVertex2f(-0.087f, -0.333f);
    glVertex2f(-0.064f, -0.321f);
    glVertex2f(-0.051f, -0.285f);
    glEnd();

    // Light Yellow

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(234, 241, 181, 150);
    glVertex2f(-0.082f, -0.165f);
    glVertex2f(-0.080f, -0.272f);
    glVertex2f(-0.071f, -0.173f);
    glVertex2f(-0.056f, -0.256f);
    glVertex2f(-0.051f, -0.201f);
    glVertex2f(-0.007f, -0.327f);
    glVertex2f(-0.027f, -0.209f);
    glVertex2f(0.016f, -0.304f);
    glVertex2f(0.004f, -0.201f);
    glVertex2f(0.029f, -0.288f);
    glVertex2f(0.038f, -0.221f);
    glVertex2f(0.111f, -0.394f);
    glVertex2f(0.064f, -0.197f);
    glVertex2f(0.071f, -0.185f);
    glVertex2f(0.133f, -0.268f);
    glVertex2f(0.142f, -0.264f);
    glVertex2f(0.084f, -0.145f);
    glVertex2f(0.093f, -0.142f);
    glVertex2f(0.124f, -0.205f);
    glVertex2f(0.104f, -0.102f);
    glVertex2f(0.127f, -0.09f);
    glVertex2f(0.173f, -0.11f);
    glVertex2f(0.178f, -0.082f);
    glVertex2f(0.136f, -0.07f);
    glVertex2f(0.216f, -0.066f);
    glVertex2f(0.164f, -0.035f);
    glVertex2f(0.213f, -0.015f);
    glVertex2f(0.196f, 0.005f);
    glVertex2f(0.213f, 0.025f);
    glVertex2f(0.356f, 0.052f);
    glVertex2f(0.338f, 0.064f);
    glVertex2f(0.260f, 0.064f);
    glVertex2f(0.231f, 0.084f);
    glVertex2f(0.180f, 0.072f);
    glVertex2f(0.169f, 0.115f);
    glVertex2f(0.233f, 0.131f);
    glVertex2f(0.307f, 0.214f);
    glVertex2f(0.309f, 0.226f);
    glVertex2f(0.260f, 0.218f);
    glVertex2f(0.260f, 0.23f);
    glVertex2f(0.116f, 0.183f);
    glVertex2f(0.176f, 0.238f);
    glVertex2f(0.184f, 0.25f);
    glVertex2f(0.162f, 0.25f);
    glVertex2f(0.149f, 0.246f);
    glVertex2f(0.200f, 0.329f);
    glVertex2f(0.198f, 0.364f);
    glVertex2f(0.162f, 0.333f);
    glVertex2f(0.169f, 0.36f);
    glVertex2f(0.133f, 0.337f);
    glVertex2f(0.087f, 0.27f);
    glVertex2f(0.073f, 0.289f);
    glVertex2f(0.120f, 0.404f);
    glVertex2f(0.124f, 0.432f);
    glVertex2f(0.049f, 0.317f);
    glVertex2f(0.062f, 0.396f);
    glVertex2f(0.027f, 0.337f);
    glVertex2f(0.031f, 0.467f);
    glVertex2f(0.013f, 0.396f);
    glVertex2f(-0.009f, 0.396f);
    glVertex2f(-0.016f, 0.412f);
    glVertex2f(-0.024f, 0.404f);
    glVertex2f(-0.038f, 0.416f);
    glVertex2f(-0.047f, 0.376f);
    glVertex2f(-0.062f, 0.479f);
    glVertex2f(-0.058f, 0.353f);
    glVertex2f(-0.069f, 0.416f);
    glVertex2f(-0.076f, 0.349f);
    glVertex2f(-0.100f, 0.44f);
    glVertex2f(-0.109f, 0.404f);
    glVertex2f(-0.136f, 0.554f);
    glVertex2f(-0.142f, 0.53f);
    glVertex2f(-0.140f, 0.455f);
    glVertex2f(-0.136f, 0.368f);
    glVertex2f(-0.151f, 0.388f);
    glVertex2f(-0.156f, 0.297f);
    glVertex2f(-0.187f, 0.353f);
    glVertex2f(-0.180f, 0.317f);
    glVertex2f(-0.209f, 0.353f);
    glVertex2f(-0.224f, 0.349f);
    glVertex2f(-0.189f, 0.274f);
    glVertex2f(-0.211f, 0.289f);
    glVertex2f(-0.200f, 0.242f);
    glVertex2f(-0.238f, 0.281f);
    glVertex2f(-0.229f, 0.238f);
    glVertex2f(-0.280f, 0.301f);
    glVertex2f(-0.260f, 0.242f);
    glVertex2f(-0.211f, 0.171f);
    glVertex2f(-0.247f, 0.179f);
    glVertex2f(-0.251f, 0.159f);
    glVertex2f(-0.247f, 0.143f);
    glVertex2f(-0.238f, 0.139f);
    glVertex2f(-0.276f, 0.123f);
    glVertex2f(-0.331f, 0.108f);
    glVertex2f(-0.289f, 0.092f);
    glVertex2f(-0.347f, 0.068f);
    glVertex2f(-0.369f, 0.052f);
    glVertex2f(-0.393f, 0.056f);
    glVertex2f(-0.347f, 0.044f);
    glVertex2f(-0.353f, 0.032f);
    glVertex2f(-0.362f, 0.021f);
    glVertex2f(-0.329f, 0.028f);
    glVertex2f(-0.271f, 0.036f);
    glVertex2f(-0.264f, 0.025f);
    glVertex2f(-0.298f, 0.005f);
    glVertex2f(-0.329f, -0.023f);
    glVertex2f(-0.331f, -0.035f);
    glVertex2f(-0.313f, -0.039f);
    glVertex2f(-0.291f, -0.039f);
    glVertex2f(-0.269f, -0.031f);
    glVertex2f(-0.287f, -0.051f);
    glVertex2f(-0.311f, -0.086f);
    glVertex2f(-0.273f, -0.074f);
    glVertex2f(-0.191f, -0.039f);
    glVertex2f(-0.207f, -0.058f);
    glVertex2f(-0.200f, -0.086f);
    glVertex2f(-0.207f, -0.106f);
    glVertex2f(-0.193f, -0.102f);
    glVertex2f(-0.209f, -0.153f);
    glVertex2f(-0.209f, -0.165f);
    glVertex2f(-0.171f, -0.126f);
    glVertex2f(-0.151f, -0.114f);
    glVertex2f(-0.153f, -0.138f);
    glVertex2f(-0.178f, -0.256f);
    glVertex2f(-0.180f, -0.296f);
    glVertex2f(-0.140f, -0.189f);
    glVertex2f(-0.153f, -0.28f);
    glVertex2f(-0.100f, -0.161f);
    glVertex2f(-0.100f, -0.315f);
    glEnd();

    // Bright Yellow

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(249, 247, 234, 150);
    glVertex2f(-0.051f, 0.209f);
    glVertex2f(-0.071f, 0.232f);
    glVertex2f(-0.100f, 0.343f);
    glVertex2f(-0.096f, 0.284f);
    glVertex2f(-0.087f, 0.24f);
    glVertex2f(-0.107f, 0.264f);
    glVertex2f(-0.089f, 0.221f);
    glVertex2f(-0.102f, 0.209f);
    glVertex2f(-0.109f, 0.205f);
    glVertex2f(-0.131f, 0.24f);
    glVertex2f(-0.118f, 0.201f);
    glVertex2f(-0.122f, 0.193f);
    glVertex2f(-0.156f, 0.225f);
    glVertex2f(-0.129f, 0.173f);
    glVertex2f(-0.104f, 0.134f);
    glVertex2f(-0.138f, 0.145f);
    glVertex2f(-0.140f, 0.13f);
    glVertex2f(-0.193f, 0.142f);
    glVertex2f(-0.171f, 0.126f);
    glVertex2f(-0.111f, 0.094f);
    glVertex2f(-0.167f, 0.086f);
    glVertex2f(-0.147f, 0.066f);
    glVertex2f(-0.107f, 0.07f);
    glVertex2f(-0.129f, 0.047f);
    glVertex2f(-0.127f, 0.031f);
    glVertex2f(-0.167f, 0.015f);
    glVertex2f(-0.142f, 0.007f);
    glVertex2f(-0.120f, 0.019f);
    glVertex2f(-0.124f, 0.007f);
    glVertex2f(-0.111f, 0.007f);
    glVertex2f(-0.120f, -0.017f);
    glVertex2f(-0.142f, -0.072f);
    glVertex2f(-0.113f, -0.04f);
    glVertex2f(-0.122f, -0.076f);
    glVertex2f(-0.129f, -0.096f);
    glVertex2f(-0.104f, -0.056f);
    glVertex2f(-0.122f, -0.104f);
    glVertex2f(-0.067f, -0.009f);
    glVertex2f(-0.076f, -0.092f);
    glVertex2f(-0.060f, -0.052f);
    glVertex2f(-0.051f, -0.025f);
    glVertex2f(-0.047f, -0.052f);
    glVertex2f(-0.042f, -0.028f);
    glVertex2f(-0.036f, -0.068f);
    glVertex2f(-0.022f, -0.068f);
    glVertex2f(-0.027f, -0.028f);
    glVertex2f(-0.020f, -0.064f);
    glVertex2f(-0.013f, -0.036f);
    glVertex2f(0.027f, -0.155f);
    glVertex2f(0.011f, -0.076f);
    glVertex2f(0.031f, -0.135f);
    glVertex2f(0.016f, -0.017f);
    glVertex2f(0.040f, -0.096f);
    glVertex2f(0.033f, -0.021f);
    glVertex2f(0.049f, -0.052f);
    glVertex2f(0.044f, -0.017f);
    glVertex2f(0.089f, -0.044f);
    glVertex2f(0.056f, -0.005f);
    glVertex2f(0.060f, 0.007f);
    glVertex2f(0.100f, -0.001f);
    glVertex2f(0.060f, 0.031f);
    glVertex2f(0.067f, 0.039f);
    glVertex2f(0.096f, 0.039f);
    glVertex2f(0.060f, 0.058f);
    glVertex2f(0.107f, 0.086f);
    glVertex2f(0.084f, 0.094f);
    glVertex2f(0.153f, 0.149f);
    glVertex2f(0.133f, 0.157f);
    glVertex2f(0.078f, 0.122f);
    glVertex2f(0.087f, 0.138f);
    glVertex2f(0.073f, 0.13f);
    glVertex2f(0.082f, 0.149f);
    glVertex2f(0.067f, 0.149f);
    glVertex2f(0.084f, 0.177f);
    glVertex2f(0.058f, 0.165f);
    glVertex2f(0.047f, 0.165f);
    glVertex2f(0.102f, 0.24f);
    glVertex2f(0.100f, 0.252f);
    glVertex2f(0.042f, 0.173f);
    glVertex2f(0.051f, 0.201f);
    glVertex2f(0.033f, 0.189f);
    glVertex2f(0.040f, 0.213f);
    glVertex2f(0.022f, 0.201f);
    glVertex2f(0.036f, 0.225f);
    glVertex2f(0.009f, 0.221f);
    glVertex2f(0.018f, 0.24f);
    glVertex2f(0.000f, 0.225f);
    glVertex2f(0.024f, 0.272f);
    glVertex2f(0.013f, 0.272f);
    glVertex2f(-0.009f, 0.221f);
    glVertex2f(-0.016f, 0.284f);
    glVertex2f(-0.018f, 0.24f);
    glVertex2f(-0.029f, 0.339f);
    glVertex2f(-0.036f, 0.343f);
    glVertex2f(-0.036f, 0.272f);
    glVertex2f(-0.044f, 0.304f);
    glVertex2f(-0.056f, 0.248f);
    glVertex2f(-0.056f, 0.228f);
    glEnd();
    glPopMatrix();
}

void scaleFire1(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    Fire();
}

void translateFire1(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    glScalef(0.25, 0.25, 0);
}

void animateFire()
{
    glPushMatrix();
    glRotatef(180, 0, positionBullet, 0);
    explode();
    glPopMatrix();
}

void bexplode()
{
    glPushMatrix();
    glScalef(0.8 * -ScaleBullet, 0.8 * -ScaleBullet, 0);

    // Red Coloring
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(216, 0, 26, 200);
    glVertex2f(0.060f, -0.558f);
    glVertex2f(0.080f, -0.566f);
    glVertex2f(0.069f, -0.629f);
    glVertex2f(0.089f, -0.657f);
    glVertex2f(0.111f, -0.661f);
    glVertex2f(0.129f, -0.669f);
    glVertex2f(0.131f, -0.708f);
    glVertex2f(0.144f, -0.724f);
    glVertex2f(0.144f, -0.783f);
    glVertex2f(0.189f, -0.898f);
    glVertex2f(0.164f, -0.708f);
    glVertex2f(0.193f, -0.712f);
    glVertex2f(0.220f, -0.768f);
    glVertex2f(0.251f, -0.704f);
    glVertex2f(0.260f, -0.661f);
    glVertex2f(0.242f, -0.633f);
    glVertex2f(0.260f, -0.586f);
    glVertex2f(0.258f, -0.562f);
    glVertex2f(0.287f, -0.57f);
    glVertex2f(0.304f, -0.562f);
    glVertex2f(0.309f, -0.487f);
    glVertex2f(0.296f, -0.447f);
    glVertex2f(0.342f, -0.538f);
    glVertex2f(0.358f, -0.554f);
    glVertex2f(0.338f, -0.499f);
    glVertex2f(0.311f, -0.428f);
    glVertex2f(0.300f, -0.384f);
    glVertex2f(0.316f, -0.372f);
    glVertex2f(0.327f, -0.412f);
    glVertex2f(0.342f, -0.463f);
    glVertex2f(0.358f, -0.459f);
    glVertex2f(0.364f, -0.432f);
    glVertex2f(0.360f, -0.416f);
    glVertex2f(0.371f, -0.392f);
    glVertex2f(0.382f, -0.396f);
    glVertex2f(0.387f, -0.455f);
    glVertex2f(0.402f, -0.471f);
    glVertex2f(0.422f, -0.447f);
    glVertex2f(0.429f, -0.372f);
    glVertex2f(0.427f, -0.345f);
    glVertex2f(0.409f, -0.325f);
    glVertex2f(0.418f, -0.297f);
    glVertex2f(0.411f, -0.262f);
    glVertex2f(0.442f, -0.297f);
    glVertex2f(0.478f, -0.329f);
    glVertex2f(0.473f, -0.297f);
    glVertex2f(0.442f, -0.242f);
    glVertex2f(0.427f, -0.226f);
    glVertex2f(0.436f, -0.202f);
    glVertex2f(0.444f, -0.175f);
    glVertex2f(0.462f, -0.198f);
    glVertex2f(0.480f, -0.175f);
    glVertex2f(0.496f, -0.155f);
    glVertex2f(0.502f, -0.115f);
    glVertex2f(0.496f, -0.096f);
    glVertex2f(0.476f, -0.08f);
    glVertex2f(0.464f, -0.08f);
    glVertex2f(0.464f, -0.056f);
    glVertex2f(0.480f, -0.032f);
    glVertex2f(0.456f, -0.009f);
    glVertex2f(0.504f, -0.001f);
    glVertex2f(0.533f, -0.005f);
    glVertex2f(0.540f, 0.007f);
    glVertex2f(0.518f, 0.023f);
    glVertex2f(0.484f, 0.023f);
    glVertex2f(0.440f, 0.023f);
    glVertex2f(0.464f, 0.074f);
    glVertex2f(0.440f, 0.114f);
    glVertex2f(0.420f, 0.126f);
    glVertex2f(0.429f, 0.142f);
    glVertex2f(0.453f, 0.149f);
    glVertex2f(0.429f, 0.189f);
    glVertex2f(0.413f, 0.24f);
    glVertex2f(0.433f, 0.264f);
    glVertex2f(0.447f, 0.311f);
    glVertex2f(0.416f, 0.335f);
    glVertex2f(0.393f, 0.367f);
    glVertex2f(0.418f, 0.414f);
    glVertex2f(0.444f, 0.458f);
    glVertex2f(0.389f, 0.418f);
    glVertex2f(0.382f, 0.418f);
    glVertex2f(0.351f, 0.442f);
    glVertex2f(0.373f, 0.493f);
    glVertex2f(0.358f, 0.509f);
    glVertex2f(0.333f, 0.517f);
    glVertex2f(0.351f, 0.541f);
    glVertex2f(0.373f, 0.557f);
    glVertex2f(0.378f, 0.604f);
    glVertex2f(0.393f, 0.616f);
    glVertex2f(0.409f, 0.624f);
    glVertex2f(0.427f, 0.687f);
    glVertex2f(0.382f, 0.663f);
    glVertex2f(0.376f, 0.636f);
    glVertex2f(0.362f, 0.62f);
    glVertex2f(0.344f, 0.604f);
    glVertex2f(0.322f, 0.588f);
    glVertex2f(0.318f, 0.557f);
    glVertex2f(0.289f, 0.588f);
    glVertex2f(0.267f, 0.62f);
    glVertex2f(0.287f, 0.643f);
    glVertex2f(0.258f, 0.647f);
    glVertex2f(0.224f, 0.636f);
    glVertex2f(0.211f, 0.675f);
    glVertex2f(0.189f, 0.659f);
    glVertex2f(0.156f, 0.667f);
    glVertex2f(0.138f, 0.655f);
    glVertex2f(0.120f, 0.726f);
    glVertex2f(0.133f, 0.798f);
    glVertex2f(0.129f, 0.841f);
    glVertex2f(0.096f, 0.853f);
    glVertex2f(0.080f, 0.841f);
    glVertex2f(0.073f, 0.794f);
    glVertex2f(0.073f, 0.762f);
    glVertex2f(0.022f, 0.73f);
    glVertex2f(0.002f, 0.778f);
    glVertex2f(-0.027f, 0.809f);
    glVertex2f(-0.033f, 0.857f);
    glVertex2f(-0.053f, 0.873f);
    glVertex2f(-0.084f, 0.869f);
    glVertex2f(-0.078f, 0.833f);
    glVertex2f(-0.116f, 0.873f);
    glVertex2f(-0.140f, 0.873f);
    glVertex2f(-0.158f, 0.833f);
    glVertex2f(-0.176f, 0.79f);
    glVertex2f(-0.193f, 0.77f);
    glVertex2f(-0.231f, 0.762f);
    glVertex2f(-0.227f, 0.73f);
    glVertex2f(-0.249f, 0.754f);
    glVertex2f(-0.284f, 0.794f);
    glVertex2f(-0.302f, 0.794f);
    glVertex2f(-0.302f, 0.734f);
    glVertex2f(-0.311f, 0.687f);
    glVertex2f(-0.316f, 0.647f);
    glVertex2f(-0.304f, 0.64f);
    glVertex2f(-0.318f, 0.596f);
    glVertex2f(-0.336f, 0.636f);
    glVertex2f(-0.349f, 0.643f);
    glVertex2f(-0.340f, 0.6f);
    glVertex2f(-0.362f, 0.572f);
    glVertex2f(-0.389f, 0.557f);
    glVertex2f(-0.422f, 0.58f);
    glVertex2f(-0.424f, 0.56f);
    glVertex2f(-0.458f, 0.584f);
    glVertex2f(-0.462f, 0.549f);
    glVertex2f(-0.469f, 0.513f);
    glVertex2f(-0.453f, 0.493f);
    glVertex2f(-0.449f, 0.462f);
    glVertex2f(-0.460f, 0.477f);
    glVertex2f(-0.496f, 0.501f);
    glVertex2f(-0.460f, 0.43f);
    glVertex2f(-0.469f, 0.379f);
    glVertex2f(-0.473f, 0.335f);
    glVertex2f(-0.571f, 0.402f);
    glVertex2f(-0.591f, 0.406f);
    glVertex2f(-0.551f, 0.371f);
    glVertex2f(-0.516f, 0.351f);
    glVertex2f(-0.464f, 0.315f);
    glVertex2f(-0.476f, 0.276f);
    glVertex2f(-0.536f, 0.292f);
    glVertex2f(-0.544f, 0.272f);
    glVertex2f(-0.476f, 0.24f);
    glVertex2f(-0.496f, 0.201f);
    glVertex2f(-0.500f, 0.161f);
    glVertex2f(-0.531f, 0.149f);
    glVertex2f(-0.547f, 0.114f);
    glVertex2f(-0.567f, 0.066f);
    glVertex2f(-0.629f, 0.031f);
    glVertex2f(-0.564f, 0.023f);
    glVertex2f(-0.549f, -0.021f);
    glVertex2f(-0.533f, -0.028f);
    glVertex2f(-0.549f, -0.076f);
    glVertex2f(-0.564f, -0.076f);
    glVertex2f(-0.582f, -0.108f);
    glVertex2f(-0.580f, -0.159f);
    glVertex2f(-0.656f, -0.179f);
    glVertex2f(-0.611f, -0.187f);
    glVertex2f(-0.576f, -0.175f);
    glVertex2f(-0.553f, -0.202f);
    glVertex2f(-0.567f, -0.25f);
    glVertex2f(-0.576f, -0.313f);
    glVertex2f(-0.589f, -0.333f);
    glVertex2f(-0.616f, -0.36f);
    glVertex2f(-0.636f, -0.408f);
    glVertex2f(-0.722f, -0.511f);
    glVertex2f(-0.647f, -0.436f);
    glVertex2f(-0.613f, -0.416f);
    glVertex2f(-0.596f, -0.424f);
    glVertex2f(-0.591f, -0.451f);
    glVertex2f(-0.567f, -0.487f);
    glVertex2f(-0.549f, -0.475f);
    glVertex2f(-0.524f, -0.424f);
    glVertex2f(-0.511f, -0.44f);
    glVertex2f(-0.478f, -0.424f);
    glVertex2f(-0.467f, -0.416f);
    glVertex2f(-0.467f, -0.467f);
    glVertex2f(-0.429f, -0.455f);
    glVertex2f(-0.447f, -0.515f);
    glVertex2f(-0.518f, -0.677f);
    glVertex2f(-0.478f, -0.633f);
    glVertex2f(-0.420f, -0.491f);
    glVertex2f(-0.409f, -0.503f);
    glVertex2f(-0.389f, -0.519f);
    glVertex2f(-0.364f, -0.495f);
    glVertex2f(-0.342f, -0.542f);
    glVertex2f(-0.358f, -0.582f);
    glVertex2f(-0.351f, -0.617f);
    glVertex2f(-0.382f, -0.744f);
    glVertex2f(-0.340f, -0.637f);
    glVertex2f(-0.318f, -0.657f);
    glVertex2f(-0.300f, -0.633f);
    glVertex2f(-0.296f, -0.613f);
    glVertex2f(-0.273f, -0.692f);
    glVertex2f(-0.249f, -0.696f);
    glVertex2f(-0.231f, -0.677f);
    glVertex2f(-0.244f, -0.736f);
    glVertex2f(-0.231f, -0.764f);
    glVertex2f(-0.209f, -0.791f);
    glVertex2f(-0.187f, -0.835f);
    glVertex2f(-0.151f, -0.835f);
    glVertex2f(-0.127f, -0.807f);
    glVertex2f(-0.111f, -0.93f);
    glVertex2f(-0.100f, -0.772f);
    glVertex2f(-0.084f, -0.76f);
    glVertex2f(-0.073f, -0.783f);
    glVertex2f(-0.060f, -0.807f);
    glVertex2f(-0.044f, -0.835f);
    glVertex2f(-0.049f, -0.874f);
    glVertex2f(-0.036f, -0.898f);
    glVertex2f(-0.016f, -0.894f);
    glVertex2f(0.002f, -0.866f);
    glVertex2f(0.000f, -0.823f);
    glVertex2f(-0.011f, -0.803f);
    glVertex2f(-0.007f, -0.756f);
    glVertex2f(-0.007f, -0.72f);
    glVertex2f(-0.004f, -0.685f);
    glVertex2f(-0.009f, -0.669f);
    glVertex2f(0.009f, -0.645f);
    glVertex2f(0.018f, -0.613f);
    glVertex2f(0.033f, -0.637f);
    glVertex2f(0.038f, -0.692f);
    glVertex2f(0.049f, -0.768f);
    glVertex2f(0.058f, -0.748f);
    glVertex2f(0.049f, -0.665f);
    glVertex2f(0.047f, -0.633f);
    glVertex2f(0.056f, -0.613f);
    glVertex2f(0.060f, -0.59f);
    glEnd();
    // Orange coloring

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(255, 122, 36, 200);
    glVertex2f(-0.044f, -0.4f);
    glVertex2f(-0.022f, -0.44f);
    glVertex2f(-0.007f, -0.432f);
    glVertex2f(-0.016f, -0.479f);
    glVertex2f(0.002f, -0.519f);
    glVertex2f(0.040f, -0.463f);
    glVertex2f(0.053f, -0.428f);
    glVertex2f(0.076f, -0.455f);
    glVertex2f(0.100f, -0.459f);
    glVertex2f(0.091f, -0.534f);
    glVertex2f(0.127f, -0.566f);
    glVertex2f(0.124f, -0.613f);
    glVertex2f(0.144f, -0.629f);
    glVertex2f(0.169f, -0.645f);
    glVertex2f(0.189f, -0.613f);
    glVertex2f(0.193f, -0.578f);
    glVertex2f(0.187f, -0.507f);
    glVertex2f(0.180f, -0.408f);
    glVertex2f(0.198f, -0.44f);
    glVertex2f(0.224f, -0.44f);
    glVertex2f(0.253f, -0.408f);
    glVertex2f(0.240f, -0.392f);
    glVertex2f(0.240f, -0.364f);
    glVertex2f(0.231f, -0.345f);
    glVertex2f(0.251f, -0.297f);
    glVertex2f(0.282f, -0.305f);
    glVertex2f(0.320f, -0.345f);
    glVertex2f(0.300f, -0.305f);
    glVertex2f(0.347f, -0.301f);
    glVertex2f(0.367f, -0.274f);
    glVertex2f(0.373f, -0.234f);
    glVertex2f(0.353f, -0.191f);
    glVertex2f(0.320f, -0.171f);
    glVertex2f(0.304f, -0.143f);
    glVertex2f(0.311f, -0.111f);
    glVertex2f(0.324f, -0.096f);
    glVertex2f(0.336f, -0.115f);
    glVertex2f(0.362f, -0.111f);
    glVertex2f(0.376f, -0.104f);
    glVertex2f(0.387f, -0.092f);
    glVertex2f(0.362f, -0.076f);
    glVertex2f(0.360f, -0.044f);
    glVertex2f(0.367f, -0.021f);
    glVertex2f(0.400f, 0.051f);
    glVertex2f(0.398f, 0.074f);
    glVertex2f(0.384f, 0.106f);
    glVertex2f(0.367f, 0.118f);
    glVertex2f(0.384f, 0.169f);
    glVertex2f(0.367f, 0.197f);
    glVertex2f(0.353f, 0.221f);
    glVertex2f(0.353f, 0.264f);
    glVertex2f(0.331f, 0.288f);
    glVertex2f(0.304f, 0.296f);
    glVertex2f(0.287f, 0.319f);
    glVertex2f(0.273f, 0.347f);
    glVertex2f(0.291f, 0.379f);
    glVertex2f(0.307f, 0.414f);
    glVertex2f(0.300f, 0.434f);
    glVertex2f(0.287f, 0.442f);
    glVertex2f(0.273f, 0.426f);
    glVertex2f(0.262f, 0.398f);
    glVertex2f(0.249f, 0.387f);
    glVertex2f(0.238f, 0.387f);
    glVertex2f(0.211f, 0.398f);
    glVertex2f(0.207f, 0.446f);
    glVertex2f(0.198f, 0.489f);
    glVertex2f(0.191f, 0.533f);
    glVertex2f(0.187f, 0.572f);
    glVertex2f(0.178f, 0.608f);
    glVertex2f(0.153f, 0.616f);
    glVertex2f(0.131f, 0.628f);
    glVertex2f(0.109f, 0.576f);
    glVertex2f(0.084f, 0.557f);
    glVertex2f(0.071f, 0.557f);
    glVertex2f(0.064f, 0.568f);
    glVertex2f(0.060f, 0.604f);
    glVertex2f(0.060f, 0.659f);
    glVertex2f(0.049f, 0.699f);
    glVertex2f(0.042f, 0.703f);
    glVertex2f(0.033f, 0.671f);
    glVertex2f(0.033f, 0.651f);
    glVertex2f(0.033f, 0.62f);
    glVertex2f(0.018f, 0.588f);
    glVertex2f(0.002f, 0.588f);
    glVertex2f(-0.004f, 0.62f);
    glVertex2f(-0.011f, 0.62f);
    glVertex2f(-0.013f, 0.568f);
    glVertex2f(-0.024f, 0.549f);
    glVertex2f(-0.038f, 0.584f);
    glVertex2f(-0.040f, 0.62f);
    glVertex2f(-0.076f, 0.675f);
    glVertex2f(-0.091f, 0.715f);
    glVertex2f(-0.104f, 0.75f);
    glVertex2f(-0.122f, 0.723f);
    glVertex2f(-0.102f, 0.655f);
    glVertex2f(-0.118f, 0.651f);
    glVertex2f(-0.140f, 0.695f);
    glVertex2f(-0.158f, 0.723f);
    glVertex2f(-0.171f, 0.726f);
    glVertex2f(-0.158f, 0.663f);
    glVertex2f(-0.184f, 0.6f);
    glVertex2f(-0.189f, 0.541f);
    glVertex2f(-0.213f, 0.537f);
    glVertex2f(-0.258f, 0.521f);
    glVertex2f(-0.258f, 0.477f);
    glVertex2f(-0.273f, 0.45f);
    glVertex2f(-0.289f, 0.422f);
    glVertex2f(-0.313f, 0.43f);
    glVertex2f(-0.367f, 0.446f);
    glVertex2f(-0.391f, 0.493f);
    glVertex2f(-0.402f, 0.474f);
    glVertex2f(-0.407f, 0.414f);
    glVertex2f(-0.367f, 0.363f);
    glVertex2f(-0.340f, 0.315f);
    glVertex2f(-0.378f, 0.296f);
    glVertex2f(-0.398f, 0.308f);
    glVertex2f(-0.436f, 0.343f);
    glVertex2f(-0.442f, 0.327f);
    glVertex2f(-0.418f, 0.28f);
    glVertex2f(-0.393f, 0.248f);
    glVertex2f(-0.396f, 0.228f);
    glVertex2f(-0.422f, 0.225f);
    glVertex2f(-0.442f, 0.225f);
    glVertex2f(-0.433f, 0.173f);
    glVertex2f(-0.462f, 0.138f);
    glVertex2f(-0.460f, 0.09f);
    glVertex2f(-0.489f, 0.11f);
    glVertex2f(-0.500f, 0.074f);
    glVertex2f(-0.511f, 0.051f);
    glVertex2f(-0.487f, 0.043f);
    glVertex2f(-0.478f, 0.007f);
    glVertex2f(-0.520f, -0.032f);
    glVertex2f(-0.504f, -0.048f);
    glVertex2f(-0.480f, -0.044f);
    glVertex2f(-0.473f, -0.076f);
    glVertex2f(-0.487f, -0.108f);
    glVertex2f(-0.478f, -0.151f);
    glVertex2f(-0.456f, -0.155f);
    glVertex2f(-0.444f, -0.171f);
    glVertex2f(-0.462f, -0.214f);
    glVertex2f(-0.496f, -0.242f);
    glVertex2f(-0.460f, -0.222f);
    glVertex2f(-0.460f, -0.266f);
    glVertex2f(-0.471f, -0.293f);
    glVertex2f(-0.491f, -0.317f);
    glVertex2f(-0.484f, -0.337f);
    glVertex2f(-0.453f, -0.333f);
    glVertex2f(-0.442f, -0.357f);
    glVertex2f(-0.427f, -0.36f);
    glVertex2f(-0.404f, -0.368f);
    glVertex2f(-0.387f, -0.349f);
    glVertex2f(-0.371f, -0.317f);
    glVertex2f(-0.353f, -0.345f);
    glVertex2f(-0.349f, -0.392f);
    glVertex2f(-0.336f, -0.424f);
    glVertex2f(-0.309f, -0.443f);
    glVertex2f(-0.291f, -0.44f);
    glVertex2f(-0.276f, -0.467f);
    glVertex2f(-0.291f, -0.495f);
    glVertex2f(-0.291f, -0.507f);
    glVertex2f(-0.302f, -0.534f);
    glVertex2f(-0.282f, -0.55f);
    glVertex2f(-0.271f, -0.53f);
    glVertex2f(-0.251f, -0.534f);
    glVertex2f(-0.244f, -0.483f);
    glVertex2f(-0.244f, -0.455f);
    glVertex2f(-0.238f, -0.479f);
    glVertex2f(-0.213f, -0.487f);
    glVertex2f(-0.189f, -0.459f);
    glVertex2f(-0.178f, -0.471f);
    glVertex2f(-0.153f, -0.443f);
    glVertex2f(-0.149f, -0.507f);
    glVertex2f(-0.131f, -0.538f);
    glVertex2f(-0.158f, -0.574f);
    glVertex2f(-0.167f, -0.598f);
    glVertex2f(-0.178f, -0.649f);
    glVertex2f(-0.153f, -0.661f);
    glVertex2f(-0.129f, -0.657f);
    glVertex2f(-0.093f, -0.606f);
    glVertex2f(-0.069f, -0.479f);
    glVertex2f(-0.060f, -0.538f);
    glVertex2f(-0.047f, -0.566f);
    glVertex2f(-0.044f, -0.526f);
    glVertex2f(-0.053f, -0.471f);
    glVertex2f(-0.049f, -0.432f);
    glEnd();

    // Yellow Coloring

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(245, 233, 40, 200);
    glVertex2f(-0.044f, -0.266f);
    glVertex2f(-0.027f, -0.341f);
    glVertex2f(-0.007f, -0.353f);
    glVertex2f(0.004f, -0.4f);
    glVertex2f(0.018f, -0.392f);
    glVertex2f(0.011f, -0.337f);
    glVertex2f(0.022f, -0.321f);
    glVertex2f(0.031f, -0.305f);
    glVertex2f(0.049f, -0.345f);
    glVertex2f(0.082f, -0.38f);
    glVertex2f(0.127f, -0.436f);
    glVertex2f(0.153f, -0.499f);
    glVertex2f(0.151f, -0.424f);
    glVertex2f(0.129f, -0.341f);
    glVertex2f(0.133f, -0.297f);
    glVertex2f(0.164f, -0.297f);
    glVertex2f(0.182f, -0.27f);
    glVertex2f(0.207f, -0.281f);
    glVertex2f(0.233f, -0.281f);
    glVertex2f(0.251f, -0.23f);
    glVertex2f(0.227f, -0.198f);
    glVertex2f(0.196f, -0.194f);
    glVertex2f(0.171f, -0.159f);
    glVertex2f(0.202f, -0.127f);
    glVertex2f(0.216f, -0.119f);
    glVertex2f(0.251f, -0.139f);
    glVertex2f(0.262f, -0.123f);
    glVertex2f(0.242f, -0.092f);
    glVertex2f(0.244f, -0.052f);
    glVertex2f(0.271f, -0.048f);
    glVertex2f(0.313f, -0.044f);
    glVertex2f(0.322f, -0.025f);
    glVertex2f(0.260f, -0.028f);
    glVertex2f(0.296f, 0.007f);
    glVertex2f(0.340f, 0.007f);
    glVertex2f(0.331f, 0.039f);
    glVertex2f(0.278f, 0.023f);
    glVertex2f(0.358f, 0.035f);
    glVertex2f(0.447f, 0.047f);
    glVertex2f(0.411f, 0.082f);
    glVertex2f(0.311f, 0.086f);
    glVertex2f(0.280f, 0.102f);
    glVertex2f(0.282f, 0.138f);
    glVertex2f(0.304f, 0.157f);
    glVertex2f(0.316f, 0.181f);
    glVertex2f(0.353f, 0.225f);
    glVertex2f(0.396f, 0.28f);
    glVertex2f(0.304f, 0.252f);
    glVertex2f(0.198f, 0.256f);
    glVertex2f(0.211f, 0.3f);
    glVertex2f(0.227f, 0.327f);
    glVertex2f(0.207f, 0.367f);
    glVertex2f(0.211f, 0.41f);
    glVertex2f(0.189f, 0.387f);
    glVertex2f(0.196f, 0.43f);
    glVertex2f(0.171f, 0.414f);
    glVertex2f(0.144f, 0.383f);
    glVertex2f(0.136f, 0.45f);
    glVertex2f(0.124f, 0.489f);
    glVertex2f(0.107f, 0.41f);
    glVertex2f(0.084f, 0.414f);
    glVertex2f(0.084f, 0.446f);
    glVertex2f(0.093f, 0.489f);
    glVertex2f(0.080f, 0.529f);
    glVertex2f(0.049f, 0.537f);
    glVertex2f(0.011f, 0.525f);
    glVertex2f(-0.007f, 0.466f);
    glVertex2f(-0.027f, 0.442f);
    glVertex2f(-0.051f, 0.481f);
    glVertex2f(-0.071f, 0.533f);
    glVertex2f(-0.082f, 0.557f);
    glVertex2f(-0.087f, 0.477f);
    glVertex2f(-0.107f, 0.501f);
    glVertex2f(-0.118f, 0.576f);
    glVertex2f(-0.153f, 0.647f);
    glVertex2f(-0.158f, 0.557f);
    glVertex2f(-0.176f, 0.537f);
    glVertex2f(-0.158f, 0.513f);
    glVertex2f(-0.176f, 0.474f);
    glVertex2f(-0.178f, 0.458f);
    glVertex2f(-0.216f, 0.466f);
    glVertex2f(-0.247f, 0.414f);
    glVertex2f(-0.267f, 0.367f);
    glVertex2f(-0.273f, 0.339f);
    glVertex2f(-0.280f, 0.323f);
    glVertex2f(-0.358f, 0.43f);
    glVertex2f(-0.349f, 0.359f);
    glVertex2f(-0.318f, 0.304f);
    glVertex2f(-0.291f, 0.256f);
    glVertex2f(-0.293f, 0.205f);
    glVertex2f(-0.316f, 0.161f);
    glVertex2f(-0.336f, 0.142f);
    glVertex2f(-0.336f, 0.118f);
    glVertex2f(-0.393f, 0.122f);
    glVertex2f(-0.353f, 0.094f);
    glVertex2f(-0.447f, 0.082f);
    glVertex2f(-0.400f, 0.039f);
    glVertex2f(-0.376f, 0.003f);
    glVertex2f(-0.316f, 0.003f);
    glVertex2f(-0.371f, -0.06f);
    glVertex2f(-0.322f, -0.068f);
    glVertex2f(-0.320f, -0.131f);
    glVertex2f(-0.356f, -0.175f);
    glVertex2f(-0.351f, -0.218f);
    glVertex2f(-0.358f, -0.27f);
    glVertex2f(-0.320f, -0.297f);
    glVertex2f(-0.282f, -0.289f);
    glVertex2f(-0.278f, -0.266f);
    glVertex2f(-0.253f, -0.321f);
    glVertex2f(-0.229f, -0.309f);
    glVertex2f(-0.193f, -0.301f);
    glVertex2f(-0.187f, -0.341f);
    glVertex2f(-0.171f, -0.329f);
    glVertex2f(-0.167f, -0.297f);
    glVertex2f(-0.162f, -0.333f);
    glVertex2f(-0.131f, -0.317f);
    glVertex2f(-0.124f, -0.274f);
    glVertex2f(-0.111f, -0.25f);
    glVertex2f(-0.107f, -0.341f);
    glVertex2f(-0.098f, -0.388f);
    glVertex2f(-0.091f, -0.412f);
    glVertex2f(-0.087f, -0.333f);
    glVertex2f(-0.064f, -0.321f);
    glVertex2f(-0.051f, -0.285f);
    glEnd();

    // Light Yellow

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(234, 241, 181, 200);
    glVertex2f(-0.082f, -0.165f);
    glVertex2f(-0.080f, -0.272f);
    glVertex2f(-0.071f, -0.173f);
    glVertex2f(-0.056f, -0.256f);
    glVertex2f(-0.051f, -0.201f);
    glVertex2f(-0.007f, -0.327f);
    glVertex2f(-0.027f, -0.209f);
    glVertex2f(0.016f, -0.304f);
    glVertex2f(0.004f, -0.201f);
    glVertex2f(0.029f, -0.288f);
    glVertex2f(0.038f, -0.221f);
    glVertex2f(0.111f, -0.394f);
    glVertex2f(0.064f, -0.197f);
    glVertex2f(0.071f, -0.185f);
    glVertex2f(0.133f, -0.268f);
    glVertex2f(0.142f, -0.264f);
    glVertex2f(0.084f, -0.145f);
    glVertex2f(0.093f, -0.142f);
    glVertex2f(0.124f, -0.205f);
    glVertex2f(0.104f, -0.102f);
    glVertex2f(0.127f, -0.09f);
    glVertex2f(0.173f, -0.11f);
    glVertex2f(0.178f, -0.082f);
    glVertex2f(0.136f, -0.07f);
    glVertex2f(0.216f, -0.066f);
    glVertex2f(0.164f, -0.035f);
    glVertex2f(0.213f, -0.015f);
    glVertex2f(0.196f, 0.005f);
    glVertex2f(0.213f, 0.025f);
    glVertex2f(0.356f, 0.052f);
    glVertex2f(0.338f, 0.064f);
    glVertex2f(0.260f, 0.064f);
    glVertex2f(0.231f, 0.084f);
    glVertex2f(0.180f, 0.072f);
    glVertex2f(0.169f, 0.115f);
    glVertex2f(0.233f, 0.131f);
    glVertex2f(0.307f, 0.214f);
    glVertex2f(0.309f, 0.226f);
    glVertex2f(0.260f, 0.218f);
    glVertex2f(0.260f, 0.23f);
    glVertex2f(0.116f, 0.183f);
    glVertex2f(0.176f, 0.238f);
    glVertex2f(0.184f, 0.25f);
    glVertex2f(0.162f, 0.25f);
    glVertex2f(0.149f, 0.246f);
    glVertex2f(0.200f, 0.329f);
    glVertex2f(0.198f, 0.364f);
    glVertex2f(0.162f, 0.333f);
    glVertex2f(0.169f, 0.36f);
    glVertex2f(0.133f, 0.337f);
    glVertex2f(0.087f, 0.27f);
    glVertex2f(0.073f, 0.289f);
    glVertex2f(0.120f, 0.404f);
    glVertex2f(0.124f, 0.432f);
    glVertex2f(0.049f, 0.317f);
    glVertex2f(0.062f, 0.396f);
    glVertex2f(0.027f, 0.337f);
    glVertex2f(0.031f, 0.467f);
    glVertex2f(0.013f, 0.396f);
    glVertex2f(-0.009f, 0.396f);
    glVertex2f(-0.016f, 0.412f);
    glVertex2f(-0.024f, 0.404f);
    glVertex2f(-0.038f, 0.416f);
    glVertex2f(-0.047f, 0.376f);
    glVertex2f(-0.062f, 0.479f);
    glVertex2f(-0.058f, 0.353f);
    glVertex2f(-0.069f, 0.416f);
    glVertex2f(-0.076f, 0.349f);
    glVertex2f(-0.100f, 0.44f);
    glVertex2f(-0.109f, 0.404f);
    glVertex2f(-0.136f, 0.554f);
    glVertex2f(-0.142f, 0.53f);
    glVertex2f(-0.140f, 0.455f);
    glVertex2f(-0.136f, 0.368f);
    glVertex2f(-0.151f, 0.388f);
    glVertex2f(-0.156f, 0.297f);
    glVertex2f(-0.187f, 0.353f);
    glVertex2f(-0.180f, 0.317f);
    glVertex2f(-0.209f, 0.353f);
    glVertex2f(-0.224f, 0.349f);
    glVertex2f(-0.189f, 0.274f);
    glVertex2f(-0.211f, 0.289f);
    glVertex2f(-0.200f, 0.242f);
    glVertex2f(-0.238f, 0.281f);
    glVertex2f(-0.229f, 0.238f);
    glVertex2f(-0.280f, 0.301f);
    glVertex2f(-0.260f, 0.242f);
    glVertex2f(-0.211f, 0.171f);
    glVertex2f(-0.247f, 0.179f);
    glVertex2f(-0.251f, 0.159f);
    glVertex2f(-0.247f, 0.143f);
    glVertex2f(-0.238f, 0.139f);
    glVertex2f(-0.276f, 0.123f);
    glVertex2f(-0.331f, 0.108f);
    glVertex2f(-0.289f, 0.092f);
    glVertex2f(-0.347f, 0.068f);
    glVertex2f(-0.369f, 0.052f);
    glVertex2f(-0.393f, 0.056f);
    glVertex2f(-0.347f, 0.044f);
    glVertex2f(-0.353f, 0.032f);
    glVertex2f(-0.362f, 0.021f);
    glVertex2f(-0.329f, 0.028f);
    glVertex2f(-0.271f, 0.036f);
    glVertex2f(-0.264f, 0.025f);
    glVertex2f(-0.298f, 0.005f);
    glVertex2f(-0.329f, -0.023f);
    glVertex2f(-0.331f, -0.035f);
    glVertex2f(-0.313f, -0.039f);
    glVertex2f(-0.291f, -0.039f);
    glVertex2f(-0.269f, -0.031f);
    glVertex2f(-0.287f, -0.051f);
    glVertex2f(-0.311f, -0.086f);
    glVertex2f(-0.273f, -0.074f);
    glVertex2f(-0.191f, -0.039f);
    glVertex2f(-0.207f, -0.058f);
    glVertex2f(-0.200f, -0.086f);
    glVertex2f(-0.207f, -0.106f);
    glVertex2f(-0.193f, -0.102f);
    glVertex2f(-0.209f, -0.153f);
    glVertex2f(-0.209f, -0.165f);
    glVertex2f(-0.171f, -0.126f);
    glVertex2f(-0.151f, -0.114f);
    glVertex2f(-0.153f, -0.138f);
    glVertex2f(-0.178f, -0.256f);
    glVertex2f(-0.180f, -0.296f);
    glVertex2f(-0.140f, -0.189f);
    glVertex2f(-0.153f, -0.28f);
    glVertex2f(-0.100f, -0.161f);
    glVertex2f(-0.100f, -0.315f);
    glEnd();

    // Bright Yellow

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(249, 247, 234, 200);
    glVertex2f(-0.051f, 0.209f);
    glVertex2f(-0.071f, 0.232f);
    glVertex2f(-0.100f, 0.343f);
    glVertex2f(-0.096f, 0.284f);
    glVertex2f(-0.087f, 0.24f);
    glVertex2f(-0.107f, 0.264f);
    glVertex2f(-0.089f, 0.221f);
    glVertex2f(-0.102f, 0.209f);
    glVertex2f(-0.109f, 0.205f);
    glVertex2f(-0.131f, 0.24f);
    glVertex2f(-0.118f, 0.201f);
    glVertex2f(-0.122f, 0.193f);
    glVertex2f(-0.156f, 0.225f);
    glVertex2f(-0.129f, 0.173f);
    glVertex2f(-0.104f, 0.134f);
    glVertex2f(-0.138f, 0.145f);
    glVertex2f(-0.140f, 0.13f);
    glVertex2f(-0.193f, 0.142f);
    glVertex2f(-0.171f, 0.126f);
    glVertex2f(-0.111f, 0.094f);
    glVertex2f(-0.167f, 0.086f);
    glVertex2f(-0.147f, 0.066f);
    glVertex2f(-0.107f, 0.07f);
    glVertex2f(-0.129f, 0.047f);
    glVertex2f(-0.127f, 0.031f);
    glVertex2f(-0.167f, 0.015f);
    glVertex2f(-0.142f, 0.007f);
    glVertex2f(-0.120f, 0.019f);
    glVertex2f(-0.124f, 0.007f);
    glVertex2f(-0.111f, 0.007f);
    glVertex2f(-0.120f, -0.017f);
    glVertex2f(-0.142f, -0.072f);
    glVertex2f(-0.113f, -0.04f);
    glVertex2f(-0.122f, -0.076f);
    glVertex2f(-0.129f, -0.096f);
    glVertex2f(-0.104f, -0.056f);
    glVertex2f(-0.122f, -0.104f);
    glVertex2f(-0.067f, -0.009f);
    glVertex2f(-0.076f, -0.092f);
    glVertex2f(-0.060f, -0.052f);
    glVertex2f(-0.051f, -0.025f);
    glVertex2f(-0.047f, -0.052f);
    glVertex2f(-0.042f, -0.028f);
    glVertex2f(-0.036f, -0.068f);
    glVertex2f(-0.022f, -0.068f);
    glVertex2f(-0.027f, -0.028f);
    glVertex2f(-0.020f, -0.064f);
    glVertex2f(-0.013f, -0.036f);
    glVertex2f(0.027f, -0.155f);
    glVertex2f(0.011f, -0.076f);
    glVertex2f(0.031f, -0.135f);
    glVertex2f(0.016f, -0.017f);
    glVertex2f(0.040f, -0.096f);
    glVertex2f(0.033f, -0.021f);
    glVertex2f(0.049f, -0.052f);
    glVertex2f(0.044f, -0.017f);
    glVertex2f(0.089f, -0.044f);
    glVertex2f(0.056f, -0.005f);
    glVertex2f(0.060f, 0.007f);
    glVertex2f(0.100f, -0.001f);
    glVertex2f(0.060f, 0.031f);
    glVertex2f(0.067f, 0.039f);
    glVertex2f(0.096f, 0.039f);
    glVertex2f(0.060f, 0.058f);
    glVertex2f(0.107f, 0.086f);
    glVertex2f(0.084f, 0.094f);
    glVertex2f(0.153f, 0.149f);
    glVertex2f(0.133f, 0.157f);
    glVertex2f(0.078f, 0.122f);
    glVertex2f(0.087f, 0.138f);
    glVertex2f(0.073f, 0.13f);
    glVertex2f(0.082f, 0.149f);
    glVertex2f(0.067f, 0.149f);
    glVertex2f(0.084f, 0.177f);
    glVertex2f(0.058f, 0.165f);
    glVertex2f(0.047f, 0.165f);
    glVertex2f(0.102f, 0.24f);
    glVertex2f(0.100f, 0.252f);
    glVertex2f(0.042f, 0.173f);
    glVertex2f(0.051f, 0.201f);
    glVertex2f(0.033f, 0.189f);
    glVertex2f(0.040f, 0.213f);
    glVertex2f(0.022f, 0.201f);
    glVertex2f(0.036f, 0.225f);
    glVertex2f(0.009f, 0.221f);
    glVertex2f(0.018f, 0.24f);
    glVertex2f(0.000f, 0.225f);
    glVertex2f(0.024f, 0.272f);
    glVertex2f(0.013f, 0.272f);
    glVertex2f(-0.009f, 0.221f);
    glVertex2f(-0.016f, 0.284f);
    glVertex2f(-0.018f, 0.24f);
    glVertex2f(-0.029f, 0.339f);
    glVertex2f(-0.036f, 0.343f);
    glVertex2f(-0.036f, 0.272f);
    glVertex2f(-0.044f, 0.304f);
    glVertex2f(-0.056f, 0.248f);
    glVertex2f(-0.056f, 0.228f);
    glEnd();
    glPopMatrix();
}

void animateexplode()
{
    glPushMatrix();
    glRotatef(180, 0, positionBullet, 0);
    explode();
    glPopMatrix();
}

void scaleBexplode(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X, scale_Y, scale_Z);
    bexplode();
}
void translateBexplode(float trans_X, float trans_Y, float trans_Z)
{
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBexplode(0.05, 0.05, 0.0);
}

/*void scaleBullet(float scale_X, float scale_Y, float scale_Z)
{
    glScalef(scale_X,scale_Y,scale_Z);
    bullet();
}
void translateBullet(float trans_X, float trans_Y, float trans_Z){
    glTranslatef(trans_X, trans_Y, trans_Z);
    scaleBullet(0.01,0.01,0.0);}

void bulletAnimate(){
    glPushMatrix();
    glTranslatef(-positionBullet,.5*positionBullet, 0.0f);
    translateBullet(0.75,-0.3,0.0);
    glPopMatrix();
}*/

void GunFire()
{
    glPushMatrix();
    glTranslatef(-positiongun, 0.0, 0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.1, 0.05);
    glVertex2f(0.11, 0.05);
    glEnd;

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.07, 0.07);
    glVertex2f(0.079, 0.07);
    glEnd;

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.09);
    glVertex2f(0.059, 0.09);
    glEnd;

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.06, 0.1);
    glVertex2f(0.069, 0.1);
    glEnd;

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.03, 0.11);
    glVertex2f(0.039, 0.11);
    glEnd;

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.01, 0.04);
    glVertex2f(0.019, 0.04);
    glEnd;

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.022, 0.09);
    glVertex2f(0.025, 0.09);
    glEnd();
    glPopMatrix();
}

void ArmyGreen()
{
    glPushMatrix();
    ShowGreenActor();
    glPopMatrix();
    glPushMatrix();
    ShowGreenActor2();
    glPopMatrix();
    glPushMatrix();
    ShowGreenActor3();
    glPopMatrix();
    glPushMatrix();
    ShowGreenActor4();
    glPopMatrix();
}

void ArmyAsh()
{
    glPushMatrix();
    ShowAshActor();
    glPopMatrix();
    glPushMatrix();
    ShowAshActor2();
    glPopMatrix();
    glPushMatrix();
    ShowAshActor3();
    glPopMatrix();
    glPushMatrix();
    ShowAshActor4();
    glPopMatrix();
}

void ArmyGreenShoot()
{
    glPushMatrix();
    ShowGreenActorShoot();
    glPopMatrix();
    glPushMatrix();
    ShowGreenActor2Shoot();
    glPopMatrix();
    glPushMatrix();
    ShowGreenActor3Shoot();
    glPopMatrix();
    glPushMatrix();
    ShowGreenActor4Shoot();
    glPopMatrix();
}

void ArmyAshShoot()
{
    glPushMatrix();
    ShowAshActorShoot();
    glPopMatrix();
    glPushMatrix();
    ShowAshActor2Shoot();
    glPopMatrix();
    glPushMatrix();
    ShowAshActor3Shoot();
    glPopMatrix();
    glPushMatrix();
    ShowAshActor4Shoot();
    glPopMatrix();
}

void NuclearSmoke()
{

    glPushMatrix();
    glTranslatef(0.0, -positionSmoke, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(221, 221, 209);
    glVertex2f(0.022f, -0.092f);
    glVertex2f(0.031f, -0.119f);
    glVertex2f(0.031f, -0.143f);
    glVertex2f(0.031f, -0.21f);
    glVertex2f(0.031f, -0.246f);
    glVertex2f(0.024f, -0.293f);
    glVertex2f(0.013f, -0.317f);
    glVertex2f(-0.003f, -0.345f);
    glVertex2f(-0.023f, -0.357f);
    glVertex2f(-0.054f, -0.38f);
    glVertex2f(-0.065f, -0.392f);
    glVertex2f(-0.069f, -0.404f);
    glVertex2f(-0.058f, -0.408f);
    glVertex2f(-0.045f, -0.416f);
    glVertex2f(-0.038f, -0.428f);
    glVertex2f(-0.025f, -0.447f);
    glVertex2f(-0.016f, -0.463f);
    glVertex2f(0.008f, -0.487f);
    glVertex2f(0.011f, -0.495f);
    glVertex2f(0.024f, -0.507f);
    glVertex2f(0.017f, -0.53f);
    glVertex2f(0.013f, -0.546f);
    glVertex2f(0.011f, -0.578f);
    glVertex2f(-0.023f, -0.637f);
    glVertex2f(-0.049f, -0.665f);
    glVertex2f(-0.056f, -0.681f);
    glVertex2f(-0.034f, -0.7f);
    glVertex2f(-0.014f, -0.708f);
    glVertex2f(-0.016f, -0.752f);
    glVertex2f(-0.027f, -0.795f);
    glVertex2f(-0.043f, -0.835f);
    glVertex2f(-0.083f, -0.87f);
    glVertex2f(-0.120f, -0.878f);
    glVertex2f(-0.149f, -0.858f);
    glVertex2f(-0.176f, -0.811f);
    glVertex2f(-0.200f, -0.779f);
    glVertex2f(-0.209f, -0.752f);
    glVertex2f(-0.229f, -0.696f);
    glVertex2f(-0.238f, -0.637f);
    glVertex2f(-0.243f, -0.59f);
    glVertex2f(-0.232f, -0.554f);
    glVertex2f(-0.205f, -0.519f);
    glVertex2f(-0.183f, -0.479f);
    glVertex2f(-0.183f, -0.487f);
    glVertex2f(-0.256f, -0.416f);
    glVertex2f(-0.292f, -0.293f);
    glVertex2f(-0.269f, -0.163f);
    glVertex2f(-0.218f, -0.111f);
    glVertex2f(-0.300f, -0.064f);
    glVertex2f(-0.318f, 0.031f);
    glVertex2f(-0.318f, 0.098f);
    glVertex2f(-0.303f, 0.169f);
    glVertex2f(-0.278f, 0.217f);
    glVertex2f(-0.256f, 0.252f);
    glVertex2f(-0.234f, 0.272f);
    glVertex2f(-0.214f, 0.292f);
    glVertex2f(-0.229f, 0.331f);
    glVertex2f(-0.247f, 0.347f);
    glVertex2f(-0.274f, 0.438f);
    glVertex2f(-0.276f, 0.497f);
    glVertex2f(-0.258f, 0.549f);
    glVertex2f(-0.234f, 0.588f);
    glVertex2f(-0.212f, 0.608f);
    glVertex2f(-0.176f, 0.604f);
    glVertex2f(-0.143f, 0.592f);
    glVertex2f(-0.116f, 0.557f);
    glVertex2f(-0.103f, 0.537f);
    glVertex2f(-0.098f, 0.588f);
    glVertex2f(-0.083f, 0.64f);
    glVertex2f(-0.056f, 0.691f);
    glVertex2f(-0.038f, 0.707f);
    glVertex2f(-0.003f, 0.703f);
    glVertex2f(0.042f, 0.683f);
    glVertex2f(0.062f, 0.651f);
    glVertex2f(0.066f, 0.628f);
    glVertex2f(0.073f, 0.584f);
    glVertex2f(0.066f, 0.545f);
    glVertex2f(0.071f, 0.525f);
    glVertex2f(0.088f, 0.553f);
    glVertex2f(0.100f, 0.56f);
    glVertex2f(0.120f, 0.564f);
    glVertex2f(0.175f, 0.553f);
    glVertex2f(0.206f, 0.537f);
    glVertex2f(0.224f, 0.47f);
    glVertex2f(0.242f, 0.398f);
    glVertex2f(0.240f, 0.363f);
    glVertex2f(0.224f, 0.331f);
    glVertex2f(0.222f, 0.296f);
    glVertex2f(0.215f, 0.264f);
    glVertex2f(0.206f, 0.248f);
    glVertex2f(0.193f, 0.24f);
    glVertex2f(0.124f, 0.225f);
    glVertex2f(0.097f, 0.217f);
    glVertex2f(0.102f, 0.173f);
    glVertex2f(0.113f, 0.173f);
    glVertex2f(0.126f, 0.161f);
    glVertex2f(0.144f, 0.142f);
    glVertex2f(0.144f, 0.142f);
    glVertex2f(0.166f, 0.062f);
    glVertex2f(0.171f, 0.035f);
    glVertex2f(0.173f, -0.001f);
    glVertex2f(0.168f, -0.048f);
    glVertex2f(0.151f, -0.088f);
    glVertex2f(0.122f, -0.108f);
    glVertex2f(0.100f, -0.123f);
    glVertex2f(0.057f, -0.119f);
    glVertex2f(0.033f, -0.1f);
    glEnd();
    glPopMatrix();
}

void scaleNuclearSmoke()
{
    glPushMatrix();
    glScalef(0.18, 0.7, 0.0);
    NuclearSmoke();
    glPopMatrix();
}

void ShowNuclearSmoke()
{
    glPushMatrix();
    glTranslatef(-0.85, 0.9, 0.0);
    scaleNuclearSmoke();
    glPopMatrix();
}

void gunFireanimate()
{
    if (positionArmy < -8.0)
    {
        glPushMatrix();
        GunFire();
        glPopMatrix();
    }
}

//...

void Mountain()
{
    // Snow White Mountain
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(0.456f, 0.462 + .070f);
    glVertex2f(0.513f, 0.541 + .070f);
    glVertex2f(0.560f, 0.659 + .070f);
    glVertex2f(0.589f, 0.647 + .070f);
    glVertex2f(0.633f, 0.643 + .070f);
    glVertex2f(0.669f, 0.604 + .070f);
    glVertex2f(0.704f, 0.568 + .070f);
    glVertex2f(0.733f, 0.56 + .070f);
    glVertex2f(0.764f, 0.56 + .070f);
    glVertex2f(0.784f, 0.553 + .070f);
    glVertex2f(0.796f, 0.501 + .070f);
    glVertex2f(0.824f, 0.402 + .070f);
    glVertex2f(0.856f, 0.323 + .070f);
    glVertex2f(0.882f, 0.256 + .070f);
    glVertex2f(0.509f, 0.078 + .070f);
    glVertex2f(0.242f, 0.003 + .070f);
    glVertex2f(0.051f, 0.066 + .070f);
    glVertex2f(0.018f, 0.142 + .070f);
    glVertex2f(0.120f, 0.252 + .070f);
    glVertex2f(0.191f, 0.331 + .070f);
    glVertex2f(0.256f, 0.391 + .070f);
    glVertex2f(0.287f, 0.43 + .070f);
    glVertex2f(0.331f, 0.379 + .070f);
    glVertex2f(0.358f, 0.343 + .070f);
    glVertex2f(0.411f, 0.398 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(0.849f, 0.351 + .070f);
    glVertex2f(0.953f, 0.197 + .070f);
    glVertex2f(0.747f, 0.173 + .070f);
    glEnd();

    // Snow Blue Mountain Bit
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.193f, 0.327 + .070f);
    glVertex2f(0.253f, 0.394 + .070f);
    glVertex2f(0.267f, 0.394 + .070f);
    glVertex2f(0.282f, 0.351 + .070f);
    glVertex2f(0.293f, 0.343 + .070f);
    glVertex2f(0.318f, 0.284 + .070f);
    glVertex2f(0.329f, 0.248 + .070f);
    glVertex2f(0.333f, 0.232 + .070f);
    glVertex2f(0.329f, 0.189 + .070f);
    glVertex2f(0.311f, 0.13 + .070f);
    glVertex2f(0.211f, 0.138 + .070f);
    glVertex2f(0.158f, 0.185 + .070f);
    glVertex2f(0.140f, 0.205 + .070f);
    glVertex2f(0.109f, 0.232 + .070f);
    glVertex2f(0.142f, 0.264 + .070f);
    glVertex2f(0.151f, 0.284 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.460f, 0.315 + .070f);
    glVertex2f(0.431f, 0.331 + .070f);
    glVertex2f(0.416f, 0.327 + .070f);
    glVertex2f(0.407f, 0.315 + .070f);
    glVertex2f(0.411f, 0.3 + .070f);
    glVertex2f(0.424f, 0.284 + .070f);
    glVertex2f(0.440f, 0.26 + .070f);
    glVertex2f(0.476f, 0.244 + .070f);
    glVertex2f(0.513f, 0.28 + .070f);
    glVertex2f(0.504f, 0.292 + .070f);
    glVertex2f(0.500f, 0.296 + .070f);
    glVertex2f(0.493f, 0.3 + .070f);
    glVertex2f(0.480f, 0.308 + .070f);
    glVertex2f(0.469f, 0.315 + .070f);
    glVertex2f(0.467f, 0.315 + .070f);
    glVertex2f(0.462f, 0.323 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.578f, 0.643 + .070f);
    glVertex2f(0.587f, 0.647 + .070f);
    glVertex2f(0.598f, 0.643 + .070f);
    glVertex2f(0.587f, 0.636 + .070f);
    glVertex2f(0.573f, 0.636 + .070f);
    glVertex2f(0.564f, 0.643 + .070f);
    glVertex2f(0.562f, 0.651 + .070f);
    glVertex2f(0.567f, 0.651 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.649f, 0.64 + .070f);
    glVertex2f(0.662f, 0.628 + .070f);
    glVertex2f(0.662f, 0.624 + .070f);
    glVertex2f(0.649f, 0.628 + .070f);
    glVertex2f(0.640f, 0.632 + .070f);
    glVertex2f(0.636f, 0.643 + .070f);
    glVertex2f(0.642f, 0.651 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.598f, 0.418 + .070f);
    glVertex2f(0.593f, 0.394 + .070f);
    glVertex2f(0.593f, 0.371 + .070f);
    glVertex2f(0.591f, 0.351 + .070f);
    glVertex2f(0.587f, 0.339 + .070f);
    glVertex2f(0.578f, 0.276 + .070f);
    glVertex2f(0.560f, 0.252 + .070f);
    glVertex2f(0.520f, 0.276 + .070f);
    glVertex2f(0.502f, 0.292 + .070f);
    glVertex2f(0.467f, 0.315 + .070f);
    glVertex2f(0.449f, 0.331 + .070f);
    glVertex2f(0.436f, 0.347 + .070f);
    glVertex2f(0.429f, 0.359 + .070f);
    glVertex2f(0.422f, 0.371 + .070f);
    glVertex2f(0.409f, 0.367 + .070f);
    glVertex2f(0.400f, 0.371 + .070f);
    glVertex2f(0.391f, 0.375 + .070f);
    glVertex2f(0.402f, 0.391 + .070f);
    glVertex2f(0.431f, 0.422 + .070f);
    glVertex2f(0.453f, 0.454 + .070f);
    glVertex2f(0.476f, 0.481 + .070f);
    glVertex2f(0.507f, 0.525 + .070f);
    glVertex2f(0.513f, 0.537 + .070f);
    glVertex2f(0.524f, 0.557 + .070f);
    glVertex2f(0.542f, 0.604 + .070f);
    glVertex2f(0.556f, 0.636 + .070f);
    glVertex2f(0.560f, 0.616 + .070f);
    glVertex2f(0.571f, 0.596 + .070f);
    glVertex2f(0.584f, 0.584 + .070f);
    glVertex2f(0.598f, 0.58 + .070f);
    glVertex2f(0.609f, 0.58 + .070f);
    glVertex2f(0.611f, 0.553 + .070f);
    glVertex2f(0.613f, 0.529 + .070f);
    glVertex2f(0.618f, 0.501 + .070f);
    glVertex2f(0.638f, 0.466 + .070f);
    glVertex2f(0.644f, 0.454 + .070f);
    glVertex2f(0.649f, 0.45 + .070f);
    glVertex2f(0.651f, 0.438 + .070f);
    glVertex2f(0.640f, 0.422 + .070f);
    glVertex2f(0.642f, 0.43 + .070f);
    glVertex2f(0.638f, 0.438 + .070f);
    glVertex2f(0.633f, 0.434 + .070f);
    glVertex2f(0.624f, 0.43 + .070f);
    glVertex2f(0.616f, 0.442 + .070f);
    glVertex2f(0.611f, 0.45 + .070f);
    glVertex2f(0.607f, 0.462 + .070f);
    glVertex2f(0.602f, 0.47 + .070f);
    glVertex2f(0.600f, 0.458 + .070f);
    glVertex2f(0.604f, 0.45 + .070f);
    glVertex2f(0.607f, 0.434 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.627f, 0.355 + .070f);
    glVertex2f(0.624f, 0.343 + .070f);
    glVertex2f(0.627f, 0.339 + .070f);
    glVertex2f(0.633f, 0.347 + .070f);
    glVertex2f(0.638f, 0.351 + .070f);
    glVertex2f(0.642f, 0.339 + .070f);
    glVertex2f(0.638f, 0.323 + .070f);
    glVertex2f(0.633f, 0.304 + .070f);
    glVertex2f(0.622f, 0.276 + .070f);
    glVertex2f(0.580f, 0.288 + .070f);
    glVertex2f(0.593f, 0.351 + .070f);
    glVertex2f(0.607f, 0.371 + .070f);
    glVertex2f(0.613f, 0.383 + .070f);
    glVertex2f(0.611f, 0.402 + .070f);
    glVertex2f(0.616f, 0.414 + .070f);
    glVertex2f(0.618f, 0.422 + .070f);
    glVertex2f(0.624f, 0.398 + .070f);
    glVertex2f(0.629f, 0.387 + .070f);
    glVertex2f(0.627f, 0.371 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.678f, 0.458 + .070f);
    glVertex2f(0.676f, 0.481 + .070f);
    glVertex2f(0.667f, 0.489 + .070f);
    glVertex2f(0.658f, 0.485 + .070f);
    glVertex2f(0.656f, 0.477 + .070f);
    glVertex2f(0.653f, 0.466 + .070f);
    glVertex2f(0.653f, 0.45 + .070f);
    glVertex2f(0.647f, 0.458 + .070f);
    glVertex2f(0.647f, 0.477 + .070f);
    glVertex2f(0.642f, 0.497 + .070f);
    glVertex2f(0.633f, 0.533 + .070f);
    glVertex2f(0.627f, 0.572 + .070f);
    glVertex2f(0.622f, 0.596 + .070f);
    glVertex2f(0.629f, 0.604 + .070f);
    glVertex2f(0.636f, 0.604 + .070f);
    glVertex2f(0.649f, 0.588 + .070f);
    glVertex2f(0.669f, 0.564 + .070f);
    glVertex2f(0.687f, 0.557 + .070f);
    glVertex2f(0.696f, 0.557 + .070f);
    glVertex2f(0.687f, 0.576 + .070f);
    glVertex2f(0.678f, 0.592 + .070f);
    glVertex2f(0.698f, 0.572 + .070f);
    glVertex2f(0.724f, 0.564 + .070f);
    glVertex2f(0.742f, 0.56 + .070f);
    glVertex2f(0.736f, 0.553 + .070f);
    glVertex2f(0.724f, 0.553 + .070f);
    glVertex2f(0.720f, 0.545 + .070f);
    glVertex2f(0.736f, 0.513 + .070f);
    glVertex2f(0.742f, 0.497 + .070f);
    glVertex2f(0.738f, 0.474 + .070f);
    glVertex2f(0.733f, 0.454 + .070f);
    glVertex2f(0.729f, 0.446 + .070f);
    glVertex2f(0.747f, 0.434 + .070f);
    glVertex2f(0.764f, 0.414 + .070f);
    glVertex2f(0.769f, 0.394 + .070f);
    glVertex2f(0.771f, 0.383 + .070f);
    glVertex2f(0.769f, 0.351 + .070f);
    glVertex2f(0.776f, 0.323 + .070f);
    glVertex2f(0.778f, 0.3 + .070f);
    glVertex2f(0.762f, 0.268 + .070f);
    glVertex2f(0.729f, 0.308 + .070f);
    glVertex2f(0.729f, 0.319 + .070f);
    glVertex2f(0.718f, 0.351 + .070f);
    glVertex2f(0.709f, 0.371 + .070f);
    glVertex2f(0.718f, 0.371 + .070f);
    glVertex2f(0.724f, 0.375 + .070f);
    glVertex2f(0.709f, 0.394 + .070f);
    glVertex2f(0.693f, 0.422 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.787f, 0.517 + .070f);
    glVertex2f(0.780f, 0.545 + .070f);
    glVertex2f(0.756f, 0.557 + .070f);
    glVertex2f(0.771f, 0.529 + .070f);
    glVertex2f(0.789f, 0.505 + .070f);
    glVertex2f(0.793f, 0.493 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(45, 131, 192);
    glVertex2f(0.820f, 0.394 + .070f);
    glVertex2f(0.822f, 0.375 + .070f);
    glVertex2f(0.831f, 0.363 + .070f);
    glVertex2f(0.842f, 0.347 + .070f);
    glVertex2f(0.844f, 0.343 + .070f);
    glVertex2f(0.836f, 0.375 + .070f);
    glVertex2f(0.827f, 0.406 + .070f);
    glVertex2f(0.800f, 0.474 + .070f);
    glVertex2f(0.807f, 0.446 + .070f);
    glVertex2f(0.813f, 0.43 + .070f);
    glEnd();

    // Snow Dark Blue Mountain Bit
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.267f, 0.28 + .080f);
    glVertex2f(0.271f, 0.284 + .080f);
    glVertex2f(0.276f, 0.256 + .080f);
    glVertex2f(0.289f, 0.225 + .080f);
    glVertex2f(0.300f, 0.201 + .080f);
    glVertex2f(0.309f, 0.181 + .080f);
    glVertex2f(0.302f, 0.236 + .080f);
    glVertex2f(0.298f, 0.292 + .080f);
    glVertex2f(0.293f, 0.347 + .080f);
    glVertex2f(0.280f, 0.371 + .080f);
    glVertex2f(0.264f, 0.398 + .080f);
    glVertex2f(0.247f, 0.387 + .080f);
    glVertex2f(0.213f, 0.351 + .080f);
    glVertex2f(0.196f, 0.323 + .080f);
    glVertex2f(0.238f, 0.232 + .080f);
    glVertex2f(0.240f, 0.272 + .080f);
    glVertex2f(0.242f, 0.292 + .080f);
    glVertex2f(0.249f, 0.292 + .080f);
    glVertex2f(0.256f, 0.28 + .080f);
    glVertex2f(0.258f, 0.264 + .080f);
    glVertex2f(0.260f, 0.256 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.198f, 0.225 + .080f);
    glVertex2f(0.204f, 0.236 + .080f);
    glVertex2f(0.207f, 0.244 + .080f);
    glVertex2f(0.202f, 0.252 + .080f);
    glVertex2f(0.198f, 0.252 + .080f);
    glVertex2f(0.189f, 0.248 + .080f);
    glVertex2f(0.184f, 0.248 + .080f);
    glVertex2f(0.171f, 0.268 + .080f);
    glVertex2f(0.173f, 0.244 + .080f);
    glVertex2f(0.180f, 0.236 + .080f);
    glVertex2f(0.187f, 0.221 + .080f);
    glVertex2f(0.202f, 0.209 + .080f);
    glVertex2f(0.211f, 0.201 + .080f);
    glVertex2f(0.209f, 0.217 + .080f);
    glVertex2f(0.202f, 0.221 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.487f, 0.398 + .080f);
    glVertex2f(0.484f, 0.391 + .080f);
    glVertex2f(0.484f, 0.379 + .080f);
    glVertex2f(0.491f, 0.367 + .080f);
    glVertex2f(0.487f, 0.355 + .080f);
    glVertex2f(0.478f, 0.359 + .080f);
    glVertex2f(0.471f, 0.379 + .080f);
    glVertex2f(0.464f, 0.398 + .080f);
    glVertex2f(0.460f, 0.418 + .080f);
    glVertex2f(0.453f, 0.434 + .080f);
    glVertex2f(0.449f, 0.442 + .080f);
    glVertex2f(0.462f, 0.446 + .080f);
    glVertex2f(0.476f, 0.446 + .080f);
    glVertex2f(0.489f, 0.442 + .080f);
    glVertex2f(0.500f, 0.438 + .080f);
    glVertex2f(0.500f, 0.438 + .080f);
    glVertex2f(0.509f, 0.414 + .080f);
    glVertex2f(0.507f, 0.398 + .080f);
    glVertex2f(0.502f, 0.387 + .080f);
    glVertex2f(0.496f, 0.391 + .080f);
    glVertex2f(0.496f, 0.406 + .080f);
    glVertex2f(0.493f, 0.414 + .080f);
    glVertex2f(0.491f, 0.418 + .080f);
    glVertex2f(0.489f, 0.414 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.522f, 0.454 + .080f);
    glVertex2f(0.522f, 0.454 + .080f);
    glVertex2f(0.518f, 0.466 + .080f);
    glVertex2f(0.513f, 0.454 + .080f);
    glVertex2f(0.509f, 0.45 + .080f);
    glVertex2f(0.511f, 0.474 + .080f);
    glVertex2f(0.518f, 0.489 + .080f);
    glVertex2f(0.527f, 0.489 + .080f);
    glVertex2f(0.531f, 0.47 + .080f);
    glVertex2f(0.533f, 0.45 + .080f);
    glVertex2f(0.531f, 0.426 + .080f);
    glVertex2f(0.531f, 0.402 + .080f);
    glVertex2f(0.527f, 0.426 + .080f);
    glVertex2f(0.524f, 0.446 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.558f, 0.529 + .080f);
    glVertex2f(0.567f, 0.553 + .080f);
    glVertex2f(0.582f, 0.568 + .080f);
    glVertex2f(0.587f, 0.584 + .080f);
    glVertex2f(0.573f, 0.596 + .080f);
    glVertex2f(0.564f, 0.592 + .080f);
    glVertex2f(0.558f, 0.604 + .080f);
    glVertex2f(0.553f, 0.624 + .080f);
    glVertex2f(0.540f, 0.596 + .080f);
    glVertex2f(0.531f, 0.568 + .080f);
    glVertex2f(0.533f, 0.557 + .080f);
    glVertex2f(0.533f, 0.541 + .080f);
    glVertex2f(0.540f, 0.529 + .080f);
    glVertex2f(0.558f, 0.509 + .080f);
    glVertex2f(0.560f, 0.481 + .080f);
    glVertex2f(0.564f, 0.466 + .080f);
    glVertex2f(0.560f, 0.43 + .080f);
    glVertex2f(0.560f, 0.418 + .080f);
    glVertex2f(0.564f, 0.438 + .080f);
    glVertex2f(0.569f, 0.458 + .080f);
    glVertex2f(0.564f, 0.485 + .080f);
    glVertex2f(0.560f, 0.517 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.587f, 0.454 + .080f);
    glVertex2f(0.589f, 0.442 + .080f);
    glVertex2f(0.593f, 0.434 + .080f);
    glVertex2f(0.600f, 0.426 + .080f);
    glVertex2f(0.602f, 0.426 + .080f);
    glVertex2f(0.604f, 0.422 + .080f);
    glVertex2f(0.593f, 0.426 + .080f);
    glVertex2f(0.584f, 0.434 + .080f);
    glVertex2f(0.582f, 0.446 + .080f);
    glVertex2f(0.582f, 0.462 + .080f);
    glVertex2f(0.576f, 0.474 + .080f);
    glVertex2f(0.576f, 0.489 + .080f);
    glVertex2f(0.578f, 0.501 + .080f);
    glVertex2f(0.580f, 0.505 + .080f);
    glVertex2f(0.587f, 0.513 + .080f);
    glVertex2f(0.587f, 0.485 + .080f);
    glVertex2f(0.587f, 0.47 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.676f, 0.509 + .080f);
    glVertex2f(0.687f, 0.493 + .080f);
    glVertex2f(0.700f, 0.47 + .080f);
    glVertex2f(0.716f, 0.446 + .080f);
    glVertex2f(0.718f, 0.477 + .080f);
    glVertex2f(0.718f, 0.501 + .080f);
    glVertex2f(0.707f, 0.525 + .080f);
    glVertex2f(0.696f, 0.541 + .080f);
    glVertex2f(0.687f, 0.553 + .080f);
    glVertex2f(0.669f, 0.564 + .080f);
    glVertex2f(0.667f, 0.553 + .080f);
    glVertex2f(0.651f, 0.553 + .080f);
    glVertex2f(0.636f, 0.553f + .080);
    glVertex2f(0.644f, 0.533 + .080f);
    glVertex2f(0.638f, 0.521 + .080f);
    glVertex2f(0.653f, 0.509 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.747f, 0.347 + .080f);
    glVertex2f(0.751f, 0.323 + .080f);
    glVertex2f(0.758f, 0.308 + .080f);
    glVertex2f(0.767f, 0.272 + .080f);
    glVertex2f(0.747f, 0.272 + .080f);
    glVertex2f(0.729f, 0.3 + .080f);
    glVertex2f(0.722f, 0.335 + .080f);
    glVertex2f(0.720f, 0.355 + .080f);
    glVertex2f(0.720f, 0.387 + .080f);
    glVertex2f(0.724f, 0.398 + .080f);
    glVertex2f(0.736f, 0.418 + .080f);
    glVertex2f(0.740f, 0.371 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.558f, 0.351 + .080f);
    glVertex2f(0.553f, 0.327 + .080f);
    glVertex2f(0.564f, 0.347 + .080f);
    glVertex2f(0.562f, 0.359 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.544f, 0.319 + .080f);
    glVertex2f(0.538f, 0.359 + .080f);
    glVertex2f(0.544f, 0.343 + .080f);
    glVertex2f(0.549f, 0.323 + .080f);
    glVertex2f(0.551f, 0.311 + .080f);
    glVertex2f(0.556f, 0.311 + .080f);
    glVertex2f(0.553f, 0.292 + .080f);
    glVertex2f(0.542f, 0.284 + .080f);
    glVertex2f(0.542f, 0.308 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.580f, 0.304 + .080f);
    glVertex2f(0.578f, 0.308 + .080f);
    glVertex2f(0.573f, 0.319 + .080f);
    glVertex2f(0.576f, 0.339 + .080f);
    glVertex2f(0.580f, 0.347 + .080f);
    glVertex2f(0.591f, 0.327 + .080f);
    glVertex2f(0.596f, 0.304 + .080f);
    glVertex2f(0.602f, 0.288 + .080f);
    glVertex2f(0.591f, 0.292 + .080f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(37, 105, 154);
    glVertex2f(0.616f, 0.375 + .080f);
    glVertex2f(0.611f, 0.398 + .080f);
    glVertex2f(0.611f, 0.383 + .080f);
    glVertex2f(0.609f, 0.371 + .080f);
    glVertex2f(0.613f, 0.355 + .080f);
    glVertex2f(0.616f, 0.347 + .080f);
    glVertex2f(0.620f, 0.351 + .080f);
    glEnd();
    // Snow Light Blue Mountain
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.129f, 0.197 + .060f);
    glVertex2f(0.138f, 0.205 + .060f);
    glVertex2f(0.118f, 0.221 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.469f, 0.315 + .060f);
    glVertex2f(0.498f, 0.3 + .060f);
    glVertex2f(0.507f, 0.288 + .060f);
    glVertex2f(0.520f, 0.248 + .060f);
    glVertex2f(0.476f, 0.24 + .060f);
    glVertex2f(0.442f, 0.26 + .060f);
    glVertex2f(0.411f, 0.3 + .060f);
    glVertex2f(0.407f, 0.311 + .060f);
    glVertex2f(0.411f, 0.323 + .060f);
    glVertex2f(0.427f, 0.327 + .060f);
    glVertex2f(0.440f, 0.327 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.571f, 0.636 + .060f);
    glVertex2f(0.564f, 0.643 + .060f);
    glVertex2f(0.562f, 0.651 + .060f);
    glVertex2f(0.584f, 0.643 + .060f);
    glVertex2f(0.596f, 0.64 + .060f);
    glVertex2f(0.580f, 0.632 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.649f, 0.64 + .060f);
    glVertex2f(0.644f, 0.647 + .060f);
    glVertex2f(0.633f, 0.64 + .060f);
    glVertex2f(0.649f, 0.624 + .060f);
    glVertex2f(0.662f, 0.616 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.604f, 0.462 + .060f);
    glVertex2f(0.593f, 0.474 + .060f);
    glVertex2f(0.591f, 0.505 + .060f);
    glVertex2f(0.593f, 0.529 + .060f);
    glVertex2f(0.609f, 0.557 + .060f);
    glVertex2f(0.613f, 0.521 + .060f);
    glVertex2f(0.629f, 0.477 + .060f);
    glVertex2f(0.644f, 0.454 + .060f);
    glVertex2f(0.649f, 0.438 + .060f);
    glVertex2f(0.638f, 0.426 + .060f);
    glVertex2f(0.609f, 0.454 + .060f);
    glVertex2f(0.596f, 0.47 + .060f);
    glVertex2f(0.589f, 0.505 + .060f);
    glVertex2f(0.591f, 0.521 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.647f, 0.592 + .060f);
    glVertex2f(0.664f, 0.58 + .060f);
    glVertex2f(0.660f, 0.564 + .060f);
    glVertex2f(0.638f, 0.553 + .060f);
    glVertex2f(0.631f, 0.553 + .060f);
    glVertex2f(0.627f, 0.572 + .060f);
    glVertex2f(0.627f, 0.6 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.716f, 0.545 + .060f);
    glVertex2f(0.736f, 0.513 + .060f);
    glVertex2f(0.733f, 0.462 + .060f);
    glVertex2f(0.713f, 0.458 + .060f);
    glVertex2f(0.716f, 0.505 + .060f);
    glVertex2f(0.700f, 0.541 + .060f);
    glVertex2f(0.693f, 0.557 + .060f);
    glVertex2f(0.680f, 0.58 + .060f);
    glVertex2f(0.736f, 0.564 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.729f, 0.446 + .060f);
    glVertex2f(0.769f, 0.41 + .060f);
    glVertex2f(0.771f, 0.371 + .060f);
    glVertex2f(0.776f, 0.327 + .060f);
    glVertex2f(0.782f, 0.288 + .060f);
    glVertex2f(0.760f, 0.319 + .060f);
    glVertex2f(0.744f, 0.367 + .060f);
    glVertex2f(0.736f, 0.41 + .060f);
    glVertex2f(0.722f, 0.383 + .060f);
    glVertex2f(0.693f, 0.422 + .060f);
    glVertex2f(0.673f, 0.481 + .060f);
    glVertex2f(0.649f, 0.481 + .060f);
    glVertex2f(0.633f, 0.541 + .060f);
    glVertex2f(0.647f, 0.517 + .060f);
    glVertex2f(0.673f, 0.505 + .060f);
    glVertex2f(0.709f, 0.47 + .060f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 201, 235);
    glVertex2f(0.713f, 0.355 + .060f);
    glVertex2f(0.707f, 0.375 + .060f);
    glVertex2f(0.718f, 0.375 + .060f);
    glVertex2f(0.738f, 0.406 + .060f);
    glVertex2f(0.749f, 0.339 + .060f);
    glVertex2f(0.753f, 0.272 + .060f);
    glEnd();
}

void Volacano()
{
    // Volcano Main Shape
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(145, 39, 49);
    glVertex2f(-0.331f, 0.454 + .070f);
    glVertex2f(-0.278f, 0.323 + .070f);
    glVertex2f(-0.176f, 0.256 + .070f);
    glVertex2f(0.040f, 0.126 + .070f);
    glVertex2f(0.091f, 0.035 + .070f);
    glVertex2f(0.031f, -0.139 + .070f);
    glVertex2f(-0.909f, -0.084 + .070f);
    glVertex2f(-0.907f, 0.003 + .070f);
    glVertex2f(-0.871f, 0.126 + .070f);
    glVertex2f(-0.782f, 0.177 + .070f);
    glVertex2f(-0.709f, 0.252 + .070f);
    glVertex2f(-0.649f, 0.323 + .070f);
    glVertex2f(-0.589f, 0.458 + .070f);
    glVertex2f(-0.531f, 0.62 + .070f);
    glVertex2f(-0.504f, 0.624 + .070f);
    glVertex2f(-0.478f, 0.62 + .070f);
    glVertex2f(-0.442f, 0.636 + .070f);
    glVertex2f(-0.404f, 0.628 + .070f);
    glVertex2f(-0.380f, 0.64 + .070f);
    glVertex2f(-0.362f, 0.576 + .070f);
    glEnd();
    // Volcano red shade
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174, 51, 59);
    glVertex2f(-0.709f, 0.205 + .070f);
    glVertex2f(-0.722f, 0.185 + .070f);
    glVertex2f(-0.747f, 0.173 + .070f);
    glVertex2f(-0.756f, 0.145 + .070f);
    glVertex2f(-0.780f, 0.114 + .070f);
    glVertex2f(-0.807f, 0.126 + .070f);
    glVertex2f(-0.764f, 0.177 + .070f);
    glVertex2f(-0.722f, 0.232 + .070f);
    glVertex2f(-0.684f, 0.264 + .070f);
    glVertex2f(-0.629f, 0.331 + .070f);
    glVertex2f(-0.629f, 0.315 + .070f);
    glVertex2f(-0.680f, 0.244 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174, 51, 59);
    glVertex2f(-0.576f, 0.308 + .070f);
    glVertex2f(-0.533f, 0.387 + .070f);
    glVertex2f(-0.522f, 0.462 + .070f);
    glVertex2f(-0.522f, 0.497 + .070f);
    glVertex2f(-0.529f, 0.501 + .070f);
    glVertex2f(-0.527f, 0.497 + .070f);
    glVertex2f(-0.600f, 0.3 + .070f);
    glVertex2f(-0.629f, 0.24 + .070f);
    glVertex2f(-0.640f, 0.181 + .070f);
    glVertex2f(-0.631f, 0.145 + .070f);
    glVertex2f(-0.616f, 0.201 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174, 51, 59);
    glVertex2f(-0.478f, 0.493 + .070f);
    glVertex2f(-0.471f, 0.477 + .070f);
    glVertex2f(-0.467f, 0.549 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174, 51, 59);
    glVertex2f(-0.424f, 0.383 + .070f);
    glVertex2f(-0.416f, 0.315 + .070f);
    glVertex2f(-0.420f, 0.217 + .070f);
    glVertex2f(-0.418f, 0.185 + .070f);
    glVertex2f(-0.389f, 0.209 + .070f);
    glVertex2f(-0.400f, 0.311 + .070f);
    glVertex2f(-0.409f, 0.442 + .070f);
    glVertex2f(-0.416f, 0.497 + .070f);
    glVertex2f(-0.433f, 0.521 + .070f);
    glVertex2f(-0.433f, 0.458 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174, 51, 59);
    glVertex2f(-0.344f, 0.394 + .070f);
    glVertex2f(-0.360f, 0.454 + .070f);
    glVertex2f(-0.393f, 0.513 + .070f);
    glVertex2f(-0.373f, 0.359 + .070f);
    glVertex2f(-0.304f, 0.189 + .070f);
    glVertex2f(-0.318f, 0.296 + .070f);
    glVertex2f(-0.322f, 0.351 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(176, 53, 63);
    glVertex2f(-0.287f, 0.272 + .070f);
    glVertex2f(-0.320f, 0.343 + .070f);
    glVertex2f(-0.347f, 0.438 + .070f);
    glVertex2f(-0.358f, 0.513 + .070f);
    glVertex2f(-0.373f, 0.584 + .070f);
    glVertex2f(-0.378f, 0.592 + .070f);
    glVertex2f(-0.344f, 0.489 + .070f);
    glVertex2f(-0.313f, 0.371 + .070f);
    glVertex2f(-0.211f, 0.236 + .070f);
    glVertex2f(-0.127f, 0.185 + .070f);
    glVertex2f(-0.073f, 0.142 + .070f);
    glVertex2f(-0.047f, 0.078 + .070f);
    glVertex2f(-0.118f, 0.138 + .070f);
    glVertex2f(-0.213f, 0.193 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(176, 53, 63);
    glVertex2f(-0.362f, 0.244 + .070f);
    glVertex2f(-0.327f, 0.169 + .070f);
    glVertex2f(-0.320f, 0.256 + .070f);
    glVertex2f(-0.364f, 0.363 + .070f);
    glVertex2f(-0.387f, 0.327 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(176, 53, 63);
    glVertex2f(-0.473f, 0.296 + .070f);
    glVertex2f(-0.484f, 0.256 + .070f);
    glVertex2f(-0.478f, 0.221 + .070f);
    glVertex2f(-0.462f, 0.264 + .070f);
    glVertex2f(-0.453f, 0.327 + .070f);
    glVertex2f(-0.456f, 0.355 + .070f);
    glEnd();

    // Volcano lighter red shade
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 82, 82);
    glVertex2f(-0.658f, 0.308 + .070f);
    glVertex2f(-0.711f, 0.248 + .070f);
    glVertex2f(-0.736f, 0.217 + .070f);
    glVertex2f(-0.789f, 0.161 + .070f);
    glVertex2f(-0.809f, 0.114 + .070f);
    glVertex2f(-0.764f, 0.181 + .070f);
    glVertex2f(-0.718f, 0.225 + .070f);
    glVertex2f(-0.680f, 0.256 + .070f);
    glVertex2f(-0.640f, 0.311 + .070f);
    glVertex2f(-0.591f, 0.406 + .070f);
    glVertex2f(-0.560f, 0.474 + .070f);
    glVertex2f(-0.549f, 0.505 + .070f);
    glVertex2f(-0.551f, 0.521 + .070f);
    glVertex2f(-0.573f, 0.489 + .070f);
    glVertex2f(-0.587f, 0.462 + .070f);
    glVertex2f(-0.631f, 0.351 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 82, 82);
    glVertex2f(-0.611f, 0.323 + .070f);
    glVertex2f(-0.624f, 0.296 + .070f);
    glVertex2f(-0.638f, 0.292 + .070f);
    glVertex2f(-0.647f, 0.252 + .070f);
    glVertex2f(-0.669f, 0.201 + .070f);
    glVertex2f(-0.720f, 0.118 + .070f);
    glVertex2f(-0.676f, 0.102 + .070f);
    glVertex2f(-0.644f, 0.173 + .070f);
    glVertex2f(-0.631f, 0.221 + .070f);
    glVertex2f(-0.616f, 0.276 + .070f);
    glVertex2f(-0.587f, 0.331 + .070f);
    glVertex2f(-0.556f, 0.402 + .070f);
    glVertex2f(-0.536f, 0.462 + .070f);
    glVertex2f(-0.527f, 0.501 + .070f);
    glVertex2f(-0.540f, 0.497 + .070f);
    glVertex2f(-0.562f, 0.434 + .070f);
    glVertex2f(-0.587f, 0.371 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 82, 82);
    glVertex2f(-0.473f, 0.327 + .070f);
    glVertex2f(-0.480f, 0.3 + .070f);
    glVertex2f(-0.491f, 0.225 + .070f);
    glVertex2f(-0.473f, 0.268 + .070f);
    glVertex2f(-0.464f, 0.331 + .070f);
    glVertex2f(-0.453f, 0.383 + .070f);
    glVertex2f(-0.458f, 0.418 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 82, 82);
    glVertex2f(-0.449f, 0.367 + .070f);
    glVertex2f(-0.453f, 0.323 + .070f);
    glVertex2f(-0.442f, 0.359 + .070f);
    glVertex2f(-0.433f, 0.414 + .070f);
    glVertex2f(-0.444f, 0.41 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 82, 82);
    glVertex2f(-0.453f, 0.232 + .070f);
    glVertex2f(-0.458f, 0.256 + .070f);
    glVertex2f(-0.460f, 0.28 + .070f);
    glVertex2f(-0.467f, 0.24 + .070f);
    glVertex2f(-0.471f, 0.201 + .070f);
    glVertex2f(-0.476f, 0.161 + .070f);
    glVertex2f(-0.433f, 0.153 + .070f);
    glVertex2f(-0.436f, 0.217 + .070f);
    glVertex2f(-0.438f, 0.296 + .070f);
    glVertex2f(-0.444f, 0.327 + .070f);
    glVertex2f(-0.449f, 0.264 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 82, 82);
    glVertex2f(-0.180f, 0.217 + .070f);
    glVertex2f(-0.211f, 0.228 + .070f);
    glVertex2f(-0.238f, 0.272 + .070f);
    glVertex2f(-0.289f, 0.315 + .070f);
    glVertex2f(-0.311f, 0.351 + .070f);
    glVertex2f(-0.349f, 0.434 + .070f);
    glVertex2f(-0.353f, 0.474 + .070f);
    glVertex2f(-0.331f, 0.434 + .070f);
    glVertex2f(-0.298f, 0.343 + .070f);
    glVertex2f(-0.278f, 0.311 + .070f);
    glVertex2f(-0.247f, 0.296 + .070f);
    glVertex2f(-0.211f, 0.268 + .070f);
    glVertex2f(-0.162f, 0.232 + .070f);
    glVertex2f(-0.093f, 0.189 + .070f);
    glVertex2f(-0.038f, 0.157 + .070f);
    glVertex2f(-0.013f, 0.126 + .070f);
    glVertex2f(-0.031f, 0.066 + .070f);
    glVertex2f(-0.071f, 0.142 + .070f);
    glVertex2f(-0.076f, 0.142 + .070f);
    glVertex2f(-0.073f, 0.134 + .070f);
    glVertex2f(-0.071f, 0.142 + .070f);
    glVertex2f(-0.104f, 0.165 + .070f);
    glVertex2f(-0.138f, 0.197 + .070f);
    glEnd();

    // Volcanic Eruption
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.593f, 0.402 + .070f);
    glVertex2f(-0.622f, 0.339 + .070f);
    glVertex2f(-0.620f, 0.327 + .070f);
    glVertex2f(-0.602f, 0.355 + .070f);
    glVertex2f(-0.576f, 0.414 + .070f);
    glVertex2f(-0.547f, 0.485 + .070f);
    glVertex2f(-0.551f, 0.497 + .070f);
    glVertex2f(-0.580f, 0.43 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.538f, 0.367 + .070f);
    glVertex2f(-0.544f, 0.3 + .070f);
    glVertex2f(-0.538f, 0.3 + .070f);
    glVertex2f(-0.536f, 0.315 + .070f);
    glVertex2f(-0.524f, 0.355 + .070f);
    glVertex2f(-0.507f, 0.422 + .070f);
    glVertex2f(-0.496f, 0.493 + .070f);
    glVertex2f(-0.520f, 0.485 + .070f);
    glVertex2f(-0.527f, 0.41 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.531f, 0.576 + .070f);
    glVertex2f(-0.511f, 0.588 + .070f);
    glVertex2f(-0.498f, 0.616 + .070f);
    glVertex2f(-0.518f, 0.616 + .070f);
    glVertex2f(-0.516f, 0.612 + .070f);
    glVertex2f(-0.536f, 0.596 + .070f);
    glVertex2f(-0.547f, 0.56 + .070f);
    glVertex2f(-0.558f, 0.529 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.449f, 0.553 + .070f);
    glVertex2f(-0.451f, 0.481 + .070f);
    glVertex2f(-0.444f, 0.438 + .070f);
    glVertex2f(-0.447f, 0.513 + .070f);
    glVertex2f(-0.440f, 0.584 + .070f);
    glVertex2f(-0.444f, 0.612 + .070f);
    glVertex2f(-0.451f, 0.624 + .070f);
    glVertex2f(-0.451f, 0.624 + .070f);
    glVertex2f(-0.464f, 0.608 + .070f);
    glVertex2f(-0.456f, 0.584 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.398f, 0.608 + .070f);
    glVertex2f(-0.409f, 0.624 + .070f);
    glVertex2f(-0.420f, 0.62 + .070f);
    glVertex2f(-0.420f, 0.624 + .070f);
    glVertex2f(-0.427f, 0.628 + .070f);
    glVertex2f(-0.407f, 0.636 + .070f);
    glVertex2f(-0.387f, 0.612 + .070f);
    glVertex2f(-0.376f, 0.553 + .070f);
    glVertex2f(-0.369f, 0.509 + .070f);
    glVertex2f(-0.389f, 0.564 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.340f, 0.367 + .070f);
    glVertex2f(-0.327f, 0.319 + .070f);
    glVertex2f(-0.331f, 0.367 + .070f);
    glVertex2f(-0.353f, 0.47 + .070f);
    glVertex2f(-0.364f, 0.489 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 71);
    glVertex2f(-0.491f, 0.58 + .070f);
    glVertex2f(-0.484f, 0.608 + .070f);
    glVertex2f(-0.500f, 0.616 + .070f);
    glVertex2f(-0.520f, 0.604 + .070f);
    glVertex2f(-0.533f, 0.592 + .070f);
    glVertex2f(-0.524f, 0.616 + .070f);
    glVertex2f(-0.507f, 0.624 + .070f);
    glVertex2f(-0.484f, 0.62 + .070f);
    glVertex2f(-0.480f, 0.6 + .070f);
    glVertex2f(-0.491f, 0.564 + .070f);
    glVertex2f(-0.491f, 0.513 + .070f);
    glVertex2f(-0.496f, 0.489 + .070f);
    glVertex2f(-0.500f, 0.525 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 113, 51);
    glVertex2f(-0.460f, 0.517 + .070f);
    glVertex2f(-0.460f, 0.477 + .070f);
    glVertex2f(-0.458f, 0.43 + .070f);
    glVertex2f(-0.456f, 0.387 + .070f);
    glVertex2f(-0.449f, 0.45 + .070f);
    glVertex2f(-0.456f, 0.525 + .070f);
    glVertex2f(-0.451f, 0.553 + .070f);
    glVertex2f(-0.462f, 0.584 + .070f);
    glVertex2f(-0.469f, 0.612 + .070f);
    glVertex2f(-0.480f, 0.62 + .070f);
    glVertex2f(-0.473f, 0.588 + .070f);
    glVertex2f(-0.469f, 0.56 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 113, 51);
    glVertex2f(-0.420f, 0.608 + .070f);
    glVertex2f(-0.413f, 0.62 + .070f);
    glVertex2f(-0.398f, 0.608 + .070f);
    glVertex2f(-0.389f, 0.568 + .070f);
    glVertex2f(-0.376f, 0.525 + .070f);
    glVertex2f(-0.396f, 0.553 + .070f);
    glVertex2f(-0.400f, 0.572 + .070f);
    glVertex2f(-0.409f, 0.553 + .070f);
    glVertex2f(-0.424f, 0.553 + .070f);
    glVertex2f(-0.431f, 0.572 + .070f);
    glVertex2f(-0.440f, 0.604 + .070f);
    glVertex2f(-0.447f, 0.628 + .070f);
    glVertex2f(-0.471f, 0.616 + .070f);
    glVertex2f(-0.453f, 0.64 + .070f);
    glVertex2f(-0.436f, 0.632 + .070f);
    glVertex2f(-0.424f, 0.632 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 113, 51);
    glVertex2f(-0.482f, 0.517 + .070f);
    glVertex2f(-0.482f, 0.58 + .070f);
    glVertex2f(-0.484f, 0.545 + .070f);
    glVertex2f(-0.489f, 0.501 + .070f);
    glVertex2f(-0.484f, 0.47 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 113, 51);
    glVertex2f(-0.349f, 0.509 + .070f);
    glVertex2f(-0.367f, 0.564 + .070f);
    glVertex2f(-0.378f, 0.592 + .070f);
    glVertex2f(-0.393f, 0.636 + .070f);
    glVertex2f(-0.380f, 0.628 + .070f);
    glVertex2f(-0.360f, 0.568 + .070f);
    glVertex2f(-0.336f, 0.477 + .070f);
    glVertex2f(-0.324f, 0.418 + .070f);
    glVertex2f(-0.331f, 0.426 + .070f);
    glVertex2f(-0.338f, 0.458 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 113, 51);
    glVertex2f(-0.409f, 0.537 + .070f);
    glVertex2f(-0.418f, 0.521 + .070f);
    glVertex2f(-0.427f, 0.533 + .070f);
    glVertex2f(-0.431f, 0.564 + .070f);
    glVertex2f(-0.420f, 0.545 + .070f);
    glVertex2f(-0.407f, 0.553 + .070f);
    glVertex2f(-0.398f, 0.568 + .070f);
    glVertex2f(-0.396f, 0.541 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 253, 129);
    glVertex2f(-0.527f, 0.509 + .070f);
    glVertex2f(-0.540f, 0.509 + .070f);
    glVertex2f(-0.533f, 0.537 + .070f);
    glVertex2f(-0.527f, 0.525 + .070f);
    glVertex2f(-0.520f, 0.505 + .070f);
    glVertex2f(-0.520f, 0.489 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 253, 129);
    glVertex2f(-0.531f, 0.56 + .070f);
    glVertex2f(-0.551f, 0.537 + .070f);
    glVertex2f(-0.540f, 0.525 + .070f);
    glVertex2f(-0.551f, 0.497 + .070f);
    glVertex2f(-0.544f, 0.489 + .070f);
    glVertex2f(-0.536f, 0.529 + .070f);
    glVertex2f(-0.516f, 0.564 + .070f);
    glVertex2f(-0.500f, 0.58 + .070f);
    glVertex2f(-0.491f, 0.6 + .070f);
    glVertex2f(-0.498f, 0.608 + .070f);
    glVertex2f(-0.513f, 0.588 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(202, 73, 18);
    glVertex2f(-0.520f, 0.505 + .070f);
    glVertex2f(-0.520f, 0.485 + .070f);
    glVertex2f(-0.502f, 0.485 + .070f);
    glVertex2f(-0.500f, 0.521 + .070f);
    glVertex2f(-0.509f, 0.568 + .070f);
    glVertex2f(-0.511f, 0.56 + .070f);
    glVertex2f(-0.531f, 0.537 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.433f, 0.304 + .070f);
    glVertex2f(-0.429f, 0.248 + .070f);
    glVertex2f(-0.422f, 0.248 + .070f);
    glVertex2f(-0.418f, 0.272 + .070f);
    glVertex2f(-0.418f, 0.311 + .070f);
    glVertex2f(-0.424f, 0.371 + .070f);
    glVertex2f(-0.449f, 0.446 + .070f);
    glVertex2f(-0.453f, 0.398 + .070f);
    glVertex2f(-0.438f, 0.355 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.476f, 0.533 + .070f);
    glVertex2f(-0.471f, 0.568 + .070f);
    glVertex2f(-0.482f, 0.6 + .070f);
    glVertex2f(-0.482f, 0.568 + .070f);
    glVertex2f(-0.482f, 0.509 + .070f);
    glVertex2f(-0.487f, 0.474 + .070f);
    glVertex2f(-0.478f, 0.485 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.407f, 0.529 + .070f);
    glVertex2f(-0.387f, 0.517 + .070f);
    glVertex2f(-0.371f, 0.485 + .070f);
    glVertex2f(-0.362f, 0.481 + .070f);
    glVertex2f(-0.371f, 0.513 + .070f);
    glVertex2f(-0.384f, 0.537 + .070f);
    glVertex2f(-0.393f, 0.553 + .070f);
    glVertex2f(-0.400f, 0.541 + .070f);
    glVertex2f(-0.411f, 0.537 + .070f);
    glVertex2f(-0.418f, 0.525 + .070f);
    glVertex2f(-0.427f, 0.537 + .070f);
    glVertex2f(-0.429f, 0.557 + .070f);
    glVertex2f(-0.442f, 0.608 + .070f);
    glVertex2f(-0.436f, 0.549 + .070f);
    glVertex2f(-0.427f, 0.509 + .070f);
    glVertex2f(-0.418f, 0.513 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.473f, 0.616 + .070f);
    glVertex2f(-0.482f, 0.612 + .070f);
    glVertex2f(-0.496f, 0.624 + .070f);
    glVertex2f(-0.469f, 0.624 + .070f);
    glVertex2f(-0.464f, 0.604 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.453f, 0.568 + .070f);
    glVertex2f(-0.460f, 0.592 + .070f);
    glVertex2f(-0.467f, 0.592 + .070f);
    glVertex2f(-0.456f, 0.557 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.491f, 0.533 + .070f);
    glVertex2f(-0.491f, 0.564 + .070f);
    glVertex2f(-0.484f, 0.572 + .070f);
    glVertex2f(-0.487f, 0.493 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 149, 60);
    glVertex2f(-0.404f, 0.608 + .070f);
    glVertex2f(-0.416f, 0.612 + .070f);
    glVertex2f(-0.420f, 0.612 + .070f);
    glVertex2f(-0.418f, 0.624 + .070f);
    glVertex2f(-0.400f, 0.616 + .070f);
    glVertex2f(-0.393f, 0.6 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 253, 129);
    glVertex2f(-0.496f, 0.564 + .070f);
    glVertex2f(-0.489f, 0.596 + .070f);
    glVertex2f(-0.496f, 0.612 + .070f);
    glVertex2f(-0.491f, 0.596 + .070f);
    glVertex2f(-0.502f, 0.572 + .070f);
    glVertex2f(-0.504f, 0.553 + .070f);
    glVertex2f(-0.500f, 0.517 + .070f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 253, 129);
    glVertex2f(-0.549f, 0.545 + .070f);
    glVertex2f(-0.556f, 0.545 + .070f);
    glVertex2f(-0.573f, 0.493 + .070f);
    glVertex2f(-0.567f, 0.489 + .070f);
    glVertex2f(-0.556f, 0.525 + .070f);
    glVertex2f(-0.549f, 0.533 + .070f);
    glVertex2f(-0.527f, 0.564 + .070f);
    glVertex2f(-0.520f, 0.584 + .070f);
    glVertex2f(-0.533f, 0.572 + .070f);
    glEnd();
}

void Cloud1()
{
    // Cloud 1 Animation
    glPushMatrix();
    glTranslatef(positionSky, 0.0f, 0.0f);

    // Cloud Middle

    GLfloat p2 = -0.1f;
    GLfloat q2 = 0.8f;
    GLfloat r2 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (r2 * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Cloud Left

    GLfloat p3 = -0.30f;
    GLfloat q3 = 0.8f;
    GLfloat r3 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (r3 + 0.1 * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Cloud Right

    GLfloat p4 = -0.1f;
    GLfloat q4 = 0.8f;
    GLfloat r4 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(p4, q4);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p4 + (r4 + 0.1 * cos(i * tp2 / tringle2)),
            q4 + (r4 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    glPopMatrix();
}

void Cloud2()
{
    // Cloud 2 Animation
    glPushMatrix();
    glTranslatef(-positionSky, 0.0f, 0.0f);

    // 2 Cloud Middle

    GLfloat p5 = -0.7f;
    GLfloat q5 = 0.5f;
    GLfloat r5 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(p5, q5);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p5 + (r5 * cos(i * tp2 / tringle2)),
            q5 + (r5 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // 2 Cloud Left

    GLfloat p6 = -0.80f;
    GLfloat q6 = 0.5f;
    GLfloat r6 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(p6, q6);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p6 + (r6 * cos(i * tp2 / tringle2)),
            q6 + (r6 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // 2 Cloud Right
    GLfloat p7 = -0.65f;
    GLfloat q7 = 0.5f;
    GLfloat r7 = 0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(p7, q7);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p7 + (r7 + 0.1 * cos(i * tp2 / tringle2)),
            q7 + (r7 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    glPopMatrix();
}

void Sun()
{
    // Sun Animation
    glPushMatrix();
    glTranslatef(0.0f, positionSun, 0.0f);
    // Sun
    GLfloat p1 = -0.7f;
    GLfloat q1 = 0.7f;
    GLfloat r1 = 0.10f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 242, 0);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1*0.7 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    glPopMatrix();
}

void VolcanicSmoke()
{
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);

    // Smoke1

    GLfloat p2 = -0.45f;
    GLfloat q2 = 0.8f;
    GLfloat r2 = 0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (r2 * (1.2) * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke1 Glow
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p4 = -0.45f;
    GLfloat q4 = 0.75f;
    GLfloat r4 = 0.05f;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p4, q4);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p4 + (r4 * (1.2) * cos(i * tp2 / tringle2)),
            q4 + (r4 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke2
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p3 = -0.45f;
    GLfloat q3 = 0.7f;
    GLfloat r3 = 0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p3, q3);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p3 + (r3 * (1.2) * cos(i * tp2 / tringle2)),
            q3 + (r3 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke2 Glow
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p5 = -0.45f;
    GLfloat q5 = 0.65f;
    GLfloat r5 = 0.05f;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p5, q5);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p5 + (r5 * (1.2) * cos(i * tp2 / tringle2)),
            q5 + (r5 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke3
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p6 = -0.45f;
    GLfloat q6 = 0.6f;
    GLfloat r6 = 0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p6, q6);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p6 + (r6 * (1.2) * cos(i * tp2 / tringle2)),
            q6 + (r6 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    // Smoke4
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p7 = -0.45f;
    GLfloat q7 = 0.5f;
    GLfloat r7 = 0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p7, q7);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p7 + (r7 * (1.2) * cos(i * tp2 / tringle2)),
            q7 + (r7 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke5
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p8 = -0.45f;
    GLfloat q8 = 0.4f;
    GLfloat r8 = 0.05f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p8, q8);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p8 + (r8 * (1.5) * cos(i * tp2 / tringle2)),
            q8 + (r8 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke6
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p9 = -0.45f;
    GLfloat q9 = 0.3f;
    GLfloat r9 = 0.06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p9, q9);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p9 + (r9 * (1.2) * cos(i * tp2 / tringle2)),
            q9 + (r9 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();

    // Smoke7
    glPushMatrix();
    glTranslatef(0.0f, -positionSmoke, 0.0f);
    GLfloat p10 = -0.45f;
    GLfloat q10 = 0.2f;
    GLfloat r10 = 0.075f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 120, 120);
    glVertex2f(p10, q10);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p10 + (r10 * (1.2) * cos(i * tp2 / tringle2)),
            q10 + (r10 * sin(i * tp2 / tringle2)));
    }
    glEnd();
    glPopMatrix();
}

void FirstTree()
{
    // 1st tree
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(1.0f, -0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.003f, -0.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(-0.812f, 0.141f);
    glVertex2f(-0.890f, 0.145f);
    glVertex2f(-0.930f, 0.026f);
    glVertex2f(-0.765f, 0.026f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(-0.872f, 0.26f);
    glVertex2f(-0.932f, 0.117f);
    glVertex2f(-0.767f, 0.117f);
    glVertex2f(-0.825f, 0.264f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(198, 105, 43);
    glVertex2f(-0.861f, 0.026f);
    glVertex2f(-0.861f, -0.215f);
    glVertex2f(-0.836f, -0.215f);
    glVertex2f(-0.834f, 0.03f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(-0.847f, 0.445f);
    glVertex2f(-0.932f, 0.236f);
    glVertex2f(-0.765f, 0.236f);
    glEnd();
}

void GreenMount1()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(84, 130, 53);
    glVertex2f(0.648f, 0.311f);
    glVertex2f(0.713f, 0.315f);
    glVertex2f(0.782f, 0.315f);
    glVertex2f(0.842f, 0.311f);
    glVertex2f(0.893f, 0.303f);
    glVertex2f(0.959f, 0.287f);
    glVertex2f(1.002f, 0.271f);
    glVertex2f(1.002f, -0.009f);
    glVertex2f(0.293f, -0.005f);
    glVertex2f(0.299f, 0.184f);
    glVertex2f(0.359f, 0.224f);
    glVertex2f(0.450f, 0.264f);
    glVertex2f(0.524f, 0.287f);
    glVertex2f(0.590f, 0.303f);
    glEnd();
}

void GreenMount2()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 148, 60);
    glVertex2f(0.330f, 0.184f);
    glVertex2f(0.417f, 0.173f);
    glVertex2f(0.497f, 0.153f);
    glVertex2f(0.586f, 0.117f);
    glVertex2f(0.653f, 0.082f);
    glVertex2f(0.719f, 0.038f);
    glVertex2f(0.766f, -0.005f);
    glVertex2f(-0.078f, -0.005f);
    glVertex2f(-0.074f, 0.133f);
    glVertex2f(-0.025f, 0.153f);
    glVertex2f(0.022f, 0.169f);
    glVertex2f(0.108f, 0.181f);
    glVertex2f(0.177f, 0.188f);
    glVertex2f(0.250f, 0.188f);
    glEnd();
}

void GreenMount3()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(104, 160, 66);
    glVertex2f(-0.345f, 0.216f);
    glVertex2f(-0.238f, 0.2f);
    glVertex2f(-0.156f, 0.173f);
    glVertex2f(-0.067f, 0.133f);
    glVertex2f(0.002f, 0.094f);
    glVertex2f(0.059f, 0.046f);
    glVertex2f(0.115f, -0.005f);
    glVertex2f(-0.983f, -0.009f);
    glVertex2f(-0.925f, 0.05f);
    glVertex2f(-0.776f, 0.145f);
    glVertex2f(-0.685f, 0.181f);
    glVertex2f(-0.612f, 0.2f);
    glVertex2f(-0.458f, 0.22f);
    glEnd();
}

void SecondTree()
{
    // 2nd tree
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(198, 105, 43);
    glVertex2f(-0.547f, 0.078f);
    glVertex2f(-0.547f, -0.254f);
    glVertex2f(-0.521f, -0.254f);
    glVertex2f(-0.521f, 0.078f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(-0.534f, 0.402f);
    glVertex2f(-0.614f, 0.19f);
    glVertex2f(-0.452f, 0.19f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(-0.567f, 0.196f);
    glVertex2f(-0.614f, 0.074f);
    glVertex2f(-0.452f, 0.074f);
    glVertex2f(-0.503f, 0.2f);
    glEnd();
}

void ThirdTree()
{
    // 3rd tree
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(0.035f, 0.204f);
    glVertex2f(-0.018f, 0.07f);
    glVertex2f(0.148f, 0.07f);
    glVertex2f(0.093f, 0.216f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(0.035f, 0.323f);
    glVertex2f(-0.016f, 0.196f);
    glVertex2f(0.148f, 0.196f);
    glVertex2f(0.093f, 0.339f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(0.037f, 0.445f);
    glVertex2f(-0.018f, 0.319f);
    glVertex2f(0.146f, 0.319f);
    glVertex2f(0.095f, 0.445f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 173, 71);
    glVertex2f(0.064f, 0.639f);
    glVertex2f(-0.018f, 0.43f);
    glVertex2f(0.146f, 0.43f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(198, 105, 43);
    glVertex2f(0.053f, 0.07f);
    glVertex2f(0.053f, -0.254f);
    glVertex2f(0.077f, -0.254f);
    glVertex2f(0.077f, 0.074f);
    glEnd();
}

void SmallRock()
{
    // rock right side
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(176, 183, 193);
    glVertex2f(0.275f, -0.096f);
    glVertex2f(0.282f, -0.104f);
    glVertex2f(0.290f, -0.116f);
    glVertex2f(0.299f, -0.128f);
    glVertex2f(0.308f, -0.136f);
    glVertex2f(0.315f, -0.144f);
    glVertex2f(0.322f, -0.151f);
    glVertex2f(0.326f, -0.171f);
    glVertex2f(0.326f, -0.187f);
    glVertex2f(0.326f, -0.203f);
    glVertex2f(0.324f, -0.211f);
    glVertex2f(0.322f, -0.211f);
    glVertex2f(0.315f, -0.211f);
    glVertex2f(0.273f, -0.246f);
    glVertex2f(0.248f, -0.246f);
    glVertex2f(0.233f, -0.242f);
    glVertex2f(0.215f, -0.242f);
    glVertex2f(0.195f, -0.242f);
    glVertex2f(0.170f, -0.211f);
    glVertex2f(0.170f, -0.175f);
    glVertex2f(0.173f, -0.148f);
    glVertex2f(0.175f, -0.124f);
    glVertex2f(0.179f, -0.104f);
    glVertex2f(0.188f, -0.088f);
    glVertex2f(0.197f, -0.076f);
    glVertex2f(0.210f, -0.072f);
    glVertex2f(0.226f, -0.065f);
    glVertex2f(0.239f, -0.065f);
    glVertex2f(0.253f, -0.065f);
    glVertex2f(0.262f, -0.072f);
    glVertex2f(0.268f, -0.08f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(111, 123, 137);
    glVertex2f(0.246f, -0.163f);
    glVertex2f(0.244f, -0.151f);
    glVertex2f(0.239f, -0.144f);
    glVertex2f(0.235f, -0.128f);
    glVertex2f(0.230f, -0.116f);
    glVertex2f(0.224f, -0.108f);
    glVertex2f(0.219f, -0.096f);
    glVertex2f(0.235f, -0.112f);
    glVertex2f(0.242f, -0.124f);
    glVertex2f(0.244f, -0.132f);
    glVertex2f(0.246f, -0.144f);
    glVertex2f(0.248f, -0.151f);
    glVertex2f(0.255f, -0.155f);
    glVertex2f(0.264f, -0.159f);
    glVertex2f(0.273f, -0.163f);
    glVertex2f(0.286f, -0.171f);
    glVertex2f(0.293f, -0.175f);
    glVertex2f(0.304f, -0.183f);
    glVertex2f(0.313f, -0.191f);
    glVertex2f(0.324f, -0.199f);
    glVertex2f(0.322f, -0.211f);
    glVertex2f(0.275f, -0.242f);
    glVertex2f(0.246f, -0.246f);
    glVertex2f(0.222f, -0.242f);
    glVertex2f(0.206f, -0.242f);
    glVertex2f(0.199f, -0.242f);
    glVertex2f(0.193f, -0.242f);
    glVertex2f(0.166f, -0.219f);
    glVertex2f(0.170f, -0.183f);
    glVertex2f(0.188f, -0.203f);
    glVertex2f(0.202f, -0.207f);
    glVertex2f(0.215f, -0.211f);
    glVertex2f(0.230f, -0.215f);
    glVertex2f(0.237f, -0.223f);
    glVertex2f(0.253f, -0.219f);
    glVertex2f(0.264f, -0.203f);
    glVertex2f(0.273f, -0.199f);
    glVertex2f(0.277f, -0.191f);
    glVertex2f(0.273f, -0.179f);
    glVertex2f(0.264f, -0.175f);
    glVertex2f(0.255f, -0.171f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(176, 183, 193);
    glVertex2f(0.175f, -0.219f);
    glVertex2f(0.184f, -0.223f);
    glVertex2f(0.188f, -0.227f);
    glVertex2f(0.195f, -0.234f);
    glVertex2f(0.197f, -0.238f);
    glVertex2f(0.197f, -0.25f);
    glVertex2f(0.195f, -0.254f);
    glVertex2f(0.186f, -0.262f);
    glVertex2f(0.170f, -0.262f);
    glVertex2f(0.157f, -0.262f);
    glVertex2f(0.150f, -0.258f);
    glVertex2f(0.153f, -0.238f);
    glVertex2f(0.157f, -0.227f);
    glVertex2f(0.164f, -0.219f);
    glVertex2f(0.170f, -0.219f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(176, 183, 193);
    glVertex2f(0.310f, -0.262f);
    glVertex2f(0.293f, -0.262f);
    glVertex2f(0.284f, -0.258f);
    glVertex2f(0.275f, -0.25f);
    glVertex2f(0.277f, -0.223f);
    glVertex2f(0.282f, -0.211f);
    glVertex2f(0.290f, -0.207f);
    glVertex2f(0.297f, -0.203f);
    glVertex2f(0.310f, -0.203f);
    glVertex2f(0.322f, -0.207f);
    glVertex2f(0.328f, -0.211f);
    glVertex2f(0.335f, -0.231f);
    glVertex2f(0.335f, -0.242f);
    glVertex2f(0.335f, -0.262f);
    glVertex2f(0.326f, -0.262f);
    glEnd();
}

void sameEye(float p1, float q1, float p2, float q2, float r1, float r2)
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 180);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // Eye Ball

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (r2 * (0.7) * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();
}

void BrownDino()
{
    // Animation
    glPushMatrix();
    glTranslatef(positionBrownDino, 0.0f, 0.0f);

    // Leg Back

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.656f, -0.558f);
    glVertex2f(0.676f, -0.562f);
    glVertex2f(0.689f, -0.53f);
    glVertex2f(0.691f, -0.499f);
    glVertex2f(0.644f, -0.483f);
    glVertex2f(0.642f, -0.483f);
    glVertex2f(0.638f, -0.515f);
    glVertex2f(0.638f, -0.534f);
    glVertex2f(0.642f, -0.55f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.762f, -0.562f);
    glVertex2f(0.778f, -0.558f);
    glVertex2f(0.787f, -0.546f);
    glVertex2f(0.791f, -0.526f);
    glVertex2f(0.791f, -0.483f);
    glVertex2f(0.744f, -0.479f);
    glVertex2f(0.740f, -0.519f);
    glVertex2f(0.740f, -0.542f);
    glVertex2f(0.747f, -0.554f);
    glVertex2f(0.753f, -0.558f);
    glEnd();
    // Leg Front
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(111, 84, 47);
    glVertex2f(0.667f, -0.566f);
    glVertex2f(0.678f, -0.574f);
    glVertex2f(0.691f, -0.574f);
    glVertex2f(0.702f, -0.57f);
    glVertex2f(0.707f, -0.554f);
    glVertex2f(0.709f, -0.523f);
    glVertex2f(0.709f, -0.499f);
    glVertex2f(0.667f, -0.487f);
    glVertex2f(0.667f, -0.487f);
    glVertex2f(0.660f, -0.515f);
    glVertex2f(0.660f, -0.515f);
    glVertex2f(0.656f, -0.534f);
    glVertex2f(0.660f, -0.554f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(111, 84, 47);
    glVertex2f(0.791f, -0.574f);
    glVertex2f(0.800f, -0.57f);
    glVertex2f(0.809f, -0.558f);
    glVertex2f(0.811f, -0.53f);
    glVertex2f(0.807f, -0.483f);
    glVertex2f(0.762f, -0.495f);
    glVertex2f(0.762f, -0.523f);
    glVertex2f(0.762f, -0.542f);
    glVertex2f(0.764f, -0.558f);
    glVertex2f(0.771f, -0.57f);
    glEnd();

    // Scales
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.651f, -0.171f);
    glVertex2f(0.662f, -0.151f);
    glVertex2f(0.676f, -0.159f);
    glVertex2f(0.689f, -0.175f);
    glVertex2f(0.698f, -0.198f);
    glVertex2f(0.636f, -0.238f);
    glVertex2f(0.642f, -0.194f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.744f, -0.143f);
    glVertex2f(0.756f, -0.171f);
    glVertex2f(0.767f, -0.21f);
    glVertex2f(0.767f, -0.21f);
    glVertex2f(0.702f, -0.187f);
    glVertex2f(0.711f, -0.155f);
    glVertex2f(0.720f, -0.143f);
    glVertex2f(0.731f, -0.135f);
    glVertex2f(0.740f, -0.135f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.813f, -0.206f);
    glVertex2f(0.816f, -0.238f);
    glVertex2f(0.813f, -0.27f);
    glVertex2f(0.811f, -0.281f);
    glVertex2f(0.767f, -0.202f);
    glVertex2f(0.780f, -0.187f);
    glVertex2f(0.800f, -0.179f);
    glVertex2f(0.807f, -0.187f);
    glVertex2f(0.809f, -0.187f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.853f, -0.293f);
    glVertex2f(0.851f, -0.317f);
    glVertex2f(0.844f, -0.349f);
    glVertex2f(0.836f, -0.372f);
    glVertex2f(0.813f, -0.274f);
    glVertex2f(0.827f, -0.266f);
    glVertex2f(0.836f, -0.266f);
    glVertex2f(0.847f, -0.27f);
    glVertex2f(0.853f, -0.277f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.860f, -0.353f);
    glVertex2f(0.869f, -0.353f);
    glVertex2f(0.873f, -0.372f);
    glVertex2f(0.873f, -0.416f);
    glVertex2f(0.838f, -0.376f);
    glVertex2f(0.849f, -0.36f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.882f, -0.376f);
    glVertex2f(0.889f, -0.357f);
    glVertex2f(0.900f, -0.376f);
    glVertex2f(0.902f, -0.4f);
    glVertex2f(0.878f, -0.4f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.907f, -0.353f);
    glVertex2f(0.911f, -0.345f);
    glVertex2f(0.918f, -0.353f);
    glVertex2f(0.924f, -0.372f);
    glVertex2f(0.904f, -0.38f);
    glVertex2f(0.904f, -0.364f);
    glEnd();

    // Horn1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 222, 103);
    glVertex2f(0.487f, -0.372f);
    glVertex2f(0.478f, -0.341f);
    glVertex2f(0.471f, -0.309f);
    glVertex2f(0.489f, -0.325f);
    glVertex2f(0.513f, -0.357f);
    glVertex2f(0.520f, -0.372f);
    glVertex2f(0.496f, -0.404f);
    glEnd();
    // Horn2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 222, 103);
    glVertex2f(0.562f, -0.234f);
    glVertex2f(0.560f, -0.198f);
    glVertex2f(0.576f, -0.226f);
    glVertex2f(0.593f, -0.266f);
    glVertex2f(0.573f, -0.305f);
    glVertex2f(0.567f, -0.274f);
    glEnd();

    // Head
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(131, 99, 58);
    glVertex2f(0.560f, -0.305f);
    glVertex2f(0.573f, -0.289f);
    glVertex2f(0.582f, -0.266f);
    glVertex2f(0.596f, -0.238f);
    glVertex2f(0.596f, -0.238f);
    glVertex2f(0.604f, -0.218f);
    glVertex2f(0.618f, -0.206f);
    glVertex2f(0.627f, -0.206f);
    glVertex2f(0.633f, -0.218f);
    glVertex2f(0.647f, -0.242f);
    glVertex2f(0.660f, -0.301f);
    glVertex2f(0.664f, -0.357f);
    glVertex2f(0.660f, -0.42f);
    glVertex2f(0.656f, -0.44f);
    glVertex2f(0.649f, -0.471f);
    glVertex2f(0.638f, -0.503f);
    glVertex2f(0.627f, -0.511f);
    glVertex2f(0.618f, -0.507f);
    glVertex2f(0.607f, -0.487f);
    glVertex2f(0.558f, -0.495f);
    glVertex2f(0.524f, -0.495f);
    glVertex2f(0.498f, -0.491f);
    glVertex2f(0.491f, -0.475f);
    glVertex2f(0.487f, -0.455f);
    glVertex2f(0.487f, -0.428f);
    glVertex2f(0.489f, -0.404f);
    glVertex2f(0.493f, -0.388f);
    glVertex2f(0.502f, -0.372f);
    glVertex2f(0.524f, -0.345f);
    glVertex2f(0.524f, -0.345f);
    glEnd();

    // Horn3

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 222, 103);
    glVertex2f(-0.02 + .598f, -0.301 + 0.02f);
    glVertex2f(-0.02 + .596f, -0.277 + 0.02f);
    glVertex2f(-0.02 + .596f, -0.234 + 0.02f);
    glVertex2f(-0.02 + .609f, -0.254 + 0.02f);
    glVertex2f(-0.02 + .627f, -0.293 + 0.02f);
    glVertex2f(-0.02 + .631f, -0.317 + 0.02f);
    glVertex2f(-0.02 + .622f, -0.333 + 0.02f);
    glVertex2f(-0.02 + .607f, -0.333 + 0.02f);
    glVertex2f(-0.02 + .602f, -0.329 + 0.02f);
    glEnd();

    // Body
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 85, 47);
    glVertex2f(0.816f, -0.258f);
    glVertex2f(0.831f, -0.297f);
    glVertex2f(0.840f, -0.353f);
    glVertex2f(0.849f, -0.388f);
    glVertex2f(0.860f, -0.396f);
    glVertex2f(0.876f, -0.4f);
    glVertex2f(0.880f, -0.467f);
    glVertex2f(0.829f, -0.499f);
    glVertex2f(0.816f, -0.503f);
    glVertex2f(0.796f, -0.507f);
    glVertex2f(0.736f, -0.515f);
    glVertex2f(0.704f, -0.515f);
    glVertex2f(0.669f, -0.515f);
    glVertex2f(0.640f, -0.499f);
    glVertex2f(0.622f, -0.467f);
    glVertex2f(0.631f, -0.234f);
    glVertex2f(0.644f, -0.214f);
    glVertex2f(0.658f, -0.198f);
    glVertex2f(0.676f, -0.187f);
    glVertex2f(0.696f, -0.179f);
    glVertex2f(0.720f, -0.179f);
    glVertex2f(0.749f, -0.187f);
    glVertex2f(0.778f, -0.206f);
    glEnd();
    // Tail
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(112, 85, 47);
    glVertex2f(0.898f, -0.384f);
    glVertex2f(0.916f, -0.368f);
    glVertex2f(0.922f, -0.36f);
    glVertex2f(0.927f, -0.368f);
    glVertex2f(0.927f, -0.38f);
    glVertex2f(0.922f, -0.404f);
    glVertex2f(0.909f, -0.436f);
    glVertex2f(0.887f, -0.459f);
    glVertex2f(0.876f, -0.467f);
    glVertex2f(0.876f, -0.4f);
    glEnd();

    // Nails

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.669f, -0.558f);
    glVertex2f(0.667f, -0.566f);
    glVertex2f(0.658f, -0.554f);
    glVertex2f(0.662f, -0.542f);
    glVertex2f(0.669f, -0.542f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.678f, -0.554f);
    glVertex2f(0.680f, -0.55f);
    glVertex2f(0.684f, -0.554f);
    glVertex2f(0.684f, -0.57f);
    glVertex2f(0.684f, -0.574f);
    glVertex2f(0.673f, -0.57f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.767f, -0.558f);
    glVertex2f(0.767f, -0.546f);
    glVertex2f(0.773f, -0.55f);
    glVertex2f(0.776f, -0.57f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(91, 68, 35);
    glVertex2f(0.789f, -0.562f);
    glVertex2f(0.789f, -0.574f);
    glVertex2f(0.780f, -0.574f);
    glVertex2f(0.782f, -0.554f);
    glVertex2f(0.784f, -0.55f);
    glEnd();

    // EYe

    sameEye(0.58f, -0.37f, 0.58f, -0.37f, 0.015f, 0.01f);

    glPopMatrix();
}

void RedDino()
{
    // red dino animation
    glPushMatrix();
    glTranslatef(positionRedDino, 0.0f, 0.0f);

    // Scales

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 53, 67);
    glVertex2f(-0.311f, -0.096f);
    glVertex2f(-0.304f, -0.1f);
    glVertex2f(-0.296f, -0.104f);
    glVertex2f(-0.282f, -0.076f);
    glVertex2f(-0.273f, -0.04f);
    glVertex2f(-0.302f, 0.011f);
    glVertex2f(-0.318f, -0.028f);
    glVertex2f(-0.331f, -0.06f);
    glVertex2f(-0.331f, -0.072f);
    glVertex2f(-0.324f, -0.084f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 53, 67);
    glVertex2f(-0.311f, -0.096f);
    glVertex2f(-0.304f, -0.1f);
    glVertex2f(-0.296f, -0.104f);
    glVertex2f(-0.282f, -0.076f);
    glVertex2f(-0.273f, -0.04f);
    glVertex2f(-0.302f, 0.011f);
    glVertex2f(-0.318f, -0.028f);
    glVertex2f(-0.331f, -0.06f);
    glVertex2f(-0.331f, -0.072f);
    glVertex2f(-0.324f, -0.084f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.249f, 0.28f);
    glVertex2f(-0.253f, 0.264f);
    glVertex2f(-0.260f, 0.248f);
    glVertex2f(-0.273f, 0.304f);
    glVertex2f(-0.262f, 0.308f);
    glVertex2f(-0.251f, 0.304f);
    glVertex2f(-0.247f, 0.296f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.233f, 0.221f);
    glVertex2f(-0.240f, 0.205f);
    glVertex2f(-0.244f, 0.189f);
    glVertex2f(-0.251f, 0.177f);
    glVertex2f(-0.260f, 0.244f);
    glVertex2f(-0.256f, 0.252f);
    glVertex2f(-0.247f, 0.248f);
    glVertex2f(-0.238f, 0.244f);
    glVertex2f(-0.233f, 0.24f);
    glVertex2f(-0.231f, 0.228f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.242f, 0.181f);
    glVertex2f(-0.233f, 0.177f);
    glVertex2f(-0.229f, 0.173f);
    glVertex2f(-0.229f, 0.161f);
    glVertex2f(-0.247f, 0.114f);
    glVertex2f(-0.260f, 0.181f);
    glVertex2f(-0.251f, 0.181f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.222f, 0.09f);
    glVertex2f(-0.227f, 0.066f);
    glVertex2f(-0.231f, 0.047f);
    glVertex2f(-0.247f, 0.094f);
    glVertex2f(-0.247f, 0.118f);
    glVertex2f(-0.233f, 0.118f);
    glVertex2f(-0.224f, 0.114f);
    glVertex2f(-0.218f, 0.11f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.198f, 0.066f);
    glVertex2f(-0.193f, 0.051f);
    glVertex2f(-0.193f, 0.035f);
    glVertex2f(-0.236f, 0.051f);
    glVertex2f(-0.218f, 0.074f);
    glVertex2f(-0.209f, 0.082f);
    glVertex2f(-0.204f, 0.086f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.191f, 0.07f);
    glVertex2f(-0.189f, 0.086f);
    glVertex2f(-0.184f, 0.086f);
    glVertex2f(-0.178f, 0.078f);
    glVertex2f(-0.169f, 0.07f);
    glVertex2f(-0.196f, 0.043f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.173f, 0.094f);
    glVertex2f(-0.171f, 0.11f);
    glVertex2f(-0.164f, 0.098f);
    glVertex2f(-0.162f, 0.082f);
    glVertex2f(-0.173f, 0.066f);
    glEnd();

    // Head
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.311f, 0.189f);
    glVertex2f(-0.331f, 0.177f);
    glVertex2f(-0.351f, 0.169f);
    glVertex2f(-0.358f, 0.177f);
    glVertex2f(-0.369f, 0.205f);
    glVertex2f(-0.376f, 0.252f);
    glVertex2f(-0.373f, 0.28f);
    glVertex2f(-0.362f, 0.292f);
    glVertex2f(-0.338f, 0.308f);
    glVertex2f(-0.300f, 0.319f);
    glVertex2f(-0.276f, 0.319f);
    glVertex2f(-0.267f, 0.304f);
    glVertex2f(-0.253f, 0.248f);
    glVertex2f(-0.249f, 0.201f);
    glVertex2f(-0.289f, 0.193f);
    glEnd();

    // Leg2
    // Leg2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 53, 67);
    glVertex2f(-0.311f, -0.096f);
    glVertex2f(-0.304f, -0.1f);
    glVertex2f(-0.296f, -0.104f);
    glVertex2f(-0.282f, -0.076f);
    glVertex2f(-0.273f, -0.04f);
    glVertex2f(-0.302f, 0.011f);
    glVertex2f(-0.318f, -0.028f);
    glVertex2f(-0.331f, -0.06f);
    glVertex2f(-0.331f, -0.072f);
    glVertex2f(-0.324f, -0.084f);
    glEnd();

    // Leg1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 77, 74);
    glVertex2f(-0.273f, -0.115f);
    glVertex2f(-0.267f, -0.123f);
    glVertex2f(-0.249f, -0.127f);
    glVertex2f(-0.238f, -0.123f);
    glVertex2f(-0.231f, -0.115f);
    glVertex2f(-0.233f, -0.048f);
    glVertex2f(-0.276f, -0.04f);
    glVertex2f(-0.273f, -0.044f);
    glVertex2f(-0.278f, -0.076f);
    glVertex2f(-0.280f, -0.096f);
    glVertex2f(-0.280f, -0.111f);
    glEnd();

    // Body
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.240f, 0.078f);
    glVertex2f(-0.242f, 0.118f);
    glVertex2f(-0.247f, 0.185f);
    glVertex2f(-0.249f, 0.205f);
    glVertex2f(-0.309f, 0.189f);
    glVertex2f(-0.318f, 0.161f);
    glVertex2f(-0.322f, 0.13f);
    glVertex2f(-0.324f, 0.098f);
    glVertex2f(-0.324f, 0.066f);
    glVertex2f(-0.320f, 0.019f);
    glVertex2f(-0.311f, -0.021f);
    glVertex2f(-0.293f, -0.052f);
    glVertex2f(-0.276f, -0.064f);
    glVertex2f(-0.244f, -0.068f);
    glVertex2f(-0.222f, -0.064f);
    glVertex2f(-0.216f, 0.051f);
    glVertex2f(-0.229f, 0.058f);
    glEnd();

    // Tail
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.200f, 0.051f);
    glVertex2f(-0.184f, 0.066f);
    glVertex2f(-0.169f, 0.086f);
    glVertex2f(-0.164f, 0.09f);
    glVertex2f(-0.160f, 0.086f);
    glVertex2f(-0.164f, 0.062f);
    glVertex2f(-0.176f, 0.019f);
    glVertex2f(-0.189f, -0.021f);
    glVertex2f(-0.200f, -0.044f);
    glVertex2f(-0.216f, -0.06f);
    glVertex2f(-0.224f, -0.068f);
    glVertex2f(-0.216f, 0.051f);
    glVertex2f(-0.218f, 0.047f);
    glEnd();

    // Hand2

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.331f, 0.118f);
    glVertex2f(-0.324f, 0.114f);
    glVertex2f(-0.309f, 0.11f);
    glVertex2f(-0.309f, 0.134f);
    glVertex2f(-0.311f, 0.126f);
    glVertex2f(-0.322f, 0.134f);
    glVertex2f(-0.331f, 0.138f);
    glVertex2f(-0.340f, 0.138f);
    glVertex2f(-0.349f, 0.13f);
    glVertex2f(-0.349f, 0.122f);
    glVertex2f(-0.342f, 0.13f);
    glVertex2f(-0.338f, 0.13f);
    glVertex2f(-0.340f, 0.122f);
    glVertex2f(-0.347f, 0.11f);
    glVertex2f(-0.340f, 0.114f);
    glEnd();

    // Hand1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.331f, 0.086f);
    glVertex2f(-0.338f, 0.07f);
    glVertex2f(-0.338f, 0.074f);
    glVertex2f(-0.338f, 0.094f);
    glVertex2f(-0.342f, 0.078f);
    glVertex2f(-0.344f, 0.082f);
    glVertex2f(-0.344f, 0.098f);
    glVertex2f(-0.333f, 0.114f);
    glVertex2f(-0.322f, 0.122f);
    glVertex2f(-0.316f, 0.126f);
    glVertex2f(-0.313f, 0.102f);
    glVertex2f(-0.327f, 0.098f);
    glEnd();

    // EYe
    sameEye(-0.31f, 0.27f, -0.31f, 0.27f, 0.015f, 0.01f);

    glPopMatrix();
}

void RedDino1()
{

    // Scales

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 53, 67);
    glVertex2f(-0.311f, -0.096f);
    glVertex2f(-0.304f, -0.1f);
    glVertex2f(-0.296f, -0.104f);
    glVertex2f(-0.282f, -0.076f);
    glVertex2f(-0.273f, -0.04f);
    glVertex2f(-0.302f, 0.011f);
    glVertex2f(-0.318f, -0.028f);
    glVertex2f(-0.331f, -0.06f);
    glVertex2f(-0.331f, -0.072f);
    glVertex2f(-0.324f, -0.084f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 53, 67);
    glVertex2f(-0.311f, -0.096f);
    glVertex2f(-0.304f, -0.1f);
    glVertex2f(-0.296f, -0.104f);
    glVertex2f(-0.282f, -0.076f);
    glVertex2f(-0.273f, -0.04f);
    glVertex2f(-0.302f, 0.011f);
    glVertex2f(-0.318f, -0.028f);
    glVertex2f(-0.331f, -0.06f);
    glVertex2f(-0.331f, -0.072f);
    glVertex2f(-0.324f, -0.084f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.249f, 0.28f);
    glVertex2f(-0.253f, 0.264f);
    glVertex2f(-0.260f, 0.248f);
    glVertex2f(-0.273f, 0.304f);
    glVertex2f(-0.262f, 0.308f);
    glVertex2f(-0.251f, 0.304f);
    glVertex2f(-0.247f, 0.296f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.233f, 0.221f);
    glVertex2f(-0.240f, 0.205f);
    glVertex2f(-0.244f, 0.189f);
    glVertex2f(-0.251f, 0.177f);
    glVertex2f(-0.260f, 0.244f);
    glVertex2f(-0.256f, 0.252f);
    glVertex2f(-0.247f, 0.248f);
    glVertex2f(-0.238f, 0.244f);
    glVertex2f(-0.233f, 0.24f);
    glVertex2f(-0.231f, 0.228f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.242f, 0.181f);
    glVertex2f(-0.233f, 0.177f);
    glVertex2f(-0.229f, 0.173f);
    glVertex2f(-0.229f, 0.161f);
    glVertex2f(-0.247f, 0.114f);
    glVertex2f(-0.260f, 0.181f);
    glVertex2f(-0.251f, 0.181f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.222f, 0.09f);
    glVertex2f(-0.227f, 0.066f);
    glVertex2f(-0.231f, 0.047f);
    glVertex2f(-0.247f, 0.094f);
    glVertex2f(-0.247f, 0.118f);
    glVertex2f(-0.233f, 0.118f);
    glVertex2f(-0.224f, 0.114f);
    glVertex2f(-0.218f, 0.11f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.198f, 0.066f);
    glVertex2f(-0.193f, 0.051f);
    glVertex2f(-0.193f, 0.035f);
    glVertex2f(-0.236f, 0.051f);
    glVertex2f(-0.218f, 0.074f);
    glVertex2f(-0.209f, 0.082f);
    glVertex2f(-0.204f, 0.086f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.191f, 0.07f);
    glVertex2f(-0.189f, 0.086f);
    glVertex2f(-0.184f, 0.086f);
    glVertex2f(-0.178f, 0.078f);
    glVertex2f(-0.169f, 0.07f);
    glVertex2f(-0.196f, 0.043f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 141, 70);
    glVertex2f(-0.173f, 0.094f);
    glVertex2f(-0.171f, 0.11f);
    glVertex2f(-0.164f, 0.098f);
    glVertex2f(-0.162f, 0.082f);
    glVertex2f(-0.173f, 0.066f);
    glEnd();

    // Head
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.311f, 0.189f);
    glVertex2f(-0.331f, 0.177f);
    glVertex2f(-0.351f, 0.169f);
    glVertex2f(-0.358f, 0.177f);
    glVertex2f(-0.369f, 0.205f);
    glVertex2f(-0.376f, 0.252f);
    glVertex2f(-0.373f, 0.28f);
    glVertex2f(-0.362f, 0.292f);
    glVertex2f(-0.338f, 0.308f);
    glVertex2f(-0.300f, 0.319f);
    glVertex2f(-0.276f, 0.319f);
    glVertex2f(-0.267f, 0.304f);
    glVertex2f(-0.253f, 0.248f);
    glVertex2f(-0.249f, 0.201f);
    glVertex2f(-0.289f, 0.193f);
    glEnd();

    // Leg2
    // Leg2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 53, 67);
    glVertex2f(-0.311f, -0.096f);
    glVertex2f(-0.304f, -0.1f);
    glVertex2f(-0.296f, -0.104f);
    glVertex2f(-0.282f, -0.076f);
    glVertex2f(-0.273f, -0.04f);
    glVertex2f(-0.302f, 0.011f);
    glVertex2f(-0.318f, -0.028f);
    glVertex2f(-0.331f, -0.06f);
    glVertex2f(-0.331f, -0.072f);
    glVertex2f(-0.324f, -0.084f);
    glEnd();

    // Leg1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 77, 74);
    glVertex2f(-0.273f, -0.115f);
    glVertex2f(-0.267f, -0.123f);
    glVertex2f(-0.249f, -0.127f);
    glVertex2f(-0.238f, -0.123f);
    glVertex2f(-0.231f, -0.115f);
    glVertex2f(-0.233f, -0.048f);
    glVertex2f(-0.276f, -0.04f);
    glVertex2f(-0.273f, -0.044f);
    glVertex2f(-0.278f, -0.076f);
    glVertex2f(-0.280f, -0.096f);
    glVertex2f(-0.280f, -0.111f);
    glEnd();

    // Body
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.240f, 0.078f);
    glVertex2f(-0.242f, 0.118f);
    glVertex2f(-0.247f, 0.185f);
    glVertex2f(-0.249f, 0.205f);
    glVertex2f(-0.309f, 0.189f);
    glVertex2f(-0.318f, 0.161f);
    glVertex2f(-0.322f, 0.13f);
    glVertex2f(-0.324f, 0.098f);
    glVertex2f(-0.324f, 0.066f);
    glVertex2f(-0.320f, 0.019f);
    glVertex2f(-0.311f, -0.021f);
    glVertex2f(-0.293f, -0.052f);
    glVertex2f(-0.276f, -0.064f);
    glVertex2f(-0.244f, -0.068f);
    glVertex2f(-0.222f, -0.064f);
    glVertex2f(-0.216f, 0.051f);
    glVertex2f(-0.229f, 0.058f);
    glEnd();

    // Tail
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.200f, 0.051f);
    glVertex2f(-0.184f, 0.066f);
    glVertex2f(-0.169f, 0.086f);
    glVertex2f(-0.164f, 0.09f);
    glVertex2f(-0.160f, 0.086f);
    glVertex2f(-0.164f, 0.062f);
    glVertex2f(-0.176f, 0.019f);
    glVertex2f(-0.189f, -0.021f);
    glVertex2f(-0.200f, -0.044f);
    glVertex2f(-0.216f, -0.06f);
    glVertex2f(-0.224f, -0.068f);
    glVertex2f(-0.216f, 0.051f);
    glVertex2f(-0.218f, 0.047f);
    glEnd();

    // Hand2

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.331f, 0.118f);
    glVertex2f(-0.324f, 0.114f);
    glVertex2f(-0.309f, 0.11f);
    glVertex2f(-0.309f, 0.134f);
    glVertex2f(-0.311f, 0.126f);
    glVertex2f(-0.322f, 0.134f);
    glVertex2f(-0.331f, 0.138f);
    glVertex2f(-0.340f, 0.138f);
    glVertex2f(-0.349f, 0.13f);
    glVertex2f(-0.349f, 0.122f);
    glVertex2f(-0.342f, 0.13f);
    glVertex2f(-0.338f, 0.13f);
    glVertex2f(-0.340f, 0.122f);
    glVertex2f(-0.347f, 0.11f);
    glVertex2f(-0.340f, 0.114f);
    glEnd();

    // Hand1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(237, 77, 74);
    glVertex2f(-0.331f, 0.086f);
    glVertex2f(-0.338f, 0.07f);
    glVertex2f(-0.338f, 0.074f);
    glVertex2f(-0.338f, 0.094f);
    glVertex2f(-0.342f, 0.078f);
    glVertex2f(-0.344f, 0.082f);
    glVertex2f(-0.344f, 0.098f);
    glVertex2f(-0.333f, 0.114f);
    glVertex2f(-0.322f, 0.122f);
    glVertex2f(-0.316f, 0.126f);
    glVertex2f(-0.313f, 0.102f);
    glVertex2f(-0.327f, 0.098f);
    glEnd();

    // EYe
    sameEye(-0.31f, 0.27f, -0.31f, 0.27f, 0.015f, 0.01f);
}

void OrangeDino()
{
    // Animation
    // Animation
    glPushMatrix();
    glTranslatef(positionOrangeDino, 0.0f, 0.0f);
    // Orange Dino Scales
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.818f, -0.25f);
    glVertex2f(-0.818f, -0.238f);
    glVertex2f(-0.813f, -0.226f);
    glVertex2f(-0.800f, -0.222f);
    glVertex2f(-0.782f, -0.23f);
    glVertex2f(-0.773f, -0.238f);
    glVertex2f(-0.800f, -0.313f);
    glVertex2f(-0.802f, -0.313f);
    glVertex2f(-0.811f, -0.289f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.756f, -0.159f);
    glVertex2f(-0.744f, -0.171f);
    glVertex2f(-0.733f, -0.187f);
    glVertex2f(-0.727f, -0.21f);
    glVertex2f(-0.773f, -0.234f);
    glVertex2f(-0.776f, -0.202f);
    glVertex2f(-0.773f, -0.175f);
    glVertex2f(-0.769f, -0.163f);
    glVertex2f(-0.762f, -0.155f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.711f, -0.143f);
    glVertex2f(-0.702f, -0.131f);
    glVertex2f(-0.702f, -0.131f);
    glVertex2f(-0.696f, -0.131f);
    glVertex2f(-0.691f, -0.139f);
    glVertex2f(-0.687f, -0.155f);
    glVertex2f(-0.680f, -0.183f);
    glVertex2f(-0.678f, -0.206f);
    glVertex2f(-0.727f, -0.206f);
    glVertex2f(-0.729f, -0.198f);
    glVertex2f(-0.720f, -0.163f);
    glVertex2f(-0.720f, -0.163f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.631f, -0.175f);
    glVertex2f(-0.631f, -0.175f);
    glVertex2f(-0.629f, -0.187f);
    glVertex2f(-0.629f, -0.226f);
    glVertex2f(-0.629f, -0.25f);
    glVertex2f(-0.676f, -0.202f);
    glVertex2f(-0.667f, -0.187f);
    glVertex2f(-0.658f, -0.175f);
    glVertex2f(-0.647f, -0.159f);
    glVertex2f(-0.642f, -0.159f);
    glVertex2f(-0.636f, -0.159f);
    glVertex2f(-0.633f, -0.163f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.593f, -0.25f);
    glVertex2f(-0.596f, -0.277f);
    glVertex2f(-0.600f, -0.313f);
    glVertex2f(-0.609f, -0.325f);
    glVertex2f(-0.631f, -0.25f);
    glVertex2f(-0.618f, -0.234f);
    glVertex2f(-0.604f, -0.226f);
    glVertex2f(-0.604f, -0.226f);
    glVertex2f(-0.596f, -0.226f);
    glVertex2f(-0.593f, -0.234f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.580f, -0.281f);
    glVertex2f(-0.573f, -0.274f);
    glVertex2f(-0.567f, -0.274f);
    glVertex2f(-0.562f, -0.289f);
    glVertex2f(-0.560f, -0.309f);
    glVertex2f(-0.558f, -0.329f);
    glVertex2f(-0.558f, -0.345f);
    glVertex2f(-0.596f, -0.333f);
    glVertex2f(-0.602f, -0.321f);
    glVertex2f(-0.591f, -0.297f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.536f, -0.289f);
    glVertex2f(-0.529f, -0.297f);
    glVertex2f(-0.524f, -0.313f);
    glVertex2f(-0.556f, -0.329f);
    glVertex2f(-0.551f, -0.301f);
    glVertex2f(-0.547f, -0.285f);
    glVertex2f(-0.544f, -0.277f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.524f, -0.289f);
    glVertex2f(-0.524f, -0.274f);
    glVertex2f(-0.522f, -0.27f);
    glVertex2f(-0.518f, -0.27f);
    glVertex2f(-0.511f, -0.277f);
    glVertex2f(-0.507f, -0.289f);
    glVertex2f(-0.522f, -0.309f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 58, 35);
    glVertex2f(-0.507f, -0.274f);
    glVertex2f(-0.507f, -0.258f);
    glVertex2f(-0.504f, -0.254f);
    glVertex2f(-0.498f, -0.254f);
    glVertex2f(-0.493f, -0.266f);
    glVertex2f(-0.507f, -0.289f);
    glEnd();

    // Back Orange Dino Plate
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 164, 48);
    glVertex2f(-0.682f, -0.455f);
    glVertex2f(-0.718f, -0.459f);
    glVertex2f(-0.762f, -0.455f);
    glVertex2f(-0.789f, -0.443f);
    glVertex2f(-0.800f, -0.416f);
    glVertex2f(-0.804f, -0.313f);
    glVertex2f(-0.800f, -0.281f);
    glVertex2f(-0.787f, -0.246f);
    glVertex2f(-0.769f, -0.218f);
    glVertex2f(-0.733f, -0.194f);
    glVertex2f(-0.696f, -0.187f);
    glVertex2f(-0.667f, -0.194f);
    glVertex2f(-0.642f, -0.214f);
    glVertex2f(-0.627f, -0.242f);
    glVertex2f(-0.616f, -0.266f);
    glVertex2f(-0.600f, -0.305f);
    glVertex2f(-0.589f, -0.321f);
    glVertex2f(-0.576f, -0.333f);
    glVertex2f(-0.567f, -0.404f);
    glVertex2f(-0.587f, -0.416f);
    glVertex2f(-0.611f, -0.432f);
    glVertex2f(-0.638f, -0.443f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 164, 48);
    glVertex2f(-0.527f, -0.301f);
    glVertex2f(-0.511f, -0.281f);
    glVertex2f(-0.491f, -0.258f);
    glVertex2f(-0.493f, -0.277f);
    glVertex2f(-0.504f, -0.309f);
    glVertex2f(-0.533f, -0.364f);
    glVertex2f(-0.567f, -0.408f);
    glVertex2f(-0.576f, -0.333f);
    glVertex2f(-0.560f, -0.333f);
    glVertex2f(-0.547f, -0.321f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 164, 48);
    glVertex2f(-0.873f, -0.321f);
    glVertex2f(-0.862f, -0.353f);
    glVertex2f(-0.851f, -0.384f);
    glVertex2f(-0.838f, -0.4f);
    glVertex2f(-0.813f, -0.42f);
    glVertex2f(-0.793f, -0.428f);
    glVertex2f(-0.802f, -0.309f);
    glVertex2f(-0.820f, -0.301f);
    glVertex2f(-0.836f, -0.277f);
    glVertex2f(-0.847f, -0.222f);
    glVertex2f(-0.856f, -0.191f);
    glVertex2f(-0.873f, -0.171f);
    glVertex2f(-0.891f, -0.171f);
    glVertex2f(-0.916f, -0.194f);
    glVertex2f(-0.938f, -0.23f);
    glVertex2f(-0.944f, -0.25f);
    glVertex2f(-0.944f, -0.274f);
    glVertex2f(-0.938f, -0.297f);
    glVertex2f(-0.924f, -0.333f);
    glVertex2f(-0.913f, -0.337f);
    glVertex2f(-0.887f, -0.325f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 163, 48);
    glVertex2f(-0.780f, -0.491f);
    glVertex2f(-0.771f, -0.495f);
    glVertex2f(-0.767f, -0.455f);
    glVertex2f(-0.787f, -0.44f);
    glVertex2f(-0.789f, -0.447f);
    glVertex2f(-0.791f, -0.483f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 163, 48);
    glVertex2f(-0.749f, -0.511f);
    glVertex2f(-0.733f, -0.515f);
    glVertex2f(-0.720f, -0.507f);
    glVertex2f(-0.716f, -0.495f);
    glVertex2f(-0.716f, -0.455f);
    glVertex2f(-0.722f, -0.447f);
    glVertex2f(-0.767f, -0.451f);
    glVertex2f(-0.771f, -0.499f);
    glVertex2f(-0.762f, -0.507f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 163, 48);
    glVertex2f(-0.676f, -0.487f);
    glVertex2f(-0.673f, -0.447f);
    glVertex2f(-0.691f, -0.455f);
    glVertex2f(-0.691f, -0.503f);
    glVertex2f(-0.676f, -0.511f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 163, 48);
    glVertex2f(-0.647f, -0.507f);
    glVertex2f(-0.669f, -0.511f);
    glVertex2f(-0.678f, -0.507f);
    glVertex2f(-0.673f, -0.451f);
    glVertex2f(-0.627f, -0.44f);
    glVertex2f(-0.624f, -0.471f);
    glVertex2f(-0.627f, -0.495f);
    glEnd();

    // Orange Dino nails

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 114, 32);
    glVertex2f(-0.780f, -0.479f);
    glVertex2f(-0.778f, -0.495f);
    glVertex2f(-0.791f, -0.487f);
    glVertex2f(-0.791f, -0.475f);
    glVertex2f(-0.787f, -0.467f);
    glVertex2f(-0.782f, -0.467f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 114, 32);
    glVertex2f(-0.767f, -0.495f);
    glVertex2f(-0.764f, -0.483f);
    glVertex2f(-0.762f, -0.487f);
    glVertex2f(-0.760f, -0.503f);
    glVertex2f(-0.769f, -0.499f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 114, 32);
    glVertex2f(-0.758f, -0.495f);
    glVertex2f(-0.756f, -0.491f);
    glVertex2f(-0.751f, -0.499f);
    glVertex2f(-0.753f, -0.507f);
    glVertex2f(-0.758f, -0.507f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 114, 32);
    glVertex2f(-0.689f, -0.495f);
    glVertex2f(-0.689f, -0.483f);
    glVertex2f(-0.684f, -0.487f);
    glVertex2f(-0.682f, -0.491f);
    glVertex2f(-0.682f, -0.507f);
    glVertex2f(-0.689f, -0.503f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 114, 32);
    glVertex2f(-0.671f, -0.499f);
    glVertex2f(-0.669f, -0.491f);
    glVertex2f(-0.667f, -0.487f);
    glVertex2f(-0.662f, -0.499f);
    glVertex2f(-0.662f, -0.511f);
    glVertex2f(-0.669f, -0.511f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 114, 32);
    glVertex2f(-0.658f, -0.499f);
    glVertex2f(-0.658f, -0.495f);
    glVertex2f(-0.656f, -0.491f);
    glVertex2f(-0.651f, -0.495f);
    glVertex2f(-0.649f, -0.507f);
    glVertex2f(-0.658f, -0.511f);
    glEnd();

    GLfloat p1 = -0.88f;
    GLfloat q1 = -0.21f;
    GLfloat r1 = 0.015f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 180);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (.6 * r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    // EYe Ball

    GLfloat p2 = -0.88f;
    ;
    GLfloat q2 = -0.21f;
    GLfloat r2 = 0.005f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p2, q2);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p2 + (r2 * (0.7) * cos(i * tp2 / tringle2)),
            q2 + (r2 * sin(i * tp2 / tringle2)));
    }
    glEnd();

    glPopMatrix();
}

void Mamoth()
{
    // Body
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(141, 60, 30);
    glVertex2f(0.287f, 0.485f);
    glVertex2f(0.296f, 0.509f);
    glVertex2f(0.304f, 0.525f);
    glVertex2f(0.309f, 0.537f);
    glVertex2f(0.316f, 0.537f);
    glVertex2f(0.324f, 0.529f);
    glVertex2f(0.331f, 0.521f);
    glVertex2f(0.338f, 0.505f);
    glVertex2f(0.344f, 0.497f);
    glVertex2f(0.356f, 0.458f);
    glVertex2f(0.351f, 0.422f);
    glVertex2f(0.342f, 0.387f);
    glVertex2f(0.331f, 0.375f);
    glVertex2f(0.316f, 0.375f);
    glVertex2f(0.316f, 0.387f);
    glVertex2f(0.309f, 0.375f);
    glVertex2f(0.298f, 0.371f);
    glVertex2f(0.280f, 0.379f);
    glVertex2f(0.271f, 0.391f);
    glVertex2f(0.256f, 0.41f);
    glVertex2f(0.262f, 0.442f);
    glVertex2f(0.273f, 0.47f);
    glEnd();

    // Head
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(159, 74, 35);
    glVertex2f(0.356f, 0.422f);
    glVertex2f(0.351f, 0.426f);
    glVertex2f(0.344f, 0.402f);
    glVertex2f(0.324f, 0.442f);
    glVertex2f(0.318f, 0.481f);
    glVertex2f(0.322f, 0.509f);
    glVertex2f(0.331f, 0.517f);
    glVertex2f(0.344f, 0.493f);
    glVertex2f(0.349f, 0.501f);
    glVertex2f(0.347f, 0.505f);
    glVertex2f(0.351f, 0.513f);
    glVertex2f(0.362f, 0.509f);
    glVertex2f(0.371f, 0.509f);
    glVertex2f(0.367f, 0.501f);
    glVertex2f(0.362f, 0.497f);
    glVertex2f(0.367f, 0.489f);
    glVertex2f(0.371f, 0.481f);
    glVertex2f(0.373f, 0.477f);
    glVertex2f(0.380f, 0.458f);
    glVertex2f(0.382f, 0.434f);
    glVertex2f(0.384f, 0.406f);
    glVertex2f(0.382f, 0.394f);
    glVertex2f(0.378f, 0.379f);
    glVertex2f(0.378f, 0.367f);
    glVertex2f(0.380f, 0.363f);
    glVertex2f(0.389f, 0.367f);
    glVertex2f(0.391f, 0.375f);
    glVertex2f(0.391f, 0.379f);
    glVertex2f(0.398f, 0.375f);
    glVertex2f(0.402f, 0.367f);
    glVertex2f(0.396f, 0.367f);
    glVertex2f(0.389f, 0.355f);
    glVertex2f(0.384f, 0.347f);
    glVertex2f(0.376f, 0.347f);
    glVertex2f(0.369f, 0.355f);
    glVertex2f(0.364f, 0.359f);
    glVertex2f(0.360f, 0.391f);
    glEnd();

    // Back Leg

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(131, 108, 92);
    glVertex2f(0.282f, 0.371f);
    glVertex2f(0.284f, 0.363f);
    glVertex2f(0.289f, 0.351f);
    glVertex2f(0.280f, 0.351f);
    glVertex2f(0.273f, 0.363f);
    glVertex2f(0.278f, 0.387f);
    glVertex2f(0.287f, 0.379f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(131, 108, 92);
    glVertex2f(0.342f, 0.367f);
    glVertex2f(0.347f, 0.351f);
    glVertex2f(0.342f, 0.347f);
    glVertex2f(0.336f, 0.347f);
    glVertex2f(0.333f, 0.379f);
    glVertex2f(0.340f, 0.387f);
    glEnd();

    // Front Leg

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 172, 142);
    glVertex2f(0.276f, 0.371f);
    glVertex2f(0.278f, 0.379f);
    glVertex2f(0.260f, 0.383f);
    glVertex2f(0.262f, 0.367f);
    glVertex2f(0.258f, 0.347f);
    glVertex2f(0.280f, 0.343f);
    glVertex2f(0.280f, 0.347f);
    glVertex2f(0.278f, 0.355f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 172, 142);
    glVertex2f(0.320f, 0.367f);
    glVertex2f(0.316f, 0.347f);
    glVertex2f(0.324f, 0.343f);
    glVertex2f(0.336f, 0.343f);
    glVertex2f(0.342f, 0.347f);
    glVertex2f(0.336f, 0.359f);
    glVertex2f(0.336f, 0.383f);
    glVertex2f(0.333f, 0.398f);
    glVertex2f(0.316f, 0.398f);
    glVertex2f(0.318f, 0.379f);
    glEnd();

    // Thong

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(129, 53, 27);
    glVertex2f(0.269f, 0.375f);
    glVertex2f(0.267f, 0.367f);
    glVertex2f(0.260f, 0.379f);
    glVertex2f(0.260f, 0.402f);
    glVertex2f(0.271f, 0.41f);
    glVertex2f(0.280f, 0.394f);
    glVertex2f(0.276f, 0.375f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(129, 53, 27);
    glVertex2f(0.333f, 0.394f);
    glVertex2f(0.329f, 0.41f);
    glVertex2f(0.311f, 0.398f);
    glVertex2f(0.320f, 0.371f);
    glVertex2f(0.336f, 0.375f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 48, 25);
    glVertex2f(0.284f, 0.391f);
    glVertex2f(0.276f, 0.398f);
    glVertex2f(0.278f, 0.371f);
    glVertex2f(0.284f, 0.371f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(120, 48, 25);
    glVertex2f(0.338f, 0.375f);
    glVertex2f(0.342f, 0.379f);
    glVertex2f(0.338f, 0.398f);
    glVertex2f(0.331f, 0.391f);
    glEnd();

    // Nails

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 228, 206);
    glVertex2f(0.271f, 0.351f);
    glVertex2f(0.273f, 0.355f);
    glVertex2f(0.276f, 0.351f);
    glVertex2f(0.280f, 0.351f);
    glVertex2f(0.278f, 0.347f);
    glVertex2f(0.262f, 0.343f);
    glVertex2f(0.267f, 0.351f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 228, 206);
    glVertex2f(0.329f, 0.351f);
    glVertex2f(0.333f, 0.351f);
    glVertex2f(0.338f, 0.355f);
    glVertex2f(0.340f, 0.347f);
    glVertex2f(0.322f, 0.343f);
    glVertex2f(0.324f, 0.355f);
    glEnd();

    // Tooth
}

void Grass(float r, float g, float b)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    // glVertex2f(-0.140f, -0.598f);
    // glVertex2f(-0.136f, -0.614f);
    // glVertex2f(-0.102f, -0.527f);
    // glVertex2f(-0.076f, -0.48f);
    // glVertex2f(-0.096f, -0.551f);
    // glVertex2f(-0.104f, -0.583f);
    // glVertex2f(-0.093f, -0.614f);
    // glVertex2f(-0.087f, -0.63f);
    glVertex2f(-0.116f, -0.701f);
    glVertex2f(-0.113f, -0.634f);
    glVertex2f(-0.118f, -0.567f);
    glVertex2f(-0.127f, -0.5f);
    // glVertex2f(-0.109f, -0.555f);
    // glVertex2f(-0.104f, -0.583f);
    // glVertex2f(-0.087f, -0.638f);
    // glVertex2f(-0.069f, -0.539f);
    // glVertex2f(-0.031f, -0.409f);
    // glVertex2f(-0.009f, -0.349f);
    // glVertex2f(0.011f, -0.318f);
    glVertex2f(0.022f, -0.306f);
    glVertex2f(-0.007f, -0.373f);
    glVertex2f(-0.018f, -0.425f);
    glVertex2f(-0.033f, -0.5f);
    glVertex2f(-0.042f, -0.579f);
    glVertex2f(-0.051f, -0.626f);
    glVertex2f(-0.053f, -0.67f);
    glVertex2f(0.002f, -0.515f);
    glVertex2f(0.020f, -0.476f);
    glVertex2f(0.058f, -0.425f);
    glVertex2f(0.084f, -0.397f);
    glVertex2f(0.060f, -0.44f);
    glVertex2f(0.040f, -0.488f);
    glVertex2f(0.022f, -0.535f);
    glVertex2f(0.004f, -0.594f);
    glVertex2f(-0.013f, -0.658f);
    glVertex2f(-0.011f, -0.757f);
    glVertex2f(-0.022f, -0.824f);
    glVertex2f(0.002f, -0.753f);
    glVertex2f(0.011f, -0.681f);
    glVertex2f(0.002f, -0.61f);
    glVertex2f(-0.018f, -0.523f);
    glVertex2f(-0.004f, -0.535f);
    glVertex2f(0.011f, -0.583f);
    glVertex2f(0.020f, -0.634f);
    glVertex2f(0.027f, -0.697f);
    glVertex2f(0.029f, -0.745f);
    glVertex2f(0.029f, -0.76f);
    glVertex2f(0.044f, -0.693f);
    glVertex2f(0.062f, -0.638f);
    glVertex2f(0.080f, -0.598f);
    glVertex2f(0.107f, -0.551f);
    glVertex2f(0.140f, -0.508f);
    glVertex2f(0.180f, -0.452f);
    glVertex2f(0.218f, -0.405f);
    glVertex2f(0.256f, -0.369f);
    glVertex2f(0.278f, -0.357f);
    glVertex2f(0.238f, -0.393f);
    glVertex2f(0.211f, -0.432f);
    glVertex2f(0.180f, -0.472f);
    glVertex2f(0.151f, -0.535f);
    // glVertex2f(0.133f, -0.559f);
    // glVertex2f(0.118f, -0.614f);
    // glVertex2f(0.100f, -0.677f);
    // glVertex2f(0.091f, -0.717f);
    // glVertex2f(0.098f, -0.757f);
    // glVertex2f(0.100f, -0.796f);
    // glVertex2f(0.118f, -0.737f);
    // glVertex2f(0.122f, -0.658f);
    // glVertex2f(0.131f, -0.587f);
    glVertex2f(0.136f, -0.539f);
    glVertex2f(0.136f, -0.484f);
    glVertex2f(0.136f, -0.448f);
    glVertex2f(0.131f, -0.425f);
    glVertex2f(0.153f, -0.492f);
    glVertex2f(0.156f, -0.539f);
    glVertex2f(0.164f, -0.61f);
    glVertex2f(0.164f, -0.65f);
    glVertex2f(0.164f, -0.713f);
    glVertex2f(0.164f, -0.749f);
    glVertex2f(0.176f, -0.757f);
    glVertex2f(0.196f, -0.725f);
    glVertex2f(0.198f, -0.693f);
    glVertex2f(0.187f, -0.646f);
    glVertex2f(0.171f, -0.602f);
    glVertex2f(0.158f, -0.563f);
    glVertex2f(0.180f, -0.587f);
    glVertex2f(0.202f, -0.646f);
    glVertex2f(0.213f, -0.681f);
    glVertex2f(0.216f, -0.693f);
    glVertex2f(0.236f, -0.638f);
    glVertex2f(0.251f, -0.598f);
    glVertex2f(0.271f, -0.551f);
    glVertex2f(0.289f, -0.511f);
    glVertex2f(0.309f, -0.476f);
    glVertex2f(0.313f, -0.472f);
    glVertex2f(0.298f, -0.527f);
    glVertex2f(0.287f, -0.559f);
    glVertex2f(0.269f, -0.614f);
    glVertex2f(0.260f, -0.654f);
    glVertex2f(0.273f, -0.666f);
    glVertex2f(0.284f, -0.705f);
    glVertex2f(0.289f, -0.725f);
    glVertex2f(0.316f, -0.662f);
    glVertex2f(0.342f, -0.591f);
    glVertex2f(0.376f, -0.543f);
    glVertex2f(0.358f, -0.602f);
    glVertex2f(0.336f, -0.65f);
    glVertex2f(0.322f, -0.693f);
    glVertex2f(0.316f, -0.725f);
    glVertex2f(0.322f, -0.76f);
    glVertex2f(0.327f, -0.808f);
    glVertex2f(0.333f, -0.757f);
    glVertex2f(0.342f, -0.713f);
    glVertex2f(0.336f, -0.674f);
    glVertex2f(0.324f, -0.626f);
    glVertex2f(0.311f, -0.567f);
    glVertex2f(0.293f, -0.531f);
    glVertex2f(0.284f, -0.492f);
    glVertex2f(0.249f, -0.417f);
    glVertex2f(0.247f, -0.409f);
    glVertex2f(0.273f, -0.436f);
    glVertex2f(0.296f, -0.48f);
    glVertex2f(0.318f, -0.515f);
    glVertex2f(0.336f, -0.555f);
    glVertex2f(0.353f, -0.587f);
    // glVertex2f(0.364f, -0.61f);
    // glVertex2f(0.382f, -0.666f);
    // glVertex2f(0.393f, -0.697f);
    // glVertex2f(0.411f, -0.753f);
    // glVertex2f(0.411f, -0.717f);
    // glVertex2f(0.402f, -0.638f);
    // glVertex2f(0.391f, -0.571f);
    // glVertex2f(0.382f, -0.535f);
    // glVertex2f(0.411f, -0.622f);
    // glVertex2f(0.424f, -0.681f);
    glVertex2f(0.433f, -0.764f);
    glVertex2f(0.438f, -0.804f);
    glVertex2f(0.438f, -0.729f);
    glVertex2f(0.436f, -0.658f);
    glVertex2f(0.429f, -0.583f);
    glVertex2f(0.420f, -0.515f);
    glVertex2f(0.402f, -0.46f);
    glVertex2f(0.402f, -0.456f);
    glVertex2f(0.438f, -0.511f);
    glVertex2f(0.464f, -0.61f);
    glVertex2f(0.478f, -0.677f);
    glVertex2f(0.482f, -0.733f);
    glVertex2f(0.498f, -0.812f);
    glVertex2f(0.504f, -0.78f);
    glVertex2f(0.520f, -0.677f);
    glVertex2f(0.547f, -0.618f);
    glVertex2f(0.569f, -0.598f);
    glVertex2f(0.549f, -0.67f);
    glVertex2f(0.542f, -0.741f);
    glVertex2f(0.538f, -0.804f);
    glVertex2f(0.536f, -0.836f);
    glVertex2f(0.536f, -0.836f);
    glVertex2f(0.542f, -0.8f);
    glVertex2f(0.549f, -0.753f);
    glVertex2f(0.553f, -0.689f);
    glVertex2f(0.553f, -0.646f);
    glVertex2f(0.549f, -0.591f);
    glVertex2f(0.538f, -0.519f);
    glVertex2f(0.509f, -0.401f);
    glVertex2f(0.529f, -0.428f);
    glVertex2f(0.549f, -0.468f);
    glVertex2f(0.562f, -0.515f);
    glVertex2f(0.580f, -0.563f);
    glVertex2f(0.591f, -0.602f);
    glVertex2f(0.602f, -0.638f);
    glVertex2f(0.624f, -0.594f);
    glVertex2f(0.640f, -0.547f);
    glVertex2f(0.669f, -0.504f);
    glVertex2f(0.678f, -0.488f);
    glVertex2f(0.653f, -0.555f);
    glVertex2f(0.640f, -0.626f);
    glVertex2f(0.633f, -0.677f);
    glVertex2f(0.640f, -0.709f);
    glVertex2f(0.656f, -0.741f);
    glVertex2f(0.669f, -0.749f);
    glVertex2f(0.696f, -0.709f);
    glVertex2f(0.669f, -0.654f);
    glVertex2f(0.698f, -0.677f);
    glVertex2f(0.696f, -0.63f);
    glVertex2f(0.678f, -0.567f);
    glVertex2f(0.667f, -0.535f);
    glVertex2f(0.660f, -0.519f);
    glVertex2f(0.687f, -0.555f);
    glVertex2f(0.707f, -0.598f);
    glVertex2f(0.727f, -0.646f);
    glVertex2f(0.738f, -0.67f);
    glVertex2f(0.749f, -0.689f);
    glVertex2f(0.749f, -0.618f);
    glVertex2f(0.764f, -0.547f);
    glVertex2f(0.784f, -0.476f);
    glVertex2f(0.804f, -0.425f);
    glVertex2f(0.829f, -0.365f);
    glVertex2f(0.804f, -0.452f);
    glVertex2f(0.798f, -0.535f);
    glVertex2f(0.796f, -0.571f);
    glVertex2f(0.787f, -0.63f);
    glVertex2f(0.791f, -0.677f);
    glVertex2f(0.793f, -0.697f);
    // glVertex2f(0.809f, -0.618f);
    // glVertex2f(0.822f, -0.535f);
    // glVertex2f(0.851f, -0.472f);
    // glVertex2f(0.887f, -0.409f);
    // glVertex2f(0.864f, -0.48f);
    // glVertex2f(0.856f, -0.547f);
    // glVertex2f(0.853f, -0.587f);
    glVertex2f(0.847f, -0.67f);
    glVertex2f(0.847f, -0.725f);
    glVertex2f(0.847f, -0.772f);
    glVertex2f(0.862f, -0.662f);
    glVertex2f(0.882f, -0.571f);
    glVertex2f(0.900f, -0.519f);
    glVertex2f(0.891f, -0.602f);
    glVertex2f(0.882f, -0.681f);
    glVertex2f(0.882f, -0.741f);
    glVertex2f(0.882f, -0.784f);
    glVertex2f(0.882f, -0.725f);
    glVertex2f(0.916f, -0.602f);
    glVertex2f(0.949f, -0.519f);
    glVertex2f(0.998f, -0.444f);
    glVertex2f(0.978f, -0.539f);
    glVertex2f(0.949f, -0.65f);
    glVertex2f(0.933f, -0.796f);
    glVertex2f(0.953f, -0.709f);
    glVertex2f(0.967f, -0.642f);
    glVertex2f(0.980f, -0.685f);
    glVertex2f(0.996f, -0.638f);
    glVertex2f(1.002f, -0.725f);
    glVertex2f(1.002f, -0.907f);
    glVertex2f(-1.002f, -0.915f);
    glVertex2f(-1.002f, -0.567f);
    glVertex2f(-1.000f, -0.563f);
    glVertex2f(-0.996f, -0.539f);
    glVertex2f(-0.998f, -0.559f);
    glVertex2f(-0.996f, -0.539f);
    glVertex2f(-1.002f, -0.563f);
    glVertex2f(-1.000f, -0.559f);
    glVertex2f(-0.996f, -0.563f);
    glVertex2f(-1.000f, -0.567f);
    glVertex2f(-0.996f, -0.571f);
    glVertex2f(-1.000f, -0.571f);
    glVertex2f(-0.993f, -0.559f);
    glVertex2f(-1.002f, -0.579f);
    glVertex2f(-0.996f, -0.575f);
    glVertex2f(-0.998f, -0.571f);
    glVertex2f(-1.000f, -0.583f);
    glVertex2f(-0.998f, -0.587f);
    glVertex2f(-0.998f, -0.567f);
    glVertex2f(-0.998f, -0.547f);
    glVertex2f(-0.991f, -0.547f);
    glVertex2f(-0.996f, -0.567f);
    glVertex2f(-1.002f, -0.559f);
    glVertex2f(-0.998f, -0.587f);
    glVertex2f(-0.996f, -0.587f);
    glVertex2f(-1.000f, -0.559f);
    glVertex2f(-0.987f, -0.504f);
    glVertex2f(-0.971f, -0.44f);
    glVertex2f(-0.942f, -0.361f);
    glVertex2f(-0.916f, -0.31f);
    glVertex2f(-0.931f, -0.365f);
    glVertex2f(-0.947f, -0.44f);
    glVertex2f(-0.958f, -0.515f);
    glVertex2f(-0.978f, -0.638f);
    glVertex2f(-0.980f, -0.658f);
    glVertex2f(-0.944f, -0.551f);
    glVertex2f(-0.900f, -0.456f);
    glVertex2f(-0.853f, -0.397f);
    glVertex2f(-0.884f, -0.472f);
    glVertex2f(-0.904f, -0.531f);
    glVertex2f(-0.922f, -0.594f);
    glVertex2f(-0.938f, -0.642f);
    glVertex2f(-0.953f, -0.689f);
    glVertex2f(-0.962f, -0.745f);
    glVertex2f(-0.964f, -0.78f);
    glVertex2f(-0.951f, -0.689f);
    glVertex2f(-0.902f, -0.563f);
    glVertex2f(-0.871f, -0.535f);
    glVertex2f(-0.911f, -0.622f);
    glVertex2f(-0.924f, -0.677f);
    glVertex2f(-0.942f, -0.741f);
    glVertex2f(-0.947f, -0.796f);
    glVertex2f(-0.949f, -0.82f);
    glVertex2f(-0.916f, -0.689f);
    glVertex2f(-0.887f, -0.63f);
    glVertex2f(-0.858f, -0.555f);
    glVertex2f(-0.831f, -0.5f);
    glVertex2f(-0.818f, -0.488f);
    glVertex2f(-0.844f, -0.583f);
    glVertex2f(-0.853f, -0.638f);
    glVertex2f(-0.862f, -0.725f);
    glVertex2f(-0.862f, -0.768f);
    glVertex2f(-0.860f, -0.78f);
    glVertex2f(-0.851f, -0.717f);
    glVertex2f(-0.842f, -0.662f);
    glVertex2f(-0.836f, -0.63f);
    glVertex2f(-0.824f, -0.587f);
    glVertex2f(-0.811f, -0.535f);
    glVertex2f(-0.793f, -0.488f);
    glVertex2f(-0.780f, -0.444f);
    glVertex2f(-0.744f, -0.373f);
    glVertex2f(-0.724f, -0.345f);
    glVertex2f(-0.742f, -0.397f);
    glVertex2f(-0.764f, -0.468f);
    glVertex2f(-0.780f, -0.539f);
    glVertex2f(-0.789f, -0.583f);
    glVertex2f(-0.800f, -0.646f);
    glVertex2f(-0.807f, -0.689f);
    glVertex2f(-0.807f, -0.709f);
    glVertex2f(-0.796f, -0.662f);
    glVertex2f(-0.780f, -0.614f);
    glVertex2f(-0.760f, -0.575f);
    glVertex2f(-0.744f, -0.535f);
    glVertex2f(-0.720f, -0.496f);
    glVertex2f(-0.709f, -0.488f);
    glVertex2f(-0.736f, -0.551f);
    glVertex2f(-0.744f, -0.598f);
    glVertex2f(-0.760f, -0.642f);
    glVertex2f(-0.771f, -0.674f);
    glVertex2f(-0.782f, -0.749f);
    glVertex2f(-0.769f, -0.784f);
    glVertex2f(-0.771f, -0.729f);
    glVertex2f(-0.747f, -0.642f);
    glVertex2f(-0.716f, -0.594f);
    glVertex2f(-0.738f, -0.674f);
    glVertex2f(-0.751f, -0.717f);
    glVertex2f(-0.713f, -0.681f);
    glVertex2f(-0.687f, -0.618f);
    glVertex2f(-0.662f, -0.567f);
    glVertex2f(-0.680f, -0.646f);
    glVertex2f(-0.704f, -0.713f);
    glVertex2f(-0.700f, -0.745f);
    glVertex2f(-0.700f, -0.788f);
    glVertex2f(-0.691f, -0.8f);
    glVertex2f(-0.678f, -0.693f);
    glVertex2f(-0.667f, -0.65f);
    glVertex2f(-0.647f, -0.614f);
    glVertex2f(-0.629f, -0.583f);
    glVertex2f(-0.598f, -0.559f);
    glVertex2f(-0.622f, -0.602f);
    glVertex2f(-0.638f, -0.638f);
    glVertex2f(-0.651f, -0.662f);
    glVertex2f(-0.658f, -0.697f);
    glVertex2f(-0.667f, -0.816f);
    glVertex2f(-0.667f, -0.847f);
    glVertex2f(-0.653f, -0.788f);
    glVertex2f(-0.653f, -0.745f);
    glVertex2f(-0.653f, -0.713f);
    glVertex2f(-0.653f, -0.681f);
    glVertex2f(-0.656f, -0.606f);
    glVertex2f(-0.660f, -0.543f);
    // glVertex2f(-0.664f, -0.504f);
    // glVertex2f(-0.671f, -0.476f);
    // glVertex2f(-0.671f, -0.472f);
    // glVertex2f(-0.682f, -0.432f);
    // glVertex2f(-0.687f, -0.413f);
    // glVertex2f(-0.691f, -0.397f);
    // glVertex2f(-0.669f, -0.425f);
    // glVertex2f(-0.656f, -0.464f);
    // glVertex2f(-0.638f, -0.519f);
    // glVertex2f(-0.629f, -0.559f);
    // glVertex2f(-0.624f, -0.594f);
    // glVertex2f(-0.611f, -0.638f);
    // glVertex2f(-0.611f, -0.685f);
    // glVertex2f(-0.611f, -0.713f);
    glVertex2f(-0.598f, -0.638f);
    glVertex2f(-0.578f, -0.583f);
    glVertex2f(-0.560f, -0.539f);
    glVertex2f(-0.536f, -0.496f);
    glVertex2f(-0.520f, -0.472f);
    glVertex2f(-0.553f, -0.559f);
    glVertex2f(-0.558f, -0.598f);
    glVertex2f(-0.560f, -0.646f);
    glVertex2f(-0.560f, -0.681f);
    glVertex2f(-0.562f, -0.709f);
    glVertex2f(-0.556f, -0.65f);
    glVertex2f(-0.536f, -0.594f);
    glVertex2f(-0.518f, -0.563f);
    glVertex2f(-0.500f, -0.535f);
    glVertex2f(-0.487f, -0.527f);
    glVertex2f(-0.480f, -0.523f);
    glVertex2f(-0.502f, -0.567f);
    glVertex2f(-0.513f, -0.614f);
    glVertex2f(-0.527f, -0.662f);
    glVertex2f(-0.529f, -0.705f);
    glVertex2f(-0.531f, -0.749f);
    glVertex2f(-0.531f, -0.772f);
    glVertex2f(-0.518f, -0.741f);
    glVertex2f(-0.507f, -0.725f);
    glVertex2f(-0.504f, -0.705f);
    glVertex2f(-0.504f, -0.685f);
    glVertex2f(-0.484f, -0.618f);
    glVertex2f(-0.473f, -0.563f);
    glVertex2f(-0.460f, -0.519f);
    glVertex2f(-0.442f, -0.472f);
    glVertex2f(-0.418f, -0.436f);
    glVertex2f(-0.413f, -0.425f);
    glVertex2f(-0.427f, -0.484f);
    glVertex2f(-0.438f, -0.535f);
    glVertex2f(-0.449f, -0.583f);
    glVertex2f(-0.458f, -0.646f);
    glVertex2f(-0.458f, -0.677f);
    glVertex2f(-0.460f, -0.697f);
    glVertex2f(-0.456f, -0.677f);
    glVertex2f(-0.422f, -0.622f);
    glVertex2f(-0.389f, -0.602f);
    glVertex2f(-0.376f, -0.598f);
    glVertex2f(-0.409f, -0.63f);
    glVertex2f(-0.427f, -0.658f);
    glVertex2f(-0.444f, -0.689f);
    glVertex2f(-0.453f, -0.709f);
    glVertex2f(-0.460f, -0.733f);
    glVertex2f(-0.460f, -0.768f);
    glVertex2f(-0.460f, -0.792f);
    glVertex2f(-0.458f, -0.78f);
    glVertex2f(-0.442f, -0.733f);
    glVertex2f(-0.442f, -0.693f);
    glVertex2f(-0.438f, -0.634f);
    glVertex2f(-0.440f, -0.587f);
    glVertex2f(-0.442f, -0.559f);
    glVertex2f(-0.453f, -0.472f);
    glVertex2f(-0.478f, -0.401f);
    glVertex2f(-0.504f, -0.357f);
    glVertex2f(-0.522f, -0.31f);
    glVertex2f(-0.491f, -0.349f);
    glVertex2f(-0.464f, -0.385f);
    glVertex2f(-0.440f, -0.436f);
    glVertex2f(-0.416f, -0.484f);
    glVertex2f(-0.400f, -0.535f);
    glVertex2f(-0.391f, -0.579f);
    glVertex2f(-0.384f, -0.606f);
    glVertex2f(-0.382f, -0.638f);
    glVertex2f(-0.376f, -0.67f);
    glVertex2f(-0.367f, -0.606f);
    glVertex2f(-0.351f, -0.539f);
    glVertex2f(-0.333f, -0.496f);
    glVertex2f(-0.309f, -0.448f);
    glVertex2f(-0.291f, -0.417f);
    glVertex2f(-0.300f, -0.456f);
    glVertex2f(-0.307f, -0.5f);
    glVertex2f(-0.318f, -0.559f);
    glVertex2f(-0.324f, -0.618f);
    glVertex2f(-0.327f, -0.674f);
    glVertex2f(-0.327f, -0.741f);
    glVertex2f(-0.327f, -0.78f);
    glVertex2f(-0.320f, -0.741f);
    glVertex2f(-0.311f, -0.654f);
    glVertex2f(-0.298f, -0.583f);
    glVertex2f(-0.284f, -0.547f);
    glVertex2f(-0.276f, -0.527f);
    glVertex2f(-0.282f, -0.583f);
    glVertex2f(-0.287f, -0.63f);
    glVertex2f(-0.291f, -0.693f);
    glVertex2f(-0.293f, -0.757f);
    glVertex2f(-0.296f, -0.796f);
    glVertex2f(-0.289f, -0.745f);
    glVertex2f(-0.280f, -0.677f);
    glVertex2f(-0.256f, -0.61f);
    glVertex2f(-0.224f, -0.527f);
    glVertex2f(-0.213f, -0.504f);
    glVertex2f(-0.220f, -0.468f);
    glVertex2f(-0.231f, -0.425f);
    glVertex2f(-0.240f, -0.397f);
    glVertex2f(-0.220f, -0.413f);
    glVertex2f(-0.200f, -0.456f);
    glVertex2f(-0.184f, -0.492f);
    glVertex2f(-0.142f, -0.425f);
    glVertex2f(-0.202f, -0.571f);
    glVertex2f(-0.220f, -0.622f);
    glVertex2f(-0.233f, -0.689f);
    glVertex2f(-0.236f, -0.729f);
    glVertex2f(-0.220f, -0.67f);
    glVertex2f(-0.202f, -0.626f);
    // glVertex2f(-0.193f, -0.61f);
    // glVertex2f(-0.204f, -0.689f);
    // glVertex2f(-0.209f, -0.733f);
    // glVertex2f(-0.211f, -0.796f);
    // glVertex2f(-0.213f, -0.847f);
    // glVertex2f(-0.202f, -0.82f);
    // glVertex2f(-0.200f, -0.764f);
    // glVertex2f(-0.196f, -0.697f);
    // glVertex2f(-0.198f, -0.666f);
    // glVertex2f(-0.202f, -0.614f);
    // glVertex2f(-0.202f, -0.583f);
    // glVertex2f(-0.218f, -0.492f);
    // glVertex2f(-0.236f, -0.405f);
    // glVertex2f(-0.220f, -0.409f);
    // glVertex2f(-0.207f, -0.44f);
    // glVertex2f(-0.198f, -0.472f);
    // glVertex2f(-0.187f, -0.488f);
    // glVertex2f(-0.160f, -0.547f);
    // glVertex2f(-0.149f, -0.575f);
    glEnd();
}

void Lab()
{
    glLineWidth(5);

    //top-side-start

    glBegin(GL_QUADS);//top
    glColor3ub(17, 119, 121);

    glVertex2f(-1.0f, 0.8f);
    glVertex2f(1.0f, 0.8f);

    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();

    //top-side-end

    //Middle-section-bg-start

    glBegin(GL_QUADS);//Middle-section
    glColor3ub(68, 165, 154);

    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);

    glVertex2f(1.0f, 0.8f);
    glVertex2f(-1.0f, 0.8f);

    glEnd();

    //Middle-section-bg-end

    glBegin(GL_QUADS);//bottom
    glColor3ub(226,234,215);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);

    glVertex2f(1.0f, -0.65f);
    glVertex2f(-1.0f, -0.65f);

    glEnd();


    //window-start
    glLineWidth(3.5);//line-left-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.8f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-left-2-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.75f, 0.6f);
    glVertex2f(-0.55f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-left-3-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.50f, 0.6f);
    glVertex2f(-0.30f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-left-4-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.25f, 0.6f);
    glVertex2f(-0.03f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-Right-1-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.03f, 0.6f);
    glVertex2f(0.25f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-Right-2-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.30f, 0.6f);
    glVertex2f(0.50f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-Right-3-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.55f, 0.6f);
    glVertex2f(0.75f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-Right-4-down
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.80f, 0.6f);
    glVertex2f(1.0f, 0.6f);

    glEnd();

    glLineWidth(3.5);//line-left-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-1.0f, 0.75f);
    glVertex2f(-0.8f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-2-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.75f, 0.75f);
    glVertex2f(-0.55f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-3-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.50f, 0.75f);
    glVertex2f(-0.30f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-4-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.25f, 0.75f);
    glVertex2f(-0.03f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-Right-1-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.03f, 0.75f);
    glVertex2f(0.25f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-Right-2-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.30f, 0.75f);
    glVertex2f(0.50f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-Right-3-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.55f, 0.75f);
    glVertex2f(0.75f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-Right-4-top
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.80f, 0.75f);
    glVertex2f(1.0f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.80f, 0.60f);
    glVertex2f(-0.80f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-2-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.75f, 0.60f);
    glVertex2f(-0.75f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-2-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.55f, 0.60f);
    glVertex2f(-0.55f, 0.75f);

    glEnd();


    glLineWidth(3.5);//line-left-3-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.50f, 0.60f);
    glVertex2f(-0.50f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-3-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.30f, 0.60f);
    glVertex2f(-0.30f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-4-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.25f, 0.60f);
    glVertex2f(-0.25f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-4-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.03f, 0.60f);
    glVertex2f(-0.03f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-1-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.03f, 0.60f);
    glVertex2f(0.03f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-1-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.25f, 0.60f);
    glVertex2f(0.25f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-2-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.30f, 0.60f);
    glVertex2f(0.30f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-2-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.50f, 0.60f);
    glVertex2f(0.50f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-3-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.55f, 0.60f);
    glVertex2f(0.55f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-3-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.75f, 0.60f);
    glVertex2f(0.75f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-4-left
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.80f, 0.60f);
    glVertex2f(0.80f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-right-3-right
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(1.0f, 0.60f);
    glVertex2f(1.0f, 0.75f);

    glEnd();

    glLineWidth(3.5);//line-left-door-up-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-1.0f, 0.55f);
    glVertex2f(-0.8f, 0.55f);

    glEnd();

    //window-end

    //door-start
    glLineWidth(3.5);//line-left-door-down-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-1.0f, -0.60f);
    glVertex2f(-0.8f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-left-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.80f, 0.55f);
    glVertex2f(-0.80f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-up-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.75f, 0.55f);
    glVertex2f(-0.55f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-left-door-down-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.75f, -0.60f);
    glVertex2f(-0.55f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-left-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.75f, 0.55f);
    glVertex2f(-0.75f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-right-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.55f, 0.55f);
    glVertex2f(-0.55f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-up-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.50f, 0.55f);
    glVertex2f(-0.30f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-left-door-down-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.50f, -0.60f);
    glVertex2f(-0.30f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-left-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.50f, 0.55f);
    glVertex2f(-0.50f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-right-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.30f, 0.55f);
    glVertex2f(-0.30f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-up-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.25f, 0.55f);
    glVertex2f(-0.03f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-left-door-down-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.25f, -0.60f);
    glVertex2f(-0.03f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-left-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.25f, 0.55f);
    glVertex2f(-0.25f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-left-door-right-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-0.03f, 0.55f);
    glVertex2f(-0.03f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-up-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.03f, 0.55f);
    glVertex2f(0.25f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-right-door-down-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.03f, -0.60f);
    glVertex2f(0.25f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-left-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.03f, 0.55f);
    glVertex2f(0.03f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-right-1
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.25f, 0.55f);
    glVertex2f(0.25f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-up-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.50f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-right-door-down-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.30f, -0.60f);
    glVertex2f(0.50f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-left-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.30f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-right-2
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.50f, 0.55f);
    glVertex2f(0.50f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-up-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.55f, 0.55f);
    glVertex2f(0.75f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-right-door-down-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.55f, -0.60f);
    glVertex2f(0.75f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-left-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.55f, 0.55f);
    glVertex2f(0.55f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-right-3
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.75f, 0.55f);
    glVertex2f(0.75f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-up-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.80f, 0.55f);
    glVertex2f(1.0f, 0.55f);

    glEnd();

    glLineWidth(3.5);//line-right-door-down-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.80f, -0.60f);
    glVertex2f(1.0f, -0.60f);

    glEnd();

    glLineWidth(3.5);//line-right-door-left-4
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(0.80f, 0.55f);
    glVertex2f(0.80f, -0.60f);

    glEnd();

    //door-end

    glLineWidth(5.0);//line
    glBegin(GL_LINES);
    glColor3ub(17, 119, 121);
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(1.0f, -0.65f);

    glEnd();

    //light start
    glBegin(GL_QUADS);//light-left
    glColor3ub(252, 252, 238);

    glVertex2f(-0.65f, 0.90f);
    glVertex2f(-0.25f, 0.90f);

    glVertex2f(-0.25f, 0.85f);
    glVertex2f(-0.65f, 0.85f);

    glEnd();

    glBegin(GL_QUADS);//left-ash
    glColor3ub(150,178,169);

    glVertex2f(-0.65f, 0.90f);
    glVertex2f(-0.60f, 0.90f);

    glVertex2f(-0.60f, 0.85f);
    glVertex2f(-0.65f, 0.85f);

    glEnd();

    glBegin(GL_QUADS);//right-ash
    glColor3ub(150,178,169);

    glVertex2f(-0.25f, 0.90f);
    glVertex2f(-0.20f, 0.90f);

    glVertex2f(-0.20f, 0.85f);
    glVertex2f(-0.25f, 0.85f);

    glEnd();

    glBegin(GL_QUADS);//light-right
    glColor3ub(252, 252, 238);

    glVertex2f(0.65f, 0.90f);
    glVertex2f(0.25f, 0.90f);

    glVertex2f(0.25f, 0.85f);
    glVertex2f(0.65f, 0.85f);

    glEnd();

    glBegin(GL_QUADS);//left-ash
    glColor3ub(150,178,169);

    glVertex2f(0.65f, 0.90f);
    glVertex2f(0.60f, 0.90f);

    glVertex2f(0.60f, 0.85f);
    glVertex2f(0.65f, 0.85f);

    glEnd();

    glBegin(GL_QUADS);//right-ash
    glColor3ub(150,178,169);

    glVertex2f(0.25f, 0.90f);
    glVertex2f(0.20f, 0.90f);

    glVertex2f(0.20f, 0.85f);
    glVertex2f(0.25f, 0.85f);

    glEnd();

    //light-end

    //cabinate
    glBegin(GL_QUADS);//most-left
    glColor3ub(219, 122, 116);

    glVertex2f(-0.88f, -0.75f);
    glVertex2f(-0.83f, -0.75f);

    glVertex2f(-0.83f, 0.20f);
    glVertex2f(-0.90f, 0.20f);

    glEnd();

    glBegin(GL_QUADS);//bg-dark
    glColor3ub(211, 105, 93);

    glVertex2f(-0.83f, -0.75f);
    glVertex2f(-0.63f, -0.75f);

    glVertex2f(-0.62f, 0.20f);
    glVertex2f(-0.83f, 0.20f);

    glEnd();

    glBegin(GL_QUADS);//left-boarder
    glColor3ub(239, 232, 183);

    glVertex2f(-0.83f, -0.75f);
    glVertex2f(-0.815f, -0.75f);

    glVertex2f(-0.815f, 0.2f);
    glVertex2f(-0.83f, 0.2f);

    glEnd();

    glBegin(GL_QUADS);//top-boarder
    glColor3ub(239, 232, 183);

    glVertex2f(-0.815f, 0.20f);
    glVertex2f(-0.62f, 0.20f);

    glVertex2f(-0.62f, 0.15f);
    glVertex2f(-0.815f, 0.15f);

    glEnd();

    glBegin(GL_QUADS);//right-boarder
    glColor3ub(239, 232, 183);

    glVertex2f(-0.62f, 0.15f);
    glVertex2f(-0.635f, 0.15f);

    glVertex2f(-0.635f, -0.75f);
    glVertex2f(-0.62, -0.75f);

    glEnd();

    glBegin(GL_QUADS);//bottom-box
    glColor3ub(243,181,161);

    glVertex2f(-0.815f, -0.75f);
    glVertex2f(-0.635f, -0.75f);

    glVertex2f(-0.635f, -0.60f);
    glVertex2f(-0.815, -0.60f);

    glEnd();

    glBegin(GL_QUADS);//middle-line
    glColor3ub(224,132,124);

    glVertex2f(-0.815f, -0.40f);
    glVertex2f(-0.635f, -0.40f);

    glVertex2f(-0.635f, -0.37f);
    glVertex2f(-0.815, -0.37f);

    glEnd();

    glBegin(GL_QUADS);//top-line
    glColor3ub(224,132,124);

    glVertex2f(-0.815f, -0.15f);
    glVertex2f(-0.635f, -0.15f);

    glVertex2f(-0.635f, -0.12f);
    glVertex2f(-0.815, -0.12f);

    glEnd();

    glBegin(GL_QUADS);//left-table-most
    glColor3ub(219, 122, 116);

    glVertex2f(-0.62f, -0.75f);
    glVertex2f(-0.58f, -0.75f);

    glVertex2f(-0.59f, -0.42f);
    glVertex2f(-0.62f, -0.42f);

    glEnd();

    glBegin(GL_QUADS);//left-table-box
    glColor3ub(245, 188, 166);

    glVertex2f(-0.58f, -0.75f);
    glVertex2f(-0.48f, -0.75f);

    glVertex2f(-0.45f, -0.45f);
    glVertex2f(-0.59f, -0.45f);

    glEnd();

    glLineWidth(2.5);//table-drawer-left-1
    glBegin(GL_LINES);
    glColor3ub(216, 149, 135);
    glVertex2f(-0.585f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

    glBegin(GL_QUADS);//table-drawer-left-box-1
    glColor3ub(216, 149, 135);

    glVertex2f(-0.55f, -0.65f);
    glVertex2f(-0.50f, -0.65f);

    glVertex2f(-0.50f, -0.67f);
    glVertex2f(-0.55f, -0.67f);
    glEnd();

    glLineWidth(2.5);//table-drawer-left-2
    glBegin(GL_LINES);
    glColor3ub(216, 149, 135);
    glVertex2f(-0.587f, -0.55f);
    glVertex2f(-0.46f, -0.55f);

    glEnd();

    glBegin(GL_QUADS);//table-drawer-left-box-2
    glColor3ub(216, 149, 135);

    glVertex2f(-0.55f, -0.55f);
    glVertex2f(-0.50f, -0.55f);

    glVertex2f(-0.50f, -0.57f);
    glVertex2f(-0.55f, -0.57f);
    glEnd();

    glLineWidth(2.5);//table-drawer-left-3
    glBegin(GL_LINES);
    glColor3ub(216, 149, 135);
    glVertex2f(-0.59f, -0.455f);
    glVertex2f(-0.45f, -0.455f);

    glEnd();

    glBegin(GL_QUADS);//table-drawer-left-box-3
    glColor3ub(216, 149, 135);

    glVertex2f(-0.55f, -0.455f);
    glVertex2f(-0.50f, -0.455f);

    glVertex2f(-0.50f, -0.475f);
    glVertex2f(-0.55f, -0.475f);
    glEnd();

    glBegin(GL_QUADS);//right-table
    glColor3ub(219, 122, 116);

    glVertex2f(-0.30f, -0.75f);
    glVertex2f(-0.25f, -0.75f);

    glVertex2f(-0.25f, -0.45f);
    glVertex2f(-0.31f, -0.45f);

    glEnd();

    glBegin(GL_QUADS);//right-table-box
    glColor3ub(245, 199, 169);

    glVertex2f(-0.25f, -0.75f);
    glVertex2f(-0.10f, -0.75f);

    glVertex2f(-0.07f, -0.45f);
    glVertex2f(-0.25f, -0.45f);

    glEnd();

    glLineWidth(2.5);//table-drawer-right-1
    glBegin(GL_LINES);
    glColor3ub(216, 149, 135);
    glVertex2f(-0.25f, -0.65f);
    glVertex2f(-0.09f, -0.65f);

    glEnd();

    glBegin(GL_QUADS);//table-drawer-right-box-1
    glColor3ub(216, 149, 135);

    glVertex2f(-0.20f, -0.65f);
    glVertex2f(-0.15f, -0.65f);

    glVertex2f(-0.15f, -0.67f);
    glVertex2f(-0.20f, -0.67f);
    glEnd();

    glLineWidth(2.5);//table-drawer-right-2
    glBegin(GL_LINES);
    glColor3ub(216, 149, 135);
    glVertex2f(-0.25f, -0.55f);
    glVertex2f(-0.08f, -0.55f);

    glEnd();

    glBegin(GL_QUADS);//table-drawer-right-box-2
    glColor3ub(216, 149, 135);

    glVertex2f(-0.195f, -0.55f);
    glVertex2f(-0.145f, -0.55f);

    glVertex2f(-0.145f, -0.57f);
    glVertex2f(-0.195f, -0.57f);
    glEnd();

    glLineWidth(2.5);//table-drawer-right-3
    glBegin(GL_LINES);
    glColor3ub(216, 149, 135);
    glVertex2f(-0.25f, -0.455f);
    glVertex2f(-0.07f, -0.455f);

    glEnd();

    glBegin(GL_QUADS);//table-drawer-right-box-3
    glColor3ub(216, 149, 135);

    glVertex2f(-0.19f, -0.455f);
    glVertex2f(-0.14f, -0.455f);

    glVertex2f(-0.14f, -0.475f);
    glVertex2f(-0.19f, -0.475f);
    glEnd();

    glBegin(GL_QUADS);//top-table-line
    glColor3ub(249,213,177);

    glVertex2f(-0.59f, -0.45f);
    glVertex2f(-0.07f, -0.45f);

    glVertex2f(-0.07f, -0.42f);
    glVertex2f(-0.59f, -0.42f);

    glEnd();

    glBegin(GL_QUADS);//bottom-machine
    glColor3ub(178,92,119);

    glVertex2f(0.25f, -0.75f);
    glVertex2f(0.50f, -0.75f);

    glVertex2f(0.48f, -0.70f);
    glVertex2f(0.27f, -0.70f);

    glEnd();

    glBegin(GL_QUADS);//bottom-machine
    glColor3ub(234,182,165);

    glVertex2f(0.48f, -0.70f);
    glVertex2f(0.27f, -0.70f);

    glVertex2f(0.27f, -0.55f);
    glVertex2f(0.48f, -0.55f);

    glEnd();

    glBegin(GL_QUADS);//middle-machine
    glColor3ub(174,237,214);

    glVertex2f(0.48f, -0.55f);
    glVertex2f(0.27f, -0.55f);

    glVertex2f(0.26f, 0.05f);
    glVertex2f(0.49f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);//table-2-left
    glColor3ub(255,240,200);

    glVertex2f(0.495f, -0.75f);
    glVertex2f(0.505f, -0.75f);

    glVertex2f(0.505f, -0.44f);
    glVertex2f(0.49f, -0.44f);

    glEnd();

    glBegin(GL_QUADS);//table-2-left-2
    glColor3ub(219,122,116);

    glVertex2f(0.505f, -0.75f);
    glVertex2f(0.56, -0.75f);

    glVertex2f(0.57f, -0.44f);
    glVertex2f(0.505f, -0.44f);

    glEnd();

    glBegin(GL_QUADS);//table-2-right-2
    glColor3ub(219,122,116);

    glVertex2f(0.87f, -0.75f);
    glVertex2f(0.945, -0.75f);

    glVertex2f(0.96f, -0.44f);
    glVertex2f(0.87f, -0.44f);

    glEnd();

    glBegin(GL_QUADS);//table-2-line
    glColor3ub(255,240,200);

    glVertex2f(0.49f, -0.445f);
    glVertex2f(0.96, -0.445f);

    glVertex2f(0.96f, -0.42f);
    glVertex2f(0.49f, -0.42f);

    glEnd();

    //upper-machine
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174,237,214);
    glVertex2f(0.338f, 0.26f);
    glVertex2f(0.293f, 0.232f);
    glVertex2f(0.267f, 0.165f);
    glVertex2f(0.262f, 0.134f);
    glVertex2f(0.260f, 0.062f);
    glVertex2f(0.489f, 0.062f);
    glVertex2f(0.484f, 0.157f);
    glVertex2f(0.464f, 0.213f);
    glVertex2f(0.433f, 0.252f);
    glVertex2f(0.384f, 0.272f);
    glEnd();

    //frame
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174,237,214);
    glVertex2f(0.338f, 0.26f);
    glVertex2f(0.293f, 0.232f);
    glVertex2f(0.267f, 0.165f);
    glVertex2f(0.262f, 0.134f);
    glVertex2f(0.260f, 0.062f);
    glVertex2f(0.489f, 0.062f);
    glVertex2f(0.484f, 0.157f);
    glVertex2f(0.464f, 0.213f);
    glVertex2f(0.433f, 0.252f);
    glVertex2f(0.384f, 0.272f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174,237,214);
    glVertex2f(0.338f, 0.26f);
    glVertex2f(0.293f, 0.232f);
    glVertex2f(0.267f, 0.165f);
    glVertex2f(0.262f, 0.134f);
    glVertex2f(0.260f, 0.062f);
    glVertex2f(0.489f, 0.062f);
    glVertex2f(0.484f, 0.157f);
    glVertex2f(0.464f, 0.213f);
    glVertex2f(0.433f, 0.252f);
    glVertex2f(0.384f, 0.272f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(174,237,214);
    glVertex2f(0.264f, 0.062f);
    glVertex2f(0.262f, 0.062f);
    glVertex2f(0.262f, 0.031f);
    glVertex2f(0.491f, 0.031f);
    glVertex2f(0.489f, 0.066f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250,224,214);
    glVertex2f(0.531f, 0.335f);
    glVertex2f(0.531f, -0.238f);
    glVertex2f(0.569f, -0.274f);
    glVertex2f(0.929f, -0.277f);
    glVertex2f(0.967f, -0.234f);
    glVertex2f(0.969f, 0.343f);
    glVertex2f(0.942f, 0.41f);
    glVertex2f(0.567f, 0.41f);
    glVertex2f(0.531f, 0.335f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(33,88,127);
    glVertex2f(0.913f, 0.359f);
    glVertex2f(0.927f, 0.359f);
    glVertex2f(0.942f, 0.315f);
    glVertex2f(0.942f, -0.206f);
    glVertex2f(0.907f, -0.234f);
    glVertex2f(0.582f, -0.23f);
    glVertex2f(0.553f, -0.202f);
    glVertex2f(0.553f, 0.292f);
    glVertex2f(0.584f, 0.359f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.067f, -0.404f);
    glVertex2f(-0.071f, -0.4f);
    glVertex2f(-0.082f, -0.238f);
    glVertex2f(0.084f, -0.242f);
    glVertex2f(0.087f, -0.404f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225,152,143);
    glVertex2f(0.104f, -0.254f);
    glVertex2f(0.104f, -0.408f);
    glVertex2f(0.089f, -0.408f);
    glVertex2f(0.082f, -0.238f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.009f, -0.408f);
    glVertex2f(-0.009f, -0.479f);
    glVertex2f(0.033f, -0.479f);
    glVertex2f(0.033f, -0.408f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.007f, -0.479f);
    glVertex2f(-0.091f, -0.526f);
    glVertex2f(-0.096f, -0.574f);
    glVertex2f(0.053f, -0.582f);
    glVertex2f(0.076f, -0.523f);
    glVertex2f(0.036f, -0.483f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213,157,148);
    glVertex2f(0.056f, -0.586f);
    glVertex2f(0.084f, -0.617f);
    glVertex2f(-0.096f, -0.606f);
    glVertex2f(-0.098f, -0.574f);
    glVertex2f(0.038f, -0.483f);
    glVertex2f(0.116f, -0.53f);
    glVertex2f(0.084f, -0.617f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(0.033f, -0.483f);
    glVertex2f(-0.096f, -0.578f);
    glVertex2f(0.080f, -0.59f);
    glVertex2f(0.109f, -0.53f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.087f, -0.574f);
    glVertex2f(-0.096f, -0.574f);
    glVertex2f(-0.098f, -0.582f);
    glVertex2f(0.016f, -0.499f);
    glVertex2f(-0.098f, -0.57f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.038f, -0.629f);
    glVertex2f(0.036f, -0.633f);
    glVertex2f(0.056f, -0.617f);
    glVertex2f(-0.058f, -0.613f);
    glVertex2f(-0.058f, -0.613f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(0.016f, -0.669f);
    glVertex2f(0.018f, -0.633f);
    glVertex2f(-0.020f, -0.633f);
    glVertex2f(-0.020f, -0.669f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.020f, -0.633f);
    glVertex2f(0.016f, -0.637f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.047f, -0.681f);
    glVertex2f(-0.018f, -0.673f);
    glVertex2f(-0.020f, -0.669f);
    glVertex2f(-0.051f, -0.677f);
    glVertex2f(-0.062f, -0.7f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(0.042f, -0.689f);
    glVertex2f(0.013f, -0.669f);
    glVertex2f(0.018f, -0.669f);
    glVertex2f(0.051f, -0.685f);
    glVertex2f(0.058f, -0.716f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.018f, -0.677f);
    glVertex2f(-0.018f, -0.669f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.007f, -0.673f);
    glVertex2f(-0.007f, -0.708f);
    glVertex2f(0.002f, -0.708f);
    glVertex2f(0.002f, -0.673f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.044f, -0.724f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.067f, -0.404f);
    glVertex2f(-0.071f, -0.4f);
    glVertex2f(-0.082f, -0.238f);
    glVertex2f(0.084f, -0.242f);
    glVertex2f(0.087f, -0.404f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.067f, -0.404f);
    glVertex2f(-0.071f, -0.4f);
    glVertex2f(-0.082f, -0.238f);
    glVertex2f(0.084f, -0.242f);
    glVertex2f(0.087f, -0.404f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225,152,143);
    glVertex2f(0.104f, -0.254f);
    glVertex2f(0.104f, -0.408f);
    glVertex2f(0.089f, -0.408f);
    glVertex2f(0.082f, -0.238f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225,152,143);
    glVertex2f(0.104f, -0.254f);
    glVertex2f(0.104f, -0.408f);
    glVertex2f(0.089f, -0.408f);
    glVertex2f(0.082f, -0.238f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.009f, -0.408f);
    glVertex2f(-0.009f, -0.479f);
    glVertex2f(0.033f, -0.479f);
    glVertex2f(0.033f, -0.408f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.009f, -0.408f);
    glVertex2f(-0.009f, -0.479f);
    glVertex2f(0.033f, -0.479f);
    glVertex2f(0.033f, -0.408f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.007f, -0.479f);
    glVertex2f(-0.091f, -0.526f);
    glVertex2f(-0.096f, -0.574f);
    glVertex2f(0.053f, -0.582f);
    glVertex2f(0.076f, -0.523f);
    glVertex2f(0.036f, -0.483f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.007f, -0.479f);
    glVertex2f(-0.091f, -0.526f);
    glVertex2f(-0.096f, -0.574f);
    glVertex2f(0.053f, -0.582f);
    glVertex2f(0.076f, -0.523f);
    glVertex2f(0.036f, -0.483f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213,157,148);
    glVertex2f(0.056f, -0.586f);
    glVertex2f(0.084f, -0.617f);
    glVertex2f(-0.096f, -0.606f);
    glVertex2f(-0.098f, -0.574f);
    glVertex2f(0.038f, -0.483f);
    glVertex2f(0.116f, -0.53f);
    glVertex2f(0.084f, -0.617f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213,157,148);
    glVertex2f(0.056f, -0.586f);
    glVertex2f(0.084f, -0.617f);
    glVertex2f(-0.096f, -0.606f);
    glVertex2f(-0.098f, -0.574f);
    glVertex2f(0.038f, -0.483f);
    glVertex2f(0.116f, -0.53f);
    glVertex2f(0.084f, -0.617f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(0.033f, -0.483f);
    glVertex2f(-0.096f, -0.578f);
    glVertex2f(0.080f, -0.59f);
    glVertex2f(0.109f, -0.53f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(0.033f, -0.483f);
    glVertex2f(-0.096f, -0.578f);
    glVertex2f(0.080f, -0.59f);
    glVertex2f(0.109f, -0.53f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.087f, -0.574f);
    glVertex2f(-0.096f, -0.574f);
    glVertex2f(-0.098f, -0.582f);
    glVertex2f(0.016f, -0.499f);
    glVertex2f(-0.098f, -0.57f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,226,201);
    glVertex2f(-0.087f, -0.574f);
    glVertex2f(-0.096f, -0.574f);
    glVertex2f(-0.098f, -0.582f);
    glVertex2f(0.016f, -0.499f);
    glVertex2f(-0.098f, -0.57f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.038f, -0.629f);
    glVertex2f(0.036f, -0.633f);
    glVertex2f(0.056f, -0.617f);
    glVertex2f(-0.058f, -0.613f);
    glVertex2f(-0.058f, -0.613f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.038f, -0.629f);
    glVertex2f(0.036f, -0.633f);
    glVertex2f(0.056f, -0.617f);
    glVertex2f(-0.058f, -0.613f);
    glVertex2f(-0.058f, -0.613f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(0.016f, -0.669f);
    glVertex2f(0.018f, -0.633f);
    glVertex2f(-0.020f, -0.633f);
    glVertex2f(-0.020f, -0.669f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(0.016f, -0.669f);
    glVertex2f(0.018f, -0.633f);
    glVertex2f(-0.020f, -0.633f);
    glVertex2f(-0.020f, -0.669f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.020f, -0.633f);
    glVertex2f(0.016f, -0.637f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.020f, -0.633f);
    glVertex2f(0.016f, -0.637f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.047f, -0.681f);
    glVertex2f(-0.018f, -0.673f);
    glVertex2f(-0.020f, -0.669f);
    glVertex2f(-0.051f, -0.677f);
    glVertex2f(-0.062f, -0.7f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.047f, -0.681f);
    glVertex2f(-0.018f, -0.673f);
    glVertex2f(-0.020f, -0.669f);
    glVertex2f(-0.051f, -0.677f);
    glVertex2f(-0.062f, -0.7f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(0.042f, -0.689f);
    glVertex2f(0.013f, -0.669f);
    glVertex2f(0.018f, -0.669f);
    glVertex2f(0.051f, -0.685f);
    glVertex2f(0.058f, -0.716f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(0.042f, -0.689f);
    glVertex2f(0.013f, -0.669f);
    glVertex2f(0.018f, -0.669f);
    glVertex2f(0.051f, -0.685f);
    glVertex2f(0.058f, -0.716f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.018f, -0.677f);
    glVertex2f(-0.018f, -0.669f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.018f, -0.677f);
    glVertex2f(-0.018f, -0.669f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.007f, -0.673f);
    glVertex2f(-0.007f, -0.708f);
    glVertex2f(0.002f, -0.708f);
    glVertex2f(0.002f, -0.673f);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143,179,172);
    glVertex2f(-0.007f, -0.673f);
    glVertex2f(-0.007f, -0.708f);
    glVertex2f(0.002f, -0.708f);
    glVertex2f(0.002f, -0.673f);
    glEnd();

    //computer

    glBegin(GL_QUADS);
    glColor3ub(182,105,101);

    glVertex2f(-0.55f,-0.35f);
    glVertex2f(-0.35f,-0.35f);

    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.55f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36,88,125);

    glVertex2f(-0.53f,-0.35f);
    glVertex2f(-0.33f,-0.35f);

    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.55f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(231,238,212);

    glVertex2f(-0.53f,-0.32f);
    glVertex2f(-0.33f,-0.32f);

    glVertex2f(-0.33f, -0.35f);
    glVertex2f(-0.53f, -0.35f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,123,116);

    glVertex2f(-0.40f,-0.35f);
    glVertex2f(-0.46f,-0.35f);

    glVertex2f(-0.46f, -0.42f);
    glVertex2f(-0.40f, -0.42f);



    glEnd();

}

// void Actor()
// {
//     glPushMatrix();
//     glTranslatef(positionActor, 0.0f, 0.0f);
//     // Body
//     glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
//     glColor3f(0.4f, 0.0f, .9f); // Red

//     glVertex2f(-0.05f, 0.0f); // x, y
//     glVertex2f(0.05f, 0.0f);  // x, y

//     glVertex2f(0.05f, 0.45f);  // x, y
//     glVertex2f(-0.05f, 0.45f); // x, y
//     glEnd();

//     glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
//     glColor3f(0.0f, 0.7f, 1.0f); // Red

//     glVertex2f(-0.05f, 0.0f); // x, y
//     glVertex2f(-0.05f, -0.45f);
//     glVertex2f(0.03f, -0.45f); // x, y
//     glVertex2f(0.03f, 0.0f);   // x, y
//                                // x, y
//     glEnd();

//     // Head
//     GLfloat p1 = 0.0f;
//     GLfloat q1 = 0.61f;
//     GLfloat r1 = 0.16f;

//     glBegin(GL_TRIANGLE_FAN);
//     glColor3ub(232, 190, 172);
//     glVertex2f(p1, q1);
//     for (i = 0; i <= tringle2; i++)
//     {
//         glVertex2f(
//             p1 + (0.5 * r1 * cos(i * tp2 / tringle2)),
//             q1 + (r1 * sin(i * tp2 / tringle2)));
//     }
//     glEnd();

//     // Shoulder
//     glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
//     glColor3f(0.3f, 0.0f, 0.8f); // Red

//     glVertex2f(-0.03f, 0.4f);  // x, y
//     glVertex2f(-0.03f, 0.25f); // x, y

//     glVertex2f(0.03f, 0.25f); // x, y
//     glVertex2f(0.03f, 0.4f);  // x, y
//     glEnd();

//     // Hands
//     glBegin(GL_QUADS); // Each set of 4 vertices form a quad
//     glColor3ub(232, 190, 172);

//     glVertex2f(-0.02f, 0.25f); // x, y
//     glVertex2f(-0.02f, 0.0f);  // x, y

//     glVertex2f(0.02f, 0.0f);  // x, y
//     glVertex2f(0.02f, 0.25f); // x, y
//     glEnd();

//     // Palm
//     GLfloat p2 = 0.0f;
//     GLfloat q2 = -0.05f;
//     GLfloat r2 = 0.065f;

//     glBegin(GL_TRIANGLE_FAN);
//     glColor3ub(232, 190, 172);
//     glVertex2f(p2, q2);
//     for (i = 0; i <= tringle2; i++)
//     {
//         glVertex2f(
//             p2 + (0.4 * r2 * cos(i * tp2 / tringle2)),
//             q2 + (r2 * sin(i * tp2 / tringle2)));
//     }
//     glEnd();

//     // Shoe
//     GLfloat p3 = -0.015f;
//     GLfloat q3 = -0.47f;
//     GLfloat r3 = 0.05f;

//     glBegin(GL_TRIANGLE_FAN);
//     glColor3f(0.4f, 0.4f, 0.4f);
//     glVertex2f(p3, q3);
//     for (i = 0; i <= tringle2; i++)
//     {
//         glVertex2f(
//             p3 + (1.2 * r3 * cos(i * tp2 / tringle2)),
//             q3 + (r3 * sin(i * tp2 / tringle2)));
//     }
//     glEnd();

//     glPopMatrix();
// }

// void scaleActor(float scale_X, float scale_Y, float scale_Z)
// {
//     glScalef(scale_X, scale_Y, scale_Z);
//     Actor();
// }

// void translateActor(float trans_X, float trans_Y, float trans_Z)
// {
//     glTranslatef(trans_X, trans_Y, trans_Z);
//     scaleActor(0.4, 0.4, 0.0);
// }

void display()
{
    glClearColor(0.0f, 0.9f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    if (positionSun <= 0.001)
    {
        glColor3ub(235, 230, 183);
    }
    else if (positionSun > 0.02 && positionSun < 0.8)
    {
        glColor3ub(132, 193, 251);
    }
    else
    {
        glColor3ub(3, 55, 84);
    }
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0, 1.0f);
    glEnd();

    glLineWidth(5);

    int i;

    Sun();

    Cloud2();

    Mountain();
    glPushMatrix();

    // animation start.............................................
    // making one without translating
    glTranslatef(-positionMamoth, -positionMamoth, 0.0f);
    Mamoth();
    glPopMatrix();
    //................

    // making another by translating
    glPushMatrix();
    glTranslatef(positionMamoth, -positionMamoth, 0.0f);
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, -0.3, 0.0);
    Mamoth();
    glPopMatrix();
    //................
    // animation end................................................

    VolcanicSmoke();
    Volacano();

    Cloud1();

    GreenMount1();
    GreenMount2();
    GreenMount3();

    RedDino();

    // Making two by rotating........................................
    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    RedDino();
    glPopMatrix();
    //...............................................................

    FirstTree();

    SecondTree();
    ThirdTree();

    SmallRock();

    OrangeDino();
    BrownDino();

    // Making two by rotating.......................................
    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    OrangeDino();
    BrownDino();
    glPopMatrix();
    //..............................................................

    Grass(86, 155, 49);

    glPushMatrix();
    glTranslatef(0.009, -0.009, 0.0);
    Grass(73, 142, 42);
    glPopMatrix();

    glPushMatrix();
    translateActor(1.0, -0.9, 0.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glScalef(1.9, 1.9, 0.0);
    glTranslatef(0.7, -0.4, 0.0);
    RedDino1();
    glPopMatrix();

    if (positionActor < -2.7)
    {
        speedActor = 0.0;
    }

    glFlush();
}

void displayFor3()
{
     glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if(positionPiretBoat < -1.01f)
    {
        speedPiretBoat = 0.0f;
    }
    if(positionSoldiersSword < -0.05f)
    {
        speedSoldiersSword = 0.009f;
    }
    if(positionSoldiersSword < -0.06f)
    {
        speedSoldiersSword = -0.009f;
    }

    Cloud1();
    Cloud2();
    Sun();

    river();

    background();

    glPushMatrix();
    translateCanon(-0.8, -0.1, 0.0);
    scaleCanon(0.15,0.15,0);
    glPopMatrix();

    glPushMatrix();
    translateCanonTwo(-0.6, -0.1, 0.0);
    scaleCanonTwo(0.12,0.12,0);
    glPopMatrix();

    glPushMatrix();
    translateDesertTemple(-0.57, 0.6, 0.0);
    scaleDesertTemple(0.37,0.37,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionPiretBoat, 0.0f, 0.0f);
    translatePiretBoat(1.3, 0.49, 0.0);
    scalePiretBoat(0.4, 0.4, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(positionSoldiersSword, 0.0f, 0.0f);
    translateSoldiersSword(0.2, -0.2, 0.0);
    scaleSoldiersSword(0.19, 0.19, 0.0);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.1,1.1,0.0);
    glTranslatef(0.0,0.04,0.0);
    ShowActor();
    glPopMatrix();

    if(positionActor<-7.5){

         glutDisplayFunc(display);
    }


    glFlush();
}

void displayFor2()
{
    glClearColor(1.0f, 1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Lab();
    //drak
    glPushMatrix();
    glTranslatef(positionBg,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor4ub(35,2,116,100);

    glVertex2f(-1.0f, -1.0f);    // x, y
    glVertex2f(1.0f, -1.0f);    // x, y

    glVertex2f(1.0f, 1.0f);    // x, y
    glVertex2f(-1.0f, 1.0f);    // x, y
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glScalef(3.0,3.0,0.0);
    glTranslatef(0.0,.6,0.0);
    ShowActor();
    glPopMatrix();

    if(positionActor<-6.5){

        glutDisplayFunc(displayFor3);
        positionActor = -0.3;

    }

    glFlush();
}

void displayFor1()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Sun();
    glPushMatrix();
    ShowNuclearSmoke();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    ShowNuclearSmoke();
    glPopMatrix();

    Road();

    YellowLand();

    Cloud();

    GreenLand();

    River();
    Water();

    // sale Boat1
    glPushMatrix();
    ShowBoat1();
    glPopMatrix();
    // translate boat1 to left

    glPushMatrix();
    ShowBrokeHouse1();
    glPopMatrix();

    glPushMatrix();
    translateFire1(0.3, 0.4, 0);
    glPopMatrix();

    glPushMatrix();
    ShowBrokeHouse2();
    glPopMatrix();

    glPushMatrix();
    ShowBrokeHouse3();
    glPopMatrix();

    glPushMatrix();
    ShowBrokeHouse4();
    glPopMatrix();

    glPushMatrix();

    ShowBrokeHouse5();
    glPopMatrix();

    glPushMatrix();
    gunFireanimate();
    glPopMatrix();

    glPushMatrix();
    // Tank1();
    ShowTank1();
    glPopMatrix();

    // Tank Stop Animation
    if (positiontank < -4.9)
    {
        speedtank = 0;
    }
    if (positiontank < -4.9)
    {
        glPushMatrix();
        ShowTank1Shoot();
        glPopMatrix();
        glPushMatrix();
        glRotatef(180, 0.0, 1.0, 0.0);
        ShowTank1Shoot();
        glPopMatrix();
    }
    /*if(positiontank<-4.4){
            glPushMatrix();
        bulletAnimate();
        glPopMatrix();
    }*/

    glPushMatrix();
    ShowNuclear();
    glPopMatrix();

    glPushMatrix();
    // Tank1();
    ShowTank1();
    glPopMatrix();

    glPushMatrix();
    ShowTank2();
    glPopMatrix();
    if (positiontank < -4.9)
    {
        glPushMatrix();
        translateBexplode(0.2, 0.1, 0.0);
        glPopMatrix();
        glPushMatrix();
        glRotatef(180, 0.0, 1.0, 0.0);
        translateBexplode(0.2, 0.1, 0.0);
        glPopMatrix();
    }

    ArmyGreen();
    ArmyAsh();

    glPushMatrix();
    Bridge();
    glPopMatrix;

    glPushMatrix();
    ShowBoat2();
    glPopMatrix();
    // scaleBoat2();

    glPushMatrix();
    ShowBoat3();
    glPopMatrix();

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2);
    glLoadIdentity();
    // glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin, spin_x, spin_y, spin_z);

    if (positionActor > -7.1)
    {
        glPushMatrix();
        ShowCloseLab();
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        ShowOpenLab();
        glPopMatrix();
        glutDisplayFunc(displayFor2);
        positionActor = 0;
    }
    glPushMatrix();
    ShowActor();
    glPopMatrix();

    if (positionBigBoat < -1.3)
    {
        speedBigBoat = 0;
    }

    if (positionArmy < -9.0)
    {
        speedArmy = 0;
    }

    /*if(positionBullet<0.5){
        speedBullet=0.0;
    }*/
    if (position < -.3)
    {
        glBegin(GL_QUADS);

        glColor4f(.7, .6, 0.2, 0.3);
        glVertex2f(-1.0, 1.0);
        glVertex2f(-1.0, -1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(1.0, 1.0);
        glEnd();
        speed = 0.0;
    }

    glFlush();
}



// void handleMouse(int button, int state, int x, int y)
// {
//     if (button == GLUT_LEFT_BUTTON)
//     {
//         speedBoat += 0.05f;
//     }
//     if (button == GLUT_RIGHT_BUTTON)
//     {
//         speedBoat -= 0.05f;
//     }
//     glutPostRedisplay();
// }

// void handleKeypress(unsigned char key, int x, int y)
// {
//     switch (key)
//     {
//     case 'z':
//         speedSky = 0.0f;
//         break;
//         glutPostRedisplay();

//     case 'x':
//         speedSky = 0.05f;
//         break;
//         glutPostRedisplay();
//     case 'a':
//         speedActor = 0.04;
//         break;
//     case 's':
//         speedActor = 0.0f;
//         break;
//     case 'd':
//         speedActor = -0.04;
//         break;
//     }
// }

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        speedArmy = +0.1;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        speedtank = -0.01;
    }
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'c':
        speed = 0.0f;
        break;
    case 'w':
        speed = 0.05f;

        break;
        glutPostRedisplay();
    case 't':
        speedtank = 0.0f;
        break;
    case 'r':
        speedtank = 0.05f;
        break;
    case 'a':
        speedActor = 0.05f;
        break;
    case 'd':
        speedActor = -0.05f;
        break;
    case 's':
        speedActor = 0.0f;
        break;
    case '1':

        glutDisplayFunc(displayFor1);

        break;

    case '2':

        glutDisplayFunc(displayFor2);
        break;

    case '3':

        glutDisplayFunc(displayFor3);
        break;

    case '4':
        glutDisplayFunc(display);
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Time Travel of War");
    glutDisplayFunc(displayFor1);
    glutTimerFunc(100, updateFor3, 0);
    glutTimerFunc(100, updateFor2, 0);
    glutTimerFunc(100, updateFor1, 0);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMouseFunc(mouse);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glutMainLoop();
    return 0;
}
