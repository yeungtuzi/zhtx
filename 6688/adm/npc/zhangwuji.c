//zhangwuji.c       
// by yeung

#define MAXNUMBER 20

#include <ansi.h>

inherit F_MASTER;
inherit "/u/z/zephyr/revengenpc.c";
inherit F_QUEST;
inherit "/feature/challenge";

mixed winer=0,fighter=0,fighter1=0;
object winerroom,fighterroom,fighter1room;
string *group1=({}),*group2=({});
string *list=({});
int over;

int selectplayer(int);
int seekplayer(mixed);
int race();
int bonus(object);
int full(mixed);
void greeting(object ob);
void re_rank(object ob);
string ask_me();
void check_time();

void create()
{
	set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
	set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
    	set("title","明教教主"NOR);
	set("gender", "男性");
    	set("age", 20);
	set("shen_type",1);
    	set("attitude", "friendly");

    	set("str", 80);
    	set("int", 50);
    	set("con", 50);
    	set("dex", 50);  
    	set("cor", 100);
	set("per", 30);

    	set("kee", 5000);
    	set("max_kee", 5000);
    	set("gin", 500);
    	set("max_gin", 500);
    	set("sen",500);
    	set("max_sen",500);
    	set("force", 9999);
    	set("max_force", 5000);
    	set("force_factor", 200);

    	set("combat_exp", 5000000);
    	set("score", 100000);
	set_temp("apply/attack",50);
    	set_temp("apply/defense",50);

    
    	set_skill("force", 200);
    	set_skill("parry", 220);
	set_skill("hand",200);
	set_skill("cuff",150);
	set_skill("iron-cloth",200);
	set_skill("sword",200);

	set_skill("jiuyang-shengong", 200);
	set_skill("qiankun-danuoyi", 220);
  	set_skill("shenghuo-shengong",200);
	set_skill("qishang-quan",150);
        set_skill("yueying-wubu",180);
        set_skill("dodge",180);
        map_skill("dodge", "yueying-wubu"); 

	map_skill("force", "jiuyang-shengong");
	map_skill("iron-cloth", "jiuyang-shengong");
	map_skill("sword", "shenghuo-shengong");
	map_skill("cuff", "qishang-quan");	
	map_skill("parry", "qiankun-danuoyi");
	map_skill("hand", "shenghuo-shengong");	

	prepare_skill("hand", "shenghuo-shengong");

    	create_family("明教",34,"教主");

        set("inquiry", ([
                "掌教弟子" : (: ask_me :),
                "乾坤大挪移" : (: ask_me :),
                "演武大会" : (: ask_me :),
        ]));

	setup();
	carry_object("/class/mingjiao/obj/skysword")->wield();
	carry_object("/class/mingjiao/obj/goldpao")->wear();	
	add_money("gold",50);                               

}

void reset()
{
//	check_time();
}          

void init()
{
	object ob,sword;
		
        add_action("give_quest", "quest");
	add_action("do_manual_start","start");
	add_action("do_list","list");
        //add_action("do_halt", "halt");
	add_action("do_study","study");
	add_action("do_practice","practice");
	add_action("do_update","update");
        add_action("do_poison","poison");
	add_action("do_play","play");
//	add_action("do_exert","exert");

	::init();
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	mapping ob_fam;

	if(!ob || environment(ob)!=environment()) return;

        if ((ob_fam = ob->query("family")) && ob_fam["family_name"] == "明教")
	{
		//re_rank(ob);
		return;
	}
	if((int)ob->query("shen")<-500000)
	{
		command("say " + HIR"邪教妖魔，竟敢到我明教来撒野，看招！！！"NOR);
		command("wield yitian jian");
		kill_ob(ob);
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say 魔从心起，于武学不利，其道必诛，劝君放下屠刀，立地成佛.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say 这位朋友，人行江湖，言行当正，切务走进邪魔歪道.");
	}
	else if((int)ob->query("shen")<100)
	{
		command("say 光明正道任人走，劝君多加保重.");
	}
	else if((int)ob->query("shen")>1000000)
	{
		command("say 大侠在上，受无忌一礼，大侠它日必为武林翘楚.");
	}
	return;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	// 2026-04-30: unused variable commented out
	// mapping my_fam  = me->query("family");

	string name, new_name;

        if ( ob->query("betrayer") )
	{
		command("shake");
                command("say 我不收背叛师门，不忠不义之徒。");
		return;
	}

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")
	{
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
		return;
	}

	if( ob->query_skill("moni-xinfa",1) < 120 )
		return notify_fail("真可惜，你的修为不够，暂时还不能拜师。\n");


	if((int)ob->query_int()<30)
	{
		command("say 你的悟性太低了，不适合学习我的功夫。");
		return 0;
	}
	if((string)ob->query("gender")=="无性")
	{
		command("say 以你的身体状况，习我功夫恐将走火如魔。");
		return 0;
	}
   if((string)ob->query("gender")=="女性")
   {
           command("say 我的功夫不适合女性修习，你还是去拜敏敏吧！");
          return 0;
   }


        if((int)ob->query("shen") <= 5000000)
	{
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return 0;
	}
	command("say 好，我就收下你了");
	command("say 再接再砺！");
        command("say 恭喜你荣任明教光明圣使！");
	command("recruit " + ob->query("id"));
	ob->set("title","明教"+GRN"光明使者"NOR);
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<200000)&&((int)ob->query("shen")>0))
    {
        message_vision("武林中人最忌争强斗狠，你不是我的对手，回去吧。\n",ob);
        return 0;
    }
    message_vision("张无忌一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);
    return 1;
}

