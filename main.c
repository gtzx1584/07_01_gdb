// 花札(こいこい)

#include <stdio.h>
#include <stdlib.h> //乱数のためのライブラリ
#include <time.h>   //時間に関するライブラリ(乱数生成用)
#include <string.h> //文字列に関するライブラリ

#define TRUE 1
#define NAME_LEN 100
// 札の状態を表す定数の定義
#define FIELD 0
#define MY_CARD 1
#define MY_FIELD 2
#define ENEMY_CARD 3
#define ENEMY_FIELD 4
#define DECK 5
// 札の属性を表す定数の定義
#define KASU 0
#define TAN 1
#define TANE 2
#define HIKARI 3
#define SAKAZUKI 4
#define MAKU 5
#define TSUKI 6
#define AME 7
#define INOSHIKATYO 8
#define AKATAN 9
#define AOTAN 10

typedef struct card
{               // 札を表す構造体
    int id;     // 札の番号
    char *name; // 札の名前
    int month;  // 札の月
    int stat;   // 札の状態
    int type;   // 札の属性
} Card;

void def_card(Card all_cards[12][4])
{ // 札の設定を行う関数
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            all_cards[i][j].id = 4 * i + j + 1;
            all_cards[i][j].month = i + 1;
            all_cards[i][j].stat = DECK; // 始めは全ての札を山札に

            switch (all_cards[i][j].month)
            {       // 札の名前の設定
            case 1: // 1月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "松に鶴";
                    all_cards[i][j].type = HIKARI;
                    break;
                case 1:
                    all_cards[i][j].name = "松に赤短";
                    all_cards[i][j].type = AKATAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "松のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 2: // 2月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "梅にうぐいす";
                    all_cards[i][j].type = TANE;
                    break;
                case 1:
                    all_cards[i][j].name = "梅に赤短";
                    all_cards[i][j].type = AKATAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "梅のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 3: // 3月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "桜に幕";
                    all_cards[i][j].type = MAKU;
                    break;
                case 1:
                    all_cards[i][j].name = "桜に赤短";
                    all_cards[i][j].type = AKATAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "桜のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 4: // 4月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "藤にほととぎす";
                    all_cards[i][j].type = TANE;
                    break;
                case 1:
                    all_cards[i][j].name = "藤に短冊";
                    all_cards[i][j].type = TAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "藤のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 5: // 5月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "菖蒲に八ツ橋";
                    all_cards[i][j].type = TANE;
                    break;
                case 1:
                    all_cards[i][j].name = "菖蒲に短冊";
                    all_cards[i][j].type = TAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "菖蒲のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 6: // 6月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "牡丹に蝶";
                    all_cards[i][j].type = INOSHIKATYO;
                    break;
                case 1:
                    all_cards[i][j].name = "牡丹に青短";
                    all_cards[i][j].type = AOTAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "牡丹のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 7: // 7月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "萩に猪";
                    all_cards[i][j].type = INOSHIKATYO;
                    break;
                case 1:
                    all_cards[i][j].name = "萩に短冊";
                    all_cards[i][j].type = TAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "萩のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 8: // 8月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "ススキに月";
                    all_cards[i][j].type = TSUKI;
                    break;
                case 1:
                    all_cards[i][j].name = "ススキに雁";
                    all_cards[i][j].type = TANE;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "ススキのカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 9: // 9月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "菊に盃";
                    all_cards[i][j].type = SAKAZUKI;
                    break;
                case 1:
                    all_cards[i][j].name = "菊に青短";
                    all_cards[i][j].type = AOTAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "菊のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 10: // 10月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "紅葉に鹿";
                    all_cards[i][j].type = INOSHIKATYO;
                    break;
                case 1:
                    all_cards[i][j].name = "紅葉に青短";
                    all_cards[i][j].type = AOTAN;
                    break;
                case 2:
                case 3:
                    all_cards[i][j].name = "紅葉のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 11: // 11月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "小野道風にカエル";
                    all_cards[i][j].type = AME;
                    break;
                case 1:
                    all_cards[i][j].name = "柳にツバメ";
                    all_cards[i][j].type = TANE;
                    break;
                case 2:
                    all_cards[i][j].name = "柳に短冊";
                    all_cards[i][j].type = TAN;
                    break;
                case 3:
                    all_cards[i][j].name = "柳のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            case 12: // 12月
                switch (j)
                {
                case 0:
                    all_cards[i][j].name = "桐に鳳凰";
                    all_cards[i][j].type = HIKARI;
                    break;
                case 1:
                case 2:
                case 3:
                    all_cards[i][j].name = "桐のカス";
                    all_cards[i][j].type = KASU;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
}

void set_card(Card all_cards[12][4])
{ // 札を初期配置を行う関数
    int b = 1;
    while (b)
    { // 不正な状態である間
        int month_num[12] = {0};
        for (int i = 0; i < 24; i++)
        {
            srand((unsigned int)time(NULL));

            int m = 1;
            while (m)
            { // 乱数と合致する札が見つかるまで
                int n = rand();
                for (int j = 0; j < 12; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (all_cards[j][k].id == 1 + (n % 48) && all_cards[j][k].stat == DECK)
                        { // 山札の中から乱数と合致する札が見つかったら
                            switch (i % 6)
                            {
                            case 0:
                            case 1:
                                all_cards[j][k].stat = ENEMY_CARD;
                                m = 0;
                                break; // 相手の手札
                            case 2:
                            case 3:
                                all_cards[j][k].stat = FIELD;
                                m = 0;
                                month_num[all_cards[j][k].month - 1]++;
                                break; // 場札(月ごとに枚数を記録)
                            case 4:
                            case 5:
                                all_cards[j][k].stat = MY_CARD;
                                m = 0;
                                break; // 自分の手札
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }

        int max = 0;
        for (int i = 0; i < 12; i++)
        {
            if (max < month_num[i])
                max = month_num[i];
        }
        if (max < 4)
            b = 0; // 場に同じ月の札が4枚あったらやり直し
    }
}

int select_card(Card all_cards[12][4], int my_or_enemy, int turn_num, FILE *fp)
{ // 手札から使う札を決定する関数
    if (my_or_enemy == MY_CARD)
    { // 自分の手番のとき
        while (TRUE)
        { // 不正な札の名前が入力される間
            printf("どの札を使いますか？:");
            char card_name[NAME_LEN] = {0};
            scanf("%s", card_name); // 札の名前を読み込み
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (strcmp(card_name, all_cards[i][j].name) == 0 && all_cards[i][j].stat == MY_CARD)
                    { // 入力された文字列と名前が一致する札が手札にあったら
                        printf("%s を使います。", all_cards[i][j].name);
                        fprintf(fp, "%s を使いました。", all_cards[i][j].name);
                        return all_cards[i][j].id; // その札の番号を返却
                    }
                }
            }

            puts("\n手札に含まれる札の名前を入力してください。");
        }
    }
    else
    {                           // 相手の手番のとき
        int trnc[9 - turn_num]; // 1~(9-turn_num(=手札の枚数))の整数をランダムな順で1つずつ格納する配列
        for (int i = 0; i < 9 - turn_num; i++)
        {
            while (TRUE)
            {
                int n = 1 + rand() % (9 - turn_num);
                int b = 1;
                for (int j = 0; j < i; j++)
                {
                    if (trnc[j] == n)
                    {
                        b = 0;
                        break;
                    } // 既に格納されている整数ならやり直し
                }
                if (b)
                {
                    trnc[i] = n;
                    break;
                }
            }
}

        for (int i = 0; i < 9 - turn_num; i++)
        { // 手札をランダムな順で走査
            int n = 0;
            for (int j = 0; j < 12; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (all_cards[j][k].stat == ENEMY_CARD)
                    {
                        n++;
                        if (trnc[i] == n)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                for (int m = 0; m < 4; m++)
                                {
                                    if (all_cards[j][k].month == all_cards[l][m].month && all_cards[l][m].stat == FIELD)
                                    { // 手札からランダムに選ばれた札と月が一致する札が場にあったら
                                        printf("%s を使います。", all_cards[j][k].name);
                                        fprintf(fp, "%s を使いました。", all_cards[j][k].name);
                                        return all_cards[j][k].id; // その札の番号を返却
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // 取ることができる札が場になかったら
        int n = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].stat == ENEMY_CARD)
                {
                    n++;
                    if (trnc[0] == n)
                    {
                        printf("%s を使います。", all_cards[i][j].name);
                        fprintf(fp, "%s を使いました。", all_cards[i][j].name);
                        return all_cards[i][j].id; // 手札のうちランダムに1枚選び、その番号を返却
                    }
                }
            }
        }
    }
}

int id_to_first_index(int card_id) { return (card_id - 1) / 4; } // 札の番号から配列の1つ目のインデックスを計算する関数

int id_to_second_index(int card_id) { return (card_id + 3) % 4; } // 札の番号から配列の2つ目のインデックスを計算する関数

void take(Card all_cards[12][4], int my_or_enemy, int card_id, FILE *fp)
{                                                    // 場から札を取る関数
    int card_month = 1 + id_to_first_index(card_id); // 与えられた札の月
    int n = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (card_month == all_cards[i][j].month && all_cards[i][j].stat == FIELD)
                n++; // 与えられた札と月が一致する場札の枚数をnに格納
        }
    }

    int frag = 0;       // ループを抜け出す条件に利用する変数
    int indxs[6] = {0}; // 取る札のインデックスを格納する配列
    switch (n)
    {
    case 0: // 与えられた札と月が一致する場札が無いとき
        puts("場に置きました。");
        fprintf(fp, "場に置きました。\n");
        all_cards[id_to_first_index(card_id)][id_to_second_index(card_id)].stat = FIELD; // 与えられた札を場に置く
        break;
    case 1: // 与えられた札と月が一致する場札が1枚のとき
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (card_month == all_cards[i][j].month && all_cards[i][j].stat == FIELD)
                {
                    all_cards[i][j].stat = (my_or_enemy == MY_CARD) ? MY_FIELD : ENEMY_FIELD; // 与えられた札と月が一致する場札を取る
                    frag = 1;
                    // 与えられた札と月が一致する場札のインデックスを記録
                    indxs[0] = i;
                    indxs[1] = j;
                    break;
                }
            }
            if (frag)
                break; // 与えられた札と月が一致する場札が見つかったらbreak
        }
        printf("%s を取りました。\n", all_cards[indxs[0]][indxs[1]].name);
        fprintf(fp, "%s を取りました。\n", all_cards[indxs[0]][indxs[1]].name);
        all_cards[id_to_first_index(card_id)][id_to_second_index(card_id)].stat = (my_or_enemy == MY_CARD) ? MY_FIELD : ENEMY_FIELD; // 与えられた札を取る
        break;
    case 2: // 与えられた札と月が一致する場札が2枚のとき
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (card_month == all_cards[i][j].month && all_cards[i][j].stat == FIELD)
                {
                    frag++;
                    // 与えられた札と月が一致する場札のインデックスを記録
                    indxs[2 * frag - 2] = i;
                    indxs[2 * frag - 1] = j;
                }
            }
            if (frag == 2)
                break; // 与えられた札と月が一致する場札が2枚とも見つかったらbreak
        }

        if (my_or_enemy == MY_CARD)
        {               // 自分の手番のとき
            int b = -1; // どちらを取るかを表す変数
            printf("どちらの札を取りますか？（%s（0）,%s（1））：", all_cards[indxs[0]][indxs[1]].name, all_cards[indxs[2]][indxs[3]].name);
            while (b != 0 && b != 1)
            {
                scanf("%d", &b); // どちらの札を取るか選ぶ
                switch (b)
                {
                case 0:
                    printf("%s を取りました。\n", all_cards[indxs[0]][indxs[1]].name);
                    fprintf(fp, "%s を取りました。\n", all_cards[indxs[0]][indxs[1]].name);
                    all_cards[indxs[0]][indxs[1]].stat = MY_FIELD; // 選ばれた札を取る
                    break;
                case 1:
                    printf("%s を取りました。\n", all_cards[indxs[2]][indxs[3]].name);
                    fprintf(fp, "%s を取りました。\n", all_cards[indxs[2]][indxs[3]].name);
                    all_cards[indxs[2]][indxs[3]].stat = MY_FIELD; // 選ばれた札を取る
                    break;
                default:
                    printf("0か1を入力してください。：");
                    break;
                }
            }
            all_cards[id_to_first_index(card_id)][id_to_second_index(card_id)].stat = MY_FIELD; // 与えられた札を取る
            break;
        }
        else
        { // 相手の手番のとき
            int m = 2 * (rand() % 2);
            all_cards[indxs[m]][indxs[m + 1]].stat = ENEMY_FIELD; // 2枚からランダムに1枚選んで取る
            printf("%s を取りました。\n", all_cards[indxs[m]][indxs[m + 1]].name);
            fprintf(fp, "%s を取りました。\n", all_cards[indxs[m]][indxs[m + 1]].name);
            all_cards[id_to_first_index(card_id)][id_to_second_index(card_id)].stat = ENEMY_FIELD; // 与えられた札を取る
            break;
        }
    case 3: // 与えられた札と月が一致する場札が3枚のとき
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (card_month == all_cards[i][j].month && all_cards[i][j].stat == FIELD)
                {
                    frag++;
                    // 与えられた札と月が一致する場札のインデックスを記録
                    indxs[2 * frag - 2] = i;
                    indxs[2 * frag - 1] = j;
                }
            }
            if (frag == 3)
                break; // 与えられた札と月が一致する場札が3枚とも見つかったらbreak
        }
        for (int i = 0; i < 3; i++)
        { // 与えられた札と月が一致する場札を3枚全て取る
            all_cards[indxs[2 * i]][indxs[2 * i + 1]].stat = (my_or_enemy == MY_CARD) ? MY_FIELD : ENEMY_FIELD;
            printf("%s", all_cards[indxs[2 * i]][indxs[2 * i + 1]].name);
            fprintf(fp, "%s", all_cards[indxs[2 * i]][indxs[2 * i + 1]].name);
            if (i < 2)
            {
                printf("、");
                fprintf(fp, "、");
            }
        }
        puts(" を取りました。\n");
        fprintf(fp, " を取りました。\n\n");
        all_cards[id_to_first_index(card_id)][id_to_second_index(card_id)].stat = (my_or_enemy == MY_CARD) ? MY_FIELD : ENEMY_FIELD; // 与えられた札を取る
        break;
    default:
        break;
    }
}

