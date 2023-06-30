#include "arvores.h"




Node* createNode(int id, int level) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->level = level;
    node->children = NULL;
    node->parent = NULL;
    node->numChildren = 0;
    node->data = NULL;
    return node;
}


void addChild(Node* parent, Node* child) {
    parent->numChildren++;
    parent->children = realloc(parent->children, parent->numChildren * sizeof(Node*));
    parent->children[parent->numChildren - 1] = child;
    child->parent = parent;
}

Node* findChild(Node* parent, int id) {
    if (parent == NULL) {
        return NULL;
    }

    for (int i = 0; i < parent->numChildren; i++) {
        if (parent->children[i] != NULL && parent->children[i]->id == id) {
            return parent->children[i];
        }
    }

    return NULL;
}

Node* leituraArquivoeGerarArvore(char* nomearquivo) {
    FILE* arquivo = fopen(nomearquivo, "r");
    DadosEntrada dados;
    Node* root = NULL;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo. Tente novamente.");
        return NULL;
    }

    while (fscanf(arquivo, "%d,%d,%[^,],%[^,],%d,%[^,],%d,%d,%d,%[^,],%d,%d,%[^,],%d,%[^,],%d,%[^,],%d,%[^,],%d,%d,%d,%[^,],%d,%[^,],%d,%d,%d,%d,%d",
           &dados.id, &dados.idSolution, dados.solutionName, dados.solutionInitials, &dados.idTeacher,
           dados.teacherName, &dados.idDay, &dados.idInstitution, &dados.idUnit, dados.unitName,
           &dados.idUnitCourse, &dados.idCourse, dados.courseName, &dados.idClass, dados.className,
           &dados.idDiscipline, dados.disciplineName, &dados.idRoom, dados.roomName, &dados.studentsNumber,
           &dados.sequence, &dados.idBeginSlot, dados.beginTimeName, &dados.idEndSlot, dados.endTimeName,
           &dados.idYear, &dados.idTerm, &dados.idCollisionType, &dados.collisionLevel, &dados.collisionSize) != EOF) {

        printf("%d,%d,%s,%s,%d,%s,%d,%d,%d,%s,%d,%d,%s,%d,%s,%d,%s,%d,%s,%d,%d,%d,%s,%d,%s,%d,%d,%d,%d,%d\n",
            dados.id, dados.idSolution, dados.solutionName, dados.solutionInitials, dados.idTeacher,
            dados.teacherName, dados.idDay, dados.idInstitution, dados.idUnit, dados.unitName,
            dados.idUnitCourse, dados.idCourse, dados.courseName, dados.idClass, dados.className,
            dados.idDiscipline, dados.disciplineName, dados.idRoom, dados.roomName, dados.studentsNumber,
            dados.sequence, dados.idBeginSlot, dados.beginTimeName, dados.idEndSlot, dados.endTimeName,
            dados.idYear, dados.idTerm, dados.idCollisionType, dados.collisionLevel, dados.collisionSize);

        if (root == NULL) {
            root = createNode(-1, 0); // Nível da raiz é 0
        }

        Node* institutionNode = findChild(root, dados.idInstitution);
        if (institutionNode == NULL) {
            institutionNode = createNode(dados.idInstitution, 1);
            addChild(root, institutionNode); // Nível da instituição é 1
        }

        Node* unitNode = findChild(institutionNode, dados.idUnit);
        if (unitNode == NULL) {
            unitNode = createNode(dados.idUnit, 2);
            addChild(institutionNode, unitNode); // Nível da unidade é 2
        }

        Node* courseNode = findChild(unitNode, dados.idCourse);
        if (courseNode == NULL) {
            courseNode = createNode(dados.idCourse, 3);
            addChild(unitNode, courseNode); // Nível do curso é 3
        }

        Node* classNode = findChild(courseNode, dados.idClass);
        if (classNode == NULL) {
            classNode = createNode(dados.idClass, 4);
            addChild(courseNode, classNode);// Nível da turma é 4
        }
   
        Node* disciplineNode = createNode(dados.idDiscipline, 5);
        addChild(classNode, disciplineNode); // Nível da disciplina é 5
        

        disciplineNode->data = (DadosDisciplina*)malloc(sizeof(DadosDisciplina));
        disciplineNode->data->idDay = dados.idDay;
        disciplineNode->data->idBeginSlot = dados.idBeginSlot; 
        disciplineNode->data->idEndSlot = dados.idEndSlot; 
        disciplineNode->data->idTeacher = dados.idTeacher; 
        disciplineNode->data->idRoom = dados.idRoom; 
        disciplineNode->data->idCollissionType = dados.idCollisionType;
        disciplineNode->data->collisionLevel = dados.collisionLevel;
        disciplineNode->data->collisionSize = dados.collisionSize;
        disciplineNode->data->id = dados.id;
    }

    fclose(arquivo);
    return root;
}
       
