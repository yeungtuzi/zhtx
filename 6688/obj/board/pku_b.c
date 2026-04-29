// /obj/board/pku_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("三角地广告牌", ({ "board" }) );
	set("location", "/d/peking/triangle");
	set("board_id", "pku_b");
	set("long",	"这是放在三角地供张贴广告和留言用的广告牌\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
