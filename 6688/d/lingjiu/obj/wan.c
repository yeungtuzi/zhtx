//wan.c			by night

inherit COMBINED_ITEM;

void create()
{
        set_name("药丸",({"wan"}));
        set("long", @LONG
一粒黝黑色的药丸，闻起来有一股清香，不知道有什么用。
LONG);
        set("value", 0);
        set("unit", "瓶");
        set("base_unit", "粒");
        set("base_weight", 1);
        set_amount(10);
}

void init()
{
	add_action("do_apply", "eat");
}

int do_apply()
{
	if(this_player()->is_busy())
		return notify_fail("刚服的药物还没起作用呢！\n");
	this_player()->start_busy(1);

    	message_vision("$N将一黝黑色的小丸吞了下去，可是好象什么也没发生。\n",this_player());
	this_player()->apply_condition("relieve_sheng_si", 120);
        add_amount(-1);
        return 1;
}
