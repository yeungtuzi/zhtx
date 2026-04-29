// /obj/board/common_a.c
// board used in the inn of xizang

inherit BULLETIN_BOARD;

void create()
{
	set_name("一般用途留言板", ({ "board" }) );
	set("location", "/d/xizang/inn");
	set("board_id", "common_a");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
