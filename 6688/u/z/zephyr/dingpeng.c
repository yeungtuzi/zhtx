//by zephyr

inherit NPC;
inherit F_MASTER;
#include <ansi.h>


object me=this_object();

void shout(object who, int stage);
void kill_liu();
int random_go();

string ask_blade();
string ask_reward();

string *shout_msg=({
YEL"\n柳若松见了丁鹏，居然一拱手道：“多谢师父赠刀之德。弟子使了此刀，搏杀了方今江湖上十七名绝顶高手。”\n"NOR, 
CYN"\n“很好，你现在大概已经天下无敌了。”\n"NOR,
YEL"\n柳若松道：“哪里，哪里！在师父面前，弟子不敢说这种话。”\n"NOR,
CYN"\n丁鹏道：“我的儿子呢？”\n"NOR,
YEL"\n柳若松笑道：“就在这里。在里面，那是我的小师弟，弟子会好好照应他的。”\n"NOR,
CYN"\n丁鹏神色一沉道：“柳若松听好，把孩子还给我，把神刀交回，我就饶你一命。”\n"NOR,
YEL"\n“那刀是师父传给弟子的。”\n"NOR,
CYN"\n“我可没有这样说。柳大爷，不必肉麻了，我没教过你一天武艺，你也不必再叫得那么好听。”\n"NOR,
YEL"\n柳若松道：“好，师父既这么说，弟子也不勉强了，弟子的年纪和师父本就不相衬。”\n"NOR,
YEL"\n“先前是为了有赠刀之德，弟子还不得不顾到礼数，现在这一点情份都没有了，你我还是各归各的吧。”\n"NOR,
CYN"\n“把刀跟我儿子抱来！”\n"NOR,
YEL"\n柳若松一笑道：“丁鹏，你儿子在里面，我并不想要他，你随时都可以抱回去。”\n"NOR,
YEL"\n“至于那柄神刀嘛，我也是魔教传人，而且还立了大功，清除了所有的叛徒，有资格承受它。”\n"NOR,
CYN"\n丁鹏笑道：“如果我坚持要收回呢？”\n"NOR,
YEL"\n“那也容易，我是夺来的，你也夺回去。”\n"NOR,
CYN"\n丁鹏道：“我知道叫你乖乖地交回是不可能的，所以早作了准备。受死吧。”\n"NOR,
YEL"\n“你就用手中这柄刀跟我决斗？”\n"NOR,
CYN"\n丁鹏把刀一伸，给他看得更为仔细，才道：“我这柄刀比你好看多了，而且天下人皆知其名，而那柄神刀，却只有江湖中人才知道它。”\n"NOR,
YEL"\n柳若松仔细地看了一下，道：“果然是那柄出跸刀，先前听人说了，我还不太相信。你要用它来跟我决斗？”\n"NOR,
CYN"\n“不是决斗，是杀人，杀死你！”\n"NOR,
YEL"\n“你不是开玩笑？它能杀人吗？”\n"NOR,
CYN"\n“是刀就能杀人，我已经杀了十几个了。”\n"NOR,
YEL"\n“我手中拿的是天下丧胆的魔神之刀。”\n"NOR,
CYN"\n“我杀的人手中都拿着武器。”\n"NOR,
});