void re_rank(object ob)
{
	string filestring,master_id;

	return;
	if( ob->is_apprentice_of(this_object()) )
	{
		filestring = read_file("/d/mingjiao/master.dat");
		if( stringp(filestring) )
              sscanf(filestring,"Master_ID = %s\nlast_synod_time",master_id);
//		write("Master ID is "+master_id+"\n");
		if( !master_id || master_id != ob->query("id") )
			ob->set("title","明教"+GRN"光明使者"NOR);		
		else
			ob->set("title","明教"+CYN"副教主"NOR);		
		
	}
}


string ask_me()
{
        mapping fam;
        object ob;
	string filestring,master_id;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";

	command("say 乾坤大挪移是本教护教神功，妙用无穷，向来只有教主才可研习。");
	command("say 每五年中秋会有全教的一次演武大会，我会从中挑选教主继承人加以传授。");

	filestring = read_file("/d/mingjiao/master.dat");
	if( stringp(filestring) )
		sscanf(filestring,"Master_ID = %s\nlast_synod_time",master_id);
	if( !stringp(filestring) || !master_id || master_id == "yeung" )
		return "我现在尚未立下掌教弟子，"+RANK_D->query_respect(this_player())+"多多加油吧！";
	else if( master_id != this_player()->query("id") )
		return "我教现任掌教弟子是"+master_id+"，"+RANK_D->query_respect(this_player())+"多多努力啊！";
	else
		return "噫，你不就是我亲立的教主继承人吗？和我开什么玩笑！";
	
}

void check_time()
{                                                          
	int last_time,time_left,day_left,hour_left,min_left,i,j;
	string filestring,master_id,time_string;
	object *ob;

	if( query("in_race") )
	{
		CHANNEL_D->do_channel( this_object(), "sys",
			"明教大较正在进行中\n" );
		return;
	}
		
	filestring = read_file("/d/mingjiao/master.dat");

	if( stringp(filestring) )
		sscanf(filestring,"Master_ID = %s\nlast_synod_time = %d",master_id,last_time);
	else
	{
		filestring = "Master_ID = yeung\nlast_synod_time = "+(string)time() + "\n";
		rm("/d/mingjiao/master.dat");
		write_file("/d/mingjiao/master.dat",filestring,1);		
		CHANNEL_D->do_channel( this_object(), "sys",
			"明教文件缺失，重新生成/d/mingjiao/master.dat" );
		return;
	}
	if( !master_id )
		master_id = "yeung"; //xixi,If no master,I am.
	if( !last_time )
	{
		filestring = "Master_ID = " + master_id + "\nlast_synod_time = "+(string)time() + "\n";
		rm("/d/mingjiao/master.dat");
		write_file("/d/mingjiao/master.dat",filestring);		
		CHANNEL_D->do_channel( this_object(), "sys",
			"明教文件损坏，重新生成/d/mingjiao/master.dat" );
		return;
	}
		                                   
	time_left = last_time + 5*86400 - time();
	
	if( time_left < 0) time_left = 0;
	if( time_left > 5*86400 ) time_left = 5*86400;
	
	if( time_left < 1)
	{

		ob = users();
		i=sizeof(ob);
		j=0;
		while(i-- )
		{
			if( ob[i]->query("family/family_name") == "明教" && ob[i]->query("combat_exp") > 50000 && !wiz_level(ob[i]) )
				j++;
		}
	
		if( j<5 ) return;

		CHANNEL_D->do_channel( this_object(), "sys",
			"现任掌教弟子是"+master_id+"，准备开始比武！");
		call_out("do_start",5);
		return;
	}		

	day_left = time_left/86400;
	time_left -= day_left*86400;
	hour_left = time_left/3600;
	time_left -= hour_left*3600;
	min_left = time_left/60;
	time_left -= min_left*60;
                                               
	time_string = "";
	if( day_left ) time_string += day_left+"天";
	if( hour_left ) time_string += hour_left+"小时";
	time_string += min_left+"分";

	CHANNEL_D->do_channel( this_object(), "sys",
		"现任掌教弟子是"+master_id+"，距离明教下次大较还有" + time_string);
	return;
}

