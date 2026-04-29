/* weaponor.c*/

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("兵器贩子", ({ "weaponor" }) );
        set("title", "兵器屋");
        set("gender", "男性" );
        set("age", 38);
        set("long", "卖兵器的是个中年人，脸上看不出什么表情。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 80);

        set("inquiry", ([
                "兵器屋" : "本店专卖各种兵器,防具.", 
        ]) );

        set("vendor_goods", ([
                "/obj/weapon/whip":5,
                "/obj/weapon/longsword":5,
                "/obj/weapon/dart":5,
                "/obj/weapon/shield":5,
//                "/obj/weapon/sixhammer":5,
 //               "/obj/weapon/thin_sword":5,
                "/obj/weapon/dagger.c":5,
               
        ]) );

        setup();
        add_money("silver", 5);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
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
        switch( random(4) ) {
                case 0:
                        say( "兵器贩子道：这位"
                                + RANK_D->query_respect(ob)
                                + "，自个儿挑一件称手的兵器吧\n");
                        break;
                case 1:
                        say( "兵器贩子突然间出了神，非常的深沉,使你捉摸不透.\n");
                        break;
        }
}

                           
