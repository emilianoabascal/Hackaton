#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include <vector>

using namespace std;

float ancho = 700;
float alto = 700;

int hor_streets = 0;
int ver_streets = 0;

float ancho_carril = 12;

class Carril{
    
};

class Seccion{
public:
    
};

class Avenida{
public:
    vector<int> n;
};

//INICIALIZAR DEFAULTS DE LA PANTALLA
void inicializar(void){
    glClearColor (0.8, 0.8, 0.8, 0.0);
    glShadeModel (GL_FLAT);
}


void escena(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-350.0, 350.0, -350.0, 350.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawStreet(float x1, float y1, float x2, float y2){
    glPushMatrix();
    glRectf(x1,y1,x2,y2);
    glPopMatrix();
}

void nombre(void){
    glClear(GL_COLOR_BUFFER_BIT);
    //glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    
    int num_carriles;
    string doble_sentido;
    //bool doble_sentido = false;
    
    float sep_vertical = alto / (hor_streets + 1);
    float sep_horizontal = ancho / (ver_streets + 1);
    
    float init_ver = - (alto / 2);
    float init_hor = -(ancho / 2);
    
    for (int i = 0; i < hor_streets; i++) {
        cout << "Numero de carriles para la calle horizontal " << i + 1 << ":";
        cin >> num_carriles;
        cout << "Doble sentido? (y/n):";
        cin >> doble_sentido;
        
        if (doble_sentido == "y") {
            num_carriles = num_carriles * 2;
            cout << "Doble" << endl;
            float p_ref = init_ver + sep_vertical;
            float sep_inicial = ((num_carriles * ancho_carril) + 3) / 2;
            for (int o = 0; o < num_carriles; o++) {
                cout << "Carril " << o + 1 << endl;
                if (o == ((num_carriles/2)-1)) {
                    drawStreet(-350, p_ref, 350, p_ref + ancho_carril);
                    p_ref = p_ref + 3;
                    glColor3f(0.5, 1.0, 0.0);
                    drawStreet(-350,p_ref -3 + ancho_carril, 350, p_ref + ancho_carril + 3);
                    glColor3f(0.0, 0.0, 0.0);
                }
                else{
                    drawStreet(-350, p_ref, 350, p_ref + ancho_carril);
                    if(o < num_carriles - 1){
                        glColor3f(1.0, 1.0, 1.0);
                        drawStreet(-350, p_ref + ancho_carril, 350, p_ref + ancho_carril + 1);
                        glColor3f(0.0, 0.0, 0.0);
                    }
                }
                p_ref = p_ref + ancho_carril + 1;
            }
        }
        else if(doble_sentido == "n"){
            cout << "Sencillo" << endl;
            float p_ref = init_ver + sep_vertical;
            float sep_inicial = (num_carriles * ancho_carril) / 2;
            for (int o = 0; o < num_carriles; o++) {
                cout << "Carril " << o + 1 << endl;
                drawStreet(-350, p_ref, 350, p_ref + ancho_carril);
                if(o < num_carriles - 1){
                    glColor3f(1.0, 1.0, 1.0);
                    drawStreet(-350, p_ref + ancho_carril, 350, p_ref + ancho_carril + 1);
                    glColor3f(0.0, 0.0, 0.0);
                }
                p_ref = p_ref + ancho_carril + 1;
            }
        }
        init_ver = init_ver + sep_vertical;
    }
    
    for (int i = 0; i < ver_streets; i++) {
        cout << "Numero de carriles para la calle vertical " << i + 1 << ":";
        cin >> num_carriles;
        cout << "Doble sentido? (y/n):";
        cin >> doble_sentido;
        
        if (doble_sentido == "y") {
            cout << "Doble" << endl;
            num_carriles = num_carriles * 2;
            float p_ref = init_hor + sep_horizontal;
            float sep_inicial2 = ((num_carriles * ancho_carril) + 3) / 2;
            for (int o = 0; o < num_carriles; o++) {
                cout << "Carril " << o + 1 << endl;
                if (o == ((num_carriles/2)-1)) {
                    drawStreet(p_ref, -350,p_ref + ancho_carril,350);
                    p_ref = p_ref + 3;
                    glColor3f(0.5, 1.0, 0.0);
                    drawStreet(p_ref -3 + ancho_carril,350,p_ref + ancho_carril + 3, -350);
                    glColor3f(0.0, 0.0, 0.0);
                }
                else{
                    drawStreet(p_ref, 350, p_ref + ancho_carril, -350);
                    if(o < num_carriles - 1){
                        glColor3f(1.0, 1.0, 1.0);
                        drawStreet(p_ref + ancho_carril, 350, p_ref + ancho_carril + 1, -350);
                        glColor3f(0.0, 0.0, 0.0);
                    }
                }
                p_ref = p_ref + ancho_carril + 1;
            }
            
        }
        else if(doble_sentido == "n"){
            cout << "Sencillo" << endl;
            float p_ref = init_hor + sep_horizontal;
            float sep_inicial = (num_carriles * ancho_carril) / 2;
            for (int o = 0; o < num_carriles; o++) {
                cout << "Carril " << o + 1 << endl;
                drawStreet( p_ref, 350, p_ref + ancho_carril, -350);
                if(o < num_carriles - 1){
                    glColor3f(1.0, 1.0, 1.0);
                    drawStreet( p_ref + ancho_carril, 350, p_ref + ancho_carril + 1, -350);
                    glColor3f(0.0, 0.0, 0.0);
                }
                p_ref = p_ref + ancho_carril + 1;
            }
        }
        init_hor = init_hor + sep_horizontal;
        //drawStreet(init_hor, 350, init_hor + ancho_carril, -350);
    }
    //glPopMatrix();
    glutSwapBuffers();
}




int main(int argc, char** argv){
    
    cout << "Número de calles horizontales:";
    cin >> hor_streets;
    cout << "Número de calles verticales:";
    cin >> ver_streets;
    
    glutInit(&argc, argv);                          //SET VENTANA PARA OPENGL
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);   //DISPLAY MODE
    glutInitWindowSize (ancho, alto);                  //DECLARAR ANCHO Y ALTO DE LA PANTALLA
    glutInitWindowPosition (100, 100);              //DECLARAR POSICIÓN INICIAL DE LA VENTANA
    glutCreateWindow ("Mi ventana de OpenGL");      //CREAR VENTANA CON NOMBRE
    inicializar ();                                 //INICIALIZAR VENTANA
    glutDisplayFunc(nombre);                        //DISPLAY DE LO QUE SE DIBUJÓ
    glutReshapeFunc(escena);                        //
    glutMainLoop();
}
