#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"九转仙丹"NOR, ({ "dan" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "胡青牛多方采集珍贵药材，再加以精炼九转而成，是武林人士梦寐以求的圣药。\n");
		set("unit", "颗");
		set("value", 50000);
	}
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object who;
         int bak;
	
	who = this_player();
        bak=who->query("max_force");
	message_vision(HIY"$N吃下一颗"+HIG"九转仙丹"HIY+"，顿时一股真气从丹田升起。。。\n",who);
	message_vision(HIY"真气循经脉运行一个周天完毕，$N顿时有脱胎换骨之感。\n"NOR,who);
	who->set("eff_kee",who->query("max_kee"));
	who->set("eff_gin",who->query("max_gin"));
	who->set("eff_sen",who->query("max_sen"));
	who->add("max_force",5+random(who->query_con()/2));
      if (who->query("max_force")> 8000){who->set("max_force",bak);}
	destruct(this_object());
	return 1;
}
