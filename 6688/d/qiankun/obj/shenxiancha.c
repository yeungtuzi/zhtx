//write by lysh
// medicine: nineflower.c
// Jay 3/18/96
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_drink", "drink");
}

void create()
{
        set_name(HIB"神仙"+HIW"茶"NOR, ({"shenxian cha", "cha"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "碗");
                set("long", "这是一碗神仙茶,只有天上神仙才可以享受到的东西。\n");
                set("no_get",1);
                set("value", 500);
                set("medicine", 1);
                set("unpawnable",1);
        }
        setup();
}

int do_drink(string arg)
{       
       object me;
       me=this_player();
       if (!id(arg))
               return notify_fail("你要吃什么？\n"); 
       me->set("mana",(int)me->query("max_mana")*2);
       me->set("atman",(int)me->query("max_atman")*2);
       write("你饮下一碗神仙茶,只觉得灵台清澈,飘飘欲仙!\n");
       destruct(this_object());
       return 1;
}

void owner_is_killed(object killer)
{
	if(userp(killer))
	{
                tell_room(environment(killer),"只见"+killer->query("name")+"偷偷的从尸体身上搜出一碗神仙茶，迅速放入自己怀里。\n"NOR);
       		move(killer);
       	}
       return;
}