void take_from_deck(Card all_cards[12][4], int my_or_enemy, FILE *fp)
{              // 山札をめくる関数
    int b = 1; // ループ制御用変数
    while (b)
    {
        int n = rand() % 48;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].id == n + 1 && all_cards[i][j].stat == DECK)
                { // 札の中からランダムに選んだ1枚が山札にあれば
                    printf("山札から %s を引きました。", all_cards[i][j].name);
                    fprintf(fp, "山札から %s を引きました。", all_cards[i][j].name);
                    take(all_cards, my_or_enemy, all_cards[i][j].id, fp); // その札を使って場から札を取る(ことを試みる)
                    b = 0;
                }
            }
        }
    }
}

void cal_point(int *point, int hand, int card_num, FILE *fp)
{ // 得点を計算する関数
    printf("\n勝負！\n出来役：");
    fprintf(fp, "\n勝負！\n出来役：");
    switch (hand)
    {
    case HIKARI: /*三光か四光か五光のとき*/
        *point += (card_num == 5 ? 10 : (card_num == 4 ? 8 : 5));
        printf("%s\n＋%d点", (card_num == 5 ? "五光！" : (card_num == 4 ? "四光！" : "三光")), (card_num == 5 ? 10 : (card_num == 4 ? 8 : 5)));
        fprintf(fp, "%s\n＋%d点", (card_num == 5 ? "五光！" : (card_num == 4 ? "四光！" : "三光")), (card_num == 5 ? 10 : (card_num == 4 ? 8 : 5)));
        break;
    case AME: /*雨入り四光のとき*/
        *point += 7;
        puts("雨入り四光！\n7点\n");
        fprintf(fp, "雨入り四光！\n7点\n");
        break;
    case MAKU: /*花見で一杯のとき*/
        *point += 5;
        puts("花見で一杯\n＋5点\n");
        fprintf(fp, "花見で一杯\n＋5点\n");
        break;
    case TSUKI: /*月見で一杯のとき*/
        *point += 5;
        puts("月見で一杯\n＋5点\n");
        fprintf(fp, "月見で一杯\n＋5点\n");
        break;
    case INOSHIKATYO: /*猪鹿蝶のとき*/
        *point += 5 + card_num;
        printf("猪鹿蝶\n＋%d点\n", 5 + card_num);
        fprintf(fp, "猪鹿蝶\n＋%d点\n", 5 + card_num);
        break;
    case AKATAN + AOTAN: /*赤短かつ青短のとき*/
        *point += 10 + card_num;
        printf("赤短＆青短！\n＋%d点\n", 10 + card_num);
        fprintf(fp, "赤短＆青短！\n＋%d点\n", 10 + card_num);
        break;
    case AKATAN: /*赤短のとき*/
        *point += 5 + card_num;
        printf("赤短\n＋%d点\n", 5 + card_num);
        fprintf(fp, "赤短\n＋%d点\n", 5 + card_num);
        break;
    case AOTAN: /*青短のとき*/
        *point += 5 + card_num;
        printf("青短\n＋%d点\n", 5 + card_num);
        fprintf(fp, "青短\n＋%d点\n", 5 + card_num);
        break;
    case TANE: /*タネのとき*/
        *point += card_num - 4;
        printf("タネ\n＋%d点\n", card_num - 4);
        fprintf(fp, "タネ\n＋%d点\n", card_num - 4);
        break;
    case TAN: /*タンのとき*/
        *point += card_num - 4;
        printf("タン\n＋%d点\n", card_num - 4);
        fprintf(fp, "タン\n＋%d点\n", card_num - 4);
        break;
    case KASU: /*カスのとき*/
        *point += card_num - 9;
        printf("カス\n＋%d点\n", card_num - 9);
        fprintf(fp, "カス\n＋%d点\n", card_num - 9);
        break;
    default:
        break;
    }
}

