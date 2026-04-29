// revenger.c
// by zephyr
inherit NPC;
#include "/u/z/zephyr/randomname.h"
#include <ansi.h>

int give_bouns(object me);

void init();
void consider();
void heal();

void create()
{

   set_name(HIY"复仇者"NOR, ({ "revenger"}) );
   set("nickname", random(2) ? HIR"誓报师仇"NOR : HIR"悲愤欲绝"NOR);
   set("gender", "男性");
   set("long",
           "这是一位悲愤欲绝的复仇者，为报师门深仇，走遍天涯海角。誓杀仇人，不死不休！\n"
    );
 
	set("combat_exp", 500000);
	set("score", 200000);

	set("pursuer", 1);
	set("vendetta/authority", 1);
	set("bellicosity",1000);

	set("str", 60);
	set("int", 30);
    set("cor", 80);
    set("cps", 30);
    set("spi", 30);
	set("attitude", "peaceful");

	set("force", 4000);
    set("max_force", 2000);
    set("force_factor", 80);
    set("max_kee",4000);
 
 
 
    set_temp("apply/attack", 100);
    set_temp("apply/defense", 50);
    set_temp("apply/armor", 50);
 
    set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: consider :),
	}) );
	setup();
	remove_call_out("dest_npc");
	call_out("dest_npc",500);
 
 }
 
 
