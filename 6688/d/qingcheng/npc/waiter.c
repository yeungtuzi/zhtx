/* waiter.c */

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "waiter"})  );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著招待客人，不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
           //     "茶叶": "/obj/example/tea_leaf",
                "/obj/example/wineskin":10,
                "/obj/example/dumpling":10,
                "/obj/example/chicken_leg":10,
            //    "茶壶": "/obj/example/tea_pot", 
        ]) );

        set_skill("unarmed",50);
        set_skill("dodge",60);
         setup();        
        carry_object("/obj/cloth")->wear();
       
}
void init()
{        object ob;

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
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                               + "，请上二楼雅座。\n");
                        break;
                case 2:
                        say( "店小二说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝几盅本店的红酒吧，包你尽兴而归。\n");
                        break;
        }
}
               
