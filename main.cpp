#include <iostream>
#include <winbgim.h>
#include <time.h>


#define M 100
#define P 200
#define C 300
#define T 400
#define E 500
#define P2 600

using namespace std;

class Graficos
{
private:
public:
    void muro(int x, int y, int e, int color)
    {
        e = e / 6;
        // rectangle(x+2,y+2,x+e-2,y+e-2);
        // rectangle(x+e/4,y+e/4,x+3*e/4,y+3*e/4);
        setcolor(COLOR(100, 100, 255));
        setfillstyle(1, COLOR(100, 100, 255));
        bar(x, y, x + 6 * e, y + 6 * e);

        setcolor(COLOR(255, 255, 255));
        setfillstyle(1, COLOR(255, 255, 255));
        int g = 1;
        for (int i = 0; i < 6; i++)
        {
            bar(x, (y - g) + i * e, x + 6 * e, (y + g) + i * e);
            if (i == 0 || i == 2 || i == 4)
            {
                // 0,2,4,6

                bar((x - g) + 4 * e, y + i * e, (x + g) + 4 * e, y + (i + 1) * e);
            }
            if (i == 1 || i == 3 || i == 5)
            {
                // 1,3,5
                bar((x - g) + 1 * e, y + i * e, (x + g) + 1 * e, y + (i + 1) * e);
            }
        }
    }

    void heroe(int x, int y, int e, int color)
    {

        e = 3;
        y += 9;
        setcolor(color);
        // Cuerpo del tanque
        rectangle(x + 2 * e, y + 2 * e, x + 8 * e, y + 5 * e);
        rectangle(x + 3 * e, y + 1 * e, x + 7 * e, y + 2 * e);
        rectangle(x + 4 * e, y + 0.5 * e, x + 6 * e, y + 1 * e);

        setfillstyle(SOLID_FILL, COLOR(120, 255, 120)); // Color gris oscuro
        floodfill(x + 5 * e, y + 3.5 * e, color);

        // Torreta del tanque
        rectangle(x + 3 * e, y - 1 * e, x + 7 * e, y + 1 * e);
        rectangle(x + 4 * e, y - 2 * e, x + 6 * e, y - 1 * e);
        rectangle(x + 4.5 * e, y - 2 * e, x + 5.5 * e, y - 3 * e);

        setfillstyle(SOLID_FILL, COLOR(50, 50, 50)); // Color gris claro
        floodfill(x + 5 * e, y - 0.5 * e, color);

        // Cañón del tanque
        rectangle(x + 4.5 * e, y - 1 * e, x + 5.5 * e, y - 7 * e);

        setfillstyle(SOLID_FILL, COLOR(100, 100, 100)); // Color gris medio
        floodfill(x + 5 * e, y - 4 * e, color);

        // Ruedas del tanque
        setcolor(COLOR(0, 0, 0));                 // Color negro
        setfillstyle(SOLID_FILL, COLOR(0, 0, 0)); // Color negro

        for (int i = 0; i < 6; i++)
        {
            circle(x + (2 + i * 1.5) * e, y + 5 * e, e / 2);
            floodfill(x + (2 + i * 1.5) * e, y + 5 * e, COLOR(0, 0, 0));
        }
    }

    void eliminado(int x, int y, int e)
    {
        setfillstyle(1, 5);
        setcolor(4);
        sector(x + e / 2, y + e / 2, 0, 360, e / 3, e / 3);
    }
    void vacio(int x, int y, int e)
    {
        setfillstyle(1, 0);
        setcolor(0);
        // sector(x+e/2,y+e/2,0,360,e/3,e/3);
        bar(x, y - 12, x + e, y + e);
    }

    void comida(int x, int y, int e, int color)
    {
    }

