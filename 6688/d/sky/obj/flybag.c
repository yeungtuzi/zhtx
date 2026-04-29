// by yydh
// Updated by dongsw 2003

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
                object shuijing;
                ob = this_player ();
        if (objectp(shuijing = present("shui jing",this_player()) ) )
                return notify_fail("你不能在挖宝的时候飞来飞去的，不怕找到的宝物被神仙收走了？\n");  
                if (ob->is_busy())
                        return notify_fail("你现在正忙着呢。\n");
                if (ob->is_fighting() )
                        return notify_fail("你无法在战斗中使用飞行包！\n");
//                if (ob->query("age") > 16)
//                        return notify_fail("只有小于16岁，才能使用飞行包!!!\n");
                    if (ob->query("combat_exp") > 800000)
                        return notify_fail("只有经验值小于800000，才能使用飞行包!!!\n");
                if (ob->query("kee") < 11)
                        return notify_fail("你的气太少了，飞不起来了!\n");
                if (ob->query("gin") < 11)
                        return notify_fail("你的精太少了，飞不起来了!\n");
        
        if(strsrch(base_name(environment(ob)),"/d/newb/") != -1)
        {
                tell_object(ob,"\n飞行包带你来到了一个完全陌生的世界......\n\n");
                ob->move("/d/sky/yzj");
                ob->set("startroom", "/d/jingcheng/nchkzh");
                ob->start_busy(10);
                call_out("ask_intro", 2, ob);
                return 1;
        }
        
        tell_object(ob,HIB"\n你心中默默祷告：“飞行包，请带我飞翔吧！”\n");
        tell_object(ob,HIB"只见飞行包发出淡淡的蓝光包裹着你钻入了云中。\n"NOR);
        ob->add("gin",-10);
        ob->add("kee",-10);
        myenv = environment (ob);
        ob->move ("/d/sky/yun");
        ob->start_busy(10);
        call_out("move_tian", 5, ob);
        return 1;
}

int ask_intro(object ob)
{
        ob->interrupt_me(ob,"death");
        tell_object(ob,"姬良：“这位" + RANK_D->query_respect(ob) + "，需要我向你介绍一下当今武林的状况吗？”(y/n)\n");
        input_to("ask_help", ob);
        return 1;
}

int ask_help(string arg, object me)
{
        object npc = present("ji liang", environment(me));
        object obj = new("/d/sky/npc/obj/9dan");

        if( arg == "Y" || arg == "y")
        {
                npc->do_visit(me);      
                return 1;
        }
        else
        {
                tell_object(me,"姬良：“飞行包是我的一个法器，或许可以对你有点用处，你可以在京城的中心找我要。”\n");
                tell_object(me,"姬良：“如果你对着飞行包诚心的祷告期盼飞翔，我想你会有所收获！”\n\n");

                if( me->query("newbie_gift") != "got")
                {
                        tell_object(me,"姬良：“鉴于你在新手村的出色表现，现特赐你九转金丹一粒，可以助你提高自身的内力修为。”\n"
                                       "姬良交给你一粒九转金丹。\n\n");
                        obj->set("owner", me);
                        obj->move(me);
                }
                me->start_busy(10);
                call_out("move_yun", 5, me);
                return 1;
        }
}

int move_yun(object me)
{
        me->interrupt_me(me,"death");
        tell_object(me,HIB"你心中默默祷告：“飞行包，请带我飞翔吧！”\n");
        tell_object(me,HIB"只见飞行包发出淡淡的蓝光包裹着你钻入了云中。\n"NOR);         
        me->move ("/d/sky/yun");
        me->start_busy(10);
        call_out("move_tian", 5, me);
        return 1;
}

int move_tian(object ob)
{
        ob->interrupt_me(ob,"death");
        tell_object(ob, "\n飞行包带你在云中转了几圈后终于来到了高空之上。\n\n");
        ob->move("/d/sky/tian");
        return 1;
}

int do_pat(string arg)
{
        object me = this_player();

                if (me->is_busy())
                        return notify_fail("你现在正忙着呢。\n");
                if (me->is_fighting() )
                        return notify_fail("你无法在战斗中使用飞行包！\n");
//                if (me->query("age") > 16)
//                        return notify_fail("只有小于16岁，才能使用飞行包!!!\n");
                  if (me->query("combat_exp") > 800000)
                        return notify_fail("只有经验值小于800000，才能使用飞行包!!!\n");
                if (me->query("food") < 1)
                        return notify_fail("你的食物太少了，无法使用!\n");
                if (me->query("gin") >= (me->query("eff_gin")*2))
                        return notify_fail("你的精已经足够使用了!\n");

        tell_object(me,HIW"你轻轻拍了拍飞行包\n"NOR);
          me->add("gin", 100);
//          me->add("food",-10);
            me->start_busy(3);
                return 1;
}



