inherit ITEM;

void create()
{
        set_name("小木屋", ({ "house","home", }) );
        set_weight(100000);
        set_max_encumbrance(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "间");
                set("long", "一间干净的小屋，四壁雪白，房间里还有几件简陋的家具。\n靠墙是灶台，好象可以做饭(cook)。\n");
                set("owner", "none");
        }
}

int is_container() { return 1; }

void init()
{
	add_action("do_out", "out");
	add_action("do_cook", "cook");
}

int do_out()
{
	object me;
	me = this_player();
	me->move("/d/hua/villige.c");
        message_vision("$N走出了自己的家…\n",me);
	return 1;
}

int do_cook(string arg)
{
	object food, me;
	if (!arg) {
		write("你想做什么? \n");
		return 1;
	}
	me = this_player();
	if (me->query("gender") == "女性") {
		message_vision("$N在家做了一盘"+arg+"。\n", me);
		food = new(__DIR__"foods");
		food->set_name(arg, ({"food"}));
                food->set("long", "一碗色香味具全的" + arg + "。\n");
		food->move(me);
	}
	else message_vision("$N是个大男人整天围着锅台转有什么出息!!!\n", me);
	return 1;
}
