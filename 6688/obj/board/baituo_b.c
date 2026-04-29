// /obj/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("白驼山庄留言板", ({ "board" }) );
	set("location", "/d/baituo/dating");
	set("board_id", "baituo_b");
	set("long",	"这是供白驼山弟子留言记事的留言板。\n" );
	setup();
	set("capacity", 20);
	replace_program(BULLETIN_BOARD);
}
