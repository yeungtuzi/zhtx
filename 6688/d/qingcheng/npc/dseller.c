/* dumpling_seller */

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖包子的", ({ "dumpling seller","seller" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "他是一个刚刚接替父亲挑起家庭担子的年轻人。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
       
        set("vendor_goods", ([
                "包子": "/obj/example/dumpling",
                          
        ]) );

        setup();
        add_money("coin", 400);
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


}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "卖包子的说道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买些刚刚出笼的包子吧.\n");
                        break;
                case 1:
                        say( "卖包子的吆喝道:卖包子嘞~~~~~~~.\n");
                        break;
                                
}
}

                           