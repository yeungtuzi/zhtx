//lihua jiu
//by tlang for feicui bei

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"梨花酒"NOR, ({ "lihua jiu", "jiu" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM"一大坛芳香扑鼻的陈年梨花酒，让人谗的口水直流。\n"NOR);
		set("unit", "坛");
		set("value", 2000);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "梨花酒",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}

/*void init()
{
	add_action("do_fill","fill");
}

int do_fill()
{
	object ob=this_player();

	if(!present("feicui bei",ob) )
		return notify_fail("这种好酒只能用翡翠杯装才适合。\n");
	add("remaining",-1);
		return 1;
}
*/

