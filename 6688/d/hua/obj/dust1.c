// poison_dust.c

inherit COMBINED_ITEM;

void create()
{
	set_name("蛇毒", ({ "snake_poison", "poison" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是从毒蛇口中挤出的并提炼而成的毒药。\n" );
		set("base_unit", "瓶");
		set("unit", "瓶");
		set("value", 70000);
	}
	set_amount(1);
}

void init()
{
	add_action("do_smear", "smear");
}

int do_smear(string arg)
{
	string me, what;
	object ob;
	// 2026-04-30: unused variable commented out
	// function f;

	if( !arg
	||	sscanf(arg, "%s on %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: smear <药粉> on <物品>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	message_vision("$N将" + name() + "涂抹在" + ob->name() + "上。\n", this_player());
	if(ob->query("poison/type") != me) {
		ob->set("poison/type", me);
		ob->set("poison/amount",10);
	}
	else {
		ob->set("poison/amount",ob->query("poison/amount")+10);
	}
	if(query_amount() > 0)
		add_amount(-1);
	return 1;
}
