// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 15/09/2026
// Archivo p01_multiple_grades.cc: programa cliente del segundo ejercicio.
// Carga múltiples calificaciones por estudiante, las muestra agrupadas y
// permite insertar elementos individualmente en memoria.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#include <iostream>
#include <string>

// MODIF: En el ejercicio de multiples grades, añadir una opción --count (la cual si no se añade el programa funciona como normalmente)
// que cuenta cuantas notas hay asociadas a ese alumno concreto.
// Ejemplo: ./p01_multiple_grades grades_multiple.txt --count alu0155555555
// si existe, el resultado deberia ser: alu0155555555 4
// Si no existe: No se ha encontrado alumno alu0155555555

#include "MultipleGradeManager.h"

namespace {

/**
 * @brief Muestra la ayuda del programa.
 */
void PrintHelp() {
  std::cout << "Modo de empleo: ./p01_multiple_grades grades.txt" << std::endl;
  // modif
  std::cout << "Opciones: --count <ALU>  Cuenta las calificaciones del ALU y finaliza." << std::endl;
  std::cout << "Lee líneas con formato <alu> <calificación>." << std::endl;
  std::cout << "Muestra todas las calificaciones agrupadas por estudiante."
            << std::endl;
  std::cout << "Ejemplo: alu0122334455 5.25" << std::endl;
}

// modif


/**
 * @brief Solicita una nueva calificación y la incorpora al gestor.
 * @param manager Gestor que mantiene las calificaciones en memoria.
 */
void AddInteractiveGrade(MultipleGradeManager& manager) {
  std::string alu;
  double grade;

  // Solicita al usuario el ALU y la calificación
  std::cout << "Introduzca ALU (o FIN para terminar): ";
  std::cin >> alu;

  // Si el usuario introduce "FIN", se termina la inserción de calificaciones
  if (alu == "FIN") {
    return;
  }

  // Solicita al usuario la calificación correspondiente al ALU introducido
  std::cout << "Introduzca calificación: ";
  std::cin >> grade;

  // Añade la calificación al gestor, conservando todas las calificaciones para el ALU dado
  manager.AddGrade(Student(alu), grade);
}

} // namespace para evitar conflictos de nombres con otras partes del programa

/**
 * @brief Punto de entrada del programa del segundo ejercicio.
 * @param argc Número de argumentos de línea de comandos.
 * @param argv Argumentos de línea de comandos.
 * @return 0 si la ejecución finaliza correctamente; 1 en caso de error.
 */
int main(int argc, char* argv[]) {
  // Comprueba si se solicita la ayuda del programa
  if (argc == 2 && std::string(argv[1]) == "--help") {
    PrintHelp();
    return 0;
  }

  // Comprueba que se ha proporcionado un fichero de entrada
  // modif
  if (!(argc == 2 || (argc == 4 && std::string(argv[2]) == "--count"))) {
    // Muestra un mensaje de uso correcto si no se proporciona el argumento esperado
    std::cout << "Modo de empleo: ./p01_multiple_grades grades.txt"
              << std::endl;
    std::cout << "Pruebe 'p01_multiple_grades --help' para más información."
              << std::endl;
    return 1;
  }

  // Crea un gestor de calificaciones que mantiene todas las calificaciones por estudiante
  MultipleGradeManager manager;

  // Intenta leer las calificaciones desde el fichero proporcionado
  if (!manager.ReadFile(argv[1])) {
    std::cerr << "Error: no se pudo abrir el fichero '"
              << argv[1] << "'." << std::endl;
    return 1;
  }

  // modif
  if (argc == 4 && std::string(argv[2]) == "--count") {
    const std::string alu_to_count = argv[3];
    int count = manager.CountGrades(alu_to_count);
    if (count >= 0) {
      std::cout << alu_to_count << ' ' << count << std::endl;
    } else {
      std::cout << "No se ha encontrado alumno " << alu_to_count << std::endl;
    }
    return 0;
  }

  // Muestra las calificaciones agrupadas por estudiante tras la lectura del fichero
  manager.Print();

  // Permite al usuario insertar calificaciones adicionales de manera interactiva
  std::cout << "¿Quieres insertar una calificación? (s/n): ";

  // Variable para almacenar la respuesta del usuario
  char answer;
  std::cin >> answer;

  // Mientras el usuario quiera insertar calificaciones, se solicita la información
  while (answer == 's' || answer == 'S') {
    // Llama a la función que solicita al usuario el ALU y la calificación
    AddInteractiveGrade(manager);
    // Muestra las calificaciones actualizadas después de cada inserción
    manager.Print();

    std::cout << "¿Quieres insertar otra calificación? (s/n): ";
    std::cin >> answer;
  }

  return 0;
}