//Descrição de cada estrutura
/*
(1) id – 126
(2) idSolution – 1001
(3) solutionName – Solução base n. 001 (4) solutionInitials – SB-001
(5) idTeacher – 101
(6) teacherName – Alan Mathison Turing (7) idDay – 2
(8) idInstitution – 2
(9) idUnit – 900
(10) unitName – INF/UFG
(11) idUnitCourse – 1
(12) idCourse – 1
(13) courseName – BSI
(14) idClass – 3
(15) className – BSI-03
(16) idDiscipline – 1001
(17) disciplineName – AED-2
(18) idRoom – 305
(19) roomName – Sala 305
(20) studentsNumber – 55
(21) sequence – 3
(22) idBeginSlot – 75
(23) beginTimeName – 18:45:00
(24) idEndSlot – 88
(25) endTimeName – 22:00:00
(26) idYear – 2023
(27) idTerm – 1
(28) idCollisionType – 0 [É uma informação de saída, atualizada pela aplicação]
    (0) – nenhuma colição ocorreu;
    (1) – colisão de professor, ou seja, o professor de “id” igual a idTeacher está associado a uma
        outra aula cujo horário coincide, parcial ou totalmente, a horário da aula presente;
    (2) – colisão de sala de aula, ou seja, a sala de aula de “id” igual a idRoom está sendo utilizada por uma outra aula, neste mesmo intervalo de tempo ou em pelo menos parte dele;
    (3) – colisão de professor e de sala, ou seja, as colisões do tipo (1) e (2) estão ocorrendo simultanea- mente.
    
(29) collisionLevel – 0 [É uma informação de saída, atualizada pela aplicação] 
    (0) – nenhuma colisão ocorreu;
    (1) – colisão parcial, ou seja, existe uma outra aula cujo intervalo de tempo é coincidente, parcial-
        mente, com o horário da presente aula;
    (2) – colisão total, ou seja, existe uma outra aula cujo intervalo de tempo é totalmente coincidente com o horário da presente aula.

(30) collisionSize – 0 [É uma informação de saída, atualizada pela aplicação]
*/

typedef struct
{
  int id;
  int idSolution;
  char SolutionName[50];
  int idTeacher;
  char teacherName[50];
  int idInstitution;
  int idUnit;
  char unitName[10];
  int idUnitCourse;
  int idCourse;
  char courseName[10];
  int idClass;
  char className[10];
  int idDiscipline;
  char disciplineName[10];
  int idRoom;
  char roomName[10];
  int studentsNumber;
  int sequence;
  int idBeginSlot;
  char beginTimeName[8];
  int idEndSlot;
  char endTimeName[8];
  int idYear;
  int idTerm;
  int idCollisionType;
  int collisionLevel
  int collisionSize

} Dados_horario;
  
//As funçoes a serem implementadas


void add_no_tree;
void run_arvore;
void verify_colison;
void free_tree;
void read_csv;
void file_csv;
  
  
  
  
  
