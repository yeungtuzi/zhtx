// revenger.c
// by zephyr
inherit NPC;
#include "/u/z/zephyr/randomname.h"
#include <ansi.h>

int give_bouns(object me);

void init();
void consider();
void heal();

int random_go();

void create()
{

   set_name(HIY"门派叛徒"NOR, ({ "traitor"}) );
   set("nickname", random(2) ? HIR"无法无天"NOR : HIR"人不为己，天诛地灭"NOR);
   set("gender", "男性");
   set("long",
           "这是一个叛徒，武功十分高强。据说是为了一些宝贝或者秘笈之类的东西，杀了自己的师尊叛逃出来的。\n"
    );
	
	set("random_move",0);

	set("traitor",1);
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

    set("chat_chance",80);
	set("chat_msg", ({
               (: random_go :)
        }) );
 
    set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: consider :),
	}) );
	setup();
	remove_call_out("dest_npc");
	call_out("dest_npc",1000);
 
 }

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

 
//复制武功，叛出师门
int betray(object master)
{
	mapping skill_status,master_skill_status,hp_status;
	int con,ran=random(50),n=0,max_lvl=0,i,lvl=0,m;
	int skill_con=0,t_hp,time,ran2,skill_lvl;
	object ob,weapon;
	string filename,dirname,*sname,type,timestr,msg,name,*str;

	seteuid(geteuid());

	set("waiting_target", master);
	set("target_name", master->query("name"));
	set("family", master->query("family/family_name"));
	ran=random(50);
	switch(query("family"))
	{
		case "少林派": ran=0;break;
		case "茅山派"  : ran=0;break;
		case "晚月庄"  : ran=49;break;
		case "峨嵋派"  : ran=49;break;
	}


	//随机确定叛徒的武功级别，当然比master要高得多
	con=random(100);
	if ( mapp(skill_status = master->query_skills()) ) //计算杀人者的等级最高的武功
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

	if (mapp(master_skill_status = master->query_skills()) ) //按master的武功种类设置对象武功
	{
		sname = keys(master_skill_status);
		for(i=0; i<sizeof(sname); i++)
		{
			skill_lvl=skill_status[sname[i]];
			if(skill_lvl>0)
			lvl=skill_lvl+(con*2)/5+random(11)-10;
			else
			lvl=max_lvl+(con*2)/5+random(11)-20;
			if(lvl<1) lvl=1;
			set_skill(sname[i],lvl + random(con)/10);
		}
	}
	set_skill("perception",150);
	if (query_skill("mysterrier",1)>400)
	{
		set_skill("mysterrier",400);	
	}
	if (query_skill("taiji-shengong",1)>400)
	{
		set_skill("taiji-shengong",400);	
	}
	if (query_skill("qinkun-danuoyi",1)>400)
	{
		set_skill("qinkun-danuoyi",400);	
	}
	if (query_skill("necromancy",1)>150)
	{
		set_skill("necromancy",150);	
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

	//设置对象的hp参数，当然比较高的了。
	t_hp=100+random(11);
	hp_status = master->query_entire_dbase();
	set("str", hp_status["str"]+random(con)/5);
	set("int", hp_status["int"]+random(con)/5);
	set("con", hp_status["con"]+random(con)/5);
	set("kar", hp_status["kar"]+random(con)/5);
	set("cor", hp_status["cor"]+random(con)/5);
	set("cps", hp_status["cps"]+random(con)/5);
	set("bln", hp_status["bln"]+random(con)/5);
	set("per", hp_status["per"]);
	set("spi", hp_status["spi"]+random(con)/5);
	set("vis", hp_status["vis"]+random(con)/5);
	set("max_kee",4*t_hp*hp_status["max_kee"]/200);
	set("eff_kee",4*t_hp*hp_status["max_kee"]/200);
	set("kee",    4*t_hp*hp_status["max_kee"]/200);

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
	set("max_force",5*t_hp*hp_status["max_force"]/150);
	if(query("max_force")>15000)
		set("max_force",15000);
	set("force",    query("max_force")*2);
	set("max_atman",t_hp*hp_status["max_atman"]/100);
	set("atman",query("max_atman")*2);
	set("max_mana",t_hp*hp_status["max_mana"]/100);
	set("mana",query("max_mana")*2);
    set("force_factor",150+random(con)+hp_status["force_factor"]);

	if (query("force_factor")<100)
	{
		set("force_factor",100);
	}
	if (query("force_factor")>400)
	{
		set("force_factor",400);
	}

	set("mana_factor",master->query("mana_factor"));
	set("combat_exp",t_hp*hp_status["combat_exp"]/100);
	
	if (query("combat_exp")<0 || query("combat_exp")>50000000)
	{
		set("combat_exp",50000000);
	}

	set_temp("apply/armor",t_hp*2+500+con);
	set_temp("apply/armor_vs_force",t_hp*2+500+con);
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
		if(query("mana_factor")>300)
		{
			set("mana_factor",300);
		}
		if(query_temp("apply/defense")>1000)
		{
			set_temp("apply/defense",1000);
		}
	}
	if(master->query("shen")>=0)
	{
		//set shen to prevent bug resulted from expel code
		set("shen",50000);
		if(ran>=25)
		{
			ran2=random(sizeof(ran_name2));
			sname=explode(ran_id2[ran2]," "); 
			set_name(ran_name2[ran2],({ran_id2[ran2],sname[0],sname[1]}));
			set("gender","女性");
			set("title",query("family")+NOR"叛徒");
			set("age",25);
		}
		else
		{
			ran2=random(sizeof(ran_name1));
			sname=explode(ran_id1[ran2]," "); 
			set_name(ran_name1[ran2],({ran_id1[ran2],sname[0],sname[1]}));
			set("gender","男性");
			set("title",query("family")+NOR"叛徒");
			set("age",41);
		}
	}

	else
	{
		set("shen",-50000);
		if(ran>=25)
		{
			ran2=random(sizeof(ran_name2));
			sname=explode(ran_id2[ran2]," "); 
			set_name(ran_name2[ran2],({ran_id2[ran2],sname[0],sname[1]}));
			set("gender","女性");
			set("title",query("family")+NOR"叛徒");
			set("age",25);
		}
		else
		{
			ran2=random(sizeof(ran_name1));
			sname=explode(ran_id1[ran2]," "); 
			set_name(ran_name1[ran2],({ran_id1[ran2],sname[0],sname[1]}));
			set("gender","男性");
			set("title",query("family")+NOR"叛徒");
			set("age",41);
		}
	}

   call_out("do_chase", random(20), this_object());
   return 1;
}
	

