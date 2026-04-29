// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("葛六", ({ "ge liu", "ge", "liu" }) );
        set("title",YEL "店小二" NOR);
        set("nickname", GRN "京城一绝" NOR);
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("vendor_goods", ([
                __DIR__"obj/xhbaozi":20,
                __DIR__"obj/shjbaozi":20,
                __DIR__"obj/hshdoufu":20,
                __DIR__"obj/mldoufu":20,
                __DIR__"obj/shgfan":20,
                __DIR__"obj/pgmian":20,
                __DIR__"obj/sltang":20,
                __DIR__"obj/tcliyu":20,
                __DIR__"obj/hshmi":20,
           ]));
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
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
     add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "葛六笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "葛六用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break; 
                case 2:
                        say( "葛六点头哈腰，往楼上一指说道：这位" + RANK_D->query_respect(ob)
                                + "，楼上雅座请。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        
    if(ob->query("money_id") && ob->value() >=1000)
        {
                tell_object(who, "葛六一哈腰，说道：多谢您老，您慢慢用。\n");

                who->set_temp("rent_paid",1);

                return 1;
        }

        return 0;
}

