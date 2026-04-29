// waiter.c
// the coolest one!

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(HIG"店"+HIC"小"+HIR"二"NOR, ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");

        set("combat_exp", 50000000);
        set("max_force", 15000);
        set("force", 30000);
        set("force_factor", 500);
        set("max_kee", 50000);
        set("max_gin", 50000);
        set("max_sen", 50000);

        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
 //               __DIR__"obj/nuomi": 1,
 //               __DIR__"obj/xigua": 1,
                "/obj/example/wineskin": -1,
                "/obj/example/dumpling": -1,
                "/obj/example/chicken_leg": -1,
        ]) );

        set_temp("apply/damage", 1000);
        set_temp("apply/armor", 1000);
        set_temp("apply/armor_vs_force", 1000);

        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("move", 400);
        set_skill("taiji-shengong",400);
        set_skill("claw",400);
        set_skill("yin-gong", 400);

        map_skill("force", "taiji-shengong");
        map_skill("parry", "yin-gong");
        map_skill("dodge", "yin-gong");
        map_skill("move", "yin-gong");
        map_skill("claw","yin-gong");
        
        prepare_skill("claw","yin-gong");

        setup();
        carry_object("/obj/cloth")->wear();
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
        add_action("do_look", "look");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "店小二说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝几盅小店的红酒吧，这几天才从窖子里开封的哟。\n");
                        break;
        }
}

int do_look(string arg)
{
        if (arg == "waiter") {
                set("env/attack", 1);
                set("force_factor", 0);
                set("force", 0);
                set("max_force", 0);
                set("combat_exp", 0);
                set_temp("apply/damage", 0);
                "/cmds/std/look"->look_living(this_player(), this_object());
                set("env/attack", 50);
                set("force_factor", 500);
                set("force", 30000);
                set("max_force", 15000);
                set("combat_exp", 50000000);
                set_temp("apply/damage", 1000);
                return 1;
        }
}

