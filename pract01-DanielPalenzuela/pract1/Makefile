CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g

COMMON_OBJECTS = Student.o
SINGLE_OBJECTS = SingleGradeManager.o p01_single_grades.o
MULTIPLE_OBJECTS = MultipleGradeManager.o p01_multiple_grades.o

TARGETS = p01_single_grades p01_multiple_grades

.PHONY: all clean

all: $(TARGETS)

p01_single_grades: $(COMMON_OBJECTS) SingleGradeManager.o p01_single_grades.o
	$(CXX) $(CXXFLAGS) $^ -o $@

p01_multiple_grades: $(COMMON_OBJECTS) MultipleGradeManager.o p01_multiple_grades.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Student.o: Student.cc Student.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

SingleGradeManager.o: SingleGradeManager.cc SingleGradeManager.h Student.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

MultipleGradeManager.o: MultipleGradeManager.cc MultipleGradeManager.h Student.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

p01_single_grades.o: p01_single_grades.cc SingleGradeManager.h Student.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

p01_multiple_grades.o: p01_multiple_grades.cc MultipleGradeManager.h Student.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS) *.o