void create()
{
	set_name("丁鹏", ({ "ding peng","ding"}) );
	set("long",CYN@LONG
他的脸很清秀，身体也很健康，说起话来显得活力充沛，
生气蓬勃，笑起来的时候，常常会露出幼稚天真的孩子气，
就像是一个你从小看着他长大的大男孩。
但是丁鹏已经不是孩子了。这三个月里，他已连续击败了
三位在江湖中极负盛名的剑客。
LONG NOR
	 );

	set("title",CYN"圆月"WHT"弯刀"NOR);
	set("age", 30);
	//set advanced skills

	set_skill("force", 500);
	set_skill("strike", 500);
	set_skill("sword", 500);
	set_skill("blade", 500);
	set_skill("parry", 500);
	set_skill("dodge", 500);
	set_skill("move", 500);
	set_skill("perception", 500);
		
	set_skill("taiji-shengong", 200);
	set_skill("celestrike", 500);
	set_skill("spring-blade", 500);
	set_skill("pyrobat-steps", 500);
	map_skill("force", "taiji-shengong");
	map_skill("strike","celestrike");
	prepare_skill("strike", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("dodge", "pyrobat-steps");
	map_skill("move", "pyrobat-steps");
 
	set("count",1);
	set("helper_id",0);
	set("helper_count",0);

	set("helper_name","0");
	set("helper_success",0);
	set("attitude", "peaceful");
	set("combat_exp", 10000000);
	set("shen_type",1);

	set("str", 100);
	set("int", 30);
	set("cor", 100);
	set("cps", 100);                       
	set("per", 50);
	set("con", 30);
	set("no_get",1);

	set("atman", 500);
	set("max_atman", 500);

	set("force", 20000);
	set("max_force", 10000);
	set("force_factor", 300);

	set("mana", 1000);
	set("max_mana", 1000);

	set("max_kee",50000);
	set("max_gin",10000);
	set("max_sen",10000);

    set("chat_chance",20);
	set("chat_msg", ({
               (: random_go :)
        }) );
	
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
	(: exert_function, "recover" :),
	}) );

		set("inquiry", ([
                "出跸刀" : "出跸刀现在在我手上。是我以十万两黄金的代价，从一个收藏家手中买下来的。", 
                "柳若松" : "这厮虏走了我的儿子，杀了我的仆从，抢了我的宝刀，我一定要杀了他。", 
                "圆月弯刀" : "圆月弯刀是江湖朋友对我的称呼。",
                "找柳若松"    : (: ask_blade :),
                "找到柳若松"    : (: ask_blade :),
                "帮忙"    : (: ask_blade :),
                "小楼一夜听春雨"    : (: ask_blade :),
                "回报"    : (: ask_reward :),
                "要求"    : (: ask_reward :),
                "奖励"    : (: ask_reward :),
        ]) );


	set_temp("apply/defense",50);
	set_temp("apply/armor_vs_force",500);
	set_temp("apply/armor",500);
	

    set("shen_type",1);
    set("skill_mark/spring-blade",1);
    setup();

	carry_object("/obj/cloth/cloth")->wear();
	carry_object(__DIR__"chubiblade")->wield();
	set("bellicosity",1000);
}                          

void init()
{
	object ob = this_player();
	add_action("do_accept","accept");
	add_action("do_select","select");
	remove_call_out("greeting");
	call_out("greeting",1,ob);
}
							 

void greeting(object ob)
{
	mapping ob_fam;

	if(!ob || environment(ob)!=environment()) return;
	
	if(is_fighting()) return;
	
	if (ob->query("id")==query("helper_id"))
		return;
	
	if (query("helper_success"))
		return;

	if ( ob->query("dingpeng_enemy") )
	{
		command("say 柳若松！！！\n");
		set_leader(ob);
	}
	else
	{
 		command("say 这位"+(string)RANK_D->query_respect(ob)+"可曾见到一个腰间挂有弯刀的中年男子");
	}
	return;
}

int accept_fight(object ob)
{
	if (! query("helper_success"))
	{
		message_vision(CYN"$N哼了一声：我正忙着，可没功夫跟人较量。\n"NOR,this_object());      
		return 0;
	}
	command("say 请！\n");
	return 1;
}

int killed_enemy(object ob)
{
	if (query_temp("dingpeng/kill_liuruosong"))
	{
		object weapon = query_temp("weapon");
		object e_weapon = ob->query_temp("weapon");

		set("helper_success",1);

		if ( objectp(e_weapon) )
		{
			if ( objectp(weapon) )
			{
				weapon->unequip();
				destruct(weapon);
			}

			e_weapon->unequip();
			e_weapon->move(me);
			message("vision", CYN"\n丁鹏从柳若松的尸体手中取回了神刀，只说了一句话：\n"NOR, environment());
			message("vision", CYN"\n“有些人纵有神刀在手，仍是无法成为刀中之神的。”\n\n"NOR, environment());
			command("wield blade");
		}
		command("haha");
		command("bow "+query("helper_id"));
		if (query("helper_id")) command("say "+ CYN"大恩不言谢，你有什么要求请提出来，我一定尽力而为。"NOR);
	}
	else 
	{
		command("say 世上偏生有这么多不怕死的家伙！\n");
		command("heng");
	}
}


