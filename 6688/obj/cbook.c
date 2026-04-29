// /obj/cbook.c

inherit ITEM;

void create()
{
	set_name("C程序指南", ({ "c book", "book" }));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是本又大又厚的书,内容好象是关于C语言的.\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name": "computer",	// name of the skill
			"exp_required":	0, // minimum combat experience required
					// to learn this skill.
			"sen_cost":  30,// gin cost every time study this
			"difficulty":20,// the base int to learn this skill											// modify is gin_cost's (difficulty - int)*5%
			"max_skill": 40,// the maximum level you can learn
				// from this object.
		]) );
	}
}
