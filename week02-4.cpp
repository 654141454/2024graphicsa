#include <GL/glut.h>
#include <math.h>
void myCircle(float x,float y,float r){
    glBegin(GL_POLYGON);
    for(float a=0;a<=3.1415*2;a+=0.1){
        glVertex2f(r*cos(a)+x,r*sin(a)+y);
    }
    glEnd();
}
void display(){
    myCircle(0.5,0.5,0.3);
    myCircle(-0.5,0.5,0.3);
    myCircle(0,-0.1,0.6);
}
int main(int argc, char *argv[])///��138��,main()�禡
{
    glutInit(&argc, argv);///��140��,�}��GLUT�\��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143��,�]�w��ܼҦ�
    glutCreateWindow("2024�q���Ͼǲ�01�g");///145��A�}�@��GLUT����
    glutDisplayFunc(display);
    glutMainLoop();///174��,�D�n���j��,�b�o�̤@���B�@
}