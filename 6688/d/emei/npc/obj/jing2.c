
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "大乘涅磐经", ({ "gin", "dacheng jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本破旧的大乘涅磐经。\n");                                    
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"sen_cost": 40, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
			"base_skill":	30,	// the maximum level you can learn
		]) );
	}
}
