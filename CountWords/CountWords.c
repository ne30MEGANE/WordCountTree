#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "data_type.h"

extern char Kadai_Sentence[];

// プロトタイプ宣言
struct tnode* addNode(struct tnode* root, char* word);
void cleanTree(struct tnode* root);
void printTree(struct tnode* root);

int main()
{
    // for debug:メモリリーク検出
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //printf("%s\n", Kadai_Sentence); // for debug

    struct tnode* r2 = malloc(sizeof(struct tnode));
    struct tnode* l2 = malloc(sizeof(struct tnode));
    struct tnode* l1 = malloc(sizeof(struct tnode));
    struct tnode* top = malloc(sizeof(struct tnode));

    if (r2 && l2 && l1 && top) {
        r2->word = "BB"; r2->count = 1; r2->left = NULL; r2->right = NULL;
        l2->word = "A"; l2->count = 0; l2->left = NULL; l2->right = NULL;
        l1->word = "B"; l1->count = 1, l1->left = l2; l1->right = r2;
        top->word = "C"; top->count = 5; top->left = l1; top->right = NULL;

        printf("%s \t%p\n", top->word, top);
        printf("%s \t%p\n", l1->word, l1);
        printf("%s \t%p\n", l2->word, l2);
        printf("%s \t%p\n", r2->word, r2);
    }

    cleanTree(top);

}

// 二分木構成
struct tnode* addNode(struct tnode *root, char *word) {
    struct tnode* node = malloc(sizeof(struct tnode));

}

// メモリ解放
void cleanTree(struct tnode* root) {
    if (root == NULL) return;
    
    cleanTree(root->left); // 左ノード
    cleanTree(root->right); // 右ノード

    //printf("clear: %s\n", root->word); // for debug
    free(root);
}

// 二分木の内容を出力
void printTree(struct tnode *root) {

}