int do_update(string arg)
{
	if( query("in_race") || query("group_race"))
	{
	write("比武期间不能在这update，如果真需要的话，可以先smash张无忌，再update。\n");
	return 1;
	}
	return 0;
}

int do_poison(string arg)
{
      if( (arg == "zhang" || arg == "zhang wuji" || arg == "wuji") && random(3) )
      {
      	message_vision(RED"$N下毒失败,事情败露！\n"NOR);
      	kill_ob(this_player());
      	this_player()->start_busy(1);
      	return 1;
      }
      return 0;
}
int do_play(string arg)
{
	if( query("in_race") )
		write("不准在这弹琴.\n");
	return 1;
}



int do_practice(string arg)
{
	if ( query("in_race") )
	{
		write("不能在这练武。\n");
		return 1;
	}
	return 0;
}

int do_study(string arg)
{
	if ( query("in_race") )
	{
		write("这不是读书的地方。\n");
		return 1;
	}
	return 0;
}

int do_zhaoji(string arg)
{
	object *ob,env,*watcher;
	int i,j;
	string *watchroom,str;

	reset_eval_cost();
	command("mp "+"现在我明教五年一度的大较即将开始,凡我明教弟子，马上集合！\n");
	ob = users();
	i=sizeof(ob);
	env=environment();
	j=0;
	while(i-- )
	{
		if( ob[i]->query("family/family_name") == "明教" )
		{
			if(ob[i]->is_ghost())
			{
				ob[i]->reincarnate();
				tell_object(ob[i],"由于举行五年大较，你重现人间。\n");
			}
			ob[i]->move("/d/mingjiao/yanwuchang");
		}
	}
	command("mp 集合完毕！");
	return 1;
}

int do_start(string arg)
{
	object obj,*ob,mj_room,zhang;

	int age1,age2,age,i;
	string str;

/*
	list = filter_array(users(),(:
		$1->query("family/family_name")=="明教"
		&& !wizardp($1)
		&& $1->query("combat_exp") >= 50000	
	:));
*/
	ob = users();
	i=sizeof(ob);           
	list = ({});
	while(i-- )
	{
		if( ob[i]->query("family/family_name") == "明教" && ob[i]->query("combat_exp") > 50000 && !wiz_level(ob[i]) )
		list += ({ ob[i]->query("id") });
	}

	
	i = sizeof(list);
	if( i<5 )
	{
		CHANNEL_D->do_channel( this_object(), "sys",
		"人数不足，比武顺延。");
		return 0;
	}
		
	remove_call_out("do_start");
  	message("sys",HIY"你听到光明顶上传来洪亮的钟声...\n"NOR,users());
  	message("sys",HIY"杨逍说道：启禀教主，我明教五年大较之期已届，请教主亲临主持大较。\n"NOR,users());
  	message("sys",HIY"张无忌点头道：甚好。\n"NOR,users());
	message_vision("$N向南离开。\n",this_object());
	move("/d/mingjiao/yanwuchang");
	environment()->set("no_death",1);

	do_zhaoji(arg);

	over=0;

	while(i--)
	{
		command("mp "+(list[i])+"加入比赛！");
	}

	set("in_race",1);

	str="现在比武正式开始。";
	command("mp "+str);

	if (selectplayer(0))
	{
		obj=find_player(winer);
		command("mp 现在擂主是"+obj->query("name"));
	}
	else
	{
		command("mp 比赛人数不够,取消比赛。");
		command("mp 大较到此结束。");	
		delete("biwu");
		delete("in_race");
		environment()->set("no_death",0);
		message_vision("$N袍袖一拂，带领众人向北离开。\n",this_object());
		move("/d/mingjiao/dadian");
		return 1;
	}
	if(!selectplayer(1))
	{
		command("mp 比赛人数不够,取消比赛。");
		delete("biwu");
		delete("in_race");
		environment()->set("no_death",0);
		message_vision("$N袍袖一拂，带领众人向北离开。\n",this_object());
		move("/d/mingjiao/dadian");
		return 1;
	}
	race();
	return 1;
}

