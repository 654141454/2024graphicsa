#include <GL/glut.h>

void display(){
    glBegin(GL_POLYGON);
        glColor3f(0,1,1); glVertex2f(0,1);
        glColor3f(1,0.27,0.45); glVertex2f(+1,-0.6);
        glColor3f(1,0.60,); glVertex2f(-1,-0.6);
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char *argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///第140行,開啟GLUT功能
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143行,設定顯示模式
    glutCreateWindow("2024電腦圖學第01週");///145行，開一個GLUT視窗
    glutDisplayFunc(display);
    glutMainLoop();///174行,主要的迴圈,在這裡一直運作
}

