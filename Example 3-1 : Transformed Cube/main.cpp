// O processo de transformação para produzir a cena desejada 
// para visualização é análogo a tirar uma fotografia com uma câmera.

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//O Exemplo 3-1 desenha um cubo que é dimensionado por uma transformação de modelagem 

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   // O comando gluLookAt multiplica a matriz atual 
   // pela matriz especificada
   // Se você não limpar a matriz atual usando a matriz
   // identidade, ele continuará combinando as matrizes de 
   // transformação anteriores com a nova fornecida. 
   glLoadIdentity ();            
   /* transformação de visualização  */
   //A transformação de visualização, gluLookAt () , 
   //posiciona e aponta a câmera para onde o cubo é desenhado. 
   //Os argumentos para este comando indicam onde a câmera 
   //(ou posição do olho) é colocada
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   //Observe que em vez de mover a câmera (com uma transformação de visualização) 
   // para que o cubo pudesse ser visualizado, você poderia ter
   // movido o cubo para longe da câmera (com uma transformação de modelagem). 
   //glTranslatef ()

   /* transformação de modelagem (escla) */ 
   glScalef (1.0, 2.0, 1.0);      
   glutWireCube (1.0);
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   // Transformação da Projeção = é como escolher uma lente para uma câmera
   // determina como os objetos são projetados na tela
   // Um tipo é a projeção em perspectiva, 
   // que corresponde à maneira como você vê as coisas na vida diária.
   // A perspectiva faz com que os objetos mais distantes pareçam menores
   // gluPerspective() tambem faz isso
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}