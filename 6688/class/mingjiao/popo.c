// daiyisi.c
// by yeung
// 1998/07/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string query_daiyisi();
int    query_yinye();
int    do_report(string arg);
int    do_accept(string arg);

void create()
{
	set_name(HIY"金花婆婆"NOR, ({ "jinhua popo", "popo" }) );
	set("title", "灵蛇岛女岛主");
	set("gender", "女性" );
	set("age", 52);
	set("int", 100);
	set("per",2);
	set("long",
		"灵蛇岛银叶金花威震江湖，银叶早逝后，金花婆婆独自行走江湖，依\n"
		"然是威风八面。但是她的身世却一直是一个迷。她鼻低唇厚、四方脸\n"
		"蛋、耳大招风，再加上如风干橘子般的面皮，真是好生丑陋的一个老太婆。\n"
		);
       	set("chat_chance", 2);
        set("chat_msg", ({
                "金花婆婆面上露出恐惧的神色，似乎害怕什么。\n",                
                "金花婆婆咬牙切齿地说：一定要杀了胡青牛这奸贼！\n",
        }) );

	set("inquiry", ([
		"波斯三使": "嗯....他们是波斯明教的护教使者，武功深不可测。\n",
		"紫衫龙王": "紫衫龙王是明教的四大法王之首，你怎么跑到我这里来问了。\n",
		"黛绮丝"  : (:query_daiyisi:),         
		"银叶先生" : (:query_yinye:),
	]) );
	set("attitude", "peaceful");
	set("shen",-200000);
	set("max_gin",3000);
	set("max_kee",3000);
	set("max_sen",3000);
	set("max_force",3000);
	set("max_mana",300);
	set("max_atman",300);
	set("force",5999);
	set("mana",300);
	set("atman",300);
	set("force_factor",80);
	
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);	
	set_skill("fanwen", 180);
	set_skill("throwing", 180);
	set_skill("parry", 180);
	set_skill("hand",180);

	set_skill("jinhua", 180);
     set_skill("yueying-wubu", 200);
	set_skill("moni-xinfa", 180);
	set_skill("shenghuo-shengong",180);
	
	map_skill("force", "moni-xinfa");
        map_skill("throwing", "jinhua");
	map_skill("parry","jinhua");
      map_skill("dodge","yueying-wubu");
	map_skill("hand","shenghuo-shengong");

	prepare_skill("hand","shenghuo-shengong");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
                (: exert_function, "yinfengdao" :),
                (: exert_function, "touguzhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),		
	}) );


	set("combat_exp", 1000000);

	setup();

	carry_object(__DIR__"obj/jinhua")->wield();
	carry_object("/d/mingjiao/npc/obj/jadestaff");
}

void init()
{
        object ob;
	
	add_action("do_report","report");
	add_action("do_accept","accept");	

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
	if( (this_object()->query("name")) == HIG"黛绮丝"NOR )
	if( ob->query_temp("marks/huiyue") && ob->query_temp("marks/miaofeng") && ob->query_temp("marks/liuyun") )
	{
		ob->delete_temp("marks/daiyisi");	
		ob->delete_temp("marks/miaofeng");	
		ob->delete_temp("marks/huiyue");	
		ob->delete_temp("marks/liuyun");	
		ob->set("marks/app_dys",1);
		message_vision(HIG"黛绮丝"NOR+"欣慰地说：好！好！好！妾身承蒙大恩，真是无以为报啊。\n",ob);
		message_vision(HIG"黛绮丝"NOR+"说：妾身曾学得一些粗浅功夫，如蒙不弃，愿传于这位"+RANK_D->query_respect(ob)+"\n",ob);
	}
}

void attempt_apprentice(object ob)
{
        if( ob->query("marks/app_dys") )
        {
        	command("say 很好很好。\n");
        	command("say 如此妾身就把我一身功夫传于"+RANK_D->query_respect(ob));
	        command("recruit " + ob->query("id") );
	}
}

int accept_learn(object ob,string skill)
{

        if( !ob->query("marks/app_dys") ){
                if( (this_object()->query("name")) != HIG"黛绮丝"NOR )
                {       
                	return 0;
                }
                command("say 我现在朝不保夕，哪里有心思教你啊....\n");
                return 0;
        }

        return 1;
}

int recognize_apprentice(object ob)
{
	return accept_learn(ob,"force");
}

