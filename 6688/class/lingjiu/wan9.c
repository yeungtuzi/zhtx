//wan9.c

inherit COMBINED_ITEM;

void create()
{
        set_name("九转熊蛇丸",({"gui wan","wan"}));
        set("long",
                "传说这灵验无比的神药九转熊蛇丸，原本只在天山飘渺峰灵鹫宫才能见到，\n");
        set("value", 100000);
        set("unit", "颗");
        set("base_unit", "粒");
        set("base_weight", 1);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
                add_action("do_apply", "eat");
}

int do_apply()
{
	if(this_player()->is_busy())
		return notify_fail("刚服的药物还没起作用呢！\n");
	this_player()->start_busy(1);

        this_player()->receive_curing("kee",1000);
	
    	message_vision("$N将一颗淡黄色的小丸吞了下去，似乎浑身充满了力量．\n",this_player());
        add_amount(-1);
        return 1;
}
