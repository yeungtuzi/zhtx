inherit ITEM;
#include <ansi.h>
void create()
{
	set_name( CYN"葵" + YEL"花" + WHT"令"NOR, ({ "sunflower ling", "ling"}) );
	set_weight(100);
                set("no_sell",1);
                set("unpawnable",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", YEL"这是一块用檀香木雕琢而成的令牌，上书：“"+CYN"葵花宫"NOR + YEL"”三字。\n"NOR);
		set("value", 100000);
		set("material", "wood");
	}
	setup();
}

void init()
{
        call_out("dest", 1800);
}

void dest()
{
	destruct(this_object());
}
