// /obj/board/lingjiu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("灵鹫宫留言板", ({ "board" }) );
	set("location", "/d/lingjiu/dating");
	set("board_id", "lingjiu_b");
	set("long",	"这是供灵鹫宫弟子留言记事的留言板。\n" );
	setup();
	set("capacity", 20);
	replace_program(BULLETIN_BOARD);
}
