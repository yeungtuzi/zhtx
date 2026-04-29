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
        set_name(HIC"天仙"+HIG"玉露"NOR, ({"tianxian yulu", "yulu", "lu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支天仙玉露，据说对于习武者恢复内力具有奇效。\n");
//            set("no_get",1);
                set("value", 500);
                set("medicine", 1);
//              set("unpawnable",1);
        }
        setup();
}

int do_drink(string arg)
{       
       object me;
       me=this_player();
       if (!id(arg))
               return notify_fail("你要喝什么？\n"); 
       me->set("force",(int)me->query("max_force")*4);
       write("你服下一支天仙玉露,只觉得一阵清凉，全身的内劲几乎就要全部迸发出来!\n");
       destruct(this_object());
       return 1;
}

void owner_is_killed(object killer)
{
	if(userp(killer))
	{
                tell_room(environment(killer),"只见"+killer->query("name")+"偷偷的从尸体身上搜出一支天仙雨露，迅速放入自己怀里。\n"NOR);
       		move(killer);
       	}
       return;
}
