// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 15/09/2026
// Archivo Student.cc: implementación de la clase Student.
// Contiene la lógica básica para representar y consultar el ALU de un estudiante.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#include "Student.h"

/**
 * @brief Construye un estudiante a partir de su identificador ALU.
 * @param alu Identificador único del estudiante.
 */
Student::Student(const std::string& alu) : alu_(alu) {}

/**
 * @brief Obtiene el identificador ALU del estudiante.
 * @return Identificador ALU.
 */
const std::string& Student::GetAlu() const {
  return alu_;
}