//write by lysh
// medicine: nineflower.c
// Jay 3/18/96
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIB"忘忧"+HIG"果"NOR, ({"wangyou guo", "guo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "这是一枚忘忧果，据说可以让人忘记过去不愉快的事情。\n");
                set("no_get",1);
                set("no_drop",1);
                set("no_paimai",1);
                set("no_sell",1);
                set("no_give",1);
                set("value", 500);
                set("medicine", 1);
//                set("unpawnable",1);
        }
        setup();
}

int do_eat(string arg)
{       
       object me;
       me=this_player();
       if (!id(arg))
               return notify_fail("你要吃什么？\n"); 
       me->add("died_times",-1);
         if(me->query("died_times")<0){me->set("died_times",0);}
       write("你吃下一枚忘忧果,只觉得神清气爽,顿时将过去的江湖仇杀恩恩怨怨忘得干干净净!\n");
       destruct(this_object());
       return 1;
}

void owner_is_killed(object killer)
{
	if(userp(killer))
	{
                tell_room(environment(killer),"只见"+killer->query("name")+"偷偷的从尸体身上搜出一枚忘忧果，迅速放入自己怀里。\n"NOR);
       		move(killer);
       	}
       return;
}