void printTree(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    if (node->level == 5) {
        printf("id Discipline: %d\n", node->id);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("Dados da disciplina:\n");
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id Day: %d\n", node->data->idDay);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id BeginTime: %d\n", node->data->idBeginSlot);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id EndTime: %d\n", node->data->idEndSlot);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id Teacher: %d\n", node->data->idTeacher);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id Room: %d\n", node->data->idRoom);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id CollisionType: %d\n", node->data->idCollissionType);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id CollisionLevel: %d\n", node->data->collisionLevel);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id CollisionSize: %d\n", node->data->collisionSize);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("id Line: %d\n", node->data->id);

    } else {
        printf("id: %d\n", node->id);
    }

    for (int i = 0; i < node->numChildren; i++) {
        printTree(node->children[i], level + 1);
    }
}


int measureColissionSize1(Node* node1){
    int valueColissionType;
    valueColissionType = (((node1->data->idEndSlot - node1->data->idBeginSlot)*30)+30);

    return valueColissionType;
}

int measureColissionSize2(Node* node1, Node* node2){
    int valueColissionType;
    valueColissionType = (((node1->data->idEndSlot - node2->data->idBeginSlot)*30)+30);

    return valueColissionType;
}


void checkColissions(Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->level == 5) {
        Node* levelFiveNode = root;
        Node* currentParent = levelFiveNode->parent;

        // Verifica colisões com outros nós de disciplina
        while (currentParent != NULL) {
            Node* classNode = currentParent;
            Node* courseNode = classNode->parent;
            Node* unitNode = (courseNode != NULL) ? courseNode->parent : NULL;
            Node* institutionNode = (unitNode != NULL) ? unitNode->parent : NULL;

            if (institutionNode != NULL) {
                for (int i = 0; i < institutionNode->numChildren; i++) {
                    Node* siblingInstitutionNode = institutionNode->children[i];
                    for (int j = 0; j < siblingInstitutionNode->numChildren; j++) {
                        Node* siblingUnitNode = siblingInstitutionNode->children[j];
                        for (int k = 0; k < siblingUnitNode->numChildren; k++) {
                            Node* siblingCourseNode = siblingUnitNode->children[k];
                            for (int l = 0; l < siblingCourseNode->numChildren; l++) {
                                Node* siblingClassNode = siblingCourseNode->children[l];
                                for (int m = 0; m < siblingClassNode->numChildren; m++) {
                                    Node* siblingNode = siblingClassNode->children[m];
                                    if (siblingNode->level == 5 && siblingNode != levelFiveNode) {
                                        if (siblingNode->data->idDay == levelFiveNode->data->idDay &&
                                        siblingNode->data->idBeginSlot == levelFiveNode->data->idBeginSlot &&
                                        siblingNode->data->idEndSlot == levelFiveNode->data->idEndSlot &&
                                        siblingNode->data->idTeacher == levelFiveNode->data->idTeacher &&
                                        siblingNode->data->idRoom != levelFiveNode->data->idRoom) {

                                        //Colisão Tipo 1 Total;
                                        levelFiveNode->data->idCollissionType = 1;
                                        levelFiveNode->data->collisionLevel = 2;
                                        levelFiveNode->data->collisionSize = measureColissionSize1(levelFiveNode);
                                        siblingNode->data->idCollissionType = 1;
                                        siblingNode->data->collisionLevel = 2;
                                        siblingNode->data->collisionSize = measureColissionSize1(siblingNode);

                                    }
                                    else if (siblingNode->data->idDay == levelFiveNode->data->idDay &&
                                            siblingNode->data->idBeginSlot == levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idEndSlot == levelFiveNode->data->idEndSlot &&
                                            siblingNode->data->idTeacher == levelFiveNode->data->idTeacher &&
                                            siblingNode->data->idRoom == levelFiveNode->data->idRoom) {

                                        //Colisao Tipo 3 Total
                                        levelFiveNode->data->idCollissionType = 3;
                                        levelFiveNode->data->collisionLevel = 2;
                                        levelFiveNode->data->collisionSize = measureColissionSize1(levelFiveNode);
                                        siblingNode->data->idCollissionType = 3;
                                        siblingNode->data->collisionLevel = 2;
                                        siblingNode->data->collisionSize = measureColissionSize1(siblingNode);
                                    }

                                    else if (siblingNode->data->idDay == levelFiveNode->data->idDay &&
                                            siblingNode->data->idBeginSlot == levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idEndSlot == levelFiveNode->data->idEndSlot &&
                                            siblingNode->data->idTeacher != levelFiveNode->data->idTeacher &&
                                            siblingNode->data->idRoom == levelFiveNode->data->idRoom) {

                                        //Colisao Tipo 2 Total
                                        levelFiveNode->data->idCollissionType = 2;
                                        levelFiveNode->data->collisionLevel = 2;
                                        levelFiveNode->data->collisionSize = measureColissionSize1(levelFiveNode);
                                        siblingNode->data->idCollissionType = 2;
                                        siblingNode->data->collisionLevel = 2;
                                        siblingNode->data->collisionSize = measureColissionSize1(siblingNode);
                                    }

                                    else if (siblingNode->data->idDay == levelFiveNode->data->idDay &&
                                            siblingNode->data->idBeginSlot < levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idEndSlot < levelFiveNode->data->idEndSlot && siblingNode->data->idEndSlot > levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idTeacher == levelFiveNode->data->idTeacher &&
                                            siblingNode->data->idRoom != levelFiveNode->data->idRoom) {

                                        //Colisao Tipo 1 Parcial
                                        levelFiveNode->data->idCollissionType = 1;
                                        levelFiveNode->data->collisionLevel = 1;
                                        levelFiveNode->data->collisionSize = measureColissionSize2(siblingNode, levelFiveNode);
                                        siblingNode->data->idCollissionType = 1;
                                        siblingNode->data->collisionLevel = 1;
                                        siblingNode->data->collisionSize = measureColissionSize2(siblingNode, levelFiveNode);
                                    }

                                    else if (siblingNode->data->idDay == levelFiveNode->data->idDay &&
                                            siblingNode->data->idBeginSlot < levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idEndSlot < levelFiveNode->data->idEndSlot && siblingNode->data->idEndSlot > levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idTeacher != levelFiveNode->data->idTeacher &&
                                            siblingNode->data->idRoom == levelFiveNode->data->idRoom) {

                                        //Colisao Tipo 2 Parcial
                                        levelFiveNode->data->idCollissionType = 2;
                                        levelFiveNode->data->collisionLevel = 1;
                                        levelFiveNode->data->collisionSize = measureColissionSize2(siblingNode, levelFiveNode);
                                        siblingNode->data->idCollissionType = 2;
                                        siblingNode->data->collisionLevel = 1;
                                        siblingNode->data->collisionSize = measureColissionSize2(siblingNode, levelFiveNode);
                                    }

                                    else if (siblingNode->data->idDay == levelFiveNode->data->idDay &&
                                            siblingNode->data->idBeginSlot < levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idEndSlot < levelFiveNode->data->idEndSlot && siblingNode->data->idEndSlot > levelFiveNode->data->idBeginSlot &&
                                            siblingNode->data->idTeacher == levelFiveNode->data->idTeacher &&
                                            siblingNode->data->idRoom == levelFiveNode->data->idRoom) {

                                        //Colisao Tipo 3 Parcial
                                        levelFiveNode->data->idCollissionType = 3;
                                        levelFiveNode->data->collisionLevel = 1;
                                        levelFiveNode->data->collisionSize = measureColissionSize2(siblingNode, levelFiveNode);
                                        siblingNode->data->idCollissionType = 3;
                                        siblingNode->data->collisionLevel = 1;
                                        siblingNode->data->collisionSize = measureColissionSize2(siblingNode, levelFiveNode);
                                    }


                                    }
                                }
                            }
                        }
                    }
                }
            }

             currentParent = currentParent->parent;
        }
    }

    // Percorre recursivamente os filhos
    for (int i = 0; i < root->numChildren; i++) {
        checkColissions(root->children[i]);
    }
}