void chat()
{
	object me, liu;
	int fighting,hurt,force_fac,i, all;
	object *enemy, victim, weapon, po_weapon, taken_weapon;

	me = this_object();
	if( !environment(me) ) return 0;
	fighting = me->is_fighting();

	liu = present("liu ruosong", environment(me));

	if( !is_fighting() && objectp(liu) && query("count") )
	{
		set_leader(0);
		command("wield dao");
		remove_call_out("shout");
		call_out("shout", 2, me, 0);
		add("count",-1);
	}


	if( query("eff_kee")<query("max_kee")*70/100)     
	{
		force_fac = query("force_factor");
		if(fighting) command("halt");
		hurt = query("max_kee")-query("eff_kee");
		hurt /= 100;
		while( hurt-- )
		command("exert heal");
		set("force_factor",force_fac);
	}
	
	if(query("sen")<(query("eff_sen")*70/100))
	command("exert refresh");
	if(query("kee")<(query("eff_kee")*70/100))
	command("exert recover");
	if(query("gin")<(query("eff_gin")*70/100))
	command("exert regenerate");

	if (is_fighting())
	{
		int f= query("force_factor");
		enemy = me->query_enemy();
		all = sizeof(enemy);

		if (f<300)
		{
			set("force_factor",300);
		}

		if(!objectp(query_temp("weapon")))
		{
			//打破在地
			po_weapon = present("chubi dao", environment());
			//被夺兵器
			for(i=0;i<all;i++)
			{
				victim = enemy[i];
				taken_weapon = present("chubi dao", victim);
				if ( objectp(taken_weapon) )
				{
					taken_weapon->move(this_object());
					message_vision(CYN"丁鹏蓦地和身向"+victim->name()+"扑出，左手手指已搭住出跸刀的刀柄。\n"NOR, environment());
					message_vision(CYN"\n"+victim->name()+"猛吃一惊，正待反击，"+name()+"右手食中二指倏取"+victim->name()+"的双目，同时左足翻起，已将刀身压住\n"NOR, environment());
					message_vision(CYN"\n"+victim->name()+"为保眼珠，只得松手放开木刀。\n"NOR, environment());
					command("wield dao");
				}
			}

			if ( objectp ( po_weapon ) && po_weapon->query("weapon_prop") )
			{
				po_weapon->move(this_object());
				message_vision(CYN"丁鹏信手一抄，从地上拾起木刀。\n"NOR, environment());
				command("wield dao");
			}
		}
	}

	::chat();

}

void shout(object who, int stage)
{                       
	message_vision(shout_msg[stage], environment(who));
	
	if( ++stage < sizeof(shout_msg) && present("liu ruosong", environment(who)) ) 
	{
		call_out( "shout", 1, who, stage);
		
		if (stage==20)
		{
			remove_call_out("kill_liu");
			call_out("kill_liu", 8);
		}
		return;
	} 

	return;
}
void kill_liu()
{
	object *ob;
	int i;
  	ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) 
		{
             if( ob[i]->query("id")=="liu ruosong" ) 
			{
				object blade = present("chubi blade", this_object());
				command("wield dao");
				kill_ob(ob[i]);
				ob[i]->kill_ob(this_object());
			}
        }
}

string ask_blade()
{
	if (query("helper_success"))
		return "多谢这位英雄关心，如今我大仇已然得报！\n";

	if (query("helper_count") )
	{
		if (query("helper_id")==this_player()->query("id"))
		return "多谢这位英雄，还请尽快帮我找到柳若松这个奸贼。在下感激不尽！\n";
		else
		return query("helper_name")+"已经在帮助我了\n";
	}
	
	if (!this_player()->query_temp("weaponor5")) return "我原有一把神刀，名作小楼一夜听春雨，江湖人称圆月弯刀。但是现在我的神刀却落在贼子柳若松手中。可恨！";


	if (!query("count"))
		return "？？？\n";

	this_player()->set_temp("ask_dingpeng",1);
	set("count",0);
	return "你愿意帮我找到柳若松吗?(accept yes/no)\n";

}


