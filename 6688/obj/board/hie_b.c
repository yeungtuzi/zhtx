// hie_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("留言板",({"board"}));
	set("long","小逍的留言板. \n");
	set("location","/d/hie/hall");
	set("board_id","hie_b");
	setup();
	set("capacity",50);
	replace_program(BULLETIN_BOARD);
}