infoSaida* runTree(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    infoSaida* head = NULL;
    infoSaida* tail = NULL;  // Ponteiro para o último elemento da lista

    if (node->level == 5 && node->data->idCollissionType != 0) {
        // Cria um novo nó para armazenar as informações importantes
        infoSaida* newInfo = malloc(sizeof(infoSaida));
        newInfo->idLine = node->data->id;
        newInfo->updateCollisionType = node->data->idCollissionType;
        newInfo->updateCollisionLevel = node->data->collisionLevel;
        newInfo->updateCollisionSize = node->data->collisionSize;
        newInfo->next = NULL;

        if (head == NULL) {
            // Se a lista estiver vazia, define o novo nó como a cabeça e a cauda da lista
            head = newInfo;
            tail = newInfo;
        } else {
            // Caso contrário, insere o novo nó no final da lista
            tail->next = newInfo;
            tail = newInfo;
        }
    }

    for (int i = 0; i < node->numChildren; i++) {
        // Chama recursivamente a função para cada filho do nó atual
        infoSaida* childInfo = runTree(node->children[i]);

        if (childInfo != NULL) {
            // Se o filho tiver informações para adicionar à lista, insere-as no final da lista atual
            if (head == NULL) {
                // Se a lista estiver vazia, define o nó do filho como a cabeça e a cauda da lista
                head = childInfo;
                tail = childInfo;
            } else {
                // Caso contrário, insere o nó do filho no final da lista
                tail->next = childInfo;

                // Atualiza a cauda para apontar para o último nó inserido
                while (tail->next != NULL) {
                    tail = tail->next;
                }
            }
        }
    }

    return head;
}