string ask_reward()
{
	if ( !this_player()->query_temp("help_dingpeng") )
	{
		return "你是哪位？为什么平白无故来问我要回报？\n";
	}

	if (present("liu ruosong", environment(me)))
	{
		return "英雄请少安毋躁，且等我先杀了柳若松这个奸贼！\n";
	}

	if ( (string) query("helper_id") == (string) this_player()->query("id") && query("helper_success") )
	{
		return "我这里有几件宝物，请您任意挑选\n\n" + "青松古剑(select 1)\n\n" +"天涯明月刀(select 2)\n" + "夜明珠(select 3)\n\n";
	}

	return "你还没有帮助我找到柳若松这个奸贼，怎么向我要奖励？\n";

}

int do_accept(string arg)
{
	if(!this_player()->query_temp("ask_dingpeng"))
	return 0;
	if(!arg||arg=="")
	return 0;
	if(arg=="no")
	  {
		command("sigh");
		command("say 既然这位"+RANK_D->query_respect(this_player())+"不肯帮忙,我也不能勉强.");
		this_player()->delete_temp("ask_dingpeng");
		set("count",1);
		return 1;
	 }
	if(arg=="yes")
	{
		set("count",1);
		set("helper_count",1);
		set("helper_id", (string) this_player()->query("id"));
		set("helper_name", (string) this_player()->query("name"));
		command("say 多谢这位"+RANK_D->query_respect(this_player()));
		command("unwield blade");
		command("follow "+ query("helper_id"));
		this_player()->set_temp("help_dingpeng",1);
		this_player()->delete_temp("ask_dingpeng");
		return 1;	
	}
	return 0;
}


int do_select(string arg)
{
	object reward;
	if(!this_player()->query_temp("help_dingpeng"))
	return 0;
	if(this_player()->query_temp("be_rewarded"))
	{
		command("?");
		return 0;
	}
	if(!arg||arg=="") 
	return 0;
	if(arg=="nothing"||arg=="什么都不要") 
	{
		this_player()->set_temp("be_rewarded", 1);
		command("?");
		command("say 英雄对这些都不感兴趣吗？");
		command("hmm");
		remove_call_out("give_amulet");
		call_out("give_amulet", 5);
		return 1;
	}
	if (arg=="1"||arg=="青松古剑")
	{
		command("say 青松古剑以前是青松居士的佩剑，削铁如泥。");
		reward=new(__DIR__"qingsonggujian");
		reward->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		this_player()->delete_temp("help_dingpeng");
		this_player()->delete_temp("ask_dingpeng");
		command("say 英雄定会善用此剑，为天下苍生谋福。");
		command("say 在下现在要急着去救我的儿子出来，大恩来日再图报答。就此告别！");
		command("bow");
		command("bye");
		destruct(me);
		return 1;
	}
	if (arg=="2"||arg=="天涯明月刀")
	{
		command("say 天涯明月刀是刀客傅红雪用过的刀，刀身黑色，威猛无比。");
		command("say 多年前我从一个前辈的手中得到此刀，如今宝刀赠英雄，就把它送给你吧。");
		reward=new(__DIR__"tianyamingyuedao");
		reward->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		this_player()->delete_temp("help_dingpeng");
		this_player()->delete_temp("ask_dingpeng");
		command("say 在下现在要急着去救我的儿子出来，大恩来日再图报答。就此告别！");
		command("bow");
		command("bye");
		destruct(me);
		return 1;
	}
	if (arg=="3"||arg=="夜明珠")
	{
		command("say 这颗夜明珠是三年前我从东海一个渔民那里购买来的,价值连城。");
		command("say 如今我将它送给英雄，聊表谢意。");
		reward=new(__DIR__"yemingzhu");
		reward->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		this_player()->delete_temp("help_dingpeng");
		this_player()->delete_temp("ask_dingpeng");
		command("say 在下现在要急着去救我的儿子出来，大恩来日再图报答。就此告别！");
		command("bow");
		command("bye");
		destruct(me);
		return 1;
	}
	if (arg=="4"||arg=="出跸刀" || arg=="破刀")
	{
		command("say 什么？你要这柄破成两半的出跸刀？？");
		command("hmm");
		command("say 传说此刀本有奇用，我也不是很清楚。但是现在它已经破成了两片.....");
		command("say 想来已经没有什么用处了吧。不过既然英雄想要...好吧，如此就把它送给你吧！");
		reward=new(__DIR__"pochubiblade");
		reward->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		this_player()->delete_temp("help_dingpeng");
		this_player()->delete_temp("ask_dingpeng");
		command("say 在下现在要急着去救我的儿子出来，大恩来日再图报答。就此告别！");
		command("bow");
		command("bye");
		destruct(me);
		return 1;
	}

	if( strsrch(arg, "出跸刀") >=0 && strsrch(arg, "和") >=0 && strsrch(arg, "天涯明月刀") >=0  ) 
	{
		command("say 天涯明月刀是刀客傅红雪用过的刀，刀身黑色，威猛无比。");
		command("say 多年前我从一个前辈的手中得到此刀，如今宝刀赠英雄，就把它送给你吧。");
		reward=new(__DIR__"tianyamingyuedao");
		reward->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		this_player()->delete_temp("help_dingpeng");
		this_player()->delete_temp("ask_dingpeng");
		command("say 在下现在要急着去救我的儿子出来，大恩来日再图报答。就此告别！");
		command("wave");
		remove_call_out("give_blade");
		call_out("give_blade",1);
		return 1;
	}
	
	return 0;
}