    void bomba(int x, int y, int e, int color)
    {
        e = e / 10;

        setcolor(COLOR(200, 200, 200));
        setfillstyle(1, COLOR(200, 200, 200));
        int cir_2[] = {x + 4.5 * e, y + 3 * e, x + 4.5 * e, y + 2 * e, x + 5.5 * e, y + 1 * e, x + 7 * e, y + 1 * e, x + 7 * e, y + 2 * e, x + 6.5 * e, y + 2 * e, x + 6.5 * e, y + 1.5 * e, x + 6 * e, y + 1.5 * e, x + 5.5 * e, y + 2 * e, x + 5.5 * e, y + 4 * e, x + 4.5 * e, y + 3 * e};
        fillpoly(11, cir_2);

        setcolor(COLOR(217, 17, 54));
        setfillstyle(1, COLOR(217, 17, 54));
        int cir_3[] = {x + 6.5 * e, y + 2 * e, x + 7 * e, y + 2 * e, x + 7 * e, y + 2.5 * e, x + 6.5 * e, y + 2.5 * e, x + 6.5 * e, y + 2 * e};
        fillpoly(5, cir_3);

        setcolor(COLOR(44, 44, 44));
        setfillstyle(1, COLOR(44, 44, 44));
        int cir_1[] = {x + 4 * e, y + 2.5 * e, x + 6 * e, y + 2.5 * e, x + 6 * e, y + 4 * e, x + 4 * e, y + 4 * e, x + 4 * e, y + 2.5 * e};
        fillpoly(5, cir_1);

        setcolor(COLOR(66, 66, 66));
        setfillstyle(1, COLOR(66, 66, 66));
        int cir[] = {x + 5 * e, y + 3 * e, x + 7 * e, y + 4 * e, x + 8 * e, y + 6 * e, x + 7 * e, y + 8 * e, x + 5 * e, y + 9 * e, x + 3 * e, y + 8 * e, x + 2 * e, y + 6 * e, x + 3 * e, y + 4 * e, x + 5 * e, y + 3 * e};
        fillpoly(9, cir);

        setcolor(COLOR(200, 200, 200));
        setfillstyle(1, COLOR(200, 200, 200));
        int cir_4[] = {x + 3 * e, y + 5 * e, x + 4 * e, y + 4 * e, x + 4 * e, y + 5 * e, x + 3 * e, y + 5 * e};
        fillpoly(4, cir_4);
    }
    void V(int x, int y, int e)
    {
        setfillstyle(1, 0);
        bar(x, y, x + e, y + e);
    }
};

class Matriz
{
private:
    int juego[200][200];
    int filas;
    int columnas;
    int totalMuros;

public:
    Matriz()
    {
    }
    void setTotalMuros(int tm)
    {
        totalMuros = tm;
    }
    void SetMatriz(int f, int c)
    {
        // cout<<"Inicializa matriz";
        filas = f;
        columnas = c;
        /*juego=new int[filas];
        for(int i=0;i<filas;i++){
            juego[i]=new int[columnas];
        }*/

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                juego[i][j] = C;
            }
        }

        for (int i = 0; i < columnas; i++)
        {
            juego[0][i] = M;
            juego[filas - 1][i] = M;
        }

        for (int i = 0; i < filas; i++)
        {
            juego[i][0] = M;
            juego[i][columnas - 1] = M;
        }

        srand(time(NULL));
        for (int i = 0; i < totalMuros; i++)
        {
            ponerMuro();
        }
    }
    void ponerMuro()
    {
        int i = rand() % (filas - 2) + 1;
        int j = rand() % (columnas - 2) + 1;
        juego[i][j] = M;
        juego[i][j + 1] = M;
        juego[i + 1][j + 1] = M;
    }
    int getFilas()
    {
        return filas;
    }
    int getColumas()
    {
        return columnas;
    }
    int getValor(int i, int j)
    {
        return juego[i][j];
    }
    void setValorMatriz(int i, int j, int v)
    {
        juego[i][j] = v;
    }
};

class Juego
{
private:
    int filas;
    int columnas;
    int xini;
    int yini;
    int escala;
    Graficos g;
    Matriz m;

    int persona_i;
    int persona_j;

    int persona2_i;
    int persona2_j;

    int bomba_i;
    int bomba_j;

