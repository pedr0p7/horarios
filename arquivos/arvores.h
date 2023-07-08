#ifndef ARVORES_H
#define ARVORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_NAME_LENGTH         100
#define TIME_NAME_LENGTH        11
#define INITIAL_SOLUTION_LENGTH 10

typedef struct  {
    
    int id;
    int idSolution;
    char solutionName[MAX_NAME_LENGTH];
    char solutionInitials[INITIAL_SOLUTION_LENGTH];
    int idTeacher;
    char teacherName[MAX_NAME_LENGTH];
    int idDay;
    int idInstitution;
    int idUnit;
    char unitName[MAX_NAME_LENGTH];
    int idUnitCourse;
    int idCourse;
    char courseName[MAX_NAME_LENGTH];
    int idClass;
    char className[MAX_NAME_LENGTH];
    int idDiscipline;
    char disciplineName[MAX_NAME_LENGTH];
    int idRoom;
    char roomName[MAX_NAME_LENGTH];
    int studentsNumber;
    int sequence;
    int idBeginSlot;
    char beginTimeName[TIME_NAME_LENGTH];
    int idEndSlot;
    char endTimeName[TIME_NAME_LENGTH];
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

void quickSort(infoSaida** head);

#endif