int check(Card all_cards[12][4], int my_or_enemy, int *point, FILE *fp)
{ // 役ができたかどうか確認する関数
    int j = 0;
    int hand[11] = {0}; // 取った札のうち、各属性の札が何枚ずつあるかを記録する関数
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (all_cards[i][j].stat == (my_or_enemy == MY_CARD ? MY_FIELD : ENEMY_FIELD))
                hand[all_cards[i][j].type]++;
        }
    }

    int pre_point = *point; // 加算前の点数を記録
    if (hand[HIKARI] + hand[MAKU] + hand[TSUKI] == 3 && hand[AME] == 1)
        cal_point(point, AME, 0, fp); // 雨入り四光ができたら
    else if (hand[HIKARI] + hand[MAKU] + hand[TSUKI] >= 3)
        cal_point(point, HIKARI, hand[HIKARI] + hand[MAKU] + hand[TSUKI] + hand[AME], fp); // 三光か四光か五光ができたら

    if (hand[SAKAZUKI] == 1)
    {
        if (hand[MAKU] == 1)
            cal_point(point, MAKU, 0, fp); // 花見で一杯ができたら
        if (hand[TSUKI] == 1)
            cal_point(point, TSUKI, 0, fp); // 月見で一杯ができたら
    }

    if (hand[INOSHIKATYO] == 3)
        cal_point(point, INOSHIKATYO, hand[SAKAZUKI] + hand[TANE], fp); // 猪鹿蝶ができたら

    if (hand[AKATAN] == 3 && hand[AOTAN] == 3)
        cal_point(point, AKATAN + AOTAN, hand[TAN], fp); // 赤短かつ青短ができたら
    else if (hand[AKATAN] == 3)
        cal_point(point, AKATAN, hand[AOTAN] + hand[TAN], fp); // 赤短ができたら
    else if (hand[AOTAN] == 3)
        cal_point(point, AOTAN, hand[AKATAN] + hand[TAN], fp); // 青短ができたら

    if (hand[TANE] + hand[INOSHIKATYO] + hand[SAKAZUKI] >= 5)
        cal_point(point, TANE, hand[TANE] + hand[INOSHIKATYO] + hand[SAKAZUKI], fp); // タネができたら

    if (hand[TAN] + hand[AKATAN] + hand[AOTAN] >= 5)
        cal_point(point, TAN, hand[TAN] + hand[AKATAN] + hand[AOTAN], fp); // タンができたら

    if (hand[KASU] + hand[SAKAZUKI] >= 10)
        cal_point(point, KASU, hand[KASU] + hand[SAKAZUKI], fp); // カスができたら

    if (pre_point != *point)
    { // 役ができていたら
        if (*point - pre_point >= 7)
        { // できた役の点数が7点以上なら点数倍
            printf("\n7点倍！\n%d×2＝%d点\n", *point - pre_point, (*point - pre_point) * 2);
            fprintf(fp, "\n7点倍！\n%d×2＝%d点\n", *point - pre_point, (*point - pre_point) * 2);
            *point += *point - pre_point;
        }
        return 1;
    }
    else
        return 0;
}

