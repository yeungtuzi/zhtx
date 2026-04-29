// /obj/board/zgc_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("中关村传言板", ({ "board" }) );
	set("location", "/d/peking/inn");
	set("board_id", "zgc_b");
	set("long",	"这是中关村各位大侠们留言的地方\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