int do_chase(object me)
{
   
	object dest, *ob;
	int i;

   dest = me->query("waiting_target");
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
		+ me->name(1) + "：你们这些假仁假义的家伙，" + dest->name() + "一直在我门作威作福，把我等当牛当马使唤。\n如今我武功既成，宝物在手，再也不须忌惮任何人，今天我就要杀了这个家伙，叛出师门！\n" NOR, ob);


   if ( !environment(dest)->query("no_fight") )
   {
		call_out("do_kill", 1, me, dest);
   }
   else
   {
		call_out("waiting", 1, me);
   }

   message_vision(CYN""+name()+"杀气腾腾地走了过来。\n" NOR, dest);
   move(environment(dest));
   return 1;
}


int do_kill(object me, object dest)
{
   if( objectp(dest) && !environment(me)->query("no_fight"))
   {
		message_vision(HIR "$N冲着"+dest->name()+"喊道： 你这个" + RANK_D->query_rude(dest) + "，整日作威作福，今天我就要杀了你，从今以后再也不用受你的气！\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->kill_ob(me);
		call_out("checking", 0,  me);   
   }
   else call_out("waiting", 1, me);     
   return 1;
}


int waiting(object me)
{
   object dest;
   dest = me->query("waiting_target");
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
	int i;
	/*if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
		return 1;
	}
	*/
	if( objectp(ob = present("corpse", environment(me))) && ob->query("victim_name") == me->query("target_name") )
	{
	   	command("chat 今日我武功已成，宝物在手，再也不惧怕任何人了！");
	   	command("chat 哈哈哈哈哈哈哈哈哈哈哈！！！！");
		me->set("random_move",1);
		me->delete("waiting_target");
		me->set("random_move",1);
		call_out("do_back", 1, me);
		return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}

void chat()
{
	object me,*enemy,victim, *inv;
	int fighting,i, j, all;

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
			if ( victim->query_skill("taiji-shengong",1)>120 || victim->query_skill("iron-cloth",1)>200 || victim->query_skill("jiuyang-shengong",1)>200 || victim->query("eff_kee")>1500 )
			{
				message_vision(CYN"\n"+name()+"大吼一声，指尖一道青丝状的真气透体而出，竟然已经练成了以无形之气伤人之功！\n"+victim->name()+RED"防备不及，正中前胸，只觉一道火辣辣的真气直冲胸口，一个禁受不住，哇的一声喷出一口鲜血！\n"NOR, environment());
				victim->receive_wound("kee", random(200 + victim->query_skill("taiji-shengong",1)/2 + victim->query_skill("jiuyang-shengong",1)/3 + victim->query_skill("iron-cloth",1) ), me);
				COMBAT_D->report_status(me,victim,1);
			}
		}
	}
/*
	inv = all_inventory(environment(me));
	j = sizeof(inv);
	while(j--)
	{
		if( inv[j]->query("family/family_name") == query("family/family_name") && !inv[j]->query_temp("being_killed_by_traitor") ) 
		{
			if ( inv[j]->query("name") == this_object() )
				continue;
			if ( random( inv[j]->query("combat_exp") ) < query("combat_exp") &&  !inv[j]->query("name")==this_object()->query("name") )
			{
				if ( ! userp( inv[j] ) )
					command("say 看你年龄还小，老子今天发善心，放你一马！趁早离开本门，到其他门派去吧！");

				else	
				{
					kill_ob(inv[j]);
					command("say 老子大小通杀！免得你以后来找我寻仇！");
				}
			}
			else 
			{
				kill_ob(inv[j]);
				inv[j]->kill_ob(me);
				command("say 去你的，老子今天一不做二不休，把你们全杀光！");
			}

			if ( userp(inv[j]) )
				inv[j]->set_temp("being_killed_by_traitor",1);

			if ( inv[j]==query("waiting_target") )
			{
				kill_ob(inv[j]);
				inv[j]->kill_ob(this_object());
			}
		}
	}
*/	
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
	object ob;
	remove_call_out("dest_npc");
	call_out("dest_npc",500);
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
	if(query("family")=="明教")
	{
		command("exert jiuyang-shield");
	}

	heal();
}

