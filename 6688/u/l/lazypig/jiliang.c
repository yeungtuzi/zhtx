inherit NPC;
#include <ansi.h>

int give_flybag();

void create()
{
        set_name("姬良", ({"ji liang"}));
        set("long","一位白衫青年，仙风道骨，仪表不凡。\n");
        set("gender", "男性");
        set("title",YEL"新人导师"NOR);
        set("age", 22);
        set("per", 40);
        set("inquiry", ([
                           "飞行包":(:give_flybag:),
                        ]));
        setup();
}

int give_flybag()
{
        object me=this_player();
        object ob=this_object();
        object obj;
        
        if (me->query_temp("newbie_flybag")=="got" )
        {
               command("say 你不是刚刚要了飞行包了吗？！");
                        return 1;
        }
        
        
        message_vision("$N说道：拿好。\n",ob);
        message_vision("$N给了$n一个飞行包。\n",ob,me);
        
        obj = new("/d/sky/obj/flybag.c");
        obj->move(me);
        
        me->set_temp("newbie_flybag","got");
        return 1;
}

