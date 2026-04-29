// /obj/book/winbook.c

inherit ITEM;

void create()
{
	set_name("WINDOWS傻瓜书", ({ "windows book", "win book", "book" }));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","微软傻瓜系列:WINDOWS傻瓜书,Bill Gates版权所有.\n");
		set("value", 4000);
		set("material", "paper");
		set("skill", ([
			"name": "computer",	// name of the skill
		"exp_required":	0, // minimum combat experience required
					// to learn this skill.
		"sen_cost":  30,// gin cost every time study this
		"difficulty":15,// the base int to learn this skill											// modify is gin_cost's (difficulty - int)*5%
		"max_skill": 30,// the maximum level you can learn
				// from this object.
		]) );
	}
}
