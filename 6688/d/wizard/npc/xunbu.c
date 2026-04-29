#include <condition.h>
#include <ansi.h>
#include <combat.h>

inherit NPC;

int clone_skill(object ,object);
int my_random_move();
void heal();


void create()
{
        int i;
      
        seteuid(getuid());

        set_name("巡捕", ({ "xunbu 007", "bu" ,"xunbu","007"}) );
	set("title", "滥杀无辜者－"+HIR"“戒”"NOR);
	set("long","据说他是六扇门弟子，追踪术登峰造极。\n"
         "武功深不可测,最可怕的是以其人之道,还治其人之身 .\n" );

	set("gender", "男性" );
        set("bellicosity", 100);
	set("no_clean_up",1);
	set("env/wimpy", 0);
        set("pills",3);

        set("age", 20+random(20));
        set("str", 25+random(15));
        set("int", 15+random(15));
        set("con", 15+random(15));
        set("dex", 15+random(15));

        i=1000+random(2000);
        set("max_gin", i);
        set("eff_gin", i);
        set("gin", i);
        i=1000+random(2000);
        set("max_kee", i);
        set("eff_kee", i);
        set("kee", i);
        i=1000+random(2000);
        set("max_sen", i);
        set("eff_sen", i);
        set("sen", i);
        set("max_atman", 300);
        set("atman", 300);
        i=500+random(2500);
        set("max_force", i);
        set("force", i);
        set("force_factor", 10+random(40));
        set("max_mana", 300);
        set("mana", 300);

        set("attitude","friendly");
        set("combat_exp", 100000+random(2000000));
        set("shen_type", 1);
        set("score", 1000000);

        set_skill("force", 50+random(1500)/10);
        set_skill("taiji-shengong", 50+random(1500)/10);
        set_skill("move", 50+random(1500)/10);
        set_skill("dodge", 50+random(1500)/10);
        set_skill("tiyunzong", 50+random(1500)/10);
        set_skill("cuff", 50+random(1500)/10);
        set_skill("taiji-quan", 50+random(1500)/10);
        set_skill("parry", 50+random(1500)/10);
        set_skill("sword", 50+random(1500)/10);
        set_skill("taiji-jian", 50+random(1500)/10);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set("chat_chance", 15);
        set("chat_msg", ({
                (: my_random_move :),
		HIW""+query("name")+"：谁要敢滥杀无辜，可要小心颈上人头。\n"NOR,
		(: my_random_move :),
		HIW""+query("name")+"：杀人偿命，欠债还钱；天网恢恢，疏而不漏。\n"NOR,
		(: my_random_move :),
		(: heal :),
        }) );

	setup();
        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/gangjian")->wield();
}

void init()
{
	object dest=this_player(),me=this_object();
	if(!is_fighting())
	{
		if(dest->query("end_anti_pk_time") && dest->query("mud_age") > dest->query("end_anti_pk_time"))
		{
			message_vision(HIW"$N对$n说道：官府对你的通缉已经结束，壮士身手不凡，还望好之为之。\n"NOR,me,dest);
			dest->delete("end_anti_pk_time");
			me->remove_killer(dest);
			dest->remove_killer(me);
			if (query_leader()==dest) me->set_leader(0);
			::init();
			return;
		}

		if(query("target")!=dest->query("id"))
		{
			if(dest->query("mud_age") < dest->query("end_anti_pk_time"))
			{
				remove_call_out("kill");
				call_out("kill",0,me,dest,1);
				dest->start_busy(2);
				return;
			}
			else if ( (dest->query("pk_point")-dest->query("pk_point_used")) >= 500)
			{
				remove_call_out("kill");
				call_out("kill",0,me,dest,2);
				dest->start_busy(2);
				return;
			}
		}

		if(query("target")==dest->query("id") 
			&& dest->query("mud_age") < dest->query("end_anti_pk_time"))
		{
			remove_call_out("kill");
			call_out("kill",0,me,dest,3);
			dest->start_busy(2);
			return ;
		}


	}
	::init();
	return;
}

int kill(object me,object dest,int how)
{
        switch( how)
	{
           case 1:  message_vision(HIR"$N对$n大喝一声：看你还能躲到哪里！\n"NOR,me,dest);
		    clone_skill(me,dest);
		    set("target",dest->query("id"));
                    break;
           case 2:  message_vision(HIR"$N对$n大喝一声：看你满身戾气，吾奉官府之命前来缉拿。\n"NOR,
				me,dest);
		    dest->add("pk_point_used",500);
		    dest->set("end_anti_pk_time",(dest->query("mud_age")+43200));
		    clone_skill(me,dest);
		    set("target",dest->query("id"));
		    break;
	   case 3:  message_vision(HIR"$N对$n嘿嘿笑道：你知道附骨之蚁吗？\n"NOR,me,dest);
		    break;
	}

	set("pursuering",1);
        set("pills",3);
	me->set_leader(dest);
        me->apply_condition("rest_time", 10);
	me->kill_ob(dest);
	dest->fight_ob(me);

	remove_call_out("checking_anti_pk");
	call_out("checking_anti_pk",1,dest); 	
        return 1;
}

