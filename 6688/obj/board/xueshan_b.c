// /obj/board/xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("雪山寺留言板", ({ "board" }) );
	set("location", "/d/xizang/dadian");
	set("board_id", "xueshan_b");
	set("long",	"这是供雪山寺僧人留言记事的留言板。\n" );
	setup();
	set("capacity", 20);
	replace_program(BULLETIN_BOARD);
}
