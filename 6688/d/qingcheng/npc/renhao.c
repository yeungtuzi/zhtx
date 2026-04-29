/* yurenhao.c
 last motify by pock 04/03/98
*/
#include <ansi.h>
inherit NPC;
string ask_food();
string *leave_msg = ({     
	" 于人豪拿起便当向南离去.\n",
	});     
	
void create()
{
	set_name("于人豪", ({"yu renhao","renhao","yu"} ) );
	set("gender", "男性" );
	set("age", 25);
	set("str", 20);
	set("cor", 25);
	set("cps", 25);
	set("shen_type",-1);
      
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 5);

       
	set("long",@LONG
 他是余沧海的嫡传弟子,是青城派年轻一代的高手,乃是青城四秀老三.
LONG);

       

	set("combat_exp", 400000);
	

	set("chat_chance_combat", 60);

	set_skill("unarmed", 60);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("sword", 70);
	set_skill("force", 30);

	set_skill("qingcheng-steps", 50);
	set_skill("cuixin-zhang",50);
	set_skill("pine-sword", 50);
	set_skill("qingcheng-force",30);

       create_family("青城派", 19, "弟子");

       map_skill("sword", "pine-sword");
       map_skill("dodge", "qingcheng-steps");
       map_skill("parry", "pine-sword");     
       map_skill("unarmed","cuixin-zhang");
       map_skill("force","qingcheng-force");
	set("inquiry", ([
	"food" :( :ask_food():),
	"便当" :( :ask_food():),
	]));
	setup();
	add_money("silver", 8);
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}
void init()
{       object ob;
	add_action("go_north","north");
	add_action("go_north","n");
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
      
	 if( (int) ob->query_temp("mark/food") == 0 ) 
	write( "于人豪说道: 今天怎么搞的?都这么晚了，还不给我送 便当 来。 \n");
	else 
	write( "于人豪说道: 谢谢你给我送的饭哟!\n");
}


void leave_stage(object who, int stage)
{
     object obj;
     tell_object(who, leave_msg[stage]);
     if( ++stage < sizeof(leave_msg) ) {
	 call_out( "leave_stage", 2, who, stage );
	 return;
     } else
       destruct(this_object());
    return;
}
int accept_fight(object me)
{
	command("say 在下哪里是您的对手？");
	return 0;
}
int accept_object(object who, object ob)
{       who = this_player();
	if( (string)ob->query("id") !="food" ){
		command("say 我现在饿的要命，不需要你这样的东西.你替我把我的便当拿来就差不多.\n");
		return 0;
	}        
	who->set_temp("mark/food",1);
	message_vision("于人豪说道: 太好了，你先替我看一下门，我去填饱肚皮再来。\n",who);
	
	call_out( "leave_stage", 2, who, 0 );
	return 1;
}
int do_gogo(string arg)
{
	if( arg == "north" )
	{
	    write(RED"于人豪喝道: 嘿，你...你不要乱闯!!!\n"NOR);
	    return 1;
	}
	return 0;
}

string ask_food()
{       this_player()->set_temp("marks/nod",1);
	return "平时早就给我送来了，可能今天 人达 有什么事忘了。\n你能不能帮我拿来啊？\n";
}
