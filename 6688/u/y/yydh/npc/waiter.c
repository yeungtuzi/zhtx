#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name(HIM"小桂子"NOR, ({ "waiter" }) );
    set("gender", "无性" );
    set("age", 22);
    set("long",
            "小桂子对着一个大镜子不停的搔首弄姿。\n");
    set("combat_exp", 5);
    set("attitude", "friendly");
    set("rank_info/respect", "阿姨");
       setup();
}

void init()
{   
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
    }

}

void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    switch( random(2) ) {
            case 0:
                    say( "小桂子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                            + "，来看看本店新到的货物吧。\n");
                    break;
            case 1:
                    say( "小桂子忍不住偷笑，说道：这位" + RANK_D->query_respect(ob)
                            + "，请进请进。\n");
                    break;
            case 2:
                    say("嘿嘿，又赚了一笔！\n");
                    break;
    }
}


