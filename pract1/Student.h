// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 15/09/2026
// Archivo Student.h: definición de la clase Student.
// Representa la información básica de un estudiante mediante su ALU.
// Referencias: guion de la Práctica 1 de CyA 2026-2027.
// Historial de revisiones
// 15/09/2026 - Creación del código.

#ifndef P01_CONTENEDORES_STUDENT_H_
#define P01_CONTENEDORES_STUDENT_H_

#include <string>

/**
 * @brief Representa un estudiante identificado mediante su ALU.
 */
class Student {
 public:
  /**
   * @brief Construye un estudiante a partir de su identificador ALU.
   * @param alu Identificador único del estudiante.
   */
  explicit Student(const std::string& alu);

  /**
   * @brief Obtiene el identificador ALU del estudiante.
   * @return Identificador ALU.
   */
  const std::string& GetAlu() const;

 private:
  /**
   * @brief Identificador ALU del estudiante.
   */
  std::string alu_;
};

#endif