#include <stdio.h>
#include <dos.h>

#define MACHINE_NEC   0
#define MACHINE_EPSON 1
#define MACHINE_OTHER 2

/* QuickC 2.0 用のプロトタイプ宣言 */
int check_pc98_vendor(void);

/*
 * BIOS メモリ領域から文字列を検索して NEC か EPSON か判定する
 */
int check_pc98_vendor(void)
{
    /* QuickC 2.0 では char far * 型を使用 */
    char far *epson_sig;
    int i;

    /* Segment 0xF800:0000 (ROM BIOS領域) を指す遠隔ポインタを作成 */
    epson_sig = (char far *)MK_FP(0xF800, 0x0000);

    /* 0xF800:0000 ? 0x1000 (4KB) の範囲で "EPSON" シグネチャを検索 */
    for (i = 0; i < 0x1000 - 5; i++) {
        if (epson_sig[i]     == 'E' &&
            epson_sig[i + 1] == 'P' &&
            epson_sig[i + 2] == 'S' &&
            epson_sig[i + 3] == 'O' &&
            epson_sig[i + 4] == 'N') {
            return MACHINE_EPSON;
        }
    }

    return MACHINE_NEC;
}

int main(void)
{
    int vendor;

    vendor = check_pc98_vendor();

    switch (vendor) {
    case MACHINE_NEC:
        printf("このコンピュータの種類は NEC PC-9800 シリーズです.\n");
        break;
    case MACHINE_EPSON:
        printf("このコンピュータの種類は EPSON PC シリーズです.\n");
        break;
    default:
        printf("このコンピュータの種類は不明です.\n");
        break;
    }

    return 0;
}