int check_TESHI_or_KUTTSUKI(Card all_cards[12][4], int my_or_enemy, int *point, FILE *fp)
{                           // 手四・くっつきができているか確認する関数
    int card_num[12] = {0}; // 手札の枚数を月ごとにカウントして記録する配列

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (all_cards[i][j].stat == my_or_enemy)
                card_num[all_cards[i][j].month - 1]++;
        }
    }

    int frag = 0;
    for (int i = 0; i < 12; i++)
    {
        switch (card_num[i])
        {
        case 0:
        case 2:
            break;
        case 1:
        case 3:
            frag = -1;
            break;
        case 4:
            frag = 1;
            break;
        default:
            break;
        }
    }

    switch (frag)
    {
    case 0: // くっつきが成立していたら
        *point += 6;
        printf("%sの手札：\n", (my_or_enemy == MY_CARD ? "あなた" : "相手"));
        fprintf(fp, "%sの手札：\n", (my_or_enemy == MY_CARD ? "あなた" : "相手"));
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].stat == my_or_enemy)
                {
                    printf("%s ", all_cards[i][j].name);
                    fprintf(fp, "%s ", all_cards[i][j].name);
                }
            }
        }
        puts("\nくっつき！\n＋6点\n");
        fprintf(fp, "\nくっつき！\n＋6点\n\n");
        return 1;
    case 1: // 手四が成立していたら
        *point += 6;
        printf("%sの手札：\n", (my_or_enemy == MY_CARD ? "あなた" : "相手"));
        fprintf(fp, "%sの手札：\n", (my_or_enemy == MY_CARD ? "あなた" : "相手"));
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].stat == my_or_enemy)
                {
                    printf("%s ", all_cards[i][j].name);
                    fprintf(fp, "%s ", all_cards[i][j].name);
                }
            }
        }
        puts("\n手四！\n＋6点\n");
        fprintf(fp, "\n手四！\n＋6点\n\n");
        return 1;
    case -1:
    default:
        return 0;
    }
}

