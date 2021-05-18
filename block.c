#include "block.h"

struct transaction get_tx(int tx_id) {
	struct transaction tx ;
	memcpy(&tx.creator, "sundong", 7);
	return tx;

}

struct block_body get_block_body(int num_txs) {
	struct block_body b_b ;
	for (int i = 0; i < num_txs; i++) {
		struct transaction tx = get_tx(i);
		memcpy(&b_b.txs[i], &tx, sizeof(struct transaction));
	}
	return b_b;
}

struct block_header get_block_header(int block_id) {
	struct block_header b_h ;
	b_h.block_id = block_id;
	return b_h;
}

struct block get_block(int id, int tx_num) {
	struct block blk;
	struct block_body b_b =  get_block_body(tx_num);
	struct block_header b_h = get_block_header(id);
	blk.blk_body = b_b;
	blk.blk_header = b_h;
	return blk;

}


void get_blocks(int num, struct block blks[]) {
	//struct block blocks[10];

	for (int i = 0; i < num; i++) {
		blks[i] = get_block(i, 100);
	}
}

//int main(){
//
//	struct block blks[10];
//	get_blocks(10, blks);
//	int a = sizeof(blks);
//	printf("size:%d\n", sizeof(blks));
//	return 0;
//}