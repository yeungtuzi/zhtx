//zhangwuji.c       
// by yeung

#include <ansi.h>

inherit F_MASTER;
inherit NPC;
inherit F_QUEST;
inherit "/feature/challenge";

void greeting(object ob);
void re_rank(object ob);
string ask_me();

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
	carry_object(__DIR__"obj/skysword")->wield();
	carry_object(__DIR__"obj/goldpao")->wear();	
	add_money("gold",50);
}

void init()
{
	object ob;

        add_action("give_quest", "quest");

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
		re_rank(ob);
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
	else if((int)ob->query("shen")>10000)
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

	// 2026-04-30: unused variable commented out
	// string name, new_name;

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

	if((int)ob->query("shen") <= 15000)
	{
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return 0;
	}
	command("say 好，我就收下你这位好兄弟");
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

	if( ob->is_apprentice_of(this_object()) )
	{
		filestring = read_file("/d/mingjiao/master.dat");
		if( stringp(filestring) )
			sscanf(filestring,"Master_ID = %s",master_id);
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
		sscanf(filestring,"Master_ID = %s",master_id);
	if( !stringp(filestring) || !master_id )
		return "我现在尚未立下掌教弟子，"+RANK_D->query_respect(this_player())+"多多加油吧！";
	else if( master_id != this_player()->query("id") )
		return "我教现任掌教弟子是"+master_id+"，"+RANK_D->query_respect(this_player())+"多多努力啊！";
	else
		return "噫，你不就是我亲立的教主继承人吗？和我开什么玩笑！";
	
}