void give_blade()
{
		object reward;
		message_vision(YEL"丁鹏转身欲离去。\n"NOR, environment());
		message_vision(YEL"$N迟疑了一下，说道，且慢，在下有一个不情之请。可否把那柄出跸刀也送给我呢？\n"NOR, environment());
		command("hmm");
		command("say 出跸刀本虽有奇用，但是现在已经破成了两片，这...");
		command("hmm");
		command("say 好吧，如此就把它送给你吧！");
		reward=new(__DIR__"pochubiblade");
		reward->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		command("bye");
		destruct(me);
}

void give_amulet()
{
		object amulet;
		this_player()->add_temp("have_helped_dingpeng");
		this_player()->delete_temp("help_dingpeng");
		this_player()->delete_temp("ask_dingpeng");
		command("say 英雄执意不要报答....这...");
		command("hmm");
		command("say 好吧，我这里有一块辟邪温玉。英雄戴在身上，在英雄有难之时我会视时相助。");
		amulet=new("/u/z/zephyr/dingpeng_amulet");
		amulet->move(this_player());

		this_player()->add_temp("have_helped_dingpeng",1);

		command("say 在下现在要急着去救我的儿子出来，大恩来日再图报答。就此告别！");
		command("bow");
		command("bye");
		destruct(me);
}

void die()
{
	object blade, killer;
	
	
	if( objectp(killer = query_temp("last_damage_from")) )
	{
		killer->set_temp("kill_dingpeng",1);

		blade = present("chubi dao", me);
		if ( objectp(blade) )
		{
			blade->unequip();
			destruct(blade);
			command("sigh");
			message_vision(YEL"\n丁鹏仰天长叹：没想到，出跸刀在手，我丁鹏仍然是如此结局，留此刀何用？\n", environment());
			message_vision(YEL"\n言罢，丁鹏手一抖，木刀在手中碎成了木片，再一抖，木片如飞蝗一般飞出。\n"RED,environment());
			message_vision(killer->query("name") + RED"大惊，但是也已经躲闪不及，被无数木片刺身而过，浑身浴血。\n"NOR,environment());
			if( environment()) 
			{
				killer->receive_wound("kee", killer->query("eff_kee")/2);
				killer->unconcious();
			}
		}
		else
		{
			if (query("helper_success"))
			message_vision(CYN"\n丁鹏仰天长叹：我丁鹏大仇刚刚得报，便命丧奸人之手，可恨啊！\n", environment());
			else
			message_vision(CYN"\n丁鹏仰天长叹：没想到，我丁鹏大仇未报，却命丧奸人之手，可恨啊！\n", environment());
		}
	}
	::die();
}

int random_go()
{
	mapping exits;
	string *dirs;
	if ( present("liu ruosong",environment()) ) return 0;
	if ( query("helper_success") ) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}
