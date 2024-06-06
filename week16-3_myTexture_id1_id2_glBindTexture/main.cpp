///week05_rotating_earth å°ˆæ?
/// ??week05_opencv_opengl_myTexture ç¨‹å??¿ä???
#include <opencv/highgui.h> ///ä½¿ç”¨ OpenCV 2.1 æ¯”è?ç°¡å–®, ?ªè???High GUI ?³å¯
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad = NULL; ///todo: è¦æ?ä¸€é¡†æ?æ¨?
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVè®€??
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCVè½‰è‰²å½?(?€è¦cv.h)
    glEnable(GL_TEXTURE_2D); ///1. ?‹å?è²¼å??Ÿèƒ½
    GLuint id; ///æº–å?ä¸€??unsigned int ?´æ•¸, ??è²¼å?ID
    glGenTextures(1, &id); /// ?¢ç?Generate è²¼å?ID
    glBindTexture(GL_TEXTURE_2D, id); ///ç¶å?bind è²¼å?ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// è²¼å??ƒæ•¸, è¶…é??…è??„ç??–T, å°±é?è¦†è²¼??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// è²¼å??ƒæ•¸, è¶…é??…è??„ç??–S, å°±é?è¦†è²¼??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// è²¼å??ƒæ•¸, ?¾å¤§?‚ç??§æ?, ?¨æ?è¿‘é?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// è²¼å??ƒæ•¸, ç¸®å??‚ç??§æ?, ?¨æ?è¿‘é?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
///?è²¼ä¸?0è¡ŒGLUTç¨‹å? (ä¸è?è²¼å??›ç?ç¨‹å?)
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(angle++, 0, 0, 1);
        gluSphere(quad, 1, 30, 30); ///glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("c:/earth.jpg");
    quad = gluNewQuadric(); ///todo:?Šé€™é??‡æ?,?‡å¥½
    gluQuadricTexture(quad, 1);///todo: ?šå¥½?°ç??„è²¼??
    glutMainLoop();
}