//复制武功，准备复仇
int revenge(object enemy, object master)
{
	mapping skill_status,master_skill_status,hp_status;
	int con,ran=random(50),n=0,max_lvl=0,i,lvl=0,m;
	int skill_con=0,t_hp,time,ran2,skill_lvl;
	object ob,weapon;
	string filename,dirname,*sname,type,timestr,msg,name,*str;

	seteuid(geteuid());

	set("waiting_target", enemy->query("id"));
	set("target_name", enemy->query("name"));
	set("family", master->query("family/family_name"));
	ran=random(50);
	switch(query("family"))
	{
		case "少林派": ran=0;break;
		case "茅山派"  : ran=0;break;
		case "晚月庄"  : ran=49;break;
		case "峨嵋派"  : ran=49;break;
	}


	//根据杀人者武功和自身武功确定复仇者武功级别
	con=enemy->query("killed_master");
	if (con>300)
		con=300;
	if (wizardp(enemy))
	{
		tell_object("已经杀过"+query("killed_master")+"个master了。\n");
	}
	if ( mapp(skill_status = enemy->query_skills()) ) //计算杀人者的等级最高的武功
	{
		sname = keys(skill_status);
		for(i=0; i<sizeof(skill_status); i++)
		{
			if(sname[i]=="force") continue;
			if(sname[i]=="literate") continue;
			if(sname[i]=="parry") continue;
			if(sname[i]=="dodge") continue;
			if(max_lvl<skill_status[sname[i]])
				max_lvl=skill_status[sname[i]];
		}
	}
	if(max_lvl<1) max_lvl=1;

	if (mapp(master_skill_status = master->query_skills()) ) //按师傅的武功种类设置对象武功
	{
		sname = keys(master_skill_status);
		for(i=0; i<sizeof(sname); i++)
		{
			skill_lvl=skill_status[sname[i]];
			if(skill_lvl>0)
			lvl=skill_lvl+(con*2)/10+random(11)-10;
			else
			lvl=max_lvl+(con*2)/10+random(11)-20;
			if(lvl<1) lvl=1;
			set_skill(sname[i],lvl + random(con)/5);
		}
	}
	set_skill("perception",150);
	if (query_skill("mysterrier",1)>200)
	{
		set_skill("mysterrier",200);	
	}
	if (query_skill("taiji-shengong",1)>300)
	{
		set_skill("taiji-shengong",300);	
	}
	if (query_skill("qinkun-danuoyi",1)>250)
	{
		set_skill("qinkun-danuoyi",250);	
	}
	if (query_skill("necromancy",1)>180)
	{
		set_skill("necromancy",180);	
	}
	if(mapp(skill_status=master->query_skill_map())) //enable 对象的武功
	{
		sname=keys(skill_status);
		for(i=0;i<sizeof(sname);i++)
			map_skill(sname[i],skill_status[sname[i]]);
	}

	if(mapp(skill_status=master->query_skill_prepare())) //prepare 
	{
		sname=keys(skill_status);
		for(i=0;i<sizeof(sname);i++)
			prepare_skill(sname[i],skill_status[sname[i]]);
	}

	if(objectp(weapon=master->query_temp("weapon")))
	{
		type=weapon->query("skill_type");
		carry_object("/obj/weapon/"+type)->wield();
		set("weapon_type",type);
	}
	else
	{
		//判断master carry_object()了什么物品
		filename=base_name(master);
		filename+=".c";
		filename=read_file(filename);
		str=explode(filename,";");
		for(i=0;i<sizeof(str);i++)
		{
			if(strsrch(str[i],"//")!=-1) continue ;
			if(strsrch(str[i],"carry_object")!=-1)
			{
				//将carry_object中的相对路径转变为绝对路径
				dirname=file_name(master);
				n=strsrch(dirname,"/",-1);
				//将__DIR__"替换成"绝对路径
				str[i]=replace_string(str[i],"__DIR__\"","\""+dirname[0..n]);
				n=strsrch(str[i],"(");
				m=strsrch(str[i],")");
				str[i]=str[i][n+2..m-2];
				weapon=new(str[i]);
				if(mapp(weapon->query("weapon_prop")))
				{
					type=weapon->query("skill_type");
					set("weapon_type",type);
					carry_object("/obj/weapon/"+type)->wield();
				}
				destruct(weapon);
			}
		}
	}
	carry_object("/obj/cloth/cloth")->wear();

	//根据杀人者情况设置对象的hp参数
	t_hp=100+random(11);
	hp_status = enemy->query_entire_dbase();
	set("str", hp_status["str"]+random(con)/5);
	set("int", hp_status["int"]+random(con)/5);
	set("con", hp_status["con"]+random(con)/5);
	set("kar", hp_status["kar"]+random(con)/5);
	set("cor", hp_status["cor"]+random(con)/5);
	set("cps", hp_status["cps"]+random(con)/5);
	set("bln", hp_status["bln"]+random(con)/5);
	set("per", hp_status["per"]+random(con)/5);
	set("spi", hp_status["spi"]+random(con)/5);
	set("vis", hp_status["vis"]+random(con)/5);
	set("max_kee",10*t_hp*hp_status["max_kee"]/100);
	set("eff_kee",10*t_hp*hp_status["max_kee"]/100);
	set("kee",    10*t_hp*hp_status["max_kee"]/100);

	if (query("max_kee")<5000)
	set("max_kee",5000);
	if (query("eff_kee")<5000)
	set("eff_kee",5000);
	if (query("kee")<5000)
	set("kee",5000);

	if (query("max_kee")>50000)
	set("max_kee",50000);
	if (query("eff_kee")>50000)
	set("eff_kee",50000);
	if (query("kee")>50000)
	set("kee",50000);

	set("max_gin",5*t_hp*hp_status["max_gin"]/100);
	set("eff_gin",5*t_hp*hp_status["max_gin"]/100);
	set("gin",    5*t_hp*hp_status["max_gin"]/100);
	set("max_sen",5*t_hp*hp_status["max_sen"]/100);
	set("eff_sen",5*t_hp*hp_status["max_sen"]/100);
	set("sen",    5*t_hp*hp_status["max_sen"]/100);
	set("max_force",10*t_hp*hp_status["max_force"]/100);
	if(query("max_force")>20000)
		set("max_force",20000);
	set("force",    query("max_force")*2);
	set("max_atman",t_hp*hp_status["max_atman"]/100);
	set("atman",query("max_atman")*2);
	set("max_mana",t_hp*hp_status["max_mana"]/100);
	set("mana",query("max_mana")*2);
    set("force_factor",50+random(con)+hp_status["force_factor"]);

	if (query("force_factor")<100)
	{
		set("force_factor",100);
	}
	if (query("force_factor")>200)
	{
		set("force_factor",200);
	}

	set("mana_factor",master->query("mana_factor"));
	set("combat_exp",t_hp*hp_status["combat_exp"]/100);
	
	if (query("combat_exp")<0 || query("combat_exp")>30000000)
	{
		set("combat_exp",30000000);
	}

	set_temp("apply/armor",t_hp*2+500+con*5);
	set_temp("apply/armor_vs_force",t_hp*2+500+con*5);
	set_temp("apply/armor_vs_spells",(t_hp*2+500)/4);
	set_temp("apply/damage",random(200)+random(con/8));

	set_temp("apply/attack",20+random(30)+random(con/8));
	set_temp("apply/defense",random(t_hp)+random(con/5));
	set_temp("apply/dodge",random(t_hp)+con);
	
	if(query("family")=="茅山派")
	{
		set_temp("apply/defense",con+100);

		set("mana_factor",random(con)+master->query("mana_factor"));

		if (query("max_mana")<3000)
		{
			set("max_mana",3000);
			set("mana",6000);
		}
		if (query("max_mana")>10000)
		{
			set("max_mana",10000);
			set("mana",20000);
		}
		if(query("mana_factor")<50)
		{
			set("mana_factor",50+random(50));
		}
		if(query("mana_factor")>100)
		{
			set("mana_factor",100);
		}
		if(query_temp("apply/defense")>1000)
		{
			set_temp("apply/defense",1000);
		}
	}
	if(master->query("shen")>=0)
	{
		if(ran>=25)
		{
			ran2=random(sizeof(ran_name2));
			sname=explode(ran_id2[ran2]," "); 
			set_name(ran_name2[ran2],({ran_id2[ran2],sname[0],sname[1]}));
			set("gender","女性");
			set("title",query("family")+NOR"大师姐");
			set("age",25);
		}
		else
		{
			ran2=random(sizeof(ran_name1));
			sname=explode(ran_id1[ran2]," "); 
			set_name(ran_name1[ran2],({ran_id1[ran2],sname[0],sname[1]}));
			set("gender","男性");
			set("title",query("family")+NOR"大师兄");
			set("age",41);
		}
	}

	else
	{
		if(ran>=25)
		{
			ran2=random(sizeof(ran_name2));
			sname=explode(ran_id2[ran2]," "); 
			set_name(ran_name2[ran2],({ran_id2[ran2],sname[0],sname[1]}));
			set("gender","女性");
			set("title",query("family")+NOR"大师姐");
			set("age",25);
		}
		else
		{
			ran2=random(sizeof(ran_name1));
			sname=explode(ran_id1[ran2]," "); 
			set_name(ran_name1[ran2],({ran_id1[ran2],sname[0],sname[1]}));
			set("gender","男性");
			set("title",query("family")+NOR"大师兄");
			set("age",41);
		}
	}

   call_out("do_chase", random(200), this_object());
   return 1;
}
	

