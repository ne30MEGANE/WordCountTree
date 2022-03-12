#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#include "data_type.h"

extern char Kadai_Sentence[];

// プロトタイプ宣言
struct tnode* addNode(struct tnode* root, char* word);
struct tnode* nodeSetting(char* word);
void cleanTree(struct tnode* root);
void printTree(struct tnode* root);
void printTree_debug(struct tnode* root, int deep);

int main()
{
    // for debug:メモリリーク検出
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //printf("%s\n", Kadai_Sentence); // for debug


    // 最初のノードを定義
    char* context = NULL; // for strtok_s
    char* token = strtok_s(Kadai_Sentence, " ", &context);
    struct tnode* tree = addNode(NULL, token);

    // 残りのノードを追加
    while (token != NULL) {
        token = strtok_s(NULL, " ", &context);
        if(token != NULL) addNode(tree, token);
    }

    // 出力
    printTree(tree);
    //printTree_debug(tree, 0);

    // メモリ解放
    cleanTree(tree);

}

// 二分木構成
struct tnode* addNode(struct tnode* root, char* word) { // 追加先二分木(根のアドレスで指定)・追加するワード
    // 最初のノード
    if(root == NULL){
        root = nodeSetting(word);
        return root;
    }

    // wordを比較してノードを追加
    while (1) {
        int cmp = strcmp(root->word, word);
        if (cmp == 0){ // 同じワード
            root->count++;
            break;
        }
        else if (cmp > 0) { // 左に追加
            if (root->left == NULL) { // 開いてるとき
                root->left = nodeSetting(word); // ノード追加・設定
                break;
            }
            else { // 開いてないとき
                root = root->left; // 次のノードに移る
            }
        }
        else if (cmp < 0) { // 右に追加
            if (root->right == NULL) {
                root->right = nodeSetting(word);
                break;
            }
            else {
                root = root->right;
            }
        }

    }

    return root;
}

// ノードメモリ確保・初期化
struct tnode* nodeSetting(char* word) {
    struct tnode* node = malloc(sizeof(struct tnode));
    if (node) {
        node->word = word;
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
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
void printTree(struct tnode* root) {
    if (root == NULL) return;
    printf("%4d %s\n", root->count, root->word);
    printTree(root->left);
    printTree(root->right);
}

// デバッグ用、深さ表示ｱﾘ出力
void printTree_debug(struct tnode* root, int deep) {
    if (root == NULL) return;

    printTree_debug(root->right, deep + 1);
    for (int i = 0; i < deep; i++) printf("--");
    printf("%d %s\n",root->count, root->word);

    printTree_debug(root->left, deep + 1);
    deep++;

}