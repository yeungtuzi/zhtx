// /obj/book/basic.c

inherit ITEM;

void create()
{
	set_name("BASIC语言", ({ "basic book", "book" }));
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","BASIC语言,三次修订本,著者:谭浩强.\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name": "computer",	// name of the skill
		"exp_required":	0, // minimum combat experience required
					// to learn this skill.
		"sen_cost":  30,// gin cost every time study this
		"difficulty":15,// the base int to learn this skill											// modify is gin_cost's (difficulty - int)*5%
		"max_skill": 25,// the maximum level you can learn
				// from this object.
		]) );
	}
}