int race()
{
	int last_time,time_left;
	string filestring,master_id;
	object ob1,ob2,ob,last_master,zhang,mj_room;

	if(over)
	{
		if( stringp(winer) )
		{
			ob=find_player(winer);
			full(ob);
			command("chat " + "我教本次大较的胜者是"+ob->short());
			command("chat " + ob->query("name") + "，我命你接任副教主尊位，为我明教第三十五代教主继承人。");
			command("chat " + "你要勤于督促众位师弟师妹，振我明教声威，不可辜负了本座的一番期望。");
			ob->add("combat_exp",1000);
			ob->set("title","明教"+YEL"副教主"NOR);

			CHANNEL_D->do_channel( this_object(), "sys",
				"重新生成/d/mingjiao/master.dat" );
        		filestring = "Master_ID = " + ob->query("id") + "\nlast_synod_time = "+(string)time() + "\n";
			rm("/d/mingjiao/master.dat");
			if( write_file("/d/mingjiao/master.dat",filestring,1) )		
				CHANNEL_D->do_channel( this_object(), "sys",
					"文件写入成功！" );
			else
				CHANNEL_D->do_channel( this_object(), "sys",
					"文件写入失败！" );
		}
		command("chat 本次大较到此结束。");
		delete("biwu");
		delete("in_race");  
		environment()->set("no_death",0);
		message_vision("$N袍袖一拂，带领众人向北离开。\n",this_object());
		move("/d/mingjiao/dadian");
		return 1;
	}
	fighter=fighter1;
	fighterroom=fighter1room;
	if(!selectplayer(1))
	{
		command("mp 本次大较即将结束。");
		over=1;
	}

	if(!find_player(winer) && !find_player(fighter) )
	{
		command("mp  "+winer+"和"+fighter+"都不知道哪去了。");
		if (!selectplayer(1))
		{
			command("mp 本次大较到此结束。");
			delete("biwu");			
			delete("in_race");
			environment()->set("no_death",0);
			message_vision("$N袍袖一拂，带领众人向北离开。\n",this_object());
			move("/d/mingjiao/dadian");
			return 1;
		}
		race();
		return 1;
	}
	if( !(ob1=find_player(winer)) )
	{
		command("mp " + winer + "不知哪去了。");
		winer=find_player(fighter)->query("id");
		winerroom=fighterroom;
		race();
		return 1;
	}
	if( !(ob2=find_player(fighter)) )
	{
		command("mp " + fighter + "不知哪去了。");
		race();
		return 1;
	}

	if( !living(ob1) ) ob1->revive();
	if( !living(ob2) ) ob2->revive();
	if(ob1->is_ghost()) ob1->reincarnate();
	if(ob2->is_ghost()) ob2->reincarnate();

	full(ob1);
	full(ob2);

	if(!present(winer,environment())) ob1->move(environment());
	if(!present(fighter,environment())) ob2->move(environment());

	command("mp " + fighter 
		+ "准备，你将向" + winer + "挑战！\n");
	if(stringp(fighter1))
		command("mp "+fighter1+"准备,下一个轮到你");
	
	set("queren",1);
	call_out("do_queren",2);
	return 1;
}

