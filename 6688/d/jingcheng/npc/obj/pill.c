// pill.c SARS预防专用药（纵横版）
// by dongsw 搞笑 2003 5.1

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"SARS预防专用药（纵横版）"NOR, ({"sars pill", "pill"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("long", "这是一片预防非典型性肺炎的药片。\n");
                set("value", 0);
                set("unpawnable",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        object ob = this_object();
        object obj;
        
        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        if (ob->query("owner") != me)
        {
                write("这片SARS药不是你的，药吃多了可不好。:p\n");
                return 1;
        }
        
        write(CYN"\n你吃下了SARS预防专用药（纵横版）。\n\n"
              HIY"你得到了 潜能 10000点！\n"
                 "你得到了 黄金 100两！\n"
                 "你得到了 内力最大点 100点！\n"
                 "你得到了 风泉之剑 1把！\n"
                 "你得到了 怒龙锦胄 1件！\n\n"
              HIG"纵横天下2巫师组在此衷心的祝福您远离非典型性肺炎的侵扰。\n\n希望您在游戏的同时能有一个健康的身体，投入到以后的学习工作中去。\n\n并且祝您五一节日快乐，有个好的假期！\n"NOR);

        me->add("potential", 10000);
        me->add("max_force", 100);
        obj = new("/obj/money/tenthousand-cash.c");
        obj->move(me);
        obj = new("/class/scholar/windspring.c");
        obj->move(me);
        obj = new("/class/fighter/dragon_armor.c");
        obj->move(me);
        destruct(ob);
        return 1;
}


