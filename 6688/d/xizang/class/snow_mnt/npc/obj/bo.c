// /d/xizang/class/snow_mnt/npc/obj/bo.c
// 铜钹, a nice secdonary weapon
// by mscat
//

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("铜钹", ({ "tongbo", "bo" }));
	set_weight(3000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", 
		"这是一只金光闪亮的铜钹,边缘锋利,似乎可作武器.\n");
		set("value", 400);
	}
	init_dagger(40);
	set("wield_msg", "$N抓起一只$n当作武器.\n");
	set("unwield_msg", "$N将手中的$n放下了.\n");
        setup();
}

/*
void init()
{
	add_action("do_cut", "cut");
}

int do_cut(string arg)
{
	object ob;
	if(!arg) return notify_fail("小心!\n");
	ob=find_player(arg);
	if(!ob) ob= find_living(arg);
	if(!ob) return notify_fail("小心!\n");
	if(!present(ob, environment(this_player()))) {
		ob->move(environment(this_player()));
		message_vision("$N莫名其妙地被弄到了这里.\n", ob);
	}
	if(objectp(ob) && ob->is_character()) {
		if((string)ob->query("gender") != "男性")
			return notify_fail("没有作用.\n");
	message_vision("$N挥动铜钹,金光一闪,"+
		"只听$n一声惨叫,双手捂住胯下,血流不止!\n", this_player(),ob);
		ob->set("gender", "无性");
		tell_object(ob, "恭喜,您可以去练辟邪剑法了.\n");
		CHANNEL_D->do_channel(this_player(), "rumor",
		sprintf("%s被逼无奈,作了太监!\n", ob->name(1)));
		ob->set("env/immortal", 0);
		ob->set("env/invisibility", 0);
		return 1;
	}
	return notify_fail("那不是一个人.\n");
}

*/
