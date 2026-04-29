// /d/xizang/class/budala/obj/bottle.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("金本巴瓶", ({ "golden bottle", "bottle" }));
	set_weight(99999);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "座");
		set("long", @LONG
    这是历代活佛用来确认转世灵童的宝瓶,据说如果是真的转世灵童在这里
祈祷(pray),就能从佛祖那里领回前世的记忆.
LONG
);
		set("material", "gold");
		set("value", 1);
		set("no_get", "你不能从藏宝殿带走金本巴瓶!\n");
}
        setup();
}

void init()
{
        add_action("do_pray", "pray");
}

int do_pray(string arg)
{
	object me;
	if(!arg || arg=="") arg="bottle";
	if(arg!="bottle" && arg!="金本巴瓶")
		return 0;
	me=this_player();
	if(!me->query("marks/reborn"))
		return notify_fail("你不是任何人的转世,怎么祈祷也没用!\n");
	if((int)me->query("marks/reborn") > 5)
		return notify_fail("你已转生太多次,佛祖没什么可给你的了.\n");
	if((int)me->query("marks/reborn_exp") < 500000)
		return 
notify_fail("你的前世没什么可取回的记忆,好好修行今世算啦!\n");
	message_vision(HIY"$N在金本巴瓶前虔诚地祈祷,仿佛听到一个声音说:\n"+
	"哦,原来是你,终于又回来了.....\n"NOR, me);
	me->add("combat_exp", me->query("marks/reborn_exp")/10);
	me->delete("marks/reborn_exp");
	return 1;
}
