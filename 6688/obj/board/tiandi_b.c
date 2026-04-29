// /obj/board/tiandi_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("天地会留言板", ({ "board" }) );
	set("location", "/d/yanjing/dating");
	set("board_id", "tiandi_b");
	set("long",	"这是供天地会会众留言记事的留言板。\n" );
	setup();
	set("capacity", 20);
	replace_program(BULLETIN_BOARD);
}
