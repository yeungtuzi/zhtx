// 9dan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"九"HIG"转"HIY"金"HIC"丹"NOR, ({"dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒九转金丹，闪闪发光，晶莹剔透。绝非凡间之物。\n");
                set("value", 0);
                set("unpawnable",1);
        }
        setup();
}

void init()
{
add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob = this_object(), me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

  //      if( ob->query("owner") != me )
  //              return notify_fail("这个不是你的，吃多了不怕上火？\n");

   //     if( me->query("newbie_gift") == "got")
     //           return notify_fail("你已经吃过一次了，吃多了不怕上火？\n");

          write(HIY"你吃下一粒九转金丹，感觉体内真气滋滋而生，内力修为有了新的进境。\n"NOR);

me->set_temp("apply/damage",1000);
me->set_temp("apply/armor_vs_force",2000);
me->set_temp("apply/armor_vs_spells",200);
me->set_temp("apply/armor",2000);
me->set("max_force",16000);
        me->set("force", 80000000);
  //me->set("force", 8000);
//        me->set("newbie_gift","got");

//log_file("9danlog", me->query("id") + " have got the newbie'gift。\n");

        destruct(this_object());
        return 1;
}
