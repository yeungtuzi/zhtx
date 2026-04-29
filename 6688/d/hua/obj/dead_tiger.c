inherit ITEM;

void create()
{
	set_name("死虎", ({ "dead tiger", "tiger" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只死虎。");
		set("value", 10000);
	}
	call_out("decay", 240);
}

protected void decay()
{
        say("死虎发出一股难闻的恶臭，烂掉了 ... \n");
        destruct(this_object());
}
