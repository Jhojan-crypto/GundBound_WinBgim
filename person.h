
class Person
{
private:
    int x;
    int y;
    int e;

public:
    Person(int x, int y, int e)
    {
        this->x = x;
        this->y = y;
        this->e = e;
    }
    ~Person()
    {
    }
    void pintar(int color)
    {

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
        rectangle(x + 4.5 * e, y - 3 * e, x + 5.5 * e, y - 8 * e);

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
    void borrar()
    {
        setcolor(COLOR(255, 255, 255)); // Color blanco

        // Borra el cuerpo del tanque
        rectangle(x + 2 * e, y + 2 * e, x + 8 * e, y + 5 * e);
        rectangle(x + 3 * e, y + 1 * e, x + 7 * e, y + 2 * e);
        rectangle(x + 4 * e, y + 0.5 * e, x + 6 * e, y + 1 * e);
        setfillstyle(SOLID_FILL, COLOR(255, 255, 255)); // Color blanco
        floodfill(x + 5 * e, y + 3.5 * e, COLOR(255, 0, 0));

        // Borra la torreta del tanque
        rectangle(x + 3 * e, y - 1 * e, x + 7 * e, y + 1 * e);
        rectangle(x + 4 * e, y - 2 * e, x + 6 * e, y - 1 * e);
        rectangle(x + 4.5 * e, y - 2 * e, x + 5.5 * e, y - 3 * e);
        setfillstyle(SOLID_FILL, COLOR(255, 255, 255)); // Color blanco
        floodfill(x + 5 * e, y - 0.5 * e, COLOR(255, 0, 0));

        // Borra el cañón del tanque
        rectangle(x + 4.5 * e, y - 3 * e, x + 5.5 * e, y - 8 * e);
        setfillstyle(SOLID_FILL, COLOR(255, 255, 255)); // Color blanco
        floodfill(x + 5 * e, y - 4 * e, COLOR(255, 0, 0));

        // Borra las ruedas del tanque
        setcolor(COLOR(255, 255, 255));                 // Color blanco
        setfillstyle(SOLID_FILL, COLOR(255, 255, 255)); // Color blanco

        for (int i = 0; i < 6; i++)
        {
            circle(x + (2 + i * 1.5) * e, y + 5 * e, e / 2);
            floodfill(x + (2 + i * 1.5) * e, y + 5 * e, COLOR(255, 255, 255));
        }
    }

    int setX(int x) { this->x = x; }
    int setY(int y) { this->x = y; }
    int getX() { return this->x; }
    int getY() { return this->x; }
    int setXY(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Bala
{
private:
    int x;
    int y;
    int e;

public:
    Bala(int x, int y, int e)
    {
        this->x = x;
        this->y = y;
        this->e = e;
    }
    ~Bala()
    {
    }
    void pintar()
    {
        setcolor(COLOR(255, 0, 0)); // Color rojo

        // Cuerpo del cohete
        rectangle(x + 2 * e, y + 2 * e, x + 8 * e, y + 5 * e);
        rectangle(x + 3 * e, y + 1 * e, x + 7 * e, y + 2 * e);
        rectangle(x + 4 * e, y + 0.5 * e, x + 6 * e, y + 1 * e);

        setfillstyle(SOLID_FILL, COLOR(255, 255, 0)); // Color amarillo
        floodfill(x + 5 * e, y + 3.5 * e, COLOR(255, 0, 0));

        // Parte superior del cohete
        line(x + 2 * e, y + 2 * e, x + 5 * e, y - 2 * e);
        line(x + 8 * e, y + 2 * e, x + 5 * e, y - 2 * e);

        setfillstyle(SOLID_FILL, COLOR(255, 165, 0)); // Color naranja
        floodfill(x + 5 * e, y - e, COLOR(255, 0, 0));

        // Propulsores del cohete
        setfillstyle(SOLID_FILL, COLOR(255, 0, 0)); // Color rojo
        floodfill(x + 4 * e, y + 5 * e, COLOR(255, 0, 0));
        floodfill(x + 6 * e, y + 5 * e, COLOR(255, 0, 0));

        // Ventanas del cohete
        setfillstyle(SOLID_FILL, COLOR(173, 216, 230)); // Color celeste
        floodfill(x + 4 * e, y + e, COLOR(255, 0, 0));
        floodfill(x + 6 * e, y + e, COLOR(255, 0, 0));

        // Alas del cohete
        setfillstyle(SOLID_FILL, COLOR(128, 128, 128)); // Color gris
        floodfill(x + e, y + 2.5 * e, COLOR(255, 0, 0));
        floodfill(x + 9 * e, y + 2.5 * e, COLOR(255, 0, 0));
    }

    void borrar()
    {
        setcolor(COLOR(255, 255, 255)); // Color blanco

        // Borra el cuerpo del cohete
        rectangle(x + 2 * e, y + 2 * e, x + 8 * e, y + 5 * e);
        rectangle(x + 3 * e, y + 1 * e, x + 7 * e, y + 2 * e);
        rectangle(x + 4 * e, y + 0.5 * e, x + 6 * e, y + 1 * e);

        // Borra la parte superior del cohete
        line(x + 2 * e, y + 2 * e, x + 5 * e, y - 2 * e);
        line(x + 8 * e, y + 2 * e, x + 5 * e, y - 2 * e);

        // Borra los propulsores del cohete
        rectangle(x + 4 * e, y + 5 * e, x + 6 * e, y + 6 * e);

        // Borra las ventanas del cohete
        rectangle(x + 4 * e, y + e, x + 6 * e, y + 2 * e);

        // Borra las alas del cohete
        rectangle(x + e, y + 2.5 * e, x + 9 * e, y + 3.5 * e);
    }

    int setX(int x) { this->x = x; }
    int setY(int y) { this->x = y; }
    int getX() { return this->x; }
    int getY() { return this->x; }
    int setXY(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};