int my_or_enemy_turn(Card all_cards[12][4], int my_or_enemy, int turn_num, int *point, FILE *fp)
{ // 手番の関数
    printf("\n--%sの手番--\n\n場札:\n", (my_or_enemy == MY_CARD ? "あなた" : "相手"));
    fprintf(fp, "\n--%sの手番--\n\n場札:\n", (my_or_enemy == MY_CARD ? "あなた" : "相手"));

    for (int i = 0; i < 12; i++)
    { // 場札を出力
        for (int j = 0; j < 4; j++)
        {
            if (all_cards[i][j].stat == FIELD)
            {
                printf("%s ", all_cards[i][j].name);
                fprintf(fp, "%s ", all_cards[i][j].name);
            }
        }
    }
    puts("\n");
    fprintf(fp, "\n\n");
    if (my_or_enemy == MY_CARD)
    { // 自分の手番のとき
        printf("あなたの手札:\n");
        fprintf(fp, "あなたの手札:\n");
        for (int i = 0; i < 12; i++)
        { // 自分の手札を出力
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].stat == MY_CARD)
                {
                    printf("%s ", all_cards[i][j].name);
                    fprintf(fp, "%s ", all_cards[i][j].name);
                }
            }
        }
        puts("\n\nあなたが取った札:");
        fprintf(fp, "\n\nあなたが取った札:\n");
        for (int i = 0; i < 12; i++)
        { // 自分が取った札を出力
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].stat == MY_FIELD)
                {
                    printf("%s ", all_cards[i][j].name);
                    fprintf(fp, "%s ", all_cards[i][j].name);
                }
            }
        }
        puts("\n\n相手が取った札:");
        fprintf(fp, "\n\n相手が取った札:\n");
        for (int i = 0; i < 12; i++)
        { // 相手が取った札を出力
            for (int j = 0; j < 4; j++)
            {
                if (all_cards[i][j].stat == ENEMY_FIELD)
                {
                    printf("%s ", all_cards[i][j].name);
                    fprintf(fp, "%s ", all_cards[i][j].name);
                }
            }
        }
        puts("\n");
        fprintf(fp, "\n\n");
    }
    fprintf(fp, "(相手の手札：\n");
    for (int i = 0; i < 12; i++)
    { // 相手の手札を出力(txtファイルのみ)
        for (int j = 0; j < 4; j++)
        {
            if (all_cards[i][j].stat == ENEMY_CARD)
                fprintf(fp, "%s ", all_cards[i][j].name);
        }
    }
    fprintf(fp, ")\n\n");

    take(all_cards, my_or_enemy, select_card(all_cards, my_or_enemy, turn_num, fp), fp); // 手札から選んだ札で場札を取る

    take_from_deck(all_cards, my_or_enemy, fp); // 山札をめくる

    return check(all_cards, my_or_enemy, point, fp); // 役ができたら1、できていなければ0を返却
}

