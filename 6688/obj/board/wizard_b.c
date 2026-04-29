// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("巫师意见箱", ({ "board" }) );
	set("location", "/d/wizard/guest_room");
	set("board_id", "wizard_b");
	set("long",
		"这是一个供玩家给巫师提出建议的留言板。\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
