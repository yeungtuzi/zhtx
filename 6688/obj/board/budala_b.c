
inherit BULLETIN_BOARD;

void create()
{
	set("board_id", "budala_b");
	set("location", "/d/xizang/class/budala/fhall" );
	setup();
	set_name("无尘明镜", ({ "mirror" }) );
	set("long","\n"
		"这是一座藏式佛龛，后面放着一面明镜，虽然布达拉宫已经\n"
		"年代久远，但是这面镜子却从未沾染过灰尘，在参禅之余，\n"
		"也习惯把自己的想法对着明镜默祷，明镜能将之一一映照。\n");
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
