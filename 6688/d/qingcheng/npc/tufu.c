/* tufu.c */

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("屠夫", ({ "tufu"})  );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                "他起刀落刀都非常的利落,显然是行中个手。\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
        set("rank_info/respect", "屠子");
        set("vendor_goods", ([
                 __DIR__"obj/pork":10,                
        ]) );

        set_skill("unarmed",10);
        set_skill("dodge",30);
        set_skill("dagger",30);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver",4);
        add_money("coin",250);
        
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
        say( "屠夫头也不抬地说道：这位" + RANK_D->query_respect(ob)
                 + "，请你稍等一会儿.\n");
             break;
       case 1:
      say( "屠夫用肩上的毛巾擦擦汗，说道：这位" + RANK_D->query_respect(ob)
                   + "，要上好的山猪肉吗?\n");
                        break;
                
        }
}
             
