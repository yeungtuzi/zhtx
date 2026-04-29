// /obj/board/biaoju_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name(YEL"镖局留言板"NOR, ({ "board" }) );
	set("location", "/d/suzhou/biaoju");
	set("board_id", "biaoju_b");
	set("long", @LONG
	镖局不在作为一个门派而存在，只负责传授基本功夫，加入它，
或者给钱都行。护镖任务暂时不开，也不给quest.
LONG	
	);
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

