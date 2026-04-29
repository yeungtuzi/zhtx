// picker
//modified for suzhou

#include <ansi.h>

inherit NPC;

void stealing(object ob);
void heal();

void create()
{
	seteuid(getuid());
	set_name("小混混", ({ "xiao hunhun", "picker"}) );
    	set("gender", "男性" );
	set("age", 12+random(6));
	set("long", "一个鬼鬼祟祟的小孩子。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_kee", 500);
	set("max_gin", 200);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 10);
	set("shen_type", 0);

  	set("thief", 0);
	set("combat_exp", random(1000));

	set_skill("force", 10); 
        set_skill("strike", 10);
	set_skill("sword", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_skill("stealing", 30);
	set_skill("begging", 30);
	set_skill("checking", 30); 
	set_skill("huntian-qigong", 10); 
	set_skill("xianglong-zhang", 10);
	set_skill("xiaoyaoyou", 10); 

	map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :)
        }) );

	set("chat_chance", 80);
	set("chat_msg", ({
		(: heal :),
		(: random_move :)
	}) );

	setup();

        carry_object("/d/yueyang/npc/obj/jitui");
        carry_object("/d/yueyang/npc/obj/jiudai");
	add_money("silver", 10);
	carry_object("/d/suzhou/npc/obj/lmcloth2")->wear();
}


void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
 
	if( !ob || environment(ob) != environment() 
                || (int)ob->query_skill("taoism", 1) > 30
                || ob->query_int() > 30
          ) return;

	switch( random(5) ) {
		case 0:
                       command("xixi " + ob->query("id"));
                       command("steal coin from " + ob->query("id"));
                       command("eat jitui");
			 break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 2:
                       command("pat " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 3:
                       command("hehe " + ob->query("id"));
                       command("steal cloth from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("steal all from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
        	 command("thank "+me->query("id"));
	         command("give 1 silver to " + me->query("id"));
	}
        else {
        	 command("heng");
	         command("say 这种东西鬼才要 ! 滚一边去 !");
		 command("give " + obj->query("name") + " to " + me->query("id"));
		 command("steal all from "+me->query("id") );
        }

	return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee") && ob->query("eff_kee") > ob->query("max_kee") / 5 )
        {
                command("exert lifeheal");
                ob->set("force_factor", 110);
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