void createList(Node* node, int level, infoSaida** list) {
    if (node->level == 5 && node->data->idCollissionType != 0) {
        int id = node->data->id;
        infoSaida* temp = *list;
        while (temp != NULL) {
            if (temp->idLine == id) {
                // Nó com o mesmo ID já existe na lista, atualize os valores se necessário
                if (node->data->idCollissionType != 0) {
                    temp->updateCollisionType = node->data->idCollissionType;
                }
                if (node->data->collisionLevel > temp->updateCollisionLevel) {
                    temp->updateCollisionLevel = node->data->collisionLevel;
                }
                if (node->data->collisionSize > temp->updateCollisionSize) {
                    temp->updateCollisionSize = node->data->collisionSize;
                }
                return;  // Saia da função, pois o nó já existe na lista
            }
            temp = temp->next;
        }
        
        // Nó com ID único, adicione à lista
        infoSaida* novo = (infoSaida*)malloc(sizeof(infoSaida));
        novo->idLine = node->data->id;
        novo->updateCollisionType = node->data->idCollissionType;
        novo->updateCollisionLevel = node->data->collisionLevel;
        novo->updateCollisionSize = node->data->collisionSize;
        novo->next = NULL;

        if (*list == NULL) {
            *list = novo;
        } else {
            temp = *list;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = novo;
        }
    }

    for (int i = 0; i < node->numChildren; i++) {
        createList(node->children[i], level + 1, list);
    }
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    for (int i = 0; i < root->numChildren; i++) {
        freeTree(root->children[i]);
    }
    
    free(root->children);
    free(root->data);
    free(root);
}


