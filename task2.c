// http://informatics.mccme.ru/mod/statements/view.php?id=206 сделать через линейный список.
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

struct Node {
  char value[52];
  struct Node * next;
};

struct List {
  struct Node * first;
  struct Node * last;
  int clas;
};

struct Node CreateNode(char value[52]) {
  struct Node a; int i = 0;
  for (char * c = value; *c != '\0'; c++) {
    a.value[i++] = *c;
  }
  a.value[i] = '\0';
  a.next = NULL;
  return a;
}

struct List CreateList(int clas) {
  struct List a;
  a.first = a.last = NULL;
  a.clas = clas;
  return a;
}

void addToList(struct List * list, char value[52]) {
  if ((*list).first == NULL) {
    (*list).last = (*list).first = (struct Node*)malloc(sizeof(struct Node));
    *((*list).last) = CreateNode(value);
  }
  else {
    (*list).last->next = (struct Node*)malloc(sizeof(struct Node));
    *((*list).last->next) = CreateNode(value);
    (*list).last = (*list).last->next;
  }
}

void ListToFile(struct List list, FILE * file) {
  struct Node * it = list.first;
  while (it != NULL) {
    fprintf(file, "%d %s\n", list.clas, it->value);
    it = it->next;
  }
}

void delList(struct List list) {
  struct Node * it = list.first;
  struct Node * next;
  while (it != NULL) {
    next = it->next;
    free(it);
    it = next;
  }
}

int main() {
  setlocale(LC_ALL, "Rus");
  FILE * fin = fopen("input.txt", "r");
  FILE * fout = fopen("output.txt", "w");
  int a; char c[52];
  struct List list9 = CreateList(9);
  struct List list10 = CreateList(10);
  struct List list11 = CreateList(11);

  while (fscanf(fin, "%d%s", &a, c) != EOF) {
    if (a == 9) {
      addToList(&list9, c);
    }
    else if (a == 10) {
      addToList(&list10, c);
    }
    else /*if (a == 11)*/ {
      addToList(&list11, c);
    }
  }

  ListToFile(list9, fout);
  ListToFile(list10, fout);
  ListToFile(list11, fout);

  delList(list9);
  delList(list10);
  delList(list11);
  fclose(fin);
  fclose(fout);
  return 0;
}