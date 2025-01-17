typedef struct circulo Circulo;

Circulo* Circulo_Cria(float raio);

float Circulo_Area(Circulo* c);

float Circulo_Perimetro(Circulo* c);

void Circulo_Libera(Circulo* c);