    int nivel;
    int muros_a_romper;

public:
    Juego(int n)
    {
        nivel = n;
        muros_a_romper = 10;
        m.setTotalMuros(50);
        filas = (nivel + 2) * 6.5;
        columnas = (nivel + 2) * 11;
    }
    void setFilas(int f)
    {
        filas = f;
    }
    void gravedad()
    {
        persona_i++;
    }
    void setColumnas(int c)
    {
        columnas = c;
    }
    void setPosJuego(int x, int y)
    {
        xini = x;
        yini = y;
    }
    void setEscala(int e)
    {
        escala = e;
    }
    void crearMatriz()
    {
        m.SetMatriz(filas, columnas);
    }
    bool gano()
    {
        for (int i = 0; i < m.getFilas(); i++)
        {
            for (int j = 0; j < m.getColumas(); j++)
            {
                if (m.getValor(i, j) == C)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void mostrarJuego()
    {
        for (int i = 0; i < m.getFilas(); i++)
        {
            for (int j = 0; j < m.getColumas(); j++)
            {
                g.V(xini + j * escala, yini + i * escala, escala);
                if (m.getValor(i, j) == M)
                {
                    g.muro(xini + j * escala, yini + i * escala, escala, COLOR(0, 0, 255));
                }
                if (m.getValor(i, j) == P)
                {
                    g.heroe(xini + j * escala, yini + i * escala, escala, COLOR(255, 0, 255));
                }
                if (m.getValor(i, j) == P2)
                {
                    g.heroe(xini + j * escala, yini + i * escala, escala, COLOR(0, 250, 255));
                }
                if (m.getValor(i, j) == E)
                {
                    g.eliminado(xini + j * escala, yini + i * escala, escala);
                }
                if (m.getValor(i, j) == C)
                {
                    g.comida(xini + j * escala, yini + i * escala, escala, COLOR(255, 0, 0));
                    // draw_manza(xini+j*e,yini+i*e,e);
                }
                if (m.getValor(i, j) == T)
                {
                    g.bomba(xini + j * escala, yini + i * escala, escala, COLOR(0, 255, 0));
                }
            }
        }
    }

    int getAleatorio(int minimo, int maximo)
    {
        return rand() % (maximo - minimo) + minimo;
    }
    bool enJuego()
    {
        persona_i = 1;
        persona_j = 1;

        persona2_i = 2;
        persona2_j = 24;

        bomba_i = 0;
        bomba_j = 0;

        m.setValorMatriz(persona_i, persona_j, P);

        m.setValorMatriz(persona2_i, persona2_j, P2);

        mostrarJuego();

        int paredes_r = 0;
        int tecla = 0;
        int comidas;
        bool perdiste;

        while (tecla != 13)
        {

            // cout<<tecla<<endl;
            // cleardevice();
            // mat[persona_i][persona_j]=0;
            m.setValorMatriz(persona_i, persona_j, 0);

            // g.heroe(xini+persona_j*50,yini+persona_i*50,50,0);

            if (comidas % 5 == 0 && tecla != 0)
            {
                cout << "Bomba puesta";
                g.vacio(xini + bomba_j * escala, yini + bomba_i * escala, escala);
                g.bomba(xini + bomba_j * escala, yini + bomba_i * escala, escala, 0);
                // dib_matriz(50,50,50,mat,10,10);
                //--->mostrarJuego();
            }
            /***********/

            if (kbhit())
            {
                tecla = getch();
                if (tecla == 77)
                {
                    if (m.getValor(persona_i, persona_j + 1) != M)
                    {
                        g.vacio(xini + persona_j * escala, yini + persona_i * escala, escala);
                        persona_j++;
                        g.heroe(xini + persona_j * escala, yini + persona_i * escala, escala, COLOR(255, 0, 255));
                    }
                }
                if (tecla == 75)
                {
                    if (m.getValor(persona_i, persona_j - 1) != M)
                    {
                        g.vacio(xini + persona_j * escala, yini + persona_i * escala, escala);
                        persona_j--;
                        g.heroe(xini + persona_j * escala, yini + persona_i * escala, escala, COLOR(255, 0, 255));
                    }
                }
                if (tecla == 72)
                {
                    if (m.getValor(persona_i - 1, persona_j) != M)
                    {
                        g.vacio(xini + persona_j * escala, yini + persona_i * escala, escala);
                        persona_i--;
                        g.heroe(xini + persona_j * escala, yini + persona_i * escala, escala, COLOR(255, 0, 255));
                    }
                }

                // tecla enemigo
                if (tecla == 'd')
                {
                    if (m.getValor(persona2_i, persona2_j + 1) != M)
                    {
                        g.vacio(xini + persona2_j * escala, yini + persona2_i * escala, escala);
                        persona2_j++;
                        g.heroe(xini + persona2_j * escala, yini + persona2_i * escala, escala, COLOR(0, 250, 255));
                    }
                }
                if (tecla == 'a')
                {
                    if (m.getValor(persona2_i, persona2_j - 1) != M)
                    {
                        g.vacio(xini + persona2_j * escala, yini + persona2_i * escala, escala);
                        persona2_j--;
                        g.heroe(xini + persona2_j * escala, yini + persona2_i * escala, escala, COLOR(0, 250, 255));
                    }
                }
                if (tecla == 'w')
                {
                    if (m.getValor(persona2_i - 1, persona2_j) != M)
                    {
                        g.vacio(xini + persona2_j * escala, yini + persona2_i * escala, escala);
                        persona2_i--;
                        g.heroe(xini + persona2_j * escala, yini + persona2_i * escala, escala, COLOR(0, 250, 255));
                    }
                }
            }

            if (m.getValor(persona_i + 1, persona_j) != M)
            {
                g.vacio(xini + persona_j * escala, yini + persona_i * escala, escala);
                persona_i++;
                g.heroe(xini + persona_j * escala, yini + persona_i * escala, escala, COLOR(255, 0, 255));
            }

            if (m.getValor(persona2_i + 1, persona2_j) != M)
            {
                g.vacio(xini + persona2_j * escala, yini + persona2_i * escala, escala);
                persona2_i++;
                g.heroe(xini + persona2_j * escala, yini + persona2_i * escala, escala, COLOR(0, 255, 255));
            }

            delay(200);

            //--->mostrarJuego();

            // mat[persona_i][persona_j]=P;
            // dib_matriz(50,50,50,mat,10,10);
        }
    }
};

int main()
{
    initwindow(1200, 600);
    int nivel = 1;
    while (true)
    {
        Juego j(nivel);
        j.setPosJuego(10, 10);
        j.setEscala(30);
        j.crearMatriz();
        //--->j.mostrarJuego();
        if (j.enJuego())
        {
            nivel++;
        }
    }

    getch();
    getch();
    return 0;
}