int do_queren()
{
	object ob1,ob2;
	delete("queren");       
	remove_call_out("do_queren");
	command("mp 比武开始");
	if(!find_player(winer) && !find_player(fighter) )
	{
		command("mp  "+winer+"和"+fighter+"都不知道哪去了。");
		if (!selectplayer(1))
		{
			command("mp 本次大较到此结束。");
			delete("biwu");
			delete("in_race");
			environment()->set("no_death",0);
			message_vision("$N袍袖一拂，带领众人向北离开。\n",this_object());
			move("/d/mingjiao/dadian");
        		return 1;
		}
		race();
		return 1;
	}
	if( !(ob1=find_player(winer)) )
	{
		command("mp " + winer + "不知哪去了。");
		winer=fighter;
		winerroom=fighterroom;
		race();
		return 1;
	}
	if( !(ob2=find_player(fighter)) )
	{
		command("mp " + fighter + "不知哪去了。");
		race();
		return 1;
	}

	command("mp " + fighter 
		+ "开始向" + winer + "挑战！\n");
	remove_call_out("check");
	call_out("check",1,ob1,ob2);

        ob1->delete_temp("halted");
       	ob2->delete_temp("halted");
	ob1->delete_temp("be_defeated");
	ob2->delete_temp("be_defeated");

	if( !living(ob1) ) ob1->revive();
	if( !living(ob2) ) ob2->revive();
	if(ob1->is_ghost()) ob1->reincarnate();
	if(ob2->is_ghost()) ob2->reincarnate();

	if(!present(winer,environment())) ob1->move(environment());
	if(!present(fighter,environment())) ob2->move(environment());
	if(ob1->is_busy())  ob1->interrupt_me(ob1, "halt");
	if(ob2->is_busy())  ob2->interrupt_me(ob2, "halt");

	tell_object(ob1,"该上场了。\n");
	tell_object(ob2,"该上场了。\n");

	ob1->bihua_ob(ob2);
	ob2->bihua_ob(ob1);

	return 1;
}

int check(object ob1,object ob2)
{
	if(!objectp(ob1) && !objectp(ob2) )
	{
		command("mp  "+winer+"和"+fighter+"双双退线。");
		if (!selectplayer(1))
		{
			command("mp 本次大较到此结束。");
			delete("biwu");
			delete("in_race");
			environment()->set("no_death",0);
			message_vision("$N袍袖一拂，带领众人向北离开。\n",this_object());
			move("/d/mingjiao/dadian");
        		return 1;
		}
		race();
		return 1;
	}

	if(!objectp(ob1))
	{
		command("mp " + winer + "退线了！\n");
		ob2->remove_all_killer();
		winer=fighter;
		winerroom=fighterroom;
		race();
		return 1;
	}
	if(!objectp(ob2))
	{
		command("mp " + fighter + "退线了！\n");
		ob1->remove_all_killer();
		race();
		return 1;
	}

	if( (ob1->is_killing() || ob1->is_fighting())
	&&  (ob2->is_killing() || ob2->is_fighting())
	&& present(ob1,environment()) && present(ob2,environment()) )
	{
		call_out("check",1,ob1,ob2);
		return 1;
	}

        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");
	ob1->remove_all_killer();
	ob2->remove_all_killer();

	if ( !present(ob1, environment()) ) 
	{
		command("mp " + winer + "落荒而逃了！\n");
		full(ob1);
		ob1->move(winerroom);
		winer=fighter;
		winerroom=fighterroom;
		race();
		return 1;
	}

	if ( !present(ob2, environment()) ) 
	{
		command("mp " + fighter + "落荒而逃了！\n");
		full(ob2);
		ob2->move(fighterroom);
		race();
		return 1;
	}
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
               command("mp " + winer + "中途放弃比武！\n");
		full(ob1);
		ob1->move(winerroom);
		winer=fighter;
		winerroom=fighterroom;
		race();
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("mp " + fighter + "中途放弃比武！\n");
		full(ob2);
		ob2->move(fighterroom);
		race();
                return 1;
         }

	if (ob2->query_temp("be_defeated")) 
	{
		command("mp " + winer	+ "比武战胜" + fighter + "！\n");
		full(ob2);
		ob2->move(fighterroom);
		ob2->delete_temp("be_defeated");
		race();
		return 1;
	}
	if ( ob1->query_temp("be_defeated") )
	{
		command("mp " + fighter + "比武战胜" + winer + "！\n");
		full(ob1);
		ob1->move(winerroom);
		ob1->delete_temp("be_defeated");
		winer=fighter;
		winerroom=fighterroom;
		race();
		return 1;
	}
	race();
	return 1;
}

int do_manual_start(string arg)
{
	if( !wizardp(this_player()) )
		return 0;
	if( !arg || arg != "race" )
	{
		write("Type start race to begin race manually.\n");
		return 1;
	}
	if( query("in_race") || query("group_race"))
	{
		write("已经正在比武中了。\n");
		return 1;
	}
	write("OK.Race will start in 5 secs.\n");
	call_out("do_start",5);
	return 1;
}