int do_chase(object me)
{
   
	object dest, *ob;
	int i;

   dest = find_player(me->query("waiting_target"));
   if( !objectp(dest) || !environment(dest) )      
   {
           call_out("waiting", 0, me);
           return 1;
   }

	ob=users();
	for(i=0;i<sizeof(ob);i++)
	{
		if( ob[i]->query("family/family_name")==me->query("family/family_name"))
			continue;
		ob[i]=0;
	}
	ob -= ({0});
	ob -= ({me});
	ob += ({me});

	message("menpai", HIW "【"+me->query("family/family_name")+"】" 
		+ me->name(1) + "：师兄弟姐妹们，我已经打听到" + dest->name() + "现在正躲藏在"+ environment(dest)->query("short") +HIW"，大家随我一起去杀了这厮，替我师门报仇雪恨！\n" NOR, ob);

   me->move(environment(dest));
   message_vision(CYN"\n$N杀气腾腾地走了过来。\n" NOR, me);

   me->set_leader(dest);
   command("look " + dest->query("id"));
   if ( !environment(me)->query("no_fight"))
   {
		call_out("do_kill", 0, me, dest);
		return 1;
   }
   else
   {
		call_out("waiting", 0, me);
		return 1;
   }

   return 1;
}


int do_kill(object me, object dest)
{
   if( objectp(dest) && !environment(me)->query("no_fight"))
   {
		message_vision(HIR "$N喊道： 呔！兀那" + RANK_D->query_rude(dest) + "，你竟然杀了我的师父，今日我就要报此血海深仇！\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);
		call_out("checking", 0,  me);   
   }
   else call_out("waiting", 1, me);     
   return 1;
}


int waiting(object me)
{
   object dest;
   dest = find_player(me->query("waiting_target"));
   if ( objectp(dest) )
   {
           if (dest->is_ghost())
           {
                  me->delete("waiting_target");
                   call_out("do_back", 1, me);
                   return 1;
           }else if (me->is_fighting() && present(dest, environment(me)))
           {
                   call_out("checking", 0, me);
                   return 1;
           }else if (living(me) && !environment(dest)->query("no_fight"))
           {
                   call_out("do_chase", 0, me);
                   return 1;
           }
   }               
   remove_call_out("waiting");
   call_out("waiting", 60, me);
    return 1;
}



int checking(object me)
{
   object ob;

   if (me->is_fighting()) 
   {
           call_out("checking", 1, me);
   return 1;
   }
   if( objectp(ob = present("corpse", environment(me))) && ob->query("victim_name") == me->query("target_name") )
   {
	   	command("chat 谁敢再来欺我"+me->query("family")+"，"+me->query("target_name")+"的下场就是榜样！！！");
		me->delete("waiting_target");
		call_out("do_back", 1, me);
   return 1;
   }
   call_out("waiting", 0, me);
   return 1;
}

void chat()
{
	object me,*enemy,victim;
	int fighting,i, all;

	me = this_object();
	if( !environment(me) ) return 0;
	fighting = me->is_fighting();

	if(fighting && random(100)>95)
	{
		enemy = me->query_enemy();
		all = sizeof(enemy);

		for(i=0;i<all;i++)
		{
			victim = enemy[i];
			if ( victim->query_skill("taiji-shengong",1)>120 || victim->query_skill("iron-cloth",1)>200 || victim->query_skill("jiuyang-shengong",1)>200 || victim->query("eff_kee")>2500 )
			{
				message_vision(CYN"\n"+name()+"大吼一声，使出了"+query("family")+"绝技，一道青丝状的真气透体而出。\n"+victim->name()+RED"防备不及，正中前胸，只觉一道火辣辣的真气直冲胸口，一个禁受不住，哇的一声喷出一口鲜血！\n"NOR, environment());
				victim->receive_wound("kee", random(200 + victim->query_skill("taiji-shengong",1)/2 + victim->query_skill("jiuyang-shengong",1)/3 + victim->query_skill("iron-cloth",1) ), me);
				COMBAT_D->report_status(me,victim,1);
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

int do_back(object me)
{
	destruct(me);
	return 1;
}              


void consider()
{
	object* all,who,me,weapon;
	int i,flag=0;
	string type;

	me=this_object();
	all=all_inventory(environment(me)); 
	for(i=0;i<sizeof(all);i++)
	{
		if(all[i]->is_killing(me)||all[i]->is_fighting(me))
			who=all[i];
	}
	if(!objectp(query_temp("weapon")))
	{
		if(stringp(type=query("weapon_type",type)))
		{
			weapon=new("/obj/weapon/"+type);
			weapon->move(this_object());
			command("wield "+weapon->query("id"));
		}
	}
	if(objectp(who) && random(100)<5)
	{
			switch(query("family"))
			{
			case "封山剑派": command("perform sword.counterattack");break;
			case "桃花岛"  : command("exert tanzhi "+who->query("id")); break;
			case "步玄派"  : command("perform dodge.hasten");break; 
			}
	}
	if(query("family")=="茅山派")
	{
		command("cast manashield");
		if ( random(100)>50 )
			command("cast blockweb on "+who->query("id"));
		command("cast feeblebolt on "+who->query("id"));
	}

	heal();
}

void dest_npc()
{
	command("chat 今日暂且把你的小命寄存在我这里，如若再来侵犯我"+query("family")+"...哼！！！");
	tell_room(environment(this_object()),"\n"+query("name") + "哼了一声，转身一个鹞子翻身，如飞燕般消失在远处。\n\n");
	destruct(this_object());
}

void heal()
{
	object ob=this_object();
	if (ob->query("kee") < ob->query("eff_kee")*60/100)
	{
		command("exert recover");
		return;
	}
	if (ob->query("gin") < ob->query("eff_gin")*60/100)
		command("exert regenerate");

	if (ob->query("sen") < ob->query("eff_sen")*60/100)
		command("exert refresh");
	return;
}

void die()
{
	object me,killer, *ob;
	string str;
	int i;
    me=this_object();
	if(!objectp(killer = query_temp("last_damage_from")) )
	{
		::die();
		return;
	}
    if(query("waiting_target")!=killer->query("id"))
	{
		::die();
		return;
	}

	ob=users();
	for(i=0;i<sizeof(ob);i++)
	{
		if( ob[i]->query("family/family_name")==me->query("family/family_name"))
			continue;
		ob[i]=0;
	}
	ob -= ({0});
	ob -= ({me});
	ob += ({me});

	message("menpai", HIW "【"+me->query("family/family_name")+"】" 
		+ me->name(1) + "：可恶！" + killer->name() + HIW"这厮果然凶狠，我看来是不成了，要先走一步了。你们暂且避其锋芒，好好练功，早晚有一日一定要替我师门报仇雪恨啊！\n" NOR, ob);
	tell_room(environment(killer),HIR"\n"+query("name")+"奋起最后一点力气，合身扑上，誓与敌人同归于尽，使出了"+ query("family")+"绝招。狠辣异常！\n");
	if ( random(killer->query("combat_exp")/10000) < 100 )
	{
		tell_room(environment(killer),HIR"\n"+killer->name()+"大吃一惊，已然没有闪避的余地，被"+name()+"重重击中！\n");
		killer->set("eff_kee",killer->query("eff_kee")/2);
		killer->set("kee",killer->query("kee")/2);
		COMBAT_D->report_status(me,killer,1);
	}
	else tell_room(environment(killer),HIR"\n"+killer->name()+"大吃一惊，慌忙之中倒地一滚，于千钧一发之际躲过了这致命一击！\n");
	tell_room(environment(killer),HIR"\n"+query("name")+"长叹道：可恨哪！\n"NOR);
	tell_room(environment(killer),"\n"+query("name")+"死了。\n");
	COMBAT_D->killer_reward(killer, me);
		
	if ( query("waiting_target") == killer->query("id") )
		give_bouns(killer);

	destruct(this_object());
}

int give_bouns(object me)
{
	int force,wlshw,money;
	object ob;
	string msg;


	if(me->query("force")<me->query("max_force"))
		me->set("force",me->query("max_force"));
	msg="你从复仇者的尸体里找寻了一会发现了：\n";

	if(random(100)>90)
	{
		ob=new("/d/moyu/obj/nineflower");
		ob->move(me);
		msg+="一粒"+ob->query("name")+"\n";
	}
	if(random(100)>10)
	{
		money=2+random(5);
		if (random(100)<2)
		{
			money*=50;
		}
		ob=new("/obj/money/gold");
		ob->set_amount(money);
		ob->move(me);
		msg+=chinese_number(money)+"两黄金\n";
	}

	if(random(100)<2)
   {
		ob=new("/d/xizang/obj/sun.c");
		ob->move(me);
		msg+="一面"+ob->query("name")+"\n";
   }

   if(random(100)<2)
   {
		ob=new("/d/xueshan/npc/obj/xarmor.c");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }

   if(random(100)<2)
   {
		ob=new("/d/qiankun/obj/nineflower.c");
		ob->move(me);
		ob=new("/d/qiankun/obj/nineflower.c");
		ob->move(me);
		msg+="两支"+ob->query("name")+"\n";
   }

	tell_object(me,HIG+msg+NOR);
	return 1;
}

int killed_enemy(object ob)
{
	command("chat 象"+ob->name()+"这样的"+RANK_D->query_rude(ob)+"，竟然接连杀害"+chinese_number(ob->query("killed_master"))+"门派的师尊，真是人神共愤！");
	command("chat 如今死在我"+query("family")+"手中，也算是为武林除了一害！");
	ob->set("killed_master",0);

}
