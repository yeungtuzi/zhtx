//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR"九花玉露"+YEL"丸"NOR, ({"jiuhua wan", "nineflower", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒九花玉露丸。\n");
                set("no_get",1);
                set("value", 50000);
                set("medicine", 1);
                set("no_get",1);
                set("no_put",1);
                set("no_drop",1);
                set("no_paimai",1);
                set("no_sell",1);
                set("no_give",1);
                set("unpawnable",1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
        call_out("dest", 900);
}

int do_eat(string arg)
{       
       object me;
       me=this_player();
       if (!id(arg))
               return notify_fail("你要吃什么？\n"); 
       me->set("force",(int)me->query("max_force")*2);
       write("你吃了一粒九花玉露丸,只觉得一阵清凉!\n");
       destruct(this_object());
       return 1;
}

void dest()
{
  //      message_vision(YEL"九花玉露丸渐渐地失去光泽，让风一吹，化作一堆齑粉随空而去了。\n"NOR);
        destruct(this_object());
}