void dest_npc()
{
	tell_room(environment(this_object()),"\n"+query("name") + "哼了一声：”"+RANK_D->query_self_rude(this_object())+"可没时间和你们周旋了，我去也！“言罢转身一个鹞子翻身，如飞燕般消失在远处。\n\n");
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
		+ me->name(1) + "：可恨！" + killer->name() + HIW"你们这些老顽固，如今一定要至我于死地，我死也要拉个垫背的！\n" NOR, ob);
	tell_room(environment(killer),HIR"\n"+query("name")+"疯了一样直直的跃起冲向敌人，誓与敌人同归于尽，使出了"+ query("family")+"绝招。狠辣异常！\n");
	if ( random(2) )
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
		
	if ( killer->query("family/family_name")==me->query("family/family_name") )
	{
		killer->add("faith",random(100) );
		tell_object(killer,CYN"你为师门报了血海深仇，手刃叛徒，你的师门忠诚度增加了！\n"NOR);
	}
	give_bouns(killer);

	destruct(this_object());
}

int give_bouns(object me)
{
	int faith, pot,exp,force,wlshw,money;
	object ob;
	string msg;
	
	msg="你被奖励了：\n";
	exp = random(query("combat_exp")/1000) + me->query("kar")*50;
	pot = random(query("combat_exp")/3000) + me->query("kar")*30;
	if (exp>10000)
	{
		exp=10000;
	}
	if (pot>5000)
	{
		pot=5000;
	}
	if (exp<1000)
	{
		exp=1000;
	}
	if (pot<500)
	{
		pot=500;
	}
	me->add("combat_exp",exp);
	msg+=chinese_number(exp)+"点实战经验\n";

	me->add("potential",pot);
	msg+=chinese_number(pot)+"点潜能\n";
   
   if(random(100)<50 && wlshw=random(3))
   {
	   me->add("wlshw", wlshw);
		msg+=chinese_number(wlshw)+"点武林声望。\n";
   }



	msg+="你从叛徒的尸体里找寻了一会发现了：\n";

	if(random(100)<100)
	{
		ob=new("/d/moyu/obj/nineflower");
		ob->move(me);
		msg+="一粒"+ob->query("name")+"\n";
	}
	if(random(100)<90)
	{
		ob=new("/d/moyu/swamp/treasure/guo");
		ob->move(me);
		msg+="一颗"+ob->query("name")+"\n";
	}

	if(random(100)<90)
	{
		money=2+random(5);
		if (random(100)<5)
		{
			money*=50;
		}
		ob=new("/obj/money/gold");
		ob->set_amount(money);
		ob->move(me);
		msg+=chinese_number(money)+"两黄金\n";
	}

	if(random(100)<5)
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

   if(random(100)<5)
   {
		ob=new("/d/qiankun/obj/nineflower.c");
		ob->move(me);
		ob=new("/d/qiankun/obj/nineflower.c");
		ob->move(me);
		msg+="两支"+ob->query("name")+"\n";
   }


   if(random(1000)<2 && me->query("bingqipu_success") )
   {
		ob=new("/u/z/zephyr/gil_amulet.c");
		ob->move(me);
		msg+="一册"+ob->query("name")+"\n";
   }

   if(random(100)<2)
   {
		ob=new("u/m/masterall/obj/xyring");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }

   if(random(100)<2)
   {
		ob=new("d/xanadu/treasure/casket");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }

   if(random(100)<5)
   {
		ob=new("/class/fighter/dragon_armor");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }


   if(random(100)<2)
   {
		ob=new("/d/xueshan/npc/obj/xsword");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }


   if(random(100)<2)
   {
		ob=new("/d/xueshan/npc/obj/xblade");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }


   if(random(100)<2)
   {
		ob=new("/d/xueshan/npc/obj/xwhip");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }


   if(random(100)<5)
   {
		ob=new("/d/xueshan/npc/obj/fcloth");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }


   if(random(100)<5)
   {
		ob=new("/d/xueshan/npc/obj/guo1");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }

   if(random(100)<5)
   {
		ob=new("/d/xueshan/npc/obj/guo2");
		ob->move(me);
		msg+="一件"+ob->query("name")+"\n";
   }


	tell_object(me,HIG+msg+NOR);
	return 1;
}

