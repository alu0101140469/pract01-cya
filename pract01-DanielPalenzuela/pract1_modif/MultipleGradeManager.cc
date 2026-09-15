// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 15/09/2026
// Archivo MultipleGradeManager.cc: implementación de la clase MultipleGradeManager.
// Lee, almacena y muestra múltiples calificaciones por ALU conservando su orden de entrada.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#include "MultipleGradeManager.h"

#include <fstream>
#include <iostream>

/**
 * @brief Lee las calificaciones de un fichero de texto.
 * @param file_name Nombre del fichero de entrada.
 * @return true si el fichero se pudo abrir y procesar; false en otro caso.
 */
bool MultipleGradeManager::ReadFile(const std::string& file_name) {
  std::ifstream input_file(file_name);

  // Comprueba si el fichero se abrió correctamente
  if (!input_file.is_open()) {
    return false;
  }

  std::string alu;
  double grade;

  // Lee cada línea del fichero y añade la calificación al gestor
  while (input_file >> alu >> grade) {
    AddGrade(Student(alu), grade);
  }

  return true;
}

/**
 * @brief Añade una calificación a un estudiante.
 * @param student Estudiante al que pertenece la calificación.
 * @param grade Calificación a incorporar.
 */
void MultipleGradeManager::AddGrade(const Student& student, double grade) {
  grades_[student.GetAlu()].push_back(grade); 
  // Añade la calificación al vector asociado al ALU del estudiante 
  // mediante el operador [] del map, que crea un vector vacío si el ALU no existía previamente.
}

/**
 * @brief Muestra todas las calificaciones agrupadas y ordenadas por ALU.
 */
void MultipleGradeManager::Print() const {
  // Recorre el map de calificaciones y muestra cada ALU seguido de sus calificaciones
  for (const auto& entry : grades_) {
    std::cout << entry.first << ':';

    // Recorre el vector de calificaciones asociado al ALU y las muestra en orden de entrada
    for (double grade : entry.second) {
      std::cout << ' ' << grade;
    }

    std::cout << std::endl;
  }
}

// modif
int MultipleGradeManager::CountGrades(const std::string& alu) const {
  auto it = grades_.find(alu);
  if (it == grades_.end()) {
    return -1;
  }
  return static_cast<int>(it->second.size());
}