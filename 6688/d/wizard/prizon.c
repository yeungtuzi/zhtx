
#include <ansi.h>

inherit __DIR__"jianyu";

void create()
{
	set("short", "监狱");
	set("long", @LONG
    这是专门用来关押有伤风化者的监狱!
    墙上(wall)写有几个字。

LONG
	);


	set("item_desc", ([
                "wall" : RED "裸奔者戒！\n\n" NOR,
                ]) );
	setup();

}

void init()
{       
	object ob = this_player();

	if( (int)ob->query_condition("bonze_jail") <= 0 )
	{
		message("vision",
			HIY "只听牢房门匡地一响，一个赤身裸体的家伙被扔了进来！\n\n" NOR, 
			environment(ob), ob);

		tell_object(ob, "狱卒嘻嘻地笑着：又抓来一个...！\n");

		ob->set("startroom", "/d/wizard/prizon");
		ob->apply_condition("bonze_jail", 10);
	}
         ::init();
}
