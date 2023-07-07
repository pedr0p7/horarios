#ifndef ARVORES_H
#define ARVORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>


typedef struct  {
    
    int id;
    int idSolution;
    char solutionName[50];
    char solutionInitials[10];
    int idTeacher;
    char teacherName[50];
    int idDay;
    int idInstitution;
    int idUnit;
    char unitName[50];
    int idUnitCourse;
    int idCourse;
    char courseName[50];
    int idClass;
    char className[50];
    int idDiscipline;
    char disciplineName[50];
    int idRoom;
    char roomName[50];
    int studentsNumber;
    int sequence;
    int idBeginSlot;
    char beginTimeName[11];
    int idEndSlot;
    char endTimeName[11];
    int idYear;
    int idTerm;
    int idCollisionType;
    int collisionLevel;
    int collisionSize;

} DadosEntrada;

typedef struct  {
    int idDay;
    int idBeginSlot;
    int idEndSlot;
    int idTeacher;
    int idRoom;
    int idCollissionType;
    int collisionLevel;
    int collisionSize;
    int id;
} DadosDisciplina;

typedef struct Node {
    int id;
    int level;
    struct Node** children;
    struct Node* parent;
    int numChildren;
    DadosDisciplina* data;
} Node;  

typedef struct infoSaida {
    int idLine;
    int updateCollisionType;
    int updateCollisionLevel;
    int updateCollisionSize;
    struct infoSaida* next;
} infoSaida;


Node* createNode(int id, int level);
void addChild(Node* parent, Node* child);
Node* findChild(Node* parent, int id);
Node* leituraArquivoeGerarArvore(char* nomearquivo);
void printTree(Node* node, int level);
int measureColissionSize1(Node* node1);
int measureColissionSize2(Node* node1, Node* node2);
void checkColissions(Node* root);
infoSaida* runTree(Node* node);
void createList(Node* node, int level, infoSaida** list);
void freeTree(Node* root);
void freeList(infoSaida* head);
void printInfoList(infoSaida* list);
void gerarArquivoSaida(char* nomeArquivoEntrada, char* nomeArquivoSaida, infoSaida* newInfo);
infoSaida* getTail(infoSaida* head);
infoSaida* partition(infoSaida* head, infoSaida* end, infoSaida** newHead, infoSaida** newEnd);
infoSaida* quickSortRecur(infoSaida* head, infoSaida* end);
void quickSort(infoSaida** head);

#endif