int killed_enemy(object ob)
{
	if (ob->query("name")==query("target_name"))
	{
		command("chat "+ob->name()+"啊"+ob->name()+"，你这"+RANK_D->query_rude(ob)+"，也会有今天！！");
	}
	else command("chat 象"+ob->name()+"这样的"+RANK_D->query_rude(ob)+"，也敢来向我挑衅，真的是不知死活！");
	command("chat "+RANK_D->query_self_rude(this_object())+"自己的师父也都杀了，还怕谁不成，不怕死的，尽管来吧！！");
	this_object()->set("random_move",1);

}

int random_go()
{
	mapping exits;
	string *dirs;
	if(is_fighting()) return 0;
	if(!query("random_move")) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}
int accept_fight(object ob)
{
	message_vision(RED"\n$N哼了一声：找死！\n"NOR,this_object());      
	kill_ob(ob);
	return 1;
}

void greeting(object ob)
{
        object me, room1;
        if( !ob || !objectp(ob) ) return;
        me = this_object();
        room1 = environment(me);


        if(ob->query("traitor")) return 0;
		/*if(!userp(ob))
		{
			me->set_leader(ob);
			kill_ob(ob);
			ob->kill_ob(me);
		}
		*/
		if (ob->query("family/family_name")==query("family/family_name") )
		{
			if(!userp(ob) )
			{
				command("say 去你的，"+RANK_D->query_self_rude(this_object())+"今天一不做二不休，把你们全杀光！");
				me->set_leader(ob);
				kill_ob(ob);
				ob->kill_ob(me);
			}
			else 
			{
				if (  random( ob->query("combat_exp"))  < query("combat_exp")  )
					command("say 看你年龄还小，"+RANK_D->query_self_rude(this_object())+"今天发善心，放你一马！趁早离开本门，到其他门派去吧！");
				else	
				{
					command("say "+RANK_D->query_self_rude(this_object())+"大小通杀！免得你以后来找我寻仇！");
					me->set_leader(ob);
					kill_ob(ob);
					ob->kill_ob(me);
				}
			}
		}
		else return;
}

