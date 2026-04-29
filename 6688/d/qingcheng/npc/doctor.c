/* doctor.c */

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("游方郎中", ({ "doctor" }) );
        set("gender", "男性" );
        set("age", 45);
	set("shen_type", 1);
        set("long", "他是一个饱经沧桑的中年人,所到的地方非常多。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 70);
        set_skill("dodge", 100);
       
        set("inquiry", ([
                "大补丸" : "它能医疗各种由于内力所造成的伤害,迅速恢复体力.", 
        ]) );

        set("vendor_goods", ([
                __DIR__"obj/medicine":10,
                __DIR__"obj/spile":2,
              
        ]) );
       set("chat_msg", ({
                (: this_object(), "random_move" :),
        }) );
          setup();
        add_money("silver", 10);
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
                        say( "游方郎中说道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买上好的伤药吗?\n");
                        break;
                case 1:
                        say( "游方郎中道:祖传秘方,包治百病.\n");
                        break;
                 case 2: 
                         say( "游方郎中道:有专治内伤的灵药出售.\n");                   
                             }
}

                           
