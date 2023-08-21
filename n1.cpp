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