int main(void)
{
    FILE *fp; // ファイル操作用ポインタ

    fp = fopen("result.txt", "w");
    fclose(fp);                    // ファイルの内容をリセット
    fp = fopen("result.txt", "a"); // 追加モード

    puts("~~~~~花札~~~~~\n");
    fprintf(fp, "~~~~~花札~~~~~\n対戦記録\n\n");

    printf("何回戦勝負？（1~12）：");
    int battle = 0;
    scanf("%d", &battle); // 何回戦行うかを入力
    while (battle < 1 || battle > 12)
    { // 1~12でなければ
        printf("1~12の整数を入力してください。：");
        scanf("%d", &battle);
    }
    fprintf(fp, "%d回戦勝負", battle);

    int my_point = 0;         // 自分の得点を格納する変数
    int enemy_point = 0;      // 相手の得点を格納する変数
    int van_or_rea = MY_CARD; // どちらが先手かを格納する変数
    for (int i = 0; i < battle; i++)
    {
        printf("\n\n\n======%d回戦======\n", i + 1);
        fprintf(fp, "\n\n\n======%d回戦======\n", i + 1);

        Card all_cards[12][4] = {0}; // 全ての札を格納するCard型二重配列
        def_card(all_cards);         // 札を設定
        set_card(all_cards);         // 札を配置
        int turn_num = 1;            // 何巡目かを格納する変数

        int b = 1;
        // 手四・くっつきが成立したらbreak
        if (check_TESHI_or_KUTTSUKI(all_cards, MY_CARD, &my_point, fp))
        {
            van_or_rea = MY_CARD;
            b = 0;
        }
        if (check_TESHI_or_KUTTSUKI(all_cards, ENEMY_CARD, &enemy_point, fp))
        {
            van_or_rea = ENEMY_CARD;
            b = 0;
        }

        while (b)
        {
            printf("\n\n------%d巡目------\n\n", turn_num);
            fprintf(fp, "\n\n------%d巡目------\n\n", turn_num);
            if (van_or_rea == MY_CARD)
            { // 自分が先手なら
                if (my_or_enemy_turn(all_cards, MY_CARD, turn_num, &my_point, fp) == 1)
                {
                    van_or_rea = MY_CARD;
                    break;
                } // 自分の手番、役ができたらbreak
                if (my_or_enemy_turn(all_cards, ENEMY_CARD, turn_num, &enemy_point, fp) == 1)
                {
                    van_or_rea = ENEMY_CARD;
                    break;
                } // 相手の手番、役ができたらbreak
            }
            else
            { // 相手が先手なら
                if (my_or_enemy_turn(all_cards, ENEMY_CARD, turn_num, &enemy_point, fp) == 1)
                {
                    van_or_rea = ENEMY_CARD;
                    break;
                } // 相手の手番、役ができたらbreak
                if (my_or_enemy_turn(all_cards, MY_CARD, turn_num, &my_point, fp) == 1)
                {
                    van_or_rea = MY_CARD;
                    break;
                } // 自分の手番、役ができたらbreak
            }

            turn_num++;
            if (turn_num == 9)
            {
                van_or_rea = (van_or_rea == MY_CARD ? ENEMY_CARD : MY_CARD);
                break;
            } // 最後まで役ができなかったらbreak
        }
        printf("\nあなたの得点：%d点\n相手の得点：%d点\n", my_point, enemy_point);
        fprintf(fp, "\nあなたの得点：%d点\n相手の得点：%d点\n", my_point, enemy_point);
    }

    printf("\n%d回戦終了！\n勝敗：", battle);
    fprintf(fp, "\n%d回戦終了！\n勝敗：", battle);
    if (my_point > enemy_point)
    {
        puts("あなたの勝ち！\n");
        fprintf(fp, "あなたの勝ち！\n\n");
    }
    else if (my_point < enemy_point)
    {
        puts("相手の勝ち\n");
        fprintf(fp, "相手の勝ち\n");
    }
    else
    {
        puts("引き分け\n");
        fprintf(fp, "引き分け\n");
    }

    fclose(fp);

    return 0;
}
