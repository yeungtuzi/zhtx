//by zephyr

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_blade();
void heal();

void create()
{
	set_name("狄青麟", ({ "di qinglin","di"}) );
	set("long",CYN@LONG
他就是“神剑”应无物的弟子，狄青麟。他手中一柄薄刀，其薄如纸。
由于此刀又薄又快，杀人后竟不见血迹。
LONG NOR
	 );

	set("title",HIY"一等侯"NOR);
	set("age", 30);



	set_skill("force", 400);
	set_skill("strike", 400);
	set_skill("sword", 400);
	set_skill("blade", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("move", 400);
	set_skill("perception", 400);
		
	set_skill("taiji-shengong", 200);
	set_skill("celestrike", 400);
	set_skill("shortsong-blade", 400);
	set_skill("fall-steps", 400);
	map_skill("force", "taiji-shengong");
	map_skill("strike","celestrike");
	prepare_skill("strike", "celestrike");
	map_skill("blade", "shortsong-blade");
	map_skill("dodge", "fall-steps");
	map_skill("move", "fall-steps");
 
        setup();

	set("attitude", "peaceful");
	set("combat_exp", 10000000);

	set("str", 100);
	set("int", 30);
	set("cor", 100);
	set("cps", 100);                       
	set("per", 50);
	set("con", 30);
	set("no_get",1);

	set("atman", 1000);
	set("max_atman", 1000);

	set("force", 20000);
	set("max_force", 10000);
	set("force_factor", 300);

	set("mana", 10000);
	set("max_mana", 10000);

	set("max_kee",50000);
	set("max_sen",50000);
	set("max_gin",50000);
	set("eff_kee",50000);
	set("eff_sen",50000);
	set("eff_gin",50000);
	set("kee",50000);
	set("sen",50000);
	set("gin",50000);
    set("chat_chance",20);
	set("chat_msg", ({
                "狄青麟冷冷的四处打量了一下。\n",
               (: heal :),
               (: random_move :)
        }) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
	(: exert_function, "recover" :),
	}) );

		set("inquiry", ([
                "万君武" : "哼，这厮早已死在我的刀下。", 
                "灵空剑" : "我手中这把薄刀的前身就是灵空剑。", 
        ]) );


	set_temp("apply/defense",50);
	set_temp("apply/armor_vs_force",1000);
	set_temp("apply/armor",3000);
	

    set("shen_type",-1);
    set("skill_mark/spring-blade",1);
    setup();

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/u/z/zephyr/fakebodao")->wield();
	set("bellicosity",1000);
}                          

int accept_fight(object ob)
{
	command("heng");
	kill_ob(ob);
	return 1;
}

int killed_enemy(object ob)
{
	command("say 世上偏生有这么多不怕死的家伙！\n");
	command("heng");
}


void chat()
{
	object me,*enemy,victim;
	int fighting,i, all;

	me = this_object();
	if( !environment(me) ) return 0;
	fighting = me->is_fighting();

	if(fighting)
	{
		enemy = me->query_enemy();
		all = sizeof(enemy);

		for(i=0;i<all;i++)
		{
			victim = enemy[i];
			if (victim->query_temp("have_hook"))
			{
				if (random(100)>95)
				{
					if (random(2))
						command("say 你这" + RANK_D->query_rude(victim) + "究竟是谁派来的？手上这柄兵器是什么来路？！");
					else command("say 万君武是你什么人？");
				}
				
				continue;
			}

			if (present("leave hook",victim))
			{
				message_vision(BLU"狄青麟冷笑一声，只见刀光轻轻一闪，手中薄刀已然到了"+victim->name()+"咽喉，"+victim->name()+"急忙用手中离别钩轻轻一拨，挡开了薄刀。\n"NOR, environment());
				victim->set_temp("have_hook",1);
				continue;
			}

			message_vision(BLU"狄青麟冷笑一声，只见刀光轻轻一闪，"+victim->name()+"已经倒下，身上却没有半点伤痕。\n"NOR, environment());
			victim->unconcious();
			if (userp(victim))
			{
				victim->move("/d/xanadu/inn");
				tell_object(victim,HIR"\n你被打晕了....\n"NOR);
			}
		}
	}
	if(query("sen")<(query("eff_sen")*70/100))
	command("exert refresh");
	if(query("kee")<(query("eff_kee")*70/100))
	command("exert recover");
	if(query("gin")<(query("eff_gin")*70/100))
	command("exert regenerate");
	::chat();
}
void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 300");
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

void smash(object victim)
{
	if (victim->query_temp("have_hook"))
	{
		command("say 你这" + RANK_D->query_rude(victim) + "究竟是谁派来的？手上这柄兵器是什么来路？！");
		command("say 万君武是你什么人？");
		return;
	}

	if (present("leave hook",victim))
	{
		message_vision(CYN"狄青麟冷笑一声，只见刀光轻轻一闪，手中薄刀已然到了"+victim->name()+"咽喉，"+victim->name()+"急忙用手中离别钩轻轻一拨，挡开了薄刀。\n"NOR, environment());
		victim->set_temp("have_hook",1);
		return;
	}

	message_vision(CYN"狄青麟冷笑一声，只见刀光轻轻一闪，"+victim->name()+"已经倒下，身上却没有半点伤痕。\n"NOR, environment());
	victim->unconcious();
	if (userp(victim))
	{
		victim->move("/d/xanadu/inn");
		tell_object(victim,HIR"\n你被打晕了....\n"NOR);
	}
}

void die()
{
	object blade,fake_blade, killer;
	if (objectp(fake_blade=present("bo blade",this_object())))
	{
		destruct(fake_blade);
	}
	killer=query_temp("last_damage_from");
	if (objectp(killer) && present("leave hook",killer))
	{
		blade=new("u/z/zephyr/bodao.c");
		blade->move(this_object());
	}
	::die();
}
