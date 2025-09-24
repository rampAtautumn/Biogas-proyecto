#include <cmath>
#include <iomanip>
#include <iostream>
//Estas de aca arriba se llaman librerías, contienen todas las funciones del codigo que no son exclusivas al codigo

//En esta parte declaramos constantes GLOBALES relacionadas a los biogases
const double PCI_CH4 = 35.8;
const double Rendimiento_promedio = 0.5;
const double Eta = 0.35;

//Colocamos una declaración de la función para que el programa la pueda leer más adelante
void formulas(double a, double b);

//función main del programa
int main(void)
{
    // procederemos a declarar unas cuantas variables de entrada LOCALES.
    double f_CH4 = 0;
    double VS = 0;

    //pedimos el input aunque se podria mejorar...
    std::cout << "Bienvenido a la calculadora de biogas." << std :: endl;
    std::cout << "inserte la fraccion volumetrica de metano en el biogas" << std:: endl;
    std::cin >> f_CH4;
    std::cout << "inserte los solidos volatiles anadidos al biodigestor por dia" << std::endl;
    std::cin >> VS;
    
    //El condicional funciona, aunque puede mejorar.
    if(f_CH4 <= 0 || f_CH4 > 1 && VS <= 0)
    {
        std::cout << "Proceso invalido, terminando programa";
        //terminamos el programa con error 1
        return 1;
    }

    //Llamamos a la función de formulas
    formulas(f_CH4,VS);
    //Ejecución exitosa
    return 0;
}

void formulas(double a, double b)
{
    //Declaramos nuevas variables LOCALES para esta función, las cuales almacenaran los datos de las formulas
    double PCI = a * PCI_CH4;
    double Vbiogas = b * Rendimiento_promedio;
    double BioEnergy = Vbiogas * PCI;
    double ElectricEnergy = (BioEnergy * Eta)/3.6;

    std::cout << "El poder calorifico del biogas es de: " << PCI << "MJ/m3" << std::endl;
    std::cout << "La energia diaria total es de:" << ElectricEnergy << "kWh" << std::endl;

    return;

}
//La función sirve, pero quizas se pueda modificar a futuro...