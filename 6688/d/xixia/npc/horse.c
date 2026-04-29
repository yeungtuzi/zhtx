//horse.c

#include <ansi.h>

inherit NPC;

int mount(object who);
int umount(object who);

object rider = 0;

void create()
{
	set_name(HIW"骏马"NOR, ({ "horse" }) );
        set("race", "野兽");
        set("age", 4+random(3));

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "hoof"}) );

	set("mount_prop/attack", 10);
	set("mount_prop/strength", 10);
	set("mount_prop/parry", 10);
	set("mount_prop/dodge", 10);
        
        set("str",45);
        set("max_kee", 1000);
        set("combat_exp", 15000);
	set("apply/armor", 30);

	set_skill("dodge", 60);
	set_skill("move", 1000);
	set_skill("unarmed", 60);

        setup();
}

int can_ride()	{ return 1; }

void init()
{
        add_action("do_quit","quit");
	add_action("do_ride", "ride");
}

int do_ride(string arg)
{
	object who = this_player();

	if (arg != "on" && arg != "off")
		return notify_fail("你要骑什么？\n");

	if (arg == "on" && mount(who))
		message_vision("$N跨上一匹高头大马，威风凛凛！\n", who);
	else if (arg == "off" && umount(who))
		message_vision("$N从马上下来。\n", who);

	return 1;
}

int mount(object who)
{
	if( objectp(rider) )
		return notify_fail(rider->name() + "已经骑在上面了。\n");
	if( who->query_temp("mounting") )
		return notify_fail("你已经骑在马上面了。\n");
	
	rider = who;
	who->set_temp("mounting", this_object());

	return 1;
}

int umount(object who)
{
	if (who->query_temp("mounting") != this_object())
		return notify_fail("你并没有骑在马上面啊！\n");
        who->delete_temp("mounting");
        rider = 0;

        return 1;
}

varargs string long(int raw)
{
        if( !rider )
        	return("一匹全身浑然一色的宝马。你也许可以骑(ride on/off)\n");

	if( rider != this_player() )
		return("一匹全身浑然一色的宝马，" + rider->name() + "正骑在马上。\n");
	return("一匹全身浑然一色的宝马，你正骑在马上。\n");
}

int do_quit(string arg)
{
        if( rider  == this_player() )
		write("你必须先从马上下来才能quit!\n");
                else return 0;
	return 1;
}