int do_list(string arg)
{
	string str;
	int i;
	if(!query("in_race")) return notify_fail("现在还没进行大较。\n");

	str="剩下的比武名单如下:\n";
	str+="---------------------------------------------------------------\n";
	for(i=0;i<sizeof(list);i++)
	{	
		str+=sprintf("%-15s",list[i]);
		if( !((i+1)%4) ) str+="\n";
	}
	str+="\n---------------------------------------------------------------\n";
	str+=sprintf("共有%d个人。\n",sizeof(list));
	write(str);
	return 1;
}

int do_halt()
{
	object me = this_player();

	if ( ! query("in_race") ) return 1;
	if (me->is_fighting() || me->is_killing())
	{
		me->set_temp("halted",1);
		me->remove_all_killer();
		message_vision(HIW"$N向後一跃，离开战圈罢手不斗了。\n"NOR, me);
		return 1;
	}

	if( me->is_busy() )
	{
		me->interrupt_me(me, "halt");
		write("ok。\n");
		return 1;
	}

	return 1;
}

int selectplayer(int flag)
{
	mixed player;
	object ob;

	if(sizeof(list))
		player=list[random(sizeof(list))];
	else
		player=0;
	while(!seekplayer(player))
	{
		list-=({player});
		if(!sizeof(list)) {player=0;break;}
		player=list[random(sizeof(list))];
	}
	list-=({player});
	if(!flag)
	{
		winer=player;
		if(stringp(winer) && ob=find_player(winer)) winerroom=environment(ob);
		if(sizeof(list))  return 1;
		else  return 0;
	}
	if(flag)
	{
		fighter1=player;
		if(stringp(player) && ob=find_player(fighter1)) fighter1room=environment(ob);
		if(stringp(fighter1))  return 1;
		else return 0;
	}
	return 0;
}

int seekplayer(mixed name)
{
	object ob;
	if( stringp(name) && (ob=find_player(name)) && !ob->is_ghost())
	{
		return 1;
	}
	return 0;
}


int full(mixed ob)
{
	int i;
	string *gifts=({ "gin","kee","sen" });
	string *gifts1=({"atman","force","mana"});

	if(!objectp(ob)) return 0;
    
	for( i = 0; i < sizeof(gifts); i++ )
	{
	ob->set(gifts[i],ob->query("max_"+gifts[i]));
	ob->set("eff_"+gifts[i],ob->query("max_"+gifts[i]));
	}
	for( i = 0; i < sizeof(gifts1); i++ )
	{
	ob->set(gifts1[i],2*ob->query("max_"+gifts1[i])-1);
	}
	ob->set("food",ob->max_food_capacity());
	ob->set("water",ob->max_water_capacity());
	ob->clear_condition();
	return 1;
}

int chat()
{
	object me,wuji;
	int fighting;

	me = this_object();
	if( !environment(me) ) return 0;
	fighting = me->is_fighting();
		
	if( fighting && (query("kee") < 1000 || query("sen") < 200 || query("gin") < 200) )
	{
		load_object("/d/mingjiao/shangyueting");
		if( objectp(wuji=find_living("zhao min")) && wuji->is_character() && !wuji->is_fighting())
		{
	//		message_vision(YEL"trying....叫老婆\n"NOR,me);
			wuji->rescue_me(me);
		}
	}
	
	//自己解毒
	if( me->query_condition("ninemoonpoison")+me->query_condition("rose_poison")+me->query_condition("tm_poison") )
	{
		if(fighting)
                        command("surrender");
		command("exert unpoison");
	}
	//九阳护体
	if( fighting && !query_temp("jiuyang-shield") )	
		command("exert jiuyang-shield");
	//自动疗伤
	if(query("sen")<(query("eff_sen")*70/100))
		command("exert refresh");
	if(query("kee")<(query("eff_kee")*70/100))
		command("exert recover");
	if(query("gin")<(query("eff_gin")*70/100))
		command("exert regenerate");
	if(query("eff_kee")<query("max_kee")*50/100)	
	{
                if(fighting) command("surrender");
		command("exert heal");
		command("exert heal");
		command("exert heal");
             set("force_factor",200);
	}	
}
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}


