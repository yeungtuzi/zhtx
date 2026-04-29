/* eshao.c */
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("恶少", ({ "eshao" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long","他满脸横肉,一看就知道不是什么好东西.
          看来他对你的态度并不友善.\n");
        set("combat_exp", 1000);
	set("shen_type", -1);
        set("rank_info/respect", "恶少");
       

        set_skill("unarmed",20);
        setup();        
        add_money("silver",20);             
        carry_object("/obj/cloth")->wear();

}
void init()
{        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       
              
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say(HIC"恶少恶狠狠的说:把你的钱教出来,要不然,哼哼.... \n"NOR);
                        break;
                case 1:
                        say(HIC"恶少对你大声嚷道:喂!你知道哪有漂亮小妞吗?\n"NOR);
                        break;
                
                        }
}
               