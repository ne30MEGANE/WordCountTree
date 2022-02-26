#pragma once

/*  データはこの構造体を使ってください。  */
struct tnode {
	char* word;  /*  単語へのポインタ  */
	int count;  /*  出現回数  */
	struct tnode* left;  /*  左の子供  */
	struct tnode* right;  /*  右の子供  */

	/*  2021 年度、あまり使わなそうなのでコメントアウト  */
//	struct tnode* parent;  /*  メモリ開放するには親が分かったほうがいいかも、実装によっては使わない  */
};