int clone_skill(object me,object ob)
{
        mapping hp_status, skill_status;
        int i, *level, tmp;
	string *sname;

        seteuid( geteuid(me) );

        if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                for(i=0; i<sizeof(skill_status); i++) {
                    me->set_skill(sname[i],skill_status[sname[i]]);
                }
                level  = values(skill_status);
		level = sort_array(level,-1);
		i=sizeof(level);
	
		tmp = level[0];
		if(tmp == 0) tmp = 1;	
		me->set_skill("taiji-jian",tmp);
		if(i>1) me->set_skill("taiji-quan",level[1]);
		if(i>2) me->set_skill("tiyunzong",level[2]);
		if(i>3) me->set_skill("taiji-shengong",level[3]);
        }
	me->set_skill("move",2000);


/* copy entire dbase values */

        hp_status = ob->query_entire_dbase();

                me->set("str", hp_status["str"]);
                me->set("int", hp_status["int"]);
                me->set("con", hp_status["con"]);
                me->set("spi", hp_status["spi"]);

                me->set("max_kee",    3*hp_status["max_kee"]);
                me->set("eff_kee",    3*hp_status["max_kee"]);
                me->set("kee",        3*hp_status["max_kee"]);
                me->set("max_sen",  hp_status["max_sen"]);
                me->set("eff_sen",  hp_status["max_sen"]);
                me->set("sen",      hp_status["max_sen"]);
                me->set("max_gin",  hp_status["max_gin"]);
                me->set("eff_gin",  hp_status["max_gin"]);
                me->set("gin",      hp_status["max_gin"]);
                me->set("max_force", 3*hp_status["max_force"]);
                me->set("force",     3*hp_status["force"]);
                me->set("force_factor",     hp_status["force_factor"]*2);
                me->set("mana",      hp_status["mana"]);
                me->set("max_mana",  hp_status["max_mana"]);
                me->set("atman",     hp_status["atman"]);
                me->set("max_atman", hp_status["max_atman"]);
                me->set("combat_exp",hp_status["combat_exp"]+100000);

        return 1;
}

int checking_anti_pk(object dest)
{
	object ob,me=this_object();
        int my_max_qi;

        if ( (int)me->query_condition("rest_time" ) == 0 ){
		me->remove_killer(dest);
		dest->remove_killer(me);
		dest->add("end_anti_pk_time",-3600);
		message_vision(HIW"$N向后一跃，跳出战圈对$n说道：\n"
			+"不是我徇私枉法，壮士这副身手得来不易，这次放你一马，下次别撞到我的手上。\n"NOR,me,dest);
		me->set_leader(0);
		me->delete("pursuering");
		me->delete("target");
		return 1;
         }

        if (me->is_fighting()) {
	        my_max_qi  = me->query("max_kee");
                if ( (me->query("kee")*100 / my_max_qi) <= 70 && (int)query("pills"))
                    {  
			message_vision(HIY "$N从口袋摸出一粒皇上御赐的大内疗伤圣药吞了下去。\n" NOR,me);
	                set("eff_gin", query("max_gin"));
        	        set("eff_kee", query("max_kee"));
                	set("eff_sen", query("max_sen"));
               		set("gin", query("eff_gin"));
	                set("kee", query("eff_kee"));
        	        set("sen", query("eff_sen"));
                	add("pills", -1);
                     }
                        
                call_out("checking_anti_pk", 1,dest);
                return 1;
        }

     
	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	dest->name(1) )
	{
		dest->delete("end_anti_pk_time");
		me->set_leader(0);
		me->delete("target");
		me->delete("pursuering");
                CHANNEL_D->do_channel(me, "rumor",
			HIR""+me->name(1)+"对着"+ob->name(1)+"长叹道：为什么总有人要滥杀无辜呢？\n"NOR);
		return 1;
	}

	if( !present(dest, environment(me)) )
	{
		CHANNEL_D->do_channel(me, "chat",
			HIR""+dest->name(1)+"你这"+RANK_D->query_rude(dest)+",算你狠，下次别撞到我的手上。\n"NOR);
		me->set_leader(0);
		me->delete("target");
		me->delete("pursuering");
		me->remove_killer(dest);
	}

	return 1;
}

int my_random_move()
{
	mapping exits;
	string *dirs;

	if(query("pursuering")) return 0;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
	return 1;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 100");
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
