// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es 
// Fecha: 15/09/2026
// Archivo SingleGradeManager.h: definición de la clase SingleGradeManager.
// Gestiona una calificación máxima por estudiante usando un contenedor map ordenado por ALU.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#ifndef P01_CONTENEDORES_SINGLE_GRADE_MANAGER_H_
#define P01_CONTENEDORES_SINGLE_GRADE_MANAGER_H_

#include <map>
#include <string>

#include "Student.h"

/**
 * @brief Gestiona una única calificación por estudiante.
 *
 * Para cada estudiante se conserva únicamente la calificación máxima
 * encontrada.
 */
class SingleGradeManager {
 public:
  /**
   * @brief Lee las calificaciones de un fichero de texto.
   * @param file_name Nombre del fichero de entrada.
   * @return true si el fichero se pudo abrir y procesar; false en otro caso.
   */
  bool ReadFile(const std::string& file_name);

  /**
   * @brief Inserta una calificación conservando la máxima del estudiante.
   * @param student Estudiante al que pertenece la calificación.
   * @param grade Calificación a incorporar.
   */
  void AddGrade(const Student& student, double grade);

  /**
   * @brief Muestra todas las calificaciones ordenadas por ALU.
   */
  void Print() const;

 private:
  /**
   * @brief Asocia cada ALU con su calificación máxima.
   */
  std::map<std::string, double> grades_;
};

#endif