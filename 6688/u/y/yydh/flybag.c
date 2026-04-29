#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_fly","flyup");
        add_action("do_pat","patit");
}
void create()
{
       set_name("飞行包", ({ "fly bag", "flybag", "bag" }) );
       set_weight(10);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "个");
               set("long", "这是一个给新手用的飞行包,你可以用flyup来快速飞行。\n");
                set("no_get", 1);
                set("no_put", 1);
                set("no_drop", 1);
            }       setup();
}
int do_fly()
{
                object ob, myenv;
                ob = this_player ();
                if (ob->is_busy())
                        return notify_fail("你现在正忙着呢。\n");
                if (ob->is_fighting() )
                        return notify_fail("你无法在战斗中使用飞行包！\n");
                if (ob->query("age") > 16)
                        return notify_fail("只有小于16岁，才能使用飞行包!!!\n");
                    if (ob->query("combat_exp") > 1000000)
                        return notify_fail("只有经验值小于1000000，才能使用飞行包!!!\n");
                if (ob->query("kee") < 11)
                        return notify_fail("你的气太少了，飞不起来了!\n");
                if (ob->query("gin") < 11)
                        return notify_fail("你的精太少了，飞不起来了!\n");

        tell_object(ob,"你发动了飞行包,你飞了起来。\n");
        tell_object(ob,"你飞啊飞,飞了很长时间终于飞到了高空......\n");
        ob->add("gin",-10);
        ob->add("kee",-10);
        myenv = environment (ob);
        ob->move (__DIR__"tian");
        return 1;
}

int do_pat(string arg)
{
        object me = this_player();

                if (me->is_busy())
                        return notify_fail("你现在正忙着呢。\n");
                if (me->is_fighting() )
                        return notify_fail("你无法在战斗中使用飞行包！\n");
                if (me->query("age") > 16)
                        return notify_fail("只有小于16岁，才能使用飞行包!!!\n");
                  if (me->query("combat_exp") > 1000000)
                        return notify_fail("只有经验值小于1000000，才能使用飞行包!!!\n");
                if (me->query("food") < 1)
                        return notify_fail("你的食物太少了，无法使用!\n");
                if (me->query("gin") >= (me->query("eff_gin")*2))
                        return notify_fail("你的精已经足够使用了!\n");

        tell_object(me,HIW"你轻轻拍了拍飞行包\n"NOR);
          me->add("gin", 100);
          me->add("food",-10);
            me->start_busy(2+random(1));
                return 1;
}