int do_report(string arg)
{
	object me;

	me = this_player();
	if( !(me->query("marks/murdurer_found")) )
		return 0;
	me->delete("marks/murdurer_found");
	command("sigh");
	command("say 没有想到，这事居然如此收场...你去吧，我想休息一下...");
	me->set("marks/银叶_success",1);
	return 1;
}


string query_daiyisi()
{
        object ob;
        
        ob = this_player();
        if( ob->query("marks/app_dys") )
        	return "你又来跟我开玩笑了。\n";
        if( ob->query_temp("marks/xiexun") )
        {
		message_vision(HIY"\n金花婆婆说道：看来谢三哥都已经给你说了，我也没有什么好隐瞒的了。\n"NOR,ob);
		message_vision(HIY"金花婆婆从面上揭下一层如蝉翼般的人皮面具。你顿时面前一亮，刹那之间，\n"NOR,ob);		
		message_vision(HIY"金花婆婆变成了一个肤如凝脂、杏眼桃腮的美艳妇人，容光照人，端丽难言。\n"NOR,ob);
		message_vision(HIY"正是貌美如花，倾倒众生的圣女黛绮丝。也正是明教四大法王之首 ━━ 紫衫龙王。 \n"NOR,ob);		
		set_name(HIG"黛绮丝"NOR, ({ "daiyi si" }) );
		set("title", "明教护教法王"NOR);
		set("nickname",HIM"紫衫龙王"NOR);
		set("gender", "女性" );
		set("age", 32);
		set("int", 100);
		set("shen",-5000000);
		set("per",100);
		set("long",
		HIM"\n黛绮丝穿了一身淡紫色的衣衫，当真胜如凌波仙子。紫衫龙王美若天仙，遥想当年\n"
		     "光明顶上，紫衫如花，长剑胜雪，不知道倾倒了多少豪杰，此时虽经岁月侵蚀，当年风\n"
		     "姿仍然仿佛留存……\n"NOR
		);

		set("inquiry", ([
			"波斯三使": "嗯....他们是波斯明教的护教使者，武功深不可测。\n波斯明教教中严规，失贞者须火刑处死。谁能解救我呢？\n",
			"紫衫龙王": "不敢当，妾身就是黛绮丝，不知殷二哥，谢三哥和韦四哥可好？\n",
			"乾坤大挪移心法" : "据说是一本羊皮书，向来由教主保存，我女儿大概知道在哪里。\n",
			"小昭"  :  	   "小昭是我的女儿，现在在明教张公子那里。\n",
			"解救" : "多谢这位"+RANK_D->query_respect(ob)+"，请多加珍重，妾身日夜盼望佳音。\n",
		]) );         
	       	set("chat_chance", 0);
	       	
	       	create_family("明教",33,"法王");
	       	
		setup();
	       	
	       	ob->set_temp("marks/daiyisi",1);
		
		return "真是恍若隔世...... \n";
		
        }
        else
       	{
		message_vision(HIY"\n金花婆婆颤声道：什么？你都知道了？你定是波斯使者的奸细！\n"NOR,ob);       		
		this_object()->kill_ob(ob);   
		ob->fight_ob(this_object());
		return HIR"不能放你逃了！"NOR;
       	}
       	return "";
       
}

int query_yinye()
{
        object  me;

        me = this_player(); 
        if( !me->query("marks/app_dys") )
        {
        	command("say 你问这个干什么？");
        	return 1;
        }
        if (!(present("jinhua popo",environment()) )  ) return 0;
        if(!(query_temp("query_yinye")))
        {
      	command("say 他中了西域一个头陀的毒药，因为胡青牛不肯医治，已经去世了。");
	command("say 你愿意替我查明真相，报这个血海深仇吗？(accpet yes/no)");
	this_player()->set_temp("query_yinye",1);
        }
        else
        {
        command( "say 你已经问过我了，还问干什么。" );
        }
        return 1;
} 


int do_accept(string arg)
{
    object feng;
    object me; 
    me=this_player();

    if (!(present("jinhua popo",environment(me)) )  ) return 0;

    if (!arg || (arg!= "yes" && arg !="no")) return 0;
    if (me->is_fighting()) return 0;
    if (!(me->query_temp("query_yinye"))) return 0;
    if (arg=="yes")
    {
	me->set("marks/银叶_1",1);
    	command("say 如此多谢了。");	
	return 1;
    }
    return 1;
}
