// renshen.c 人参

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("人参", ({"renshen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵成形的老山参。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{                              
   int neili;
   int max_neili;
   object me = this_player();
	if (!arg || (arg != "renshen" && arg != "shen" ) )
		return notify_fail("你要吃什么？\n");
         max_neili=me->query("max_force");
         neili=me->query("force");
         neili = neili + me->query("max_force")/4;
	 if( neili > 2* max_neili ) neili = 2* max_neili;
         me->set("force",neili);
         message_vision("$N吃了一棵人参，感到内力有所增加！\n", me);
         destruct(this_object());
         return 1;

}

