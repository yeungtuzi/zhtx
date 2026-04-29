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
        set_name(HIY"金"+HIW"蚕"+HIC"王"NOR, ({"jincan wang", "can", "wang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只金蚕王，据说服食以后会增加很多天赋，也不知道是不是真的。\n");
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_paimai",1);
                set("no_sell",1);
                set("value", 500);
                set("medicine", 1);
                set("unpawnable",1);
        }
        setup();
}

int do_eat(string arg)
{
       object me,ob;
       me=this_player();
       ob = this_object();
       if( !this_object()->id(arg) ) return 0;
        if( ob->query("owner") != me )
                return notify_fail("这个东东又不是你的，好意思吃白食吗？\n"); 
       if (me->query("kar")<30 && random(4) == 0)me->add("kar",random(2));
      if (me->query("per")<30 && random(4) == 0)me->add("per",random(2));
      if (me->query("elo")<30 && random(4) == 0)me->add("elo",random(2));
      if (me->query("msc")<30 && random(4) == 0)me->add("msc",random(2));
      if (me->query("wil")<30 && random(4) == 0)me->add("wil",random(2));
      if (me->query("spi")<30 && random(8) == 0)me->add("spi",1);
       write(HIC"你服下一只金蚕王，只觉得脱胎换骨，全身的能量几欲奔泻而出!\n"NOR);
       destruct(this_object());
       return 1;
}

void owner_is_killed(object killer)
{
     object ob;
     ob = this_object();
	if(userp(killer))
	{
                tell_room(environment(killer),"只见"+killer->query("name")+"偷偷的从尸体身上搜出一只金蚕王，迅速放入自己怀里。\n"NOR);
       		move(killer);
             ob->set("owner", killer);
       	}
       return;
}
