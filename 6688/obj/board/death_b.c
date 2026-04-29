//fighter_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("最后的留言板", ({ "board" }) );
	set("location", "/d/death/deathhall");
	set("board_id", "death_b");
	set("long",	"这是供逝去的人留言记事的留言板。\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
