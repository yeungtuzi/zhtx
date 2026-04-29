/* girl_waiter.c*/
#include <ansi.h>
inherit NPC;


void create()
{
        set_name("女侍", ({ "girl waiter","girl","waiter" }) );
        set("gender", "女性" );
        set("per", 25);
        set("age", 18);
        set("long", "她是酒店的女侍,正值青春年少,长得亭亭玉立。\n");
        set("combat_exp", 400);
        set("attitude", "friendly");
      
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("dagger", 10);

        set("inquiry", ([
                "过夜" : HIM"“本店只做酒席生意,不是旅馆.”\n"NOR, 
                "特别服务" : HIM"“官人可要洁身自好啊!\n"NOR,
                          ]) );

        setup();
        add_money("silver", 1);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/dagger")->wield();
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
        switch( random(4) ) {
                case 0:
                        say( "女侍笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，定做筵席吗?\n");
                        break;
                case 1:
                        say( "女侍趁老板娘不注意,对你抛了个媚眼.\n");
                        break;
        }
 }

                           