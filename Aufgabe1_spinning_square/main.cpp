// FirstProgram.cpp : Einfaches OpenGL Programm
// Zeichnet 1 weisses Quadrat in ein Fenster der Groesse 250 x 250.
// Die Hintergrundfarbe des Fensters ist schwarz.
//
#include <GL/glut.h>

GLfloat angle = 0;
// Definition der Objekte, die gezeichnet werden sollen
// hier 1 Quadrat
void display(void)
{  
    if(angle > 360) angle = 0;
    angle += 0.05;
   // Loeschen des Ausgabefensters
   glClear(GL_COLOR_BUFFER_BIT); 
   
   // Definition der Farbe des Objektes
   glColor3f(0.0, 0.0, 1.0);     



   // Quadrat wird als Polygon definiert
   glBegin(GL_POLYGON); 
      // Koordinaten der Eckpunkte
      glVertex3f(0.25, 0.25, 0.0);
      glVertex3f(0.75, 0.25, 0.0);
      glVertex3f(0.75, 0.75, 0.0);
      glVertex3f(0.25, 0.75, 0.0);
   glEnd(); // Ende der Quadrat-Definition

   glLoadIdentity();
   glTranslated(0.5,0.5,0);
   glRotatef(angle, 0, 0, 1);
   glTranslated(-0.5,-0.5,0);



  // glutSwapBuffers();

   glFlush(); // Gepufferte OpenGL-Objekte werden erst jetzt verarbeitet
   glutPostRedisplay();
}

void init(void)
{
   // Hintergrundfarbe loeschen und auf die Farbe "weiss" setzen
   glClearColor(1.0, 1.0, 1.0, 0.0);
   
   // Projektions-Parameter setzen: 
   // die aktuelle Matrix bestimmt die Projektions-Transformation 
   // und alle folgenden Transformations-Änderungen beeinflussen diese Projektions-Matrix
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main (int argc, char** argv)
{
// Deklaration der initialen Fenstergroesse und -position und des
// Darstellungsmodus (einfacher Puffer und RGBA). 
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(250,250);
   glutInitWindowPosition(100,100);

   // Oeffnen des Fensters mit einem Title
   glutCreateWindow("Grüss Gott meine Studenten!");
   
   // Aufruf der Initialisierungs-Funktion
   init();
   
   // Registriere Funktionen als callback-Funktion zum Zeichnen der Grafiken
   // hier: callBack-Funktion = display()
   // Aktion: sende Grafiken ans Ausgabefenster
   glutDisplayFunc(display);
   
   // Beginne den "main loop" und fuehre alle Prozesse aus,
   // d.h. zeichne alles und warte.
   glutMainLoop();
   return 0;
}

