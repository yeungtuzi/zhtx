///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
                "/obj/example/teapot": -1,
                "/obj/example/wineskin": -1,
                "/obj/example/dumpling": -1,
                "/obj/example/chicken_leg": -1,
        ]));
        setup();
}

void init()
{
        object ob;

        ob = this_player();

        ::init();
                   if( interactive(ob = this_player()) && !is_fighting() ) {
                           remove_call_out("greeting");
                           call_out("greeting", 1, ob);
        }
//        add_action("do_buy", "buy");
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        int exp;
    if( !ob || environment(ob) != environment() ) return;
    switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
           exp=ob->query("combat_exp");
           if(exp<20000) {
                        tell_object(ob,YEL"店小二笑咪咪地说道：在这儿可以买到食物和水哦。用指令"HIW+" list "NOR+YEL"可以看到商品列表。\n"
                        +"用指令"HIW+" buy <物品> from waiter "NOR+YEL"就可以买到了，不过你身上得带钱哦。\n"
                        +"店小二神神秘秘的说道：你先去夫子书院习字，有一定长进后就可以去村东口小溪边钓鱼，\n"
                        +"村北边的森林打猎挣钱了。从这儿"HIW+" n; e; e; n "NOR+YEL"就到夫子书院了。\n"NOR);
                }
}


