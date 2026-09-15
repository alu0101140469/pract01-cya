// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 15/09/2026
// Archivo SingleGradeManager.cc: implementación de la clase SingleGradeManager.
// Lee, almacena, actualiza y muestra una única calificación máxima por ALU.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#include "SingleGradeManager.h"

#include <fstream>
#include <iostream>

/**
 * @brief Lee las calificaciones de un fichero de texto.
 * @param file_name Nombre del fichero de entrada.
 * @return true si el fichero se pudo abrir y procesar; false en otro caso.
 */
bool SingleGradeManager::ReadFile(const std::string& file_name) {
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
 * @brief Inserta una calificación conservando la máxima del estudiante.
 * @param student Estudiante al que pertenece la calificación.
 * @param grade Calificación a incorporar.
 */
void SingleGradeManager::AddGrade(const Student& student, double grade) {
  // Obtiene el ALU del estudiante
  const std::string& alu = student.GetAlu();

  // Busca la calificación actual del estudiante
  auto iterator = grades_.find(alu);

  // Si no existe o la nueva calificación es mayor, actualiza el valor
  if (iterator == grades_.end() || grade > iterator->second) {
    grades_[alu] = grade;
  }
}

/**
 * @brief Muestra todas las calificaciones ordenadas por ALU.
 */
void SingleGradeManager::Print() const {
  for (const auto& entry : grades_) {
    // Muestra el ALU y la calificación máxima asociada
    std::cout << entry.first << ' ' << entry.second << std::endl;
  }
}