void freeList(infoSaida* head) {
    infoSaida* current = head;
    while (current != NULL) {
        infoSaida* next = current->next;
        free(current);
        current = next;
    }
}


void printInfoList(infoSaida* list) {
    infoSaida* current = list;
    while (current != NULL) {
        printf("ID: %d\n", current->idLine);
        printf("Update Collision Type: %d\n", current->updateCollisionType);
        printf("Update Collision Level: %d\n", current->updateCollisionLevel);
        printf("Update Collision Size: %d\n", current->updateCollisionSize);
        printf("--------------------------\n");

        current = current->next;
    }
}

void gerarArquivoSaida(char* nomeArquivoEntrada, char* nomeArquivoSaida, infoSaida* newInfo){

    FILE* arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    FILE* arquivoSaida = fopen(nomeArquivoSaida, "w");
    DadosEntrada dados;
    infoSaida* currentInfoSaida = newInfo;

    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo. Tente novamente.");
        return;
    }

    while (fscanf(arquivoEntrada, "%d,%d,%[^,],%[^,],%d,%[^,],%d,%d,%d,%[^,],%d,%d,%[^,],%d,%[^,],%d,%[^,],%d,%[^,],%d,%d,%d,%[^,],%d,%[^,],%d,%d,%d,%d,%d",
           &dados.id, &dados.idSolution, dados.solutionName, dados.solutionInitials, &dados.idTeacher,
           dados.teacherName, &dados.idDay, &dados.idInstitution, &dados.idUnit, dados.unitName,
           &dados.idUnitCourse, &dados.idCourse, dados.courseName, &dados.idClass, dados.className,
           &dados.idDiscipline, dados.disciplineName, &dados.idRoom, dados.roomName, &dados.studentsNumber,
           &dados.sequence, &dados.idBeginSlot, dados.beginTimeName, &dados.idEndSlot, dados.endTimeName,
           &dados.idYear, &dados.idTerm, &dados.idCollisionType, &dados.collisionLevel, &dados.collisionSize) != EOF) {
    
    
            if(dados.id == currentInfoSaida->idLine){
            fprintf(arquivoSaida, "%d,%d,%s,%s,%d,%s,%d,%d,%d,%s,%d,%d,%s,%d,%s,%d,%s,%d,%s,%d,%d,%d,%s,%d,%s,%d,%d,%d,%d,%d\n",
            dados.id, dados.idSolution, dados.solutionName, dados.solutionInitials, dados.idTeacher,
           dados.teacherName, dados.idDay, dados.idInstitution, dados.idUnit, dados.unitName,
           dados.idUnitCourse, dados.idCourse, dados.courseName, dados.idClass, dados.className,
           dados.idDiscipline, dados.disciplineName, dados.idRoom, dados.roomName, dados.studentsNumber,
           dados.sequence, dados.idBeginSlot, dados.beginTimeName, dados.idEndSlot, dados.endTimeName,
           dados.idYear, dados.idTerm, currentInfoSaida->updateCollisionType, currentInfoSaida->updateCollisionLevel, currentInfoSaida->updateCollisionSize);

            currentInfoSaida = currentInfoSaida->next;

        }

 

    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
}

infoSaida* getTail(infoSaida* head) {
    if (head == NULL || head->next == NULL)
        return head;

    infoSaida* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    return tail;
}

infoSaida* partition(infoSaida* head, infoSaida* end, infoSaida** newHead, infoSaida** newEnd) {
    infoSaida* pivot = end;
    infoSaida* prev = NULL;
    infoSaida* current = head;
    infoSaida* tail = pivot;

    while (current != pivot) {
        if (current->idLine < pivot->idLine) {
            if (*newHead == NULL)
                *newHead = current;

            prev = current;
            current = current->next;
        } else {
            if (prev)
                prev->next = current->next;

            infoSaida* tmp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

infoSaida* quickSortRecur(infoSaida* head, infoSaida* end) {
    if (head == NULL || head == end)
        return head;

    infoSaida* newHead = NULL;
    infoSaida* newEnd = NULL;

    infoSaida* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        infoSaida* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(infoSaida** head) {
    *head = quickSortRecur(*head, getTail(*head));
}
