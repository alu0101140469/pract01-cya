// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 15/09/2026
// Archivo MultipleGradeManager.h: definición de la clase MultipleGradeManager.
// Gestiona múltiples calificaciones por estudiante usando un map ordenado por ALU.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#ifndef P01_CONTENEDORES_MULTIPLE_GRADE_MANAGER_H_
#define P01_CONTENEDORES_MULTIPLE_GRADE_MANAGER_H_

#include <map>
#include <string>
#include <vector>

#include "Student.h"

/**
 * @brief Gestiona una o más calificaciones asociadas a cada estudiante.
 *
 * Las calificaciones se conservan en el mismo orden en el que se incorporan.
 */
class MultipleGradeManager {
 public:
  /**
   * @brief Lee las calificaciones de un fichero de texto.
   * @param file_name Nombre del fichero de entrada.
   * @return true si el fichero se pudo abrir y procesar; false en otro caso.
   */
  bool ReadFile(const std::string& file_name);

  /**
   * @brief Añade una calificación a un estudiante.
   * @param student Estudiante al que pertenece la calificación.
   * @param grade Calificación a incorporar.
   */
  void AddGrade(const Student& student, double grade);

  /**
   * @brief Muestra todas las calificaciones agrupadas y ordenadas por ALU.
   */
  void Print() const;

  // modif
  int CountGrades(const std::string& alu) const;

 private:
  /**
   * @brief Asocia cada ALU con sus calificaciones, en orden de entrada.
   */
  std::map<std::string, std::vector<double>> grades_;
};

#endif