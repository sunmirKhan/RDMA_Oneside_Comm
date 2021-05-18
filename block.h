#include <stdio.h>
//#include <openssl/sha256.h>
#include <stdlib.h>
#include <string.h>


struct block_header
{
	long   version;
	char      pre_hash[256];
	char      merkle_root[256];
	char      producer[20];
	long   block_id;

};

struct transaction
{
	char      creator[20];
	char      tx_hash[256];

};


struct block_body
{
	struct transaction  txs[100];
};

struct block
{
	struct block_header  blk_header;
	struct block_body    blk_body;
};


struct transaction get_tx(int tx_id);

struct block_body get_block_body(int num_txs);

struct block_header get_block_header(int block_id);

struct block get_block(int id, int tx_num);

void get_blocks(int num, struct block blks[]);